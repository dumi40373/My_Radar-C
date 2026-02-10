/*
** EPITECH PROJECT, 2025
** my_radar
** File description:
** is_intersecting
*/

#include "my.h"


static int rects_intersect(const sfFloatRect *a, const sfFloatRect *b)
{
    float a_left = a->left;
    float a_right = a->left + a->width;
    float a_top = a->top;
    float a_bottom = a->top + a->height;
    float b_left = b->left;
    float b_right = b->left + b->width;
    float b_top = b->top;
    float b_bottom = b->top + b->height;

    if (a_right <= b_left)
        return 0;
    if (b_right <= a_left)
        return 0;
    if (a_bottom <= b_top)
        return 0;
    if (b_bottom <= a_top)
        return 0;
    return 1;
}

void in_area_verif(aircraft_node_t *current, aircraft_node_t *node)
{
    if (node != current && node->is_alive &&
        rects_intersect(&current->box, &node->box)) {
        if (current->in_control && node->in_control)
            return;
        current->is_alive = 0;
        node->is_alive = 0;
        return;
    }
}

void is_intersecting(aircraft_node_t *current, aircraft_list_t *list)
{
    aircraft_node_t *node = list->list;

    if (!current->is_alive)
        return;
    while (node) {
        in_area_verif(current, node);
        node = node->next;
    }
}
