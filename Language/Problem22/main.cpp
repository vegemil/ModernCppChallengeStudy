﻿// 다양한 온도 스케일 표기
// 가장 많이 사용되는 섭씨, 화씨, Kelvin의 세 가지 온도 스케일을 표현하고 변환할 수 있도록 작
// 은 라이브러리를 작성하라. 이 라이브러리는 당신이 36.5_deg로 섭씨를, 97.7f로 화씨를, 그리
// 고 309.65_K로 Kelvin을 온도 문자 표현으로 작성할 수 있게 해야 한며, 이 값들로 연산을 수행
// 하고 변한을 한다.

#include "gsl/gsl"

// create `main` function for catch
#define CATCH_CONFIG_MAIN   
#include <catch2/catch.hpp>

// Redirect CMake's #define to C++ constexpr string
constexpr auto TestName = PROJECT_NAME_STRING;


