#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

int requestDataTex(char *menInicio, char *menError, char *text, int len);
int requestDataNumFloat(char *menInicio, char *menError, float *number, int min, int max);
int requestDataNumInt(char *menInicio, char *menError, int *number, int min, int max);
char* addSpaces(char *text, int len);
int removeBarN(char *text);
int ordenarStrings(char *array);
