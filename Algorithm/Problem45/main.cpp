#include "gsl/gsl"

// create `main` function for catch
#define CATCH_CONFIG_MAIN   
#include "catch2/catch.hpp"

// Redirect CMake's #define to C++ constexpr string
constexpr auto TestName = PROJECT_NAME_STRING;

#include <queue>

template<typename T> void print_queue(T& q) {
    while(!q.empty()) {
        std::cout << q.top() << " ";
        q.pop();
    }
    std::cout << '\n';
}

TEST_CASE("Priority queue") {
    std::priority_queue<int> q;

    REQUIRE(q.empty() == true);

    for(int n : {1,8,5,6,3,4,0,9,7,2})
    {
        q.push(n);
    }

    REQUIRE(q.size() == 10);

    print_queue(q);

    REQUIRE_FALSE(q.size() == 10);
}