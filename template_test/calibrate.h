#pragma once
#include <stdint.h>

void CalibratieLine(const uint8_t* pIn, uint8_t* pOut)
{
	const int lineSize = 31104;

	uint8_t* pW = new uint8_t[lineSize];
	memset(pW, 255, lineSize);
	uint8_t* pB = new uint8_t[lineSize];
	memset(pB, 0, lineSize);

	float* pTemp = new float[lineSize];

	for (int i = 0; i < lineSize; i++)
	{
		pTemp[i] = 255.f / ((pW[i] << 8) - (pB[i] << 8));
	}

	for (int i = 0; i < lineSize; i++)
	{
		if (pIn[i] < pB[i])
			pOut[i] = 0;
		else if (pIn[i] > pW[i])
			pOut[i] = 255;
		else
			pOut[i] = ((uint16_t)(((pIn[i] - pB[i]) << 8) * pTemp[i])) >> 8;
	}

	delete[] pW;
	delete[] pB;
	delete[] pTemp;
}