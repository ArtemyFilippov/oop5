#pragma once
#include "Lens_type.h"

class Opticaldevice {
public:
	Opticaldevice(); //����������� �� ���������
	Opticaldevice(const char* _name, float _aperture, lens_type _type, float line_of_sight); //����������� �������������
	Opticaldevice(const Opticaldevice& m); //���������� �����������
	~Opticaldevice(); //����������
	void set_line_of_sight(float _line_of_sight); //�������
	void set_name(const char* _name);
	void set_lens_type(lens_type _type);
	void set_aperture(float _aperture);

	float get_line_of_sight()const; //�������
	char* get_name()const;
	void get_lens_type();
	float get_aperture()const;
	void print()const; //�����
	bool operator>(int b);
	bool operator==(char* name);
private:
	float line_of_sight; //���� ������ � ������
	char* name; //��������
	lens_type type; //��� �����
	static int amount; //����������
	float aperture; //�����������������m �� 0 �� 1
};

