#include <iostream>
#include "WordDataBase.hpp"
#include "AutoComplete.hpp"

int main(int argc, char *argv[]){

    if(argc == 2){
        const std::string path_file = argv[1]; // Arquivo informado pelo usuário

        WordDataBase db = WordDataBase(path_file);
        db.sortAlphabetically();
        //db.printWordDataBase(true, 40);//exibe a base de palavras(primeiros 40)

        AutoComplete ac = AutoComplete(&db);//inicializa a classe AutoComplete com a base de palavras
        ac.searchPrefix("POR");// procura na base de dados por palavras que iniciem com esse prefixo
        ac.sortByWeight();

        ac.printAutoCompleteBase(false, 0);//exibe a base vComp (inteira)
    }else{
        std::cout << "Argumentos inválidos!" << std::endl;
    }

    return 0;
}