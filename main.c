#include "library.h"

int main()
{
    Tree_WorldCities *worldCities_tree = NULL;

    int total = 0;
    int *ptrTotal = &total;

    char searchCity[100];
    int opMenu;
    int *ptrTotal = &total; 

    worldCities_tree = Read_World_Cities_File(worldCities_tree, ptrTotal);

    Print_World_Cities_Tree(worldCities_tree);
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
            break;
        
        default:
            printf("Opcao Invalida!");
            break;
        }
    } while (opMenu =! 0);

    printf("\n\nTotal cidades: %d\n\n", total);

    
    printf("Indique a Cidade (em Ingles): ");
    scanf("%s", searchCity);

    Small_Letters(searchCity);





    return 0;
}

