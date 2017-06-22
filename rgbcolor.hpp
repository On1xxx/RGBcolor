#ifndef _RGBCOLOR_HPP_
#define _RGBCOLOR_HPP_

/*****************************************************************************/

#include <iostream>
#include <string>

/*****************************************************************************/

class RGBColor
{ 
	
	unsigned char Red;
	unsigned char Green;
	unsigned char Blue;
	unsigned int RGBPacked;


public:

	/*****************************************************************************/
	RGBColor(unsigned char _Red, unsigned char _Green, unsigned char _Blue);
	RGBColor(unsigned int _Packed);
	

	unsigned char getRed() const;
	unsigned char getGreen() const;
	unsigned char getBlue() const;
	unsigned int getPackedRGB() const;

	double Max(double _q, double _w, double _e) const;


	double getBlackKey() const;
	double getCyanColor() const;
	double getMagentaColor() const;
	double getYellowColor() const;


	const double k = getBlackKey();

	bool operator == (RGBColor c) const;
	bool operator != (RGBColor c) const;
	RGBColor operator + (RGBColor _c) const;
	RGBColor & operator += (RGBColor _ñ);
	RGBColor getInvertedColor() const;

	friend std::ostream & operator << (std::ostream & s, RGBColor _c);

	/*****************************************************************************/
};

/*****************************************************************************/

inline 
unsigned char RGBColor::getRed() const
{
	return Red;
}

/*****************************************************************************/

inline 
unsigned char RGBColor::getGreen() const
{
	return Green;
}

/*****************************************************************************/

inline 
unsigned char RGBColor::getBlue() const
{
	return Blue;
}

/*****************************************************************************/

inline unsigned int RGBColor::getPackedRGB() const
{
	return RGBPacked;
}

/*****************************************************************************/

inline RGBColor RGBColor::getInvertedColor() const
{
	unsigned int a = RGBPacked ^ 0xFFFFFF;
	RGBColor result(a);
	return result;

}

/*****************************************************************************/

#endif //  _RGBCOLOR_HPP_

