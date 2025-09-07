#include "Fixed.hpp"
#include <iostream>

Fixed::Fixed(): _raw_bits(0)
{
	std::cout << "Default costructor called\n"
}

Fixed::Fixed(const Fixed &other): _raw_bits(other._raw_bits)
{
	std::cout << "Copy costructor called\n";
}


Fixed &Fixed::operator=(const Fixed &other)
{
	if (this != &other)
	{
		this->_raw_bits = other._raw_bits; //can go with just _raw_bits instead of this->_raw_bits, but making it explicit for clarity
	}
	std::cout << "Copy assignment operator called!" << std::endl;
	return (*this); // Required for chaining
}

Fixed::~Fixed()
{
	std::cout << "Destructor called\n";
}

int Fixed::getRawBits( void ) const
{
	std::cout << "getRawBits member function called\n";
	return (_raw_bits);
}

void Fixed::setRawBits( int const raw )
{
	_raw_bits = raw;
	std::cout << "setRawBits member function called\n";
}