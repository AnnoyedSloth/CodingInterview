// CodingInterview.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include "pch.h"
#include <iostream>
#include <string>

using namespace std;

// Replace specific character to other character
void Q4(string& str)
{
	char* charStr = const_cast<char*>(str.c_str());
	
	int spaces = 0;
	int len = 0;

	while (*charStr)
	{
		if (*charStr == ' ') ++spaces;
		++len;
		++charStr;
	}
	--charStr;

	int size = len + (spaces * 2);

	char* newStr = (char*)malloc(size);
	newStr[size] = '\0';
	
	for (int a = 0; a < size; ++a)
	{
		++newStr;
	}
	--newStr;
 
	for(int a=size; a>=0; --a)
	{
		if (*charStr == ' ')
		{
			newStr[size-3] = '%';
			newStr[size-2] = '2';
			newStr[size-1] = '3';

			size -= 3;
			--charStr;
		}
		else
		{
			newStr[size-1] = *charStr;
			--size;
			--charStr;
		}
	}
	
	cout << newStr << endl;
}

// Compress the continuously repeated characters
string Q5(string str)
{
	string newStr;

	char* charStr = const_cast<char*>(str.c_str());

	int count = 1;
	char curChar = charStr[0];

	while (*charStr)
	{
		++charStr;

		if (curChar == *charStr) ++count;
		else
		{
			newStr.push_back(curChar);
			newStr.push_back(count+48);
			count = 1;
			curChar = *charStr;
		}

	}
	
	cout << newStr << endl;

	return newStr;
}



int main()
{
	//string str = "Tell me what you need";
	//Q4(str);

	//string str2("aabcccccccccaa");
	//Q5(str2);
}

// 프로그램 실행: <Ctrl+F5> 또는 [디버그] > [디버깅하지 않고 시작] 메뉴
// 프로그램 디버그: <F5> 키 또는 [디버그] > [디버깅 시작] 메뉴

// 시작을 위한 팁: 
//   1. [솔루션 탐색기] 창을 사용하여 파일을 추가/관리합니다.
//   2. [팀 탐색기] 창을 사용하여 소스 제어에 연결합니다.
//   3. [출력] 창을 사용하여 빌드 출력 및 기타 메시지를 확인합니다.
//   4. [오류 목록] 창을 사용하여 오류를 봅니다.
//   5. [프로젝트] > [새 항목 추가]로 이동하여 새 코드 파일을 만들거나, [프로젝트] > [기존 항목 추가]로 이동하여 기존 코드 파일을 프로젝트에 추가합니다.
//   6. 나중에 이 프로젝트를 다시 열려면 [파일] > [열기] > [프로젝트]로 이동하고 .sln 파일을 선택합니다.
