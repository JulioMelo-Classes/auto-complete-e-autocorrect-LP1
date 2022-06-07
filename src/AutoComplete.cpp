#include <iostream>
#include <vector>
#include <string>
#include "AutoComplete.hpp"
using namespace std;

AutoComplete::AutoComplete(WordDataBase *dataBase)
{
    m_dbWords = dataBase;
}

void AutoComplete::searchPrefix(string t_val){

    auto funcUpper = [&](pair<int, string> str, pair<int, string> sentence)
    {
        string a = sentence.second.substr(0, str.second.size());
        return str.second.compare(a) <= 0;
    };

    auto funcLower = [&](pair<int, string> sentence, pair<int, string> str)
    {
        string a = sentence.second.substr(0, str.second.size());
        return str.second.compare(a) >= 0;
    };

    auto begin = m_dbWords->getBeginBase(); // Inicia begin com o começo da base de palavras
    auto end = m_dbWords->getEndBase(); // Inicia end com o final da base de palavras

    begin = upper_bound(begin, end, make_pair(0, t_val), funcUpper);
    end = lower_bound(begin, end, make_pair(0, t_val), funcLower);

    for(auto it = begin; it < end; it++){
        m_vComp.push_back(*it);
    }
}

void AutoComplete::clearVComp(){
    m_vComp.clear();

}

void AutoComplete::sortByWeight(){
    const auto begin = m_vComp.begin();
    const auto end = m_vComp.end();
    
    std::sort(begin, end, [](const auto p1, const auto p2)->bool{
        return p1.first > p2.first;
    });
}

void AutoComplete::printAutoCompleteBase(bool t_limiter,size_t t_limit){
    size_t t = (t_limit > 0)? t_limit: 0;
    if (!t_limiter){
        t = m_vComp.size();
    }
    if(m_vComp.empty()){
        return;
    }
    cout << "-----AUTOCOMPLETE------" << endl;
    for (size_t i = 0; i < m_vComp.size(); i++)
    {
        cout << m_vComp[i].second << endl;
    }
}