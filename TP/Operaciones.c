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


float factorValores(float numeroUno, float numeroDos)
{
    float factorA;
    float factorB;
    float factorialA;
    float factorialB;
    factorA=1;
    factorB=1;

    if(numeroUno>=0)
    {

        for (factorialA = numeroUno; factorialA >= 1; factorialA--)
        {
            factorA = factorA * factorialA;
        }

        printf("El factorial del primero numero es  %2.f\n" , factorA);

    }
    else
    {
        printf("No se puede obtener el factorial del primer numero \n");
    }
    if(numeroDos>=0)
    {
        for (factorialB = numeroDos; factorialB >= 1; factorialB--)
        {
                factorB = factorB * factorialB;
        }
        printf("El factorial del segundo numero es  %2.f  \n" , factorB);

    }
    else
    {
        printf("No se puede obtener el factorial del segundo numero \n");
    }


        return 0;


}


