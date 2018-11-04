// Algorithm2.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include "pch.h"
#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <sstream>
#include <functional>
std::vector<std::string> getwords(std::string const& command)
{
	std::vector<std::string> words;
	std::stringstream sCommand(command);
	std::string tmp;
	while (sCommand >> tmp)
	{
		words.push_back(tmp);
	}
	return words;
}
bool isSuffix(std::string const& word, std::string const& prefix)
{
	return word.size() >= prefix.size() &&
		word.substr(0, prefix.size()) == prefix;
}

int getCount(std::vector<std::string> const& contacts, std::string const& prefix)
{
	int count = 0;
	auto it = std::find_if(contacts.begin(), contacts.end(), std::bind(isSuffix, std::placeholders::_1, prefix));
	while (it != contacts.end() && isSuffix(*it, prefix))
	{
		++count;
		++it;
	}
	return count;
}

int main()
{
	std::vector<std::string> contacts;
	std::string str;
	while (!std::cin.eof() && !std::cin.fail())
	{
		std::cout << "> ";
		std::getline(std::cin, str);
		auto words = getwords(str);
		if (words.size() != 2) continue;

		if (words[0] == "Add")
		{
			contacts.push_back(words[1]);
			std::sort(contacts.begin(), contacts.end());
		}
		else if (words[0] == "Find")
		{
			std::cout << words[1] << " " << getCount(contacts, words[1]) << " coincidence" << std::endl;
		}
		
	}
}

