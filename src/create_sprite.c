/*
** EPITECH PROJECT, 2025
** my_radar
** File description:
** create sprite
*/

#include "my.h"

sfSprite *create_sprite(sfTexture *texture, int x, int y, sfVector2f *scale)
{
    sfSprite *sprite = sfSprite_create();

    sfSprite_setTexture(sprite, texture, sfTrue);
    sfSprite_setScale(sprite, *scale);
    sfSprite_setPosition(sprite, (sfVector2f){x, y});
    return sprite;
}
