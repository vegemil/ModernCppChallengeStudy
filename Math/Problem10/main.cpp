#include <iostream>
#include <bitset>

//## Grey Code
// 5자리의 비트 숫자에 대해 일반 2진표현, 그레이코드 표현, 10진수로 표현하기

unsigned long binToGrey(unsigned long num)
{
	return num ^ (num >> 1);
}

int main(void)
{
	for (int i = 0; i < 32; ++i)
	{
		std::bitset<5> bin(i);

		std::bitset<5> grey(binToGrey(bin.to_ulong()));

		std::cout << "bin : " << bin.to_string() << ", grey : " << grey.to_string() << ", dex : " << i << std::endl;
	}

	return 0;
}