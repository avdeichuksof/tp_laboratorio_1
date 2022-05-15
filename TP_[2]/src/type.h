/*
 * type.h
 *
 *  Created on: 14 may. 2022
 *      Author: avdei
 */

#ifndef TYPE_H_
#define TYPE_H_

struct
{
    int id;
    char descripcion[20];
    int isEmpty;
}typedef  eTypePassenger;

#endif /* TYPE_H_ */

/** \brief busca el tipo de pasajero elegido por id
 *
 * \param type[] eTypePassenger Pointer to array of typePassenger
 * \param tamT int Array lenght
 * \param id int TypePassenger id
 * \param pIndice int* Pointer to index
 * \return int Returns -1 si no existe el id y todoOk si existe
 *
 */
int buscarTypePassenger(eTypePassenger type[], int tamT, int id, int* pIndice);

/** \brief Valida por id que exista el tipo de pasajero elegido
 *
 * \param type[] eTypePassenger Pointer to array of typePassenger
 * \param tamT int Array lenght
 * \param id int TypePassenger id
 * \return int Returns -1 si no existe el id y esValido si existe
 *
 */
int validarTypePassenger(eTypePassenger type[], int tamT, int id);

/** \brief Dispone en una lista ordenada por columnas la informacion de los tipos de pasajeros
 *
 * \param type[] eTypePassenger Pointer to array of typePassenger
 * \param tamT int Array lenght
 * \return int Devuelve la informacion
 *
 */
int listarTypePassenger(eTypePassenger type[], int tamT);

/** \brief Guarda la descripcion por id de los tipos de pasajeros
 *
 * \param type[] eTypePassenger Pointer to array of typePassenger
 * \param tamT int Array lenght
 * \param id int TypePassenger id
 * \param descripcion[] char Pointer to string Descripcion
 * \return int Devuleve la descripcion del tipo de pasajero
 *
 */
int cargarDescripcionTypePassenger(eTypePassenger type[], int tamT, int id, char descripcion[]);
