// Algorithm1.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include "pch.h"
#include <iostream>
#include <sstream>
#include <fstream>
#include <vector>
#include <algorithm>

//разбиваем строку на слова
std::vector<std::string> getWordsList(std::ifstream& input)
{
	std::vector<std::string> words;
	std::string line;
	while (std::getline(input, line))
	{
		std::string word;
		std::stringstream streamLine(line);
		while (streamLine >> word)
		{
			words.push_back(word);
		}
	}
	return words;
}

std::pair<int, int> calculateMinMaxDistance(std::vector<std::string> const& words, std::string const& w1, std::string const& w2)
{
	std::vector<int> firstWordPositions;
	std::vector<int> secondWordPositions;
	//собираем индексы позиций уже в отсортированном по возврастанию виде
	for (size_t i = 0; i < words.size(); ++i)
	{
		if (words[i] == w1) firstWordPositions.push_back(int(i));
		if (words[i] == w2) secondWordPositions.push_back(int(i));
	}
	std::pair<int, int> minMax = { words.size(), 0 };
	//Максимальный - обязательно разница крайеих индексов
	minMax.second = std::max(std::abs(firstWordPositions[firstWordPositions.size() - 1] - secondWordPositions[0]), 
		std::abs(secondWordPositions[secondWordPositions.size() - 1] - firstWordPositions[0]));
	//поиск минимального
	for (auto i : firstWordPositions)
	{
		for (auto k : secondWordPositions)
		{
			int distance = std::abs(i - k);
			//если 2 индекс больше первого и дистанция больше минимально найденной, 
			//то дистанция будет только увеличиваться, нет смысла продолжать поиск
			if (distance > minMax.first && k > i)
			{
				break;
			}
			minMax.first = std::min(distance, minMax.first);
		}
	}
	//Вычитаем единицу из значений так как нам нужно найти количество слов между требуемыми словами
	return { minMax.first - 1, minMax.second - 1 };
}

std::pair<int, int> getMinMaxDistance(std::string const& inputFileName, std::string const& w1, std::string const& w2)
{
	std::ifstream input(inputFileName);
	std::vector<std::string> words = getWordsList(input);
	return calculateMinMaxDistance(words, w1, w2);

}

int main()
{
	std::string inputFileName("input.txt");
	std::string word1 = "cat";
	std::string word2 = "dog";
	auto result = getMinMaxDistance(inputFileName, word1, word2);

    std::cout << "Min distance " << result.first << ", Max distance " << result.second << std::endl;
}
