#include "library.h"

void Search_Origin(Tree_Iberia_Cities *tree, Tree_World_Cities *worldTree, data line3Data)
{
    if (tree)
    {
            line3Data = Search_50k(worldTree, tree->idOrigin, line3Data);
            
            if (line3Data.population)
            {
                printf("\n\nID: %lu\tPopulation: %lu", line3Data.id, line3Data.population);
                /* line3Data.population = 0;
                line3Data.id = 0; */
            }
            Search_Destination(tree->treeDestination, worldTree, line3Data);

        Search_Origin(tree->left, worldTree, line3Data);
        Search_Origin(tree->right, worldTree, line3Data);
    }    
}

void Search_Destination(Tree_Destination *tree, Tree_World_Cities *worldTree, data line3Data)
{
    if (tree)
    {
        Search_Destination(tree->left, worldTree, line3Data);

           line3Data = Search_30k(worldTree, tree->idDestination, line3Data);
           
           if (line3Data.population)
           {
                printf("\n\t\tID: %lu\tPopulation: %lu", line3Data.id, line3Data.population);
                line3Data.id = 0;
                line3Data.population = 0;
           }
        
        Search_Destination(tree->right, worldTree, line3Data);
    }    
}

data Search_50k(Tree_World_Cities *worldTree, unsigned long int id, data line3Data)
{
    if (worldTree)
    {
        if (worldTree->data.id == id)
        {
            if (worldTree->data.population > 50000)
            {
                line3Data.id = id;
                line3Data.population = worldTree->data.population;
                return line3Data;
            }
        }

        Search_50k(worldTree->left, id, line3Data);
        Search_50k(worldTree->right, id, line3Data);
    }
}

data Search_30k(Tree_World_Cities *worldTree, unsigned long int id, data line3Data)
{
    if (worldTree)
    {
        if (worldTree->data.id == id)
        {
            if (worldTree->data.population < 30000)
            {
                line3Data.id = id;
                line3Data.population = worldTree->data.population;
                return line3Data;
            }
        }

        Search_30k(worldTree->left, id, line3Data);
        Search_30k(worldTree->right, id, line3Data);
    }
}


/* void SearchOrigin(Tree_World_Cities *worldTree, Tree_Iberia_Cities *iberiaTree)
{
    if (iberiaTree)
    {
        SearchOrigin(worldTree, iberiaTree->left);

            Search_50k(worldTree, iberiaTree->idOrigin, iberiaTree);
        
        SearchOrigin(worldTree, iberiaTree->right);
    }    
}

void SearchDestinations(Tree_Destination *tree, Tree_World_Cities *worldTree, unsigned long int originID, unsigned long int originPopulation, char *city)
{
    if (tree)
    {
        SearchDestinations(tree->left, worldTree, originID, originPopulation, city);

            Search_30k(tree->idDestination, worldTree, originID, originPopulation, city);
        
        SearchDestinations(tree->right, worldTree, originID, originPopulation, city);
    }    
}

void Search_50k(Tree_World_Cities *worldTree, unsigned long int idIberia, Tree_Iberia_Cities *iberiaTree)
{
    if (worldTree)
    {
        Search_50k(worldTree->left, idIberia, iberiaTree);

        if (worldTree->data.id == idIberia)
            if (worldTree->data.population > 50000)
                SearchDestinations(iberiaTree->treeDestination, worldTree, worldTree->data.id, worldTree->data.population, worldTree->data.city);
            
        Search_50k(worldTree->right, idIberia, iberiaTree);
    }
}

void Search_30k(unsigned long int idDestino, Tree_World_Cities *worldTree, unsigned long int originID, unsigned long int originPopulation, char *city)
{
    if (worldTree)
    {
        Search_30k(idDestino, worldTree->left, originID, originPopulation, city);

        if (worldTree->data.id == idDestino)
        {
            if (worldTree->data.population < 30000)
            {
                if (worldTree->flag == 0)
                {
                    printf("\n\nPartida:\n\tID: %lu\n\tName: %s\n\tPopulation: %lu", originID, city, originPopulation);
                    worldTree->flag++;
                }

                if (worldTree->flag2 == 0)
                {
                    printf("\n\n\t\tDestino(s):\n");
                    worldTree->flag2++;
                }
                

                printf("\t\t\tID: %lu\n\t\t\tName: %s\n\t\t\tPopulation: %lu\n\n", worldTree->data.id, worldTree->data.city, worldTree->data.population);
            }
        }
        
        Search_30k(idDestino, worldTree->right, originID, originPopulation, city);
    }
} */

/* void Search_50k(Tree_World_Cities *worldTree, Tree_Iberia_Cities *iberiaTree)
{
    if (worldTree)
    {
        if (worldTree->data.population > 50000)
        {
            SearchOrigin(worldTree, iberiaTree, worldTree->data.id);
        }

        Search_50k(worldTree->left, iberiaTree);   
        Search_50k(worldTree->right, iberiaTree);
    }
}

void SearchOrigin(Tree_World_Cities *worldTree, Tree_Iberia_Cities *iberiaTree, unsigned long int id)
{
    if (iberiaTree)
    {
        if (iberiaTree->idOrigin == id)
        {
            SearchDestinations(iberiaTree->treeDestination, worldTree, worldTree->data.city, worldTree->data.population);
        }

        if (id < iberiaTree->idOrigin)
        {
            SearchOrigin(worldTree, iberiaTree->left, id);
        }
        else
        {
            SearchOrigin(worldTree, iberiaTree->right, id);
        }
    }
}

void SearchDestinations(Tree_Destination *destinationTree, Tree_World_Cities *worldTree, char *city, unsigned long int population)
{
    if (destinationTree)
    {
        SearchDestinations(destinationTree->left, worldTree, city, population);

        Search_30k(worldTree, destinationTree->idDestination, city, population, destinationTree);

        SearchDestinations(destinationTree->right, worldTree, city, population);
    }   
}

void Search_30k(Tree_World_Cities *worldTree, unsigned long int id, char *city, unsigned long int population, Tree_Destination *destinationTree)
{
        if (worldTree)
        {
            if (worldTree->data.id == id)
            {
            }

            Search_30k(worldTree->left, id, city, population, destinationTree);
            Search_30k(worldTree->right, id, city, population, destinationTree);
        }   
} */

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