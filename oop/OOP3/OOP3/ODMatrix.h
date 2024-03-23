#pragma once
#include "Opticaldevice.h"
#include <iostream>

class ODMatrix {
public:
	~ODMatrix(); //����������

	void add(Opticaldevice* d); //���������� ��������
	void deleteDevice(int n); //�������� ��������
	void printData()const; //����� �� ����� �����������
	void sort();	//���������� �� aperture
	void printnamed(char* name)const;	//����� �� ����� ��������� � �������� ������
	void searchapperture(float a)const;	//����� ���������, � ������� aperture ���� ��������� ��������
	Opticaldevice** getarray()const;  //��������� ���������� ������ ���������� �� �������� ������� 
	Opticaldevice* find(char* name)const;
private:
	Opticaldevice* **matrix = NULL;
	int size = 0;
};