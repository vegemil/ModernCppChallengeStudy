#include <iostream>

//## 섹시 소수 쌍을 구하기
//사용자가 입력한 숫자까지 모든 섹시 소수를 구하여라
//[섹시 소수란](https://ko.wikipedia.org/wiki/%EC%84%B9%EC%8B%9C_%EC%86%8C%EC%88%98)

int main(void)
{
	unsigned int num = 0;

	std::cout << "양수를 입력하세요 " << std::endl;
	std::cin >> num;

	bool* array = new bool[num + 1];

	for (int i = 2; i <= num; ++i)
	{
		array[i] = true;
	}

	for (int i = 2; i <= sqrt(num); ++i)
	{
		if (true == array[i])
		{
			for (int j = i * i; j <= num; j += i)
			{
				array[j] = false;
			}
		}
	}

	for (int i = 2; i < num; ++i)
	{
		if ((i + 6) < num)
		{
			if ((true == array[i]) && (true == array[i + 6]))
			{
				std::cout << "(" << i << ", " << i + 6 << ")" << std::endl;
			}
		}
	}

	return 0;
}