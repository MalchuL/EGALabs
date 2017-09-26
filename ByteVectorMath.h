#pragma once
#include "ByteVector.h"
class ByteVectorMath
{
public:
	static int HemmingLength(ByteVector & vect1, ByteVector & vect2);
	static ByteVector GrayCode(const ByteVector& vect) {
		return vect.SymmetrycSumm(vect.offestRight(1));
	
	
	}
};

