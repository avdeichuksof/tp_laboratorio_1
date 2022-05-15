/*
 * arrayPassengers.h
 *
 *  Created on: 14 may. 2022
 *      Author: avdei
 */

#ifndef ARRAYPASSENGERS_H_
#define ARRAYPASSENGERS_H_

#include "type.h"
#include "status.h"

typedef struct
{
    int id;
    char name[51];
    char lastName[51];
    float price;
    char flyCode[10];
    int typePassenger;
    int statusFlight;
    int isEmpty;
}Passenger;

#endif /* ARRAYPASSENGERS_H_ */


/** \brief To indicate that all positions in the array are empty,
*          this function puts the flag (isEmpty) in TRUE in all
*          position of the array
* \param lista[] Passenger Pointer to array of passenger
* \param len int Array length
* \return int Return (-1) if Error [Invalid length or NULL pointer] - (0) if Ok
*
*/
int initPassengers(Passenger lista[], int len);


/** \brief adds in an existing list of passengers the values received as parameters
 *         in the first empty position
 *
 * \param lista[] Passenger Pointer to array of passenger
 * \param len int Array lenght
 * \param id int Passenger id
 * \param name[] char Passenger name
 * \param lastName[] char Passenger last name
 * \param price float Flight price
 * \param typePassenger int Passenger type class
 * \param flycode[] char Codigo de vuelo
 * \param type[] eTypePassenger Pointer to array of type passenger
 * \param tamT int Array lenght
 * \param status[] eStatusFlight Pointer to array of status flight
 * \param tamS int Array lenght
 * \return intReturn (-1) if Error [Invalid length or NULL pointer or without
 *         free space] - (0) if Ok
 *
 */
int addPassenger(Passenger lista[], int len, int* pId, char name[],char lastName[], float price,int typePassenger, char flycode[], eTypePassenger type[], int tamT, eStatusFlight status[], int tamS);


/** \brief find a Passenger by Id and returns the index position in array.
*
* \param lista[] Passenger Pointer to array of passenger
* \param len int Array lenght
* \param id int Passenger id
* \param pIndice int* Pointer to index
* \return Return passenger index position or (-1) if [Invalid length or
*         NULL pointer received or passenger not found]
*
*/
int findPassengerById(Passenger lista[], int len, int id, int* pIndice);


/** \brief Removes a Passenger by Id (put isEmpty Flag in 1)
*
* \param lista[] Passenger Pointer to array of passenger
* \param len int Array lenght
* \param id int Passenger id
* \param type[] eTypePassenger Pointer to array of type passenger
* \param tamT int Array lenght
* \param status[] eStatusFlight Pointer to array of status flight
* \param tamS int Array lenght
* \return int Return (-1) if Error [Invalid length or NULL pointer or if can't
*         find a passenger] - (0) if Ok
*
*/
int removePassenger(Passenger lista[], int len, int id, eTypePassenger type[], int tamT, eStatusFlight status[], int tamS);


/** \brief prints the content of passengers array
 *
 * \param lista[] Passenger Pointer to array of passenger
 * \param len int Array lenght
 * \param type[] eTypePassenger Pointer to array of type passenger
 * \param tamT int Array lenght
 * \param status[] eStatusFlight Pointer to array of status flight
 * \param tamS int Array lenght
 * \return int Returns passenger info
 *
 */
int printPassenger(Passenger lista[], int len, eTypePassenger type[], int tamT, eStatusFlight status[], int tamS);


/** \brief Sorts the elements in the array of passengers, the argument order
           indicates UP or DOWN order
*
* \param lista[] Passenger Pointer to array of passenger
* \param len int Array lenght
* \param order int [1] indicate UP - [0] indicate DOWN
* \return int Return (-1) if Error [Invalid length or NULL pointer] - (0) if Ok
*
*/
int sortPassengers(Passenger lista[], int len, int order);


/** \brief Sorts the elements in the array of passengers, the argument order
           indicates UP or DOWN order
*
* \param lista[] Passenger Pointer to array of passenger
* \param len int Array lenght
* \param order int [1] indicate UP - [0] indicate DOWN
* \return int Return (-1) if Error [Invalid length or NULL pointer] - (0) if Ok
*
*/
int sortPassengersByCodeStatus(Passenger lista[], int len, int order);


/** \brief Muestra un menu donde se elige que informacion del pasajero se va a modificar
 *
 * \param lista[] Passenger Pointer to array of passenger
 * \param len int Array lenght
 * \param id int Recibe el id del pasajero para poder buscarlo facilmente
 * \param type[] eTypePassenger Pointer to array of type passenger
 * \param tamT int Array lenght
 * \param status[] eStatusFlight Pointer to array of status flight
 * \param tamS int Array lenght
 * \return int Returns modified info
 *
 */
int modifyPassengers(Passenger lista[], int len, eTypePassenger type[], int tamT, eStatusFlight status[], int tamS);
