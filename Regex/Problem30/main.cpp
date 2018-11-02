// URL 부분을 추출
// URL을 나타내는 문자열을 받아서, URL의 각 부분(프로토콜, 도메인, 포트, 경로, 쿼리 그리고
// fragment)을 파싱(Parse)하고 추출하는 함수를 작성하라.

#include "gsl/gsl"
// create `main` function for catch
#define CATCH_CONFIG_MAIN   
#include "catch2/catch.hpp"

#include <string>
#include <locale>
#include <sstream>

// Redirect CMake's #define to C++ constexpr string
constexpr auto TestName = PROJECT_NAME_STRING;

void parseURL(const std::string& input) {
	// passing -1 as the submatch index parameter performs splitting
	std::string resultStr;

	std::regex url_regex(
		R"(^(([^:\/?#]+):)?(//([^\/?#]*))?([^?#]*)(\?([^#]*))?(#(.*))?)",
		std::regex::extended
	);

	std::smatch url_match_result;

	unsigned counter = 0;

	if (std::regex_match(input, url_match_result, url_regex)) {
		for (const auto& res : url_match_result) {
			std::cout << counter++ << ": " << res << std::endl;
		}
	}
}


TEST_CASE("URL Parsing") {
	parseURL("http://www.somehost.com/a.gif");
	parseURL("ftp://id:pass@192.168.1.234/a.gif");
	parseURL("mailto:somebody@mail.somehost.com");
}