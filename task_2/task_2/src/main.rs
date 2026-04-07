use std::collections::HashSet;
use std::io;

fn limitations(s: &str) -> bool {
    let symbols = "qwertyuiopasdfghjklzxcvbnm0123456789.+";
    let zapret = "&=+<>,_`-";

    
    let parts: Vec<&str> = s.split('@').collect();
    if parts.len() != 2 {
        return false;
    }

    let name = parts[0];
    let domen = parts[1];

    // В C++ коде проверялось "@" + domen.size() < 4
    if !domen.contains('.') || domen.len() < 3 {
        return false;
    }

    
    if domen.chars().any(|c| zapret.contains(c)) {
        return false;
    }

    
    if name.len() < 6 || name.len() > 30 {
        return false;
    }

    
    if s.contains("..") {
        return false;
    }

    
    if !name.chars().all(|c| symbols.contains(c)) {
        return false;
    }

    
    if name.starts_with('.') || name.ends_with('.') {
        return false;
    }

    true
}

fn normal_email(s: &str) -> String {
    let parts: Vec<&str> = s.split('@').collect();
    let mut name = parts[0];
    let domen = parts[1];

    // Отрезаем всё после '+'
    if let Some(plus_pos) = name.find('+') {
        name = &name[..plus_pos];
    }

    // Удаляем точки из имени
    let clean_name: String = name.chars().filter(|&c| c != '.').collect();

    format!("{}@{}", clean_name, domen)
}

fn main() {
    let mut emails = HashSet::new();
    let stdin = io::stdin();

    loop {
        let mut input = String::new();
        // Читаем строку целиком
        if stdin.read_line(&mut input).is_err() {
            break;
        }

        let email = input.trim(); // Убираем пробелы и символы переноса

        if email == "end" {
            break;
        }

        if !limitations(email) {
            println!("ERROR!!!");
        } else {
            let normalized = normal_email(email);
            emails.insert(normalized);
        }
    }

    println!("Уникальных адресов {}", emails.len());
}
