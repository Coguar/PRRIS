// Algorithm2.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include "pch.h"
#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <sstream>
#include <functional>

//разбивает строку на слова
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
//проверяет соответствует ли префикс данной строке
bool isSuffix(std::string const& word, std::string const& prefix)
{
	return word.size() >= prefix.size() &&
		word.substr(0, prefix.size()) == prefix;
}

//возвращает количество записей с требуемым префиксом
int getCount(std::vector<std::string> const& contacts, std::string const& prefix)
{
	//кол-во записей
	int count = 0;
	//поиск первого элемента с требуемым префиксом (итератор)
	auto it = std::find_if(contacts.begin(), contacts.end(), std::bind(isSuffix, std::placeholders::_1, prefix));
	//пока элемент содержит преффикс - продолжаем
	//если элемент не содержит преффикс то дальше проверять смысла нет т.к. массив заранее отсортирован
	while (it != contacts.end() && isSuffix(*it, prefix))
	{
		//увеличиваем счетчик
		++count;
		//увеличиваем итератор
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
		//получаем введенную команду
		std::getline(std::cin, str);
		//делим команду на слова
		auto words = getwords(str);
		//слов в комманде только 2
		if (words.size() != 2) continue;

		if (words[0] == "Add")
		{
			contacts.push_back(words[1]);
			//сортируем после добавления
			std::sort(contacts.begin(), contacts.end());
		}
		else if (words[0] == "Find")
		{
			//вывод колличества
			std::cout << words[1] << " " << getCount(contacts, words[1]) << " coincidence" << std::endl;
		}
		
	}
}

