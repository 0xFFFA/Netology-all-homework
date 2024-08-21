
#include <iostream>

/*
Напишите программу, которая спрашивает у пользователя номер месяца и выводит на экран название месяца, введённого пользователем.

Если пользователь ввёл некорректный номер месяца, сообщите ему об этом.

Спрашивайте пользователя до тех пор, пока он не введёт 0.

Для решения задачи воспользуйтесь перечислением.
*/

// Определяем перечисление, явно указываем значения
enum  eMonths
{
    January = 1,
    February = 2,
    March = 3,
    Aplril = 4,
    May = 5,
    June = 6,
    July = 7,
    August = 8,
    September = 9,
    October = 10,
    November = 11,
    December = 12
}; 

int main (void)
{
    // Переменная - перечисление
    eMonths mo;
    // Переменная, куда будем вводить данные
    short int someinput = 1;

    // Далее делаем невообразимо тупой цикл, работаем, пока someinput не равен 0
    do
    {
        // Спрашиваем про номер месяца
        std::cout << "\nPlease enter a month number: ";
        std::cin >> someinput;
        // Проверяем, диапазон должен быть [1..12]
        if (someinput >= 1 && someinput <= 12)
        {
            // Присваиваем переменной значение через приведение типов
            mo = static_cast <eMonths> (someinput);
            // И теперь надо вывести наименование месяца
            switch (mo)
            {
                case 1: 
                    std::cout << "January";
                    break;
                case 2: 
                    std::cout << "February";
                    break;
                case 3: 
                    std::cout << "March";
                    break;
                case 4: 
                    std::cout << "April";
                    break;
                case 5: 
                    std::cout << "May";
                    break;
                case 6: 
                    std::cout << "June";
                    break;
                case 7: 
                    std::cout << "July";
                    break;
                case 8: 
                    std::cout << "August";
                    break;
                case 9: 
                    std::cout << "September";
                    break;
                case 10: 
                    std::cout << "October";
                    break;
                case 11: 
                    std::cout << "November";
                    break;
                case 12: 
                    std::cout << "December";
                    break;    
            }
        } 
        else
        {
            std::cout << "Value should be from 1 till 12\n";
        }        

    } while (someinput != 0);

    return 0;
}