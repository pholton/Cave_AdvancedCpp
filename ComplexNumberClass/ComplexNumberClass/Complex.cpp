#include "stdafx.h"
#include "complex.h"
#include <iostream>

cop::Complex::Complex() : real(0), imaginary(0) {

}

cop::Complex::Complex(double real, double imaginary) : real(real), imaginary(imaginary) {
	
}

cop::Complex::Complex(const Complex &other) {
	// Use the overloaded assignment operator for the copy constructor
	*this = other;
}

double cop::Complex::getReal() const {
	return real;
}

double cop::Complex::getImaginary() const {
	return imaginary;
}

const cop::Complex &cop::Complex::operator=(const cop::Complex &other) {
	real = other.real;
	imaginary = other.imaginary;
	return *this;
}

bool cop::Complex::operator==(const cop::Complex &other) const {
	return (real == other.real) && (imaginary == other.imaginary);
}

bool cop::Complex::operator!=(const cop::Complex &other) const {
	return !(*this == other);
}

std::ostream &cop::operator<<(std::ostream &out, const cop::Complex &c) {
	out << "(" << c.getReal() << "," << c.getImaginary() << ")";
	return out;
}

cop::Complex cop::operator+(const cop::Complex &c1, const cop::Complex &c2) {
	return Complex(c1.getReal() + c2.getReal(), c1.getImaginary() + c2.getImaginary());
}

cop::Complex cop::operator+(const cop::Complex &c1, double d) {
	return Complex(c1.getReal() + d, c1.getImaginary());
}

cop::Complex cop::operator+(double d, const cop::Complex &c1) {
	return Complex(c1.getReal() + d, c1.getImaginary());
}