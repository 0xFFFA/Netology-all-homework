#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>

// См. постановку задачи в README.md 

// Задаем структуру, обрабатывать будем массив структур
struct sAddress
{
    std::string city;
    std::string street;
    std::string building;
    std::string appartment;

    // Перегружаем оператор < для работы метода sort
    bool operator<(const sAddress &r) const
    {
        if (city != r.city) {
            return city < r.city;
        }
    }

};

// Делаем тупо, можно было заморочится с классом, прятать в нем все и было бы покрасивее
// Но, не смотря на название модуля Abstraction & Incapsulation, тут ничего про абстракцию и инкапсуляцию нет
// А когда я делал игру Жизнь, мне сказали, что классы там как из пушки по воробьям
// Поэтому функциональное программирование наше все, пока не разрешает обратное ))
// P.S. Переписал Жизнь на C# и без классов и объектов. На C# получилось проще


int main (void)
{
    std::ofstream outfile;
    std::ifstream infile;
    std::string buffer;
    int num;

    // Открываем файл in.txt
    infile.open ("/Users/alekseibelov/Documents/Netology/CPP-Netology-all-homework/04-Abstraction and incapsulation/02/in.txt");
    if (!infile.is_open ())
    {
        std::cout << "Файл in.txt открыть не удалось!" << std::endl;
        return -1;
    }
    
    // Читаем заголовок файла, там указано количество записей
    infile >> buffer;
    // Переводим строку в int
    num = std::stoi (buffer);
    // Проверяем на всякий случай на предмет всяких шалостей
    if (num <= 0)
    {
        std::cout << "Что-то не так с заголовком файла!" << std::endl;
        return -1;
    }

    // Открываем файл out.txt
    outfile.open ("/Users/alekseibelov/Documents/Netology/CPP-Netology-all-homework/04-Abstraction and incapsulation/02/out.txt");
    if (!outfile.is_open ())
    {
        std::cout << "Файл out.txt открыть не удалось!" << std::endl;
        return -1;
    }
    // Пишем туда кол-во блоков
    outfile << buffer << std::endl;

    // Определяем память под массив структур
    std::vector <sAddress> data;
    sAddress temp;

    // Читаем файл, заносим в массив структур
    for (int i = 0; i <= num - 1; i++)
    {
        infile >> temp.city;
        infile >> temp.street;
        infile >> temp.building;
        infile >> temp.appartment;
        data.push_back (temp);
    }

    // Тут будет сортировка. Я умею в разные сортировки, но решил, раз уж я тут использую вектора, то пусть будет сортировка стандартыми средствами
    // Единственный момент - пришлось оператор < перегрузить
    std::sort (data.begin (), data.end ());

    // Выводим в файл 
    for (int i = 0; i <= num - 1; i++)
    {
        outfile << data [i].city << ", " << data [i].street << ", " << data [i].building << ", " << data [i].appartment << "." << std::endl;
    }

    // Чистим за собой

    outfile.close ();
    infile.close ();

    return 0;
}