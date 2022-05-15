/*
 ============================================================================
 Name        : TP_labo_2.c
 Author      : 
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include "arrayPassengers.h"
#include "otrasFunciones.h"
#include "type.h"
#include "status.h"

#define UP 1
#define DOWN 0

#define LAST_NAME 0
#define TYPE 1
#define CODE 2
#define STATUS 3

#define TAM_PASS 8
#define TAM_CODE 5
#define TAM_TYPE 3
#define TAM_STAT 3

int main(void){
	setbuf (stdout,NULL);

	char salir='n';
	    int flagPassenger=0;

	    int proximoId=1000;
	    Passenger lista[TAM_PASS];
	    eTypePassenger type[TAM_TYPE]=
	    {
	        {6000, "Primera"},
	        {6001, "Ejecutiva"},
	        {6002, "Turista"}
	    };
	    eStatusFlight status[TAM_STAT]=
	    {
	        {2000, "Activo"},
	        {2001, "Inactivo"},
	        {2002, "Demorado"}
	    };

	    initPassengers(lista, TAM_PASS);

	    hardcodearPasajeros(lista, TAM_PASS, 5, &proximoId);

	    do
	    {
	        switch(menu())
	        {
	        case 1:
	            addPassenger(lista, TAM_PASS, &proximoId, lista->name, lista->lastName, lista->price, lista->typePassenger, lista->flyCode, type, TAM_TYPE, status, TAM_STAT);
	            flagPassenger=1;
	            break;
	        case 2:
	            listarPasajeros(lista, TAM_PASS, type, TAM_TYPE, status, TAM_STAT);
	            flagPassenger=1;
	            break;
	        case 3:
	            if(flagPassenger==1)
	            {
	                modifyPassengers(lista, TAM_PASS, type, TAM_TYPE, status, TAM_STAT);
	            }
	            else
	            {
	                printf("ERROR.Para realizar esta accion deben haberse ingresado pasajeros.\n");
	            }
	            break;
	        case 4:
	            if(flagPassenger==1)
	            {
	                removePassenger(lista, TAM_PASS, &proximoId, type, TAM_TYPE, status, TAM_STAT);
	            }
	            else
	            {
	                printf("ERROR.Para realizar esta accion deben haberse ingresado pasajeros.\n");
	            }
	            break;
	        case 5:
	            if(flagPassenger==1)
	            {
	                switch(subMenuInformes())
	                {
	                    case 1:
	                        sortPassengers(lista, TAM_PASS, 1);
	                        listarPasajeros(lista, TAM_PASS, type, TAM_TYPE, status, TAM_STAT);
	                        break;
	                    case 2:
	                        promedioPreciosYTotal(lista, TAM_PASS);
	                        break;
	                    case 3:
	                        sortPassengersByCodeStatus(lista, TAM_PASS, 1);
	                        listarPasajeros(lista, TAM_PASS, type, TAM_TYPE, status, TAM_STAT);
	                        break;
	                    case 4:
	                        salir='s';
	                        break;
	                }
	            }
	            else
	            {
	                printf("ERROR.Para realizar esta accion deben haberse ingresado pasajeros.\n");
	            }
	            break;
	        case 6:
	            salir='s';
	            break;
	        }
	        system("pause");
	    }
	    while(salir!='s');


	return 0;
}
