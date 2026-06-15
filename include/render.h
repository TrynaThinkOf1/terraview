#ifndef TERRAVIEW_RENDER_H
#define TERRAVIEW_RENDER_H

#include <string.h>

#include <ncurses.h>

#include "Views.h"

/// @ Actually create the earth WINDOW*
/// @ The loop in `main()` will display and erase it
WINDOW* renderEarth(int starty, int startx, int view);

#endif /* TERRAVIEW_RENDER_H */
