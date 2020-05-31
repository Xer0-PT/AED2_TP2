#include "library.h"

Tree_WorldCities *Read_World_Cities_File(Tree_WorldCities *tempTree)
{
    FILE *file;
    Data_WorldCities tempData;

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

/*         if (strcmp(tempData.iso3, "PRT") == 0 || strcmp(tempData.iso3, "ESP") == 0)
        {
            printf("\nCity: %s", tempData.city);
            printf("\nIso3: %s", tempData.iso3);
            printf("\nPop: %d", tempData.population);
            printf("\nId: %d", tempData.id);
            puts("");

             tempTree = WorldCities_to_Tree(tempTree, tempData); 
        } */

        tempTree = WorldCities_to_Tree(tempTree, tempData);
        
    }

    fclose(file);
    
    return tempTree;
}

/*!Insere o ficheiro na Arvore */
Tree_WorldCities *WorldCities_to_Tree(Tree_WorldCities *tree, Data_WorldCities tempData)
{
    if (tree)
    {
        if(strcmp(tree->data.city, tempData.city) < 0)
            tree->left = WorldCities_to_Tree(tree->left, tempData);

        if(strcmp(tree->data.city, tempData.city) > 0)
            tree->right = WorldCities_to_Tree(tree->right, tempData);

        if (strcmp(tree->data.city, tempData.city) == 0)
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

Iberia_Cities *Read_Iberia_Cities_File(Iberia_Cities *tempTree)
{
    FILE *file;

    int auxIdOrigin;
    int auxIdDestination;
    float auxCost;


    char line[256];
    char word[100];

    int lineIndex;
    int wordIndex;
    int column;

    file = fopen(FILE_CIDADES_IBERIA, "r");

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
                case 1  :   auxIdOrigin = atoi(word);       break;

                case 3  :   auxIdDestination = atoi(word);  break;

                case 5  :   auxCost = atof(word);           break;
            }
            lineIndex++;
            column++;
        }        

        tempTree = IberiaCities_to_Tree(tempTree, auxIdOrigin, auxIdDestination, auxCost);   
    }

    fclose(file);
    
    return tempTree;
}

/*!Insere o ficheiro na Arvore */
Iberia_Cities *IberiaCities_to_Tree(Iberia_Cities *tree, int auxIdOrigin, int auxIdDestination, float auxCost)
{
    if (tree)
    {
        if(tree->idOrigin < auxIdOrigin)       
            IberiaCities_to_Tree(tree->left, auxIdOrigin, auxIdDestination, auxCost);
        
        if(tree->idOrigin > auxIdOrigin)       
            IberiaCities_to_Tree(tree->right, auxIdOrigin, auxIdDestination, auxCost);

        if(tree->idOrigin == auxIdOrigin)
            tree->treeDestination = AddDestinations(tree->treeDestination, auxIdDestination, auxCost);
    }
    else
    {
        tree = (Iberia_Cities*) malloc(sizeof(Iberia_Cities));

        tree->idOrigin = auxIdOrigin;
        tree->countDestinations++;
        tree->treeDestination.idDestination = auxIdDestination;
        tree->treeDestination.cost = auxCost;


        tree->treeDestination.left = tree->treeDestination.right = NULL;
        tree->left = tree->right       =   NULL;
    }
    return tree;
}

Destination_Tree *AddDestinations(Destination_Tree *tree, int auxIdDestination, float auxCost)
{
    if (tree)
    {
        if(tree->idDestination < auxIdDestination)       
            AddDestinations(tree->left, auxIdDestination, auxCost);
        
        if(tree->idDestination > auxIdDestination)      
            AddDestinations(tree->right, auxIdDestination, auxCost);

        if(tree->idDestination == auxIdDestination)
        {
            if (auxCost < tree->cost)
            {
                tree->cost = auxCost;
            }
        }
    }
    else
    {
        tree = (Destination_Tree*) malloc(sizeof(Iberia_Cities));

        tree->idOrigin = auxIdOrigin;
        tree->countDestinations++;
        tree->treeDestination.idDestination = auxIdDestination;
        tree->treeDestination.cost = auxCost;


        tree->treeDestination.left = tree->treeDestination.right = NULL;
        tree->left = tree->right       =   NULL;
    }
    return tree;
}