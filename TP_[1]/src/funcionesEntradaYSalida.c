/*
 * funcionesEntradaYSalida.c
 *
 *  Created on: 16 abr. 2022
 *      Author: avdei
 */

#include <stdio.h>
#include <stdlib.h>
#include "funcionesEntradaYSalida.h"

int menu()
{
    int opcion;

	system ("\n\n\n\n");
	printf(" *** MENU DE OPCIONES ***\n");
	printf("1- Ingresar kilometros.\n");
	printf("2- Ingresar precio de vuelos.\n");
	printf("3- Calcular costos.\n");
	printf("4- Informar resultados.\n");
	printf("5- Carga forzada de datos.\n");
	printf("6- Salir\n");
	printf("Ingrese la opcion elegida: ");
	scanf("%d", &opcion);
	system ("\n\n\n\n");

	return opcion;
}

void confirmarSalida(char* p)
{
    char confirmar;
    printf("Está seguro que desea salir? (s:si / n:no): ");
    fflush(stdin);
    scanf("%c", &confirmar);

    *p=confirmar;
}

void ingresarKm(int* pFlagKm, float* pKmIngresado)
{
    if(pFlagKm!=NULL)
    {   float kmIngresado;

        printf("Ingrese los km de su vuelo: ");
        scanf("%f", &kmIngresado);
        *pFlagKm=1;
        *pKmIngresado=kmIngresado;
    }
    while(pKmIngresado<0)
    {
        float kmIngresado;

        printf("Valor invalido. Reingrese los km de su vuelo: ");
        scanf("%f", &kmIngresado);
        *pFlagKm=1;
        *pKmIngresado=kmIngresado;
    }

}

int subMenuAerolineas()
{
    int opcion;

    system ("\n\n\n\n");
    printf("1. Ingresar precio de vuelo Aerolineas.\n");
    printf("2. Ingresar precio de vuelo Latam.\n");
    printf("Ingrese la opcion elegida: ");
	scanf("%d", &opcion);
	system ("\n\n\n\n");

	return opcion;
}

void ingresarPrecioAerolineas(int* pFlagPrecioAerolineas, float* pPrecioAerolineasIngresado)
{
    float precioAerolineasIngresado;

    printf("Ingrese el precio del vuelo de Aerolineas: ");
    scanf("%f", &precioAerolineasIngresado);

    *pFlagPrecioAerolineas=1;
    *pPrecioAerolineasIngresado=precioAerolineasIngresado;
}

void ingresarPrecioLatam(int* pFlagPrecioLatam, float* pPrecioLatamIngresado)
{
    float precioLatamIngresado;

    printf("Ingrese el precio del vuelo de Latam: ");
    scanf("%f", &precioLatamIngresado);
    *pFlagPrecioLatam=1;
    *pPrecioLatamIngresado=precioLatamIngresado;
}

