#include "library.h"
#include <stdbool.h>

/*! Verifica se a palavra inserida pelo utilizador existe*/
/*! Se existir, totalOcurrencesLine6 toma o valor das ocorrencias da palavra */
void SearchCity(Tree_WorldCities *tree, char *word, int *ptrCityCount)
{
    if(tree)
    {
        if(strcmp(tree->data.city, word) < 0)
            SearchCity(tree->left, word, ptrCityCount);
        
        if(strcmp(tree->data.city, word) > 0)
            SearchCity(tree->right, word, ptrCityCount);

        if(strcmp(tree->data.city, word) == 0)
        {
            ++*ptrCityCount;
            printf("\n\tID: %d", tree->data.id);
            SearchCity(tree->right, word, ptrCityCount);
        }
    }
}