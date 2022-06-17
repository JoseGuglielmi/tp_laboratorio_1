/*
 * Passenger.h
 *
 *  Created on: 19 may. 2022
 *
 */


#include "../inc/library.h"
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

#ifndef PASSENGER_H_
#define PASSENGER_H_

//estructura de pasajeros
typedef struct
{
    int id;
    char nombre[50];
    char apellido[50];
    float precio;
    char codigoDeVuelo[8];
    char tipoPasajero[50];
    char estadoDeVuelo[50];
}Passenger;

/**
 * @brief generamos un pasajero dinamico
 * 
 * @return Passenger* retorna el pasajero dinamico
 */
Passenger* Passenger_new();

/**
 * @brief guardamos datos de un pasajero por parametros
 * 
 * @param id de del pasajero
 * @param nombre del pasajero
 * @param apellido del pasajero
 * @param precio del vuelo
 * @param codigoDeVuelo del pasajero
 * @param tipoPasajero 
 * @param estadoDeVuelo del pasajero
 * @return Passenger* 
 */
Passenger* Passenger_newParametros(int id,char* nombre,char* apellido, char* precio , char* codigoDeVuelo, char* tipoPasajero,char* estadoDeVuelo);

/**
 * @brief eliminamos un pasajero
 * 
 * @param this pasajero a eliminar
 */
void Passenger_delete(Passenger* this);

/**
 * @brief asignamos id
 * 
 * @param this pasajero
 * @param id a guardar del pasajero
 * @return int 0 mal 1 bien
 */
int Passenger_setId(Passenger* this,int id);
/**
 * @brief optenemos los datos del pasajero
 * 
 * @param this pasjero que queremos sabre su info
 * @param id donde pasamos el id del pasajero
 * @return int 0 mal 1 bien
 */
int Passenger_getId(Passenger* this,int* id);

/**
 * @brief asignamos un nombre
 * 
 * @param this pasajero
 * @param nombre a guardar del pasajero
 * @return int 0 mal 1 bien
 */
int Passenger_setNombre(Passenger* this,char* nombre);
/**
 * @brief optenemos los datos del pasajero
 * 
 * @param this pasjero que queremos sabre su info
 * @param nombre donde pasamos el nombre del pasajero
 * @return int 0 mal 1 bien
 */
int Passenger_getNombre(Passenger* this,char* nombre);

/**
 * @brief asignamos un apellido
 * 
 * @param this pasajero
 * @param apellido a guardar del pasajero
 * @return int 0 mal 1 bien
 */
int Passenger_setApellido(Passenger* this,char* apellido);
/**
 * @brief optenemos los datos del pasajero
 * 
 * @param this pasjero que queremos sabre su info
 * @param apellido donde pasamos el apellido del pasajero
 * @return int 0 mal 1 bien
 */
int Passenger_getApellido(Passenger* this,char* apellido);

/**
 * @brief asignamos un precio
 * 
 * @param this pasajero
 * @param precio a guardar del pasajero
 * @return int 0 mal 1 bien
 */
int Passenger_setPrecio(Passenger* this, float precio);
/**
 * @brief optenemos los datos del pasajero
 * 
 * @param this pasjero que queremos sabre su info
 * @param precio donde pasamos el precio del pasajero
 * @return int 0 mal 1 bien
 */
int Passenger_getPrecio(Passenger* this,float* precio);

/**
 * @brief asignamos un codigo de vuelo
 * 
 * @param this pasajero
 * @param codigoVuelo a guardar del pasajero
 * @return int 0 mal 1 bien
 */
int Passenger_setCodigoVuelo(Passenger* this,char* codigoVuelo);
/**
 * @brief optenemos los datos del pasajero
 * 
 * @param this pasjero que queremos sabre su info
 * @param codigoVuelo donde pasamos el codigo de vuelo del pasajero
 * @return int 0 mal 1 bien
 */
int Passenger_getCodigoVuelo(Passenger* this,char* codigoVuelo);

/**
 * @brief asignamos un tipo de pasajero
 * 
 * @param this pasajero
 * @param tipoPasajero a guardar del pasajero
 * @return int 0 mal 1 bien
 */
int Passenger_setTipoPasajero(Passenger* this,char* tipoPasajero);
int Passenger_getTipoPasajero(Passenger* this,char* tipoPasajero);

/**
 * @brief asignamos un nombre
 * 
 * @param this pasajero
 * @param estadoDeVuelo del pasajero
 * @return int 0 mal 1 bien
 */
int Passenger_setEstadoDeVuelo(Passenger *this, char *estadoDeVuelo);
/**
 * @brief optenemos los datos del pasajero
 * 
 * @param this pasjero que queremos sabre su info
 * @param estadoDeVuelo donde pasamos el estado de vuelo del pasajero
 * @return int 0 mal 1 bien
 */
int Passenger_getEstadoDeVuelo(Passenger *this, char *estadoDeVuelo);


#endif /* PASSENGER_H_ */
