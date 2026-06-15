#include "render.h"

#include <stdlib.h>
#include <string.h>

#include <ncurses.h>

#include "Views.h"

#define MIN(a, b) ((a < b) ? a : b)

const int SYMMETRIC_CUTOFFS[] = {
  79, 55, 45, 37, 31, 27, 23, 19, 15, 13, 11, 9, 7, 5, 3, 3, 1, 1, 1, 1,
  1, 1, 1, 1, 3, 3, 5, 7, 9, 11, 13, 15, 19, 23, 27, 31, 37, 45, 55, 79};

WINDOW* renderEarth(int starty, int startx, int view) {
  refresh();

  WINDOW* win = newwin(EARTH_HEIGHT, EARTH_LENGTH, starty, startx);
  if (!win) return NULL;

  const int copy_len = MIN(EARTH_LENGTH, MERCATOR_PROJECTION_LENGTH - view);

  for (int row = 0; row < EARTH_HEIGHT; row++) {
    char* line = MERCATOR_PROJECTION[row];
    char buffer[EARTH_LENGTH + 1] = {0};

     // copy the rest of the characters in line, rather than an arbitrary number
    strncpy(buffer, line + view, copy_len);

    if (view + EARTH_LENGTH > MERCATOR_PROJECTION_LENGTH) { // we need to wrap around
      
    }
    
    buffer[EARTH_LENGTH] = '\0';

    memset(buffer, ' ', SYMMETRIC_CUTOFFS[row] / 2);
    memset(buffer + EARTH_LENGTH - (SYMMETRIC_CUTOFFS[row] / 2), ' ', SYMMETRIC_CUTOFFS[row] / 2);

    mvwaddstr(win, row, 0, buffer);
    mvwaddch(win, row, SYMMETRIC_CUTOFFS[row] / 2, '#' | A_BOLD);
    mvwaddch(win, row, EARTH_LENGTH - (SYMMETRIC_CUTOFFS[row] / 2) - 1, '#' | A_BOLD);
  }

  return win;
}
