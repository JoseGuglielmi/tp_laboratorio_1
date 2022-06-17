/*
	utest example : Unit test examples.
	Copyright (C) <2018>  <Mauricio Davila>

	This program is free software: you can redistribute it and/or modify
	it under the terms of the GNU General Public License as published by
	the Free Software Foundation, either version 3 of the License, or
	(at your salir) any later version.

	This program is distributed in the hope that it will be useful,
	but WITHOUT ANY WARRANTY; without even the implied warranty of
	MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
	GNU General Public License for more details.

	You should have received a copy of the GNU General Public License
	along with this program.  If not, see <http://www.gnu.org/licenses/>.
*/

#include <stdio.h>
#include <stdlib.h>
#include "../inc/Controller.h"
#include "../inc/Passenger.h"
#include "../testing/inc/main_test.h"
#include "../inc/LinkedList.h"

int main(void)
{
	/*startTesting(1);  // ll_newLinkedList...
	startTesting(2);  // ll_len..
	startTesting(3);  // getNode - test_getNode..
	startTesting(4);  // addNode - test_addNode..
	startTesting(5);  // ll_add...
	startTesting(6);  // ll_get...
	startTesting(7);  // ll_set...
	startTesting(8);  // ll_remove...
	startTesting(9);  // ll_clear...
	startTesting(10); // ll_deleteLinkedList...
	startTesting(11); // ll_indexOf...
	startTesting(12); // ll_isEmpty...
	startTesting(13); // ll_push...
	startTesting(14); // ll_pop...
	startTesting(15); // ll_contains...
	startTesting(16); // ll_containsAll...
	startTesting(17); // ll_subList...
	startTesting(18); // ll_clone...
	startTesting(19); // ll_sort... */

	setbuf(stdout, NULL);
	// opcion elegida por el usuario
	int salir = 0;
	int flagAux = 0;

	// la lista donde guardamos los pasajeros
	LinkedList *listaPasajeros = ll_newLinkedList();
	LinkedList *listaPasajerosAux = ll_newLinkedList();
	do
	{
		// mostramos el menu y lo llevo a l opcion que eligio el usuario
		switch (menu())
		{
		case 1:
			// carga de usuarios desde el data.csv
			controller_loadFromText("data.csv", listaPasajeros);
			// guardamos el total de pasajeros ingresados
			break;
		case 2:
			// carga de usuarios desde el data.bin
			controller_loadFromBinary("data.bin", listaPasajeros);
			// guardamos el total de pasajeros ingresados
			break;
		case 3:
			// añadimos un pasajero a la lista
			controller_addPassenger(listaPasajeros);
			break;
		case 4:
			// si hay pasajeros, le dejamos editarlos
			if (!ll_isEmpty(listaPasajeros))
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
			if (!ll_isEmpty(listaPasajeros))
			{
				// elimino al pasajero seleccionado por el usuario
				controller_removePassenger(listaPasajeros);
			}
			else
			{
				// si no hay pasajeros, no le dejo eliminar ninguno
				printf("No hay pasajeros en la lista para modificar\n");
			}

			break;
		case 6:
			if (!ll_isEmpty(listaPasajeros))
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
			if (!ll_isEmpty(listaPasajeros))
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
			if (!ll_isEmpty(listaPasajeros))
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
			if (!ll_isEmpty(listaPasajeros))
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
			// limpiamos la lista
			if (ll_clear(listaPasajeros) == 0 && ll_clear(listaPasajerosAux) == 0)
			{
				printf("Se a limpido la lista con exito\n");
				// inicializo la bandera en 0 (lista auxiliar vacia)
				flagAux = 0;
			}
			else
			{
				printf("Hubo un error al limpiar la lista\n");
			}
			break;
		case 11:
			remplazarPasajero(listaPasajeros);
			break;
		case 12:
			listaPasajerosAux = ll_clone(listaPasajeros);
			if (listaPasajerosAux != NULL)
			{
				printf("Se creo la lista auxiliar\n");
				// inicializo la bandera en 1 (lista auxiliar con datos)
				flagAux = 1;
			}

			break;
		case 13:
			// valido que halla lista auxiliar
			if (flagAux == 0)
			{
				printf("no hay datos en la lista auxiliar, cree una lista auxiliar\n");
			}
			else
			{
				// comparo las listas y informo
				if (compararListas(listaPasajeros, listaPasajerosAux, flagAux) == 1)
				{
					printf("Los datos de los pasajero (lista auxiliar) estan en la lista original\n");
				}
				else
				{
					printf("Los datos de los pasajero (lista auxiliar) no estan en la lista original\n");
				}
			}
			break;
		case 14:
			// valido que halla pasajeros en la lista
			if (!ll_isEmpty(listaPasajerosAux))
			{
				// si hay pasajeros se lo mostramos
				controller_ListPassenger(listaPasajerosAux);
			}
			else
			{
				// si no pasajeros, se lo informamos
				printf("ingrese pasajeros antes de querer mostrarlos\n");
			};
			break;
		case 15:
			// valido que halla pasajeros en la lista
			if (!ll_isEmpty(listaPasajeros))
			{
				// realizo el pop
				if (controller_Eliminar_ll_pop(listaPasajeros, listaPasajerosAux) == 1)
				{
					printf("se a eliminado correctamente y se a guardado el pasajero en la lista auxiliar\n");
					flagAux = 1;
				}
				else
				{
					printf("no se pudo realizar la eliminacion\n");
				}
			}
			break;
		case 16:
			// muestro el indice del pasajero seleccionado por el usuario
			if (controller_indice(listaPasajeros))
			{
				printf(". todo realizado correctamente\n");
			}
			else
			{
				printf("hubo un error\n");
			}
			break;
		case 17:
			// realizo el push
			if (controller_ll_push(listaPasajeros))
			{
				printf("Se a insertado el pasajero con exito\n");
			}
			else
			{
				printf("Hubo un error al hacer el push\n");
			}
			break;
		case 18:
			// elimino la listas
			ll_deleteLinkedList(listaPasajeros);
			ll_deleteLinkedList(listaPasajerosAux);
			salir = 10;
			break;
		}
		// si la opcion es 10 se sale del programa
	} while (salir != 10);

	return 0;
}
