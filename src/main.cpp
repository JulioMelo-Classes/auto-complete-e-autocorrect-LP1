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
        // const std::string path_file = argv[1]; // Arquivo informado pelo usuário
        WordDataBase db = WordDataBase("../data/ptbrcorpus.txt");
        db.sortAlphabetically();
        AutoComplete acomp = AutoComplete(&db); // inicializa a classe AutoComplete com a base de palavras
        acomp.searchPrefix("AB"); // procura na base de dados por palavras que iniciem com esse prefixo
        acomp.sortByWeight();     // Ordena o vetor de palavras candidatas ao autocomplete pelo peso
        db.sortBySentenceSyze();
        AutoCorrect acorr = AutoCorrect(&db, db.getBase()); // inicializa a classe AutoCorrect com a base de palavras
        // db.printWordDataBase(false, 200);
        //-----------------------------------------------------------------------------------------------------------------------
        //-----------------------------------------------------------------------------------------------------------------------
        //-----------------------------------------------------------------------------------------------------------------------
        //-----------------------------------------------------------------------------------------------------------------------
        string n = "COCHIXO";
        acorr.wordsWithShortestDistance(n, 3, 3);
        cout << "----- " << n.size() << endl;
        acorr.printAutoCorrectBase(false, 30);
        cout << "levenshtein - " << acorr.levenshteinDistance("DESCONHECIMENTO", "DESCONEHCINAHTO", 11, 11) << endl;
        Interface::setAutoComplete(&acomp);
        Interface::printCandidateWords(8);
    }
    else
    {
        std::cout << "Argumentos inválidos!" << std::endl;
    }
    return 0;
}