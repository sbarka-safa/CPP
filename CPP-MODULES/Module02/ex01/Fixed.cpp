#include "Fixed.hpp"

Fixed::Fixed( void ) : _fixedPointValue(0){
    std::cout << "Default constructor called" << std::endl;
}

Fixed::~Fixed( void ){
    std::cout << "Destructor called" << std::endl;
}

Fixed::Fixed(Fixed const  & src)
{
    std::cout << "Copy constructor called" << std::endl;
    *this = src;
}

Fixed const  & Fixed::operator = (Fixed const & src)
{
    std::cout << "Assignation operator called" << std::endl;
    if(this != &src)
       this->_fixedPointValue = src.getRawBits();

    return *this;
}

int Fixed::getRawBits( void ) const {
   return _fixedPointValue;
}

void Fixed::setRawBits(int const raw)
{
    _fixedPointValue = raw;
}
/*
    A constructor that takes a constant integer as a parameter and 
    that converts it to the correspondant fixed(8) point value.
*/
Fixed::Fixed(int const & x )
{
    std::cout << "Int constructor called" << std::endl;
    // 1 << 8  == 2 ^ 8 = 256
    this->_fixedPointValue =  x * (1 << _bitFractio);

}

/*
    A constructor that takes a constant floating point as a parameter and 
    that convertsit to the correspondant fixed(8) point value.
*/
Fixed::Fixed(float  const & x)
{
    std::cout << "Float constructor called" << std::endl;
    this->_fixedPointValue = std::roundf(x * (1 << _bitFractio));
}
/*
    A member functionfloat toFloat( void ) const;that 
    converts the fixed pointvalue to a floating point 
    value
*/
float  Fixed::toFloat( void )  const 
{
    return ((float)_fixedPointValue / (float)(1 << _bitFractio));
}

/*
    A member functionint toInt( void ) const;that converts the 
    fixed point valueto an integer value
*/

int Fixed::toInt( void ) const
{
    return (roundf(_fixedPointValue /(1 << _bitFractio)));
}

std::ostream & operator << (std::ostream & o ,Fixed const & src){
    o << src.toFloat();
    return o;
}

const int Fixed::_bitFractio = 8;

//https://pediaa.com/difference-between-fixed-point-and-floating-point/
//https://www.forth.com/starting-forth/5-fixed-point-arithmetic/