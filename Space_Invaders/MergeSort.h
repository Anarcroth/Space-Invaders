#include <vector>
#include "PlayerInfo.h"
#ifndef __MERGESORT_H_INCLUDED__
#define __MERGESORT_H_INCLUDED__
#pragma once

void merge(std::vector<std::pair<int, PlayerInfo*>> &a, std::vector<std::pair<int, PlayerInfo*>> &tmpArray, int leftPos, int rightPos, int rightEnd)
{
	int leftEnd = rightPos - 1;
	int tmpPos = leftPos;
	int numElements = rightEnd - leftPos + 1;
	while (leftPos <= leftEnd && rightPos <= rightEnd)
	{
		if (a[leftPos] <= a[rightPos])
		{
			tmpArray[tmpPos++] = a[leftPos++];
		}
		else
		{
			tmpArray[tmpPos++] = a[rightPos++];
		}
	}
	while (leftPos <= leftEnd)
	{
		tmpArray[tmpPos++] = a[leftPos++];
	}
	while (rightPos <= rightEnd)
	{
		tmpArray[tmpPos++] = a[rightPos++];
	}
	for (int i = 0; i < numElements; i++, rightEnd--)
	{
		a[rightEnd] = tmpArray[rightEnd];
	}
}

void mergeSort2(std::vector<std::pair<int, PlayerInfo*>> &a, std::vector<std::pair<int, PlayerInfo*>> &tmpArray, int left, int right)
{
	if (left < right)
	{
		int center = (left + right) / 2;
		mergeSort2(a, tmpArray, left, center);
		mergeSort2(a, tmpArray, center + 1, right);
		merge(a, tmpArray, left, center + 1, right);
	}
}

void mrgsrt(std::vector<std::pair<int, PlayerInfo*>> &a)
{
	std::vector<std::pair<int, PlayerInfo*>> TmpArr(a.size());
	mergeSort2(a, TmpArr, 0, a.size() - 1);
}

#endif __MERGESORT_H_INCLUDED__