#include <iostream>

// Описание задачи см. файл README.md

// Задаем структуру, содержащую адрес
struct sPostAddress
{
    std::string city;
    std::string street;
    std::string building;
    std::string appartment;
    std::string index;
};

// Функция вывода экземпляра структуры, содержащей адрес, на экран
void ShowAddress (sPostAddress *addr)
{
    std::cout << "Город: " << addr -> city << std::endl;
    std::cout << "Улица: " << addr -> street << std::endl;
    std::cout << "Дом: " << addr -> building << std::endl;
    std::cout << "Квартира: " << addr -> appartment << std::endl;
    std::cout << "Индекс: " << addr -> index << std::endl;
}

int main (void)
{
    // Задаем две переменные, содержащие структуру адреса 
    sPostAddress s1, s2;
    //  Заполняем
    s1.city = "Москва";
    s1.street = "Арбат";
    s1.building = "12";
    s1.appartment = "8";
    s1.index = "123456";

    s2.city = "Ижевск";
    s2.street = "Пушкина";
    s2.building = "59";
    s2.appartment = "143";
    s2.index = "953769";

    ShowAddress (&s1);
    ShowAddress (&s2);

    return 0;
}