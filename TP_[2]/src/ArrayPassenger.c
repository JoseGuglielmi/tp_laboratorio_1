#include "ArrayPassenger.h"

int menu()
{
    int opcion;

    printf("*** MENU ***\n\n");

    printf("1-Altas\n");
    printf("2-Modificar\n");
    printf("3-Baja\n");
    printf("4-Informar\n");
    printf("5-Alta Forzada de pasajero\n");
    printf("6-Salir\n\n");
    requestDataNumInt("Ingrese una opcion: ", "Error. Ingrese un numero: ", &opcion, 1, 100);
    return opcion;
}

int initPassengers(Passenger *list, int len)
{
    int todoOk = -1;

    if (list != NULL && len >= 0)
    {
        for (int i = 0; i < len; i++)
        {
            list[i].isEmpty = 0;
        }
        todoOk = 1;
    }
    return todoOk;
}

int findPassenger(Passenger *list, int len)
{
    int position = -1;

    if (list != NULL && len >= 0)
    {
        for (int i = 0; i < len; i++)
        {
            if (list[i].isEmpty == 0)
            {
                position = i;
                break;
            }
        }
    }

    return position;
}

int addPassenger(Passenger *list, int len, int id, char name[], char lastName[], float price, int typePassenger, int statusFlight, char flycode[], int *idP)
{
    int todoOk = 0;
    int index;

    if (list != NULL && idP != NULL)
    {

        index = findPassenger(list, len);
        if (index == -1)
        {
            printf("No hay espacio en la lista\n");
            system("pause");
        }
        else
        {

            requestDataTex("Ingrese su nombre: ", "Error. Ingrese un nombre valido: ", name, 51);
            ordenarStrings(list[index].name);

            requestDataTex("Ingrese su Apellido:  ", "Error. Ingrese un Apellido valido: ", lastName, 51);
            ordenarStrings(list[index].lastName);

            requestDataNumFloat("Ingrese Precio del vuelo: ", "Error. ReIngrese el precio: ", &price, 0, 100000000);

            printf("ingrese codigo de vuelo: ");
            fflush(stdin);
            fgets(flycode, 10, stdin);
            removeBarN(flycode);

            requestDataNumInt("Ingrese el tipo de pasajero 1-Primera clase 2-business 3-turista: ", "Error. ReIngrese el tipo de pasajero 1-Primera clase 2-business 3-turista: ", &typePassenger, 1, 3);

            requestDataNumInt("Ingrese su estado de vuelo: 1-activo 2-demorado 3-cancelado: ", "Error. ReIngrese su estado de vuelo: 1-activo 2-demorado 3-cancelado: ", &statusFlight, 1, 3);

            id = *idP;
            *idP = *idP + 1;

            strcpy(list[index].name, name);
            strcpy(list[index].lastName, lastName);
            strcpy(list[index].flycode, flycode);

            list[index].price = price;
            list[index].statusFlight = statusFlight;
            list[index].typePassenger = typePassenger;
            list[index].id = id;
            list[index].isEmpty = 1;

            todoOk = 1;
            printf("                                            |Nuevo Pasajero|\n");
            printf("\n ID  Nombre               Apellido             Codigo de vuelo   Tipo de pasajero   Estado del vuelo   Precio\n");
            printPassenger(list + index);

            todoOk = 1;
        }
    }

    return todoOk;
}

int printPassenger(Passenger *list)
{
    int todoOk = 0;
    char name[50];
    char lastN[50];
    char flyC[50];

    if (list != NULL)
    {

        strcpy(name, addSpaces(list->name, 20));
        strcpy(lastN, addSpaces(list->lastName, 20));
        strcpy(flyC, addSpaces(list->flycode, 10));

        if (list->typePassenger == 1 && list->statusFlight == 1)
        {
            printf("%04d %s%s%s       %s            %s             %.5f\n", list->id, name, lastN, flyC, "Premium", "activo", list->price);
        }
        else if (list->typePassenger == 1 && list->statusFlight == 2)
        {
            printf("%04d %s%s%s       %s            %s           %.5f\n", list->id, name, lastN, list->flycode, "Premium", "demorado", list->price);
        }
        else if (list->typePassenger == 1 && list->statusFlight == 3)
        {
            printf("%04d %s%s%s       %s            %s          %.5f\n", list->id, name, lastN, list->flycode, "Premium", "cancelado", list->price);
        }
        else if (list->typePassenger == 2 && list->statusFlight == 1)
        {
            printf("%04d %s%s%s       %s           %s             %.5f\n", list->id, name, lastN, list->flycode, "business", "activo", list->price);
        }
        else if (list->typePassenger == 2 && list->statusFlight == 2)
        {
            printf("%04d %s%s%s       %s           %s           %.5f\n", list->id, name, lastN, list->flycode, "business", "demorado", list->price);
        }
        else if (list->typePassenger == 2 && list->statusFlight == 3)
        {
            printf("%04d %s%s%s       %s           %s          %.5f\n", list->id, name, lastN, list->flycode, "business", "cancelado", list->price);
        }
        else if (list->typePassenger == 3 && list->statusFlight == 1)
        {
            printf("%04d %s%s%s       %s            %s             %.5f\n", list->id, name, lastN, list->flycode, "turista", "activo", list->price);
        }
        else if (list->typePassenger == 3 && list->statusFlight == 2)
        {
            printf("%04d %s%s%s       %s            %s           %.5f\n", list->id, name, lastN, list->flycode, "turista", "demorado", list->price);
        }
        else if (list->typePassenger == 3 && list->statusFlight == 3)
        {
            printf("%04d %s%s%s       %s            %s          %.5f\n", list->id, name, lastN, list->flycode, "turista", "cancelado", list->price);
        }
        todoOk = 1;
    }
    else
    {
        printf("Error al mostrar\n");
    }

    return todoOk;
}

