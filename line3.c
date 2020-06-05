#include "library.h"

/*! Procedimento para imprimir cidades com população acima de 50 000 */
void Get_50k(Tree_Iberia_Cities *iberiaTree)
{
    if (iberiaTree)
    {
        if (iberiaTree->population > 50000)
        {
            printf("\n\nID: %lu\tPopulation: %.f\n", iberiaTree->idOrigin, iberiaTree->population);
            Get_30k(iberiaTree->treeDestination);
        }

        Get_50k(iberiaTree->left);
        Get_50k(iberiaTree->right);
    }
}

/*! Procedimento para imprimir destinos com população menor que 30 000, da cidade com população acima de 50 000 */
void Get_30k(Tree_Destination *destinationTree)
{
    if (destinationTree)
    {
        if (destinationTree->population < 30000)
            printf("\n\t\tID: %lu\tPopulation: %.f", destinationTree->idDestination, destinationTree->population);
        
        Get_30k(destinationTree->left);
        Get_30k(destinationTree->right);
    }
}