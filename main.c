#include "library.h"

int main()
{
    Tree_WorldCities *worldCities_tree = NULL;

    int total = 0;
    int *ptrTotal = &total; 

    worldCities_tree = Read_World_Cities_File(worldCities_tree, ptrTotal);

    Print_World_Cities_Tree(worldCities_tree);





    return 0;
}
