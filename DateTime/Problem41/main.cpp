// 41. Day of the week
// Write a function that, given a date, determines the day of the week. This function should
// return a value between 1 (for Monday) and 7 (for Sunday).
// 날짜가 주어지면 해당 날짜의 요일을 출력하는 함수를 출력하는 함수를 작성하세요.
// 반환 형태는 1(월요일) 과 7(일요일)입니다

#include "gsl/gsl"
// create `main` function for catch
#define CATCH_CONFIG_MAIN   
#include "catch2/catch.hpp"

// Redirect CMake's #define to C++ constexpr string
constexpr auto TestName = PROJECT_NAME_STRING;

TEST_CASE("tokenize", "[Joining strings]") {
	//REQUIRE(checkLicensePlate("LLL-LL 555") == true);
	//REQUIRE(checkLicensePlate("LLL-LL 5555") == true);
	//REQUIRE_FALSE(checkLicensePlate("LLL-LLL 555") == true);
	//REQUIRE_FALSE(checkLicensePlate("LL-LLLL 555") == true);

}