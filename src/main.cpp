#include <iostream>
#include "WordDataBase.hpp"
#include "AutoComplete.hpp"
#include "Interface.hpp"

int main(int argc, char *argv[]){

    if(argc == 2){
        const std::string path_file = argv[1]; // Arquivo informado pelo usuário

        WordDataBase db = WordDataBase(path_file);
        db.sortAlphabetically();

        AutoComplete ac = AutoComplete(&db);//inicializa a classe AutoComplete com a base de palavras

        ac.searchPrefix("sa");// procura na base de dados por palavras que iniciem com esse prefixo
        ac.sortByWeight(); // Ordena o vetor de palavras candidatas ao autocomplete pelo peso

        Interface::setAutoComplete(&ac);
        Interface::printCandidateWords(8);

    }else{
        std::cout << "Argumentos inválidos!" << std::endl;
    }

    return 0;
}