int printPassengers(Passenger *list, int len)
{
    int todoOk = 0;

    if (list != NULL && len >= 0)
    {
        printf("                                              |Lista de pasajeros|\n");
        printf("\n ID  Nombre               Apellido             Codigo de vuelo   Tipo de pasajero   Estado del vuelo   Precio\n");

        for (int i = 0; i <= len && (list + i)->isEmpty == 1; i++)
        {
            printPassenger(list + i);
        }
        todoOk = 1;
    }
    return todoOk;
}

int menuMod(Passenger *list)
{
    int opcion;
    printf("                                            *** MENU de modificacion ***\n\n");

    printf(" ID  Nombre               Apellido             Codigo de vuelo   Tipo de pasajero   Estado del vuelo   Precio\n");
    printPassenger(list);

    printf("\n1-Modificar Nombre\n");
    printf("2-Modificar Apellido\n");
    printf("3-Modificar Precio\n");
    printf("4-Modificar Codigo de Vuelo\n");
    printf("5-Modificar Tipo de pasajero\n");
    printf("6-Modificar Estado de vuelo\n");
    printf("7-Volver al menu principal\n\n");

    requestDataNumInt("Ingrese una opcion: ", "Error. ReIngrese una opcion: ", &opcion, 0, 100);

    return opcion;
}

int modifyPassenger(Passenger *list, int len, int addP)
{
    int todoOk = 0;
    int id = 0;
    int index;
    int exit = 0;


    if (addP != 0)
    {
        if (!printPassengers(list, len))
        {

            printf("Hubo un error al mostrar los pasajeros\n");
        }
        else
        {
            if (!requestDataNumInt("Ingrese el id que desea modificar: ", "Error. ReIngrese un id correcto:", &id, 0, 2000))
            {
                printf("Error al pedir los datos.\n");
            }
            else
            {
                index = findPassengerById(list, len, id);
                while (index == -1)
                {
                    requestDataNumInt("Error al encontrar el id, ReIngrese: ", "Error al encontrar el id, ReIngrese: ", &id, 0, 2000);
                    index = findPassengerById(list, len, id);
                    todoOk = 1;
                }
                do
                {
                    switch (menuMod(list + index))
                    {
                    case 1:
                        requestDataTex("Ingrese su nombre: ", "Error. Ingrese un nombre valido: ", list[index].name, 51);
                        ordenarStrings(list[index].name);
                        break;
                    case 2:
                        requestDataTex("Ingrese su apellido: ", "Error. Ingrese un apellido valido: ", list[index].lastName, 51);
                        ordenarStrings(list[index].lastName);
                        break;
                    case 3:
                        requestDataNumFloat("Ingrese Precio del vuelo: ", "Error. ReIngrese el precio: ", &(list + index)->price, 0, 100000000);
                        break;
                    case 4:
                        printf("ingrese codigo de vuelo: ");
                        fflush(stdin);
                        fgets(list[index].flycode, 10, stdin);
                        removeBarN(list[index].flycode);
                        break;
                    case 5:
                        requestDataNumInt("Ingrese el tipo de pasajero 1-Primera clase 2-business 3-turista: ", "Error. ReIngrese el tipo de pasajero 1-Primera clase 2-business 3-turista: ", &(list + index)->typePassenger, 0, 3);
                        break;
                    case 6:
                        requestDataNumInt("Ingrese su estado de vuelo: 1-activo 2-demorado 3-cancelado: ", "Error. ReIngrese su estado de vuelo: 1-activo 2-demorado 3-cancelado: ", &(list + index)->statusFlight, 0, 3);
                        break;
                    case 7:
                        exit = 1;
                        todoOk = 1;
                        break;
                    default:
                        printf("Opcion invalida ReIngrese\n");
                        system("pause");
                        break;
                    }
                } while (exit == 0);
            }
        }
    }

    return todoOk;
}

