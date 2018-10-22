#include <iostream>
#include <math.h>

//## Armstrong numbers
//3자리의 Armstrong number 구하기

int calcArmstrong(int i)
{
	int sum = 0;

	for (int j = 2; j >= 0; --j)
	{
		int num = (i / pow(10, j));

		sum += pow(num, 3);

		i -= num * pow(10, j);
	}
	 
	return sum;
}

int main(void)
{
	for (int i = 100; i < 1000; ++i)
	{
		if (calcArmstrong(i) == i)
		{
			std::cout << "결과값 : " << i << std::endl;
		}
	}

	return 0;
}