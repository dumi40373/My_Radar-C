/*
** EPITECH PROJECT, 2025
** str cat
** File description:
** str cat
*/

#include <unistd.h>
#include "my2.h"

char *my_strcat(char *dest, char const *src)
{
    int l = my_strlen(dest);

    for (int i = 0; src[i] != '\0'; i++) {
        dest[l + i] = src[i];
    }
    return dest;
}
