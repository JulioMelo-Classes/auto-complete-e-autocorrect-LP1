#ifndef AutoComplete_hpp
#define AutoComplete_hpp
#include <string>
#include <vector>
#include "WordDataBase.hpp"

using namespace std;

/*Classe responsável por processar a base de palavras e gerar o vComp*/
class AutoComplete{
    private: 
        vector<pair< int , string>> m_baseComp; //Base armazenando a quantidade de ocorrências e a sentença
        vector<pair< int , string>> m_vComp; // Base armazenando todas entradas da base que iniciam com o prefixo buscado
    public:

        /**
         * @brief Constrói uma objeto do tipo AutoComplete
         * 
         * @param t_base_ referencia do vetor da WordDataBase
         */
        AutoComplete(vector<pair<int, string>>& t_base_);

        /**
         * @brief Faz uma busca das ocorrencias do prefixo na base
         * 
         * @param t_val prefixo a ser pesquisado na base
         * 
         * @return um par com o indice inicial e final das ocorrencias do prefixo em t_baseComp(prescindivel)
         */
        pair<int, int> searchPrefix(string t_val);

        /**
         * @brief Imprime a base de m_vComp
         * 
         * @param limiter Um booleano que representa se a busca vai ser limitada à um número específico ou não
         * @param limit Um número que corresponde ao limite de palavras que serão mostradas (Se o limiter for false esse parâmetro
         */
        void printAutoCompleteBase(bool limiter,size_t limit);
};
#endif