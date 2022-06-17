#include "../inc/Controller.h"

int menu()
{
	int opcion;

	printf("\n1. Cargar los datos de los pasajeros desde el archivo data.csv (modo texto).\n");
	printf("2. Cargar los datos de los pasajeros desde el archivo data.bin (modo binario).\n");
	printf("3. Alta de pasajero\n");
	printf("4. Modificar datos de pasajero\n");
	printf("5. Baja de pasajero\n");
	printf("6. Listar pasajeros\n");
	printf("7. Ordenar pasajeros\n");
	printf("8. Guardar los datos de los pasajeros en el archivo data.csv (modo texto).\n");
	printf("9. Guardar los datos de los pasajeros en el archivo data.csv (modo binario).\n");
	printf("10.Limpiar lista\n");
	printf("11.Reemplazar un pasajero por otro\n");
	printf("12.Crear una lista auxliar\n");
	printf("13.comparar contenido de las lista\n");
	printf("14.listar lista auxiliar\n");
	printf("15.Eliminar pasajero por su indice\n");
	printf("16.Obtener el indice de donde se encuentra el pasajero en la lista\n");
	printf("17.Insertar un pasajero en el indice que especifique el usuario\n");
	printf("18.Salir\n");

	validarInt("Ingrese una opcion: ", "Error. Ingrese una opcion valida: ", &opcion, 1, 18);

	return opcion;
}

int controller_loadFromText(char *path, LinkedList *pArrayListPassenger)
{
	int todoOk = 0;

	if (path != NULL && pArrayListPassenger != NULL)
	{
		// abrimos el archivo
		FILE *data = fopen(path, "r");
		// valido que no sea null
		if (data == NULL)
		{
			todoOk = 0;
			printf("error al abrir el archivo\n");
		}
		else
		{
			// Si esta vacio copia lo del archivo a la lista
			if (ll_len(pArrayListPassenger) == 0)
			{
				todoOk = parser_PassengerFromText(data, pArrayListPassenger);
				printf("pasajeros agregados con exito\n");
				// si tiene datos, hacemos el backUp
			}
			else
			{
				// hacemos el backUp
				if (!controller_saveAsText("backUp.csv", pArrayListPassenger))
				{
					// si no se hizo el backUp se lo informo
					printf("Los datos fueron cargados, pero no se pudo hacer el backUp\n");
					// limpio la lista
					ll_clear(pArrayListPassenger);
					// y la relleno con los datos del archivo
					todoOk = parser_PassengerFromText(data, pArrayListPassenger);
				}
				else
				{
					// si se hizo el backUp se lo informamos
					printf("Se han sobre-escrito los datos, se hizo un backUp en \"backUp.csv\"\n");
					// limpio la lista
					ll_clear(pArrayListPassenger);
					// y la relleno con los datos del archivo
					todoOk = parser_PassengerFromText(data, pArrayListPassenger);
				}
			}
		}
		// cerramos el archivo
		fclose(data);
	}

	return todoOk;
}

/** \brief Carga los datos de los pasajeros desde el archivo data.csv (modo binario).
 *
 * \param path char*
 * \param pArrayListPassenger LinkedList*
 * \return int
 *
 */
int controller_loadFromBinary(char *path, LinkedList *pArrayListPassenger)
{
	int todoOk = 0;

	if (path != NULL && pArrayListPassenger != NULL)
	{
		// abrimos archivo
		FILE *data = fopen(path, "rb");

		// validamos el archivo
		if (data == NULL)
		{
			todoOk = 0;
			printf("error al abrir el archivo\n");
		}
		else
		{
			// Si esta vacio copia lo del archivo a la lista
			if (ll_len(pArrayListPassenger) == 0)
			{
				todoOk = parser_PassengerFromBinary(data, pArrayListPassenger);
				// si tiene datos, hacemos el backUp
			}
			else
			{
				// si tiene datos, hacemos el backUp
				if (!controller_saveAsBinary("backUp.bin", pArrayListPassenger))
				{
					printf("Los datos fueron cargados, pero no se pudo hacer el backUp\n");
					// limpio la lista
					ll_clear(pArrayListPassenger);
					// y la relleno con los datos del archivo
					todoOk = parser_PassengerFromBinary(data, pArrayListPassenger);
				}
				else
				{
					// si se hizo el backUp se lo informamos
					printf("Se han sobre-escrito los datos, se hizo un backUp en \"backUp.bin\"\n");
					// limpio la lista
					ll_clear(pArrayListPassenger);
					// y la relleno con los datos del archivo
					todoOk = parser_PassengerFromBinary(data, pArrayListPassenger);
				}
			}
		}
		// cerramos el archivo
		fclose(data);
	}
	return todoOk;
}

