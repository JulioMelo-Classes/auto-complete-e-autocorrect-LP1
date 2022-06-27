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
         * @brief Pegar o iterator do começo da base de palavras
         * 
         * @return O iterator que referencia o começo (begin) da base de palavras
         */
        vector<pair< int , string>>::iterator getBeginBase();

        /**
         * @brief Pegar o iterator do final da base de palavras
         * 
         * @return O iterator que referencia o final (end) da base de palavras
         */
        vector<pair< int , string>>::iterator getEndBase();

        /**
         * @brief Retorna um recorte do banco com todas as palavras que iniciam com uma determinada sentença
         * 
         * @param sentence Sentença a ser buscada
         * @return Um std::pair de iterators em que o primeiro elemento corresponde ao início do recorte e o segundo corresponde ao fim do recorte
         */
        pair<vector<pair< int , string>>::iterator, vector<pair< int , string>>::iterator> startsWith(string t_sentence);

        /**
         * @brief Retorna um recorte do banco com todas as palavras que possuam o tamanho igual ou maior q sentence
         * 
         * @param sentence sentenca a ter o tamanho comparado
         * @return Um std::pair de iterators em que o primeiro elemento corresponde ao início do recorte e o segundo corresponde ao fim do recorte
         */
        pair<vector<pair< int , string>>::iterator, vector<pair< int , string>>::iterator> withSizeOf(string t_sentence);

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
    
};
#endif