#pragma once
#ifndef ARRAYD_ARRAYD_HPP_20241120
#define ARRAYD_ARRAYD_HPP_20241120

#include <cstddef>

class ArrayD {
public:
	// умолчательный и копирующий конструкторы
	ArrayD() = default;
	ArrayD(const ArrayD&);

	// конструктор с заданным размером
	ArrayD(const std::ptrdiff_t size);
	
	// деструктор
	~ArrayD();

	// оператор присваивания
	ArrayD& operator=(const ArrayD&);

	// метод получения размера
	[[nodiscard]] std::ptrdiff_t Size() const noexcept { return size_; }

	// метод изменения размера
	void Resize(const std::ptrdiff_t size);

	// оператор доступа к элементу по индексу
	[[nodiscard]] double& operator[](const std::ptrdiff_t idx); // ссылка для модификации элемента
	[[nodiscard]] double operator[](const std::ptrdiff_t idx) const; // копия элемента для работы с константным значением

	// вставка элементов в массив
	void Insert(const std::ptrdiff_t idx, const double val);

	// удаление элементов из массива
	void Remove(const std::ptrdiff_t idx);

private:
	// объем выделенной памяти(вместимость), размер и указатель на данные
	std::ptrdiff_t capacity_ = 0;
	std::ptrdiff_t size_ = 0;
	double* data_ = nullptr;
};

#endif