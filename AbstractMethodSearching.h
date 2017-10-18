#pragma once
#include "ByteVector.h"
#include <map>
#include <vector>
#include <algorithm>

using namespace std;
namespace MethodSearching {
	typedef float funcvalue;
	typedef vector<ByteVector> set;
	typedef map<ByteVector, funcvalue> func;
	class AbstractMethodSearching
	{
	private:
		vector<ByteVector>* reorderednums;
	protected:
		func* elements;
		
		vector<ByteVector>* getReorderedNums();

		void printReorderedNums();

		static void printSet(set* const printedset);
		static void printSet(set* const printedset, func* const function);
	public:
		void addReorderedNums();

		virtual ByteVector find() = 0;
		AbstractMethodSearching(ByteVector vectors[], funcvalue values[], int size);
		AbstractMethodSearching(const vector<ByteVector>& vectors, const vector<funcvalue>& values);
		~AbstractMethodSearching();
	};


}