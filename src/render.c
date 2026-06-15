#include "render.h"

#include <stdlib.h>
#include <string.h>

#include <ncurses.h>

#include "Views.h"

#define MAX(a, b) ((a > b) ? a : b)
#define MIN(a, b) ((a < b) ? a : b)


WINDOW* renderEarth(int starty, int startx, int view) {
  refresh();

  WINDOW* win = newwin(EARTH_HEIGHT, EARTH_LENGTH, starty, startx);
  if (!win) return NULL;

  int copy_len = MIN(EARTH_LENGTH, (MERCATOR_PROJECTION_LENGTH - view));

  for (int row = 0; row < MERCATOR_PROJECTION_HEIGHT; row++) {
    char* line = MERCATOR_PROJECTION[row];
    char buffer[EARTH_LENGTH + 1] = {0};

    strncpy(buffer, line + view, copy_len);

    if (copy_len < EARTH_LENGTH) {
      strncpy(buffer + copy_len - 1, line, EARTH_LENGTH - copy_len); // take from the beginning of the line
    }

    buffer[EARTH_LENGTH] = '\0';

    mvwaddstr(win, row, 0, buffer);
  }

  return win;
}
