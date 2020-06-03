#include "library.h"

void Search_50k(Tree_World_Cities *worldTree, Tree_Iberia_Cities *iberiaTree)
{
    if (worldTree)
    {
        if (worldTree->data.population > 50000)
        {
            SearchOrigin(worldTree, iberiaTree, worldTree->data.id);
        }

        Search_50k(worldTree->left, iberiaTree);   
        Search_50k(worldTree->right, iberiaTree);
    }
}

void SearchOrigin(Tree_World_Cities *worldTree, Tree_Iberia_Cities *iberiaTree, unsigned long int id)
{
    if (iberiaTree)
    {
        if (iberiaTree->idOrigin == id)
        {
            SearchDestinations(iberiaTree->treeDestination, worldTree, worldTree->data.city, worldTree->data.population);
        }

        if (id < iberiaTree->idOrigin)
        {
            SearchOrigin(worldTree, iberiaTree->left, id);
        }
        else
        {
            SearchOrigin(worldTree, iberiaTree->right, id);
        }
    }
}

Tree_Line_3 *AddOrigem(Tree_Line_3 *line3_tree, Tree_World_Cities *worldTree, Tree_Destination *destinationTree)
{
    if (line3_tree)
    {
        if(id < line3_tree->idOrigin)
            line3_tree->left = WorldCities_to_Tree(tree->left, tempData);

        if(id > line3_tree->idOrigin)
            line3_tree->right = WorldCities_to_Tree(tree->right, tempData);
    }
    else
    {
        line3_tree->treeDestination = (Tree_Destination*) malloc(sizeof(Tree_Destination));

        line3_tree->treeDestination->idDestination = id;


        tree->left = tree->right       =   NULL;
    }
    return tree;
}