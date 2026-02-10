/*
** EPITECH PROJECT, 2025
** my_radar
** File description:
** draw_towers
*/

#include "my.h"

void set_tower_sp(tower_node_t *current, towers_t *towers_data)
{
    sfVector2u size;

    current->tower_sp = create_sprite(towers_data->tower_txt,
        current->x_pos, current->y_pos,
        &((sfVector2f){0.078125, 0.078125}));
    size = sfTexture_getSize(towers_data->tower_txt);
    sfSprite_setOrigin(current->tower_sp,
        (sfVector2f){size.x / 2.f, size.y / 2.f});
}

void draw_towers(window_t *data, tower_list_t *towers, towers_t *towers_data)
{
    tower_node_t *current = towers->list;

    while (current) {
        if (!current->tower_sp)
            set_tower_sp(current, towers_data);
        if (!current->circle) {
            current->circle = create_circle(0, 0, current->radius);
            sfCircleShape_setOrigin(current->circle,
                (sfVector2f){current->radius, current->radius});
            sfCircleShape_setPosition(current->circle,
                (sfVector2f){current->x_pos, current->y_pos});
        }
        sfRenderWindow_drawCircleShape(data->window, current->circle, NULL);
        sfRenderWindow_drawSprite(data->window, current->tower_sp, NULL);
        current = current->next;
    }
}
