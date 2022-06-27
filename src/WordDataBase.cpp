#include "WordDataBase.hpp"
#include <string>
#include <fstream>
#include <sstream>
#include <vector>
#include <iostream>
using namespace std;
//* WORDDATABASE
WordDataBase::WordDataBase(string filePath)
{
	m_file_path = filePath;

	fstream palavrasfile;
	palavrasfile.open(m_file_path, ios::in);

	int peso;
	string palavra;
	bool swap = true;
	string frase;

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
//* STARTSWITH
pair<vector<pair< int , string>>::iterator, vector<pair< int , string>>::iterator> WordDataBase::startsWith(string t_sentence){
    auto toUpperCase = [](const string str)->string{
        string uper = str;
        for(size_t i=0; i < str.length(); i++){
            uper[i] = std::toupper(str[i]);
        }
        return uper;
    }; // Função para deixar toda string em maiúsculo

	t_sentence = toUpperCase(t_sentence);

	auto funcLower = [&](pair<int, string> str, pair<int, string> sentence){
        string uper = toUpperCase(str.second);
        return uper <= sentence.second;
    };

    auto funcUpper = [&](pair<int, string> sentence, pair<int, string> str){
        string prefix = str.second.substr(0, sentence.second.length());
        string uper = toUpperCase(prefix);
        return sentence.second < uper;
    };

	const auto begin = m_base.begin();
	const auto end = m_base.end();

	const auto lower = lower_bound(begin, end, make_pair(0, t_sentence), funcLower);
    const auto upper = upper_bound(begin, end, make_pair(0, t_sentence), funcUpper);

	return make_pair(lower, upper);
}
//* WITHSIZEOF
pair<vector<pair< int , string>>::iterator, vector<pair< int , string>>::iterator> WordDataBase::withSizeOf(string t_sentence){
    auto toUpperCase = [](const string str)->string{
        string uper = str;
        for(size_t i=0; i < str.length(); i++){
            uper[i] = std::toupper(str[i]);
        }
        return uper;
    }; // Função para deixar toda string em maiúsculo

	t_sentence = toUpperCase(t_sentence);

	auto funcLower = [&](pair<int, string> str, pair<int, string> sentence)
    {
        return str.second.length() <= sentence.second.length() - 1 ;
    };

    auto funcUpper = [&](pair<int, string> sentence, pair<int, string> str)
    {
        return sentence.second.size() + 1 < str.second.size();
    };

	const auto begin = m_base.begin();
	const auto end = m_base.end();

	const auto lower = lower_bound(begin, end, make_pair(0, t_sentence), funcLower);
    const auto upper = upper_bound(begin, end, make_pair(0, t_sentence), funcUpper);

	return make_pair(lower, upper);
}
//* SORTALPHABETICALLY
void WordDataBase::sortAlphabetically()
{
	auto begin = m_base.begin();
	auto end = m_base.end();

	std::sort(begin, end, [](const auto &p1, const auto &p2) -> bool
			  { return p1.second < p2.second; });
}
//* SORTBYSENTENCESIZE
void WordDataBase::sortBySentenceSyze()
{
	auto begin = m_base.begin();
	auto end = m_base.end();

	std::sort(begin, end, [](const auto &p1, const auto &p2) -> bool
			  { return p1.second.length() < p2.second.length(); });
}

