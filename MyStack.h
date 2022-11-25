#pragma once

#include "EStack.h"


// шаблонный класс MyStack, в котором вместо T может быть какой-то тип: int, double ...
template <typename T>
class MyStack {
public:
	// конструктор
	explicit MyStack(size_t size)
		: maxSize(size)
		, currentSize(0)
	{
		data = new T[size]; //выделяем память под данные
	};

	// в десттрукторе освобождаем память
	~MyStack() {
		// do nothing
	}

	bool isFull() const
	{
		return (currentSize == maxSize);
	}

	bool isEmpty() const
	{
		return (currentSize == 0);
	}

	size_t size() const {
		return currentSize;
	}

	size_t capacity() const {
		return maxSize;
	}

	// метод добавления в конец
	void push(const T& value) {
		if (isFull()) {
			// Если currentSize == maxSize, значит мы заполнили все имеющиеся ячейки - переполнение
			throw Exc::EStackOverflow("Size limit of MyStack is reached!");
		}

		data[currentSize] = value;
		++currentSize;
	}

	// метод удаления из конца
	const T& pop() {
		if (isEmpty()) {
			// если так, то стек пуст и бросаем исключение
			throw Exc::EStackEmpty("This instance of MyStack is empty!");
		}

		--currentSize;
		return data[currentSize];
	}

private:
	T* data; // указатель на данные в кусе

	size_t maxSize; // храним максимально допустимый размер
	size_t currentSize; // индекс элемента за последним на данный момент
};
