// 34. Removing empty lines from a text file
// Write a program that, given the path to a text file, modifies the file by removing
// all empty lines. Lines containing only whitespaces are considered empty.
// 34. 텍스트 파일에서 빈 줄을 제거
// 텍스트 파일의 경로를 받아서, 모든 비어있는 줄을 제거해서 파일을 수정하는 프로그램을 작성하
// 라. 오직 공백문자들(whitespaces)만으로 이루어진 줄을 비어있는 줄이라고 여긴다.

#include "gsl/gsl"
// create `main` function for catch
#define CATCH_CONFIG_MAIN   
#include "catch2/catch.hpp"

// Redirect CMake's #define to C++ constexpr string
constexpr auto TestName = PROJECT_NAME_STRING;

TEST_CASE("tokenize", "[Joining strings]") {

}