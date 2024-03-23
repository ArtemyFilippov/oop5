
#include "ODMatrix.h"
#include "iostream"

using namespace std;

ODMatrix::~ODMatrix() {
	for (int i = 0; i < this->size; i++)
	{
		delete[] matrix[i];
	}
	delete[] matrix;
};

void ODMatrix::add(Opticaldevice* d) {
	// если матрица пуста, то выделяем память под первый объект класса
	if (size == 0) {
		matrix = new Opticaldevice * *[1];
		matrix[0] = new Opticaldevice * [1];
		matrix[0][0] = d;
		size = 1;
		return;
	}

	// проверяем, есть ли место для добавления элемента
	int row = 0, col = 0;
	bool found = false;
	for (row = 0; row < size; row++) {
		for (col = 0; col < size; col++) {
			if (matrix[row][col] == NULL) {
				found = true;
				break;
			}
		}
		if (found) {
			break;
		}
	}

	if (found) {
		matrix[row][col] = d; // на свободное место
		return;
	}

	// если нет свободного места, то увеличиваем размер матрицы на 1 в каждую строну
	Opticaldevice*** temp = new Opticaldevice * *[size + 1];
	for (int i = 0; i < size + 1; i++) {
		temp[i] = new Opticaldevice * [size + 1];
		for (int j = 0; j < size + 1; j++) {
			temp[i][j] = NULL;
		}
	}

	// копируем существующие элементы в новую матрицу
	for (int i = 0; i < size; i++) {
		for (int j = 0; j < size; j++) {
			temp[i][j] = matrix[i][j];
		}
	}

	temp[size][0] = d; // добавляем новый элемент
	delete[] matrix; // освобождаем память от старой матрицы
	matrix = temp;
	size++;
};

void ODMatrix::deleteDevice(int n) {
	matrix[n / size][n % size] = NULL;
};


std::ostream& operator<<(std::ostream& os, const Opticaldevice& matrix) {
	os << matrix.get_aperture();
	return os;
}

void ODMatrix::printData()const {
	for (int i = 0; i < size; i++) {
		for (int j = 0; j < size; j++) {
			if (matrix[i][j] == NULL) cout << "0";
			else cout << *matrix[i][j] <<  endl;
			cout << " ";
		}
		cout << endl;
	}
};

void ODMatrix::sort() {
	bool f1 = 0;
	while (!f1) {
		f1 = 1;
		for (int i = 0; i < size * size - 1; i++) {  //сдвигаем ненулевые значения влево
			if (matrix[i / size][i % size] == NULL && (matrix[(i + 1) / size][(i + 1) % size] != NULL)) {
				swap(matrix[i / size][i % size], matrix[(i + 1) / size][(i + 1) % size]);
				f1 = 0;
			}
		}
	}
	int a = 0;
	float m = 0;
	while (matrix[a / size][a % size] != NULL) a++; //a - кол-во ненулевых элементов
	int jk;
	for (int i = 0; i < a - 1; i++) {
		for (int j = i; j < a - 1; j++) {
			if (*matrix[j / size][j % size] > m) m = matrix[j / size][j % size]->get_aperture(); jk = j;
		}
		swap(matrix[jk / size][jk % size], matrix[i / size][i % size]);
		m = 0;
	}
};

void ODMatrix::printnamed(char* name)const {
	for (int i = 0; i < size; i++) {
		for (int j = 0; j < size; j++) {
			if (matrix[i][j] != NULL && *matrix[i][j] == name) matrix[i][j]->print();
		}
	}
};

Opticaldevice* ODMatrix::find(char* name)const {
	for (int i = 0; i < size; i++) {
		for (int j = 0; j < size; j++) {
			if (matrix[i][j] != NULL && *matrix[i][j]->get_name() == *name) return matrix[i][j];
			else return 0;
		}
	}
}

void ODMatrix::searchapperture(float a)const {
	for (int i = 0; i < size; i++) {
		for (int j = 0; j < size; j++) {
			if (matrix[i][j] != NULL && matrix[i][j]->get_aperture() >= a) matrix[i][j]->print();
		}
	}
};

Opticaldevice** ODMatrix::getarray()const {
	Opticaldevice** arr = new Opticaldevice * [size * size];
	for (int i = 0; i < size; i++) {
		for (int j = 0; j < size; j++) arr[i * size + j] = matrix[i][j];
	}
	return arr;
}
