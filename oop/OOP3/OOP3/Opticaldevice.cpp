
#include "lens_type.h"
#include "Opticaldevice.h"
#include "iostream"

using namespace std;

Opticaldevice::Opticaldevice() {
	delete[]this->name;
	this->name = new char[20];
	this->aperture = 1.0;
	this->line_of_sight = 1.0;
	this->type = lens_type::straight;

};

int Opticaldevice::amount = 1;

Opticaldevice::Opticaldevice(const char* _name, float _aperture, lens_type _type, float _line_of_sight) {
	this->name = new char[strlen(_name) + 1];
	strcpy_s(this->name, strlen(_name), _name);
	this->aperture = _aperture;
	this->type = _type;
	this->line_of_sight = _line_of_sight;
};

Opticaldevice::Opticaldevice(const Opticaldevice& m) {
	this->aperture = m.aperture;
	this->line_of_sight = m.line_of_sight;
	this->type = m.type;
	this->name = new char[strlen(m.name)];
	strcpy_s(this->name, strlen(m.name) + 1, m.name);
};

Opticaldevice::~Opticaldevice() {
	delete[]this->name;
};

float Opticaldevice::get_line_of_sight()const {
	return this->line_of_sight;
};

void Opticaldevice::get_lens_type() {
	switch (this->type) {
	case lens_type::converging: cout << "converging"; break;
	case lens_type::straight: cout << "straight"; break;
	case lens_type::diverging: cout << "diverging"; break;
	}
};

float Opticaldevice::get_aperture()const {
	return this->aperture;
};

char* Opticaldevice::get_name()const {
	char* cpyname;
	cpyname = new char[strlen(this->name) + 1];
	strcpy_s(cpyname, strlen(this->name) + 1, this->name);
	return cpyname;
};

void Opticaldevice::set_name(const char* _name) {
	delete[] this->name;
	this->name = new char[strlen(_name) + 1];
	strcpy_s(this->name, strlen(_name) + 1, _name);
};

void Opticaldevice::set_aperture(float _aperture) {
	this->aperture = _aperture;
};

void Opticaldevice::set_line_of_sight(float _lineofsight) {
	this->line_of_sight = _lineofsight;
};

void Opticaldevice::set_lens_type(lens_type _type) {
	this->type = _type;
}

void Opticaldevice::print()const {
	cout << "Name:" << this->name << endl;
	cout << "Aperture:" << this->aperture << endl;
	cout << "Line of sight:" << this->line_of_sight << endl;
	cout << "lens type:";
}

bool Opticaldevice::operator>(int b) {
	return this->get_aperture() > b;
};

bool Opticaldevice::operator==(char* name) {
	return this->get_name() == name;
}
