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

}Destination_Tree;

typedef struct _World_Cities_Data
{
    unsigned long int id;
    unsigned long int population;

    char *city;
    char *iso3;
}Data_WorldCities;

typedef struct _Iberia_Cities_Data
{
    unsigned long int idOrigin;
    int countDestinations;

    Destination_Tree *treeDestination;

    struct _Iberia_Cities_Data *left, *right;

}Iberia_Cities;

typedef struct _World_Cities_Tree
{
    Data_WorldCities data;
    struct _World_Cities_Tree *left, *right;
}Tree_WorldCities;



/*! ------------ SIGNATURES ------------ */

/*! Main  */



/*! readFiles */
Tree_WorldCities *Read_World_Cities_File(Tree_WorldCities *tempTree);
Tree_WorldCities *WorldCities_to_Tree(Tree_WorldCities *tree, Data_WorldCities tempData);
void Print_World_Cities_Tree(Tree_WorldCities *tree);
void Small_Letters(char *word);

Iberia_Cities *Read_Iberia_Cities_File(Iberia_Cities *tempTree);
Iberia_Cities *IberiaCities_to_Tree(Iberia_Cities *tree, unsigned long int auxIdOrigin, unsigned long int auxIdDestination, float auxCost);
Destination_Tree *AddDestinations(Destination_Tree *tree, unsigned long int auxIdDestination, float auxCost);
void Print_Iberia_Cities_Tree(Iberia_Cities *tree);
void Print_Destinations_Tree(Destination_Tree *tree);

/*! csvFunctions */
void SearchCity(Tree_WorldCities *tree, char *word, int *ptrCityCount);

#endif