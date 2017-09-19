#pragma once
#include "vcruntime_exception.h"
#include "ByteVector.h"
#include <string>
namespace exceptions {
	class IllegalVectorSizeException :
		public std::exception
	{
	private:
		IllegalVectorSizeException();
		int vect1, vect2;
	public:
		const char* what() const {
			return (string("One vector has length ") + std::to_string(vect1) + string(" but other length is ") + std::to_string(vect2)).c_str();
		}
		
		IllegalVectorSizeException(int vect1,int vect2);
		~IllegalVectorSizeException();
	};

}