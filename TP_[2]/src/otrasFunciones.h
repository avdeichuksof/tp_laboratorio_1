/*
 * otrasFunciones.h
 *
 *  Created on: 14 may. 2022
 *      Author: avdei
 */

#ifndef OTRASFUNCIONES_H_
#define OTRASFUNCIONES_H_

#include "arrayPassengers.h"
#include "status.h"

#endif /* OTRASFUNCIONES_H_ */

/** \brief menu de opciones
 *
 * \return int devuelve la opcion elegida
 *
 */
int menu();

/** \brief menu de opciones para modificar info de un pasajero
 *
 * \return int devuelve la opcion elegida
 *
 */
int menuModificarPasajero();

/** \brief submenu para elegir que informe mostrar
 *
 * \return int devuelve la opcion elegida
 *
 */
int subMenuInformes();

/** \brief busca un lugar libre en el array de pasajeros
 *
 * \param lista[] Passenger Pointer to array of passenger
 * \param len int Tamaño del array
 * \param pIndice int* Pointer to index
 * \return int Returns -1 si no hay lugar y todoOk si hay lugar
 *
 */
int buscarPasajeroLibre(Passenger lista[], int len, int* pIndice);

/** \brief busca un pasajero en el array pasajero mediante un id ingresado
 *
 * \param lista[] Passenger
 * \param lista[] Passenger Pointer to array of passenger
 * \param len int Tamaño del array
 * \param pIndice int* Pointer to index
 * \return int Returns -1 si el pasajero no existe y todoOk si existe
 *
 */
int buscarPasajero(Passenger lista[], int len, int id, int* pIndice);

/** \brief hardcodeo de pasajeros
 *
 * \param lista[] Passenger
 * \param lista[] Passenger Pointer to array of passenger
 * \param cant int Cantidad de pasajeros que se desea hardcodear
 * \param pId int* Pointer to passenger's Id
 * \return int
 *
 */
int hardcodearPasajeros(Passenger lista[], int len, int cant, int* pId);

/** \brief Dispone en una lista ordenada por columnas la informacion de los pasajeros dados de alta
 *
 * \param lista[] Passenger Pointer to array of Passengers
 * \param len int Array lenght
 * \param type[] eTypePassenger Pointer to array of typePassenger
 * \param tamT int Array lenght
 * \param status[] eStatusFlight Pointer to array of statusFlight
 * \param tamS int Array lenght
 * \return int Devuelve la lista con la informacion
 *
 */
int listarPasajeros(Passenger lista[], int len, eTypePassenger type[], int tamT, eStatusFlight status[], int tamS);

/** \brief Realiza el promedio del precio de los vuelos ingresados
 *
 * \param lista[] Passenger Pointer to array of Passengers
 * \param len int Array lenght
 * \return int Devuelve promedio, total y cantidad de pasajeros que superan el promedio del valor de vuelo
 *
 */
int promedioPreciosYTotal(Passenger lista[], int len);

/** \brief Muestra un pasajero del array Passengers
 *
 * \param onePassenger Passenger Una posicion dentro del array
 * \param type[] eTypePassenger Pointer to array of typePassengers
 * \param tamT int Array lenght
 * \param status[] eStatusFlight Pointer to array of statusFlight
 * \param tamS int Array lenght
 * \return int Informacion del pasajero
 *
 */
int mostrarPasajero(Passenger onePassenger, eTypePassenger type[], int tamT, eStatusFlight status[], int tamS);

