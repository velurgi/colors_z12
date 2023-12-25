//Поиск совпадающих цветов
#include <iostream>
#include <vector>
#include <ctime>

int dataCheckInt(int integer) { //Проверка на int
    while (std::cin.fail() || integer < 0) {
        std::cin.clear();
        std::cin.ignore(1000, '\n');
        std::cout << "Ошибка, вы должны ввести целое неотрицательное число." << std::endl << "Введите число ещё раз: " << std::endl;
        std::cin >> integer;
    }
    return integer;
}

int randFunction() {
    int x = rand() % 8 + 1;
    return x;
}

int main()
{
    srand(time(0));
    setlocale(LC_ALL, "RU");

    std::cout << "Введите количество строк: " << std::endl;
    int rows = 0;
    std::cin >> rows;
    rows = dataCheckInt(rows);

    std::cout << "Введите количество столбцов: " << std::endl;
    int colums = 0;
    std::cin >> colums;
    colums = dataCheckInt(colums);

    std::vector <std::vector<int>> matrix;

    //Заполнение случайными числами
    for (int i = 0; i < rows; i++) {
        std::vector <int> row;
        for (int j = 0; j < colums; j++) {
            row.push_back(randFunction());
        }
        matrix.push_back(row);
    }
    

    





    //Не поверите, вывод
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < colums; j++) {
            std::cout << matrix[i][j];
            std::cout << " ";
        }
        std::cout << std::endl;
    }
    return 0;
}