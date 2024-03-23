#pragma once
#include <iostream>
#include <map>
#include <string>
#include "Opticaldevice.h"
#include "ODMatrix.h"


class Statistics {
private:
    std::map<const Opticaldevice*, int> dataDictionary; // Словарь для хранения объектов Opticaldevice и количества копий
    double totallos = 0; // Общее числовое значение для характеристики line of sight

public:
    void addATDToKK(const Opticaldevice* ATDPointer, int copies) {
        dataDictionary[ATDPointer] += copies; // Добавление объекта ATD в словарь с указанным количеством копий
    }

    void addATDToKKWithQuantity(ODMatrix* mx) {
        Opticaldevice* ATDPointer;
        char* name = new char[100];
        int copies;

        std::cout << "Enter name and amount of copies: ";
        std::cin >> name >> copies;
        if (mx->find(name)) {
            ATDPointer = mx->find(name); // Нахождение объекта ATD в матрице ODMatrix
            dataDictionary[ATDPointer] += copies; // Добавление объекта ATD с указанным количеством копий в словарь
        }
        else std::cout << "There is no devices with name" << name;
    }

    void decreaseQuantity(const Opticaldevice* ATDPointer, int amount) {
        if (dataDictionary.find(ATDPointer) != dataDictionary.end()) {
            dataDictionary[ATDPointer] -= amount; // Уменьшение количества объекта ATD по указанному ключу
            if (dataDictionary[ATDPointer] <= 0) {
                dataDictionary.erase(ATDPointer); // Удаление объекта из словаря, если количество стало нулевым или отрицательным
            }
        }
    }

    void removeByKey(const Opticaldevice* ATDPointer) {
        dataDictionary.erase(ATDPointer); // Удаление объекта по ключу из словаря
    }

    void displayInfo() {
        std::cout << "statistics:" << std::endl;
        for (const auto& pair : dataDictionary) {
            std::cout << "Object: " << pair.first->get_name() << ", amount: " << pair.second << std::endl; // Вывод информации о объектах ATD и их количестве
        }
    }

    void calculateTotalValue() {
        totallos = 0;
        for (const auto& pair : dataDictionary) {
            totallos += pair.first->get_line_of_sight() * pair.second; // Расчет общего числового значения по характеристике поля зрения
        }
        std::cout << "Summary of line of sight: " << totallos << std::endl; // Вывод общего числового значения на экран
    }

    void clearDictionary() {
        dataDictionary.clear(); // Очистка словаря
        totallos = 0; // Сброс общего числового значения
    }
};