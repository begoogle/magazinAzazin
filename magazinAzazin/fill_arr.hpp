#pragma once

#ifndef _FILL_ALL_HPP_
#define _FILL_ALL_HPP_

#include "include.hpp"

template<typename ArrType>
void FillArr(ArrType* dynamicArr, ArrType* staticArr, size_t arraySize) {
	for (size_t i = 0; i < arraySize; i++)
	{
		dynamicArr[i] = staticArr[i];
	}
}
#endif // !_FILL_ALL_HPP_


