import java.util.*

// Функция для подсчета количества букв
fun sumChar(str: String): Map<Char, Int> {
    val result = mutableMapOf<Char, Int>()
    for (char in str) {
        // getOrDefault позволяет избежать проверки на null
        result[char] = result.getOrDefault(char, 0) + 1
    }
    return result
}

// Проверка, можно ли составить палиндром
fun check(counts: Map<Char, Int>): Boolean {
    var oddCount = 0
    for (count in counts.values) {
        if (count % 2 == 1) {
            oddCount++
            if (oddCount > 1) {
                return false
            }
        }
    }
    return true
}

// Построение палиндрома
fun buildPalindrome(counts: Map<Char, Int>): String {
    val left = StringBuilder()
    var middle = ""

    // Проходим по отсортированной карте (TreeMap), чтобы результат был стабильным
    val sortedCounts = counts.toSortedMap()

    for ((char, count) in sortedCounts) {
        // Добавляем половину символов в левую часть
        repeat(count / 2) {
            left.append(char)
        }
        // Если количество нечетное — этот символ пойдет в середину
        if (count % 2 == 1) {
            middle = char.toString()
        }
    }

    val leftPart = left.toString()
    val rightPart = leftPart.reversed()

    return leftPart + middle + rightPart
}

fun main() {
    val scanner = Scanner(System.`in`)
    
    if (!scanner.hasNext()) return
    val oldStr = scanner.next()
    
    val charCounts = sumChar(oldStr)

    if (!check(charCounts)) {
        println("No")
    } else {
        println("Yes")
        println(buildPalindrome(charCounts))
    }
}

// чтобы скомпилировать kotlinc hello.kt -include-runtime -d hello.jar и запустить java -jar hello.jar