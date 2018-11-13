// 40. Number of days between two dates
// Write a function that, given two dates, returns the number of days between the two dates.
// The function should work regardless of the order of the input dates
// 두 날짜가 주어지면 그 날짜의 사이의 일수를 리턴하는 함수를 작성하세요.
// 날짜의 입력형태는 입력의 순서 관계없이 작동해야합니다

#include "gsl/gsl"
// create `main` function for catch
#define CATCH_CONFIG_MAIN   
#include "catch2/catch.hpp"

// Redirect CMake's #define to C++ constexpr string
constexpr auto TestName = PROJECT_NAME_STRING;

TEST_CASE("Number of days between two dates") {
	//REQUIRE(checkLicensePlate("LLL-LL 555") == true);
	//REQUIRE(checkLicensePlate("LLL-LL 5555") == true);
	//REQUIRE_FALSE(checkLicensePlate("LLL-LLL 555") == true);
	//REQUIRE_FALSE(checkLicensePlate("LL-LLLL 555") == true);

}