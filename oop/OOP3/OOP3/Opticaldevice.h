#pragma once
#include "Lens_type.h"

class Opticaldevice {
public:
	Opticaldevice(); //конструктор по умолчанию
	Opticaldevice(const char* _name, float _aperture, lens_type _type, float line_of_sight); //конструктор инициализатор
	Opticaldevice(const Opticaldevice& m); //копирующий конструктор
	~Opticaldevice(); //деструктор
	void set_line_of_sight(float _line_of_sight); //сеттеры
	void set_name(const char* _name);
	void set_lens_type(lens_type _type);
	void set_aperture(float _aperture);

	float get_line_of_sight()const; //геттеры
	char* get_name()const;
	void get_lens_type();
	float get_aperture()const;
	void print()const; //вывод
	bool operator>(int b);
	bool operator==(char* name);
private:
	float line_of_sight; //поле зрения в метрах
	char* name; //название
	lens_type type; //тип линзы
	static int amount; //количество
	float aperture; //светопроницаемостm от 0 до 1
};

