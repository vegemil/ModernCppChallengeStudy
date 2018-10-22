#include <iostream>

int countCollatzConjecture(int num)
{
	int count = 1;
	unsigned int value = num;

	while (value != 1)
	{
		if (value % 2 == 0)
		{
			value = value * 0.5;
		}
		else
		{
			value = (value * 3) + 1;
		}
		++count;
	}

	return count;
}

int main(void)
{
	int num = 0;
	int count = 0;

	for (int i = 2; i <= 1000000; ++i)
	{
		int j = countCollatzConjecture(i);
		if (count < j)
		{
			num = i;
			count = j;
		}
	}

	std::cout << "num : " << num << std::endl;
	std::cout << "count : " << count << std::endl;

 	return 0;
}