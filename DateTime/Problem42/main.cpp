// 42. Day and week of the year
// Write a function that, given a date, returns the day of the year (from 1 to 365 or 366 for
// leap years) and another function that, for the same input, returns the calendar week of the
// year
// 날짜가 주어지면 해당년수(윤년일시 366 일)의 일수를 출력하는 함수와 해당 연도의 달력의 주의
// 개수 를 반환하는 함수를 작성해주세요

#include "gsl/gsl"
// create `main` function for catch
#define CATCH_CONFIG_MAIN   
#include "catch2/catch.hpp"

// Redirect CMake's #define to C++ constexpr string
constexpr auto TestName = PROJECT_NAME_STRING;

TEST_CASE("Day and week of the year") {
	//REQUIRE(checkLicensePlate("LLL-LL 555") == true);
	//REQUIRE(checkLicensePlate("LLL-LL 5555") == true);
	//REQUIRE_FALSE(checkLicensePlate("LLL-LLL 555") == true);
	//REQUIRE_FALSE(checkLicensePlate("LL-LLLL 555") == true);

}