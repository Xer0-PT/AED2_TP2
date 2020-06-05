#include "library.h"

/*! Função para ler o ficheiro WorldCities.csv  */
/*! Decompondo cada linha em 11 colunas, ignorando a informação que não seja relevante */
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

    fgets(line, sizeof(line), file);

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
                /*! Decomposição da linha em coluna */
                case 2  :
                    Small_Letters(word);
                    tempData.city =     (char*) malloc(strlen(word)*sizeof(char) + 1);
                    strcpy(tempData.city, word);
                break;

                case 7  :
                    tempData.iso3 =     (char*) malloc(strlen(word)*sizeof(char) + 1);
                    strcpy(tempData.iso3, word);
                break;

                case 10 :   tempData.population = atof(word);   break;

                case 11 :   tempData.id = atol(word);     break;
            }
            lineIndex++;
            column++;
        }        
        /*! Estamos a fazer a leitura do ficheiro cidadesPT.txt */
        if (strcmp(tempData.iso3, "PRT") == 0)
            tempTree = WorldCities_to_Tree(tempTree, tempData);
    }

    fclose(file);
    
    return tempTree;
}

/*! Insere os dados lidos na função anterior numa árvore de procura binária */
Tree_World_Cities *WorldCities_to_Tree(Tree_World_Cities *tree, Data_WorldCities tempData)
{
    if (tree)
    {
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

        tree->left = tree->right       =   NULL;
    }
    return tree;
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
            word[i] = word[i] + 32;

        i++;
    }
}

/*! Função para ler o ficheiro CidadesPT.txt  */
/*! Decompondo cada linha em 5 colunas, ignorando a informação que não seja relevante */
Tree_Iberia_Cities *Read_Iberia_Cities_File(Tree_Iberia_Cities *tempTree, Tree_World_Cities *worldTree)
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
                /*! Decomposição da linha em coluna */
                case 1  :   auxIdOrigin = atol(word);      break;

                case 3  :   auxIdDestination = atol(word); break;

                case 5  :   auxCost = atof(word);           break;
            }

            lineIndex++;
            column++;
        }        
        tempTree = IberiaCities_to_Tree(tempTree, auxIdOrigin, auxIdDestination, auxCost, worldTree);   
    }

    fclose(file);
    
    return tempTree;
}

/*! Insere os dados lidos na função anterior numa árvore de procura binária */
Tree_Iberia_Cities *IberiaCities_to_Tree(Tree_Iberia_Cities *tree, unsigned long int auxIdOrigin, unsigned long int auxIdDestination, float auxCost, Tree_World_Cities *worldTree)
{
    if (tree)
    {
        if(auxIdOrigin < tree->idOrigin)       
            tree->left = IberiaCities_to_Tree(tree->left, auxIdOrigin, auxIdDestination, auxCost, worldTree);
        
        if(auxIdOrigin > tree->idOrigin)       
            tree->right = IberiaCities_to_Tree(tree->right, auxIdOrigin, auxIdDestination, auxCost, worldTree);

        /*! Se o ID da cidade de origem for igual, então estamos perante outro destino, ou destino com menor/maior custo */
        if(auxIdOrigin == tree->idOrigin)
            /*! Chama a função para adicionar um destino à árvore de destinos que fica guardada em cada nodo da árvore de origem */
            tree->treeDestination = AddDestinations(tree->treeDestination, auxIdDestination, auxCost, worldTree);
    }
    else
    {
        tree = (Tree_Iberia_Cities*) malloc(sizeof(Tree_Iberia_Cities));

        tree->idOrigin = auxIdOrigin;
        tree->countDestinations = 0;

        /*! Chama a função que obtém a população desta cidade, ficando este valor já registado nesta árvore */
        /*! Facilitando a procura de cidades com mais de 50 000 habitantes */
        GetPopulation_Origin(worldTree, tree);

        tree->left = tree->right = NULL;

        /*! Chama a função para adicionar um destino à árvore de destinos que fica guardada em cada nodo da árvore de origem */
        tree->treeDestination = AddDestinations(tree->treeDestination, auxIdDestination, auxCost, worldTree);
    }
    return tree;
}

/*! Função para adicionar destinos à árvore de procura binária */
Tree_Destination *AddDestinations(Tree_Destination *tree, unsigned long int auxIdDestination, float auxCost, Tree_World_Cities *worldTree)
{
    if (tree)
    {
        if(auxIdDestination < tree->idDestination)       
            tree->left = AddDestinations(tree->left, auxIdDestination, auxCost, worldTree);

        if(auxIdDestination > tree->idDestination)      
            tree->right = AddDestinations(tree->right, auxIdDestination, auxCost, worldTree);

        /*! Se o destino for igual, então verificamos se o custo é menor */
        /*! Se for menor, então fica só guardado esse custo */
        if(auxIdDestination == tree->idDestination)
        {
            if (auxCost < tree->cost)
                tree->cost = auxCost;
        }
    }
    else
    {
        tree = (Tree_Destination*) malloc(sizeof(Tree_Destination));
        
        tree->idDestination = auxIdDestination;
        tree->cost = auxCost;

        /*! Chama a função que obtém a população desta cidade, ficando este valor já registado nesta árvore */
        /*! Facilitando a procura de cidades com menos de 30 000 habitantes */
        GetPopulation_Destination(worldTree, tree);

        tree->left = tree->right = NULL;
    }
    return tree;
}

/*! Procedimento para percorrer a árvore WorldCities à procura do ID da cidade origem para ficar já guardado o número de habitantes */
void GetPopulation_Origin(Tree_World_Cities *worldTree, Tree_Iberia_Cities *iberiaTree)
{
    if (worldTree)
    {
        if (worldTree->data.id == iberiaTree->idOrigin)
            iberiaTree->population = worldTree->data.population;

        if (iberiaTree->idOrigin < worldTree->data.id)
            GetPopulation_Origin(worldTree->left, iberiaTree);

        if (iberiaTree->idOrigin > worldTree->data.id)
            GetPopulation_Origin(worldTree->right, iberiaTree);
    }
}

/*! Procedimento para percorrer a árvore WorldCities à procura do ID da cidade destino para ficar já guardado o número de habitantes */
void  GetPopulation_Destination(Tree_World_Cities *worldTree, Tree_Destination *destinationTree)
{
    if (worldTree)
    {
        if (worldTree->data.id == destinationTree->idDestination)
            destinationTree->population = worldTree->data.population;

        if (destinationTree->idDestination < worldTree->data.id)
            GetPopulation_Destination(worldTree->left, destinationTree);

        if (destinationTree->idDestination > worldTree->data.id)
            GetPopulation_Destination(worldTree->right, destinationTree);
    }
}

/*! Procedimento para chamar a função de calcular o número de destinos para cada cidade origem */
void CalculateDestinations(Tree_Iberia_Cities *tree)
{
    if (tree)
    {
        CalculateDestinations(tree->left);

        tree->countDestinations = NumberOfDestinations(tree->treeDestination);

        CalculateDestinations(tree->right);
    }   
}

/*! Função que calcula a profundidade da ávore de destinos e retorna esse valor */
/*! Que significa a quantidade de destinos que essa cidade tem */
int NumberOfDestinations(Tree_Destination *tree)
{   
    if (tree == NULL)  
        return 0; 
    
    else     
        return(NumberOfDestinations(tree->left) + 1 + NumberOfDestinations(tree->right));   
}