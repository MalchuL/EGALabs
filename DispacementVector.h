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
	bool CheckValue() const {
		for (num i = 1; i < getSize()+1; i++)
		{
		//	if (find(displacement.begin(), displacement.end(), i) == displacement.end())return false;
			if (count(displacement.begin(), displacement.end(), i) != 1)return false;
		}
		return true;
	}
	DispacementVector() {
		displacement= vector<num>(1);
		displacement[0] = 1;
	}

	int getSize() const {
		return displacement.size();
	}
	DispacementVector(int size) {
		this->displacement = vector<num>(size);
		for (size_t i = 0; i < size; i++)
		{
			this->displacement[i] = i+1;
		}
	}
	void setNum(int pos, num value) {
		displacement[pos - 1] = value;
	}
	num getNum(int pos) const {
		return displacement[pos-1];
	}
	DispacementVector(num * displacement, unsigned int size) {
		this->displacement = vector<num>(size);
		for (size_t i = 0; i < size; i++)
		{
			this->displacement[i] = displacement[i];
		}
	}
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



