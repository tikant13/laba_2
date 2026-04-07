import Foundation

func main() {
    var n = 0
    var number = 0
    var kvad = 0 // количество чисел полные квадраты

    // Читаем количество чисел
    if let inputN = readLine(), let valN = Int(inputN) {
        n = valN
    }

    for _ in 1...n {
        // Читаем каждое число в цикле
        if let inputNum = readLine(), let valNum = Int(inputNum) {
            number = valNum
            
            let numSqrt = Int(sqrt(Double(number)))
            
            if (numSqrt * numSqrt) == number {
                kvad += 1
            }
        }
    }

    print("Результат: \(kvad)")
}

main()