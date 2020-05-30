#include "library.h"

Tree_WorldCities *Read_World_Cities_File(Tree_WorldCities *tempTree, int *ptrTotalCities)
{
    FILE *file;
    Data_WorldCities tempData;

/* 
    int intTrash;
    char charTrash[100];
    char auxCity[100];
    char auxIso3[100];
 */


    char line[256];
    char word[100];

    int lineIndex;
    int wordIndex;
    int column;
    int total = 0;


    file = fopen(FILE_WORLD_CITIES, "r");

    rewind(file);

    while (fgets(line, sizeof(line), file))
    {
        lineIndex = 0;
        column = 1;

        while (line[lineIndex] != 44 && line[lineIndex] != 13 && line[lineIndex] != 10)
        {
            wordIndex = 0;
            
            while (line[lineIndex] != 44 && line[lineIndex] != 13 && line[lineIndex] != 10)
            {
                word[wordIndex] = line[lineIndex];
                lineIndex++;
                wordIndex++;
            }
            
            word[wordIndex] = 0;

            switch (column)
            {
                case 2  :   strcpy(tempData.city, word);        break;
                
                case 7  :   strcpy(tempData.iso3, word);        break;

                case 10 :   tempData.population = atoi(word);   break;

                case 11 :   tempData.id = atoi(word);           break;
            }
            lineIndex++;
            column++;
        }

        total++;
        WorldCities_to_Tree(tempTree, tempData);
        
    }
    

/* 
    while (fscanf(file, "%s,%s,%d,%d,%s,%s,%s,%s,%s,%d,%d", charTrash, auxCity, &intTrash, &intTrash, charTrash, charTrash, auxIso3, charTrash, charTrash, &tempData.population, &tempData.id) != EOF)
    {
        if (strcmp(auxIso3, "PTR") == 0 || strcmp(auxIso3, "ESP") == 0)
        {
            ++total;

            tempData.city = (char*) malloc(strlen(auxCity) * sizeof(char) + 1);
            tempData.iso3 = (char*) malloc(strlen(auxIso3) * sizeof(char) + 1);

            strcpy(tempData.city, auxCity);
            strcpy(tempData.iso3, auxIso3);

            tempTree = WorldCities_to_Tree(tempTree, tempData);
        }
    }
 */
    fclose(file);

    *ptrTotalCities = total;
    
    return tempTree;
}

/*!Insere o ficheiro na Arvore */
Tree_WorldCities *WorldCities_to_Tree(Tree_WorldCities *tree, Data_WorldCities tempData)
{
    if (tree)
    {
        if (tempData.id < tree->data.id)
            tree->left = WorldCities_to_Tree(tree->left, tempData);

        if (tempData.id > tree->data.id)
            tree->right = WorldCities_to_Tree(tree->right, tempData);
    }
    else
    {
        tree = (Tree_WorldCities*) malloc(sizeof(Tree_WorldCities));

        tree->data.city =   (char*) malloc(strlen(tempData.city)   *   sizeof(char) + 1);
        tree->data.iso3 =   (char*) malloc(strlen(tempData.iso3)   *   sizeof(char) + 1);

        strcpy(tree->data.city, tempData.city);
        strcpy(tree->data.iso3, tempData.iso3);
        
        tree->data.id           =   tempData.id;
        tree->data.population   =   tempData.population;

        tree->left = tree->right       =   NULL;
    }
    return tree;
}

/*! Imprime a Arvore*/
void Print_World_Cities_Tree(Tree_WorldCities *tree)
{
    if (tree)
    {
        Print_World_Cities_Tree(tree->right);

        printf("\nID: %d\tCity: %s\tISO3: %s\tPopulation: %d", tree->data.id, tree->data.city, tree->data.iso3, tree->data.population);
        
        Print_World_Cities_Tree(tree->left);
    }
}