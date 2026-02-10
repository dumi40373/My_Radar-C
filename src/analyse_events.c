/*
** EPITECH PROJECT, 2025
** my_radar
** File description:
** analyse_events
*/

#include "my.h"

void analyse_events(sfEvent *event, window_t *data)
{
    if (event->type == sfEvtClosed)
        sfRenderWindow_close(data->window);
}
