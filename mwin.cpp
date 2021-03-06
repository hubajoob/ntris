#include "mwin.h"

mwin::mwin() {
    int x, y;
    initscr();

    if(has_colors() != TRUE)
    {
        endwin();
        printf("ERROR, your terminal can't display colors.\n");
    }
    getmaxyx(stdscr, y, x);
    if(x < WIDTH || y < HEIGHT) {
        endwin();
        printf("ERROR, your terminal is too small. (min %ux%u)\n", WIDTH, HEIGHT);
    }
    clear();
    noecho();
    start_color();

    init_pair(0, COLOR_WHITE, COLOR_BLACK);
    init_pair(1, COLOR_BLACK, COLOR_RED);
    init_pair(2, COLOR_BLACK, COLOR_YELLOW);
    init_pair(3, COLOR_BLACK, COLOR_BLUE);
    init_pair(4, COLOR_BLACK, COLOR_GREEN);
    init_pair(5, COLOR_BLACK, COLOR_CYAN);
    init_pair(6, COLOR_BLACK, COLOR_MAGENTA);
    init_pair(7, COLOR_BLACK, COLOR_WHITE);

    curs_set(0); // remove curser
    refresh();
    mainwin    = newwin(32, 32, 0, 0);
    previewwin = newwin(9, 16, 0, 35);
    scorewin   = newwin(10, 20, 12, 35);
    box(mainwin, 0, 0);
}
