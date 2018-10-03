#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>
#include "arrayEmployees.h"



void menuEmployees(sEmployee listadoEmployee[] , int tam)
{
    int opcion=0;
    int validacion = 0;
    do
    {
            printf("\n      *********************************************");
            printf("\n      ||                                         ||");
            printf("\n      ||          .:EMPLOYEE REGISTER:.          ||");
            printf("\n      ||                                         ||");
            printf("\n      *********************************************");
            printf("\n      ||                                         ||");
            printf("\n      ||      1. ALTA                            ||");
            printf("\n      ||                                         ||");
            printf("\n      ||      2. MODIFICACION                    ||");
            printf("\n      ||                                         ||");
            printf("\n      ||      3. BAJA                            ||");
            printf("\n      ||                                         ||");
            printf("\n      ||      4. INFORMAR                        ||");
            printf("\n      ||                                         ||");
            printf("\n      ||                                         ||");
            printf("\n      ||                                         ||");
            printf("\n      ||                                         ||");
            printf("\n      ||   5.Salir                               ||");
            printf("\n      *********************************************");
            printf("\n                                                    ");
            printf("\n");
            printf("\n          Ingrese una opcion (1/5) : ");
            scanf("%d" , & opcion);

        switch(opcion)
        {
            case 1:
                system("cls");
                validacion = 1;
                addEmployee(listadoEmployee,tam);
                break;

            case 2:
                if(validacion == 0)
                {

                    system("cls");
                    printf("    *--------------------------------------*     \n");
                    printf("    SE NECESITA LA CARGA DE ALGUN EMPLEADO       \n");
                    printf("    *--------------------------------------*     \n");
                    break;

                }
                else
                {
                    system("cls");
                    employeeModify(listadoEmployee , tam);
                    break;
                }
            case 3:
                if(validacion == 0)
                {

                    system("cls");
                    printf("    *--------------------------------------*     \n");
                    printf("    SE NECESITA LA CARGA DE ALGUN EMPLEADO       \n");
                    printf("    *--------------------------------------*     \n");
                    break;

                }
                else
                {
                    system("cls");
                    IdAuto();
                    employeeRemoveById(listadoEmployee, tam );
                    break;
                }
            case 4:
                if(validacion == 0)
                {
                    system("cls");
                    printf("    *--------------------------------------*     \n");
                    printf("    SE NECESITA LA CARGA DE ALGUN EMPLEADO       \n");
                    printf("    *--------------------------------------*     \n");
                    break;
                }
                else
                {
                    system("cls");
                    menuInformes(listadoEmployee , tam);
                    break;
                }
            case 5:
                opcion = 5;
                break;


        }
        system("pause");
    }
    while(opcion!=5);
    {
    }

}

void employeeRemoveById(sEmployee listadoEmployee[], int tam)
{
    int bandera =0;
    int acceder;
    int idaux;

    mostrarListadoEmployees(listadoEmployee , tam);
    printf("\n Ingrese el ID del empleado a remover ");
    scanf("%d" , & idaux);

    for(int i=0; i<tam ; i++)
    {
        if(listadoEmployee[i].isEmpty!=VACIO && idaux == listadoEmployee[i].id)
        {
            bandera=1;
            printf("\n ¿ Desea dar de baja permanentemente a este empleado ? \n (s/n)");
            acceder=getch();
            if(acceder == 's')
            {
                printf("   ----------------------------------------------    \n");
                printf("            Removiendo datos del Empleado...         \n");
                printf("   ----------------------------------------------    \n");
                system("pause");
                system("cls");
                printf("   ----------------------------------------------   \n");
                printf("            Se removio Exitosamente!!                \n");
                printf("   ----------------------------------------------    \n");
                listadoEmployee[i].isEmpty=VACIO;
                break;
            }
            else if (acceder != 's')
            {
                printf("\n Precione la tecla s para salir al menu \n");
            }
        }
    }
    if(bandera==0)
    {
        printf("\n No se encuentra este ID en la base de datos \n");
    }


}

int initEmployees(sEmployee* listadoEmployee , int tam)
{
    int i;

    for(i=0; i<tam; i++)
    {
        listadoEmployee[i].isEmpty = VACIO;
    }

    return 0;
}