int removePassenger(Passenger *list, int len)
{
    int todoOk = 0;
    int id = 0;
    int index = -1;
    int a;

    if (!printPassengers(list, len))
    {
        printf("Hubo un error al mostrar los pasajeros\n");
    }
    else
    {
        if (!requestDataNumInt("Ingrese el id del pasajero que desea borrar: ", "Error. ReIngrese un id correcto:", &id, 0, 2000))
        {
            printf("Error al pedir los datos.\n");
        }
        else
        {
            index = findPassengerById(list, len, id);
            while (index == -1)
            {
                requestDataNumInt("Error al encontrar el id, ReIngrese id: ", "Error al encontrar el id, ReIngrese id: ", &id, 0, 2000);
                index = findPassengerById(list, len, id);
                todoOk = 1;
            }
            printPassenger(list + index);
            requestDataNumInt("Desea eliminarlo? 1 para si 2 para no: ", "Error. Desea eliminarlo? 1 para si 2 para no: ", &a, 1, 2);
            if (a == 1)
            {
                list[index].isEmpty = 0;
                todoOk = 1;
            }
            else
            {
                todoOk = 2;
            }
        }
    }

    return todoOk;
}

int findPassengerById(Passenger *list, int len, int id)
{
    int index = 0;

    for (int i = 0; i <= len; i++)
    {
        if (list[i].id == id && list[i].isEmpty == 1)
        {
            index = i;
            break;
        }
        else
            index = -1;
    }

    return index;
}
// poner en el .h
int menuInfo()
{
    int opcion;

    printf("                        *** MENU DE INFORMACION ***\n\n");

    printf("1-Ordenados alfabeticamente por Apellido y Tipo de pasajero.\n");
    printf("2-Total y promedio de los precios de los pasajes, y cuantos pasajeros superan el precio promedio.\n");
    printf("3-Listado de los pasajeros por Codigo de vuelo y estados de vuelos(ACTIVO).\n");
    printf("4-Volver al menu principal\n\n");

    requestDataNumInt("Ingrese una opcion: ", "Error. ReIngrese una opcion: ", &opcion, 0, 100);

    return opcion;
}

int passengerInfo(Passenger *list, int len, int addP)
{
    int todoOk = 0;
    int exit = 1;

    if (addP != 0)
    {
        do
        {
            switch (menuInfo())
            {
            case 1:
                if (!sortPassengers(list, len, 1))
                {
                    printf("hubo un error al ordenar a los pasajeros\n");
                }
                else
                {
                    printPassengers(list, len);
                }
                system("pause");
                break;
            case 2:
                totalAndAveragePass(list, len);
                break;
            case 3:
                if (!sortPassengersByCode(list, len, 1))
                {
                    printf("hubo un error al ordenar a los pasajeros\n");
                }
                system("pause");
                break;
            case 4:
                exit = 0;
                break;

            default:
                printf("Opcion incorrecta\n");
                system("pause");
                break;
            }
        } while (exit == 1);
    }
    else
        printf("Ingrese pasajeros antes de usar esta opcion\n");

    return todoOk;
}

int totalAndAveragePass(Passenger *list, int len)
{
    int todoOk = 0;
    float totalPrices = 0;
    float average = 0;
    int passengerAverage = 0;
    int passengerCounter = 0;

    printf("*Precios*\n");
    for (int i = 0; i <= len; i++)
    {
        if (list[i].isEmpty == 1)
        {
            printf("%.5f    \n", list[i].price);
            totalPrices = totalPrices + list[i].price;
            passengerCounter++;
        }
    }
    average = totalPrices / passengerCounter;

    for (int i = 0; i <= len; i++)
    {
        if (list[i].isEmpty == 1 && list[i].price >= average)
        {
            passengerAverage++;
        }
    }

    printf("\nEl total de los Precios ingresados es de: %.5f\n", totalPrices);
    printf("El Promedio de los Precios es de: %.6f\n", average);
    printf("Total de pasajeros que superan el precio promero: %d\n", passengerAverage);
    system("pause");

    return todoOk;
}

