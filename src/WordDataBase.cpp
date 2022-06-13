#include "WordDataBase.hpp"
#include <string>
#include <fstream>
#include <sstream>
#include <vector>
#include <iostream>
using namespace std;

WordDataBase::WordDataBase(string filePath)
{
	m_file_path = filePath;

	fstream palavrasfile;
	palavrasfile.open(m_file_path, ios::in);

	int peso;
	string palavra;
	bool swap = true;
	string frase;
	int count = 0;

	while (getline(palavrasfile, frase))
	{
		istringstream iss(frase);
		string token;
		while (getline(iss, token, '\t'))
		{
			if (swap)
			{
				peso = atoi(token.c_str());
				swap = false;
			}
			else
			{
				palavra = token;
				swap = true;
			}
		}
		m_base.push_back(make_pair(peso, palavra));
	}
}

vector<pair<int, string>>::iterator WordDataBase::getBeginBase(){return m_base.begin();}


vector<pair<int, string>>::iterator WordDataBase::getEndBase(){return m_base.end();}

void WordDataBase::sortAlphabetically()
{
	auto begin = m_base.begin();
	auto end = m_base.end();

	std::sort(begin, end, [](const auto &p1, const auto &p2) -> bool
			  { return p1.second < p2.second; });
}

void WordDataBase::sortBySentenceSyze()
{
	auto begin = m_base.begin();
	auto end = m_base.end();

	std::sort(begin, end, [](const auto &p1, const auto &p2) -> bool
			  { return p1.second.length() < p2.second.length(); });
}
