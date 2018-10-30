// 글 제목을 대문자 표시
// 입력된 텍스트의 모든 단어에서 시작 문자는 대문자로, 나머지 문자는 소문자를 갖는, 대문자 표
// 시 버전으로 변환하는 함수를 작성하시오. 예를 들어, “the c++ challenger” 문자열은 “The
// C++ Challenger”로 변환되어야 한다.

#include <string>
#include <locale>

#include "gsl/gsl"

// create `main` function for catch
#define CATCH_CONFIG_MAIN   
#include "catch2/catch.hpp"

// Redirect CMake's #define to C++ constexpr string
constexpr auto TestName = PROJECT_NAME_STRING;

std::string capitalizing(std::string str)
{
	for (std::string::iterator iter = str.begin(); iter != str.end(); ++iter)
	{
		if (iter == str.begin())
		{
			*iter = std::toupper(*iter, std::locale());
		}

		char ch = *(iter);
		if (true == std::isspace(ch, std::locale()))
		{
			if (++iter != str.end())
			{
				*iter = std::toupper(*iter, std::locale());
			}
		}
	}

	return str;
}


TEST_CASE("Capitalizing an article title", "[Capitalizing]") {
	REQUIRE(capitalizing("the c++ challenger") == "The C++ Challenger");
	REQUIRE_FALSE(capitalizing("Example sentence to test isspace") == "Example sentence to test isspace");
}
