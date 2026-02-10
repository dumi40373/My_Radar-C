/*
** EPITECH PROJECT, 2025
** my_radar
** File description:
** create_rect
*/

#include "my.h"

sfRectangleShape *create_rect(int x, int y)
{
    sfRectangleShape *rect = sfRectangleShape_create();

    sfRectangleShape_setPosition(rect, (sfVector2f){x, y});
    sfRectangleShape_setSize(rect, (sfVector2f){18.0, 22.0});
    sfRectangleShape_setOutlineColor(rect, sfGreen);
    sfRectangleShape_setFillColor(rect, sfTransparent);
    sfRectangleShape_setOutlineThickness(rect, 1);
    return rect;
}
