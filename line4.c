#include "library.h"

/*! Procedimento que procura qual o maior número de destinos, atribuindo esse valor à variável MostDestinations por apontador */
void MostDestinations(Tree_Iberia_Cities *iberiaTree, int *ptrMostDestinations)
{
    if (iberiaTree)
    {
        MostDestinations(iberiaTree->left, ptrMostDestinations);
        
        if (iberiaTree->countDestinations > *ptrMostDestinations)
        {
            *ptrMostDestinations = iberiaTree->countDestinations;
        }
        
        MostDestinations(iberiaTree->right, ptrMostDestinations);
    }
}

/*! Procedimento para imprimir as cidades com número de destinos igual ao atribuído à variável MostDestinations */
void PrintMostDestinations(Tree_Iberia_Cities *iberiaTree, int mostDestinations)
{
    if (iberiaTree)
    {
        PrintMostDestinations(iberiaTree->left, mostDestinations);
        
        if (iberiaTree->countDestinations == mostDestinations)
        {
            printf("\nID: %lu", iberiaTree->idOrigin);
        }
        
        PrintMostDestinations(iberiaTree->right, mostDestinations);
    }   
}