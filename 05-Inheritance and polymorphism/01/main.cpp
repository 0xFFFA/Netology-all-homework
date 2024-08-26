#include <iostream>

// Описание задачи см. README.md

// Определяем класс фигуры, затем от него наследуем треугольник и четырехугольник
// Делаем конструктор, определяющий кол-во сторон, и функцию просмотра кол-ва сторон
// Функцию просмотра кол-ва сторон перегрузим, хотя можно было и не перегружать, а сделать иначе
// Просто добавить наименование фигуры и выводить наименование и кол-во сторон
// Но я выбрал и перегрузить
// Все просто, без блекджека и поэтесс

class TFigure
{
    protected:
        short int NumberOfSides;
    public:
        TFigure (void);
        void ShowNOS (void);
};

// Для неизвестной фигуры кол-во сторон равно 0
TFigure::TFigure (void)
{
    NumberOfSides = 0;
}

// Функция показа кол-ва сторон
void TFigure::ShowNOS (void)
{
    std::cout << "Фигура: " << NumberOfSides << std::endl;
}

// Класс треугольник, наследованный от фигуры
class TTriangle : public TFigure
{
    public:
        TTriangle (void);
        void ShowNOS (void);
};

TTriangle::TTriangle (void)
{
    NumberOfSides = 3;
}

// Функция показа кол-ва сторон
void TTriangle::ShowNOS (void)
{
    std::cout << "Треугольник: " << NumberOfSides << std::endl;
}

class TQuadrangle : public TFigure
{
    public:
        TQuadrangle (void);
        void ShowNOS (void);
};

TQuadrangle::TQuadrangle (void)
{
    NumberOfSides = 4;
}

void TQuadrangle::ShowNOS (void)
{
    std::cout << "Четырехугольник: " << NumberOfSides << std::endl;
}


int main (void)
{
    // Объявляем объекты всех трех классов
    TFigure figure;
    TTriangle triangle;
    TQuadrangle quadrangle;

    figure.ShowNOS ();
    triangle.ShowNOS ();
    quadrangle.ShowNOS ();

    return 0;
}