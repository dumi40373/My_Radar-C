/*
** EPITECH PROJECT, 2025
** my_radar
** File description:
** draw sprites
*/

#include "my.h"

static sfVector2f normalize(const sfVector2f *v)
{
    float len = sqrt(v->x * v->x + v->y * v->y);

    if (len == 0)
        return (sfVector2f){0, 0};
    return (sfVector2f){v->x / len, v->y / len};
}

static void handle_delay(aircraft_node_t *current)
{
    sfTime t = sfClock_getElapsedTime(current->delay_clock);
    float sec = t.microseconds / 1000000.0f;

    if (sec >= current->delay) {
        current->is_delay = 1;
        sfClock_restart(current->move_clock);
    }
}

static sfVector2f set_direction(aircraft_node_t *current)
{
    sfVector2f direction = (sfVector2f){
        current->x_end - current->position.x,
        current->y_end - current->position.y};

    return direction;
}

static float set_distance(sfVector2f *direction)
{
    float distance = sqrt(
        direction->x * direction->x +
        direction->y * direction->y);

    return distance;
}

void update_control_zone(aircraft_node_t *plane, tower_list_t *towers)
{
    tower_node_t *tower = towers->list;
    float dx = 0.0;
    float dy = 0.0;
    float dist = 0.0;

    plane->in_control = 0;
    while (tower) {
        dx = plane->position.x - tower->x_pos;
        dy = plane->position.y - tower->y_pos;
        dist = sqrt(dx * dx + dy * dy);
        if (dist <= tower->radius) {
            plane->in_control = 1;
            return;
        }
        tower = tower->next;
    }
}

static void set_final_current(aircraft_node_t *current)
{
    current->position.x = current->x_end;
    current->position.y = current->y_end;
    current->box.left = current->x_end;
    current->box.top = current->y_end;
    current->is_alive = 0;
}

static void set_intersect_current(aircraft_node_t *current,
    sfVector2f *direction, float dt, window_t *data)
{
    sfVector2f dir;

    dir = normalize(direction);
    current->position.x += dir.x * current->speed * dt;
    current->position.y += dir.y * current->speed * dt;
    current->box.left += dir.x * current->speed * dt;
    current->box.top += dir.y * current->speed * dt;
    update_control_zone(current, data->list_towers);
    is_intersecting(current, data->list_aircrafts);
}

static void handle_movement(aircraft_node_t *current, window_t *data)
{
    sfTime t = sfClock_getElapsedTime(current->move_clock);
    float dt = t.microseconds / 1000000.0f;
    sfVector2f direction;
    float distance;

    current->box.left = current->position.x;
    current->box.top = current->position.y;
    direction = set_direction(current);
    distance = set_distance(&direction);
    if (distance <= current->speed * dt) {
        set_final_current(current);
    } else {
        set_intersect_current(current, &direction, dt, data);
    }
    sfSprite_setPosition(current->aircraft_sp, current->position);
    sfRectangleShape_setPosition(current->rect, current->position);
    sfClock_restart(current->move_clock);
}

void drawing_sprites(window_t *data, aircraft_node_t *current)
{
    if (current->is_alive) {
        sfRenderWindow_drawSprite(data->window,
            current->aircraft_sp, NULL);
        sfRenderWindow_drawRectangleShape(data->window, current->rect, NULL);
    }
}

void draw_crafts(aircraft_list_t *aircrafts,
    aircrafts_t *crafts_data, window_t *data)
{
    aircraft_node_t *current;

    current = aircrafts->list;
    while (current) {
        if (!current->aircraft_sp) {
            current->aircraft_sp = create_sprite(crafts_data->aircraft_txt,
                current->x_start, current->y_start,
                &((sfVector2f){0.0248, 0.0292}));
            current->rect = create_rect(current->x_start, current->y_start);
        }
        if (current->is_delay == 0)
            handle_delay(current);
        if (current->is_delay == 1) {
            handle_movement(current, data);
            drawing_sprites(data, current);
        }
        current = current->next;
    }
}
