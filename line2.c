#include "library.h"


/*! Verifica se o ID inserido pelo utilizador existe */
/*! Se existir, chama o procedimento para imprimir os destinos desse ID */
void CheckIfIDExists(Tree_Iberia_Cities *tree, unsigned long int id, int *ptrNumberOfDestinations)
{
    if (tree)
    {
        if (tree->idOrigin == id)
        {
            *ptrNumberOfDestinations = tree->countDestinations;
            ShowDestinations(tree->treeDestination);
        }

        if (id < tree->idOrigin)
            CheckIfIDExists(tree->left, id, ptrNumberOfDestinations);
        
        if (id > tree->idOrigin)
            CheckIfIDExists(tree->right, id, ptrNumberOfDestinations);
    }
}

/*! Procedimento para imprimir os destinos e o seu custo */
void ShowDestinations(Tree_Destination *tree)
{
    if (tree)
    {
        ShowDestinations(tree->left);

        printf("\n\tID: %lu\tCusto: %f", tree->idDestination, tree->cost);
        
        ShowDestinations(tree->right);
    }
}