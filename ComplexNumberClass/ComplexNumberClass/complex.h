#ifndef COMPLEX_H_
#define COMPLEX_H_

#include "stdafx.h"
#include <iostream>

namespace cop {
	class Complex {
	private:
		double real;
		double imaginary;

	public:
		// Constructors and Destructors
		Complex();
		Complex(double real, double imaginary);
		Complex(const Complex &other);  // Copy constructor
		~Complex() {}

		// Getters
		double getReal() const;
		double getImaginary() const;

		// Assignment overloading
		const Complex &operator=(const Complex &other);
		// Overloading the == and != operators
		bool operator==(const Complex &other) const;
		bool operator!=(const Complex &other) const;
	};

	// Left bitshift overloading
	std::ostream &operator<<(std::ostream &out, const Complex &c);

	// addition overloading
	Complex operator+(const Complex &c1, const Complex &c2);
	Complex operator+(const Complex &c1, double d);
	Complex operator+(double d, const Complex &c1);

} // namespace cop

#endif