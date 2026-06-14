#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#include <ncurses.h>

#include "Views.h"

#define KEY_CONTROL_C 3


int main(int argc, char** argv) {
  if (argc > 1) {
    if (strcmp(argv[1], "-v") || strcmp(argv[1], "--version")) {
      printf("The Phi Project - terraview\nVERSION: %s\n", VERSION);
      return EXIT_SUCCESS;
    }
  }

  initscr(); // create `stdscr` object
  raw(); // gather all key presses without allowing C to process signals
  noecho(); // don't automatically display the chars that users type

  int ch;
  while ((ch = getch()) != 'q' && ch != KEY_CONTROL_C) {
    ;
  }

  reset_shell_mode();
  endwin();

  return EXIT_SUCCESS;
}