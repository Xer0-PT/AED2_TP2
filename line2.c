#include "library.h"

void CheckIfIDExists(Tree_Iberia_Cities *tree, unsigned long int id, int *ptrNumberOfDestinations)
{
    if (tree)
    {
        if (tree->idOrigin == id)
        {
            *ptrNumberOfDestinations = tree->countDestinations;
            ShowDestinations(tree->treeDestination);
        }
        CheckIfIDExists(tree->left, id, ptrNumberOfDestinations);
        CheckIfIDExists(tree->right, id, ptrNumberOfDestinations);
    }
}

void ShowDestinations(Tree_Destination *tree)
{
    if (tree)
    {

        ShowDestinations(tree->left);

        printf("\n\tID: %lu\tCusto: %f", tree->idDestination, tree->cost);
        
        ShowDestinations(tree->right);
    }
}