/*
** EPITECH PROJECT, 2024
** game
** File description:
** nothing
*/

#include "../include/my.h"

void handle_drawing(PaintApp *app)
{
    if (!app->isDraw) return;
    sfVector2i mouse_pos = sfMouse_getPositionRenderWindow(app->win);
    sfVector2f pos = {(float)mouse_pos.x - app->params.rad,
                      (float)mouse_pos.y - app->params.rad};
    if (mouse_pos.x >= app->params.pos.x &&
        mouse_pos.x <= app->params.pos.x + app->params.size.x &&
        mouse_pos.y >= app->params.pos.y &&
        mouse_pos.y <= app->params.pos.y + app->params.size.y) {
        sfColor color;
        if (app->tool == TOOL_PENCIL) {
            color = sfBlack;
        } else {
            color = sfWhite;
        }
        add_circle(&app->circ, pos, app->params.rad, color);
    }
}

void handle_toolbar_events(sfEvent *evt, PaintApp *app)
{
    if (evt->mouseButton.x >= 50 && evt->mouseButton.x <= 150) {
        if (evt->mouseButton.y >= 50 && evt->mouseButton.y <= 100) {
            app->tool = TOOL_PENCIL;
        }
        if (evt->mouseButton.y >= 110 && evt->mouseButton.y <= 160) {
            app->tool = TOOL_ERASER;
        }
    }
}

void handle_events(PaintApp *app)
{
    sfEvent evt;
    while (sfRenderWindow_pollEvent(app->win, &evt)) {
        if (evt.type == sfEvtClosed) sfRenderWindow_close(app->win);
        if (evt.type == sfEvtMouseButtonPressed) {
            handle_toolbar_events(&evt, app);
            app->isDraw = sfTrue;
        }
        if (evt.type == sfEvtMouseButtonReleased) app->isDraw = sfFalse;
        if (evt.type == sfEvtMouseMoved) handle_drawing(app);
    }
}

void render(PaintApp *app)
{
    sfRenderWindow_clear(app->win, sfWhite);
    draw_toolbar(app->win);
    draw_palette(app->win);
    draw_button(app->win, (sfVector2f){100, 50}, (sfVector2f){50, 50},
                sfColor_fromRGB(200, 200, 200), "Pencil");
    draw_button(app->win, (sfVector2f){100, 50}, (sfVector2f){50, 110},
                sfColor_fromRGB(200, 200, 200), "Eraser");
    draw_paper(app->win);
    draw_circles(app->win, app->circ);
    sfRenderWindow_display(app->win);
}

void add_condition_3(sfRenderWindow *win)
{
    PaintApp app = { win, NULL, {{240, 200}, {1440, 900}, sfBlack, 10.0f}, TOOL_PENCIL, sfFalse };
    while (sfRenderWindow_isOpen(win)) {
        handle_events(&app);
        render(&app);
    }
}
