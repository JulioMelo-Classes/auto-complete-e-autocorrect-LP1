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

        /**
         * @brief Imprime a base de dados
         * 
         * @param limiter Um booleano que representa se a busca vai ser limitada à um número específico ou não
         * @param limit Um número que corresponde ao limite de palavras que serão mostradas (Se o limiter for false esse parâmetro
         * não terá relevância) 
         */
        void printBase(bool limiter, size_t limit);

        /**
         * @brief Ordena a base pela ordem alfabética das palavras
         * 
         */
        void sortAlphabetically();


};
#endif