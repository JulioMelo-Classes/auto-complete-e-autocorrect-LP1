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
         * @brief Procura o par cuja sentença é a maior de todas (Em quantidade de letras)
         * 
         * @return pair<int, string> Com o par da maior sentença da base
         */
        pair<int, string> getBiggestSentence();

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