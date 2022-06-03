#ifndef LoadBase_hpp
#define LoadBase_hpp
#include <string>
#include <vector>
//#include "Algo.hpp"
using namespace std;

class LoadBase{
    private:
        string m_dir;
        vector<pair< int , string>> m_base;
    public:
        LoadBase(string dir);
        void imprimeBase(bool header);
};
#endif