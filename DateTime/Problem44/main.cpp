// 44. Monthly calendar
// Write a function that, given a year and month, prints to the console the month calendar.
// The expected output format is as follows (the example is for December 2017):

// 년과 달이 주어지면 콘솔로 해당 달의 달력을 출력하세요.
// 출력의 형태는 다음과 같습니다.

#include "gsl/gsl"
// create `main` function for catch
#define CATCH_CONFIG_MAIN   
#include "catch2/catch.hpp"

// Redirect CMake's #define to C++ constexpr string
constexpr auto TestName = PROJECT_NAME_STRING;

TEST_CASE("Monthly calendar") {
	//REQUIRE(checkLicensePlate("LLL-LL 555") == true);
	//REQUIRE(checkLicensePlate("LLL-LL 5555") == true);
	//REQUIRE_FALSE(checkLicensePlate("LLL-LLL 555") == true);
	//REQUIRE_FALSE(checkLicensePlate("LL-LLLL 555") == true);

}