/*
 * arrayPassengers.c
 *
 *  Created on: 14 may. 2022
 *      Author: avdei
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "arrayPassengers.h"
#include "type.h"
#include "otrasFunciones.h"
#include "status.h"

int initPassengers(Passenger lista[], int len)
{
    int todoOk= 0;
	if(lista!=NULL && len>0)
	    {
	        for(int i=0; i<len; i++)
	        {
	        	lista[i].isEmpty = 1;
	        }
	        todoOk = 1;
	    }
	return todoOk;
}

int printPassenger(Passenger lista[], int len, eTypePassenger type[], int tamT, eStatusFlight status[], int tamS)
{
    int todoOk=0;
    char descTypePassenger[20];
    char descStatusFlight[20];

    if(lista!=NULL && len>0)
        {
            cargarDescripcionStatusFlight(status, tamS, status->id, descStatusFlight);
            cargarDescripcionTypePassenger(type, tamT, type->id, descTypePassenger);

            printf(" %4d     %s     %s     %9.2f    %s    %s     %s\n",
                   lista->id,
                   lista->name,
                   lista->lastName,
                   lista->price,
                   lista->flyCode,
                   descTypePassenger,
                   descStatusFlight);

            todoOk=1;
        }
	return todoOk;
}


int addPassenger(Passenger lista[], int len, int* pId, char name[],char lastName[],
float price,int typePassenger, char flyCode[], eTypePassenger type[], int tamT, eStatusFlight status[], int tamS)
{
    int todoOk = 0;
    char auxCad[100];
    int indice;
    Passenger nuevoPasajero;

    if(lista!=NULL && len>0 && pId!=NULL && type!=NULL && tamT>0 && status!=NULL && tamS>0)
    {
        if(buscarPasajeroLibre(lista, len, &indice))
        {
            if(indice == - 1)
            {
                printf("No hay lugar en el sistema\n");
            }
            else
            {
                // aca caigo cuando haya lugar
                printf("Ingrese nombre: ");
                fflush(stdin);
                gets(auxCad);
                while(strlen(auxCad) >= 51)
                {
                    printf("Nombre demasiado largo. Reingrese nombre: ");
                    fflush(stdin);
                    gets(auxCad);
                }
                strcpy(nuevoPasajero.name, auxCad);

                printf("Ingrese apellido: ");
                fflush(stdin);
                gets(auxCad);
                while(strlen(auxCad) >= 51)
                {
                    printf("Apellido demasiado largo. Reingrese apellido: ");
                    fflush(stdin);
                    gets(auxCad);
                }
                strcpy(nuevoPasajero.lastName, auxCad);

                printf("Ingrese precio: ");
                scanf("%f", &nuevoPasajero.price);
                while(nuevoPasajero.price<0)
                {
                    printf("Precio invalido. Ingrese precio: ");
                    scanf("%f", &nuevoPasajero.price);
                }

                printf("Ingrese codigo de vuelo: ");
                scanf("%s", &nuevoPasajero.flyCode);

                listarTypePassenger(type, tamT);
                printf("Ingrese Id de tipo de pasajero: ");
                scanf("%d", &nuevoPasajero.typePassenger);
                while(!validarTypePassenger(type, tamT, type->id))
                {
                    printf("Id invalido. Ingrese Id de tipo de pasajero: ");
                    scanf("%d", &nuevoPasajero.typePassenger);
                }

                listarStatusFlight(status, tamS);
                printf("Ingrese Id del estado de su vuelo: ");
                scanf("%d", &nuevoPasajero.statusFlight);
                 while(!validarStatusFlight(status, tamS, status->id))
                {
                    printf("Id invalido. Ingrese Id de estado de vuelo: ");
                    scanf("%d", &nuevoPasajero.statusFlight);
                }

                nuevoPasajero.isEmpty = 0;
                nuevoPasajero.id = *pId;
                *pId = *pId + 1;
                lista[indice] = nuevoPasajero;
                todoOk = 1;

                printf("Pasajero agregado exitosamente\n");

                listarPasajeros(lista, len, type, tamT, status, tamS);

            }
        }
        else
        {
            printf("Ocurrio un problema con los parametros\n");
        }
    }
    return todoOk;
}


int findPassengerById(Passenger lista[], int len, int id, int* pIndice)
{
    int todoOk=0;
    if(lista!=NULL && len>0 && id>0)
    {
        *pIndice=-1;
        for(int i=0; i<len; i++)
        {
            if(lista[i].isEmpty==0 &&  lista[i].id==id)
            {
                *pIndice=i;
                break;
            }
        }
        todoOk=1;
    }
    return todoOk;
}

int modifyPassengers(Passenger lista[], int len, eTypePassenger type[], int tamT, eStatusFlight status[], int tamS)
{
    int todoOk = 0;
    int indice;
    int id;
    char salir = 'n';
    char auxCad[100];
    if(lista!=NULL && len>0)
    {
        listarPasajeros(lista, len, type, tamT, status, tamS);
        printf("Ingrese id: ");
        scanf("%d", &id);
        if(findPassengerById(lista, len, id, &indice))
        {
            if(indice == -1)
            {
                printf("No hay un pasajero con id %d\n", id);
            }
            else
            {
                mostrarPasajero(lista[indice], type, tamT, status, tamS);

                do
                {
                    switch(menuModificarPasajero())
                    {

                    case 1:
                        printf("Ingrese nuevo nombre: ");
                        fflush(stdin);
                        gets(auxCad);
                        strcpy(lista[indice].name, auxCad);
                        printf("Se ha modificado el nombre\n");
                        break;
                    case 2:
                        printf("Ingrese nuevo apellido: ");
                        fflush(stdin);
                        gets(auxCad);
                        strcpy(lista[indice].lastName, auxCad);
                        printf("Se ha modificado el apellido\n");
                        break;
                    case 3:
                        printf("Ingrese nuevo precio: ");
                        scanf("%f", &lista[indice].price);
                        printf("Se ha modificado la precio\n");
                        break;
                    case 4:
                        printf("Ingrese nuevo codigo de vuelo: ");
                        scanf("%s", &lista[indice].flyCode);
                        printf("Se ha modificado el codigo de vuelo\n");
                        break;
                    case 5:
                        listarTypePassenger(type, tamT);
                        printf("Ingrese nuevo tipo de pasajero: ");
                        scanf("%s", &lista[indice].typePassenger);
                        while(!validarTypePassenger(type, tamT, type->id))
                        {
                            printf("Id invalida. Ingrese nuevo tipo de pasajero: ");
                            scanf("%s", &lista[indice].typePassenger);

                        }
                        printf("Se a modificado el tipo de pasajero\n");
                        break;
                    case 6:
                        salir = 's';
                        break;
                    }
                    system("pause");
                }
                while(salir != 's');
            }
        }
        else
        {
            printf("Ocurrio un problema al buscar pasajero\n");
        }
        todoOk = 1;
    }
    return todoOk;
}

int removePassenger(Passenger lista[], int len, int id, eTypePassenger type[], int tamT, eStatusFlight status[], int tamS)
{
    int todoOk=0;
    int indice;
    char confirmar;
    if(lista!=NULL && len>0)
    {
        listarPasajeros(lista, len, type, tamT, status, tamS);

        printf("Ingrese id: ");
        scanf("%d", &id);

        if(buscarPasajero(lista, len, id, &indice))
        {
            if(indice== -1)
            {
                printf("No hay pasajeros con id %d\n", id);
            }
            else
            {
                mostrarPasajero(lista[indice], type, tamT, status, tamS);
                printf("Confirma baja?: ");
                fflush(stdin);
                scanf("%c", &confirmar);
                if(confirmar!='S' && confirmar!='s')
                {
                    printf("Baja cancelada por el usuario\n");
                }
                else
                {
                    lista[indice].isEmpty=1;
                    printf("Baja realizada con exito\n");
                    todoOk=1;
                }
            }
        }
        else
        {
            printf("Ocurrio un problema al buscar pasajero\n");
        }
    }
    return todoOk;
}

int sortPassengers(Passenger lista[], int len, int order)
{
    int todoOk = 0;
    Passenger auxType;
    if(lista!= NULL && len>0 && order>=0 && order<=1)
    {
        for(int i=0; i<len -1; i++)
        {
            for(int j= i + 1; j<len; j++)
            {
                if( (strcmp(lista[i].lastName, lista[j].lastName)>0 &&(lista[i].typePassenger == lista[j].typePassenger) &&  order==1)
                   || (lista[i].typePassenger>lista[j].typePassenger && order==1)
                   || (strcmp(lista[i].lastName, lista[j].lastName)<0 &&(lista[i].typePassenger == lista[j].typePassenger) &&  order==0)
                   || (lista[i].typePassenger<lista[j].typePassenger && order==0))
                   {
                        auxType = lista[i];
                        lista[i] = lista[j];
                        lista[j] = auxType;
                   }
                }
            }
            todoOk = 1;
        }
       return todoOk;
    }

int sortPassengersByCodeStatus(Passenger lista[], int len, int order)
{
    int todoOk = 0;
    Passenger auxType;
    if(lista!= NULL && len>0 && order>=0 && order<=1)
    {
        for(int i=0; i<len -1; i++)
        {
            for(int j= i + 1; j<len; j++)
            {
                if(((lista[i].statusFlight == lista[j].statusFlight) && strcmp(lista[i].flyCode, lista[j].flyCode)>0 && order==1)
                   || (lista[i].statusFlight>lista[j].statusFlight && order ==1)
                   || ((lista[i].statusFlight == lista[j].statusFlight) && strcmp(lista[i].flyCode, lista[j].flyCode)<0 && order==0)
                   || (lista[i].statusFlight<lista[j].statusFlight && order ==0))
                {
                    auxType = lista[i];
                    lista[i] = lista[j];
                    lista[j] = auxType;
                }
            }
        }
        todoOk = 1;
    }
    return todoOk;
}


