#pragma once
#include "ByteVector.h"
#include <map>
#include <vector>
typedef float funcvalue;
using namespace std;
namespace MethodSearching {
	class AbstractMethodSearching
	{
	protected:
		map<ByteVector&, funcvalue>* elements;
	public:
		virtual ByteVector find() = 0;
		AbstractMethodSearching(ByteVector vectors[], funcvalue values[],int size) {
			elements = new map<ByteVector&,funcvalue>();
			for (size_t i = 0; i <size; i++)
			{
				elements->insert(pair<ByteVector&, funcvalue>( vectors[i], values[i]));
			}
		}
	};

}