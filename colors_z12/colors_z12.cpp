//Поиск совпадающих цветов
#include <iostream>
#include <vector>
#include <ctime>

/*
═══════════░▓
══════════░▓▓
════════░▓░░▓
═══════▓▓░░░▓
▓════░▓░░░░░▓══════════░▓▓░
▓═══▒▓░░░░░░▓░══════░▓▓░░▓░
▓══▓▒═░░░░░░░▓════░▓▓░░░░▓
░▓▓░═░░░░░░░░▓══░▒▓░░░░░▒▓
░░░░░░░░░░░░░▒▓▓▓░░░░░░═▓═════░▓▓▓▓▓
░░░░░░░░░░░░░░░░░░░░░░░░▓═░▓▓▓▓░░▒▓
░░░░░░░░░░░░░░░░░░░░░░░░▓▓▓░░░═░▒▓░
░░░░░░░░░░░░░░░░░░░░░░░░░░░░░═░▓▓▒
░░░░░░░░░░░░░░░░░░░░░░░░░░░░░▒▓▓▒
░░░░░░░░░░░░░░░░░══░░░░░░░░░▒▓▓▓▓▓▓▓▓▓▓▓
░══════════░░════░▒▒░░░═░░░░▒░░░░░░░░░▓▓
▒░══░▒▒▓▓██▓══░▒█▓░════▒▓░░░═░░░═░░▒▓▓▒
▓█████████▓░▒▓███═══░▒██▒═░░░░░░░▒▓▓▒
▓█▓▓▓▓▓▓▓█▓█████══░▓████═══▒▒═░░░░░▓▓
▓▓▓▓▓▓▓▓▓██▓▓▓█▒░▓█████▒══▒▓▒═░░░░══▓▓▓▓
▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓████▓▓█░═▒▒█▓═░░░░░░▒▒▓
▓▓▓▓▓▓▓▓▓▓▓▓▓████▓▓▓▓▓▓═▒▓██▓═░░░═░▓▓▓
▓█▓▓▓▓▓▓▓▓▓▓▓██▓▓▓▓▓▓█▒▒████▓═░░░░▓
▒▒▓████████████████▓▓▓▓██▓▓█▓═░░═▓█
▒▒░░▒░░░░░░▒░▒▒▒▓▓██████▓▓▓█▓═░═▒▓█▓
▒██▒░░══════░▓░═░░░▒▒▓████▓▓█══░█══▓
▒▒▒▒░▒═░░░═░▓░░░░░░░░░░▒▓████══▓▒══▓
▒▒▓▓░▓═░░░═▒▓░░░░░░░░░░░░░▓██═▓▓══░▓
▒▓▓▒░▓═░░═▒▓░░░░░░░░░░░░░══▒▒▒██▒══▓
▓▒░░▒▓═══░▓░░░░░░░░░░░░░░▓▓▓▒░▓██▓═▓
▓▓░░▒▓═░░▒▒░░░░░░░░░░░░░░▓═▒█░░▓██▓▓
▓█▒░▒▓═▓▓▒░░░░░░░░░░░░░░░▓══██▒▒▓██
░░░░▒▓▒█▓░░░░░░░░░░░░░░░░▓═▒█▓▓▒██░
░░░░▒█▓▒░░░░▒░░░░░░░░░░░░░▓▓▓▒▒▒▒
▒░░░▒█▒░░░░▒▒▒▒▒▒▒▒▒▒▒░░░░▒▓▒░▓░
█▒░░▒▓░░░░░░░░░░░░▒▒▒▒▒░░░░░░░▓
▓▓░░▒▒░░░░░░░░░░░░░░░░░░░░░░░░▓
▒▓░░░░░░░▒▒▒▒▒▒▒▒▒▒▒░░░░░░░░░░░▓
▒▓░░░░░░░░░░░░░░░░░▒░░░░░░░░░░░▒▓
▒▓░░░░░░░░░░░░░░▒▒░░░░░░░░░░░░░░▓▒
▒▓░░░░░░░▒▒▒▒▒▒▒▒▒░░░░░░░░░░▒▓▓▒▒█░
▒▓▒░░░░░░▒▒░░░░░░░░░░░░░░░░░▒▓██▓▒
▒▓▓░░░░░░░░░░░░░░░░░░▒▒▒▒░░░░▓░
░▒▓▓░░░░░░░░░░░░░░░░▒▒▒▒▓▓▓░▓
░▒▓▓▓▒░░░░░░░░░░░░░░░░░░░▒▓█▓
░░█▒▒▓▓▒░░░░░░░░░░░░░░░░▒▒▓▒
░░▓▓▒▒▒▓▓▒░░░░░░░░░░░░░░░▒▓
░░▒█▒▒▒▒▒▓▓▒▒░░░░░░░░░░░░▓
░░░▓▓▒▒▒▒▒▒▓▓▓▒░░░░░░░░░░▓
░░░▒▓▒▒▒▒▒▒▒▒▒▓▓▓▒░░░░░░░▓
░░░░▓▒▒▒▒▒▒▒▒▒▒▓▓▓▒▒░░░░▓░
░░░░▓▓▒▒▒▒▒▒▓▓▓▓▓▓▓▓▓▓▓▓░
░░░░░▓▒▒▒▒▒▓░
▓▓██▓▓▓██▓▓██▒
▓▓██▓▓▓██▓▓██▒
▓▓██▓▓▓██▓▓██▒
▓▓██▓▓▓██▓▓██▒
Наруто помогает писать код
*/



