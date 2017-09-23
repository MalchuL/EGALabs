#pragma once
#include "ByteVector.h"
#include <map>
#include <vector>
#include <algorithm>
#include "Logger.h"
typedef float funcvalue;
typedef vector<ByteVector*> set;
typedef map<ByteVector*, funcvalue> func;
using namespace std;
namespace MethodSearching {
	class AbstractMethodSearching
	{
	protected:
		func* elements;
		vector<ByteVector*>* reorderednums;


		void addReorderedNums() {
			reorderednums = new vector<ByteVector*>();
			for (func::iterator it = elements->begin(); it != elements->end(); ++it) {
				reorderednums->push_back(it->first);

			}

			random_shuffle(reorderednums->begin(), reorderednums->end());
		}

		
		void printreorderednums() {
		clog << endl;
		clog << "Input Data"<<endl;
		for (auto it = reorderednums->begin(); it != reorderednums->end(); it++)
		{
		clog << **it<<" "<<elements->at(*it)<<endl;
		}
		clog << endl;
		}
		static void printset(set* const printedset) {
			clog << "{ ";
			for (auto i = printedset->begin(); i != printedset->end(); i++)
			{
				clog << **i << ", ";
			}
			clog << "}";
		}
		static void printset(set* const printedset, func* const function) {
			clog << "{ ";
			for (auto i = printedset->begin(); i != printedset->end(); i++)
			{
				clog << **i << ":" << function->at(*i) << ", ";
			}
			clog << "}" << endl;
		}
	public:
		virtual ByteVector find() = 0;
		AbstractMethodSearching(ByteVector vectors[], funcvalue values[],int size) {
			elements = new func();
			for (size_t i = 0; i <size; i++)
			{
				elements->insert(pair<ByteVector*, funcvalue>( new ByteVector(vectors[i]), values[i]));
			}
		}
		AbstractMethodSearching( const vector<ByteVector>& vectors,const vector<funcvalue>& values) {
			int size = vectors.size() > values.size() ? values.size() : vectors.size();
			elements = new func();
			for (size_t i = 0; i <size; i++)
			{
				elements->insert(pair<ByteVector*, funcvalue>(new ByteVector(vectors[i]), values[i]));
			}

		
		}
		~AbstractMethodSearching() {
			delete reorderednums;
			for (func::iterator it = elements->begin(); it != elements->end(); ++it) {
				delete it->first;

			}
			delete elements;

		}
	};


}