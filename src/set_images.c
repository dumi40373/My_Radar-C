/*
** EPITECH PROJECT, 2025
** my_radar
** File description:
** set images
*/

#include "my.h"

void set_images(background_t *back_data, aircrafts_t *crafts_data,
    towers_t *towers_data)
{
    back_data->background_text = create_texture("background_map.png");
    back_data->background_sp = create_sprite(back_data->background_text,
        0, 0, &((sfVector2f){1.25, 1.0546875}));
    crafts_data->aircraft_txt = create_texture("aircraft.png");
    towers_data->tower_txt = create_texture("tower.png");
}
