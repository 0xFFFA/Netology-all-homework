#include <unistd.h>
#include <iostream>
#include <fstream>

int main (void)
{
    std::ifstream infile;
    std::ofstream outfile;
    std::string buffer;
    int num;

    // Открываем файл in.txt
    infile.open ("/Users/alekseibelov/Documents/Netology/CPP-Netology-all-homework/04-Abstraction and incapsulation/01/in.txt");
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
    outfile.open ("/Users/alekseibelov/Documents/Netology/CPP-Netology-all-homework/04-Abstraction and incapsulation/01/out.txt");
    if (!outfile.is_open ())
    {
        std::cout << "Файл out.txt открыть не удалось!" << std::endl;
        return -1;
    }
    // Пишем туда кол-во блоков
    outfile << buffer << std::endl;

    for (int i = 1; i <= num; i++)
    {
        //Читаем файл
        // Довольно-таки тупой способ, но морочиться с циклом ради 4-х значний и не хотел
        infile >> buffer;
        outfile << buffer << ", ";
        infile >> buffer;
        outfile << buffer << ", ";
        infile >> buffer;
        outfile << buffer << ", ";
        infile >> buffer;
        outfile << buffer << std::endl;    
  
    }

    infile.close ();
    outfile.close ();
    return 0;
}