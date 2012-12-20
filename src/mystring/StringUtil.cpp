/*
 * StringUtil.cpp
 *
 *  Created on: Nov 19, 2012
 */

#include "StringUtil.h"
#include <stdio.h>
#include <string.h>

using namespace mystring;

StringUtil::StringUtil()
{
}

StringUtil::~StringUtil()
{
}

bool StringUtil::contains(const char* dest, const char* targetCharacters)
{
	const char* findPoint = strstr(dest, targetCharacters);

	if(findPoint == NULL)
		return false;
	else
		return true;
}

void StringUtil::trimSpace(char *src, char *dest, int len)
{
	int startIndex = 0;
	int endIndex = len;
	int pureValueLen = 0;

	for(int i=0; i<len; i++)
	{
		if(src[i] != 32) //32 is space
		{
			startIndex = i;
			break;
		}
	}

	for(int i=len-1; i>=0; i--)
	{
		if(src[i] != 32)
		{
			endIndex = i;
			break;
		}
	}

	pureValueLen = (endIndex - startIndex) + 1;
	strncpy(dest, src+startIndex, pureValueLen);
}

