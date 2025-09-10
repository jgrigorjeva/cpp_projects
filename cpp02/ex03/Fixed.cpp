#include "Fixed.hpp"
#include <iostream>
#include <cmath>

Fixed::Fixed(): _raw_bits(0)
{
	// std::cout << "Default costructor called\n";
}

Fixed::Fixed(const int num)
{
	// std::cout << "Int constructor called\n";
	_raw_bits = num << _fract_bits;
}

Fixed::Fixed(const float num)
{
	// std::cout << "Float constructor called\n";
	_raw_bits = static_cast<int>(roundf(num * (1 << _fract_bits)));
	// shifts the "decimal" point to the right by _frac_bits and makes the resulting float an integer for storing
}


Fixed::Fixed(const Fixed &other): _raw_bits(other._raw_bits)
{
	// std::cout << "Copy costructor called\n";
}


Fixed &Fixed::operator=(const Fixed &other)
{
	if (this != &other)
	{
		this->_raw_bits = other._raw_bits; //can go with just _raw_bits instead of this->_raw_bits, but making it explicit for clarity
	}
	// std::cout << "Copy assignment operator called" << std::endl;
	return (*this); // Required for chaining
}

Fixed::~Fixed()
{
	// std::cout << "Destructor called\n";
}

int Fixed::getRawBits( void ) const
{
	// std::cout << "getRawBits member function called\n";
	return (_raw_bits);
}

void Fixed::setRawBits( int const raw )
{
	_raw_bits = raw;
	// std::cout << "setRawBits member function called\n";
}

float Fixed::toFloat( void ) const
{
	float result;

	result = static_cast<float>(_raw_bits) / (1<<_fract_bits);
	return result;
}

int Fixed::toInt( void ) const
{
	int result;

	// result = _raw_bits >> _fract_bits; //maybe round instead of truncating
	result = static_cast<int>(roundf(static_cast<float>(_raw_bits) / (1 << _fract_bits)));
	return result;
}

std::ostream& operator<<(std::ostream& out, const Fixed& src)
{
	out << src.toFloat();
	return out;
}

// comparison operators overload
bool Fixed::operator>(const Fixed& other) const
{
	return (this->_raw_bits > other._raw_bits);
}

bool Fixed::operator<(const Fixed& other) const
{
	return (this->_raw_bits < other._raw_bits);
}

bool Fixed::operator>=(const Fixed& other) const
{
	return (this->_raw_bits >= other._raw_bits);
}

bool Fixed::operator<=(const Fixed& other) const
{
	return (this->_raw_bits <= other._raw_bits);
}

bool Fixed::operator==(const Fixed& other) const
{
	return (this->_raw_bits == other._raw_bits);
}

bool Fixed::operator!=(const Fixed& other) const
{
	return (this->_raw_bits != other._raw_bits);
}

// arithmetic operators overload
Fixed Fixed::operator+(const Fixed& other) const
{
	Fixed result;

	result._raw_bits = this->_raw_bits + other._raw_bits;
	return (result);
}

Fixed Fixed::operator-(const Fixed& other) const
{
	Fixed result;

	result._raw_bits = this->_raw_bits - other._raw_bits;
	return (result);
}

Fixed Fixed::operator*(const Fixed& other) const
{
	Fixed result;

	result._raw_bits = (this->_raw_bits * other._raw_bits) >> _fract_bits;
	return (result);
}

Fixed Fixed::operator/(const Fixed& other) const
{
	Fixed result;

	result._raw_bits = (this->_raw_bits / other._raw_bits) << _fract_bits;
	return (result);
}

// increment/decrement operators overload
Fixed& Fixed::operator++()
{
	++_raw_bits;
	return *this;
}

Fixed Fixed::operator++(int)
{
	Fixed tmp(*this);
	++(*this);
	return tmp;
}

Fixed& Fixed::operator--()
{
	--_raw_bits;
	return *this;
}

Fixed Fixed::operator--(int)
{
	Fixed tmp(*this);
	--(*this);
	return tmp;
}

// min max
Fixed& Fixed::min(Fixed& num1, Fixed& num2)
{
	if (num1 < num2)
		return (num1);
	return (num2);
}
const Fixed& Fixed::min(const Fixed& num1, const Fixed& num2)
{
	if (num1 < num2)
		return (num1);
	return (num2);
}
Fixed& Fixed::max(Fixed& num1, Fixed& num2)
{
	if (num1 > num2)
		return (num1);
	return (num2);
}
const Fixed& Fixed::max(const Fixed& num1, const Fixed& num2)
{
	if (num1 > num2)
		return (num1);
	return (num2);
}