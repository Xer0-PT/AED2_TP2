/* #include "library.h"


void Search_50k(Tree_World_Cities *worldTree, unsigned long int id)
{
    if (worldTree)
    {
        if (worldTree->data.id == id)
        {
            if (worldTree->data.population > 50000)
            {
                printf("\tID: %lu\tPopulation: %lu", id, worldTree->data.population);
            }
        }

        Search_Population(worldTree->left, id);
        Search_Population(worldTree->right, id);
    }
}

void Search_30k(Tree_World_Cities *worldTree, unsigned long int id)
{
    if (worldTree)
    {
        if (worldTree->data.id == id)
        {
            if (worldTree->data.population < 30000)
            {
                printf("\tID: %lu\tPopulation: %lu", id, worldTree->data.population);
            }
        }

        Search_Population(worldTree->left, id);
        Search_Population(worldTree->right, id);
    }
} */