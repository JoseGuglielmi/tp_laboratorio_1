#include <stdio.h>
#include <stdlib.h>

/**
 * @brief muestra un menu y se va actualizando amedida que el usuario ingresa sus datos
 *
 * @param flagKilo bandera de que el usuario ingreso los kilometros 0=no 1=si
 * @param flagPre bandera de que el usuario ingreso el precio de los vuelos 0=no 1=si
 * @param kilo flotante de los kilometros ingresados por el usuario
 * @param preLat flotante del precio de Latam ingresados por el usuario
 * @param preAe flotante del precio de Aerolineas ingresados por el usuario
 * @param pCreditoLatam flotante del precio de Latam pagado con Tarjeta de credito
 * @param pDebitoLatam flotante del precio de Latam pagado con Tarjeta de  debito
 * @param pBitcoinsLatam flotante del precio de Latam pagado con bitcois
 * @param pUnitarioLatam flotante del precio Unitario de Latam
 * @param pCreditoAe flotante del precio de Aerolineas pagado con Tarjeta de credito
 * @param pDebitoAe flotante del precio de Aerolineas pagado con Tarjeta de debito
 * @param pBitcoinsAe flotante del precio de Aerolineas pagado bitcions
 * @param pUnitarioAe flotante del precio unitario de Aerolineas
 * @param flagInforme bandera de que el usuario ingreso en la opcion 4 0=no 1=si
 * @param flagCostos bandera de que el usuario calculo los datos 0=no 1=si
 * @param dPrecio flotante de la diferecia de precio
 * @return int la opcion ingresada por el usuario
 */
int menu(int flagKilo, int flagPre, float kilo, float preLat, float preAe, float pCreditoLatam, float pDebitoLatam, float pBitcoinsLatam, float pUnitarioLatam, float pCreditoAe, float pDebitoAe, float pBitcoinsAe, float pUnitarioAe, int flagInforme, int flagCostos, float dPrecio);

/**
 * @brief pide datos al usuario y valida que sean correctos
 *
 * @param num flotante de tipo puntero donde se almacena el numero que ingreso el usuario
 * @param texto cadena de texto donde esta el mensaje que se mostrara al usuario al pedir el dato
 * @return int 0|si no se pudo optener datos o 1|si se pudo optener datos
 */
int pedirDatos(float* num, char texto[]);

/**
 * @brief funcion que calcula el precio de los vuelos
 *
 * @param kilometros flotante de los kilometros ingresados por el usuario
 * @param viaje flotante del precio ingresado por el usuario
 * @param pCredito flotante del precio pagado con Tarjeta de credito, donde se guardara el resultado de la cuenta
 * @param pDebito flotante del precio pagado con Tarjeta de debito, donde se guardara el resultado de la cuenta
 * @param pBitcoins flotante del precio pagado con bitcois, donde se guardara el resultado de la cuenta
 * @param pUnitario flotante del precio unitario, donde se guardara el resultado de la cuenta
 * @param pLatam flotante del precio de Latam ingresados por el usuario
 * @param pAero flotante del precio de Aerolineas ingresados por el usuario
 * @param dife flotante de la diferecia de precio, donde se guardara el resultado de la cuenta
 * @param flagDif bandera de difencia de precio 0|si no se puede calcular o 1|si se puede calcular
 * @return int 0|si no se pudo realizar los calulos o 1|si se pudo realizar los calculos
 */
int calcularCosto(float kilometros, float viaje, float* pCredito, float* pDebito, float* pBitcoins, float* pUnitario, float* pLatam, float* pAero, float* dife, int flagDif);

/**
 * @brief funcion para ver los precios sin introducir ningun dato(ya estan precargados)
 *
 * @param pCredito recibe flotante que se mostrara por mensaje al usuario
 * @param pDebito recibe flotante que se mostrara por mensaje al usuario
 * @param pBitcoin recibe flotante que se mostrara por mensaje al usuario
 * @param pUnitario recibe flotante que se mostrara por mensaje al usuario
 * @param pDife recibe flotante que se mostrara por mensaje al usuario
 * @param opcion entero que sirve como orden para mostrar los mensajes (0|Latam o 1|aerolineas)
 * @return int retorna si se pudo mostrar correctamente el mensaje al usuario 0=no 1=si
 */
int cargaForzada(float* pCredito,float* pDebito,float* pBitcoin,float* pUnitario,float* pDife, int opcion);