int addEmployee(sEmployee listadoEmployee[] , int tam)
{
     sEmployee auxEmployee;
     int retorno = 0;
     int indice = traerIndiceVacio(listadoEmployee , tam);

     if(indice > -1)
     {
         do
         {
             printf(" \n Ingrese nombre del empleado: ");
             fflush(stdin);
             gets(auxEmployee.name);
         }while(strlen(auxEmployee.name)==0);

         do
         {
             printf(" \n Ingrese apellido del empleado: ");
             fflush(stdin);
             gets(auxEmployee.lastName);

         }while(strlen(auxEmployee.lastName)==0);

         printf(" \n Inggrese salario del empleado: ");
         fflush(stdin);
         scanf("%f" , &auxEmployee.salary);

         do
         {
             printf(" \n Ingrese sector del empleado: ");
             fflush(stdin);
             gets(auxEmployee.sector);

         }while(strlen(auxEmployee.sector)==0);

         auxEmployee.id = IdAuto();
         auxEmployee.isEmpty = OCUPADO;
         listadoEmployee[indice] = auxEmployee;

         retorno = 1;

     }
     else
     {
         system("cls");
                    printf("    *--------------------------------------*     \n");
                    printf("        NO HAY  ESPACIO PARA MAS ALTAS           \n");
                    printf("    *--------------------------------------*     \n");
     }
     return retorno;

}


void mostrarUnEmploye(sEmployee listadoEmployee)
{

    printf("%8d %14s %15s %19f %8s \n\n", listadoEmployee.id , listadoEmployee.name,
                                 listadoEmployee.lastName, listadoEmployee.salary, listadoEmployee.sector);
}


int mostrarListadoEmployees(sEmployee listadoEmployee[] , int tam)
{
    int retorno = -1;
    int i;

    system("cls");
    printf("%10s %10s %10s %15s %12s \n\n", "ID Employee --" , " -- Nombre --" ,  " -- Apellido --" ,  " -- Salario --" , " -- Sector --");

    if(tam > 0 && listadoEmployee != NULL)
    {
        retorno = 0;
        for(i=0; i<tam; i++)
        {
            if(listadoEmployee[i].isEmpty ==OCUPADO)
            {

                mostrarUnEmploye(listadoEmployee[i]);
            }
        }
    }
    return retorno;
}


int findEmployeeById(sEmployee listadoEmployee[] , int tam , int id)
{
    int resultado = -1;
    int i;

    for(i = 0 ; i < tam; i++)
    {
        if(listadoEmployee[i].id == id && listadoEmployee[i].isEmpty == BORRADO)
        {
            resultado = i;
            break;
        }
    }
    return resultado;


}

int IdAuto(void)
{
    static int IDEmpleado=0;

    IDEmpleado++;
    return IDEmpleado;
}


void employeeModify(sEmployee listadoEmployee[] , int tam)
{
    int idaux;
    int i;
    int opcion;
    char validar;

    mostrarListadoEmployees(listadoEmployee , tam);
    printf("Ingrese el ID del empleado: ");
    scanf("%d" , &idaux);

    for(i=0 ; i<tam ; i++)
    {
        if(idaux == listadoEmployee[i].id)
        {
            mostrarListadoEmployees(listadoEmployee , tam);
            printf("Desea modificar algun dato ?  s / n");
            validar=getch();
            if(validar == 's')
            {
                printf("\n      *********************************************");
                printf("\n      ||                                         ||");
                printf("\n      ||          QUE DESEA MODIFICAR ?          ||");
                printf("\n      ||                                         ||");
                printf("\n      *********************************************");
                printf("\n      ||                                         ||");
                printf("\n      ||      1. Nombre                          ||");
                printf("\n      ||                                         ||");
                printf("\n      ||      2. Apellido                        ||");
                printf("\n      ||                                         ||");
                printf("\n      ||      3. Salario                         ||");
                printf("\n      ||                                         ||");
                printf("\n      ||      4. Sector                          ||");
                printf("\n      ||                                         ||");
                printf("\n      ||                                         ||");
                printf("\n      ||   5.Salir                               ||");
                printf("\n      *********************************************");
                printf("\n");
                printf("\n          Ingrese una opcion (1/5) :      ");
                scanf("%d" , & opcion);

                switch(opcion)
                {
                    case 1:
                        system("cls");
                        fflush(stdin);
                        printf("Ingrese nuevo nombre: ");
                        gets(listadoEmployee[i].name);
                        printf("\n\n");
                        mostrarListadoEmployees(listadoEmployee , tam);
                        system("pause");
                        break;
                    case 2:
                        system("cls");
                        fflush(stdin);
                        printf("Ingrese nuevo apellido: ");
                        gets(listadoEmployee[i].lastName);
                        printf("\n\n");
                        mostrarListadoEmployees(listadoEmployee , tam);
                        system("pause");
                        break;
                    case 3:
                        system("cls");
                        fflush(stdin);
                        printf("Ingrese nuevo salario: ");
                        scanf("%f" , &listadoEmployee[i].salary);
                        printf("\n\n");
                        mostrarListadoEmployees(listadoEmployee , tam);
                        system("pause");
                        break;
                    case 4:
                        system("cls");
                        fflush(stdin);
                        printf("Ingrese nuevo sector: ");
                        gets(listadoEmployee[i].sector);
                        printf("\n\n");
                        mostrarListadoEmployees(listadoEmployee , tam);
                        system("pause");
                        break;
                    case 5:
                        opcion = 5;
                        break;
                    default:
                        printf("Ingrese una opcion valida");

                }
            }
        }
    }
}

