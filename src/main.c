#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#include <ncurses.h>

#include "Views.h"
#include "render.h"

#define KEY_CONTROL_C 3


int main(int argc, char** argv) {
  if (argc > 1) {
    if (strcmp(argv[1], "-v") || strcmp(argv[1], "--version")) {
      printf("The Phi Project - terraview\nVERSION: %s\n", VERSION);
      return EXIT_SUCCESS;
    }

    printf("Unrecognized Argument `%s`", argv[1]);
    return EXIT_FAILURE;
  }

  initscr(); // create `stdscr` object
  raw(); // gather all key presses without allowing C to process signals
  noecho(); // don't automatically display the chars that users type
  curs_set(0); // make cursor invisible
  
  halfdelay(3); // wait 300ms per cycle

  int maxy, maxx;
  getmaxyx(stdscr, maxy, maxx);

  if (maxy < EARTH_HEIGHT || maxx < EARTH_LENGTH) {
    printf("Error: terminal window not large enough\n\t must be at least %ix%i\n", EARTH_LENGTH, EARTH_HEIGHT);
    return EXIT_FAILURE;
  }

  /* INIT DONE, NOW LOGIC */

  int starty = (maxy - EARTH_HEIGHT) / 2;
  int startx = (maxx - EARTH_LENGTH) / 2;

  WINDOW* win = NULL;

  int view = 0;

  int ch;
  while ((ch = getch()) != 'q' && ch != KEY_CONTROL_C) {
    if (win) werase(win);

    if (view >= MERCATOR_PROJECTION_LENGTH) view = 0;

    win = renderEarth(starty, startx, view);
    if (win) wrefresh(win);
    refresh();

    view++;
  }

  /* LOGIC DONE, NOW EXIT */

  reset_shell_mode();
  endwin();

  return EXIT_SUCCESS;
}
