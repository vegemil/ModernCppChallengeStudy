// 32. Pascalʼs triangle
// Write a function th#t prints up to 10 rows of Pascalʼs triangle to the console.
// 32. 파스칼의 삼각형
// 콘솔로 파스칼의 삼각형 10행을 출력하는 함수를 작성하라.

#include "gsl/gsl"
// create `main` function for catch
#define CATCH_CONFIG_MAIN   
#include "catch2/catch.hpp"



// Redirect CMake's #define to C++ constexpr string
constexpr auto TestName = PROJECT_NAME_STRING;

void pascalTriangle(int line)
{
	int coef = 1;

	for (int i = 0; i < line; i++)
	{
		for (int space = 1; space <= line - i; space++)
			std::cout << "  ";

		for (int j = 0; j <= i; j++)
		{
			if (j == 0 || i == 0)
				coef = 1;
			else
				coef = coef * (i - j + 1) / j;

			std::cout << coef << "   ";
		}
		std::cout << std::endl;
	}
}

TEST_CASE("Pascalʼs triangle") {
	pascalTriangle(10);
}