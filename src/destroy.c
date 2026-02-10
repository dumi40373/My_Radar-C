/*
** EPITECH PROJECT, 2025
** my_radar
** File description:
** destroy
*/

#include "my.h"

void destroy_lists(aircraft_node_t *current_craft,
    tower_node_t *current_tower)
{
    while (current_craft) {
        sfClock_destroy(current_craft->delay_clock);
        sfClock_destroy(current_craft->move_clock);
        sfSprite_destroy(current_craft->aircraft_sp);
        current_craft = current_craft->next;
    }
    while (current_tower) {
        sfSprite_destroy(current_tower->tower_sp);
        current_tower = current_tower->next;
    }
}

void destroy(window_t *data, background_t *back_data,
    aircrafts_t *crafts_data, towers_t *towers_data)
{
    aircraft_list_t *aircrafts = data->list_aircrafts;
    tower_list_t *towers = data->list_towers;
    aircraft_node_t *current_craft = aircrafts->list;
    tower_node_t *current_tower = towers->list;

    sfSprite_destroy(back_data->background_sp);
    sfTexture_destroy(back_data->background_text);
    sfSprite_destroy(crafts_data->aircraft_sp);
    sfTexture_destroy(crafts_data->aircraft_txt);
    sfSprite_destroy(towers_data->tower_sp);
    sfTexture_destroy(towers_data->tower_txt);
    sfRenderWindow_destroy(data->window);
    destroy_lists(current_craft, current_tower);
}
