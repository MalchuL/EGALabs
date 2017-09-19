#pragma once
#include "ByteVector.h"
class ByteVectorMath
{
public:
	static int HemmingLength(ByteVector & vect1, ByteVector & vect2) {
		int size = (vect1.getLen() > vect1.getLen()) ? vect1.getLen() : vect2.getLen();
		int length = 0;
		for (size_t i = 0; i < size; i++)
		{
			if (vect1.getChar(i) != vect2.getChar(i))length++;
		}
		return length;

	}

};

