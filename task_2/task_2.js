"use strict";


function limitations(str) {
    const symbols = "qwertyuiopasdfghjklzxcvbnm0123456789.+";
    const zapret = "&=+<>,_`-";

    
    if (!str.includes('@')) return false;

    const [strName, ...rest] = str.split('@');
    const domain = rest.join('@'); // На случай, если в домене тоже есть @ (хотя это некорректно)

    
    if (!domain.includes('.') || domain.length < 4) return false;

    // Проверка запрещенных символов в домене
    for (let char of domain) {
        if (zapret.includes(char)) return false;
    }

    if (strName.length < 6 || strName.length > 30) return false;

    
    if (str.includes('..')) return false;

    
    for (let char of strName) {
        if (!symbols.includes(char)) return false;
    }

    
    if (strName.startsWith('.') || strName.endsWith('.')) return false;

    return true;
}

function normalEmail(str) {
    let [name, domain] = str.split('@');

    // Отрезаем всё после '+'
    if (name.includes('+')) {
        name = name.split('+')[0];
    }

    // Удаляем все точки из имени
    const cleanName = name.split('.').join('');

    return `${cleanName}@${domain}`;
}


function startApp() {
    const emailsSet = new Set();
    

    const testInputs = [
        "my.email+extra@gmail.com",
        "myemail@gmail.com",
        "bad..email@test.com",
        "short@m.c",
        "very.long.name.with.points@domain.com",
        "end"
    ];

    for (let email of testInputs) {
        if (email === "end") break;

        if (!limitations(email)) {
            console.log(`EROR!!! (${email})`);
        } else {
            const normalized = normalEmail(email);
            emailsSet.add(normalized);
            console.log(`Added: ${normalized}`);
        }
    }

    
    console.log(`Уникальных адресов: ${emailsSet.size}`);
}

startApp();