/*
* 암시적링크(프로세스가 시작할 때 dll 가져옴)
* 암시적링크에는 dll파일과 lib파일이 모두 필요하다
* dll파일 쪽에서는 dll에 있는 어떤함수를 사용한다고 호출을 구현해주는 부분이 있어야한다.
* (헤더 파일 .h 파일로 던져주기 가능)
* 프로그램 실행시 dll 파일 불러온 후 호출한 함수가 있는지 검사한다. 없으면 kill
* 
* 명시적링크(프로세스 실행 중일때 dll 가져옴)
* 실행지점까지 무슨 dll을 불러올지 모르는 경우 사용, 설정파일에 따라 dll파일이 바뀌는 경우
* 세가지 함수가 필요하다 (LoadLibrary, GetProcAddress, FreeLibrary)
* 
*/
#include <iostream>
#include <stdio.h>
#include "windows.h"

// -----------------------------------------------------------------------------------------
////암시적링크 - 1.헤더파일 등록하기(헤더 파일을 모를때 사용가능한지?)
//#include "../Dll1_ExprotTest/imageDll.h"
//#pragma comment(lib, "../Debug/Dll1_ExprotTest.lib")
//
////암시적링크 - 2.함수 등록해주기(하나씩 다 등록해야함)
////extern "C" __declspec(dllimport) double Sum(double a, double b);
////extern __declspec(dllimport) int x;
////extern __declspec(dllimport) int fnExample(void);
//
//
//int main() {
//	//첫번째 예제
//	std::cout << "x: " << x << std::endl;
//	std::cout << "fnExample: " << fnExample() << std::endl;
//
//	//두번째 예제
//	std::cout << "Sum: " << Sum(5.0, 1.0) << std::endl;
//}

// -----------------------------------------------------------------------------------------
//명시적링크 - 함수포인터
//포인터 (*)는 아시다시피 NULL을 허용하지만 레퍼런스 (&)는 NULL이 허용되지 않습니다.

typedef double(*pFunctionDLL)(double, double);
pFunctionDLL pFunction = NULL;

int main(int argc, char* argv[]) {
	HMODULE hMod = NULL;
	hMod = LoadLibraryA("Dll1_ExprotTest.dll");

	if (hMod == NULL) {
		printf("DLL Load Fail! \n");
		return 0;
	}
	else {
		printf("DLL Find OK! \n");
	}

	pFunction = (pFunctionDLL)GetProcAddress(hMod, "Sum");
	std::cout << "Sum: " << pFunction(5.0, 1.0) << std::endl;
}