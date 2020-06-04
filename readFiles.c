#include "library.h"

Tree_World_Cities *Read_World_Cities_File(Tree_World_Cities *tempTree)
{
    FILE *file;
    Data_WorldCities tempData;

    char line[512];
    char word[256];

    int lineIndex;
    int wordIndex;
    int column;

    file = fopen(FILE_WORLD_CITIES, "r");

    /* rewind(file); */

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

                case 10 :   tempData.population = atol(word);   break;

                case 11 :   tempData.id = atol(word);           break;
            }
            lineIndex++;
            column++;
        }        
        /* if (strcmp(tempData.iso3, "PRT") == 0 || strcmp(tempData.iso3, "ESP") == 0) */
        if (strcmp(tempData.iso3, "PRT") == 0)
        {
            tempTree = WorldCities_to_Tree(tempTree, tempData); 
        }

        /* tempTree = WorldCities_to_Tree(tempTree, tempData); */
    }

    fclose(file);
    
    return tempTree;
}

/*!Insere o ficheiro na Arvore */
Tree_World_Cities *WorldCities_to_Tree(Tree_World_Cities *tree, Data_WorldCities tempData)
{
    if (tree)
    {
        /* if(strcmp(tree->data.city, tempData.city) < 0)
            tree->left = WorldCities_to_Tree(tree->left, tempData);

        if(strcmp(tree->data.city, tempData.city) > 0)
            tree->right = WorldCities_to_Tree(tree->right, tempData);

        if (strcmp(tree->data.city, tempData.city) == 0)
            tree->right = WorldCities_to_Tree(tree->right, tempData); */   

        if(tempData.id < tree->data.id)
            tree->left = WorldCities_to_Tree(tree->left, tempData);

        if(tempData.id > tree->data.id)
            tree->right = WorldCities_to_Tree(tree->right, tempData);
    }
    else
    {
        tree = (Tree_World_Cities*) malloc(sizeof(Tree_World_Cities));

        tree->data.city =   (char*) malloc(strlen(tempData.city)   *   sizeof(char) + 1);
        tree->data.iso3 =   (char*) malloc(strlen(tempData.iso3)   *   sizeof(char) + 1);

        strcpy(tree->data.city, tempData.city);
        strcpy(tree->data.iso3, tempData.iso3);
        
        tree->data.id           =   tempData.id;
        tree->data.population   =   tempData.population;

        tree->flag = 0;
        tree->flag2 = 0;

        tree->left = tree->right       =   NULL;
    }
    return tree;
}

/*! Imprime a Arvore*/
void Print_World_Cities_Tree(Tree_World_Cities *tree)
{
    if (tree)
    {
        Print_World_Cities_Tree(tree->left);

        printf("\nID: %lu\tCity: %s\tISO3: %s\tPopulation: %lu", tree->data.id, tree->data.city, tree->data.iso3, tree->data.population);
        
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

Tree_Iberia_Cities *Read_Iberia_Cities_File(Tree_Iberia_Cities *tempTree)
{
    FILE *file;

    unsigned long int auxIdOrigin;
    unsigned long int auxIdDestination;
    float auxCost;


    char line[512];
    char word[256];

    int lineIndex;
    int wordIndex;
    int column;

    file = fopen(FILE_CIDADES_PT, "r");
    /* file = fopen(FILE_CIDADES_IBERIA, "r"); */

    /* rewind(file); */

    while (fgets(line, sizeof(line), file))
    {
        lineIndex = 0;
        column = 1;

        /* 44 - , | 13 - CR | 10 - New Line */
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
                case 1  :   auxIdOrigin = atol(word);      break;

                case 3  :   auxIdDestination = atol(word); break;

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
Tree_Iberia_Cities *IberiaCities_to_Tree(Tree_Iberia_Cities *tree, unsigned long int auxIdOrigin, unsigned long int auxIdDestination, float auxCost)
{
    if (tree)
    {
        if(auxIdOrigin < tree->idOrigin)       
            tree->left = IberiaCities_to_Tree(tree->left, auxIdOrigin, auxIdDestination, auxCost);
        
        if(auxIdOrigin > tree->idOrigin)       
            tree->right = IberiaCities_to_Tree(tree->right, auxIdOrigin, auxIdDestination, auxCost);

        if(auxIdOrigin == tree->idOrigin)
        {
            tree->treeDestination = AddDestinations(tree->treeDestination, auxIdDestination, auxCost);
        }
    }
    else
    {
        tree = (Tree_Iberia_Cities*) malloc(sizeof(Tree_Iberia_Cities));

        tree->idOrigin = auxIdOrigin;
        tree->countDestinations = 0;

        tree->left = tree->right = NULL;

        tree->treeDestination = AddDestinations(tree->treeDestination, auxIdDestination, auxCost);
    }
    return tree;
}

Tree_Destination *AddDestinations(Tree_Destination *tree, unsigned long int auxIdDestination, float auxCost)
{
    if (tree)
    {
        if(auxIdDestination < tree->idDestination)       
            tree->left = AddDestinations(tree->left, auxIdDestination, auxCost);

        if(auxIdDestination > tree->idDestination)      
            tree->right = AddDestinations(tree->right, auxIdDestination, auxCost);

        if(auxIdDestination == tree->idDestination)
        {
            if (auxCost < tree->cost)
            {
                tree->cost = auxCost;
            }
        }
    }
    else
    {
        tree = (Tree_Destination*) malloc(sizeof(Tree_Destination));
        
        tree->idDestination = auxIdDestination;
        tree->cost = auxCost;

        tree->left = tree->right = NULL;
    }
    return tree;
}

/* void Print_Iberia_Cities_Tree(Tree_Iberia_Cities *tree, Tree_World_Cities *worldTree)
{
    if (tree)
    {
        Print_Iberia_Cities_Tree(tree->left, worldTree);

        printf("\n\nID: %lu\tDestinos: %d", tree->idOrigin, tree->countDestinations);
        Search_Population(worldTree, tree->idOrigin);
        puts("");

        Print_Destinations_Tree(tree->treeDestination, worldTree);
        Print_Iberia_Cities_Tree(tree->right, worldTree);
    }    
}

void Print_Destinations_Tree(Tree_Destination *tree, Tree_World_Cities *worldTree)
{
    if (tree)
    {
        printf("\n\t\tID: %lu\tCusto: %f", tree->idDestination, tree->cost);
        Search_Population(worldTree, tree->idDestination);

        Print_Destinations_Tree(tree->left, worldTree);
        Print_Destinations_Tree(tree->right, worldTree);
    }    
} */

void CalculateDestinations(Tree_Iberia_Cities *tree)
{
    if (tree)
    {
        CalculateDestinations(tree->left);

        tree->countDestinations = NumberOfDestinations(tree->treeDestination);

        CalculateDestinations(tree->right);
    }   
}

int NumberOfDestinations(Tree_Destination *tree)
{   
    if (tree == NULL)  
        return 0; 
    
    else     
        return(NumberOfDestinations(tree->left) + 1 + NumberOfDestinations(tree->right));   
} 


void Search_Population(Tree_World_Cities *worldTree, unsigned long int id)
{
    if (worldTree)
    {
        if (worldTree->data.id == id)
        {
            printf("\tPopulation: %lu", worldTree->data.population);
        }

        Search_Population(worldTree->left, id);
        Search_Population(worldTree->right, id);
    }
}