// 35. Computing the size of a directory
// Write a function that computes the size of a directory, in bytes, recursively. It
// should be possible to include whether symbolic links should be followed or not.
// 35. 디렉토리의 크기를 계산하기
// 재귀적으로, 몇 바이트 인지, 어떤 디렉토리의 크기를 계산하는 함수를 작성하라. 심볼릭 링크들
// 을 포함해서 계산할 지 선택할 수 있어야 한다.

#include "gsl/gsl"
// create `main` function for catch
#define CATCH_CONFIG_MAIN   
#include "catch2/catch.hpp"

// Redirect CMake's #define to C++ constexpr string
constexpr auto TestName = PROJECT_NAME_STRING;

#include <experimental/filesystem>

TEST_CASE("Computing the size of a directory", "[Joining strings]") {
	auto currentFolderInfo = std::experimental::filesystem::space(std::experimental::filesystem::current_path());

	std::cout << "Current Path : " << std::experimental::filesystem::current_path() << std::endl;

	std::cout << ".        Capacity       Free      Available\n"
		<< "current Folder:   " << currentFolderInfo.capacity << "   "
		<< currentFolderInfo.free << "   " << currentFolderInfo.available << '\n';
}