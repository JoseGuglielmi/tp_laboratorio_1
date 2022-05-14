#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include "funciones.h"

typedef struct{
int id;
char name[51];
char lastName[51];
float price;
char flycode[10];
int typePassenger;
int statusFlight;
int isEmpty;
}Passenger;

/** \brief To indicate that all position in the array are empty,
* this function put the flag (isEmpty) in TRUE in all
* position of the array
* \param list Passenger* Pointer to array of passenger
* \param len int Array length
* \return int Return (-1) if Error [Invalid length or NULL pointer] - (0) if Ok
*
*/
int initPassengers(Passenger* list, int len);

int findPassenger(Passenger* list, int len);

/** \brief add in a existing list of passengers the values received as parameters
* in the first empty position
* \param list passenger*
* \param len int
* \param id int
* \param name[] char
* \param lastName[] char
* \param price float
* \param typePassenger int
* \param flycode[] char
* \return int Return (-1) if Error [Invalid length or NULL pointer or without
free space] - (0) if Ok
*/
int addPassenger(Passenger* list, int len, int id, char name[],char lastName[],float price,int typePassenger,int statusFlight, char flycode[], int *idP);

/** \brief print the content of passengers array
*
* \param list Passenger*
* \param length int
* \return int
*
*/
int printPassenger(Passenger* list);

int printPassengers(Passenger *list, int len);

int menuMod(Passenger *list);

int menu();

int modifyPassenger(Passenger *list, int len, int addP);

int findPassengerById(Passenger *list, int len, int id);

int removePassenger(Passenger *list, int len);

int menuInfo();

int passengerInfo(Passenger *list, int len, int addP);

int totalAndAveragePass(Passenger *list, int len);

int sortPassengers(Passenger *list, int len, int order);

int sortPassengersByCode(Passenger *list, int len, int order);

int hardcodearPasseger(Passenger *list, int len, int *id, int cantidad, int *addP);
