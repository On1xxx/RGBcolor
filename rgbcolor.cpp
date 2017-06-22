#include "rgbcolor.hpp"

/*****************************************************************************/

RGBColor::RGBColor(unsigned char _Red, unsigned char _Green, unsigned char _Blue)
	: Red(_Red), Green(_Green), Blue(_Blue)
{
	RGBPacked = ((_Red << 16) & 0xFF0000) + ((_Green << 8) & 0x00FF00) + (_Blue & 0x0000FF);
}

/*****************************************************************************/

RGBColor::RGBColor(unsigned int _Packed)
	:RGBPacked(_Packed)
{
	Red = _Packed >>16 ;
	Green = (_Packed - (_Packed & 0xFF0000)) >> 8;
	Blue = (_Packed - (_Packed & 0xFF0000)) - (_Packed & 0x00FF00);
}

/*****************************************************************************/

double RGBColor::getBlackKey() const
{
	return (1 - Max((double)Red / 255.0, (double)Green / 255.0, (double)Blue / 255.0));
}

/*****************************************************************************/

double RGBColor::getCyanColor() const
{
	return  (k==1) ? 0.0 : ((1 - (double)Red / 255.0 - k) / (1 - k));
}

/*****************************************************************************/

double RGBColor::getMagentaColor() const
{
	return (k==1) ? 0.0 : ((1 - (double)Green / 255.0 - k) / (1 - k));
}

/*****************************************************************************/

double RGBColor::getYellowColor() const
{
	return (k == 1) ? 0.0 : ((1 - (double)Blue / 255.0 - k) / (1 - k));
}

/*****************************************************************************/

double RGBColor::Max(double _q, double _w, double _e) const
{
	double max = _q;
	if (max < _w) max = _w;
	if (max < _e) max = _e;

	return max;
}

/*****************************************************************************/

bool RGBColor::operator == (RGBColor c) const
{
	
	return Red == c.getRed() &&
		   Green == c.getGreen() &&
		   Blue == c.getBlue() &&
		   RGBPacked == c.getPackedRGB();
}

/*****************************************************************************/

bool RGBColor::operator != (RGBColor c) const
{

	return !(*this == c);
}

/*****************************************************************************/

RGBColor & RGBColor::operator += (RGBColor _c)
{
	
	Red += _c.getRed();
	Green += _c.getGreen();
	Blue += _c.getBlue();
	RGBPacked += _c.getPackedRGB();


	return *this;
}


/*****************************************************************************/

RGBColor RGBColor::operator + (RGBColor _c) const
{
	RGBColor result = *this;
	result += _c;
	return result;

}

/*****************************************************************************/

std::ostream & operator << (std::ostream & s, RGBColor _c)
{
	
	s << '#' << std::uppercase << std::hex;

	if ((int)_c.Red == 0 && (int)_c.Green == 0 && (int)_c.Blue == 0)
		s << "00000" << _c.RGBPacked;
	
	else if ((int)_c.Red == 0 && (int)_c.Green == 0) 
		s << "0000"  << _c.RGBPacked;

	else if ((int)_c.Red == 0) 
		s << "00"<< _c.RGBPacked;
	 
	else if ((int)_c.Red < 16) 
		s << '0'<< _c.RGBPacked;

	else s  << _c.RGBPacked;
	
	return s;
}

/*****************************************************************************/