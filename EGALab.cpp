// EGALab.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"
#include "ByteVector.h"
#include "ByteVectorMath.h"
#include <iostream>
#include <exception>
#include "vcruntime_exception.h"
#include "IllegalVectorSizeException.h"
#include "MonteCarlosMethodSearching.h"
#include "DepthSearchMethod.h"
#include "SearchInWidthMethod.h"
#include <vector>
using namespace exceptions;
using namespace std;
using namespace MethodSearching;
void testmethod();
void testvalue();
void testmera();
constexpr int size = 5;
int main()
{
	//throw IllegalVectorSizeException(1,2);
	testmethod();
//	testvalue();
//	testmera();
	getchar();
    return 0;

}

void testmera() {
	int vect1 = 0b00101;
	int vect2 = 0b00110;
	try
	{
		cout << ByteVectorMath::HemmingLength(ByteVector(vect1, 5), ByteVector(vect2, 6));

	}
	catch (const std::exception& expr)
	{
		cout << expr.what();
	}
	

}
void testmethod() {
	srand(0);
	//ByteVector* bytes = new ByteVector[32];
	vector<ByteVector> vectors = vector<ByteVector>();
	vector<funcvalue> values = vector<funcvalue>();
	
	for (size_t i = 0; i < 32; i++)
	{
		vectors.push_back(ByteVector(i, 5));
		int t = abs(rand() % 60);
		values.push_back(t);
		clog << ByteVector(i, 5) << " " << t << endl;;
	}
	cout << MonteCarlosMethodSearching(vectors, values, 32, 6).find();
	cout << DepthSearchMethod(vectors, values, 6, 64).find();
	cout << SearchInWidthMethod(vectors, values, 4, 22).find();
}
void testvalue() {
	int testval = 0b01001;
	//cout << testval << endl;
	ByteVector& byte = ByteVector(testval,5);
	cout <<byte.offestRight(2);
	cout << endl<<endl;

	ByteVector vect1 = ByteVector(7,5);
	ByteVector vect2 = ByteVector(6,5);
	cout << vect1 << endl << vect2 << endl;
	cout << vect1.SymmetrycSumm(vect2);
}