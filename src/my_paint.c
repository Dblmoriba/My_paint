/*
** EPITECH PROJECT, 2024
** my_hunter
** File description:
** nothing
*/

#include "../include/my.h"

void open_window(sfRenderWindow *window)
{
    sfVideoMode mode = {1920, 1080, 32};
    sfEvent event;
    sfUint32 style = sfResize | sfClose;
    sfRenderTexture *canvas = sfRenderTexture_create(1440, 900, sfFalse);

    window = sfRenderWindow_create(mode, "My_paint", style, NULL);
    while (sfRenderWindow_isOpen(window)){
    add_condition_3(window);
    }
    sfRenderWindow_destroy(window);
}

void add_circle(CircleNode **head, sfVector2f pos, float rad, sfColor col)
{
    CircleNode *new_node = create_node(pos, rad, col);
    new_node->next = *head;
    *head = new_node;
}

void draw_circles(sfRenderWindow *win, CircleNode *head)
{
    for (CircleNode *current = head; current != NULL; current = current->next) {
        sfRenderWindow_drawCircleShape(win, current->circle, NULL);
    }
}

/*void add_background(sfRenderWindow *window)
{
    sfVector2f scale_button = {0.09, 0.09};
    sfTexture *backgroundTexture = sfTexture_createFromFile("w.png", NULL);
    sfSprite *backgroundSprite = sfSprite_create();
    sfTexture *buttonTexture = sfTexture_createFromFile("asset/p.png", NULL);
    sfSprite *button = sfSprite_create();
    sfVector2f pos_button = {800, 430};

    sfSprite_setTexture(button, buttonTexture, sfTrue);
    sfSprite_setScale(button, scale_button);
    sfSprite_setPosition(button, pos_button);
    sfSprite_setTexture(backgroundSprite, backgroundTexture, sfTrue);
    sfRenderWindow_drawSprite(window, backgroundSprite, NULL);
    sfRenderWindow_drawSprite(window, button, NULL);
    sfSprite_destroy(backgroundSprite);
    sfSprite_destroy(button);
    sfTexture_destroy(backgroundTexture);
    sfTexture_destroy(buttonTexture);
}*/
