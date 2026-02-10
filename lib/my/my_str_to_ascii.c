/*
** EPITECH PROJECT, 2025
** lib
** File description:
** str to ASCII
*/

#include <stdio.h>
#include <stdlib.h>
#include "my2.h"

int str_to_ascii(const char *str)
{
    char *res = malloc(sizeof(char) * my_strlen(str) + 1);
    int res2 = 0;

    for (int i = 0; str[i] != '\0'; i++) {
        res2 += (int)str[i];
    }
    return res2;
}
