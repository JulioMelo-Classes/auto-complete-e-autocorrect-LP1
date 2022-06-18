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

        WordDataBase db = WordDataBase(path_file);

        db.sortAlphabetically();
        AutoComplete acomp = AutoComplete(&db); // inicializa a classe AutoComplete com a base de palavras
        acomp.searchPrefix("AB"); // procura na base de dados por palavras que iniciem com esse prefixo
        acomp.sortByWeight();     // Ordena o vetor de palavras candidatas ao autocomplete pelo peso

        db.sortBySentenceSyze();
        AutoCorrect acorr = AutoCorrect(&db); // inicializa a classe AutoCorrect com a base de palavras

        string n = "AB";
        acorr.wordsWithShortestDistance(n, 2, 2);

        Interface::setAutoComplete(&acomp);
        Interface::setAutoCorrect(&acorr);

        Interface::printCandidateWords(10);
    }
    else
    {
        std::cout << "Argumentos inválidos!" << std::endl;
    }
    return 0;
}