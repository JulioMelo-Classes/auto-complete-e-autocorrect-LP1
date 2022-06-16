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
        vector<pair< int , string>> m_baseComp;
        vector<pair< int , string>> m_vCorr; // Base armazenando todas entradas da base que iniciam com o prefixo buscado
    public:

        /**
         * @brief Constrói uma objeto do tipo AutoCorrect
         * 
         * @param dataBase referência para um banco de palavras
         */
        AutoCorrect(WordDataBase *dataBase, vector<pair<int, string>>& t_base_);

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
         * 
         * @param t_word palavra a ser comparada na base de dados
         * @param t_distanceUp define o tamanha maximo das palavras candidatas em relação a t_word
         * @param t_distanceDown define o tamanho minino das palavras candidatas em relacao a t_word
         */
        void wordsWithShortestDistance(string word, int t_distanceUp, int t_distanceDown);

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
         * @brief Ordena a base m_vCorr pelo peso (ocorrências) das sentenças (Do maior para o menor)
         */
        void sortByWeight();

        /**
         * @brief Imprime a base de m_vCorr
         * 
         * @param limiter Um booleano que representa se a busca vai ser limitada à um número específico ou não
         * @param limit Um número que corresponde ao limite de palavras que serão mostradas (Se o limiter for false esse parâmetro
         */
        void printAutoCorrectBase(bool t_limiter,size_t t_limit);
};
#endif