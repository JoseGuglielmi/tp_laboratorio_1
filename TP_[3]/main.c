#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "Controller.h"
#include "Passenger.h"

/****************************************************
    Menu:
     1. Cargar los datos de los pasajeros desde el archivo data.csv (modo texto).
     2. Cargar los datos de los pasajeros desde el archivo data.csv (modo binario).
     3. Alta de pasajero
     4. Modificar datos de pasajero
     5. Baja de pasajero
     6. Listar pasajeros
     7. Ordenar pasajeros
     8. Guardar los datos de los pasajeros en el archivo data.csv (modo texto).
     9. Guardar los datos de los pasajeros en el archivo data.csv (modo binario).
    10. Salir
*****************************************************/

int main()
{

    setbuf(stdout, NULL);
    // cantidad de pasajeros
    int addP = 0;
    // opcion elegida por el usuario
    int option = 0;

    // la lista donde guardamos los pasajeros
    LinkedList *listaPasajeros = ll_newLinkedList();
    do
    {
        // mostramos el menu y lo llevo a l opcion que eligio el usuario
        switch (menu())
        {
        case 1:
            // carga de usuarios desde el data.csv
            controller_loadFromText("data.csv", listaPasajeros);
            // guardamos el total de pasajeros ingresados
            addP = ll_len(listaPasajeros);
            break;
        case 2:
            // carga de usuarios desde el data.bin
            controller_loadFromBinary("data.bin", listaPasajeros);
            // guardamos el total de pasajeros ingresados
            addP = ll_len(listaPasajeros);
            break;
        case 3:
            // añadimos un pasajero a la lista
            controller_addPassenger(listaPasajeros);
            // sumamos un pasajero
            addP++;
            break;
        case 4:
            // si hay pasajeros, le dejamos editarlos
            if (addP)
            {
                if (controller_editPassenger(listaPasajeros))
                {
                    // si se edito con exito, se lo informamos
                    printf("Los datos fueron modificados con exito\n");
                }
                else
                {
                    // si no se edito con exito, se lo informamos
                    printf("Los datos no se pudieron modificar con exito\n");
                }
            }
            else
            {
                // si no hay pasajeros, no le dejamos editarlos
                printf("No hay pasajeros en la lista para modificar\n");
            }
            break;
        case 5:
            // si hay pasajeros, le dejamos eliminar
            if (addP)
            {
                // elimino al pasajero seleccionado por el usuario
                controller_removePassenger(listaPasajeros);
                // resto uno a la cantidad de pasajeros
                addP--;
            }
            else
            {
                // si no hay pasajeros, no le dejo eliminar ninguno
                printf("No hay pasajeros en la lista para modificar\n");
            }

            break;
        case 6:
            if (addP)
            {
                // si hay pasajeros se lo mostramos
                controller_ListPassenger(listaPasajeros);
            }
            else
            {
                // si no pasajeros, se lo informamos
                printf("ingrese pasajeros antes de querer mostrarlos\n");
            };
            break;
        case 7:
            // si hay pasajeros, le dejamos ordenarlos
            if (addP)
            {
                // lo llebamos al menu de opciones donde ordenara la lista como quiera el usuario
                controller_sortPassenger(listaPasajeros);
            }
            else
            {
                // si no hay pasajeros, no le dejamos ordenarlos
                printf("No hay pasajeros en la lista para ordenar\n");
            }

            break;
        case 8:
            // si hay pasajeros, le dejamos guardarlo en un data.csv
            if (addP)
            {
                // guardamos la lista en un archivo .csv
                if (controller_saveAsText("data.csv", listaPasajeros))
                {
                    printf("se guardaron los datos correctamente\n");
                }
                else
                {
                    printf("Error al guardar los datos\n");
                }
            }
            else
            {
                // si no hay pasajeros, no le dejo guardarlo
                printf("No hay pasajeros en la lista para guardar\n");
            }

            break;
        case 9:
            // si hay pasajeros, le dejamos guardarlo en un data.bin
            if (addP)
            {
                // guardamos la lista en un archivo .bin
                if (controller_saveAsBinary("data.bin", listaPasajeros))
                {
                    printf("se guardaron los datos correctamente\n");
                }
                else
                {
                    printf("Error al guardar los datos\n");
                }
            }
            else
            {
                // si no hay pasajeros, no le dejo guardarlo
                printf("No hay pasajeros en la lista para guardar\n");
            }
            break;
        case 10:
            option = 10;
            break;
        }
        // si la opcion es 10 se sale del programa
    } while (option != 10);
    return 0;
}
