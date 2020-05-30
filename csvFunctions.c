#include <library.h>

/*! Verifica se a palavra inserida pelo utilizador existe*/
/*! Se existir, totalOcurrencesLine6 toma o valor das ocorrencias da palavra */
void IsInTree(Tree_WorldCities *tree, char *word)
{
    int cityCount = 0;
    if(tree)
    {
        if(strcmp(tree->data.city, word) < 0)
            IsInTree(tree->left, word);
        
        if(strcmp(tree->data.city, word) > 0)
            IsInTree(tree->right, word);

        if(strcmp(tree->data.city, word) == 0)
        {
            cityCount ++;
            printf("\n\tID: %d", tree->data.city);
        }
    }
    printf("\nExiste um tota de %d cidades com esse nome.");
}