#include "funciones.h"
#include "ArrayPassenger.h"

int requestDataTex(char *menInicio, char *menError, char *text, int len)
{
    int todoOk = 1;

    char auxText[100];

    if (menInicio != NULL && menError != NULL && text != NULL)
    {

        printf("%s", menInicio);
        fflush(stdin);
        fgets(auxText, len - 1, stdin);
        removeBarN(auxText);
        for (int i = 0; i < len; i++)
        {
            if (isalpha(auxText[i]) == 0)
            {
                todoOk = 0;
                break;
            }
            else if (strcmp((auxText + i + 1), "\0") == 0)
            {
                todoOk = 1;
                break;
            }
        }

        while (!todoOk)
        {
            todoOk = requestDataTex(menError, menError, auxText, len);
        }

        if (todoOk)
        {
            strcpy(text, auxText);
        }
    }
    else
    {
        todoOk = 0;
    }

    return todoOk;
}

int requestDataNumFloat(char *menInicio, char *menError, float *number, int min, int max)
{
    int todoOk = 1;
    float auxNumber = 0;
    char auxText[99];
    char *auxNum;
    int contadorDePuntos = 0;

    if (menInicio != NULL && menError != NULL && number != NULL)
    {
        printf("%s", menInicio);
        fflush(stdin);
        fgets(auxText, max, stdin);
        removeBarN(auxText);
        for (int i = 0; i < 99; i++)//1.1.1
        {
            if (auxText[i] == '.' && contadorDePuntos == 0)
            {
                contadorDePuntos++;
            }
            else if (!isdigit(auxText[i]))
            {
                todoOk = 0;
                break;
            }
            else if (!strcmp((auxText + i + 1), "\0"))
            {
                todoOk = 1;
                auxNumber = strtof(auxText, &auxNum);
                break;
            }
        }

        do
        {
            while (!todoOk)
            {
                contadorDePuntos = 0;
                printf("%s", menError);
                fflush(stdin);
                fgets(auxText, max, stdin);
                removeBarN(auxText);
                for (int i = 0; i < 99; i++)
                {
                    if (auxText[i] == '.' && contadorDePuntos == 0)
                    {
                        contadorDePuntos++;
                    }
                    else if (!isdigit(auxText[i]))
                    {
                        todoOk = 0;
                        break;
                    }
                    else if (!strcmp((auxText + i + 1), "\0"))
                    {
                        todoOk = 1;
                        auxNumber = strtof(auxText, &auxNum);
                        break;
                    }
                }
            }

            if (todoOk && auxNumber >= min && auxNumber <= max)
            {
                *number = auxNumber;
                todoOk = 1;
            }
            else
            {
                todoOk = 0;
            }

        } while (todoOk == 0);
    }
    else
    {
        todoOk = 0;
    }
    return todoOk;
}

int requestDataNumInt(char *menInicio, char *menError, int *number, int min, int max)
{
    int todoOk = 1;
    int auxNumber;

    if (menInicio != NULL && menError != NULL && number != NULL)
    {
        char auxText[99];
        printf("%s", menInicio);
        fflush(stdin);
        fgets(auxText, 99, stdin);
        removeBarN(auxText);
        for (int i = 0; i < 99; i++)
        {
            if (isdigit(auxText[i]) == 0)
            {
                todoOk = 0;
                break;
            }
            else if (strcmp((auxText + i + 1), "\0") == 0)
            {
                todoOk = 1;
                auxNumber = atoi(auxText);
                break;
            }
        }

        do
        {
            while (!todoOk)
            {
                printf("%s", menError);
                fflush(stdin);
                fgets(auxText, 99, stdin);
                removeBarN(auxText);
                for (int i = 0; i < 99; i++)
                {
                    if (isdigit(auxText[i]) == 0)
                    {
                        todoOk = 0;
                        break;
                    }
                    else if (strcmp((auxText + i + 1), "\0") == 0)
                    {
                        todoOk = 1;
                        auxNumber = atoi(auxText);
                        break;
                    }
                }
            }

            if (todoOk && auxNumber >= min && auxNumber <= max)
            {
                *number = auxNumber;
                todoOk = 1;
            }
            else
            {
                todoOk = 0;
            }
        } while (!todoOk);
    }
    else
    {
        todoOk = 0;
    }
    return todoOk;
}

int removeBarN(char *text)
{
    int todoOk = 0;

    for (int i = 0; i < 50; i++)
    {
        if (!strcmp((text + i), "\n"))
        {
            strcpy((text + i), "\0");
            todoOk = 1;
            break;
        }
    }

    return todoOk;
}

char *addSpaces(char *text, int len)
{

    for (int i = 0; i <= len; i++)
    {
        if (strlen(text) <= len)
        {
            if (!strcmp(text + i, "\0"))
            {
                strcpy((text + i), " ");
            }
        }
        else if (!strcmp(text + len + 1, "\0"))
        {
            break;
        }
        else
        {
            strcpy((text + len + 1), "\0");
        }
    }
    return text;
}

int ordenarStrings(char *array)
{
    int todoOk = 0;

    if (array != NULL)
    {
        for(int i = 0; i < 99; i++){
            if(!strcmp(array+i,"\0")){
                break;
            }else{
                array[i] = tolower(array[i]);
            }
        }
        array[0] = toupper(array[0]);
        todoOk = 1;
    }
return todoOk;
}
