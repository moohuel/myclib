/*
 * MyExample.cpp
 *
 *  Created on: Dec 28, 2012
 */

#include <string>
#include <stdio.h>
#include <string.h>

using namespace std;

void split()
{
	//char *src = "ab|cd|ed"; //Error
	//char src[20] = "ab|cd|ed"; //OK
	string raw = "ab|cd|ef";
	char* src = const_cast<char*>(raw.c_str());
	char *ptr = src;
	char *rest;
	char *result;

	while(result = strtok_r(ptr, "|", &rest))
	{
		printf("strtok_r result=%s\n", result);
		ptr = rest;
	}
}

//int main()
//{
//	split();
//
//	return 0;
//}