int dataCheckInt(int integer) { //Проверка на int
	while (std::cin.fail() || integer < 0) {
		std::cin.clear();
		std::cin.ignore(1000, '\n');
		std::cout << "Ошибка, вы должны ввести целое неотрицательное число." << std::endl << "Введите число ещё раз: " << std::endl;
		std::cin >> integer;
	}
	return integer;
}

int randFunction(int maxValue) {
	int x = rand() % (maxValue) + 1;
	return x;
}

int findColorFunction(std::vector<std::vector<int>> &matrix, int i, int j) {
	if (matrix[i][j] == 0) { 
		return 0;
	}
	int counter = 1;
	int columnLength = matrix[0].size();
	int rowLength = matrix.size();
	
	if (i - 1 >= 0 && matrix[i][j] == matrix[i - 1][j]) {
		matrix[i][j] = 0;
		counter += findColorFunction(matrix, i - 1, j);
	}
	if (i+1 < rowLength && matrix[i][j] == matrix[i + 1][j]) {
		matrix[i][j] = 0;
		counter += findColorFunction(matrix, i + 1, j);
	}
	if (j + 1 < columnLength && matrix[i][j] == matrix[i][j + 1]) {
		matrix[i][j] = 0;
		counter += findColorFunction(matrix, i, j + 1);
	}
	if (j-1 >= 0 && matrix[i][j] == matrix[i][j - 1]) {
		matrix[i][j] = 0;
		counter += findColorFunction(matrix, i, j - 1);
	}
	return counter;
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

	std::cout << "Введите максимальное значение: " << std::endl;
	int maxValue = 0;
	std::cin >> maxValue;
	maxValue = dataCheckInt(maxValue);

		std::vector <std::vector<int>> matrix;

	//Заполнение случайными числами
	for (int i = 0; i < rows; i++) {
		std::vector <int> row;
		for (int j = 0; j < colums; j++) {
			row.push_back(randFunction(maxValue));
		}
		matrix.push_back(row);
	}
	std::vector <int> maxNum;
	for (int i = 0; i < maxValue+1; i++) {
		maxNum.push_back(0);
	}
	//Не поверите, вывод
	for (int i = 0; i < rows; i++) {
		for (int j = 0; j < colums; j++) {
			std::cout << matrix[i][j];
			std::cout << " ";
		}
		std::cout << std::endl;
	}
	for (int i = 0; i < rows; i++) {
		for (int j = 0; j < colums; j++) {
			if (matrix[i][j] == 0) {
				continue;
			}
			int v = matrix[i][j];
			int z = findColorFunction(matrix, i, j);
			if (maxNum[v - 1] < z) {
				maxNum[v - 1] = z;
			}
		}
	}


	
	for (int i = 0; i < maxNum.size()-1; i++) {
		std::cout << i+1 << ". " << maxNum[i]<<std::endl;
	}



	return 0;
}