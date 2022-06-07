#include <iostream>
#include <vector>
#include <string>
#include "AutoComplete.hpp"
using namespace std;

AutoComplete::AutoComplete(vector<pair<int, string>>& t_base_)
{
    m_baseComp = t_base_;
}

pair<int, int> AutoComplete::searchPrefix(string t_val){

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
    int upper = upper_bound(m_baseComp.begin(), m_baseComp.end(), make_pair(0, t_val), funcUpper) - m_baseComp.begin();
    int low = lower_bound(m_baseComp.begin(), m_baseComp.end(), make_pair(0, t_val), funcLower) - m_baseComp.begin();
    
    for (size_t i = upper; i < low; i++)
    {
        m_vComp.push_back(m_baseComp[i]);
    }
    
    return make_pair(upper, low);//prescindível
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