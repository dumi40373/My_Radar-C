/*
** EPITECH PROJECT, 2025
** my_radar
** File description:
** create texture
*/

#include "my.h"

sfTexture *create_texture(char *image_path)
{
    sfTexture *texture;

    texture = sfTexture_createFromFile(image_path, NULL);
    return texture;
}
