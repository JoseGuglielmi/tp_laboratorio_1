#include "../inc/LinkedList.h"
#include "../inc/Passenger.h"

/**
 * @brief recorro el fichero en modo lectura y guardo sus datos en la lista
 * 
 * @param pFile recibo el fichero abierto (texto)
 * @param pArrayListPassenger la lista
 * @return int 0 mal 1 bien
 */
int parser_PassengerFromText(FILE* pFile , LinkedList* pArrayListPassenger);

/**
 * @brief recorro el fichero en modo lectura y guardo sus datos en la lista
 * 
 * @param pFile recibo el fichero abierto (bin)
 * @param pArrayListPassenger la lista
 * @return int 0 mal 1 bien
 */
int parser_PassengerFromBinary(FILE* pFile , LinkedList* pArrayListPassenger);
