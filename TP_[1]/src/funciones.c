#include "funciones.h"

int menu(int flagKilo, int flagPre, float kilo, float preLat, float preAe, float pCreditoLatam, float pDebitoLatam, float pBitcoinsLatam, float pUnitarioLatam, float pCreditoAe, float pDebitoAe, float pBitcoinsAe, float pUnitarioAe, int flagInforme, int flagCostos, float dPrecio){
	int opciones = 0;

	printf("         *** menu ***\n");
	//compruebo si el usuario ingreso los kilometros
	if (flagKilo == 0){
		//si no ingreso los kilometros
		printf("1-ingresar kilometros: sin datos\n\n");
	}else{
		//si ingreso los kilometros
		printf("1-ingresar kilometros: %0.2f KM\n\n", kilo);
	}

	printf("2-Ingresar Precio de Vuelos\n");
	//compruebo si el usuario ingreso los precios de los vuelos
	if (flagPre== 0){
		//si no ingreso los precios de los vuelos
		printf("  -Precio vuelo Aerolineas: sin datos\n");
		printf("  -Precio vuelo Latam: sin datos\n\n");
	}else{
		//si ingreso los precios de los vuelos
		printf("  -Precio vuelo Aerolineas: $%0.2f\n", preAe);
		printf("  -Precio vuelo Latam: $%0.2f\n\n", preLat);
	}

	printf("3-Calcular todos los costos\n");
	//compruebo si el usuario calculo los costos
	if(flagCostos == 0){
	//si el usuario no calculo los costos
	printf("  a) Tarjeta de debito (descuento 10 porciento)\n");
	printf("  b) Tarjeta de credito (interes 25 porciento)\n");
	printf("  c) Bitcoin (1BTC -> 4606954.55 Pesos Argentinos)\n");
	printf("  d) Mostrar precio por km (precio unitario)\n");
	printf("  e) Mostrar diferencia de precio (Latam-Aerolineas)\n\n");
	}else{
	//si el usuario calculo los costos
	printf("  a) Tarjeta de debito (descuento 10 porciento)|(Realizado correctamente)\n");
	printf("  b) Tarjeta de credito (interes 25 porciento)|(Realizado correctamente)\n");
	printf("  c) Bitcoin (1BTC -> 4606954.55 Pesos Argentinos)|(Realizado correctamente)\n");
	printf("  d) Mostrar precio por km (precio unitario)|(Realizado correctamente)\n");
	printf("  e) Mostrar diferencia de precio (Latam-Aerolineas)|(Realizado correctamente)\n\n");
	}

	printf("4-Informar Resultados\n\n");
	//compruebo si el usuario quiere ver los resultados y se los muestro en caso de elegir dicha opcion
	if(flagInforme == 1){
		printf("  Aerolineas:\n");
		printf("  a) Precio con tarjeta de debito: $%0.2f\n", pDebitoAe);
		printf("  b) Precio con tarjeta de credito: $%0.2f\n", pCreditoAe);
		printf("  c) Precio pagando con bitcoin: %0.10f BTC\n", pBitcoinsAe);
		printf("  d) Precio unitario: $%f\n\n", pUnitarioAe);
		printf("  Latam:\n");
		printf("  a) Precio con tarjeta de debito: $%0.2f\n", pDebitoLatam);
		printf("  b) Precio con tarjeta de credito: $%0.2f\n", pCreditoLatam);
		printf("  c) Precio pagando con bitcoin: %0.10f BTC\n", pBitcoinsLatam);
		printf("  d) Precio unitario: $%f\n\n", pUnitarioLatam);

		printf("  La diferencia de precio es: %0.2f\n\n", dPrecio);
	}

	printf("5. Carga forzada de datos\n\n");
	printf("6. Salir\n\n");
	//pido una opcion al usuario
	printf("ingrese una opcion: ");
	fflush(stdin);
	scanf("%d", &opciones);
	//retorno la opcion
	return opciones;
}

