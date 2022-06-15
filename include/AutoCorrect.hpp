#ifndef AutoCorrect_hpp
#define AutoCorrect_hpp
#include <string>
#include <vector>
#include "WordDataBase.hpp"

//#include "Algo.hpp"
using namespace std;

class AutoCorrect{
    private: 
        WordDataBase *m_dbWords; //Base armazenando a quantidade de ocorrências e as palavras
        vector<pair< int , string>> m_vCorr; // Base armazenando todas entradas da base que iniciam com o prefixo buscado
    public:

        /**
         * @brief Constrói uma objeto do tipo AutoCorrect
         * 
         * @param dataBase referência para um banco de palavras
         */
        AutoCorrect(WordDataBase *dataBase);

        /**
         * @brief Faz uma busca das ocorrencias do prefixo na base de palavras e alimenta m_vComp
         * 
         * @param t_val prefixo a ser pesquisado na base
         */
        int levenshteinDistance(string t_valA, string t_valB, int t_sizeA, int t_sizeB);

        /**
         * @brief Limpa o vetor m_vComp
         */
        void clearVComp();

        /**
         * @brief Pega o iterador do começo da base do autocomplete
         * 
         * @return vector<pair< int , string>>::iterator com o iterador apontando para o início do vetor da base
         */
        vector<pair< int , string>>::iterator getBegin();

        /**
         * @brief Pega o iterador do fim da base do autocomplete
         * 
         * @return vector<pair< int , string>>::iterator com o iterador apontando para o fim da base 
         */
        vector<pair< int , string>>::iterator getEnd();

        /**
         * @brief Pega o tamanho do vetor da base de palavras do autocomplete
         * 
         * @return size_t Referente ao tamanho do vetor da base autocomplete
         */
        size_t getBaseSize();

        /**
         * @brief Ordena a base m_vComp pelo peso (ocorrências) das sentenças (Do maior para o menor)
         */
        void sortByWeight();
};
#endif