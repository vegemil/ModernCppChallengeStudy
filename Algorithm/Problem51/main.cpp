//51. Transforming a list of phone numbers
//Write a function that, given a list of phone numbers, transforms them so they all start with a specified phone country code, preceded by the + sign.
//Any whitespaces from a phone number should also be removed.The following is a list of input and output examples :
//			07555 123456 = > +447555123456
//			07555123456 = > +447555123456
//			+ 44 7555 123456 = > +447555123456
//			44 7555 123456 = > +447555123456
//			7555 123456 = > +447555123456

#include "gsl/gsl"
// create `main` function for catch
#define CATCH_CONFIG_MAIN
#include "catch2/catch.hpp"

// Redirect CMake's #define to C++ constexpr string
constexpr auto TestName = PROJECT_NAME_STRING;

#include <cctype>

std::string removeSpace(const std::string str)
{
	std::string removeSpaceStr;

	for (const char& c : str)
	{
		if (isdigit(c))
		{
			removeSpaceStr.push_back(c);
		}
	}

	return removeSpaceStr;
}

std::string transformingPhoneNumber(const std::string str)
{
	std::string resultStr;

	// 숫자 외에 제거
	resultStr = removeSpace(str);

	// 시작이 0인애들 제거
	if (*resultStr.begin() == '0')
	{
		resultStr.erase(resultStr.begin());
	}

	// 지역번호가 없는 애들
	if (resultStr.size() < 12)
	{	
		resultStr.insert(0, "44");
	}

	resultStr.insert(resultStr.begin(), '+');

	return resultStr;
}

TEST_CASE("Transforming a list of phone numbers") {
	REQUIRE(transformingPhoneNumber("07555 123456") == "+447555123456");
	REQUIRE(transformingPhoneNumber("07555123456") == "+447555123456");
	REQUIRE(transformingPhoneNumber("+ 44 7555 123456") == "+447555123456");
	REQUIRE(transformingPhoneNumber("44 7555 123456") == "+447555123456");
	REQUIRE(transformingPhoneNumber("7555 123456") == "+447555123456");
}