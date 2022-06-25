#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include "ArrayPassenger.h"
#include "funciones.h"
#define LEN 2000

int main()
{
	setbuf(stdout, NULL);
    Passenger list[LEN];
    Passenger auxList;
    int exit = 1;
    int id = 1;
    int addP = 0;
    int dato;

    if (initPassengers(list, LEN))
    {
        do
        {

            switch (menu())
            {
            case 1:
                if (addPassenger(list, LEN, auxList.id, auxList.name, auxList.lastName, auxList.price, auxList.typePassenger, auxList.statusFlight, auxList.flycode, &id))
                {
                    printf("\nAlta Exitosa\n");
                    addP++;
                    system("pause");
                }
                else
                {
                    printf("Error al dar de alta\n");
                }


                break;
            case 2:
                if (addP != 0)
                {
                    if (!modifyPassenger(list, LEN, addP))
                    {

                        printf("Error al mostrar el menu de modificacion, Ingrese pasajeros\n");
                        system("pause");
                    }
                }
                else
                {
                    printf("Agrege pasajeros antes de querer modificarlos\n");
                    system("pause");
                }
                break;
            case 3:

                if (addP != 0)
                {
                    dato = removePassenger(list, LEN);
                    if (dato == 2)
                    {
                        printf("baja canselada.\n");
                        system("pause");
                    }
                    else if (dato == 1)
                    {
                        printf("baja exitosa.\n");
                        addP--;
                        system("pause");
                    }
                    else if (dato == 0)
                    {
                        printf("Error al mostrar el menu de baja pasajero.\n");
                        system("pause");
                    }
                }
                else
                {
                    printf("No puedes borrar algo que no ingresaste :/.\n");
                    system("pause");
                }

                break;
            case 4:

                passengerInfo(list, LEN, addP);
                printf("\n");
                system("pause");
                break;
            case 5:
                if (!hardcodearPasseger(list, LEN, &id, 14, &addP))
                {
                    printf("Error al dar de alta\n");
                    system("pause");
                }
                else
                {
                    printf("Alta exitosa\n");
                    system("pause");
                }
                break;
            case 6:
                exit = 0;
                break;

            default:
                printf("Opcion Incorrecta\n");
                system("pause");
                break;
            }
        } while (exit == 1);
    }
    else
    {
        printf("No se puedo inicializar la lista\n");
        system("pause");
    }

    return 0;
}
