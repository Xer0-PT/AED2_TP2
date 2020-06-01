#ifndef LIBRARY_H_
#define LIBRARY_H_

/*! Include Libraries */
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>

/*! File Constant */

#define FILE_WORLD_CITIES "../CITIES/BIG/worldcities.csv"
#define FILE_CIDADES_IBERIA "../CITIES/BIG/cidadesiberia.txt"

#define FILE_CIDADES_PT "../CITIES/small/cidadesPT.txt"

/*! Data Structures */

typedef struct _Destination_Tree
{
    unsigned long int idDestination;
    float cost;
    struct _Destination_Tree *left, *right;

}Tree_Destination;

typedef struct _World_Cities_Data
{
    unsigned long int id;
    unsigned long int population;

    char *city;
    char *iso3;
}Data_WorldCities;

typedef struct _Iberia_Cities_Tree
{
    unsigned long int idOrigin;
    int countDestinations;

    Tree_Destination *treeDestination;

    struct _Iberia_Cities_Tree *left, *right;

}Tree_Iberia_Cities;

typedef struct _World_Cities_Tree
{
    Data_WorldCities data;
    struct _World_Cities_Tree *left, *right;
}Tree_World_Cities;



/*! ------------ SIGNATURES ------------ */

/*! Main  */



/*! readFiles */
Tree_World_Cities *Read_World_Cities_File(Tree_World_Cities *tempTree);
Tree_World_Cities *WorldCities_to_Tree(Tree_World_Cities *tree, Data_WorldCities tempData);
void Print_World_Cities_Tree(Tree_World_Cities *tree);
void Small_Letters(char *word);

Tree_Iberia_Cities *Read_Iberia_Cities_File(Tree_Iberia_Cities *tempTree);
Tree_Iberia_Cities *IberiaCities_to_Tree(Tree_Iberia_Cities *tree, unsigned long int auxIdOrigin, unsigned long int auxIdDestination, float auxCost);
Tree_Destination *AddDestinations(Tree_Destination *tree, unsigned long int auxIdDestination, float auxCost, int *ptrCount);
void Print_Iberia_Cities_Tree(Tree_Iberia_Cities *tree);
void Print_Destinations_Tree(Tree_Destination *tree);
void CalculateDestinations(Tree_Iberia_Cities *tree);
int NumberOfDestinations(Tree_Destination *tree);

/*! Line 1  */
void SearchCity(Tree_World_Cities *tree, char *word, int *ptrCityCount);

/*! Line 2 */
void CheckIfIDExists(Tree_Iberia_Cities *tree, unsigned long int id, int *ptrNumberOfDestinations);
void ShowDestinations(Tree_Destination *tree);

/*! Line 3 */
void Search_50k(Tree_World_Cities *worldTree, Tree_Iberia_Cities *iberiaTree);
void SearchOrigin(Tree_World_Cities *worldTree, Tree_Iberia_Cities *iberiaTree, unsigned long int id);
void SearchDestinations(Tree_Destination *destinationTree, Tree_World_Cities *worldTree);
void Search_30k(Tree_World_Cities *worldTree, unsigned long int id);

/*! Line 4 */
void MostDestinations(Tree_Iberia_Cities *iberiaTree, int *ptrMostDestinations);
void PrintMostDestinations(Tree_Iberia_Cities *iberiaTree, int mostDestinations);

#endif