import java.util.*;

public class Main {

    public static boolean limitations(String str) { // ПРОВЕРКА

        String symbols = "qwertyuiopasdfghjklzxcvbnm0123456789.+";
        String zapret = "&=+<>,_`-";
        String strName = "";
        String strDomen = "@";

        if (!str.contains("@")) { // если нет @
            return false;
        }

        int pos = str.indexOf('@');
        strDomen += str.substring(pos + 1); // домен

        if (!strDomen.contains(".") || strDomen.length() < 4) {
            return false;
        }

        // проверка запрещённых символов в домене
        for (char i : strDomen.toCharArray()) {
            boolean prov = true;
            for (char j : zapret.toCharArray()) {
                if (i == j) {
                    prov = false;
                    break;
                }
            }
            if (!prov) {
                return false;
            }
        }

        // имя пользователя
        for (char c : str.toCharArray()) {
            if (c == '@') break;
            strName += c;
        }

        if (strName.length() < 6 || strName.length() > 30) {
            return false;
        }

        // проверка на ".."
        for (int i = 0; i < str.length() - 1; i++) {
            if (str.charAt(i) == '.' && str.charAt(i + 1) == '.') {
                return false;
            }
        }

        // проверка допустимых символов
        for (char c : strName.toCharArray()) {
            boolean prov = false;
            for (char j : symbols.toCharArray()) {
                if (c == j) {
                    prov = true;
                    break;
                }
            }
            if (!prov) {
                return false;
            }
        }

        if (strName.charAt(0) == '.' || strName.charAt(strName.length() - 1) == '.') {
            return false;
        }

        return true;
    }

    public static String normalEmail(String str) { // нормализация
        int pos = str.indexOf('@');
        String name = str.substring(0, pos);
        String domen = str.substring(pos);

        StringBuilder cleanName = new StringBuilder();

        int plusPos = name.indexOf('+');
        if (plusPos != -1) {
            name = name.substring(0, plusPos);
        }

        for (char c : name.toCharArray()) {
            if (c != '.') {
                cleanName.append(c);
            }
        }

        return cleanName.toString() + domen;
    }

    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        Set<String> emails = new HashSet<>();

        String email = "";

        while (!email.equals("end")) {
            email = scanner.next();

            if (!email.equals("end") && !limitations(email)) {
                System.out.println("EROR!!!");
            } else {
                if (!email.equals("end")) {
                    email = normalEmail(email);
                    emails.add(email);
                }
            }
        }

        System.out.println("Уникальных адресов " + emails.size());
    }
}