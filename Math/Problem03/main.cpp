#include <iostream>
#include <algorithm>    // std::max

//## 최소 공배수
//두개 이상의 숫자의 최소 공배수를 계산하고 출력하여라

int greatestCommonDivisior(unsigned int num1, unsigned num2)
{
	return (num2 == 0) ? num1 : greatestCommonDivisior(num2, (num1 % num2));
}

int leastCommonMultiple(unsigned int num1, unsigned num2)
{
	return (num1 * num2) / greatestCommonDivisior(num2, (num1 % num2));
}

int main(void)
{
	unsigned int num1, num2 = 0;

	std::cout << "양수를 입력하세요 " << std::endl;
	std::cin >> num1;
	std::cin >> num2;

	unsigned int result = leastCommonMultiple(num1, num2);

	std::cout << "결과값 : " << result << std::endl;
	
	return 0;
}