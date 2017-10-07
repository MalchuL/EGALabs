#pragma once
#include <iostream>
using namespace std;
typedef bool byte;

class ByteVector
{
private:
	//��� �������� ��������
	byte* word;
	const int size;
	ByteVector(int size);
public:

	int getLen() const { return size; }
	byte getByte(int id)  const;
	void setByte(int id, byte value);
	ByteVector offestRight(int offsetsize) const;
	ByteVector offestLeft(int offsetsize) const;
	ByteVector SymmetrycSumm(const ByteVector&vect) const;
	//ByteVector() :ByteVector(0, 0) {}

	ByteVector(int vect,int size);
	//����������� �����������
	ByteVector(const ByteVector& vect);
	ByteVector operator=(const ByteVector& vect);
	bool operator<(const ByteVector& other)const {
		if (getLen() != other.getLen())throw 1;
		for (int i = 0; i < getLen(); i++)
		{	
			//������� ���� ������� ������
			int index = getLen() - i - 1;
			//���� ���� �� ���� ������ �� ����� �� ���� � ����� ������� 0, �� �� ������
			if (getByte(index) != other.getByte(index))return !getByte(index);
		}
		return false;
	}
	bool operator==(const ByteVector& other)const {
		if (getLen() != other.getLen())throw 1;
		for (int i = 0; i < getLen(); i++)
		{

			if (getByte(i) != other.getByte(i))return false;
		}
		return true;
	}
	~ByteVector();
	friend ostream& operator<<(ostream& a, const ByteVector&vect);
};

