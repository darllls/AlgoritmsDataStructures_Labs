#include <iostream>
#include <fstream>
#include <string>
int shift(std::string word, char character, int pos)
{
	for (int i = word.size() - 1; i >= 0; --i)
	{
		if (word[i] == character)
		{
			int h = pos - i;
			return h > 0 ? h : 1;
		}
	}
	return word.size();
}
void BM(std::string text, std::string substr, int* results, int& n)
{
	n = 0;
	int text_size = text.size();
	int substr_size = substr.size();

	int sh = 0;
	while (sh <= (text_size - substr_size))
	{
		int j = substr_size - 1;
		while (j >= 0 && substr[j] == text[sh + j]) j--;
		if (j < 0)
		{
			results[n] = sh;
			n++;
			sh++;
		}
		else
		{
			sh += shift(text, text[sh + j], j);
		}
	}
}
int main()
{
	std::string text;
	std::string string;
	std::fstream file;
	file.open("file.txt", std::ios::in);
	getline(file, text);
	getline(file, string);
	std::cout << "First string:\n\n";
	std::cout << text << "\n\n";
	std::cout << "Second string: " << string << "\n\n";
	int results[256];
	int n;
	BM(text, string, results, n);
	std::cout << "Second string at: ";
	for (int i = 0; i < n; ++i)
	{
		std::cout << results[i] << " ";
	}
	std::cout << "\n";
	return 0;
}