void menuInformes(sEmployee listadoEmployee[] , int tam)
{
    int opcion;
    do
    {
                printf("\n      ******************************************************************");
                printf("\n      ||                                                              ||");
                printf("\n      ||                      |Informe Empleados|                     ||");
                printf("\n      ||                                                              ||");
                printf("\n      ******************************************************************");
                printf("\n      ||                                                              ||");
                printf("\n      ||      1.Empleados ordenados por Apellido                      ||");
                printf("\n      ||                                                              ||");
                printf("\n      ||      2.Empleados ordenados por Sector                        ||");
                printf("\n      ||                                                              ||");
                printf("\n      ||      3.Promedio Salarios y Total de Salarios                 ||");
                printf("\n      ||                                                              ||");
                printf("\n      ||                                                              ||");
                printf("\n      ||                                                              ||");
                printf("\n      ||                                                              ||");
                printf("\n      ||   5.Salir                                                    ||");
                printf("\n      ******************************************************************");
                printf("\n");
                printf("\n          Ingrese una opcion (1/5) :      ");
                scanf("%d" , & opcion);

                switch(opcion)
                {
                    case 1:
                        system("cls");
                        alphabeticallyOrderedByLastName(listadoEmployee , tam);
                        mostrarListadoEmployees(listadoEmployee , tam);
                        break;
                    case 2:
                        system("cls");
                        alphabeticallyOrderedBySector(listadoEmployee ,  tam);
                        mostrarListadoEmployees(listadoEmployee , tam);
                        break;
                    case 3:
                        system("cls");
                        avarageSalary(listadoEmployee, tam);
                        break;

                }

    }
    while(opcion!=4);
    {

    }

}

void alphabeticallyOrderedByLastName(sEmployee listadoEmployee[] , int tam)
{
    int i;
    int j;
    sEmployee aux;


    system("cls");
    for(i=0; i<tam-1; i++)
    {
        for(j=i+1; j<tam; j++)
        {
                if (strcmp(listadoEmployee[i].lastName , listadoEmployee[j].lastName) > 0)
                {
                    aux=listadoEmployee[i];
                    listadoEmployee[i]=listadoEmployee[j];
                   listadoEmployee[j]=aux;
                }
        }
    }


}

void alphabeticallyOrderedBySector(sEmployee listadoEmployee[] , int tam)
{
    int i;
    int j;
    sEmployee aux;

    system("cls");
    for(i=0; i<tam-1; i++)
    {
        for(j=i+1; j<tam; j++)
        {
                if (listadoEmployee[i].sector > listadoEmployee[j].sector)
                {
                    aux=listadoEmployee[i];
                    listadoEmployee[i]=listadoEmployee[j];
                    listadoEmployee[j]=aux;
                }
        }
    }
}


void avarageSalary(sEmployee listadoEmployee[] , int tam)
{
    int contarSalary=0;
    float sumaSalary=0;
    float avarageSueldo;
    int contadorMaxSalary=0;
    int i;

    for(i=0 ; i < tam ; i++)
    {
        if(listadoEmployee[i].isEmpty == OCUPADO)
        {
            sumaSalary+=listadoEmployee[i].salary;
            contarSalary++;
        }

    }
    avarageSueldo = sumaSalary/contarSalary;
    for(i = 0 ; i< tam ; i++)
    {

        if(listadoEmployee[i].isEmpty == OCUPADO && listadoEmployee[i].salary>avarageSueldo)
        {
            mostrarUnEmploye(listadoEmployee[i]);
            contadorMaxSalary++;
        }
    }

    system("cls");
    printf("   ----------------------------------------------    \n");
    printf("            El total de los sueldos es:  %2.f        \n" , sumaSalary);
    printf("   ----------------------------------------------    \n");

    printf("   ----------------------------------------------    \n");
    printf("            Promedio Total de sueldo:  %2.f          \n" , avarageSueldo);
    printf("   ----------------------------------------------    \n");

    printf("   ---------------------------------------------------------------------    \n");
    printf("      Los empleados que superan el salario prommedio es de: %d             \n" , contadorMaxSalary);
    printf("   ---------------------------------------------------------------------    \n");

    system("pause");
}


int traerIndiceVacio(sEmployee listadoEmployee[] ,int tam)
{
    int retorno = -1;
    int i;
    if(listadoEmployee != NULL && tam>0)
    {
        for (i=0; i<tam; i++)
        {
            if (listadoEmployee[i].isEmpty)
            {
                retorno = i;
                break;
            }
        }
    }
    return retorno;
}



