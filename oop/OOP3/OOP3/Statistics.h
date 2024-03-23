#pragma once
#include <iostream>
#include <map>
#include <string>
#include "Opticaldevice.h"
#include "ODMatrix.h"


class Statistics {
private:
    std::map<const Opticaldevice*, int> dataDictionary; // ������� ��� �������� �������� Opticaldevice � ���������� �����
    double totallos = 0; // ����� �������� �������� ��� �������������� line of sight

public:
    void addATDToKK(const Opticaldevice* ATDPointer, int copies) {
        dataDictionary[ATDPointer] += copies; // ���������� ������� ATD � ������� � ��������� ����������� �����
    }

    void addATDToKKWithQuantity(ODMatrix* mx) {
        Opticaldevice* ATDPointer;
        char* name = new char[100];
        int copies;

        std::cout << "Enter name and amount of copies: ";
        std::cin >> name >> copies;
        if (mx->find(name)) {
            ATDPointer = mx->find(name); // ���������� ������� ATD � ������� ODMatrix
            dataDictionary[ATDPointer] += copies; // ���������� ������� ATD � ��������� ����������� ����� � �������
        }
        else std::cout << "There is no devices with name" << name;
    }

    void decreaseQuantity(const Opticaldevice* ATDPointer, int amount) {
        if (dataDictionary.find(ATDPointer) != dataDictionary.end()) {
            dataDictionary[ATDPointer] -= amount; // ���������� ���������� ������� ATD �� ���������� �����
            if (dataDictionary[ATDPointer] <= 0) {
                dataDictionary.erase(ATDPointer); // �������� ������� �� �������, ���� ���������� ����� ������� ��� �������������
            }
        }
    }

    void removeByKey(const Opticaldevice* ATDPointer) {
        dataDictionary.erase(ATDPointer); // �������� ������� �� ����� �� �������
    }

    void displayInfo() {
        std::cout << "statistics:" << std::endl;
        for (const auto& pair : dataDictionary) {
            std::cout << "Object: " << pair.first->get_name() << ", amount: " << pair.second << std::endl; // ����� ���������� � �������� ATD � �� ����������
        }
    }

    void calculateTotalValue() {
        totallos = 0;
        for (const auto& pair : dataDictionary) {
            totallos += pair.first->get_line_of_sight() * pair.second; // ������ ������ ��������� �������� �� �������������� ���� ������
        }
        std::cout << "Summary of line of sight: " << totallos << std::endl; // ����� ������ ��������� �������� �� �����
    }

    void clearDictionary() {
        dataDictionary.clear(); // ������� �������
        totallos = 0; // ����� ������ ��������� ��������
    }
};