#include "library.h"

/*! Se existir, CityCount toma o valor de quantas cidades existem com esse nome */
/*! Se não existir, CityCount fica com valor zero  */
void SearchCity(Tree_World_Cities *tree, char *word, int *ptrCityCount)
{
    if(tree)
    {
        SearchCity(tree->left, word, ptrCityCount);

        if (strcmp(tree->data.city, word) == 0)
        {
            ++*ptrCityCount;
            printf("\n\tID: %lu", tree->data.id);
        }

        SearchCity(tree->right, word, ptrCityCount);
    }
}