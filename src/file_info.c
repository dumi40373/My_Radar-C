/*
** EPITECH PROJECT, 2025
** my_radar
** File description:
** get_file_info
*/

#include "my.h"

static void add_towers(tower_list_t *towers, char **infos)
{
    tower_node_t *new = malloc(sizeof(tower_node_t));

    new->x_pos = my_getnbr(infos[1]);
    new->y_pos = my_getnbr(infos[2]);
    new->radius = my_getnbr(infos[3]);
    new->id = towers->next_id;
    towers->next_id++;
    new->tower_sp = NULL;
    new->circle = NULL;
    new->next = towers->list;
    new->prev = NULL;
    if (towers->list)
        new->prev = new;
    towers->list = new;
}

static void add_boxes(aircraft_node_t *new)
{
    new->position = (sfVector2f){new->x_start, new->y_start};
    new->box.left = new->x_start;
    new->box.top = new->y_start;
    new->box.width = 20.0f;
    new->box.height = 20.0f;
    new->hitbox = &new->box;
    new->is_delay = 0;
    new->is_alive = 1;
    new->in_control = 0;
    new->rect = NULL;
}

static void add_aircrafts(aircraft_list_t *aircrafts, char **infos,
    aircrafts_t *crafts_data)
{
    aircraft_node_t *new = malloc(sizeof(aircraft_node_t));

    new->x_start = my_getnbr(infos[1]);
    new->y_start = my_getnbr(infos[2]);
    new->x_end = my_getnbr(infos[3]);
    new->y_end = my_getnbr(infos[4]);
    new->speed = my_getnbr(infos[5]);
    new->delay = my_getnbr(infos[6]);
    new->id = aircrafts->next_id;
    aircrafts->next_id++;
    add_boxes(new);
    new->delay_clock = sfClock_create();
    new->move_clock = sfClock_create();
    new->aircraft_sp = NULL;
    new->next = aircrafts->list;
    new->prev = NULL;
    if (aircrafts->list)
        aircrafts->list->prev = new;
    aircrafts->list = new;
}

int del_aircrafts(aircraft_list_t *aircrafts, int del_id)
{
    aircraft_node_t *current = aircrafts->list;
    aircraft_node_t *previous = current;

    if (current->id == del_id) {
        aircrafts->list = current->next;
        free(current);
        return 0;
    }
    while (current && current->id != del_id) {
        previous = current;
        current = current->next;
    }
    previous->next = current->next;
    free(current);
    return 0;
}

int get_tab_len(char **tab)
{
    int len = 0;

    for (int i = 0; tab[i]; i++)
        len++;
    return len;
}

int error_handling(char **parsed_lines)
{
    char **infos;
    int len;

    for (int i = 0; parsed_lines[i]; i++) {
        if (parsed_lines[i][0] != 'A' && parsed_lines[i][0] != 'T')
            return 84;
        infos = my_str_to_word_array(parsed_lines[i], " ");
        if (!infos)
            return 84;
        len = get_tab_len(infos);
        if (parsed_lines[i][0] == 'A' && len != 7)
            return 84;
        if (parsed_lines[i][0] == 'T' && len != 4)
            return 84;
    }
    return 0;
}

static void init_lists_heads(tower_list_t *towers, aircraft_list_t *aircrafts)
{
    towers->list = NULL;
    towers->next_id = 0;
    aircrafts->list = NULL;
    aircrafts->next_id = 0;
}

static void add_in_lists(char **infos, aircraft_list_t *aircrafts,
    aircrafts_t *crafts_data, tower_list_t *towers)
{
    if (infos[0][0] == 'A')
        add_aircrafts(aircrafts, infos, crafts_data);
    if (infos[0][0] == 'T')
        add_towers(towers, infos);
}

int get_infos(char *file_path, window_t *data, aircrafts_t *crafts_data)
{
    char *buffer;
    char **parsed_line;
    tower_list_t *towers = malloc(sizeof(tower_list_t));
    aircraft_list_t *aircrafts = malloc(sizeof(aircraft_list_t));
    char **infos;

    buffer = read_file(file_path);
    if (!buffer)
        return 84;
    parsed_line = my_str_to_word_array(buffer, "\n");
    if (error_handling(parsed_line) == 84)
        return 84;
    init_lists_heads(towers, aircrafts);
    for (int i = 0; parsed_line[i]; i++) {
        infos = my_str_to_word_array(parsed_line[i], " ");
        add_in_lists(infos, aircrafts, crafts_data, towers);
    }
    data->list_towers = towers;
    data->list_aircrafts = aircrafts;
    return 0;
}
