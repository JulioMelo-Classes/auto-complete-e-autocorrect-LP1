#include <iostream>
#include "WordDataBase.hpp"
#include "AutoComplete.hpp"
#include "Interface.hpp"
#include <string>
using namespace std;

int main(int argc, char *argv[])
{
    if (argc == 2)
    {
        const std::string path_file = argv[1];

        WordDataBase dbComp = WordDataBase(path_file); // Cria banco de palavras para o autocomplete
        WordDataBase dbCorr = WordDataBase(path_file); // Cria banco de palavras para o autocorrect

        AutoComplete acomp = AutoComplete(&dbComp); // inicializa a classe AutoComplete com a base de palavras
        dbComp.sortAlphabetically();

        AutoCorrect acorr = AutoCorrect(&dbCorr); // inicializa a classe AutoCorrect com a base de palavras
        dbCorr.sortBySentenceSyze();

        // Configura o autocomplete e o autocorrect que serão usados na impressão da saída
        Interface::setAutoComplete(&acomp);
        Interface::setAutoCorrect(&acorr);
 
        const string inputMessage = "Digite uma palavra, ou parte dela, e digite Enter ou pressione Ctrl + d pra terminar: ";
        
        auto pairSentence = Interface::readSentence(inputMessage);

        while(pairSentence.second){ // Enquanto o usuário não digitou CTRL + D
            acomp.clearVComp();
            acorr.clearVCorr();

            const string sentence = pairSentence.first;

            acomp.searchPrefix(sentence); // procura na base de dados por palavras que iniciem com esse prefixo
            acomp.sortByWeight();     // Ordena o vetor de palavras candidatas ao autocomplete pelo peso

            acorr.wordsWithShortestDistance(sentence, 2, 2, 3); // procura na base de dados por palavras para o autocorrect

            Interface::printCandidateWords(true, 10, "Matches são");

            pairSentence = Interface::readSentence(inputMessage);
        }
    }
    else
    {
        std::cout << "Argumentos inválidos!" << std::endl;
    }
    return 0;
}