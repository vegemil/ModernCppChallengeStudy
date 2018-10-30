// 문자열을 바이너리(Binary)로 변환
// 16진수 문자열을 받아서, 그 문자열 숫자값들이 변환된 8비트 정수들의 벡터를 반환하는 함수를
// 작성하라. 다음의 예를 참고하시오:
// 입력: "BAADF00D" or "baadF00D", 출력: {0xBA, 0xAD, 0xF0, 0x0D}
// 입력 "010203040506", 출력: {1, 2, 3, 4, 5, 6}

#include <iostream>
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
private:
	std::vector<int> vec;

	void convert(std::string str)
	{
		std::string temp;

		for (auto iter : str)
		{
			temp.push_back(iter);

			if (temp.size() == 2)
			{
				int value = std::stoi(temp, nullptr, 16);
				vec.push_back(value);
				temp.clear();
			}
		}
	}

public:
	ConvertBinaryToString(std::string str)
	{
		convert(str);
	}

	std::string to_String()
	{
		std::string resultStr;

		resultStr.append("{");
		for (auto iter : vec)
		{
			if (resultStr.size() != 1)
			{
				resultStr.append(", ");
			}

			std::string str;
			std::stringstream stream;
			stream << std::hex << iter;

			str.append(stream.str());

			stream.str(std::string());
			stream.clear();

			for (auto character : str)
			{
				if (true == std::isalpha(character, std::locale()))
				{
					std::string temp;
					for (auto c : str)
					{
						temp.push_back(std::toupper(c, std::locale()));
					}

					resultStr.append("0x");
					stream << std::hex << std::setfill('0') << std::setw(2) << temp;
					resultStr.append(stream.str());
					break;
				}
				else
				{
					resultStr.append(str);
				}
			}
		}
		resultStr.append("}");

		return resultStr;
	}
};

TEST_CASE("String to Binary conversion", "[String2binary]") {
	REQUIRE(ConvertBinaryToString("BAADF00D").to_String() == "{0xBA, 0xAD, 0xF0, 0x0D}");
	REQUIRE(ConvertBinaryToString("010203040506").to_String() == "{1, 2, 3, 4, 5, 6}");
}
