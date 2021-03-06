#pragma once //소스 코드 파일을 컴파일할 때 컴파일러에 헤더 파일이 한 번만 포함되도록 지정합니다.
/*
* 다음 ifdef 블록은 DLL에서 내보내는 작업을 더 간소화하는 매크로를 만드는표준 방법입니다.
* 이 DLL에 들어 있는 파일은 모두 명령줄에 정의된 *수정됨(IMAGEDLL_EXPORTS -> DLL1EXPROTTEST_EXPORTS)기호로 컴파일됩니다.
* 이 DLL을 사용하는 프로젝트에서는 이 기호를 정의할 수 없습니다.
* 이렇게 하면 소스 파일에 이 파일이 포함된 다른 모든 프로젝트에서는 *수정됨(IMAGEDLL_API -> DLLTEST_API) 함수를 DLL에서 가져오는 것으로 표시되는 반면,
* 이 DLL에서는 이 매크로로 정의된 기호가 내보내지는 것으로 표시됩니다.
* [프로젝트]-[속성]-[C/C++]-[전처리기] 에서 DLL1EXPROTTEST_EXPORTS 확인
*/
#ifdef DLL1EXPROTTEST_EXPORTS
#define DLLTEST_API __declspec(dllexport)
#else
#define DLLTEST_API __declspec(dllimport)
#endif

#include <Windows.h>

//첫번째 예제
class DLLTEST_API CExampleA {
public:
	CExampleA(void);
	// TODO: 여기에 메서드를 추가합니다.
};
extern DLLTEST_API int x;
DLLTEST_API int fnExample(void);

/*
* extern "C" : C++ 소스에서 선언한 전역 변수나 함수를 C에서 사용해야 할 경우
*/
//두번째 예제
extern "C" DLLTEST_API double Sum(double a, double b);
extern "C" DLLTEST_API double Sub(double a, double b);
extern "C" DLLTEST_API double Mul(double a, double b);
extern "C" DLLTEST_API double Div(double a, double b);
