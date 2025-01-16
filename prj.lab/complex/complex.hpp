

#ifndef COMPLEX_COMPLEX_H_20191010
#define COMPLEX_COMPLEX_H_20191010

#include <iosfwd>

struct Complex {
    Complex() = default; // умолчательный конструктор

    Complex(const Complex&) = default; // копирующий конструктор

    Complex(Complex&&) = default; // конструктор перемещения

    explicit Complex(const double real) : re(real) { } // конструктор комлексного числа из вещественного

    Complex(const double real, const double imaginary) : re(real), im(imaginary) {} // конструктор с вещественной и мнимой частями

    Complex &operator=(const Complex&) = default; // копирующее присваивание
    Complex &operator=(Complex&&) = default; // перемещающее присваивание

    ~Complex() = default; // деструктор

    [[nodiscard]] Complex operator-() const noexcept; // унарный минус

    [[nodiscard]] bool operator==(const Complex& rhs) const noexcept; // равенство
    [[nodiscard]] bool operator!=(const Complex& rhs) const noexcept; // неравенство

    Complex& operator+=(const Complex& rhs) noexcept; // присваивающее сложение с Complex
    Complex& operator+=(const double rhs) noexcept; // присваивающее сложение с double

    Complex& operator-=(const Complex& rhs) noexcept; // присваивающее вычитание Complex
    Complex& operator-=(const double rhs) noexcept; // присваивающее вычитание double

    Complex& operator*=(const Complex& rhs) noexcept; // присваивающее умножение на Complex 
    Complex& operator*=(const double rhs) noexcept; // присваивающее умножение на double

    Complex& operator/=(const Complex& rhs) noexcept; // присваивающее деление на Complex
    Complex& operator/=(const double rhs) noexcept; // присваивающее деление на double

    [[nodiscard]] std::ostream& WriteTo(std::ostream& ostrm) const noexcept; // форматированный вывод в поток ostrm
    [[nodiscard]] std::istream& ReadFrom(std::istream& istrm) noexcept; // форматированный ввод из потока istrm

    double re{0.0}; // определение вещественной части
    double im{0.0}; // определение мнимой части

    static const char leftBrace{ '{' };   // левая скобка форматированного представления
    static const char separator{ ',' };   // разделитель форматированного представления
    static const char rightBrace{ '}' };  // правая скобка форматированного представления
};

[[nodiscard]] Complex operator+(const Complex& lhs, const Complex& rhs) noexcept; // сложение комплексных чисел

[[nodiscard]] Complex operator+(const Complex& lhs, const double rhs) noexcept; // сложение комплексного и вещественного чисел
[[nodiscard]] Complex operator+(const double lhs, const Complex& rhs) noexcept; // сложение вещественного и комплексного чисел

[[nodiscard]] Complex operator-(const Complex& lhs, const Complex& rhs) noexcept; // вычитание комплексных чисел
[[nodiscard]] Complex operator-(const Complex& lhs, const double rhs) noexcept; // вычитание вещественного числа из комплексного
[[nodiscard]] Complex operator-(const double lhs, const Complex& rhs) noexcept; // вычитание комплексного числа из вещественного

[[nodiscard]] Complex operator*(const Complex& lhs, const Complex& rhs) noexcept; // умножение комплексных чисел
[[nodiscard]] Complex operator*(const Complex& lhs, const double rhs) noexcept; // умножение комплексного числа на вещественное
[[nodiscard]] Complex operator*(const double lhs, const Complex& rhs) noexcept; // умножение вещественного числа на комплексное

[[nodiscard]] Complex operator/(const Complex& lhs, const Complex& rhs); // деление комплексных чисел
[[nodiscard]] Complex operator/(const Complex& lhs, const double rhs); // деление комплексных чисел
[[nodiscard]] Complex operator/(const double lhs, const Complex& rhs); // деление комплексных чисел

// Форматированный вввод в потока ostrm комплексного числа \se Complex::write_to.
inline std::ostream& operator<<(std::ostream& ostrm, const Complex& rhs) noexcept {
	return rhs.WriteTo(ostrm);
}

// Форматированный ввод из потока istrm комплексного числа \se Complex::read_from.
inline std::istream& operator>>(std::istream& istrm, Complex& rhs) noexcept {
	return rhs.ReadFrom(istrm);
}

#endif