int controller_gestionId(LinkedList *pArrayListPassenger, int id)
{
	Passenger *new;
	int flag = 0;
	int mayorId = 0;
	int tam = ll_len(pArrayListPassenger);

	if (pArrayListPassenger != NULL)
	{
		// verifico que no halla pasajeros y que si el id es mejor o igual a 0 retorno id = 1
		if (tam == 0 && id <= 0)
		{
			id = 1;
		}
		else
		{
			// busco el id mas alto y lo retorno
			for (int i = 0; i < tam; i++)
			{
				new = (Passenger *)ll_get(pArrayListPassenger, i);
				// buscamos el id mas alto de la lista y lo retornamos id+1
				if (!flag || new->id > mayorId)
				{
					flag = 1;
					mayorId = new->id;
					id = mayorId + 1;
				}
			}
		}
	}

	return id;
}

/** \brief Alta de pasajero
 *
 * \param path char*
 * \param pArrayListPassenger LinkedList*
 * \return int
 *
 */
int controller_addPassenger(LinkedList *pArrayListPassenger)
{
	int todoOk = 0;

	// variables donde guardamos los datos previos a guardarlo en la lista
	char nombre[50];
	char apellido[50];
	float precio;
	char codigoDeVuelo[7];
	char tipoPasajero[50];
	char estadoDeVuelo[50];
	char precioChar[50];
	int id = 1;

	Passenger *new;

	if (pArrayListPassenger != NULL)
	{
		// pido todos los datos
		validarTexto("Ingrese nombre del pasajero: ", "Error. Reingrese el nombre del pasajero: ", nombre, 50);
		ordenarStrings(nombre);

		validarTexto("Ingrese su apellido: ", "Apellido invalido. Reingrese apellido: ", apellido, 50);
		ordenarStrings(apellido);

		validarFloat("Ingrese el precio del vuelo: ", "El precio no es valido. Reingrese el precio del vuelo: ", &precio, 1, 100000000);

		validarTexto("Ingrese el tipo de pasajero FirstClass o ExecutiveClass o EconomyClass: ", "Error. ReIngrese el tipo de pasajero FirstClass o ExecutiveClass o EconomiyClass: ", tipoPasajero, 50);

		while (strcmp(tipoPasajero, "FirstClass") != 0 && strcmp(tipoPasajero, "ExecutiveClass") != 0 && strcmp(tipoPasajero, "EconomyClass") != 0)
		{
			validarTexto("Error ReIngrese el tipo de pasajero FirstClass o ExecutiveClass o EconomyClass: ", "Error. ReIngrese el tipo de pasajero FirstClass o ExecutiveClass o EconomyClass: ", tipoPasajero, 50);
		}
		validarTexto("Ingrese el estado del vuelo:  En Horario o Demorado o Aterrizado o En Vuelo: ", "Error. ReIngrese el estado del vuelo:  En horario o Demorado o Aterrizado o En Vuelo: ", estadoDeVuelo, 50);

		while (strcmp(estadoDeVuelo, "En Horario") != 0 && strcmp(estadoDeVuelo, "Demorado") != 0 && strcmp(estadoDeVuelo, "Aterrizado") != 0 && strcmp(estadoDeVuelo, "En Vuelo") != 0)
		{
			validarTexto("Error. ReIngrese el estado del vuelo:  En Horario o Demorado o Aterrizado o En Vuelo: ", "Error. ReIngrese el estado del vuelo:  En horario o Demorado o Aterrizado o En Vuelo: ", estadoDeVuelo, 50);
		}

		validarAlfaNumerico("Ingrese el codigo de vuelo: ", "Error. Reingrese codigo de vuelo: ", codigoDeVuelo, 8);

		// parceo los datos de tipo float a tipo char
		sprintf(precioChar, "%f", precio);

		// busco el ultimo id
		id = controller_gestionId(pArrayListPassenger, id);

		// agregamos los datos al nuevo pasajero
		new = Passenger_newParametros(id, nombre, apellido, precioChar, codigoDeVuelo, tipoPasajero, estadoDeVuelo);

		// verificamos que no sea nulo
		if (new != NULL)
		{
			// y guardamos el pasajero en la lista
			ll_add(pArrayListPassenger, new);
			todoOk = 1;
		}
	}
	return todoOk;
}

