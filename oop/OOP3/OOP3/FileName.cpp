#pragma once
#include "lens_type.h"
#include "Opticaldevice.h"
#include "string"
#include <iostream>
#include "ODMatrix.h"
#include "Statistics.h"

using namespace std;

int main() {
	//Opticaldevice device1;
	//device1.set_name("ma");
	//cout << "Name:" << device1.get_name() << endl;
	//device1.set_aperture(0.1);
	//cout << "Apperture:" << device1.get_aperture() << endl;
	//device1.set_line_of_sight(2);
	//cout << "line_of_sight:" << device1.get_line_of_sight() << endl;
	//device1.print();
	//device1.get_lens_type();
	ODMatrix* Mx = new ODMatrix;
	Opticaldevice* d2 = new Opticaldevice;
	Opticaldevice* d3 = new Opticaldevice;
	d2->set_line_of_sight(40);
	d3->set_line_of_sight(4);
	d2->set_name("aaa");
	d3->set_name("bbb");
	Mx->add(d2);

	Statistics stat;
	stat.addATDToKKWithQuantity(Mx);
	stat.addATDToKK(d3, 4);
	stat.displayInfo();
	cout << "bbb decrese quanity by 1" << endl;
	stat.decreaseQuantity(d3, 1);
	stat.displayInfo();
	stat.calculateTotalValue();
	stat.removeByKey(d2);
	cout << "delete aaa" << endl;
	stat.displayInfo();
	stat.clearDictionary();
	stat.displayInfo();
	system("pause");
	return 0;
}