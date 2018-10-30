// 구분자로 분리된 문자열들을 결합
// 받은 문자열 목록과 구분자로 모든 입력 문자열들을 합쳐서 구분자로 분리된 새로운 문자열을 만
// 드는 함수를 작성하라. 구분자는 마지막 문자열엔 나타나지 않으며, 입력 문자열이 없을때, 함수
// 는 비어있는 문자열을 반환한다.
// 예: 입력 { "this","is","an","example" } 그리고 구분자 ' ' (공백), 출력: "this is an
// example".


#include "gsl/gsl"
// create `main` function for catch
#define CATCH_CONFIG_MAIN   
#include "catch2/catch.hpp"

// Redirect CMake's #define to C++ constexpr string
constexpr auto TestName = PROJECT_NAME_STRING;

std::string joiningString(std::vector<std::string> vec)
{
	std::string resultStr;

	for (auto iter : vec)
	{
		if (iter != vec.at(0))
		{
			resultStr.append(" ");
		}

		resultStr.append(iter);
	}

	return resultStr;
}

TEST_CASE("Joining strings together separated by a delimiter", "[Joining strings]") {
	std::vector<std::string> vec;
	vec.push_back("this");
	vec.push_back("is");
	vec.push_back("an");
	vec.push_back("example");

	REQUIRE(joiningString(vec) == "this is an example");
}