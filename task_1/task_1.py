def sum_char(s):
    """Считает количество букв в строке."""
    result = {}
    for char in s:
        
        result[char] = result.get(char, 0) + 1 # get(char, 0) вернет 0, если ключа еще нет в словаре
    return result

def check_palindrome(char_map):
    """Проверяет, можно ли из этих букв составить палиндром."""
    odd_count = 0
    for count in char_map.values():
        if count % 2 == 1:
            odd_count += 1
            if odd_count > 1:
                return False
    return True

def build_palindrome(char_map):
    """Строит сам палиндром."""
    left = []
    middle = ""
    
    
    for char in sorted(char_map.keys()): # Сортируем ключи
        count = char_map[char]
        left.append(char * (count // 2)) # Добавляем половину символов в левую часть
        if count % 2 == 1: # Если количество нечетное, этот символ пойдет в середину
            middle = char
            
    left_str = "".join(left)
    return left_str + middle + left_str[::-1] # В Python разворот строки делается через срез [::-1]

def main():
    old_str = input().strip()
    char_map = sum_char(old_str)
    
    if not check_palindrome(char_map):
        print("No")
    else:
        print("Yes")
        print(build_palindrome(char_map))

if __name__ == "__main__":
    main()

    # python3 task_1.py