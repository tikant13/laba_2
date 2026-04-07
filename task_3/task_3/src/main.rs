use std::io;
use std::f64;

fn main() {
    let mut input = String::new();

    // ввод n
    io::stdin().read_line(&mut input).unwrap();
    let n: i32 = input.trim().parse().unwrap();

    let mut kvad = 0; // количество чисел полные квадраты

    for _i in 1..=n {
        input.clear();
        io::stdin().read_line(&mut input).unwrap();
        let number: i32 = input.trim().parse().unwrap();

        let num_sqrt = (number as f64).sqrt() as i32;

        if num_sqrt * num_sqrt == number {
            kvad += 1;
        }
    }

    println!("Результат: {}", kvad);
}