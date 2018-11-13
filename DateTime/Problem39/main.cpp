// 39. Measuring function execution time
// Write a function that can measure the execution time of a function(with any number of
// arguments) in any required duration(such as seconds, milliseconds, microseconds, and so
// on).
// 39.함수의 실행 시간을 측정하세요
// 원하는 duration(나노초, 밀리어초, 마이크로초)에 대해 실행시간을 측정할수 있는 함수를
// 작성해주세요

#include "gsl/gsl"
// create `main` function for catch
#define CATCH_CONFIG_MAIN   
#include "catch2/catch.hpp"

// Redirect CMake's #define to C++ constexpr string
constexpr auto TestName = PROJECT_NAME_STRING;

long fibonacci(int n)
{
    if (n < 3) return 1;
    return fibonacci(n-1) + fibonacci(n-2);
}

TEST_CASE("Measuring function execution time") {
	std::chrono::time_point<std::chrono::system_clock> start, end;
	start = std::chrono::system_clock::now();
	std::cout << "f(42) = " << fibonacci(42) << '\n';
	end = std::chrono::system_clock::now();

	std::chrono::duration<double> elapsed_seconds = end-start;
	std::time_t end_time = std::chrono::system_clock::to_time_t(end);

	std::cout << "finished computation at " << std::ctime(&end_time)
		<< "elapsed time: " << elapsed_seconds.count() << "s\n";
}