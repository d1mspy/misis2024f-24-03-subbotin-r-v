#pragma once
#ifndef RATIONAL_RATIONAL_HPP_20241113
#define RATIONAL_RATIONAL_HPP_20241113

#include <cstdint>
#include <iosfwd>
#include <algorithm>

class Rational {
public:
	// умолчательный и копирующий конструкторы 
	Rational() = default;
	Rational(const Rational&) = default;

	explicit Rational(const std::int32_t num) noexcept : num_(num) { } // конструктор из int32_t
	Rational(const std::int32_t num, const std::int32_t den); //конструктор с числителем и знаменателем

	~Rational() = default; // деструктор

	Rational& operator=(const Rational&) = default; // копирующее присваивание

	// возвращение числителя и знаменателя
	[[nodiscard]] std::int32_t num() const noexcept { return num_; }
	[[nodiscard]] std::int32_t den() const noexcept { return den_; }

	// операторы сравнения
	[[nodiscard]] bool operator==(const Rational& rhs) const noexcept;
	[[nodiscard]] bool operator!=(const Rational& rhs) const noexcept;
	[[nodiscard]] bool operator<(const Rational& rhs) const noexcept;
	[[nodiscard]] bool operator<=(const Rational& rhs) const noexcept;
	[[nodiscard]] bool operator>(const Rational& rhs) const noexcept;
	[[nodiscard]] bool operator>=(const Rational& rhs) const noexcept;

	// унарный минус
	[[nodiscard]] Rational operator-() const noexcept { return { -num_, den_ }; }

	//присваивающие операторы с рациональными числами
	Rational& operator+=(const Rational& rhs) noexcept;
	Rational& operator-=(const Rational& rhs) noexcept;
	Rational& operator*=(const Rational& rhs) noexcept;
	Rational& operator/=(const Rational& rhs);

	//присваивающие операторы с int32_t
	Rational& operator+=(const int32_t& rhs) noexcept;
	Rational& operator-=(const int32_t& rhs) noexcept;
	Rational& operator*=(const int32_t& rhs) noexcept;
	Rational& operator/=(const int32_t& rhs);

	// форматированный ввод вывод
	std::ostream& WriteTo(std::ostream& ostrm) const noexcept;
	std::istream& ReadFrom(std::istream& istrm);

private:
	// значения числителя и знаменателя по умолчанию
	std::int32_t num_ = 0;
	std::int32_t den_ = 1;

	// сокращение дроби
	void Normalize() noexcept;
};

// арифметические операторы для рациональных чисел и int32_t
[[nodiscard]] Rational operator+(const Rational& lhs, const Rational& rhs) noexcept;
[[nodiscard]] Rational operator-(const Rational& lhs, const Rational& rhs) noexcept;
[[nodiscard]] Rational operator*(const Rational& lhs, const Rational& rhs) noexcept;
[[nodiscard]] Rational operator/(const Rational& lhs, const Rational& rhs);

[[nodiscard]] Rational operator+(const Rational& lhs, const int32_t& rhs) noexcept;
[[nodiscard]] Rational operator-(const Rational& lhs, const int32_t& rhs) noexcept;
[[nodiscard]] Rational operator*(const Rational& lhs, const int32_t& rhs) noexcept;
[[nodiscard]] Rational operator/(const Rational& lhs, const int32_t& rhs);

[[nodiscard]] Rational operator+(const int32_t& lhs, const Rational& rhs) noexcept;
[[nodiscard]] Rational operator-(const int32_t& lhs, const Rational& rhs) noexcept;
[[nodiscard]] Rational operator*(const int32_t& lhs, const Rational& rhs) noexcept;
[[nodiscard]] Rational operator/(const int32_t& lhs, const Rational& rhs);

// форматированный ввод/вывод
inline std::ostream& operator<<(std::ostream& ostrm, const Rational& rhs) noexcept {
	return rhs.WriteTo(ostrm);
}

inline std::istream& operator>>(std::istream& istrm, Rational& rhs) {
	return rhs.ReadFrom(istrm);
}

#endif