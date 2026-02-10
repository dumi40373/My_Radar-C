/*
** EPITECH PROJECT, 2025
** my_radar
** File description:
** initialize structures
*/

#include "my.h"

background_t initialize_back(void)
{
    background_t back_data = {
        .background_text = NULL,
        .background_sp = NULL
    };

    return back_data;
}

aircrafts_t initialize_aircrafts(void)
{
    aircrafts_t crafts_data = {
        .aircraft_txt = NULL,
        .aircraft_sp = NULL
    };

    return crafts_data;
}

towers_t initialize_towers(void)
{
    towers_t towers_data = {
        .tower_txt = NULL,
        .tower_sp = NULL,
    };

    return towers_data;
}

window_t initialize_window(void)
{
    window_t data = {
        .window = create_window(),
        .list_towers = NULL,
        .list_aircrafts = NULL
    };

    return data;
}
