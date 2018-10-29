// 다양한 온도 스케일 표기
// 가장 많이 사용되는 섭씨, 화씨, Kelvin의 세 가지 온도 스케일을 표현하고 변환할 수 있도록 작
// 은 라이브러리를 작성하라. 이 라이브러리는 당신이 36.5_deg로 섭씨를, 97.7f로 화씨를, 그리
// 고 309.65_K로 Kelvin을 온도 문자 표현으로 작성할 수 있게 해야 한며, 이 값들로 연산을 수행
// 하고 변한을 한다.

#include "gsl/gsl"

// create `main` function for catch
#define CATCH_CONFIG_MAIN   
#include <catch2/catch.hpp>
#include <string>
#include <map>

// Redirect CMake's #define to C++ constexpr string
constexpr auto TestName = PROJECT_NAME_STRING;


class CConvertTemperatureScales {
private:

	typedef struct {
		float	offset;
		float	scale;
		int		precision; // 소수점.
	}CONVINFO;

	typedef std::map<std::string, CONVINFO> MAP_CONVINFO;

	float m_fDegree;
	MAP_CONVINFO m_mapConvInfo;
	const char* m_keyC;
	const char* m_keyF;
	const char* m_keyK;
	

	std::string _ToConvert(const char* szKey)
	{
		MAP_CONVINFO::iterator iter = m_mapConvInfo.find(szKey);
		if (m_mapConvInfo.end() == iter)
			return "";
		const int BUFSIZE = 1024;
		char szPattern[BUFSIZE];
		char szBuffer[BUFSIZE];

		sprintf(szPattern, "%%.%df_%s", (*iter).second.precision, szKey);
		sprintf(szBuffer, szPattern, m_fDegree*(*iter).second.scale + (*iter).second.offset);

		return szBuffer;
	}

public:
	CConvertTemperatureScales(const char* szData) 
		: m_fDegree(0.f)
	{
		m_keyC = "deg";
		m_keyF = "f";
		m_keyK = "K";

		m_mapConvInfo[m_keyC] = CONVINFO{ 0.f, 1.f, 1 };
		m_mapConvInfo[m_keyF] = CONVINFO{ 32.f, 180.f / 100.f, 1 };
		m_mapConvInfo[m_keyK] = CONVINFO{ 273.15f, 1.f, 2 };

		assgign(szData);
	}

	void assgign(const char* szData) {
		// TODO : implementation.
		if (!szData)
			return;
		const char* szFind = strchr(szData, '_');

		if (!szFind )
			return;
		float fValue = atof(szData);

		MAP_CONVINFO::iterator iter = m_mapConvInfo.find(++szFind);

		if (m_mapConvInfo.end() == iter)
			return;

		m_fDegree = (fValue - (*iter).second.offset) / (*iter).second.scale;
	}

	std::string toK() {
		// TODO : implementation.

		return _ToConvert(m_keyK);
	}

	std::string toF() {
		// TODO : implementation.
		return _ToConvert(m_keyF);
	}

	std::string toC() {
		// TODO : implementation.
		return _ToConvert(m_keyC);
	}
};

TEST_CASE("Literals of various temperature scales", "[temperature scales]") {
	REQUIRE(CConvertTemperatureScales("36.5_deg").toF() == "97.7_f");
	REQUIRE(CConvertTemperatureScales("97.7_f").toK() == "309.65_K");
	REQUIRE(CConvertTemperatureScales("309.65_K").toC() == "36.5_deg");
}


