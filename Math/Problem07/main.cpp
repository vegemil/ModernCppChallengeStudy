#include <iostream>
#include <set>
#include <map>

//##친화수 구하기
//1,000,000 보다 작은 친화수 쌍을 구하기

int calcSumDivisor(int value)
{
	int ret = 1;
	int end = value;

	for (int i = 2; i < end; ++i)
	{
		end = value / i;

		if (value%i == 0)
			ret += end + i;
		else
			++end;		
	}

	return ret;
}

int main(void)
{
	const unsigned int num = 1000000;

	std::set<int> setCalculated;
	std::map<int, int> mapAmicableList;

	for (int i = 2; i <= num; ++i)
	{
		if (setCalculated.end() != setCalculated.find(i))
			continue;
		int sumDivisor1 = calcSumDivisor(i);
		setCalculated.insert(i);

		if (setCalculated.end() != setCalculated.find(sumDivisor1))
			continue;
		int sumDivisor2 = calcSumDivisor(sumDivisor1);
		setCalculated.insert(sumDivisor1);

		if (i == sumDivisor2)
		{
			printf("%d (%d,%d)\n", mapAmicableList.size(), i, sumDivisor1);
			mapAmicableList.insert(std::map<int, int>::value_type(i, sumDivisor1));
		}
	}

	return 0;
}