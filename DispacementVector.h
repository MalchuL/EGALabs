#pragma once
#include <vector>
#include "IllegalVectorSizeException.h"
using namespace exceptions;
using namespace std;
typedef int num;
class DispacementVector
{	
	vector<num> displacement;
public:
	bool CheckValue() const;
	DispacementVector();

	int getSize() const;
	DispacementVector(int size);
	void setNum(int pos, num value);
	num getNum(int pos) const;
	void InsertWithRightOffset(int pos, num value);
	DispacementVector(num * displacement, unsigned int size);



	bool operator<(const DispacementVector& other)const {
		if (getSize() != other.getSize())throw IllegalVectorSizeException(getSize(), other.getSize());

		long int thisvect=0;
		long int othervect = 0;
		//нужно, чтобы ввести систему счисления
		long int ten = getSize();
		for (size_t i = 1; i <= getSize(); i++)
		{
			thisvect += ten*getNum(i);
			othervect += ten*other.getNum(i);
			ten *= 10;
		}

		return thisvect < othervect;
	
	}
	bool operator==(const DispacementVector& other)const {
		if (getSize() != other.getSize())throw IllegalVectorSizeException(getSize(), other.getSize());
		for (int i = 1; i <= getSize(); i++)
		{
			if (getNum(i) != other.getNum(i))return false;
		}
		return true;
	}
	friend ostream& operator<<(ostream& a, const DispacementVector&vect);
};



