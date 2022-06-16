#include "AutoCorrect.hpp"
#include <vector>
#include <string>
#include <iostream>
using namespace std;

AutoCorrect::AutoCorrect(WordDataBase *dataBase, vector<pair<int, string>> &t_base_)
{
    m_dbWords = dataBase;
    m_baseComp = t_base_;
}

int min(int x, int y, int z) { return min(min(x, y), z); }
void AutoCorrect::wordsWithShortestDistance(string t_word, int t_distanceUp, int t_distanceDown)
{
    auto toUpperCase = [](const string str)->string{
        string uper = str;

        for(size_t i=0; i < str.length(); i++){
            uper[i] = std::toupper(str[i]);
        }

        return uper;
    }; // Função para deixar toda string em maiúsculo

    t_word = toUpperCase(t_word);

    auto funcLower = [&](pair<int, string> str, pair<int, string> sentence)
    {
        return str.second.length() <= sentence.second.length() - 1 - t_distanceDown;
    };

    auto funcUpper = [&](pair<int, string> sentence, pair<int, string> str)
    {
        return sentence.second.size() + t_distanceUp < str.second.size();
    };

    auto begin = m_dbWords->getBeginBase(); // Inicia begin com o começo da base de palavras
    auto end = m_dbWords->getEndBase();     // Inicia end com o final da base de palavras

    auto lowIt = lower_bound(begin, end, make_pair(0, t_word), funcLower);
    auto upperIt = upper_bound(begin, end, make_pair(0, t_word), funcUpper);

    int low = lowIt - begin;
    int upper = upperIt - begin;

    // for (int it = low; it < upper; it++)
    // {
    //     if (AutoCorrect::levenshteinDistance(m_baseComp[it].second, t_word, m_baseComp[it].second.size(), t_word.size()) < 6)
    //     {
    //         m_vCorr.push_back(m_baseComp[it]);
    //     }
    // }
    for(auto it = lowIt; it < upperIt; it++){
        if (AutoCorrect::levenshteinDistance((*it).second, t_word, (*it).second.size(), t_word.size()) < 6)
        {
            m_vCorr.push_back(*it);
        }
    }
}


int AutoCorrect::levenshteinDistance(string t_valA, string t_valB, int t_sizeA, int t_sizeB)
{
    int dp[t_sizeA + 1][t_sizeB + 1];
    for (int i = 0; i <= t_sizeA; i++)
    {
        for (int j = 0; j <= t_sizeB; j++)
        {
            if (i == 0)
                dp[i][j] = j;
            else if (j == 0)
                dp[i][j] = i;
            else if (t_valA[i - 1] == t_valB[j - 1])
                dp[i][j] = dp[i - 1][j - 1];
            else
                dp[i][j] = 1 + min(dp[i][j - 1],      // Insert
                                   dp[i - 1][j],      // Remove
                                   dp[i - 1][j - 1]); // Replace
        }
    }
    return dp[t_sizeA][t_sizeB];
}

void AutoCorrect::printAutoCorrectBase(bool t_limiter, size_t t_limit)
{
    size_t t = (t_limit > 0) ? t_limit : 0;
    if (!t_limiter)
    {
        t = m_vCorr.size();
    }
    if (m_vCorr.empty())
    {
        return;
    }
    cout << "-----AUTOCOMPLETE------" << endl;
    for (size_t i = 0; i < t; i++)
    {
        cout << i << " - " << m_vCorr[i].second << " - " << m_vCorr[i].second.size() << endl;
    }
}
