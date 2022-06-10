#include "Interface.hpp"
using namespace std;

#include "AutoComplete.hpp"
#include "AutoCorrect.hpp"
#include <iostream>

/*Declaração de variáveis estáticas*/
AutoComplete* Interface::m_autoComplete = nullptr;
AutoCorrect* Interface::m_autoCorrect = nullptr;

/*static*/ void Interface::setAutoComplete(AutoComplete *ac){m_autoComplete = ac;};

/*static*/ void Interface::setAutoCorrect(AutoCorrect *ac){m_autoCorrect = ac;};

/*static*/ string Interface::getSpaceString(size_t strLen){
    string espacos = "";
    
    for(size_t i=0;i < strLen; i++){
        espacos+=" ";
    }
    return espacos;
}

/*static*/ size_t Interface::getLineSize(){
    const auto beginComp = m_autoComplete->getBegin();
    const auto endComp = m_autoComplete->getEnd();
    const string header = "Autocomplete";

    auto maxPair = std::max_element(beginComp, endComp,[](const auto &p1, const auto &p2)->bool{
        size_t strLen1 = p1.second.length();
        size_t strLen2 = p2.second.length();

        return strLen1 < strLen2;
    });

    size_t maxSize = ((*maxPair).second.length() > header.length())? (*maxPair).second.length(): header.length();

    return maxSize;
}

/*static*/ void Interface::printHeader(size_t lineSize){
    const string h1 = "Autocomplete";
    const string h2 = "Autocorrect";

    const string spaces = Interface::getSpaceString(lineSize - h1.length());

    std::cout << h1 << spaces << "   | " << h2 << std::endl;
}

/*static*/ void Interface::printCandidateWords(size_t n){
    const size_t lineSize = Interface::getLineSize();
    std::cout << lineSize << std::endl;
    auto beginComp = m_autoComplete->getBegin();
    auto endComp = m_autoComplete->getEnd();

    Interface::printHeader(lineSize);
    for(size_t i=0; i < n && beginComp!=endComp; i++, beginComp++){
        const string word = (*beginComp).second;
        const string spaces = Interface::getSpaceString(lineSize - word.length());

        std::cout << word << spaces << "   |" << std::endl;
    }
}