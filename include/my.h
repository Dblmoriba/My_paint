/*
** EPITECH PROJECT, 2024
** my
** File description:
** Nothing
*/

#include <SFML/Audio.h>
#include <SFML/Graphics.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <SFML/Audio.h>
#include <stdbool.h>
#include <SFML/Graphics.h>
#include <stdlib.h>

#ifndef MY_H
    #define MY_H

typedef enum {
    TOOL_PENCIL,
    TOOL_ERASER
} ToolType;

typedef struct CircleNode {
    sfCircleShape *circle;
    struct CircleNode *next;
} CircleNode;

typedef struct {
    sfVector2f pos;
    sfVector2f size;
    sfColor color;
    float rad;
} DrawParams;

typedef struct {
    sfRenderWindow *win;
    CircleNode *circ;
    DrawParams params;
    ToolType tool;
    sfBool isDraw;
} PaintApp;

void open_window(sfRenderWindow *window);
void add_background(sfRenderWindow *window);
void position(sfRenderWindow *window);
void add_condition_3(sfRenderWindow *window);

void add_circle(CircleNode **head, sfVector2f pos, float rad, sfColor col);
void draw_circles(sfRenderWindow *win, CircleNode *head);

void add_circle(CircleNode **head, sfVector2f pos, float rad, sfColor col);
void draw_circles(sfRenderWindow *win, CircleNode *head);
void handle_drawing(PaintApp *app);
void handle_toolbar_events(sfEvent *evt, PaintApp *app);
void handle_events(PaintApp *app);
void render(PaintApp *app);
void add_condition_3(sfRenderWindow *win);

void draw_paper(sfRenderWindow *win);
void draw_toolbar(sfRenderWindow *win);
void draw_button(sfRenderWindow *win, sfVector2f size, sfVector2f pos,
                sfColor col, const char *label);
void draw_palette(sfRenderWindow *win);
CircleNode *create_node(sfVector2f pos, float rad, sfColor col);
#endif
