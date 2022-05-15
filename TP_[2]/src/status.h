/*
 * status.h
 *
 *  Created on: 14 may. 2022
 *      Author: avdei
 */

#ifndef STATUS_H_
#define STATUS_H_

struct
{
    int id;
    char descripcion[20];
    int isEmpty;
}typedef eStatusFlight;

#endif /* STATUS_H_ */

/** \brief busca el estado de vuelo elegido por id
 *
 * \param status[] eStatusFlight Pointer to array of statusFlight
 * \param tamS int Array lenght
 * \param id int Status id
 * \param pIndice int* Pointer to index
 * \return int Returns -1 si no existe el id y todoOk si existe
 *
 */
int buscarStatusFlight(eStatusFlight status[], int tamS, int id, int* pIndice);

/** \brief Valida por id que exista el estado de vuelo elegido
 *
 * \param status[] eStatusFlight Pointer to array of statusFlight
 * \param tamS int Array lenght
 * \param id int Status id
 * \return int Returns -1 si no existe el id y esValido si existe
 *
 */
int validarStatusFlight(eStatusFlight status[], int tamS, int id);

/** \brief Dispone en una lista ordenada por columnas la informacion de los estados de vuelo
 *
 * \param status[] eStatusFlight Pointer to array of statusFlight
 * \param tamS int Array lenght
 * \return int Devuelve la informacion
 *
 */
int listarStatusFlight(eStatusFlight status[], int tamS);

/** \brief Guarda la descripcion por id de los estados de vuelo
 *
 * \param status[] eStatusFlight Pointer to array of statusFlight
 * \param tamS int Array lenght
 * \param id int Status id
 * \param descripcion[] char Pointer to string of Descripcion
 * \return int Devuleve la descripcion del tipo de pasajero
 *
 */
int cargarDescripcionStatusFlight(eStatusFlight status[], int tamS, int id, char descripcion[]);
