/*
** EPITECH PROJECT, 2024
** make button
** File description:
** Nothing
*/

#include "../include/my.h"

void draw_paper(sfRenderWindow *win)
{
    sfRectangleShape *paper = sfRectangleShape_create();

    sfRectangleShape_setSize(paper, (sfVector2f){1440, 900});
    sfRectangleShape_setFillColor(paper, sfWhite);
    sfRectangleShape_setOutlineColor(paper, sfBlack);
    sfRectangleShape_setOutlineThickness(paper, 1);
    sfRectangleShape_setPosition(paper, (sfVector2f){240, 200});
    sfRenderWindow_drawRectangleShape(win, paper, NULL);
    sfRectangleShape_destroy(paper);
}

void draw_toolbar(sfRenderWindow *win)
{
    sfRectangleShape *toolbar = sfRectangleShape_create();

    sfRectangleShape_setSize(toolbar, (sfVector2f){1920, 200});
    sfRectangleShape_setFillColor(toolbar, sfColor_fromRGB(240, 240, 240));
    sfRectangleShape_setPosition(toolbar, (sfVector2f){0, 0});
    sfRenderWindow_drawRectangleShape(win, toolbar, NULL);
    sfRectangleShape_destroy(toolbar);
}

void draw_button(sfRenderWindow *win, sfVector2f size, sfVector2f pos,
                sfColor col, const char *label)
{
    sfRectangleShape *btn = sfRectangleShape_create();
    sfFont *font = sfFont_createFromFile("asset/mainF.otf");
    sfText *text = sfText_create();

    sfRectangleShape_setSize(btn, size);
    sfRectangleShape_setFillColor(btn, col);
    sfRectangleShape_setOutlineThickness(btn, 1);
    sfRectangleShape_setPosition(btn, pos);
    sfRenderWindow_drawRectangleShape(win, btn, NULL);
    sfText_setString(text, label);
    sfText_setFont(text, font);
    sfText_setCharacterSize(text, 20);
    sfText_setPosition(text, (sfVector2f){pos.x + 10, pos.y + 10});
    sfRenderWindow_drawText(win, text, NULL);
    sfRectangleShape_destroy(btn);
    sfText_destroy(text);
    sfFont_destroy(font);
}

void draw_palette(sfRenderWindow *win)
{
    sfVector2f size = {50, 50};
    sfVector2f start = {1350, 50};
    sfColor colors[18] = {
        sfColor_fromRGB(0, 0, 0), sfColor_fromRGB(128, 128, 128),
        sfColor_fromRGB(255, 0, 0), sfColor_fromRGB(255, 165, 0),
        sfColor_fromRGB(255, 255, 0), sfColor_fromRGB(0, 128, 0),
        sfColor_fromRGB(0, 0, 255), sfColor_fromRGB(128, 0, 128),
        sfColor_fromRGB(255, 255, 255), sfColor_fromRGB(165, 42, 42),
        sfColor_fromRGB(255, 192, 203), sfColor_fromRGB(255, 215, 0),
        sfColor_fromRGB(173, 216, 230), sfColor_fromRGB(240, 230, 140),
        sfColor_fromRGB(0, 255, 255), sfColor_fromRGB(75, 0, 130),
        sfColor_fromRGB(192, 192, 192), sfColor_fromRGB(230, 230, 250)
    };

    for (int i = 0; i < 18; ++i) {
        sfVector2f pos = {start.x + (i % 9) * (size.x + 10),
                        start.y + (i / 9) * (size.y + 10)};
        draw_button(win, size, pos, colors[i], "");
    }
}

CircleNode *create_node(sfVector2f pos, float rad, sfColor col)
{
    CircleNode *node = malloc(sizeof(CircleNode));

    node->circle = sfCircleShape_create();
    sfCircleShape_setRadius(node->circle, rad);
    sfCircleShape_setFillColor(node->circle, col);
    sfCircleShape_setPosition(node->circle, pos);
    node->next = NULL;
    return node;
}
