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
    const string header = "Autocomplete";

    if(m_autoComplete->getBaseSize() == 0){ // Se não houver elemento nenhum na base de palavras
        string msg = "No match found"; // 

        return msg.length(); 
    }

    const auto maxPair = m_autoComplete->getBiggestSentence();

    size_t maxSize = (maxPair.second.length() > header.length())? maxPair.second.length(): header.length();

    return maxSize;
}

/*static*/ void Interface::printHeader(size_t lineSize){
    const string h1 = "Autocomplete";
    const string h2 = "Autocorrect";

    Interface::printLine(h1, h2, lineSize);
}

/*static*/ size_t Interface::getNumberOfLines(bool limited, size_t max){
    size_t baseComplete = m_autoComplete->getBaseSize();
    size_t baseCorrect = m_autoCorrect->getBaseSize();

    size_t maxBase = (baseComplete > baseCorrect)? baseComplete: baseCorrect;

    maxBase = (maxBase==0)?1: maxBase; // Se não tiver palavras candidatas, reserva um espaço pro "No match found"

    if(!limited) return maxBase;
    
    return (maxBase < max)? maxBase: max;
}

/*static*/ void Interface::printCandidateWords(bool limited, size_t n, string message){
    const size_t lineSize = Interface::getLineSize();
    n = Interface::getNumberOfLines(limited, n);

    auto beginComp = m_autoComplete->getBegin();
    auto endComp = m_autoComplete->getEnd();

    auto beginCorr = m_autoCorrect->getBegin();
    auto endCorr = m_autoCorrect->getEnd();

    std::cout << message << std::endl;
    Interface::printHeader(lineSize);
    for(size_t i=0; i < n; i++){
        string autoCompleteWord = (i==0)?"No match found":"";
        string autoCorrectWord = (i==0)?"No match found":"";
        
        if(i < m_autoComplete->getBaseSize()){ // Enquanto ainda tem palavras na base
            autoCompleteWord = (*beginComp).second;
            beginComp++;
        }

        if(i < m_autoCorrect->getBaseSize()){
            autoCorrectWord = (*beginCorr).second;
            beginCorr++;
        }

        const string spacesAutoComplete = Interface::getSpaceString(lineSize - autoCompleteWord.length());

        Interface::printLine(autoCompleteWord, autoCorrectWord, lineSize);
    }
}

/*static*/ void Interface::printLine(string autoCompleteWord, string autoCorrectWord, size_t lineSize){
    const string autoCompleteSpaces = Interface::getSpaceString(lineSize - autoCompleteWord.length());

    std::cout << autoCompleteWord << autoCompleteSpaces << "   | " << autoCorrectWord <<std::endl;
}

/*static*/ pair<string, bool> Interface::readSentence(string message){
    pair<string, bool> par = make_pair("", false);

    std::cout << message;
    par.second = getline(cin, par.first) && !cin.eof();

    return par;
}