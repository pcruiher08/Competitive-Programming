#include <iostream>
#include <string>

int countSubstring(const std::string& str, const std::string& sub)
{
	if (sub.length() == 0) return 0;
	int count = 0;
	for (size_t offset = str.find(sub); offset != std::string::npos;
	offset = str.find(sub, offset + sub.length()))
	{
		++count;
	}
	return count;
}
int main()
{
    std:: string x;
    getline(std::cin, x);
	std::cout << countSubstring(x, "CodingRush2014")    << '\n';
	return 0;
}