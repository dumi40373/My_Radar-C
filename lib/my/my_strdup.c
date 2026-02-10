/*
** EPITECH PROJECT, 2025
** my lib
** File description:
** strdup
*/

#include "my2.h"
#include <stdlib.h>

char *my_strdup(char *str)
{
    char *res = malloc(sizeof(char) * (my_strlen(str) + 1));
    int i = 0;

    for (; str[i]; i++)
        res[i] = str[i];
    res[i] = '\0';
    return res;
}