int pedirDatos(float* num, char texto[40]){
	//almaceno lo que devuelve el scanf
	int r;
	//variable que uso para validar si todo salio bien o algo salio mal 0|mal o 1|bien
	int todoOk = 0;

	//valido que el puntero sea distinto a null para continuar
	if(num !=  NULL){

		//muestro un mensaje al usuario
		printf("%s", texto);

		//limpio el buffer de entrada
		fflush(stdin);

		//capturo lo que ingreso el usuario
		r = scanf("%f", *(&num));

		//valido si el dato igresado esta mal
		while(r == 0 || *num <= -1){

			//muestro mensaje de error
			printf("dato erroneo, reingreselo: ");
			//limpio el buffer de entrada
			fflush(stdin);
			//capturo lo que ingreso el usuario
			r = scanf("%f",*(&num));
		}
		todoOk = 1;
	}else{
		//si el puntero es nulo se termina la fucion
		printf("Error al pedir datos\n");
		system("pause");
	}

	return todoOk;
}

int calcularCosto(float kilometros, float viaje, float* pCredito, float* pDebito, float* pBitcoins, float* pUnitario, float* pLatam, float* pAero, float* dife, int flagDif){
	//variable que uso para validar si todo salio bien o algo salio mal 0|mal o 1|bien
	int todoOk = 0;

	//valido que los puntero sea distinto a null para continuar
	if(pCredito != NULL && pBitcoins != NULL && pDebito != NULL && pUnitario != NULL && pLatam != NULL && pAero != NULL && dife != NULL){

		//realizo los calculos
		*pCredito = viaje + (viaje * 0.25);
		*pDebito =  viaje - (viaje * 0.1);
		*pBitcoins = viaje / 4606954.55;
		//verifico que no se divide por cero
		if(viaje != 0){
		//realizo la divicion
		*pUnitario = kilometros / viaje;
		}else{
			//no se realiza la divicion, lo guardo como -1
			*pUnitario = -1;
		}
		todoOk = 1;

		//valido si se ingresaron los precios para calcular la diferencia
		if(flagDif == 1){
			//me fijo el mayor para para restarlos, para evitar resultados negativos
			if(*pLatam > *pAero){
				*dife = *pLatam - *pAero;
			}else{
				*dife = *pAero - *pLatam;
			}
		}
	}
	return todoOk;
}

int cargaForzada(float* pCredito,float* pDebito,float* pBitcoin,float* pUnitario,float* pDife, int opcion){
	//variable que uso para validar si todo salio bien o algo salio mal 0|mal o 1|bien
	int todoOk = 0;
	//valido que los puntero sea distinto a null para continuar
	if(pCredito != NULL && pBitcoin != NULL && pDebito != NULL && pUnitario != NULL && pDife != NULL){
		//me fijo el orden para mostrar los mensajes
		if(opcion == 1){
		printf("ingresar kilometros: 7090.00 KM\n\n");
		printf("Aerolineas: $162965\n");
		printf("a) Precio con tarjeta de debito: $%0.2f\n",*pDebito);
		printf("b) Precio con tarjeta de credito: $%0.2f\n", *pCredito);
		printf(" c) Precio pagando con bitcoin: %.10f BTC\n", *pBitcoin);
		printf(" d) Precio unitario: $%0.10f\n\n",*pUnitario);
		todoOk = 1;
		}else{
		printf("Latam: $159339\n");
		printf("a) Precio con tarjeta de debito: $%0.2f\n",*pDebito);
		printf("b) Precio con tarjeta de credito: $%0.2f\n", *pCredito);
		printf(" c) Precio pagando con bitcoin: %.10f BTC\n", *pBitcoin);
		printf(" d) Precio unitario: $%0.2f\n\n",*pUnitario);

		printf("La diferencia de precio es : %0.10f", *pDife);
		todoOk = 1;
		}
	}
	return todoOk;
}
