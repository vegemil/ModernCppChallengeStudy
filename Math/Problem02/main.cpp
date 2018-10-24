#include <iostream>
#include <algorithm>    // std::max

//## 최대 공약수
//두개의 정수가 주어질때 이 두 숫자의 최대공약수 를 구하고 출력하여라.

int greatestCommonDivisior(unsigned int num1, unsigned num2)
{
	return (num2 == 0) ? num1 : greatestCommonDivisior(num2, (num1 % num2));
}

int main(void)
{
	unsigned int num1, num2 = 0;

	std::cout << "양수를 입력하세요 " << std::endl;
	std::cin >> num1;
	std::cin >> num2;

	unsigned int result = 1;

	//while (false)
	//{
	//	unsigned int biggerNum = std::max(num1, num2);

	//	for (unsigned int i = 1; i < biggerNum; ++i)
	//	{
	//		if ((num1 % i == 0) && (num2 % i == 0))
	//		{
	//			result = i;
	//		}
	//	}
	//}

	result = greatestCommonDivisior(num1, num2);

	std::cout << "결과값 : " << result << std::endl;

	return 0;
}