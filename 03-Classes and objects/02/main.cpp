#include <iostream>

// Постановку задачи см. README.md

class TCounter
{
    private:
        int counter;
    public:
        TCounter ();
        TCounter (int value);
        void Increase ();
        void Decrease ();
        void Show ();
};

TCounter::TCounter ()
{
    counter = 1;
}

TCounter::TCounter (int value)
{
    counter = value;
}

void TCounter::Increase ()
{
    counter++;
}

void TCounter::Decrease ()
{
    counter --;
}

void TCounter::Show ()
{
    std::cout << counter << std::endl;
}

int main (void)
{
    std::string inp;
    int value;
    TCounter *counter;

    std::cout << "Вы хотите указать начальное значение счётчика? Введите да или нет: ";
    std::cin >> inp;
    if (inp == "да")
    {
        std::cout << "Введите начальное значение счетчика: ";
        std::cin >> value;
        counter = new TCounter (value);
    }
    else
        counter = new TCounter;

    while (true)
    {

        std::cout << "Введите команду ('+', '-', '=' или 'x'): ";
        std::cin >> inp;
        
        // Вообще я думал, что С++ уже умеет в switch и std::string, но оказалось, что нет
        // Делаем через if elsif 
        if (inp == "+")
            counter -> Increase ();
        else if (inp == "-")
            counter -> Decrease ();
        else if (inp == "=")
            counter -> Show ();
        else if (inp == "x")
            return 0;

    }
    
    delete counter;
    return 0;
}