// 37. Finding files in a directory that match a regular expression
// Write a function that, given the path to a directory and a regular expression,
// returns a list of all the directory entries whose names match the regular
// expression.
// 37. 정규표현식에 맞는 파일들을 디렉토리에서 찾기
// 디렉토리 경로와 정규표현식을 받아서, 이름이 정규표현식에 맞는 모든 디렉토리 목록을 반환하
// 는 함수를 작성하라.

#include "gsl/gsl"
// create `main` function for catch
#define CATCH_CONFIG_MAIN   
#include "catch2/catch.hpp"

// Redirect CMake's #define to C++ constexpr string
constexpr auto TestName = PROJECT_NAME_STRING;

TEST_CASE("tokenize", "[Joining strings]") {

}