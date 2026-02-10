/*
** EPITECH PROJECT, 2025
** my_radar
** File description:
** execute
*/

#include "my.h"

void set_sprites(window_t *data, background_t *back_data,
    aircrafts_t *crafts_data, towers_t *towers_data)
{
    sfRenderWindow_clear(data->window, sfBlack);
    sfRenderWindow_drawSprite(data->window, back_data->background_sp, NULL);
    draw_crafts(data->list_aircrafts, crafts_data, data);
    draw_towers(data, data->list_towers, towers_data);
    sfRenderWindow_display(data->window);
}

void open_window(window_t *data, background_t *back_data,
    aircrafts_t *crafts_data, towers_t *towers_data)
{
    sfEvent event;
    aircraft_node_t *current;

    sfRenderWindow_setFramerateLimit(data->window, 60);
    while (sfRenderWindow_isOpen(data->window)) {
        while (sfRenderWindow_pollEvent(data->window, &event)) {
            analyse_events(&event, data);
        }
        set_sprites(data, back_data,
            crafts_data, towers_data);
    }
    destroy(data, back_data, crafts_data, towers_data);
}

int execute_window(char *file)
{
    background_t back_data = initialize_back();
    aircrafts_t crafts_data = initialize_aircrafts();
    towers_t towers_data = initialize_towers();
    window_t data = initialize_window();

    if (get_infos(file, &data, &crafts_data) == 84)
        return 84;
    set_images(&back_data, &crafts_data, &towers_data);
    open_window(&data, &back_data, &crafts_data, &towers_data);
    return 0;
}
