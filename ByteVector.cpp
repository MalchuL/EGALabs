#include "stdafx.h"
#include "ByteVector.h"


byte ByteVector::getChar(int id) {
	return word[id];
}

ByteVector ByteVector::offestRight(int offsetsize) const {
	ByteVector returnedvect = ByteVector();
	for (int i = 0; i < size; i++)
	{

		if (offsetsize + i >= size || offsetsize + i < 0)
		{
			returnedvect.word[i] = 0;
		}
		else
		{
			returnedvect.word[i] = this->word[i + offsetsize];
		}
	}
	return returnedvect;
}

ByteVector ByteVector::offestLeft(int offsetsize) const { return offestRight(-offsetsize); }

ByteVector ByteVector::SymmetrycSumm(const ByteVector & vect) {
	ByteVector returnedvect = ByteVector();
	for (size_t i = 0; i < size; i++)
	{
		returnedvect.word[i] = this->word[i] ^ vect.word[i];
	}
	return returnedvect;
}

 ByteVector::ByteVector(int vect) :ByteVector() {
	for (size_t i = 0; i < size; i++)
	{
		word[i] = ((1 << i)&vect) != 0;
	}
}

//Конструктор копирования

ByteVector::ByteVector(const ByteVector & vect) :ByteVector() {

	for (size_t i = 0; i < size; i++)
	{
		this->word[i] = vect.word[i];
	}

}

ByteVector::~ByteVector() {
	delete[] word;
}


ostream& operator<<(ostream& a, const ByteVector&vect) {
	for (int i = vect.size - 1; i >= 0; i--)
	{
		a << vect.word[i];
	}
	return a;
}