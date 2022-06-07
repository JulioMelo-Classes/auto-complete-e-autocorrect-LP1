#ifndef AutoComplete_hpp
#define AutoComplete_hpp
#include <string>
#include <vector>
#include "WordDataBase.hpp"

using namespace std;

/*Classe responsável por processar a base de palavras e gerar o vComp*/
class AutoComplete{
    private: 
        WordDataBase *m_dbWords; //Base armazenando a quantidade de ocorrências e as palavras
        vector<pair< int , string>> m_vComp; // Base armazenando todas entradas da base que iniciam com o prefixo buscado
    public:

        /**
         * @brief Constrói uma objeto do tipo AutoComplete
         * 
         * @param dataBase referência para um banco de palavras
         */
        AutoComplete(WordDataBase *dataBase);

        /**
         * @brief Faz uma busca das ocorrencias do prefixo na base de palavras e alimenta m_vComp
         * 
         * @param t_val prefixo a ser pesquisado na base
         */
        void searchPrefix(string t_val);

        /**
         * @brief Limpa o vetor m_vComp
         */
        void clearVComp();

        /**
         * @brief Imprime a base de m_vComp
         * 
         * @param limiter Um booleano que representa se a busca vai ser limitada à um número específico ou não
         * @param limit Um número que corresponde ao limite de palavras que serão mostradas (Se o limiter for false esse parâmetro
         */
        void printAutoCompleteBase(bool limiter,size_t limit);
};
#endif