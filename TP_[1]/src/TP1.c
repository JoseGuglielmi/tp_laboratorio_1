#include <stdio.h>
#include <stdlib.h>
#include "funciones.h"

int main()
{
	//para la consola de eclipse
	setbuf(stdout, NULL);
	//variable para salir del programa
	char salir = 'n';

	//variables para almacenar los datos que ingrese el usuario
	float kilometros = 0;
	float precioLatam = 0;
	float precioAerolineas = 0;

	//variables para almacenar los resultados de los calculos realizados de Latam
	float pCreditoLatam;
	float pDebitoLatam;
	float pBitcoinLatam;
	float pUnitarioLatam;

	//variables para almacenar los resultados de los calculos realizados de Aerolineas
	float pCreditoAerolineas;
	float pDebitoAerolineas;
	float pBitcoinAerolineas;
	float pUnitarioAerolineas;

	//variables para almacenar el resultado de la diferencia entre el precio de Latam y aerolineas
	float diferenciaPrecios;

	//banderas para saber que se a realizado correctamente y asi realizar otras operaciones
	int flagKilo = 0;
	int flagPre = 0;
	int flagInforme = 0;
	int flagCostos = 0;
	int flagDif = 0;

	//entro en bucle do while para mostrar el menu al usuario
	do{
		//limpio la pantalla
		system("cls");

		//switch con las opciones del menu
		switch (menu(flagKilo, flagPre, kilometros, precioLatam, precioAerolineas, pCreditoLatam, pDebitoLatam, pBitcoinLatam, pUnitarioLatam, pCreditoAerolineas, pDebitoAerolineas, pBitcoinAerolineas, pUnitarioAerolineas, flagInforme, flagCostos, diferenciaPrecios)){
		case 1:
			// si el usuario ingreso a la opcion 4 y vuelve a ingresar la opcion 1 se restablese las opciones 4 y 3
			if (flagInforme == 1){
				flagInforme = 0;
				flagCostos = 0;
			}
			// si el usuario ya realizo los calculos pero modifica algun dato se restablese la bandera calculos para que el usuario tenga que volver a calcularlos
			else if (flagCostos == 1){
				flagCostos = 0;
			}
			//limpio pantalla
			system("cls");

			//valido que se halla ingresado todo correctamente
			if(pedirDatos(&kilometros, "Ingrese los kilometros:")){
				flagKilo = 1;
			}else{
				//si hubo error tiro mensaje de error
				printf("Error al pedir datos");
			}
			break;
		case 2:
			// si el usuario ingreso a la opcion 4 y vuelve a ingresar la opcion 1 se restablese las opciones 4 y 3
			if (flagInforme == 1){
				flagInforme = 0;
				flagCostos = 0;
			}
			//si el usuario ya realizo los calculos pero modifica algun dato se restablese la bandera calculos para que el usuario tenga que volver a calcularlos
			else if (flagCostos == 1){
				flagCostos = 0;
			}
			//si el usuario quiere ingresar a la opcion 2 sin antes introducir los kilometros le da un error
			if (flagKilo == 0){
				system("cls");
				//mensaje de alerta que primero ingrese los kilometros
				printf("Ingrese los kilometros antes de usar esta opcion\n");
				//pone en pausa la consola
				system("pause");
			}
			else{
				system("cls");
				//pide y valida los precios que se ingresaron
				if(pedirDatos(&precioAerolineas, "Ingrese Precio de Aerolineas: ") == 0 || pedirDatos(&precioLatam, "Ingrese Precio de Latam: ") == 0){
					printf("error al pedir datos\n");
					system("pause");
				}else{
					//si es todo correcto se inicializan las variables en 1
					flagDif = 1;
					flagPre = 1;
				}
			}
			break;
		case 3:
		//si el usuario quiere ingresar a la opcion 2 sin antes introducir los kilometros le da un error
			if (flagKilo == 0){
				system("cls");
				//mensaje de alerta que primero ingrese los kilometros
				printf("Ingrese los kilometros antes de usar esta opcion\n");
				system("pause");
			}
			//si el usuario quiere ingresar a la opcion 3 sin antes introducir los precios le da un error
			else if (flagPre == 0){
				system("cls");
				//mensaje de alerta que primero ingrese los precios
				printf("Ingrese los precios de las aerolineas antes de usar esta opcion\n");
				system("pause");
			}
			else{
				//realizo los calculos y valido que se hallan realizado correctamente
				if (calcularCosto(kilometros, precioLatam, &pCreditoLatam, &pDebitoLatam, &pBitcoinLatam, &pUnitarioLatam, &precioLatam, &precioAerolineas, &diferenciaPrecios, flagDif) == 0){
					//tiro error en caso de que no se halla podido realizar los calculos
					printf("hubo un error al realizar los calculos\n");
					system("pause");
				}
				//realizo los calculos y valido que se hallan realizado correctamente
				else if (calcularCosto(kilometros, precioAerolineas, &pCreditoAerolineas, &pDebitoAerolineas, &pBitcoinAerolineas, &pUnitarioAerolineas, &precioLatam, &precioAerolineas, &diferenciaPrecios, flagDif) == 0){
					//tiro error en caso de que no se halla podido realizar los calculos
					printf("hubo un error al realizar los calculos\n");
					system("pause");
				}
				else{
					//si se realizo todo correctamente inicializo la bandera en 1
					flagCostos = 1;
				}
			}
			break;
		case 4:
			//si el usuario quiere ingresar a la opcion 2 sin antes introducir los kilometros le da un error
			if (flagKilo == 0){
				system("cls");
				//mensaje de alerta que primero ingrese los kilometros
				printf("Ingrese los kilometros antes de usar esta opcion\n");
				system("pause");
			}
			else if (flagPre == 0){
				system("cls");
				//mensaje de alerta que primero ingrese los precios
				printf("Ingrese los precios de las aerolineas antes de usar esta opcion\n");
				system("pause");
			}
			else if (flagCostos == 0){
				system("cls");
				//si el usuario quiere ingresar a la opcion 3 sin antes introducir los precios le da un error
				printf("Realizar los calculos antes de ver los resultados\n");
				system("pause");
			}
			else{
				//si esta todo correcto inicializo la bandera en 1
				flagInforme = 1;
			}
			break;
		case 5:
			//inicializo en 0 la bandera costos para evitar mostrar datos erroneos
			flagCostos = 0;
			system("cls");
			//realizo los calculos y valido que se hallan realizado correctamente
			if (calcularCosto(7090, 159339, &pCreditoLatam, &pDebitoLatam, &pBitcoinLatam, &pUnitarioLatam, &precioLatam, &precioAerolineas, &diferenciaPrecios, flagDif) == 0){
				//mensaje de error
				printf("hubo un error al realizar los calculos\n");
				system("pause");
			}
			//realizo los calculos y valido que se hallan realizado correctamente
			else if (calcularCosto(7090, 162965, &pCreditoAerolineas, &pDebitoAerolineas, &pBitcoinAerolineas, &pUnitarioAerolineas, &precioLatam, &precioAerolineas, &diferenciaPrecios, flagDif) == 0){
				//mensaje de error
				printf("hubo un error al realizar los calculos\n");
				system("pause");
			}
			else{
				//si esta todo correcto inicializo la bandera en 1
				flagCostos = 1;
			}
			//si se pudo realizar los calculos muestro los resultados
			if (flagCostos == 1){
			//muestro los mensajes con los resultados
			if (cargaForzada(&pCreditoAerolineas, &pDebitoAerolineas, &pBitcoinAerolineas, &pUnitarioAerolineas, &diferenciaPrecios, 1) == 0){
				system("cls");
				//mensaje de error
				printf("hubo un error al realizar los calculos\n");
			//muestro los mensajes con los resultados
			}else if (cargaForzada(&pCreditoLatam, &pDebitoLatam, &pBitcoinLatam, &pUnitarioLatam, &diferenciaPrecios, 0) == 0){
				system("cls");
				//mensaje de error
				printf("hubo un error al realizar la carga forzada\n");
			}
				system("pause");
				//inicializo en 0 para que no pueda ingresar a la opcion 4 el usuario
				flagCostos = 0;
			}
			break;
		case 6:
			system("pause");
			//si el usuario ingreso en la opcion 6 inicializo la variable salir en 's' para salir del programa
			salir = 's';
			break;
		default:
			system("cls");
			//si el usuario ingresa cualquier numero o letra le da error
			printf("Opcion invalida\n");
			system("pause");
			break;
		}
		//si salir es 'n' entra en bucle, si cambia la variable se rompe el bucle
	} while (salir == 'n');

	return 0;
}
