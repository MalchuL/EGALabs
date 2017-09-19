#include "stdafx.h"
#include "IllegalVectorSizeException.h"


exceptions::IllegalVectorSizeException::IllegalVectorSizeException()
{

}

exceptions::IllegalVectorSizeException::IllegalVectorSizeException(int vect1, int vect2):vect1(vect1),vect2(vect2)
{

}


exceptions::IllegalVectorSizeException::~IllegalVectorSizeException()
{
}
