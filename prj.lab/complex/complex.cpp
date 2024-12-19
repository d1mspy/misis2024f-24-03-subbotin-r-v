#include <complex/complex.hpp>
#include <cmath>
#include <limits>

Complex Complex::operator-() const noexcept { return Complex(-re, -im); }

bool Complex::operator==(const Complex& rhs) const noexcept {
	double eps = 2*std::numeric_limits<double>::epsilon();
	return (std::abs(re - rhs.re) <= eps) && (std::abs(im - rhs.im) <= eps);
}
bool Complex::operator!=(const Complex& rhs) const noexcept { return !(*this == rhs); }

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

Complex operator+(const Complex& lhs, const Complex& rhs) noexcept { return Complex(lhs) += rhs; }
