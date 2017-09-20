#pragma once
#include "ByteVector.h"
#include <map>
#include <vector>
#include <algorithm>
typedef float funcvalue;
typedef vector<ByteVector*> set;
using namespace std;
namespace MethodSearching {
	class AbstractMethodSearching
	{
	protected:
		map<ByteVector*, funcvalue>* elements;
		vector<ByteVector*>* reorderednums;


		void addReorderedNums() {
			reorderednums = new vector<ByteVector*>();
			for (map<ByteVector*, funcvalue>::iterator it = elements->begin(); it != elements->end(); ++it) {
				reorderednums->push_back(it->first);

			}

			random_shuffle(reorderednums->begin(), reorderednums->end());
		}

		
		void printdata() {
		clog << endl;
		for (auto it = reorderednums->begin(); it != reorderednums->end(); it++)
		{
		clog << **it<<" "<<elements->at(*it)<<endl;
		}
		clog << endl;
		}
		
	public:
		virtual ByteVector find() = 0;
		AbstractMethodSearching(ByteVector vectors[], funcvalue values[],int size) {
			elements = new map<ByteVector*,funcvalue>();
			for (size_t i = 0; i <size; i++)
			{
				elements->insert(pair<ByteVector*, funcvalue>( new ByteVector(vectors[i]), values[i]));
			}
		}
		AbstractMethodSearching( const vector<ByteVector>& vectors,const vector<funcvalue>& values) {
			int size = vectors.size() > values.size() ? values.size() : vectors.size();
			elements = new map<ByteVector*, funcvalue>();
			for (size_t i = 0; i <size; i++)
			{
				elements->insert(pair<ByteVector*, funcvalue>(new ByteVector(vectors[i]), values[i]));
			}
		}
		~AbstractMethodSearching() {
			delete reorderednums;
			for (map<ByteVector*, funcvalue>::iterator it = elements->begin(); it != elements->end(); ++it) {
				delete it->first;

			}
			delete elements;

		}
	};


}