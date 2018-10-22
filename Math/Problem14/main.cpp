#include <iostream>
#include <vector>
#include <string>

bool checkISBN(std::vector<int> isbnInt)
{
	int sum = 0;
	for (int i = 0; i < 9; ++i)
	{
		sum += isbnInt[i] * (i + 1);
	}

	if ((sum % 11) == isbnInt[9])
	{
		return true;
	}

	return false;
}

int main(void)
{
	std::string isbnStr;

	std::cout << "isbn 코드를 입력하세요" << std::endl;
	std::cin >> isbnStr;

	std::vector<int> isbnInt;

	for (auto iter : isbnStr)
	{
		int num = iter - '0';
		isbnInt.push_back(num);
	}

	for (auto iter : isbnInt)
	{
		std::cout << iter;
	}
	
	std::cout << "는 ISBN 코드가 " << (checkISBN(isbnInt) ? "맞습니다." : "아닙니다.");

	return 0;
}