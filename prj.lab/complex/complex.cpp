#include "complex.hpp"
#include <iostream>
#include <sstream>
#include <stdexcept>
#include <limits>
#include <cmath>

Complex Complex::operator-() const noexcept { return Complex(-re, -im); }

bool Complex::operator==(const Complex& rhs) const noexcept {
	double eps = 2*std::numeric_limits<double>::epsilon();
	return (std::abs(re - rhs.re) <= eps) && (std::abs(im - rhs.im) <= eps);
}

bool Complex::operator!=(const Complex& rhs) const noexcept { 
	return !(*this == rhs); 
}

Complex& Complex::operator+=(const Complex& rhs) noexcept {
	re += rhs.re;
	im += rhs.im;
	return *this;
}
Complex& Complex::operator+=(const double rhs) noexcept {
	return operator+=(Complex(rhs)); 
}

Complex& Complex::operator-=(const Complex& rhs) noexcept {
	re -= rhs.re;
	im -= rhs.im;
	return *this;
}
Complex& Complex::operator-=(const double rhs) noexcept {
	return operator-=(Complex(rhs));
}

Complex& Complex::operator*=(const Complex& rhs) noexcept {
	re = re*rhs.re - im*rhs.im;
	im = re*rhs.im + rhs.re*im;
	return *this;
}
Complex& Complex::operator*=(const double rhs) noexcept {
	re *= rhs;
	im *= rhs;
	return *this;
}

Complex& Complex::operator/=(const Complex& rhs) noexcept {
	re = re*rhs.re + im*rhs.im;
	im = im*rhs.re - re*rhs.im;
	return operator/=(rhs.re*rhs.re + rhs.im*rhs.im);
}
Complex& Complex::operator/=(const double rhs) noexcept {
	re /= rhs;
	im /= rhs;
	return *this;
}

Complex operator+(const Complex& lhs, const Complex& rhs) noexcept {
	return Complex(lhs.re + rhs.re, lhs.im + rhs.im);
}

Complex operator+(const Complex& lhs, const double rhs) noexcept {
	return Complex(lhs.re + rhs, lhs.im);
}

Complex operator+(const double lhs, const Complex& rhs) noexcept {
	return Complex(lhs + rhs.re, rhs.im);
}

Complex operator-(const Complex& lhs, const Complex& rhs) noexcept {
	return Complex(lhs.re - rhs.re, lhs.im - rhs.im);
}

Complex operator-(const Complex& lhs, const double rhs) noexcept {
	return Complex(lhs.re - rhs, lhs.im);
}

Complex operator-(const double lhs, const Complex& rhs) noexcept {
	return Complex(lhs - rhs.re, -rhs.im);
}

Complex operator*(const Complex& lhs, const Complex& rhs) noexcept {
	return Complex(lhs.re*rhs.re - lhs.im*rhs.im, lhs.re*rhs.im + lhs.im*rhs.re);
}

Complex operator*(const Complex& lhs, const double rhs) noexcept {
	return Complex(lhs.re * rhs, lhs.im * rhs);
}

Complex operator*(const double lhs, const Complex& rhs) {
	return Complex(lhs * rhs.re, lhs * rhs.im);
}

Complex operator/(const Complex& lhs, const Complex& rhs) {
	return Complex( 
		(lhs.re * rhs.re + lhs.im * rhs.im) / (rhs.re * rhs.re + rhs.im * rhs.im),
		(lhs.im * rhs.re - lhs.re * rhs.im) / (rhs.re * rhs.re + rhs.im * rhs.im)
	);
}

Complex operator/(const Complex& lhs, const double rhs) {
	return Complex(lhs.re / rhs, lhs.im / rhs);
}

Complex operator/(const double lhs, const Complex& rhs) {
	return Complex(
		(lhs * rhs.re) / (rhs.re * rhs.re + rhs.im * rhs.im),
		(-lhs * rhs.im) /(rhs.re * rhs.re + rhs.im * rhs.im)
	);
}


std::ostream& Complex::WriteTo(std::ostream& ostrm) const noexcept {
    ostrm << leftBrace << re << separator << im << rightBrace;
    return ostrm;
}

std::istream& Complex::ReadFrom(std::istream& istrm) noexcept {
    char left_brace = 0;
    char right_brace = 0;
    char sep = 0;
    double real_part = 0.0;
    double imag_part = 0.0;

    if (istrm >> left_brace && left_brace == leftBrace &&
        istrm >> real_part &&
        istrm >> sep && sep == separator &&
        istrm >> imag_part &&
        istrm >> right_brace && right_brace == rightBrace) {
        re = real_part;
        im = imag_part;
    }
    else {
        istrm.setstate(std::ios::failbit);
    }

    return istrm;
}

