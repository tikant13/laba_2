use std:: collections::HashMap; // вместо map
use std::io; // для ввода и вывода

fn sum_char(s : &str) -> HashMap<char, i32> { // эта функция отвечает за счёт кол-ва букв 
    let mut result: HashMap<char, i32> = HashMap::new();
    for i in s.chars() {
        *result.entry(i).or_insert(0) += 1; // позволяет найти значение или втавить 0, если ключа нет
    }
    result
}
// Проверяем на возможность создания палиндрома
fn check(counts: &HashMap<char, i32>) -> bool{
    let mut odd_count = 0;
    for &count in counts.values() {
        if count % 2 != 0 {
            odd_count += 1;
        }
        if odd_count > 1 {
            return false;
        }
    }
    true
}

fn palindrom(counts: &HashMap<char, i32>) -> String { // полиндром строим 
    let mut left = String::new();
    let mut middle = String::new();

    
    for (&ch, &count) in counts { // итерация по HashMap дает ссылки на ключ и значение
        let half: usize = (count / 2) as usize; // Добавляем половину символов в левую часть
        left.push_str(&ch.to_string().repeat(half));

        if count % 2 != 0 {
            middle = ch.to_string();
        }
    }

    // Создаем правую часть: копируем левую и разворачиваем
    let right: String = left.chars().rev().collect();

    format!("{}{}{}", left, middle, right)
}
fn main() {
   let mut old_str: String = String::new();
   io::stdin().read_line(&mut old_str).unwrap();
   let old_str = old_str.trim(); // Убираем символ переноса строки \n

    let counts: HashMap<char, i32> = sum_char(&old_str);
    if !check(&counts) {
        println!("No");
    } else {
        println!("Yes");
        println!("{}", palindrom(&counts));
    }
}
// cargo run