/*
** EPITECH PROJECT, 2025
** my_radar
** File description:
** create_circleshape
*/

#include "my.h"

sfCircleShape *create_circle(int x, int y, float radius)
{
    sfCircleShape *circle = sfCircleShape_create();

    sfCircleShape_setRadius(circle, radius);
    sfCircleShape_setOutlineColor(circle, sfWhite);
    sfCircleShape_setFillColor(circle, sfTransparent);
    sfCircleShape_setOutlineThickness(circle, 1);
    sfCircleShape_setPosition(circle, (sfVector2f){x, y});
    return circle;
}
