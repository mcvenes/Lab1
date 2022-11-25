#pragma once

#include "Person.h"
#include "MyStack.h"

#include <iostream>
#include <fstream>
#include <string>

// класс дл€ чтени€ и записи персон из файловых стримов
class PersonKeeper
{
public:
	// статический метод дл€ обращени€ к единственному экземпл€ру класса (singletone)
	static PersonKeeper& instance()
	{
		static PersonKeeper p;
		return p;
	}

	// метод чтени€ персон из файла filePath
	// возвращает стэк объектов класса Person
    MyStack<Person>* readPersons(const std::string& filePath, int maxSize) const;

	// метод записи стэка персон в стрим
	// stack передаем как копию, т.к. в ходе работы оригинальный объект не должен мен€тьс€
	void writePersons(MyStack<Person> stack, std::fstream &stream);

private:
	// приватный конструктор, т.к. singletone
	PersonKeeper() {}
};