/** \brief Modificar datos de pasajero
 *
 * \param path char*
 * \param pArrayListPassenger LinkedList*
 * \return int
 *
 */
int controller_editPassenger(LinkedList *pArrayListPassenger)
{
	int todoOk = 0;
	int opcion;
	int id;
	Passenger *new;
	char nombre[50];
	char apellido[50];
	float precio;
	char codigoDeVuelo[7];
	char tipoPasajero[50];
	char estadoDeVuelo[50];

	if (pArrayListPassenger != NULL)
	{
		// verifico que halla pasajeros
		if (controller_ListPassenger(pArrayListPassenger))
		{

			validarInt("Ingrese el id del pasajero que desea modificar: ", "Error. ReIngrese un id valido del pasajero que desea modificar: ", &id, 1, 5000);

			if (ll_len(pArrayListPassenger) > 0)
			{
				// busco el id ingresado por el usuario en la lista
				for (int i = 0; i < ll_len(pArrayListPassenger); i++)
				{
					// obtengo el pasajero
					new = (Passenger *)ll_get(pArrayListPassenger, i);
					// y verifico que sea el id
					if (new->id == id)
					{
						do
						{
							controller_showPassenger(new);
							switch (menuEdit())
							{
							// modifica el nombre
							case 1:
								validarTexto("Ingrese nombre del pasajero: ", "Error. Reingrese el nombre del pasajero: ", nombre, 50);
								ordenarStrings(nombre);
								Passenger_setNombre(new, nombre);
								break;
							// modifica el apellido
							case 2:
								validarTexto("Ingrese su apellido: ", "Apellido invalido. Reingrese apellido: ", apellido, 50);
								ordenarStrings(apellido);
								Passenger_setApellido(new, apellido);
								break;
							// modifica el precio
							case 3:
								validarFloat("Ingrese el precio del vuelo: ", "El precio no es valido. Reingrese el precio del vuelo: ", &precio, 1, 100000000);
								Passenger_setPrecio(new, precio);
								break;
							// modifica el tipo
							case 5:
								validarTexto("Ingrese el tipo de pasajero FirstClass o ExecutiveClass o EconomyClass: ", "Error. ReIngrese el tipo de pasajero FirstClass o ExecutiveClass o EconomiyClass: ", tipoPasajero, 50);

								while (strcmp(tipoPasajero, "FirstClass") != 0 && strcmp(tipoPasajero, "ExecutiveClass") != 0 && strcmp(tipoPasajero, "EconomyClass") != 0)
								{
									validarTexto("Error ReIngrese el tipo de pasajero FirstClass o ExecutiveClass o EconomyClass: ", "Error. ReIngrese el tipo de pasajero FirstClass o ExecutiveClass o EconomyClass: ", tipoPasajero, 50);
								}
								Passenger_setTipoPasajero(new, tipoPasajero);
								break;
								// modifica el estado
							case 6:
								validarTexto("Ingrese el estado del vuelo:  En Horario o Demorado o Aterrizado o En Vuelo: ", "Error. ReIngrese el estado del vuelo:  En horario o Demorado o Aterrizado o En Vuelo: ", estadoDeVuelo, 50);

								while (strcmp(estadoDeVuelo, "En Horario") != 0 && strcmp(estadoDeVuelo, "Demorado") != 0 && strcmp(estadoDeVuelo, "Aterrizado") != 0 && strcmp(estadoDeVuelo, "En Vuelo") != 0)
								{
									validarTexto("Error. ReIngrese el estado del vuelo:  En Horario o Demorado o Aterrizado o En Vuelo: ", "Error. ReIngrese el estado del vuelo:  En horario o Demorado o Aterrizado o En Vuelo: ", estadoDeVuelo, 50);
								}
								Passenger_setEstadoDeVuelo(new, estadoDeVuelo);

								break;
							// modifica el codigo de vuelo
							case 4:
								validarAlfaNumerico("Ingrese el codigo de vuelo: ", "Error. Reingrese codigo de vuelo: ", codigoDeVuelo, 8);
								Passenger_setCodigoVuelo(new, codigoDeVuelo);
								break;
							case 7:
								opcion = 7;
								todoOk = 1;
								break;
							}

						} while (opcion != 7);
					}
				}
			}
		}
	}

	return todoOk;
}

