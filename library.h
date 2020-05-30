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

typedef struct _World_Cities_Data
{
    int id;
    int population;

    char *city;
    char *iso3;
}Data_WorldCities;


typedef struct _World_Cities_Tree
{
    Data_WorldCities data;
    struct _World_Cities_Tree *left, *right;
}Tree_WorldCities;


/*! ------------ SIGNATURES ------------ */

/*! Main  */



/*! readFiles */
Tree_WorldCities *Read_World_Cities_File(Tree_WorldCities *tempTree, int *ptrTotalCities);
Tree_WorldCities *WorldCities_to_Tree(Tree_WorldCities *tree, Data_WorldCities tempData);
void Print_World_Cities_Tree(Tree_WorldCities *tree);
void Small_Letters(char *word);

#endif