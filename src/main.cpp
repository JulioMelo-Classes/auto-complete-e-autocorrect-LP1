#include <iostream>
#include "WordDataBase.hpp"

bool isSubStrBegin(const std::string &sub,const std::string &str){
    if(sub.length() > str.length()) return false;

    if(str.substr(0, sub.length()) == sub)
        return true;
    

    return false;
}

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
    std::vector<std::string> sentences = {"ABRACO", "SAO JOSE", "SAO PAULO", "SAO VALENTIN", "ABRA" };
    std::sort(sentences.begin(), sentences.end());

    auto lower = std::lower_bound(sentences.begin(), sentences.end(), "ABC", [](const std::string s1, const std::string s2)->bool{
        return s1 <= s2;
    });

    auto upper = std::upper_bound(sentences.begin(), sentences.end(), "ABC", [](const std::string s1, const std::string s2)->bool{
        return s1 > s2;
    });

    for(lower; lower < upper; lower++){
        const std::string palavra = *lower;

        if(isSubStrBegin("ABC", palavra))
            std::cout << *lower << std::endl;
        else{
            break;
        }
        
    }

    return 0;
}