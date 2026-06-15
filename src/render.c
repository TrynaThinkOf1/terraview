#include "render.h"

#include <stdlib.h>
#include <string.h>

#include <ncurses.h>

#include "Views.h"

#define MAX(a, b) ((a > b) ? a : b)
#define MIN(a, b) ((a < b) ? a : b)

const int OFFSETS[] = {19, 18, 17, 16, 15, 14, 13, 12, 11, 10, 9, 8, 7, 6, 5, 4, 3, 2, 1, 0, 0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19};
const char* const SPACES = "                     "; // so that I can copy at most 20 spaces for whitespace


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

    strncpy(buffer, SPACES, OFFSETS[row]); // TRACE TRAP IS HERE
    strncpy(&buffer[EARTH_LENGTH] - OFFSETS[row], SPACES, OFFSETS[row]); // TRACE TRAP IS HERE

    mvwaddstr(win, row, 0, buffer);
  }

  return win;
}
