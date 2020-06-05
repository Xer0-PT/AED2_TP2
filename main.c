#include "library.h"

int main()
{
    Tree_World_Cities *worldCities_tree = NULL;
    Tree_Iberia_Cities *iberiaCities_tree = NULL;

    char searchCity[100];

    int opMenu;
    int cityCount = 0;
    int *ptrCityCount = &cityCount;
    
    unsigned long int searchID;
    int numberOfDestinations = -1;
    int *ptrNumberOfDestinations = &numberOfDestinations;

    int countMostDestinations = -1;
    int *ptrCountMostDestinations = &countMostDestinations;

    worldCities_tree = Read_World_Cities_File(worldCities_tree);

    iberiaCities_tree = Read_Iberia_Cities_File(iberiaCities_tree, worldCities_tree);

    CalculateDestinations(iberiaCities_tree);
    
     do
    {
        puts("");
        puts("");
        puts("1 - Verificar cidades iguais");
        puts("2 - Verificar cidades para onde posso viajar");
        puts("3 - Cidades com mais de 50 000 habitantes e destinos com menos de 30000");
        puts("4 - Cidades com maior numero de destinos");
        puts("0 - Exit");
        puts("");
        printf("Opcao: ");
        scanf("%d", &opMenu);
        switch (opMenu)
        {
            case 1:
                printf("Indique a Cidade: ");
                scanf("%s", searchCity);

                Small_Letters(searchCity);

                SearchCity(worldCities_tree, searchCity, ptrCityCount);

                printf("\nExiste um total de %d cidades com esse nome.", cityCount);

                cityCount = 0;
            break;

            case 2:
                printf("Indique o ID da cidade a procurar: ");
                scanf("%lu", &searchID);

                CheckIfIDExists(iberiaCities_tree, searchID, ptrNumberOfDestinations);

                if (numberOfDestinations == -1)
                {
                    puts("ID nao existe!!");
                }
                else
                {
                    printf("\n\nEsta cidade tem %d destinos disponíveis.", numberOfDestinations);
                }
                
            break;

            case 3:
                Get_50k(iberiaCities_tree);
            break;

            case 4:
                MostDestinations(iberiaCities_tree, ptrCountMostDestinations);
                
                printf("\n\nMaior numero de destinos: %d\n\n", countMostDestinations);

                PrintMostDestinations(iberiaCities_tree, countMostDestinations);
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