int menuEdit()
{
	int opcion;

	printf("1. Modificar nombre\n");
	printf("2. Modificar apellido\n");
	printf("3. Modificar precio\n");
	printf("4. Modificar codigo de vuelo\n");
	printf("5. Modificar tipo de pasajero\n");
	printf("6. Modificar estado de vuelo\n");
	printf("7. Salir\n");

	validarInt("Ingrese una opcion: ", "Error. Ingrese una opcion valida: ", &opcion, 1, 7);
	return opcion;
}
/** \brief Baja de pasajero
 *
 * \param path char*
 * \param pArrayListPassenger LinkedList*
 * \return int
 *
 */
int controller_removePassenger(LinkedList *pArrayListPassenger)
{
	int todoOk = 0;
	int id;
	Passenger *new;
	char confirma;

	if (pArrayListPassenger != NULL)
	{
		// muestro la lista
		if (controller_ListPassenger(pArrayListPassenger))
		{
			// pido el id que desea borrar
			validarInt("Ingrese el id del pasajero que desea borrar: ", "Error ReIngrese un id valido del pasajero que desea borrar: ", &id, 1, 5000);

			// verifico que halla pasajeros
			if (ll_len(pArrayListPassenger) > 0)
			{
				// recorro la lista en busca del id que ingreso el usuario
				for (int i = 0; i < ll_len(pArrayListPassenger); i++)
				{
					// obtengo los pasajeros para verificar su id
					new = (Passenger *)ll_get(pArrayListPassenger, i);

					// si coinciden los ids lo borro
					if (new->id == id)
					{
						// muestro el pasajero que quiere borrar
						controller_showPassenger(new);
						// le pregunto si lo quier borrar
						printf("Desea eliminar este pasajero? (si o no): ");
						fflush(stdin);
						fgets(&confirma, 2, stdin);
						if (confirma == 's')
						{
							// si confirma lo borro
							ll_remove(pArrayListPassenger, i);
							printf("Pasajero removido con exito\n");
						}
						else
						{
							// si lo cancela, no hago nada
							printf("Baja cancelada\n");
						}
					}
				}
			}
		}
	}
	return todoOk;
}

/** \brief Listar pasajeros
 *
 *
 * \param path char*
 * \param pArrayListPassenger LinkedList*
 * \return int
 *
 */
