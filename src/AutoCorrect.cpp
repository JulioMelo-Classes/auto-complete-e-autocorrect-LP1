#include "AutoCorrect.hpp"
using namespace std;

AutoCorrect::AutoCorrect(WordDataBase *dataBase){
    m_dbWords = dataBase;
}

int min(int x, int y, int z) { return min(min(x, y), z); }

int AutoCorrect::levenshteinDistance(string t_valA, string t_valB, int t_sizeA, int t_sizeB)
{
    if (t_sizeA == 0)
        return  t_sizeB;
    if ( t_sizeB == 0)
        return t_sizeA;
    if (t_valA[t_sizeA - 1] == t_valB[t_sizeB - 1])
        return AutoCorrect::levenshteinDistance(t_valA, t_valB, t_sizeA - 1,  t_sizeB - 1);
    return 1 + min(levenshteinDistance(t_valA, t_valB, t_sizeA,  t_sizeB - 1), // Insert
                   levenshteinDistance(t_valA, t_valB, t_sizeA - 1,  t_sizeB), // Remove
                   levenshteinDistance(t_valA, t_valB, t_sizeA - 1, t_sizeB - 1) // Replace
                  );
}
 
