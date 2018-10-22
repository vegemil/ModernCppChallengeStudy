#include <iostream>
#include <cmath>

//## 주어진 숫자안에서 가장 큰 소수 구하기
//사용자가 입력한 숫자안에서 가장 큰 소수 구하기(이 값은 양수여야한다)

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

	unsigned int result = 0;

	for (int i = num; i > 1; i--)
	{
		if (true == isPrime(i))
		{
			result = i;
			break;
		}
	}

	std::cout << "결과값 : " << result << std::endl;

	return 0;
}