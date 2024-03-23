#pragma once
#include "Opticaldevice.h"
#include <iostream>

class ODMatrix {
public:
	~ODMatrix(); //деструктор

	void add(Opticaldevice* d); //добавление элемента
	void deleteDevice(int n); //удаление элемента
	void printData()const; //вывод на экран содержимого
	void sort();	//сортировка по aperture
	void printnamed(char* name)const;	//вывод на экран элементов с заданным именем
	void searchapperture(float a)const;	//поиск элементов, у которых aperture выше заданного значения
	Opticaldevice** getarray()const;  //возвращат одномерный массив указателей на элементы матрицы 
	Opticaldevice* find(char* name)const;
private:
	Opticaldevice* **matrix = NULL;
	int size = 0;
};