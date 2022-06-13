#ifndef Interface_hpp
#define Interface_hpp

#include "AutoComplete.hpp"
#include "AutoCorrect.hpp"

//#include "Algo.hpp"
using namespace std;

/*Classe que realiza a interface entre o programa e o usuário*/
class Interface{
    private:
        static AutoComplete *m_autoComplete;
        static AutoCorrect *m_autoCorrect;

    public:
    
    /**
     * @brief Configura o autocomplete da interface
     * 
     * @param ac AutoComplete a ser inserido
     */
    static void setAutoComplete(AutoComplete *ac);

    /**
     * @brief Configura o autocorrect da interface
     * 
     * @param ac AutoCorrect a ser inserido
     */
    static void setAutoCorrect(AutoCorrect *ac);

    /**
     * @brief Retorna uma string apenas com espaços em branco
     * 
     * @param strLen O tamanho da string a ser gerada
     * 
     * @return std::string Uma string com os espaços em branco
     */
    static std::string getSpaceString(size_t strLen);

    /**
     * @brief Calcula o tamanho da linha com base nas palavras do autocomplete
     * 
     * @return size_t Referente ao tamanho da linha
     */
    static size_t getLineSize();

    /**
     * @brief Imprime as palavras candidatas ao autocomplete e autocorrect com base em vComp e vCor
     * 
     * @param n Quantidade máxima de linhas que serão impressas (Tanto as do autocomplete quanto as do autocorrect)
     */
    static void printCandidateWords(size_t n);

    /**
     * @brief Imprime uma linha da tabela de palavras candidatas
     * 
     * @param autoCompleteWord Palavra da base de autocomplete 
     * @param autoCorrectWord Palavra da base de autocorrect
     */
    static void printLine(string autoCompleteWord, string autoCorrectWord, size_t lineSize);

    /**
     * @brief Imprime o cabeçalho da tabela de saída
     * 
     * @param lineSize Tamanho da linha do auto complete
     */
    static void printHeader(size_t lineSize);

};
#endif