int controller_ListPassenger(LinkedList *pArrayListPassenger)
{
	int todoOk = 0;
	Passenger *pasajero;

	if (pArrayListPassenger != NULL)
	{
		// verifico que hallan pasajeros
		if (ll_len(pArrayListPassenger) > 0)
		{
			// muestro el pasajero
			printf("%-4s %-20s %-20s %-10s %-8s %-15s %-10s\n", "ID", "NOMBRE", "APELLIDO", "PRECIO", "CODIGO", "TIPO", "ESTADO");
			for (int i = 0; i < ll_len(pArrayListPassenger); i++)
			{
				// muestro el pasajero
				pasajero = (Passenger *)ll_get(pArrayListPassenger, i);
				printf("%-4d %-20s %-20s %-10.2f %-8s %-15s %-10s\n", pasajero->id, pasajero->nombre, pasajero->apellido, pasajero->precio, pasajero->codigoDeVuelo, pasajero->tipoPasajero, pasajero->estadoDeVuelo);
			}
			todoOk = 1;
		}
		else
		{
			// si no hay pasajeros, se lo informo al usuario
			printf("agrege pasajeros a antes de listarlos o cargue un archivo correctamente\n");
		}
	}

	return todoOk;
}

int controller_showPassenger(Passenger *pasajero)
{
	int todoOk = 0;

	if (pasajero != NULL)
	{
		// muestro un pasjero
		printf("%-4s %-20s %-20s %-10s %-8s %-15s %-10s\n", "ID", "NOMBRE", "APELLIDO", "PRECIO", "CODIGO", "TIPO", "ESTADO");
		printf("%-4d %-20s %-20s %-10.2f %-8s %-15s %-10s\n", pasajero->id, pasajero->nombre, pasajero->apellido, pasajero->precio, pasajero->codigoDeVuelo, pasajero->tipoPasajero, pasajero->estadoDeVuelo);
		todoOk = 1;
	}
	return todoOk;
}

/** \brief Ordenar pasajeros
 *
 * \param path char*
 * \param pArrayListPassenger LinkedList*
 * \return int
 *
 */
int controller_sortPassenger(LinkedList *pArrayListPassenger)
{
	int todoOk = 0;
	int r;
	int criterio;
	if (pArrayListPassenger != NULL)
	{
		// pido el creiterio de ordenamiento
		validarInt("Ingrese el criterio con el que desea ordenar la lista:  1 = Ascendente   0 = Descendente: ", "Error. Ingrese el criterio con el que desea ordenar la lista:  1 = Ascendente   0 = Descendente:", &criterio, 0, 1);

		// muestro el menu y hago lo que me ingreso el usuario
		switch (menuSort())
		{
		case 1:
			r = ll_sort(pArrayListPassenger, controller_SortId, criterio);
			break;
		case 2:
			r = ll_sort(pArrayListPassenger, controller_SortNombre, criterio);
			break;
		case 3:
			r = ll_sort(pArrayListPassenger, controller_SortApellido, criterio);
			break;
		case 4:
			r = ll_sort(pArrayListPassenger, controller_SortPrecio, criterio);
			break;
		case 5:
			r = ll_sort(pArrayListPassenger, controller_SortCodigo, criterio);
			break;
		case 6:
			r = ll_sort(pArrayListPassenger, controller_SortTipo, criterio);
			break;
		case 7:
			r = ll_sort(pArrayListPassenger, controller_SortEstado, criterio);
			break;
		}
		if (!r)
		{
			// si salio bien, se lo digo
			printf("Los datos fueron ordenados con exito\n");
			todoOk = 1;
		}
		else if (r == -1)
		{
			// si no salio bien, se lo digo
			printf("Eror al ordenar los datos\n");
		}
	}
	return todoOk;
}

int menuSort()
{
	int opcion;

	printf("1.Ordenar lista por ID\n");
	printf("2.Ordenar lista por nombre \n");
	printf("3.Ordenar lista por apellido \n");
	printf("4.Ordenar lista por precio \n");
	printf("5.Ordenar lista por codigo de vuelo \n");
	printf("6.Ordenar lista por tipo de pasajero \n");
	printf("7.Ordenar lista por estado del vuelo \n");

	validarInt("Ingrese una opcion: ", "Error. Ingrese una opcion valida: ", &opcion, 1, 7);

	return opcion;
}

