#include "library.h"

int main()
{
    Tree_WorldCities *worldCities_tree = NULL;

    int total = 0;
    int *ptrTotal = &total;

    char searchCity[100];

    worldCities_tree = Read_World_Cities_File(worldCities_tree, ptrTotal);

    Print_World_Cities_Tree(worldCities_tree);

    printf("\n\nTotal cidades: %d\n\n", total);

    
    printf("Indique a Cidade (em Ingles): ");
    scanf("%s", searchCity);

    Small_Letters(searchCity);
    




    return 0;
}

