; Компиляция:
; nasm -f elf64 main.asm -o main.o
; gcc main.o -o main -no-pie
; Запуск: ./main

section .data
    
    fmt_in:      db "%d", 0
    fmt_out:     db "Результат: %d", 10, 0 ; 10 - это символ новой строки (\n)

section .bss
    n:           resd 1    ; переменная n (int, 4 байта)
    number:      resd 1    ; переменная number (int, 4 байта)
    kvad:        resd 1    ; переменная kvad (int, 4 байта)

section .text
    global main
    extern printf, scanf, sqrt

main:
    push rbp                ; сохраняем базовый указатель
    mov rbp, rsp

    
    lea rdi, [rel fmt_in]   ; первый аргумент scanf: формат
    lea rsi, [rel n]        ; второй аргумент: адрес n
    xor eax, eax            ; зануляем eax (требование ABI для функций с переменным числом аргументов)
    call scanf

    
    mov dword [rel kvad], 0

    
    mov r12d, 1             ; используем r12d для хранения i

loop_start:
   
    mov eax, [rel n]
    cmp r12d, eax
    jg loop_end             ; если i > n, выходим из цикла


    lea rdi, [rel fmt_in]
    lea rsi, [rel number]
    xor eax, eax
    call scanf

   
    cvtsi2sd xmm0, dword [rel number] ; переводим int в double для функции sqrt
    call sqrt                         ; xmm0 = sqrt(number)
    cvttsd2si eax, xmm0               ; переводим double обратно в int (с отсечением)
   

    
    mov ebx, eax            ; ebx = numSqrt
    imul eax, eax           ; eax = numSqrt * numSqrt
    
    mov ecx, [rel number]   ; ecx = number
    cmp eax, ecx            ; сравниваем (numSqrt * numSqrt) и number
    jne skip_increment      ; если не равны, пропускаем инкремент

   
    inc dword [rel kvad]

skip_increment:
    inc r12d                ; i++
    jmp loop_start          ; возвращаемся к началу цикла

loop_end:
    
    lea rdi, [rel fmt_out]  ; формат вывода
    mov esi, [rel kvad]     ; значение kvad
    xor eax, eax
    call printf

   
    mov eax, 0
    pop rbp
    ret
