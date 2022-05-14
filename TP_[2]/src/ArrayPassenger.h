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

/**
 * @brief add in a existing list of passengers the values received as parameters
* in the first empty position
 *
 * @param list passenger* passenger type structure
 * @param len int frame size
 * @param id int id to assign to the passenger
 * @param name char I keep the name
 * @param lastName char I keep the last name
 * @param price float I save the price of the flight
 * @param typePassenger int I save the type of passenger
 * @param statusFlight int save passenger status
 * @param flycode  char I save the passenger's flight code
 * @param idP int autoIncremental id to assign to the passenger
* \return int Return (-1) if Error [Invalid length or NULL pointer or without
free space] - (0) if Ok
 */
int addPassenger(Passenger* list, int len, int id, char name[],char lastName[],float price,int typePassenger,int statusFlight, char flycode[], int *idP);

/**
 * @brief I print a passenger
 *
 * @param list Passenger* passed a passenger to print
 * @return int
 */
int printPassenger(Passenger* list);

/** \brief print the content of passengers array
*
* \param list Passenger*
* \param len int frame size
* \return int Return (0) if Error [Invalid length or NULL pointer or without
free space] - (1) if Ok
*
*/
int printPassengers(Passenger *list, int len);


/**
 * @brief passenger modification menu
 *
 * @param list receives the passenger that the user chose to modify
 * @return int returns the option that you want to modify the passenger
 */
int menuMod(Passenger *list);

/**
 * @brief program main menu
 *
 * @return int returns the option entered by the user
 */
int menu();


/**
 * @brief modified the passenger based on what the user wants to modify
 *
 * @param list Passenger* I receive the list to go through in search of the passenger to modify
 * @param len int frame size
 * @param addP int which I use to check if passengers were entered
 * @return int Return (0) if Error - (1) if Ok
 */
int modifyPassenger(Passenger *list, int len, int addP);

/**
 * @brief search passenger by id
 *
 * @param list Passenger* I receive the list to go through and look for the passenger id
 * @param len int frame size
 * @param id id to assign to the passenger
 * @return int returns the position of the passenger, if it does not exist it returns -1
 */
int findPassengerById(Passenger *list, int len, int id);

/**
 * @brief I remove the passenger that the user indicated
 *
 * @param list Passenger* I receive the list to go through in search of the passenger to cancel
 * @param len int frame size
 * @return int Return (0) if Error - (1) if Ok
 */
int removePassenger(Passenger *list, int len);

/**
 * @brief menu where I show what information you want to see about the passengers
 *
 * @return int returns the option entered by the user
 */
int menuInfo();


/**
 * @brief I show the information of the passengers according to what the user wants to see
 *
 * @param list Passenger* list to go
 * @param len int frame size
 * @param addP int which I use to check if passengers were entered
 * @return int return (0) if Error - (1) if Ok
 */
int passengerInfo(Passenger *list, int len, int addP);

/**
 * @brief calculate the total of the prices of the flights and take an average, and show how many exceed the average
 *
 * @param list Passenger* list to go
 * @param len int frame size
 * @return int return (0) if Error - (1) if Ok
 */
int totalAndAveragePass(Passenger *list, int len);

/**
 * @brief ordered the passengers in alphabetical order
 *
 * @param list Passenger* list to go
 * @param len int frame size
 * @param order order in which you want to order the passengers
 * @return int return (0) if Error - (1) if Ok
 */
int sortPassengers(Passenger *list, int len, int order);

/**
 * @brief ordered passengers by flight code
 *
 * @param list Passenger* list to go
 * @param len int frame size
 * @param order order in which you want to order the passengers
 * @return int return (0) if Error - (1) if Ok
 */
int sortPassengersByCode(Passenger *list, int len, int order);

/**
 * @brief  I hardcodear the passengers
 *
 * @param list Passenger* list to save hardcoded passengers
 * @param len int frame size
 * @param id int to assign to the passenger
 * @param cantidad number of passengers to hardcodear
 * @param addP which I use to check if passengers were entered
 * @return int return (0) if Error - (1) if Ok
 */
int hardcodearPasseger(Passenger *list, int len, int *id, int cantidad, int *addP);
