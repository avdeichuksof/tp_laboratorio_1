/*
 * status.c
 *
 *  Created on: 14 may. 2022
 *      Author: avdei
 */


#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "status.h"

int listarStatusFlight(eStatusFlight status[], int tamS)
{
    int todoOk=0;
    if(status!=NULL && tamS>0)
    {
    	printf("\n\n\n\n");
        printf("*** Lista de estados de vuelo ***\n");
        printf("  Id        Descripcion\n");
        printf("------------------------------\n");

        for(int i=0; i<tamS; i++)
        {
            printf(" %4d   %10s\n", status[i].id, status[i].descripcion);
        }
        printf("\n\n");
        todoOk=1;
    }
    return todoOk;
}

int buscarStatusFlight(eStatusFlight status[], int tamS, int id, int* pIndice)
{
    int todoOk=0;
    if(status!=NULL && tamS>0 && pIndice!=NULL)
    {
        *pIndice= -1; //si da -1 no existe el estado
        for(int i=0; i<tamS; i++)
        {
            if(status[i].id==id)
            {
                *pIndice=i;
                break;
            }
        }
        todoOk=1;
    }
    return todoOk;
}

int cargarDescripcionStatusFlight(eStatusFlight status[], int tamS, int id, char descripcion[])
{
    int todoOk=0;
    int indice;

        buscarStatusFlight(status, tamS, id, &indice);

        if(descripcion!=NULL && indice!= -1)
        {
            strcpy(descripcion, status[indice].descripcion);
            todoOk=1;
        }
        return todoOk;
}

int validarStatusFlight(eStatusFlight status[], int tamS, int id)
{
    int esValido=0;
    int indice;

    buscarStatusFlight(status, tamS, id, &indice);

    if(indice!= -1)
    {
        esValido=1;
    }
    return esValido;
}

