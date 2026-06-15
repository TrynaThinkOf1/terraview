#include "render.h"

#include <stdlib.h>
#include <string.h>

#include <ncurses.h>

#include "Views.h"

#define MIN(a, b) ((a < b) ? a : b)

WINDOW* renderEarth(int starty, int startx, int view) {
  refresh();

  WINDOW* win = newwin(EARTH_HEIGHT, EARTH_LENGTH, starty, startx);
  if (!win) return NULL;

  return win;
}