int sortPassengers(Passenger *list, int len, int order)
{
    int todoOk = 0;
    Passenger auxList;

    if (order == 1)
    {
        for (int i = 0; i <= len; i++)
        {
            for (int j = i + 1; j <= len; j++)
            {
                if (strcmp(list[i].lastName, list[j].lastName) > 0 && list[i].isEmpty == 1 && list[j].isEmpty == 1)
                {
                    auxList = list[i];
                    list[i] = list[j];
                    list[j] = auxList;
                }
            }
            todoOk = 1;
        }

        for (int i = 0; i <= len; i++)
        {
            for (int j = i + 1; j <= len; j++)
            {
                if (list[i].typePassenger > list[j].typePassenger && list[i].isEmpty == 1 && list[j].isEmpty == 1)
                {
                    auxList = list[i];
                    list[i] = list[j];
                    list[j] = auxList;
                }
            }
            todoOk = 1;
        }
    }
    else if (order == 2)
    {
        for (int i = 0; i <= len; i++)
        {
            for (int j = i + 1; j <= len; j++)
            {
                if (strcmp(list[i].lastName, list[j].lastName) < 0 && list[i].isEmpty == 1 && list[j].isEmpty == 1)
                {
                    auxList = list[i];
                    list[i] = list[j];
                    list[j] = auxList;
                }
            }
            todoOk = 1;
        }

        for (int i = 0; i <= len; i++)
        {
            for (int j = i + 1; j <= len; j++)
            {
                if (list[i].typePassenger < list[j].typePassenger && list[i].isEmpty == 1 && list[j].isEmpty == 1)
                {
                    auxList = list[i];
                    list[i] = list[j];
                    list[j] = auxList;
                }
            }
            todoOk = 1;
        }
    }
    return todoOk;
}

int sortPassengersByCode(Passenger *list, int len, int order)
{
    int todoOk = 0;
    Passenger auxList;
    if (order == 1)
    {
        printf("                                            *** MENU de modificacion ***\n\n");
        printf(" ID  Nombre               Apellido             Codigo de vuelo   Tipo de pasajero   Estado del vuelo   Precio\n");

        for (int i = 0; i <= len; i++)
        {
            for (int j = i + 1; j <= len; j++)
            {
                if (strcmp(list[i].flycode, list[j].flycode) > 0 && list[i].isEmpty == 1 && list[j].isEmpty == 1)
                {
                    auxList = list[i];
                    list[i] = list[j];
                    list[j] = auxList;
                }
            }
        }
        for (int i = 0; i <= len; i++)
        {
            if (list[i].statusFlight == 1 && list[i].isEmpty == 1)
            {
                printPassenger(list + i);
                todoOk = 1;
            }
        }
    }
    else if (order == 2)
    {
        printf("                                            *** MENU de modificacion ***\n\n");
        printf(" ID  Nombre               Apellido             Codigo de vuelo   Tipo de pasajero   Estado del vuelo   Precio\n");

        for (int i = 0; i <= len; i++)
        {
            for (int j = i + 1; j <= len; j++)
            {
                if (strcmp(list[i].flycode, list[j].flycode) < 0 && list[i].isEmpty == 1 && list[j].isEmpty == 1)
                {
                    auxList = list[i];
                    list[i] = list[j];
                    list[j] = auxList;
                }
            }
        }
        for (int i = 0; i <= len; i++)
        {
            if (list[i].statusFlight == 1 && list[i].isEmpty == 1)
            {
                printPassenger(list + i);
                todoOk = 1;
            }
        }
    }
    return todoOk;
}

int hardcodearPasseger(Passenger *list, int len, int *id, int cantidad, int *addP)
{
    int todoOk = 0;

    Passenger auxLista[] = {{0, "Jose", "Guglielmi", 145.124, "UL432KJ564", 3, 1, 1}, {0, "Alesso", "Guglielmi", 255.5555, "GL444KJ546", 2, 1, 1}, {0, "Matias", "Corta", 573.142, "GHJ32KJLOP", 1, 2, 1}, {0, "Yulissa", "Carguapoma", 78.12313, "FL4432KJ54", 1, 2, 1}, {0, "Brian", "Saldivar", 543.222, "HL752KJ56", 1, 3, 1}, {0, "Juan", "Saldivar", 678.312, "HG4RWKJ565", 2, 3, 1}, {0, "Nicolas", "Guglielmi", 451.973, "32432KJPW4", 2, 3, 1}, {0, "Ana", "Saldivar", 634.678, "BNNM2KJ121", 1, 3, 1}, {0, "Marcos", "Martin", 612.987, "994YTKJ564", 3, 3, 1}, {0, "Soledad", "Martin", 131.724, "WE1132KJ53", 3, 1, 1}, {0, "Felipe", "Fernandez", 985.874, "JLG32KJ504", 2, 3, 1}, {0, "Julieta", "Ruiz", 166.524, "AA4721J972", 3, 2, 1}, {0, "Lulu", "AFKl", 115.674, "KL4PPKJH09", 1, 1, 1}, {0, "Alejo", "Martin", 995.991, "BB435KJ561", 3, 2, 1}};

    for (int i = 0; i < cantidad; i++)
    {
        if(list[i].isEmpty == 0){
        list[i] = auxLista[i];
        list[i].id = *id;
        *id = *id + 1;
        todoOk = 1;
        *addP = *addP + 1;
        }
    }

    return todoOk;
}
