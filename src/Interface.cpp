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

    if(m_autoComplete->getBaseSize() == 0){ // Se não houver elemento nenhum na base de palavras
        string msg = "No match found"; // 

        return msg.length(); 
    }

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

    Interface::printLine(h1, h2, lineSize);
}

/*static*/ size_t Interface::getNumberOfLines(size_t max){
    size_t maxBase = m_autoComplete->getBaseSize(); // MODIFICAR DEPOIS QUANDO TIVER O AUTOCORRECT

    maxBase = (maxBase==0)?1: maxBase; // Se não tiver palavras candidatas, reserva um espaço pro "No match found"

    return (maxBase < max)? maxBase: max;
}

/*static*/ void Interface::printCandidateWords(size_t n){
    const size_t lineSize = Interface::getLineSize();
    n = Interface::getNumberOfLines(n);

    auto beginComp = m_autoComplete->getBegin();
    auto endComp = m_autoComplete->getEnd();

    Interface::printHeader(lineSize);
    for(size_t i=0; i < n; i++){
        string autoCompleteWord = (i==0)?"No match found":"";
        string autoCorrectWord = ""; // Modificar depois
        
        if(i < m_autoComplete->getBaseSize()){ // Enquanto ainda tem palavras na base
            autoCompleteWord = (*beginComp).second;
            beginComp++;
        }
        const string spacesAutoComplete = Interface::getSpaceString(lineSize - autoCompleteWord.length());

        Interface::printLine(autoCompleteWord, autoCorrectWord, lineSize);
    }
}

/*static*/ void Interface::printLine(string autoCompleteWord, string autoCorrectWord, size_t lineSize){
    const string autoCompleteSpaces = Interface::getSpaceString(lineSize - autoCompleteWord.length());

    std::cout << autoCompleteWord << autoCompleteSpaces << "   | " << autoCorrectWord <<std::endl;
}