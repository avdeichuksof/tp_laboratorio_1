/*
 * funcionesDeCalculo.c
 *
 *  Created on: 16 abr. 2022
 *      Author: avdei
 */

#include <stdio.h>
#include <stdlib.h>
#include "funcionesDeCalculo.h"


float debitoAerolineas (float* pPrecioA)
{
    float debitoA;

    debitoA= *pPrecioA * 0.10;
    return debitoA;
}

float debitoLatam (float* pPrecioL)
{
    float debitoL;

    debitoL = *pPrecioL * 0.10;
    return debitoL;
}

float creditoAerolineas (float* pPrecioA)
{
    float creditoA;

    creditoA= *pPrecioA + (*pPrecioA * 0.25);
    return creditoA;
}

float creditoLatam (float* pPrecioL)
{
    float creditoL;

    creditoL= *pPrecioL + (*pPrecioL * 0.25);
    return creditoL;
}

float btcAerolineas (float* pPrecioBtc, float* pPrecioA)
{
    float btcA;

    btcA=(*pPrecioA / *pPrecioBtc);
    return btcA;
}

float btcLatam (float* pPrecioBtc, float* pPrecioL)
{
    float btcL;

    btcL=(*pPrecioL / *pPrecioBtc);
    return btcL;
}

float precioUnitarioA (float* pKms, float* pPrecioA)
{
    float unitarioA;

    unitarioA=(*pPrecioA / *pKms);
    return unitarioA;
}

float precioUnitarioL (float* pKms, float* pPrecioL)
{
    float unitarioL;

    unitarioL=(*pPrecioL / *pKms);
    return unitarioL;
}

float diferencia (float* pPrecioA, float* pPrecioL)
{
    float diferencia;

    diferencia=(*pPrecioA - *pPrecioL);
    return diferencia;
}

