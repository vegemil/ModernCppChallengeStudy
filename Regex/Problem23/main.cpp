// 바이너리(Binary)를 문자열로 변환
// 8비트 정수들을 받아서 그 정수들에 대한 16진수 문자열을 반환하는 함수를 작성하라. 이 함수는
// 대문자와 소문자 모두 제공할 수 있어야 한다. 여기 입력과 출력에 대한 예를 참고하시오:
// 입력: { 0xBA, 0xAD, 0xF0, 0x0D }, 출력: "BAADF00D" 또는 "baadf00d"
// 입력: { 1,2,3,4,5,6 }, 출력: "010203040506" 

#include<iostream>
#include <string>
#include <ios>
#include <locale>

#include "gsl/gsl"

// create `main` function for catch
#define CATCH_CONFIG_MAIN   
#include "catch2/catch.hpp"

// Redirect CMake's #define to C++ constexpr string
constexpr auto TestName = PROJECT_NAME_STRING;

class ConvertBinaryToString
{
private :
	std::string str;

	void convert(std::vector<int> vec)
	{
		std::string hex;
		for (auto iter : vec)
		{
			std::stringstream stream;
			stream << std::setfill('0') << std::setw(2) << std::hex << iter;

			str.append(stream.str());
		}
	}

public:
	ConvertBinaryToString(std::vector<int> vec) : str("")
	{
		convert(vec);
	}

	std::string to_StringUpper()
	{
		std::string temp; 
		for (auto c : str)
		{
			temp.push_back(std::toupper(c, std::locale()));
		}

		return temp;
	}

	std::string to_Stringlower()
	{
		std::string temp;
		for (auto c : str)
		{
			temp.push_back(std::tolower(c, std::locale()));
		}

		return temp;
	}
};

TEST_CASE("Binary to string conversion", "[Binary2string]") {
	std::vector<int> vec;
	vec.push_back(0xBA);
	vec.push_back(0xAD);
	vec.push_back(0xF0);
	vec.push_back(0x0D);

	REQUIRE(ConvertBinaryToString(vec).to_StringUpper() == "BAADF00D");
	REQUIRE(ConvertBinaryToString(vec).to_Stringlower() == "baadf00d");

	vec.clear();
	for (int i = 1; i <= 6; ++i)
	{
		vec.push_back(i);
	}

	REQUIRE(ConvertBinaryToString(vec).to_StringUpper() == "010203040506");
	REQUIRE(ConvertBinaryToString(vec).to_Stringlower() == "010203040506");
}
