//#ifdef 전처리기 특성을 이용. 실제 컴파일이 수행되기전에 실행
//#endif

#include "pch.h"
#include "framework.h"
#include "ImageDLL.h"

#include <iostream>
#include <chrono> //시간관련 라이브러리


//첫번째 예제
// 내보낸 변수의 예제입니다.
DLLTEST_API int x = 0;

// 내보낸 함수의 예제입니다.
DLLTEST_API int fnExample(void)
{
    return 1;
}
// 내보낸 클래스의 생성자입니다.
CExampleA::CExampleA()
{
    return;
}

//두번째 예제
double Sum(double a, double b) {
	return a + b;
}

double Sub(double a, double b) {
	return a - b;
}

double Mul(double a, double b) {
	return a * b;
}

double Div(double a, double b) {
	return a / b;
}
