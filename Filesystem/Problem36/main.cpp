// 36. Deleting files older than a given date
// Write a function that, given the path to a directory and a duration, deletes all
// the entries (files or subdirectories) older than the specified duration, in a
// recursive manner. The duration can represent anything, such as days, hours,
// minutes, seconds, and so on, or a combination of that, such as one hour and
// twenty minutes. If the specified directory is itself older than the given duration,
// it should be deleted entirely.
// 36. 특정 날짜보다 오래된 파일들을 지우기
// 어떤 디렉토리에 대한 경로와 기간을 받아서, 정해진 기간보다 오래된 모든 것(파일들 또는 서브
// 디렉토리들)을 재귀적으로 삭제하는 함수를 작성하라. 기간은 일, 시간, 분, 초, 그외 등등, 또는
// 이 것 들의 조합인 한시간 그리고 이십분과 같이 어떤 것으로도 나타낼 수 있다. 만약에 특정 디렉
// 토리가 정해진 기간보다 오래 됐으면, 이 디렉토리 전체가 지워져야 한다

#include "gsl/gsl"
// create `main` function for catch
#define CATCH_CONFIG_MAIN   
#include "catch2/catch.hpp"

// Redirect CMake's #define to C++ constexpr string
constexpr auto TestName = PROJECT_NAME_STRING;

#include <experimental/filesystem>
#include <ctime>

bool checkModifyDate(std::tm* time, const std::experimental::filesystem::path & p)
{
	auto fileTime = std::experimental::filesystem::last_write_time(p);

	std::time_t cftime = decltype(fileTime)::clock::to_time_t(fileTime);
	std::time_t mtime = std::mktime(time); // time_t 형식으로 변경. 

	std::cout << p.generic_string() << " ";

	if (cftime < mtime)
	{
		if (std::experimental::filesystem::remove(p) == false)
		{
			std::cout << "ERROR REMOVE FILE!" << std::endl;
		}
		else
		{
			std::cout << "REMOVE FILE SUCCESS!" << std::endl;
		}
		return false;
	}
	else
	{ 
		std::cout << "FILE SURVIVE!" << std::endl;
		return true;
	}
}

void checkDirectory(std::tm* time, const std::experimental::filesystem::path & p)
{
	if (std::experimental::filesystem::is_directory(p))
	{
		if (false == checkModifyDate(time, p))
		{
			return;
		}
	}

	if (true == checkModifyDate(time, p))
	{
		for (auto& p : std::experimental::filesystem::recursive_directory_iterator(p))
		{
			checkModifyDate(time, p);
		}
	}
}

TEST_CASE("Deleting files older than a given date") {
	std::istringstream s("2018-10-01");
	std::tm x = { 0, };
	s >> std::get_time(&x, "%Y-%m-%d");

	checkDirectory(&x, "C:\\Users\\euna501\\Downloads\\LINE WORKS");
}