#include <iostream>
#include "LoadBase.hpp"

int main(int argc, char *argv[]){
    /*codigo?*/
    LoadBase db = LoadBase("../data/ptbrcorpus.txt");
    db.imprimeBase(true);
    return 0;
}