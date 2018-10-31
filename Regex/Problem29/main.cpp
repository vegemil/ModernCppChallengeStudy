// 번호판 유효성 검사
// LLL-LL DDD 또는 LLL-LL DDDD (L은 대문자이고 D는 숫자) 형식의 번호판을 고려하여, 다음
// 을 작성하라:
// • 번호판 숫자가 정확한 형식인지 유효성을 검사하는 함수
// • 텍스트를 입력 받아서, 모든 번호판 숫자들을 찾고 추출하여 반환하는 함수

#include "gsl/gsl"
// create `main` function for catch
#define CATCH_CONFIG_MAIN   
#include "catch2/catch.hpp"

#include <string>
#include <locale>
#include <sstream>

// Redirect CMake's #define to C++ constexpr string
constexpr auto TestName = PROJECT_NAME_STRING;

bool checkAlphabet(std::string str)
{	if(str.length() != 6)
		return false;

	if (str.at(3) == '-')
	{
		str.replace(3, 1, "");
	}
	else
	{
		return false;
	}

	for (auto iter : str)
	{
		if (false == isalpha(iter))
		{
			return false;
		}		
	}

	return true;
}

bool checkNumber(int num)
{
	int ret = (num / 100);
	if (ret > 0 && ret < 100)
		return true;

	return false;
}

bool checkLicensePlate(std::string str)
{
	std::string alphabet;
	int number;

	std::stringstream(str) >> alphabet;

	str.replace(0, 7, "");
	number = std::atoi(str.c_str());

	if (checkAlphabet(alphabet) && checkNumber(number))
	{
		return true;
	}
	
	return false;
}

TEST_CASE("tokenize", "[Joining strings]") {
	REQUIRE(checkLicensePlate("LLL-LL 555") == true);
	REQUIRE(checkLicensePlate("LLL-LL 5555") == true);
	REQUIRE_FALSE(checkLicensePlate("LLL-LLL 555") == true);
	REQUIRE_FALSE(checkLicensePlate("LL-LLLL 555") == true);
}