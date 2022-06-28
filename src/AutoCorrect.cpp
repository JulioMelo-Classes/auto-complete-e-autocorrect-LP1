#include "AutoCorrect.hpp"
#include <vector>
#include <string>
#include <iostream>

using namespace std;

AutoCorrect::AutoCorrect(WordDataBase *dataBase)
{
    m_dbWords = dataBase;
}

void AutoCorrect::wordsWithShortestDistance(string t_word, int t_distanceGap){
    auto toUpperCase = [](const string str)->string{
        string uper = str;

        for(size_t i=0; i < str.length(); i++){
            uper[i] = std::toupper(str[i]);
        }

        return uper;
    }; // Função para deixar toda string em maiúsculo

    t_word = toUpperCase(t_word);

    const auto iteratorsAutoCorrect = m_dbWords->withSizeOf(t_word); 
    const auto begin = iteratorsAutoCorrect.first;
    const auto end = iteratorsAutoCorrect.second;

    vector<pair< int , string>> m_vCorrTemp;

    for (auto it = begin; it < end; it++)
    {
        if (AutoCorrect::levenshteinDistance((*it).second, t_word, (*it).second.size(), t_word.size()) <= t_distanceGap) //Distancia aceitavel
        {
            m_vCorrTemp.push_back(*it);
        }
    }

    sort(m_vCorrTemp.begin(), m_vCorrTemp.end(), [](const auto p1, const auto p2) -> bool
         { return p1.first > p2.first; });



    for (size_t j = 0; j <= t_distanceGap; j++)
    {
        for (size_t i = 0; i < m_vCorrTemp.size(); i++)
        {
            if (AutoCorrect::levenshteinDistance(m_vCorrTemp[i].second, t_word, m_vCorrTemp[i].second.size(), t_word.size()) == j) //Distancia aceitavel
            {
                m_vCorr.push_back(m_vCorrTemp[i]);
            }
        }
    }


}

int min(int x, int y, int z) { return min(min(x, y), z); }

int AutoCorrect::levenshteinDistance(string t_valA, string t_valB, int t_sizeA, int t_sizeB)
{
     auto toUpperCase = [](const string str)->string{
        string uper = str;
        for(size_t i=0; i < str.length(); i++){
            uper[i] = std::toupper(str[i]);
        }
        return uper;
    }; // Função para deixar toda string em maiúsculo

	t_valA = toUpperCase(t_valA);
	t_valB = toUpperCase(t_valB);


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

vector<pair< int , string>>::iterator AutoCorrect::getBegin(){return m_vCorr.begin();};

vector<pair< int , string>>::iterator AutoCorrect::getEnd(){return m_vCorr.end();};

size_t AutoCorrect::getBaseSize(){return m_vCorr.size();};

void AutoCorrect::clearVCorr(){m_vCorr.clear();};

void AutoCorrect::sortByWeight(){
    const auto begin = m_vCorr.begin();
    const auto end = m_vCorr.end();
    
    sort(begin, end, [](const auto p1, const auto p2)->bool{
        return p1.first > p2.first;
    });
}
