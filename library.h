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

/*! Data Structures */

typedef struct _Destination_Tree
{
    int idDestination;
    float cost;
    struct _Destination_Tree *left, *right;

}Destination_Tree;

typedef struct _World_Cities_Data
{
    int id;
    int population;

    char *city;
    char *iso3;
}Data_WorldCities;

typedef struct _Iberia_Cities_Data
{
    int idOrigin;
    int countDestinations;

    Destination_Tree treeDestination;

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

/*! csvFunctions */
void SearchCity(Tree_WorldCities *tree, char *word, int *ptrCityCount);

#endif