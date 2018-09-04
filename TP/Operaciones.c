#include <stdio.h>
#include <stdlib.h>
#include "Operaciones.h"


float sumaValores(float numeroUno , float numeroDos)
{
    float suma;
    suma = numeroUno+numeroDos;
    return suma;

}

float restaValores(float numeroUno , float numeroDos)
{
    float resta;
    resta = numeroUno-numeroDos;
    return resta;
}

float multiplicarValores(float numeroUno , float numeroDos)
{
    float multiplicacion;
    multiplicacion = numeroUno * numeroDos;
    return multiplicacion;

}

float pedirNumero(void)
{
    float numero;
    printf("Ingrese un numero: ");
    scanf("%f" , &numero);
    return numero;
}

float divisionValores(float numeroUno , float numeroDos)
    {
        float division;

        division = numeroUno / numeroDos;

        return division;
    }


float factorValores(float numeroUno)
{
    float factorA;
    float factorialDeA;
    factorA=1;


        for (factorialDeA = numeroUno; factorialDeA > 0; factorialDeA--)
        {
            factorA = factorA * factorialDeA;
        }

    return factorA;

}


