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
    const auto iteratorsAutoComplete = m_dbWords->startsWith(t_val); 

    const auto begin = iteratorsAutoComplete.first;
    const auto end = iteratorsAutoComplete.second;

    for(auto it = begin; it < end; it++){
        m_vComp.push_back(*it);
    }
}

void AutoComplete::clearVComp(){
    m_vComp.clear();
}

vector<pair<int, string>>::iterator AutoComplete::getBegin(){return m_vComp.begin();};

vector<pair<int, string>>::iterator AutoComplete::getEnd(){return m_vComp.end();};

size_t AutoComplete::getBaseSize(){return m_vComp.size();};

void AutoComplete::sortByWeight(){
    const auto begin = m_vComp.begin();
    const auto end = m_vComp.end();
    
    std::sort(begin, end, [](const auto p1, const auto p2)->bool{
        return p1.first > p2.first;
    });
}