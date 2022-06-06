#include <iostream>
#include "WordDataBase.hpp"

int main(int argc, char *argv[]){

    // if(argc == 2){
    //     const std::string path_file = argv[1]; // Arquivo informado pelo usuário

    //     WordDataBase db = WordDataBase(path_file);
        
    //     //db.sortAlphabetically();
    //     db.sortBySentenceSyze();

    //     db.printBase(true, 5);
    // }else{
    //     std::cout << "Argumentos inválidos!" << std::endl;
    // }
    std::vector<std::string> sentences = {"ABRA", "ABRACO", "SAO JOSE", "SAO PAULO", "SAO PEDRO", "SAO VALENTIN"};
    std::sort(sentences.begin(), sentences.end());

    auto lower = std::lower_bound(sentences.begin(), sentences.end(), "SAO P", [](const std::string str, const std::string sentence)->bool{
        return str <= sentence;
    });

    auto upper = std::upper_bound(sentences.begin(), sentences.end(), "SAO P", [](const std::string sentence, const std::string str)->bool{
        std::string sub = str.substr(0, sentence.length());

        return sentence < sub;
    });

    std::cout << (lower - sentences.begin()) << std::endl;
    std::cout << (upper - sentences.begin()) << std::endl;

    for(lower; lower < upper; lower++){
        const std::string palavra = *lower;

        std::cout << palavra << std::endl;        
    }

    return 0;
}