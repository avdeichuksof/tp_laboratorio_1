/*
 * otrasFunciones.c
 *
 *  Created on: 14 may. 2022
 *      Author: avdei
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "otrasFunciones.h"
#include "arrayPassengers.h"
#include "status.h"

int menu(void)
{
    int opcion;
    printf("\n\n\n\n");
    printf(" --- Menu de opciones ---\n");
    printf("1. Alta de pasajeros.\n");
    printf("2. Alta forzada de pasajeros.\n");
    printf("3. Modificar pasajero.\n");
    printf("4. Baja de pasajeros.\n");
    printf("5. Informes.\n");
    printf("6. Salir.\n");
    printf("Ingrese opcion: ");
    scanf("%d", &opcion);
    printf("\n\n\n\n");
    return opcion;
}

int menuModificarPasajero(void)
{
    int opcion;
    printf("\n\n\n\n");
    printf("*** Campos a modificar ***\n");
    printf("1- Nombre\n");
    printf("2- Apellido\n");
    printf("3- Precio\n");
    printf("4- Codigo de vuelo\n");
    printf("5- Tipo de pasajero\n");
    printf("6- Salir\n");
    printf("Ingrese opcion: ");
    scanf("%d", &opcion);
    printf("\n\n\n\n");
    return opcion;
}

int subMenuInformes(void)
{
    int opcion;
    printf("\n\n\n\n");
    printf("***Opciones a informar***\n");
    printf("1- Por apellido y tipo de pasajero\n");
    printf("2- Total y promedio de precios\n");
    printf("3- Por codigo de vuelo y estado ACTIVO\n");
    printf("4- Salir\n");
    printf("Ingrese opcion: ");
    scanf("%d", &opcion);
    printf("\n\n\n\n");
    return opcion;
}

int buscarPasajeroLibre(Passenger lista[], int len, int* pIndice)
{
    int todoOk = 0;
    if(lista!=NULL && len>0 && pIndice!=NULL)
    {
        *pIndice = -1;
        for(int i=0; i<len; i++)
        {
            if(lista[i].isEmpty)
            {
                *pIndice = i;
                break;
            }
        }
        todoOk = 1;
    }
    return todoOk;
}

int buscarPasajero(Passenger lista[], int len, int id, int* pIndice)
{
    int todoOk = 0;
    if(lista!=NULL && len>0 && pIndice!=NULL && id>0)
    {
        *pIndice = -1;
        for(int i=0; i < len; i++)
        {
            if( lista[i].isEmpty==0 && lista[i].id==id )
            {
                *pIndice = i;
                break;
            }
        }
        todoOk = 1;
    }
    return todoOk;
}


int hardcodearPasajeros(Passenger lista[], int len, int cant, int* pId)
{
    int todoOk=0;
    Passenger pasajeros[]=
    {
        {0, "Brian", "Alarcon", 50900.80, "aa1234ce", 6000, 2001, 0},
        {0, "Lucia", "Bimbo", 80090.00,"la1452pc", 6002, 2000, 0},
        {0, "Carlos", "Zarate", 60050.10, "fb1889ct", 6003, 2000, 0},
        {0, "Antonella", "Zarate", 90813.30, "aa1234ce", 6002, 2002, 0},
        {0, "Fabian", "Alvear", 70005.00, "la452pc", 6002, 2001, 0}
    };
    if(lista!=NULL && len>0 && pId!=NULL && cant>0 && cant<=len)
    {
        for(int i=0; i<cant; i++)
        {
            lista[i]=pasajeros[i];
            lista[i].id= *pId;
            *pId = *pId + 1;
        }
        todoOk=1;
    }
    return todoOk;
}

int listarPasajeros(Passenger lista[], int len, eTypePassenger type[], int tamT, eStatusFlight status[], int tamS)
{
    int todoOk=0;
    int flag=0;
    if(lista!= NULL && len>0)
    {
        system("cls");
        printf("                      *** Listado de Pasajeros ***\n\n");
        printf("  Id       Nombre     Apellido     Precio      Codigo       Tipo        Estado\n");
        printf("--------------------------------------------------------------------------------\n");
        for(int i=0; i < len; i++)
        {
            if(!lista[i].isEmpty)
            {
                mostrarPasajero(lista[i], type, tamT, status, tamS);
                flag++;
            }
        }
        if(flag == 0)
        {
            printf("No hay pasajeros en el sistema.\n");
        }
        printf("\n\n");

        todoOk = 1;
    }
    return todoOk;
}

int mostrarPasajero(Passenger onePassenger, eTypePassenger type[], int tamT, eStatusFlight status[], int tamS)
{
    int todoOk = 0;
    char descStatus[20];
    char descType[20];

    if(type != NULL && tamT > 0 && status!=NULL && tamS>0)
        {
            cargarDescripcionStatusFlight(status, tamS, status->id, descStatus);
            cargarDescripcionTypePassenger(type, tamT, type->id, descType);

            printf(" %4d  %10s  %10s    %9.2f  %10s  %10s  %10s\n",
                   onePassenger.id,
                   onePassenger.name,
                   onePassenger.lastName,
                   onePassenger.price,
                   onePassenger.flyCode,
                   descType,
                   descStatus);
            todoOk=1;
        }
    return todoOk;
}

int promedioPreciosYTotal(Passenger lista[], int len)
{
    int todoOk=0;
    float promedio=0;
    float acumuladorPrecios=0;
    float total=0;
    int contadorPasajeros=0;
    int contadorPasajerosMasDelPromedio=0;

    if(lista!=NULL && len>0)
    {
        for(int i=0; i<len; i++)
        {
            if(!lista[i].isEmpty)
            {
                acumuladorPrecios+=lista[i].price;
                contadorPasajeros++;
            }
        }
        if(contadorPasajeros!=0)
        {
            promedio=acumuladorPrecios/contadorPasajeros;
            total=acumuladorPrecios;
        }
        for(int i=0; i<len; i++)
        {
            if(lista[i].price>promedio)
            {
                contadorPasajerosMasDelPromedio++;
            }
        }
        todoOk=1;
        printf("El total de precios es: $ %9.2f\n", total);
        printf("El promedio de precios es: $ %9.2f\n", promedio);
        printf("Hay %d pasajeros que pagan mas que el promedio de los precios\n", contadorPasajerosMasDelPromedio);
    }
    return todoOk;
}


