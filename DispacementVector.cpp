#include "stdafx.h"
#include "DispacementVector.h"

ostream& operator<<(ostream& a, const DispacementVector&vect) {
	a << "(";
	for (int i = 1; i <= vect.getSize(); i++)
	{
		
		a << vect.getNum(i)<<',';
	}
	a << ")";
	return a;
}

bool DispacementVector::CheckValue() const {
	for (num i = 1; i < getSize() + 1; i++)
	{
		//	if (find(displacement.begin(), displacement.end(), i) == displacement.end())return false;
		if (count(displacement.begin(), displacement.end(), i) != 1)return false;
	}
	return true;
}

DispacementVector::DispacementVector() {
	displacement = vector<num>(1);
	displacement[0] = 1;
}

int DispacementVector::getSize() const {
	return displacement.size();
}

DispacementVector::DispacementVector(int size) {
	this->displacement = vector<num>(size);
	for (size_t i = 0; i < size; i++)
	{
		this->displacement[i] = i + 1;
	}
}

void DispacementVector::setNum(int pos, num value) {
	displacement[pos - 1] = value;
}

num DispacementVector::getNum(int pos) const {
	return displacement[pos - 1];
}

void DispacementVector::InsertWithRightOffset(int pos, num value) {
	for (size_t i = getSize(); i > pos; i--)
	{
		setNum(i, getNum(i - 1));
	}
	setNum(pos, value);
}

inline DispacementVector::DispacementVector(num * displacement, unsigned int size) {
	this->displacement = vector<num>(size);
	for (size_t i = 0; i < size; i++)
	{
		this->displacement[i] = displacement[i];
	}
}
