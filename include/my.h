/*
** EPITECH PROJECT, 2025
** my.h
** File description:
** my.h
*/

#ifndef MY_H
    #define MY_H
    #include <stdarg.h>
    #include <dirent.h>
    #include <SFML/Graphics.h>
    #include <SFML/Audio.h>
    #include <SFML/Graphics/Export.h>
    #include <SFML/Graphics/Color.h>
    #include <SFML/Graphics/Rect.h>
    #include <SFML/Graphics/Types.h>
    #include <SFML/Graphics/PrimitiveType.h>
    #include <SFML/Graphics/RenderStates.h>
    #include <SFML/Graphics/Vertex.h>
    #include <SFML/Window/Event.h>
    #include <SFML/Window/VideoMode.h>
    #include <SFML/Window/WindowHandle.h>
    #include <SFML/Window/Window.h>
    #include <SFML/System/Vector2.h>
    #include <stddef.h>
    #include <stdlib.h>
    #include <stdio.h>
    #include "../include/my2.h"
    #include <math.h>
typedef struct background {
    sfTexture *background_text;
    sfSprite *background_sp;
} background_t;
typedef struct aircrafts {
    sfTexture *aircraft_txt;
    sfSprite *aircraft_sp;
} aircrafts_t;
typedef struct aircraft_node {
    int x_start;
    int y_start;
    int x_end;
    int y_end;
    int speed;
    int delay;
    int id;
    int is_delay;
    int is_alive;
    int in_control;
    sfFloatRect box;
    sfFloatRect *hitbox;
    sfRectangleShape *rect;
    sfVector2f position;
    sfClock *delay_clock;
    sfClock *move_clock;
    sfSprite *aircraft_sp;
    struct aircraft_node *next;
    struct aircraft_node *prev;
} aircraft_node_t;
typedef struct aircraft_list {
    aircraft_node_t *list;
    int next_id;
} aircraft_list_t;
typedef struct towers {
    sfTexture *tower_txt;
    sfSprite *tower_sp;
} towers_t;
typedef struct tower_node {
    int x_pos;
    int y_pos;
    int radius;
    int id;
    sfSprite *tower_sp;
    sfCircleShape *circle;
    struct tower_node *next;
    struct tower_node *prev;
} tower_node_t;
typedef struct tower_list {
    tower_node_t *list;
    int next_id;
} tower_list_t;
typedef struct window {
    sfRenderWindow *window;
    tower_list_t *list_towers;
    aircraft_list_t *list_aircrafts;
} window_t;
int execute_window(char *file);
sfRenderWindow *create_window(void);
window_t initialize_window(void);
background_t initialize_back(void);
aircrafts_t initialize_aircrafts(void);
towers_t initialize_towers(void);
sfTexture *create_texture(char *image_path);
sfSprite *create_sprite(sfTexture *texture, int x, int y, sfVector2f *scale);
void destroy(window_t *data, background_t *back_data,
    aircrafts_t *crafts_data, towers_t *towers_data);
void analyse_events(sfEvent *event, window_t *data);
void set_images(background_t *back_data, aircrafts_t *crafts_data,
    towers_t *towers_data);
char *read_file(const char *filename);
int get_infos(char *file_path, window_t *data, aircrafts_t *crafts_data);
void draw_crafts(aircraft_list_t *aircrafts,
    aircrafts_t *crafts_data, window_t *data);
void is_intersecting(aircraft_node_t *current, aircraft_list_t *list);
int del_aircrafts(aircraft_list_t *aircrafts, int del_id);
void draw_towers(window_t *data, tower_list_t *towers, towers_t *tower_sprite);
sfRectangleShape *create_rect(int x, int y);
sfCircleShape *create_circle(int x, int y, float radius);
#endif
