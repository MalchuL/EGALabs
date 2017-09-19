#pragma once
#include <iostream>
using namespace std;
typedef bool byte;

class ByteVector
{
private:
	//Все хранится наоборот
	byte* word;
	const int size = 5;
	ByteVector() {
		this->word = new byte[size];
		for (size_t i = 0; i < size; i++)
		{
			this->word[i] = false;
		}
	}
public:
	int getLen() { return size; }
	byte getChar(int id);
	ByteVector offestRight(int offsetsize) const;
	ByteVector offestLeft(int offsetsize) const;
	ByteVector SymmetrycSumm(const ByteVector&vect);


	ByteVector(int vect);
	//Конструктор копирования
	ByteVector(const ByteVector& vect);

	

	~ByteVector();
	friend ostream& operator<<(ostream& a, const ByteVector&vect);
};

