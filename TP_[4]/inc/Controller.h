
#include "../inc/Passenger.h"
#include "../inc/LinkedList.h"
#include "../inc/parser.h"

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
 * @brief remplazo un pasajero por otro
 * 
 * @param pArrayListPassenger lista de pasajeros
 * @return int 0 mal 1 todoOK
 */
int remplazarPasajero(LinkedList *pArrayListPassenger);

/**
 * @brief creo un pasajero y lo retorno
 * 
 * @param pArrayListPassenger lista de pasajeros
 * @return Passenger* devuelvo el pasajero nuevo
 */
Passenger *Controller_PasajeroNuevo(LinkedList *pArrayListPassenger);

/**
 * @brief compara la lista1 con la lista2 (si coinciden los datos de la lista1 con la lista2)
 * 
 * @param lista1 lista original (lista1)
 * @param lista2 lista auxiliar (lista2)
 * @param flag2 bandera para saber si hay una lista creada(o que contiene datos)
 * @return int 0 mal 1 todoOK
 */
int compararListas(LinkedList *lista1, LinkedList *lista2, int flag2);

/**
 * @brief elimino un pasajero por el indice y lo guardo en una lista auxiliar
 * 
 * @param this lista original (this)
 * @param this2 lista auxiliar (this2)
 * @return int 0 mal 1 todoOK
 */
int controller_Eliminar_ll_pop(LinkedList *this, LinkedList *this2);

/**
 * @brief pido un id y le digo su indice
 * 
 * @param this lista donde estan guardado los pasajeros
 * @return int 0 mal 1 todoOK
 */
int controller_indice(LinkedList *this);

/**
 * @brief inserto un elemento (pasajero) en el indice que el usuario elija
 * 
 * @param this lista donde estan guardado los pasajeros
 * @return int 0 mal 1 todoOK
 */
int controller_ll_push(LinkedList *this);

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
