#include <iostream>

//## 3가 5가 나누어지는 수의 합을 구하여라
//사용자가 입력한 숫자까지 3 또는 5이 나누어지는 수의 합을 출력하여라

int main(void)
{
	unsigned int num = 0;

	std::cout << "양수를 입력하세요 " << std::endl;
	std::cin >> num;

	unsigned int result = 0;

	for (unsigned int i = 0; i <= num; ++i)
	{
		if ((i % 3 == 0) && (i % 5 == 0))
		{
			result += i;
		}
	}

	std::cout << "결과값 : " << result << std::endl;

	return 0;
}