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
                case 2  :
                    Small_Letters(word);
                    tempData.city =     (char*) malloc(strlen(word)*sizeof(char) + 1);
                    strcpy(tempData.city, word);
                break;
                
                case 7  :
                    tempData.iso3 =     (char*) malloc(strlen(word)*sizeof(char) + 1);
                    strcpy(tempData.iso3, word);
                break;

                case 10 :   tempData.population = atoi(word);   break;

                case 11 :   tempData.id = atoi(word);           break;
            }
            lineIndex++;
            column++;
        }        

        if (strcmp(tempData.iso3, "PRT") == 0 || strcmp(tempData.iso3, "ESP") == 0)
        {
            /* printf("\nCity: %s", tempData.city);
            printf("\nIso3: %s", tempData.iso3);
            printf("\nPop: %d", tempData.population);
            printf("\nId: %d", tempData.id);
            puts(""); */

            tempTree = WorldCities_to_Tree(tempTree, tempData);
            ++*ptrTotalCities;
        }
        
    }

    fclose(file);
    
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
        Print_World_Cities_Tree(tree->left);

        printf("\nID: %d\tCity: %s\tISO3: %s\tPopulation: %d", tree->data.id, tree->data.city, tree->data.iso3, tree->data.population);
        
        Print_World_Cities_Tree(tree->right);
    }    
}

/*! Função para colocar as palavras em minusculas */
void Small_Letters(char *word)
{
    char aux;
    int i = 0;

    while (word[i] != '\0')
    {
        aux = word[i];
        if (aux >= 'A' && aux <= 'Z')
        {
            word[i] = word[i] + 32;
        }
        i++;
    }
}

