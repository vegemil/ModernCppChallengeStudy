// 가능한 구분자 목록을 받아 문자열을 토큰으로 분리
// 문자열과 가능한 구분자 목록 문자들을 받아서, 전달받은 어떤 구분자라도 있으면 그 문자열을 토
// 큰으로 분리하여 std:vector로 반환하는 함수를 작성하라.
// 예: 입력: "this,is.a sample!!" 그리고 구분자 ",.! ", 출력: {"this", "is", "a", "sample"}.

#include "gsl/gsl"
// create `main` function for catch
#define CATCH_CONFIG_MAIN   
#include "catch2/catch.hpp"
#include <string>
#include <regex>

// Redirect CMake's #define to C++ constexpr string
constexpr auto TestName = PROJECT_NAME_STRING;

static std::string trimString = ",.! ";

std::vector<std::string> split(const std::string& input, const std::string& regex) {
	// passing -1 as the submatch index parameter performs splitting
	std::vector<std::string> resultStr;

	std::regex word_regex(regex);

	auto words_begin =
		std::sregex_iterator(input.begin(), input.end(), word_regex);
	auto words_end = std::sregex_iterator();

	for (std::sregex_iterator i = words_begin; i != words_end; ++i) 
	{
		std::smatch match = *i;
		std::string match_str = match.str();
		
		resultStr.push_back(match_str);
	}

	return resultStr;
}
TEST_CASE("tokenize", "[Joining strings]") {

	/*for (auto iter : trimString)
	{
		std::vector<std::string> vec;
		vec.push_back("this,is.a sample!!");

		for (auto str : vec)
		{
			vec = split(str, &(iter));
		}
	}*/


	std::vector<std::string> vec;
	vec.push_back("this,is.a sample!!");

	vec = split("this,is.a sample!!", "[,.! ]+");

	/*REQUIRE(split("this,is.a sample!!") == "{\"this\", \"is\", \"a\", \"sample\"}");*/
}