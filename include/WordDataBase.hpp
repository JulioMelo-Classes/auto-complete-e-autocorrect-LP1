#ifndef WordDataBase_hpp
#define WordDataBase_hpp
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

/*Classe responsável por gerenciar um banco de dados de palavras*/
class WordDataBase{
    private:
        string m_file_path; // Caminho do arquivo de texto
        vector<pair< int , string>> m_base; // Base armazenando a quantidade de ocorrências e a sentença
    public:

        /**
         * @brief Constrói uma objeto do tipo WordDataBase
         * 
         * @param filePath O caminho (path) do arquivo de palavras utilizado
         */
        WordDataBase(string filePath);

        // /**
        //  * @brief funcao get de t_base como referência
        //  * 
        //  * @return referencia de m_base
        //  * 
        //  */
        // vector<pair<int, string>>& getBase();

        /**
         * @brief Pegar o iterator do começo da base de palavras
         * 
         * @return O iterator que referencía o começo (begin) da base de palavras
         */
        vector<pair< int , string>>::iterator getBeginBase();

        /**
         * @brief Pegar o iterator do final da base de palavras
         * 
         * @return O iterator que referencia o final (end) da base de palavras
         */
        vector<pair< int , string>>::iterator getEndBase();

        /**
         * @brief Ordena a base pela ordem alfabética das palavras
         * 
         */
        void sortAlphabetically();

        /**
         * @brief Ordena a base pelo tamanho das sentenças
         * 
         */
        void sortBySentenceSyze();


        /**
         * @brief imprime a base de dados
         * 
         */
        void printWordDataBase(bool limiter, size_t limit);

        /**
         * @brief funcao get da base
         * 
         * * @return referencia da base
         *
         */
        vector<pair<int, string>> &getBase();



};
#endif