int controller_SortNombre(void *nombre1, void *nombre2)
{

	if (nombre1 != NULL && nombre2 != NULL)
	{

		if (strcmp(((Passenger *)nombre1)->nombre,
				   ((Passenger *)nombre2)->nombre) > 0)
		{
			return 1;
		}
		if (strcmp(((Passenger *)nombre1)->nombre,
				   ((Passenger *)nombre2)->nombre) < 0)
		{
			return -1;
		}
	}
	return 0;
}

int controller_SortApellido(void *pasajero1, void *pasajero2)
{

	if (pasajero1 != NULL && pasajero2 != NULL)
	{

		if (strcmp(((Passenger *)pasajero1)->apellido,
				   ((Passenger *)pasajero2)->apellido) > 0)
		{
			return 1;
		}
		if (strcmp(((Passenger *)pasajero1)->apellido,
				   ((Passenger *)pasajero2)->apellido) < 0)
		{
			return -1;
		}
	}
	return 0;
}

int controller_SortTipo(void *pasajero1, void *pasajero2)
{

	if (pasajero1 != NULL && pasajero2 != NULL)
	{

		if (strcmp(((Passenger *)pasajero1)->tipoPasajero,
				   ((Passenger *)pasajero2)->tipoPasajero) > 0)
		{
			return 1;
		}
		if (strcmp(((Passenger *)pasajero1)->tipoPasajero,
				   ((Passenger *)pasajero2)->tipoPasajero) < 0)
		{
			return -1;
		}
	}
	return 0;
}

int controller_SortEstado(void *pasajero1, void *pasajero2)
{

	if (pasajero1 != NULL && pasajero2 != NULL)
	{

		if (strcmp(((Passenger *)pasajero1)->estadoDeVuelo,
				   ((Passenger *)pasajero2)->estadoDeVuelo) > 0)
		{
			return 1;
		}
		if (strcmp(((Passenger *)pasajero1)->estadoDeVuelo,
				   ((Passenger *)pasajero2)->estadoDeVuelo) < 0)
		{
			return -1;
		}
	}
	return 0;
}

int controller_SortCodigo(void *pasajero1, void *pasajero2)
{

	if (pasajero1 != NULL && pasajero2 != NULL)
	{

		if (strcmp(((Passenger *)pasajero1)->codigoDeVuelo,
				   ((Passenger *)pasajero2)->codigoDeVuelo) > 0)
		{
			return 1;
		}
		if (strcmp(((Passenger *)pasajero1)->codigoDeVuelo,
				   ((Passenger *)pasajero2)->codigoDeVuelo) < 0)
		{
			return -1;
		}
	}
	return 0;
}

int controller_SortId(void *pasajero1, void *pasajero2)
{

	if (pasajero1 != NULL && pasajero2 != NULL)
	{

		if (((Passenger *)pasajero1)->id > ((Passenger *)pasajero2)->id)
		{
			return 1;
		}
		if (((Passenger *)pasajero1)->id < ((Passenger *)pasajero2)->id)
		{
			return -1;
		}
	}
	return 0;
}

int controller_SortPrecio(void *pasajero1, void *pasajero2)
{

	if (pasajero1 != NULL && pasajero2 != NULL)
	{

		if (((Passenger *)pasajero1)->precio > ((Passenger *)pasajero2)->precio)
		{
			return 1;
		}
		if (((Passenger *)pasajero1)->precio < ((Passenger *)pasajero2)->precio)
		{
			return -1;
		}
	}
	return 0;
}

/** \brief Guarda los datos de los pasajeros en el archivo data.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListPassenger LinkedList*
 * \return int
 *
 */
