#include <iostream>
#include <vector>

//## 과잉수 구하기
//사용자가 입력한 숫자까지 과잉수를 구하기
//[과잉수란](https://ko.wikipedia.org/wiki/%EA%B3%BC%EC%9E%89%EC%88%98)

bool isPrime(int num)
{
	if (num <= 1)
	{
		return false;
	}

	for (int i = 2; (i * i) <= num; ++i)
	{
		if (num % i == 0)
		{
			return false;
		}
	}

	return true;
}

int main(void)
{
	unsigned int num = 0;

	std::cout << "양수를 입력하세요 " << std::endl;
	std::cin >> num;

	std::vector<int> resultList;

	for (int i = 2; i <= num; ++i)
	{
		if (false == isPrime(i))
		{
			int sum = 0;
			for (int j = 1; j < i; ++j)
			{
				if ((i % j) == 0)
				{
					sum += j;
				}
			}

			if (sum > i)
			{
				resultList.push_back(i);
			}
		}
	}

	for (auto iter : resultList)
	{
		std::cout << "결과값 : " << iter << std::endl;
	}

	return 0;
}