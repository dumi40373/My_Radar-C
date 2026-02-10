/*
** EPITECH PROJECT, 2025
** libmy
** File description:
** str to int
*/

#include <stdio.h>

int my_str_to_int(char *str)
{
    int nb = 0;

    for (int i = 0; str[i]; i++) {
        if (i != 0)
            nb *= 10;
        nb += str[i] - '0';
    }
    return nb;
}
