// EGALab.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"
#include "ByteVector.h"
#include "ByteVectorMath.h"
#include <iostream>
using namespace std;

void testvalue();
void testmera();
int main()
{
	//testvalue();
	testmera();
	getchar();
    return 0;

}

void testmera() {
	int vect1 = 0b00101;
	int vect2 = 0b00110;

	cout<<ByteVectorMath::HemmingLength(ByteVector(vect1),ByteVector(vect2));

}

void testvalue() {
	int testval = 0b01001;
	//cout << testval << endl;
	ByteVector& byte = ByteVector(testval);
	cout <<byte.offestRight(2);
	cout << endl<<endl;

	ByteVector vect1 = ByteVector(7);
	ByteVector vect2 = ByteVector(6);
	cout << vect1 << endl << vect2 << endl;
	cout << vect1.SymmetrycSumm(vect2);
}