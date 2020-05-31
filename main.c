#include "library.h"

int main()
{
    Tree_WorldCities *worldCities_tree = NULL;
    Iberia_Cities *iberiaCities_tree = NULL;

    char searchCity[100];


    int opMenu;
    int cityCount = 0;
    int *ptrCityCount = &cityCount;

    worldCities_tree = Read_World_Cities_File(worldCities_tree);
    /* Print_World_Cities_Tree(worldCities_tree); */

    puts("1");

    iberiaCities_tree = Read_Iberia_Cities_File(iberiaCities_tree);
    Print_Iberia_Cities_Tree(iberiaCities_tree);

    
     do
    {
        puts("");
        puts("");
        puts("1 - Verificar cidades iguais");
        puts("2 - Verificar cidades para onde posso viajar");
        puts("3 - Listar todas as cidades com mais de 50 000 habitantes");
        puts("4 - Verificar caminho entre cidades");
        puts("0 - Exit");
        puts("");
        printf("Opcao: ");
        scanf("%d", &opMenu);
        switch (opMenu)
        {
            case 1:
                printf("Indique a Cidade (em Ingles): ");
                scanf("%s", searchCity);

                Small_Letters(searchCity);

                printf("\n%s", searchCity);

                SearchCity(worldCities_tree, searchCity, ptrCityCount);

                printf("\nExiste um total de %d cidades com esse nome.", cityCount);
            break;

            case 2:



            break;
            
            case 0:
                
            break;

            default:
                printf("Opcao Invalida!");
            break;

        }
    } while (opMenu != 0);






    return 0;
}

