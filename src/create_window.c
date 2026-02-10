/*
** EPITECH PROJECT, 2025
** my_radar
** File description:
** create window
*/

#include "my.h"

sfRenderWindow *create_window(void)
{
    sfVideoMode mode = {1920, 1080, 32};
    sfUint32 style = {sfClose | sfResize};
    sfRenderWindow *my_window;

    my_window = sfRenderWindow_create(mode, "my_radar", style, NULL);
    return my_window;
}