int controller_saveAsText(char *path, LinkedList *pArrayListPassenger)
{
	int todoOk = 0;
	Passenger *pasajero;

	if (path != NULL && pArrayListPassenger != NULL)
	{

		// abro el archivo modo escritura de texto
		FILE *data = fopen(path, "a");
		// verifico que no sea nullo
		if (data == NULL)
		{
			todoOk = 0;
			printf("error al abrir el archivo\n");
		}
		// verifico que halla pasajeros en la lista
		else if (ll_len(pArrayListPassenger) > 0)
		{
			// recorro la lista
			for (int i = 0; i < ll_len(pArrayListPassenger); i++)
			{
				// guardo los pasajeros en un archivo
				pasajero = (Passenger *)ll_get(pArrayListPassenger, i);
				fprintf(data, "%d,%s,%s,%f,%s,%s,%s\n", pasajero->id, pasajero->nombre, pasajero->apellido, pasajero->precio, pasajero->codigoDeVuelo, pasajero->tipoPasajero, pasajero->estadoDeVuelo);
			}
			todoOk = 1;
			// cierro el archivo
			fclose(data);
		}
	}
	return todoOk;
}

/** \brief Guarda los datos de los pasajeros en el archivo data.csv (modo binario).
 *
 * \param path char*
 * \param pArrayListPassenger LinkedList*
 * \return int
 *
 */
int controller_saveAsBinary(char *path, LinkedList *pArrayListPassenger)
{
	int todoOk = 0;
	Passenger *pasajero;

	if (path != NULL && pArrayListPassenger != NULL)
	{

		// abro el archivo modo escritura binaria
		FILE *data = fopen(path, "ab");
		int cant;

		// valido que no sea nulo
		if (data == NULL)
		{
			todoOk = 0;
			printf("error al abrir el archivo\n");
		}
		// verifico que hallan pasajeros en la lista
		if (ll_len(pArrayListPassenger) > 0)
		{
			// recorro la listas
			for (int i = 0; i < ll_len(pArrayListPassenger); i++)
			{
				// guardo el pasajero en el archivo.bin
				pasajero = (Passenger *)ll_get(pArrayListPassenger, i);
				cant = fwrite(pasajero, sizeof(Passenger), 1, data);
				if (cant != 1)
				{
					break;
				}
			}
			todoOk = 1;
			fclose(data);
		}
	}
	return todoOk;
}

Passenger *Controller_PasajeroNuevo(LinkedList *pArrayListPassenger)
{
	// variables donde guardamos los datos previos a guardarlo en la lista
	char nombre[50];
	char apellido[50];
	float precio;
	char codigoDeVuelo[7];
	char tipoPasajero[50];
	char estadoDeVuelo[50];
	char precioChar[50];
	int id = 1;

	// donde guardo el nuevo pasajero
	Passenger *new;

	// busco el ultimo id
	id = controller_gestionId(pArrayListPassenger, id);

	// pido todos los datos
	validarTexto("Ingrese nombre del pasajero: ", "Error. Reingrese el nombre del pasajero: ", nombre, 50);
	ordenarStrings(nombre);

	validarTexto("Ingrese su apellido: ", "Apellido invalido. Reingrese apellido: ", apellido, 50);
	ordenarStrings(apellido);

	validarFloat("Ingrese el precio del vuelo: ", "El precio no es valido. Reingrese el precio del vuelo: ", &precio, 1, 100000000);

	validarTexto("Ingrese el tipo de pasajero FirstClass o ExecutiveClass o EconomyClass: ", "Error. ReIngrese el tipo de pasajero FirstClass o ExecutiveClass o EconomiyClass: ", tipoPasajero, 50);

	while (strcmp(tipoPasajero, "FirstClass") != 0 && strcmp(tipoPasajero, "ExecutiveClass") != 0 && strcmp(tipoPasajero, "EconomyClass") != 0)
	{
		validarTexto("Error ReIngrese el tipo de pasajero FirstClass o ExecutiveClass o EconomyClass: ", "Error. ReIngrese el tipo de pasajero FirstClass o ExecutiveClass o EconomyClass: ", tipoPasajero, 50);
	}
	validarTexto("Ingrese el estado del vuelo:  En Horario o Demorado o Aterrizado o En Vuelo: ", "Error. ReIngrese el estado del vuelo:  En horario o Demorado o Aterrizado o En Vuelo: ", estadoDeVuelo, 50);

	while (strcmp(estadoDeVuelo, "En Horario") != 0 && strcmp(estadoDeVuelo, "Demorado") != 0 && strcmp(estadoDeVuelo, "Aterrizado") != 0 && strcmp(estadoDeVuelo, "En Vuelo") != 0)
	{
		validarTexto("Error. ReIngrese el estado del vuelo:  En Horario o Demorado o Aterrizado o En Vuelo: ", "Error. ReIngrese el estado del vuelo:  En horario o Demorado o Aterrizado o En Vuelo: ", estadoDeVuelo, 50);
	}
	validarAlfaNumerico("Ingrese el codigo de vuelo: ", "Error. Reingrese codigo de vuelo: ", codigoDeVuelo, 8);

	// parceo los datos de tipo float a tipo char
	sprintf(precioChar, "%f", precio);

	// agregamos los datos al nuevo pasajero
	new = Passenger_newParametros(id, nombre, apellido, precioChar, codigoDeVuelo, tipoPasajero, estadoDeVuelo);

	return new;
}

