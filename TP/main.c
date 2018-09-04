#include <stdio.h>
#include <stdlib.h>
#include "Operaciones.h"

float sumaValores(float, float);
float restaValores(float, float);
float multiplicarValores(float, float);
float divisionValores(float, float);
float factorValores(float, float);
float pedirNumero(void);


int main()
{
    int opcion=0;
    float operandoA=0;
    float operandoB=0;
    float suma;
    float resta;
    float multiplicacion;
    float division;

    do
        {
            printf("\n      *********************************************");
            printf("\n      ||                                         ||");
            printf("\n      ||             .:CALCULADORA:.             ||");
            printf("\n      ||                                         ||");
            printf("\n      *********************************************");
            printf("\n      ||           Elija una operacion:          ||");
            printf("\n      ||                                         ||");
            printf("\n      ||      1. Ingrese OperandoA: %2.f           ||",operandoA);
            printf("\n      ||                                         ||");
            printf("\n      ||      2. Ingrese OperandoB: %2.f           ||",operandoB);
            printf("\n      ||                                         ||");
            printf("\n      ||      3. Calcular todas las operaciones  ||");
            printf("\n      ||                                         ||");
            printf("\n      ||      4. Notificar resultados            ||");
            printf("\n      ||                                         ||");
            printf("\n      ||                                         ||");
            printf("\n      ||                                         ||");
            printf("\n      ||                                         ||");
            printf("\n      ||   5.Salir                               ||");
            printf("\n      *********************************************");
            printf("\n                                                    ");
            printf("\n|| Ingrese una opcion (1/5) ");
            scanf("%d", &opcion);

            switch(opcion)
            {
            case 1:
                system("cls");
                operandoA = pedirNumero();
                break;
            case 2:
                system("cls");
                operandoB = pedirNumero();
                break;
            case 3:
                system("cls");
                printf("Calculando...\n");
                system("pause");
                suma = sumaValores(operandoA,operandoB );
                resta = restaValores(operandoA , operandoB);
                multiplicacion = multiplicarValores(operandoA, operandoB);
                division = divisionValores(operandoA, operandoB);
                printf(" ----------------------------------------------\n");
                printf("Terminando de calcular...\n");
                printf(" ----------------------------------------------\n");
                break;
            case 4:
                system("cls");
                printf(" --------------------------------------------------- \n");
                printf("                Imprimiendo resultados:\n              ");
                printf("\n La suma de %2.f + %2.f es: %2.f\n" , operandoA , operandoB , suma);
                printf(" --------------------------------------\n");
                printf("\n La resta de %2.f - %2.f es: %2.f\n" , operandoA , operandoB , resta);
                printf(" --------------------------------------\n");
                printf("\n El producto de %2.f * %2.f es: %2.f\n" , operandoA , operandoB , multiplicacion);
                printf(" --------------------------------------\n");
                if(operandoB != 0)
                {
                    printf("\n La division de %2.f / %2.f es: %2.f\n" , operandoA , operandoB , division);
                    printf(" --------------------------------------\n");
                }
                else
                {
                    printf("\n No se puede dividir por 0\n");
                    printf(" --------------------------------------\n");
                }
                factorValores(operandoA,operandoB);
                printf(" --------------------------------------\n");
                break;
            case 5:

                opcion = 5;
                system("cls");
                printf(" ***************************************\n");
                printf("        Saliendo de la calculadora...   \n");
                printf(" ***************************************\n");
                break;

            default:
                system("cls");
                printf("\n Digite una opcion valida \n");

            }

            system("pause");
        }
        while (opcion!=5);
        {
          return 0;
        }

}
