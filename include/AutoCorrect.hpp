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
        vector<pair< int , string>> m_vCorr;
    public:

        /**
         * @brief Constrói uma objeto do tipo AutoCorrect
         * 
         * @param dataBase referência para um banco de palavras
         */
        AutoCorrect(WordDataBase *dataBase);

        /**
         * @brief calcula a distancia entre duas palavras utilizando o algoritmo de levenshtein
         * 
         * @param t_valA palavra a ser comparada 
         * @param t_valB palavra de comparacao
         * @param t_sizeA tamanho da palavra a ser comparada 
         * @param t_sizeB tamanho da palavra de comparacao
         */
        int levenshteinDistance(string t_valA, string t_valB, int t_sizeA, int t_sizeB);

        /**
         * @brief Busca as palavras com tamanhos proximo e calcula a distancia levenshtein entre elas
         * @param t_word palavra a ser comparada na base de dados
         * @param t_distanceGap define a distancia Levenshtein aceitavel para as palavras candidatas
         */
        void wordsWithShortestDistance(string t_word, int distanceGap);

        /**
         * @brief Pega o iterador do começo da base do autoCorrect
         * 
         * @return vector<pair< int , string>>::iterator com o iterador apontando para o início do vetor da base
         */
        vector<pair< int , string>>::iterator getBegin();

        /**
         * @brief Pega o iterador do fim da base do autoCorrect
         * 
         * @return vector<pair< int , string>>::iterator com o iterador apontando para o fim da base 
         */
        vector<pair< int , string>>::iterator getEnd();

        /**
         * @brief Pega o tamanho do vetor da base de palavras do autoCorrect
         * 
         * @return size_t Referente ao tamanho do vetor da base autoCorrect
         */
        size_t getBaseSize();

        /**
         * @brief Limpa a base vCorr removendo todos os elementos
         */
        void clearVCorr();
};
#endif