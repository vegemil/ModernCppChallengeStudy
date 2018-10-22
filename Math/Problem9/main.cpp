#include <iostream>

//##Prime factors of a number
//사용자가 입력한 숫자의 소인수를 구하기

int main(void)
{
	unsigned int num = 0;

	std::cout << "양수를 입력하세요 " << std::endl;
	std::cin >> num;

	for (int i = 2; i <= num; i++)
	{
		while (num % i == 0)
		{
			num /= i;
			std::cout << i << " ";
		}
	}

	return 0;
}