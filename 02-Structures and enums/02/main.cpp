#include <iostream>
#include <string>

// See task decsription at README.md

// Задаем структуру банковского счета
struct sBankAccount
{
    std::string name;
    int account;
    double sum;
};

void FillBankAccount (sBankAccount *acc)
{
    std::cout << "Введите номер счета ";
    std::cin >> acc -> account;
    std::cout << "Введите имя владельца ";
    std::cin >> acc -> name;
    std::cout << "Введите баланс ";
    std::cin >> acc -> sum;    
}

int main (void)
{
    // Объявляем переменную структуры
    sBankAccount account;
    // Заполняем экземпляр структуры
    FillBankAccount (&account);
    // Выводим данные из экземпляра структуры
    std::cout << "Ваш счет:" << account.name << ", " << account.account << ", " << account.sum << std::endl;
    
    return 0;
}