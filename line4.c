#include "library.h"

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