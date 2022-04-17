/*
 * funcionesEntradaYSalida.h
 *
 *  Created on: 16 abr. 2022
 *      Author: avdei
 */

#ifndef FUNCIONESENTRADAYSALIDA_H_
#define FUNCIONESENTRADAYSALIDA_H_



#endif /* FUNCIONESENTRADAYSALIDA_H_ */

/** \brief muestra el menu y solicita opcion
 *
 * \return int retorna la opcion seleccionada
 *
 */
int menu();

/** \brief solicita confirmacion de salida
 *
 * \param p char* recibe un caracter
 * \return void
 *
 */
void confirmarSalida(char* p);



/** \brief solicita ingreso de km
 *
 * \param pFlagKm int* recibe la flag en 0
 * \param kmIngresado float guarda los km ingresados
 * \return void
 *
 */
void ingresarKm(int* pFlagKm, float* pKmIngresado);


/** \brief muestra opciones para ingresar los precios de las aerolineas
 *
 * \return int retorna la opcion seleccionada
 *
 */
int subMenuAerolineas();


/** \brief solicita ingreso de precio del vuelo de aerolineas
 *
 * \param pFlagPrecioAerolineas int* recibe la flag en 0
 * \param pPrecioAerolineasIngresado float* guarda el precio ingresado
 * \return return void
 *
 */
void ingresarPrecioAerolineas(int* pFlagPrecioAerolineas, float* pPrecioAerolineasIngresado);


/** \brief solicita ingreso de precio del vuelo de latam
 *
 * \param pFlagPrecioLatam int* recibe la flag en 0
 * \param pPrecioLatamIngresado float* guarda el precio ingresado
 * \return return void
 *
 */
void ingresarPrecioLatam(int* pFlagPrecioLatam, float* pPrecioLatamIngresado);
