#pragma once
#include "ByteVector.h"
class ByteVectorMath
{
public:
	static int HemmingLength(ByteVector & vect1, ByteVector & vect2);
	static ByteVector GrayCodeEncoder(const ByteVector& vect) {
		return vect.SymmetrycSumm(vect.offestRight(1));
	
	
	}
	static ByteVector GrayCodeDecoder(const ByteVector& vect) {
		ByteVector returnedvector = vect;
		for (size_t i = 1; i < returnedvector.getLen(); i++)
		{
			returnedvector = returnedvector.SymmetrycSumm(vect.offestRight(i));
		}
		return returnedvector;
	}
};

