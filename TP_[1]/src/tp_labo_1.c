/*
 ============================================================================
 Name        : tp_labo_1.c
 Author      : Avdeichuk Sofia
 Version     :
 Copyright   : Your copyright notice
 Description : Tp Labo 1
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include "funcionesEntradaYSalida.h"
#include "funcionesDeCalculo.h"

int main(void)
{
	setbuf(stdout, NULL);

		char salir='n';

	    int flagKm=0;
	    int flagPrecioAerolineas=0;
	    int flagPrecioLatam=0;
	    int flagCalculoCostos=0;

	    float precioBtc=4606954.55;
	    float kmIngresado;
	    float precioLatamIngresado;
	    float precioAerolineasIngresado;

	    float kmForzado=7090;
	    float precioLatamForzado=159339;
	    float precioAerolineasForzado=162965;

	    do
	    {
	        switch(menu())
	        {
	        case 1:
	            ingresarKm(&flagKm, &kmIngresado);
	            break;
	        case 2:
	            if(flagKm==1)
	            {
	                switch(subMenuAerolineas())
	                {
	                case 1:
	                    ingresarPrecioAerolineas(&flagPrecioAerolineas, &precioAerolineasIngresado);
	                    break;
	                case 2:
	                    ingresarPrecioLatam(&flagPrecioLatam, &precioLatamIngresado);
	                    break;
	                }
	            }
	            else
	            {
	                printf("Primero ingrese los km, por favor.\n");
	            }
	            break;
	        case 3:
	            if(flagPrecioAerolineas==1 && flagPrecioLatam==1)
	            {
	                printf("Calculando resultados...\n");
	                flagCalculoCostos=1;
	            }
	            else
	            {
	                printf("Primero debe ingresar ambos precios del vuelo.\n");
	            }
	            break;
	        case 4:
	            if(flagCalculoCostos==1)
	            {
	                printf("Latam: %.2f", precioLatamIngresado);
	                printf("\na) Precio con tarjeta de debito: %.2f", debitoLatam(&precioLatamIngresado));
	                printf("\nb) Precio con tarjeta de credito: %.2f", creditoLatam(&precioLatamIngresado));
	                printf("\nc) Precio pagando con bitcoin : %.7f", btcLatam(&precioBtc, &precioLatamIngresado));
	                printf("\nd) Precio unitario: %.2f", precioUnitarioL(&kmIngresado, &precioLatamIngresado));
	                printf("\n");
	                printf("\nAerolineas: %.2f", precioAerolineasIngresado);
	                printf("\na) Precio con tarjeta de debito: %.2f", debitoAerolineas(&precioAerolineasIngresado));
	                printf("\nb) Precio con tarjeta de credito: %.2f", creditoAerolineas(&precioAerolineasIngresado));
	                printf("\nc) Precio pagando con bitcoin : %.7f", btcAerolineas(&precioBtc, &precioAerolineasIngresado));
	                printf("\nd) Precio unitario: %.2f", precioUnitarioA(&kmIngresado, &precioAerolineasIngresado));
	                printf("\n");
	                printf("\nLa diferencia de precio es : %.2f\n", diferencia(&precioAerolineasIngresado, &precioLatamIngresado));
	            }
	            else
	            {
	                printf("Primero se deben calcular los costos.\n");
	            }

	            break;
	        case 5:
	            printf("Latam: %.2f", precioLatamForzado);
	            printf("\na) Precio con tarjeta de debito: %.2f", debitoLatam(&precioLatamForzado));
	            printf("\nb) Precio con tarjeta de credito: %.2f", creditoLatam(&precioLatamForzado));
	            printf("\nc) Precio pagando con bitcoin : %.7f", btcLatam(&precioBtc, &precioLatamForzado));
	            printf("\nd) Precio unitario: %.2f", precioUnitarioL(&kmForzado, &precioLatamForzado));
	            printf("\n");
	            printf("\nAerolineas: %.2f", precioAerolineasForzado);
	            printf("\na) Precio con tarjeta de debito: %.2f", debitoAerolineas(&precioAerolineasForzado));
	            printf("\nb) Precio con tarjeta de credito: %.2f", creditoAerolineas(&precioAerolineasForzado));
	            printf("\nc) Precio pagando con bitcoin : %.7f", btcAerolineas(&precioBtc, &precioAerolineasForzado));
	            printf("\nd) Precio unitario: %.2f", precioUnitarioA(&kmForzado, &precioAerolineasForzado));
	            printf("\n");
	            printf("\nLa diferencia de precio es : %.2f\n", diferencia(&precioAerolineasForzado, &precioLatamForzado));
	            break;
	        case 6:
	            confirmarSalida(&salir);
	            break;
	        default:
	            printf("Opcion invalida. Elija una opcion del 1 al 6.\n");
	            break;
	        }

	        system("pause");

	    }while(salir!='s');

	return EXIT_SUCCESS;
}
