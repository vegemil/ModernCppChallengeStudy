// 38. Temporary log files
// Create a logging class that writes text messages to a discardable text file. The
// text file should have a unique name and must be located in a temporary
// directory. Unless specified otherwise, this log file should be deleted when the
// instance of the class is destroyed. However, it should be possible to retain the
// log file by moving it to a permanent location.
// 38. 임시 로그 파일들
// 텍스트 메시지를 버릴 수 있는 텍스트 파일에 작성하는 로깅 클래스를 만들어라. 텍스트 파일은
// 유일한 이름을 갖고 있어야 하며, 임시의 디렉토리에 위치해야 한다. 다른 방식을 정의하지 않으
// 면, 이 로그파일은 클래스의 인스턴스가 파괴될 때, 지워져야 한다. 하지만 로그파일을 다른 영속
// 적인 위치로 이동시킴으로써, 유지가 가능해야 한다.

#include "gsl/gsl"
// create `main` function for catch
#define CATCH_CONFIG_MAIN   
#include "catch2/catch.hpp"

// Redirect CMake's #define to C++ constexpr string
constexpr auto TestName = PROJECT_NAME_STRING;

TEST_CASE("tokenize", "[Joining strings]") {

}