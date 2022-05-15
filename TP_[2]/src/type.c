/*
 * type.c
 *
 *  Created on: 14 may. 2022
 *      Author: avdei
 */


#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "type.h"


int listarTypePassenger(eTypePassenger type[], int tamT)
{
    int todoOk=0;
    if(type!=NULL && tamT>0)
    {
    	printf("\n\n\n\n");
        printf("*** Lista de estados de vuelo ***\n");
        printf("  Id        Descripcion\n");
        printf("------------------------------\n");

        for(int i=0; i<tamT; i++)
        {
            printf(" %4d   %10s\n", type[i].id, type[i].descripcion);
        }
        printf("\n\n");
        todoOk=1;
    }
    return todoOk;
}

int buscarTypePassenger(eTypePassenger type[], int tamT, int id, int* pIndice)
{
    int todoOk=0;
    if(type!=NULL && tamT>0 && pIndice!=NULL)
    {
        *pIndice= -1;
        for(int i=0; i<tamT; i++)
        {
            if(type[i].id==id)
            {
                *pIndice=i;
                break;
            }
        }
        todoOk=1;
    }
    return todoOk;
}

int cargarDescripcionTypePassenger(eTypePassenger type[], int tamT, int id, char descripcion[])
{
    int todoOk=0;
    int indice;

        buscarTypePassenger(type, tamT, id, &indice);

        if(descripcion!=NULL && indice!= -1)
        {
            strcpy(descripcion, type[indice].descripcion);
            todoOk=1;
        }
        return todoOk;
}

int validarTypePassenger(eTypePassenger type[], int tamT, int id)
{
    int esValido=0;
    int indice;

    buscarTypePassenger(type, tamT, id, &indice);

    if(indice!= -1)
    {
        esValido=1;
    }
    return esValido;
}
