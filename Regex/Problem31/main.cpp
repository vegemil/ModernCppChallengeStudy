// 문자열에서 날짜를 변환
// dd.mm.yyyy 또는 dd-mm-yyyy 형식의 날짜들을 포함한 텍스트를 입력받아서, yyyy-mmdd
// 형식의 날짜들을 갖도록 텍스트를 변환하는 함수를 작성하라.

#include "gsl/gsl"
// create `main` function for catch
#define CATCH_CONFIG_MAIN   
#include "catch2/catch.hpp"

#include <iostream>
#include <sstream>
#include <locale>
#include <iomanip>
#include <regex>
#include <string>

// Redirect CMake's #define to C++ constexpr string
constexpr auto TestName = PROJECT_NAME_STRING;

std::string parseDate(const std::string& input) {
	std::string resultStr;

	std::regex word_date("\\b\\d{2}[.-]\\d{2}[.-]\\d{4}\\b");

	std::cmatch m;
	if (false == std::regex_search(input.c_str(), m, word_date))
	{
		return "날짜 아님";
	}

	std::regex word_regex("[^-.]+");

	std::vector<std::string> dateVec;

	auto words_begin =
		std::sregex_iterator(input.begin(), input.end(), word_regex);
	auto words_end = std::sregex_iterator();

	for (std::sregex_iterator i = words_begin; i != words_end; ++i)
	{
		if (i != words_begin)
			resultStr.insert(0, "-");

		std::smatch match = *i;
		std::string match_str = match.str();

		resultStr.insert(0, match_str);
	}

	std::istringstream s(resultStr);

	std::tm x = {0, };
	s >> std::get_time(&x, "%Y-%m-%d");

	std::stringstream ss;
	ss << std::put_time(&x, "%Y-%m%d");
	resultStr = ss.str();

	return resultStr;
}


TEST_CASE("Date Parsing") {
	REQUIRE(parseDate("02-11-2018") == "2018-1102");
	REQUIRE(parseDate("02.11.2018") == "2018-1102");

	REQUIRE(parseDate("02.11.20185") == "날짜 아님");
	REQUIRE(parseDate("02/11/20185") == "날짜 아님");
}