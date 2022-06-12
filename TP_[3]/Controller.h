
#include "Passenger.h"
#include "LinkedList.h"
#include "parser.h"

/**
 * @brief generamos un id segun el ultimo pasajero ingresado ej: pasajero id =10, devuelve 11
 * 
 * @param pArrayListPassenger la lista
 * @param id el id 
 * @return int retorna el ultimo id +1 ej: ultimoId = 10, retorna 11
 */
int controller_gestionId(LinkedList *pArrayListPassenger, int id);

/**
 * @brief traemos los pasajeros del archivo.csv a la lista
 * 
 * @param path nombre del archivo.csv
 * @param pArrayListPassenger lista
 * @return int 0 mal 1 todoOK
 */
int controller_loadFromText(char* path , LinkedList* pArrayListPassenger);

/**
 * @brief traemos los pasajeros del archivo.bin a la lista
 * 
 * @param path nombre del archivo.bin
 * @param pArrayListPassenger lista
 * @return int 0 mal 1 todoOK
 */
int controller_loadFromBinary(char* path , LinkedList* pArrayListPassenger);

/**
 * @brief añadimos un pasajero a la lista
 * 
 * @param pArrayListPassenger lista
 * @return int 0 mal 1 todoOK
 */
int controller_addPassenger(LinkedList* pArrayListPassenger);

/**
 * @brief editamos un pasajero de la lista
 * 
 * @param pArrayListPassenger lista
 * @return int 0 mal 1 todoOK
 */
int controller_editPassenger(LinkedList* pArrayListPassenger);

/**
 * @brief removemos un pasajero de la lista
 * 
 * @param pArrayListPassenger lista
 * @return int 0 mal 1 todoOK
 */
int controller_removePassenger(LinkedList* pArrayListPassenger);

/**
 * @brief listamos todos los pasajeros de la lista
 * 
 * @param pArrayListPassenger lista
 * @return int 0 mal 1 todoOK
 */
int controller_ListPassenger(LinkedList* pArrayListPassenger);

/**
 * @brief ordenamos la lista segun el usuario quiera
 * 
 * @param pArrayListPassenger lista
 * @return int 0 mal 1 todoOK
 */
int controller_sortPassenger(LinkedList* pArrayListPassenger);

/**
 * @brief guardamos los datos de la lista en un archivo.csv
 * 
 * @param path nombre del archivo.csv
 * @param pArrayListPassenger  lista
 * @return int 0 mal 1 todoOK
 */
int controller_saveAsText(char* path , LinkedList* pArrayListPassenger);

/**
 * @brief guardamos los datos de la lista en un archivo.bin
 * 
 * @param path nombre del archivo.bin
 * @param pArrayListPassenger  lista
 * @return int 0 mal 1 todoOK
 */
int controller_saveAsBinary(char* path , LinkedList* pArrayListPassenger);

/**
 * @brief mostramos un pasajero
 * 
 * @param pasajero a mostrar
 * @return int 0 mal 1 todoOK
 */
int controller_showPassenger(Passenger* pasajero);

/**
 * @brief menu principal
 * 
 * @return int opcion elegida
 */
int menu();

/**
 * @brief menu de edicion
 * 
 * @return int opcion elegida
 */
int menuEdit();

/**
 * @brief menu de ordenamiento
 * 
 * @return int opcion elegida
 */
int menuSort();

//criterio de ordenamiento:
int controller_SortId(void* pasajero1, void* pasajero2);//por id
int controller_SortNombre(void* nombre1, void* nombre2);//por nombre
int controller_SortApellido(void* pasajero1, void* pasajero2);//por apellido
int controller_SortPrecio(void* pasajero1, void* pasajero2);//por precio
int controller_SortTipo(void* pasajero1, void* pasajero2);//por tipo de pasajero
int controller_SortCodigo(void* pasajero1, void* pasajero2);//por codigo de vuelo
int controller_SortEstado(void* pasajero1, void* pasajero2);//por estado de vuelo
