// 33. Tabular printing of a list of processes
// Suppose you have a snapshot of the list of all processes in a system. The
// information for each process includes name, identifier, status (which can be
// either running or suspended), account name (under which the process runs),
// memory size in bytes, and platform (which can be either 32-bit or 64-bit). Your
// task is to writer a function that takes such a list of processes and prints them
// to the console alphabetically, in tabular format. All columns must be left-
// aligned, except for the memory column which must be right-aligned. The value
// of the memory size must be displayed in KB. The following is an example of the
// output of this function:
// chrome.exe 1044 Running marius.bancila 25180 32-bit
// chrome.exe 10100 Running marius.bancila 227756 32-bit
// cmd.exe 512 Running SYSTEM 48 64-bit
// explorer.exe 7108 Running marius.bancila 29529 64-bit
// skype.exe 22456 Syspended marius.bancila 656 64-bit
// 33. 표로 정리된 프로세스들의 목록을 출력
// 당신이 어떤 시스템의 모든 프로세스들의 목록을 스냅샷으로 가지고 있다고 가정하자. 각 프로세
// 스의 정보는 이름, 식별자, 상태(running 또는 suspended 두 가지 상태일 수 있다), 계정 이름
// (프로세스가 동작중인 계정), 메모리 크기(byte), 그리고 플랫폼(32-bit 또는 64-bit 일 수 있
// 다)을 포함한다. 당신의 임무는 프로세스의 목록을 가져와서, 콘솔에 알파벳 표의 형식으로 목록
// 을 출력하는 함수를 작성하는 것이다. 모든 컬럼은 반드시 left-aligned 여야 하며, 메모리 컬럼
// 만 예외적으로 right-aligned 이다. 메모리 크기 값은 반드시 KB로 보여져야 한다. 아래에 보여
// 지는 것은, 이 하마수의 출력 예제이다:
// chrome.exe 1044 Running marius.bancila 25180 32-bit
// chrome.exe 10100 Running marius.bancila 227756 32-bit
// cmd.exe 512 Running SYSTEM 48 64-bit
// explorer.exe 7108 Running marius.bancila 29529 64-bit
// skype.exe 22456 Syspended marius.bancila 656 64-bit

#include "gsl/gsl"
// create `main` function for catch
#define CATCH_CONFIG_MAIN   
#include "catch2/catch.hpp"

// Redirect CMake's #define to C++ constexpr string
constexpr auto TestName = PROJECT_NAME_STRING;

TEST_CASE("tokenize", "[Joining strings]") {

}