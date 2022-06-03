#include <iostream>
#include "WordDataBase.hpp"

int main(int argc, char *argv[]){

    if(argc == 2){
        const std::string path_file = argv[1]; // Arquivo informado pelo usuário

        WordDataBase db = WordDataBase(path_file);
        
        db.sortAlphabetically();

        db.printBase(true, 5);
    }else{
        std::cout << "Argumentos inválidos!" << std::endl;
    }

    return 0;
}