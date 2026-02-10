/*
** EPITECH PROJECT, 2025
** handle_shortest
** File description:
** handle shortest for printf
*/

#include <stdarg.h>
#include "my2.h"

void handle_shortest(va_list ap)
{
    double d = va_arg(ap, double);

    my_shortest(d);
}
