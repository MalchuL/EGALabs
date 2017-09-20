#pragma once
#include "AbstractMethodSearching.h"
using namespace std;
namespace MethodSearching {
	class SearchInWidthMethod :public AbstractMethodSearching
	{
	public:
		SearchInWidthMethod(ByteVector vectors[], funcvalue values[], int size, int NSteps, int randomseed) :AbstractMethodSearching(vectors, values, size), NSteps(NSteps)
		{
			this->randomseed = randomseed;
			srand(randomseed);
			//Добавить ключи в переупорядоченный лист
			addReorderedNums();

			//

		}

		SearchInWidthMethod(const vector<ByteVector>& vectors, const vector<funcvalue>& values, int NSteps, int randomseed) :AbstractMethodSearching(vectors, values), NSteps(NSteps)
		{
			this->randomseed = randomseed;
			srand(randomseed);

			//Добавить ключи в переупорядоченный лист
			addReorderedNums();
			//

		}
		SearchInWidthMethod();
		~SearchInWidthMethod();
	};

}