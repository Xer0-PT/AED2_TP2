#include "library.h"

void Search_50k(Tree_World_Cities *worldTree, Tree_Iberia_Cities *iberiaTree)
{
    if (worldTree)
    {
        Search_50k(worldTree->left, iberiaTree);

        if (worldTree->data.population > 50000)
        {
            SearchOrigin(worldTree, iberiaTree, worldTree->data.id);
        }
        
        Search_50k(worldTree->right, iberiaTree);
    }
}

void SearchOrigin(Tree_World_Cities *worldTree, Tree_Iberia_Cities *iberiaTree, unsigned long int id)
{
    if (iberiaTree)
    {
        SearchOrigin(worldTree, iberiaTree->left, id);

        if (iberiaTree->idOrigin == id)
        {
            printf("\nCidade: %s\tPopulacao: %lu", worldTree->data.city, worldTree->data.population);
            SearchDestinations(iberiaTree->treeDestination, worldTree);
        }

        SearchOrigin(worldTree, iberiaTree->right, id);
    }
}

void SearchDestinations(Tree_Destination *destinationTree, Tree_World_Cities *worldTree)
{
    if (destinationTree)
    {
        SearchDestinations(destinationTree->left, worldTree);

        Search_30k(worldTree, destinationTree->idDestination);

        SearchDestinations(destinationTree->right, worldTree);
    }   
}

void Search_30k(Tree_World_Cities *worldTree, unsigned long int id)
{
    if (worldTree)
    {
        Search_30k(worldTree->left, id);

        if (worldTree->data.id == id)
        {
            if (worldTree->data.population < 30000)
            {
                printf("\n\t\tCidade: %s\tPopulacao: %lu", worldTree->data.city, worldTree->data.population);
            }
        }

        Search_30k(worldTree->right, id);
    }   
}

/* void Search_30k(Tree_World_Cities *worldTree, Tree_Destination *destinationTree)
{
    if (worldTree)
    {
        Search_30k(worldTree->left, destinationTree);

            if (destinationTree)
            {
                Search_30k(worldTree, destinationTree->left);

                if (destinationTree->idDestination == worldTree->data.id)
                {
                    if (worldTree->data.population < 30000)
                    {
                        printf("\n\t\tCidade: %s\tPopulacao: %lu", worldTree->data.city, worldTree->data.population);
                    }
                }

                Search_30k(worldTree, destinationTree->right);
            }
        
        Search_30k(worldTree->right, destinationTree);
    }


    if (destinationTree)
    {
        Search30k(worldTree, destinationTree->left);

        if (worldTree)
        {
            Search30k(worldTree->left, destinationTree);

            if (destinationTree->idDestination == worldTree->data.id)
            {
                if (worldTree->data.population < 30000)
                {
                    printf("\n\t\tCidade: %s\tPopulacao: %lu", worldTree->data.city, worldTree->data.population);
                }
            }
            
            Search30k(worldTree->right, destinationTree);
        }
        
        Search30k(worldTree, destinationTree->right);
    }
} */