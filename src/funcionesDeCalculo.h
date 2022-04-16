/*
 * funcionesDeCalculo.h
 *
 *  Created on: 16 abr. 2022
 *      Author: avdei
 */

#ifndef FUNCIONESDECALCULO_H_
#define FUNCIONESDECALCULO_H_



#endif /* FUNCIONESDECALCULO_H_ */

/** \brief calcula el descuento por pagar con debito
 *
 * \param
 * \param
 * \return devuleve el resultado
 *
 */
float debitoAerolineas (float* pPrecioA);


/** \brief calcula el descuento por pagar con debito
 *
 * \param
 * \param
 * \return devuleve el resultado
 *
 */
float debitoLatam (float* pPrecioL);


/** \brief calcula el aummento por pagar con credito
 *
 * \param
 * \param
 * \return devuelve el resultado
 *
 */
float creditoAerolineas (float* pPrecioA);

/** \brief calcula el aummento por pagar con credito
 *
 * \param
 * \param
 * \return devuelve el resultado
 *
 */
float creditoLatam (float* pPrecioL);


/** \brief calcula el precio del vuelo con bitcoin
 *
 * \param
 * \param
 * \return devuelve el resultado
 *
 */
float btcAerolineas (float* pPrecioBtc, float* pPrecioA);

/** \brief calcula el precio del vuelo con bitcoin
 *
 * \param
 * \param
 * \return devuelve el resultado
 *
 */
float btcLatam (float* pPrecioBtc, float* pPrecioL);


/** \brief calcula el precio unitario
 *
 * \param
 * \param
 * \return devuelve el resultado
 *
 */
float precioUnitarioA (float* pKms, float* pPrecioA);

/** \brief calcula el precio unitario
 *
 * \param
 * \param
 * \return devuelve el resultado
 *
 */
float precioUnitarioL (float* pKms, float* pPrecioL);



/** \brief calcula la diferencia de precio entre las dos aerolineas
 *
 * \param
 * \param
 * \return devuelve el resultado
 *
 */
float diferencia (float* pPrecioA, float* pPrecioL);
