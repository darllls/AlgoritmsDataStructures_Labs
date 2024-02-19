#include <iostream>
#include <fstream>
#include <string>

void LPS(std::string substr, int M, int* lps)
{
	int len = 0;
	int i = 1;
	lps[0] = 0;
	while (i < M)
	{
		if (substr[i] == substr[len])
		{
			lps[i] = len + 1;
			len++;
			i++;
		}
		else
		{
			if (len != 0)
			{
				len = lps[len - 1];
			}
			else
			{
				lps[i] = 0;
				i++;
			}
		}
	}
}
void KMP(std::string text, std::string substr, int* results, int& n)
{
	n = 0;
	int N = text.length();
	int M = substr.length();
	int* lps = new int[M];
	for (int i = 0; i < M; ++i)
	{
		lps[i] = 0;
	}
	LPS(substr, M, lps);
	int i = 0;
	int j = 0;
	while (i < N - M + 1)
	{
		if (text[i] == substr[j])
		{
			i++;
			j++;
		}
		else
		{
			if (j != 0)
			{
				j = lps[j - 1];
			}
			else
			{
				i++;
			}
		}
		if (j == M)
		{
			results[n] = i - j;
			n++;
			j = lps[j - 1];
		}
	}
	delete[] lps;
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
	KMP(text, string, results, n);
	std::cout << "\nSecond string at: ";
	for (int i = 0; i < n; ++i)
	{
		std::cout << results[i] << " ";
	}
	std::cout << "\n";
	return 0;
}