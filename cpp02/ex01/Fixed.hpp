#ifndef FIXED_H
# define FIXED_H
#include <iostream>

class Fixed
{
  private:
	int _raw_bits;
	static const int _fract_bits = 8;

  public:
	Fixed();
	Fixed(const int);
	Fixed(const float);

	Fixed(const Fixed &other);
	Fixed& operator=(const Fixed& other);
	~Fixed();
	int getRawBits( void ) const;
	void setRawBits( int const raw );
	float toFloat( void ) const;
	int toInt( void ) const;

};

std::ostream& operator<<(std::ostream& out, const Fixed& src);


#endif