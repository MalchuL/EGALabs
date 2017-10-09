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
#include "AnsambleSearchMethod.h"
#include <vector>
#include "DispacementVector.h"
using namespace exceptions;
using namespace std;
using namespace MethodSearching;
void testMonte();
void testInDepth();
void testInWidth();
void testvalue();
void testmera();
void testfuncs();
void testGrayCode();
void testEnsemble();
void testDisplacementVector();
constexpr int size = 5;
int main()
{
	//throw IllegalVectorSizeException(1,2);
	//testMonte();
//	testInDepth();
	//testInWidth();
//	testEnsemble();
	testDisplacementVector();
//	testvalue();
//	testmera();
//	testGrayCode();
	//testfuncs();
	getchar();
    return 0;

}
void testfuncs() {
	int vect1 = 0b00101;
	cout << ByteVectorMath::GrayCodeEncoder(ByteVector(0b000, 3))<<endl;
	cout << ByteVectorMath::GrayCodeEncoder(ByteVector(0b010, 3))<<endl;
	cout << ByteVectorMath::GrayCodeEncoder(ByteVector(0b110, 3))<<endl;
	cout << ByteVector(0b110100,6)<<" "  <<ByteVectorMath::GrayCodeDecoder( ByteVectorMath::GrayCodeEncoder(ByteVector(0b110100, 6)))<<endl;
	
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
void testMonte() {
	srand(0);
	//ByteVector* bytes = new ByteVector[32];
	vector<ByteVector> vectors = vector<ByteVector>();
	vector<funcvalue> values = vector<funcvalue>();
	
	for (size_t i = 0; i < 1<<5; i++)
	{
		vectors.push_back(ByteVector(i, 5));
		int t = abs(rand() % 60);
		values.push_back(t);
		clog << ByteVector(i, 5) << " " << t << endl;;
	}

	cout << "Monte Carlo"<<endl;
	cout << MonteCarlosMethodSearching(vectors, values, 8, 39).find()<<endl << endl<<endl;

}
void testInDepth() {
	srand(0);
	//ByteVector* bytes = new ByteVector[32];
	vector<ByteVector> vectors = vector<ByteVector>();
	vector<funcvalue> values = vector<funcvalue>();

	for (size_t i = 0; i < 1 << 5; i++)
	{
		vectors.push_back(ByteVector(i, 5));
		int t = i;
		values.push_back(t);
		clog << ByteVector(i, 5) << " " << t << endl;;
	}

	cout << "In Depth" << endl;
	cout << DepthSearchMethod(vectors, values, 10, 66).find() << endl << endl << endl;

}
void testGrayCode() {
	srand(0);
	//ByteVector* bytes = new ByteVector[32];
	vector<ByteVector> vectors = vector<ByteVector>();
	vector<funcvalue> values = vector<funcvalue>();
	cout << "True values" << endl;
	for (size_t i = 0; i < 1 << 5; i++)
	{

		int t = i - (2 << 4);
		t *= t;
		clog << ByteVector(i, 5) << " " << t << endl;
	}
	cout << "Gray code values" << endl;
	for (size_t i = 0; i < 1 << 5; i++)
	{
		vectors.push_back(ByteVectorMath::GrayCodeEncoder(ByteVector(i, 5)));
		int t = i - (2 << 4);
		t *= t;
		values.push_back(t);
		clog << ByteVectorMath::GrayCodeEncoder( ByteVector(i, 5)) << " " << t << endl;
	}

	cout << "In Width with Gray code" << endl;
	cout <<"Decoded value:"<<ByteVectorMath::GrayCodeDecoder( SearchInWidthMethod(vectors, values, 8, 26).find()) << endl << endl;
}
void testEnsemble() {
	srand(0);
	//ByteVector* bytes = new ByteVector[32];
	vector<ByteVector> vectors = vector<ByteVector>();
	vector<funcvalue> values = vector<funcvalue>();

	for (int i = 1; i < 1 << 7; i++)
	{
		vectors.push_back(ByteVector(i, 7));
		funcvalue t = 5 * sin(i) + log(i);
		values.push_back(t);
		clog << ByteVector(i, 7) << " " << t << endl;;
	}

	cout << "Ensemble" << endl;
	cout << AnsambleSearchMethod(vectors, values, 8, 8,22).find() << endl << endl;
}
void testDisplacementVector()
{
	DispacementVector test(5);

	cout << test <<endl;
	cout << test.CheckValue()<<endl;
	test.setNum(1, 5);
	cout << test.CheckValue() << endl;

}
void testInWidth() {
	srand(0);
	//ByteVector* bytes = new ByteVector[32];
	vector<ByteVector> vectors = vector<ByteVector>();
	vector<funcvalue> values = vector<funcvalue>();

	for (size_t i = 0; i < 1 << 5; i++)
	{
		vectors.push_back(ByteVector(i, 5));
		int t = i - (2<<4);
		t *= t;
		values.push_back(t);
		clog << ByteVector(i, 5) << " " << t << endl;;
	}

	cout << "In Width" << endl;
	cout << SearchInWidthMethod(vectors, values, 8, 39).find() << endl << endl;

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