int remplazarPasajero(LinkedList *pArrayListPassenger)
{
	int todoOk = 0;
	int indice;
	if (pArrayListPassenger != NULL)
	{
		Passenger *new;
		// creo un nuevo pasajero
		new = Controller_PasajeroNuevo(pArrayListPassenger);
		// valido que no sea null
		if (new != NULL)
		{
			//pido un indice
			validarInt("Ingrese el indice donde desea remplazar al psajero", "", &indice, 0, ll_len(pArrayListPassenger));

			//remplazo el elemento(pasajero)
			if (ll_set(pArrayListPassenger, indice, new) == 0)
			{
				printf("se a remplazado correctamente\n");
				todoOk = 1;
			}
			else
			{
				printf("hubo un error al remplazar al pasajero\n");
			}
		}
	}

	return todoOk;
}

int compararListas(LinkedList *lista1, LinkedList *lista2, int flag2)
{
	int todoOk = 0;
	if (lista1 != NULL && lista2 != NULL && flag2 != 0)
	{
		// comparto que los datos de la lista2 esten en la lista original
		todoOk = ll_containsAll(lista1, lista2);
	}
	return todoOk;
}

int controller_Eliminar_ll_pop(LinkedList *this, LinkedList *this2)
{
	int todoOk = 0;
	int index;

	Passenger *new;

	if (this != NULL && this2 != NULL)
	{
		// pido un indice
		validarInt("Ingrese el indice: ", "Error. ReIngrese el indice: ", &index, 0, ll_len(this) - 1);

		// lo elimino y optengo la direcion de memoria del pasajero borrado
		new = ll_pop(this, index);
		if (new != NULL)
		{
			// añado el pasajero eliminado a la lista auxiliar
			if (!ll_add(this2, new))
			{
				todoOk = 1;
			}
		}
	}

	return todoOk;
}

int controller_indice(LinkedList *this)
{
	int todoOk = 0;
	int id = 0;
	Passenger *new;

	if (this != NULL)
	{
		// pido un id
		validarInt("Ingrese un ID: ", "Error. ReIngrese un ID: ", &id, 1, controller_gestionId(this, id) - 1);

		for (int i = 0; i < ll_len(this); i++)
		{
			// obtengo el pasajero
			new = (Passenger *)ll_get(this, i);
			// y verifico que sea el id
			if (new->id == id)
			{
				printf("el indice del pasajero con el id %d es: %d", id, i);
				todoOk = 1;
				break;
			}
		}
	}

	return todoOk;
}

int controller_ll_push(LinkedList *this)
{
	int todoOk = 0;
	int index;
	Passenger *new;

	if (this != NULL)
	{
		// pido el indice
		validarInt("Ingrese el indice: ", "Error. ReIngrese el indice: ", &index, 0, ll_len(this) - 1);

		// creo un nuevo pasajero
		new = Controller_PasajeroNuevo(this);
		// valido que no sea null
		if (new != NULL)
		{
			// realizo el push
			if (!ll_push(this, index, new))
			{
				todoOk = 1;
			}
		}
	}

	return todoOk;
}