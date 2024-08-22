#include <iostream>

// Постановку задачи см. README.md

// Объявляем класс калькулятор
class TCalc
{
    private:
        double num1, num2;
    public:
        double Add ();
        double Multiply ();
        double Substruct_1_2 ();
        double Substruct_2_1 ();
        double Divide_1_2 ();
        double Divide_2_1 ();
        bool Set1 (double value);
        bool Set2 (double value); 
};

double TCalc::Add ()
{
    return num1 + num2;
}

double TCalc::Multiply ()
{
    return num1 * num2;
}

double TCalc::Substruct_1_2 ()
{
    return num1 - num2;
}

double TCalc::Substruct_2_1 ()
{
    return num2 - num1;
}

double TCalc::Divide_1_2 ()
{
    // Проверка на ноль, а то вдруг после создания объекта и присваивания значений по дефолту будет попытка произвести деление
    if (num2 != 0)
        return num1 / num2;
}

double TCalc::Divide_2_1 ()
{
    // Проверка на ноль, а то вдруг после создания объекта и присваивания значений по дефолту будет попытка произвести деление
    if (num1 != 0)
        return num2 / num1;
}

bool TCalc::Set1 (double value)
{
    if (value == 0)
    {
        std::cout << "Неверное значение" << std::endl;
        return false;
    }
    else
    {
        num1 = value;
        return true;
    }
}

bool TCalc::Set2 (double value)
{
    if (value == 0)
    {
        std::cout << "Неверное значение" << std::endl;
        return false;
    }
    else
    {
        num2 = value;
        return true;
    }
}


int main (void)
{
    double inp;
    TCalc calc;
 
    // Запускаем бесконечный цикл
    while (true)
    {
        // Вводим первое значение 
        do 
        {
            std::cout << "Введите num1: ";
            std::cin >> inp;
        } while (!calc.Set1 (inp));
        // И второе таким же макаром
        do 
        {
            std::cout << "Введите num2: ";
            std::cin >> inp;
        } while (!calc.Set2 (inp));

        // И выводим скопом на экран результаты работы
        std::cout << "num 1 + num2 = " << calc.Add () << std::endl;
        std::cout << "num 1 * num2 = " << calc.Multiply () << std::endl;
        std::cout << "num 1 - num2 = " << calc.Substruct_1_2 () << std::endl;
        std::cout << "num 2 - num1 = " << calc.Substruct_2_1 () << std::endl;
        std::cout << "num 1 / num2 = " << calc.Divide_1_2 () << std::endl;
        std::cout << "num 2 / num1 = " << calc.Divide_2_1 () << std::endl;
    }

    return 0;
}