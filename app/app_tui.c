#include <ncurses.h>

int main(void) {
  initscr(); /* Start curses mode */
  noecho();
  curs_set(0);

  int cached_y_max, cached_x_max, y_max, x_max;
  int win_wave_plot_height, win_wave_plot_width;
  int win_panel_height, win_panel_width;
  int x_padding, y_padding;

  getmaxyx(stdscr, cached_y_max, cached_x_max);
  x_padding = 3;
  y_padding = 1;
  win_wave_plot_height = cached_y_max * 7 / 11;
  win_wave_plot_width = cached_x_max - 2 * x_padding;
  win_panel_height = cached_y_max * 4 / 11 - 1;
  win_panel_width = win_wave_plot_width / 3;

  // Initialise windows
  WINDOW* win_wave_plot =
      newwin(win_wave_plot_height, win_wave_plot_width, y_padding, x_padding);
  box(win_wave_plot, 0, 0);

  WINDOW* win_description =
      newwin(win_panel_height, win_panel_width, y_padding, x_padding);
  box(win_description, 0, 0);
  mvwin(win_description, y_padding + win_wave_plot_height, x_padding);

  WINDOW* win_feedback =
      newwin(win_panel_height, win_panel_width, y_padding, x_padding);
  box(win_feedback, 0, 0);
  mvwin(win_feedback, y_padding + win_wave_plot_height,
        x_padding + win_panel_width);

  WINDOW* win_toggle =
      newwin(win_panel_height, win_panel_width, y_padding, x_padding);
  box(win_toggle, 0, 0);
  mvwin(win_toggle, y_padding + win_wave_plot_height,
        x_padding + 2 * win_panel_width);

  mvwprintw(win_wave_plot, 0, 2, " Wave Plot ");
  mvwprintw(win_description, 0, 2, " Description ");
  mvwprintw(win_feedback, 0, 2, " Statistics ");
  mvwprintw(win_toggle, 0, 2, " Controls ");

  while (true) {
    getmaxyx(stdscr, y_max, x_max);
    
    // Check if window size has change - if yes, recalculate
    if (y_max != cached_y_max || x_max != cached_x_max) {
      cached_x_max = x_max;
      cached_y_max = y_max;
      win_wave_plot_height = cached_y_max * 7 / 11;
      win_wave_plot_width = cached_x_max - 2 * x_padding;
      win_panel_height = cached_y_max * 4 / 11 - 1;
      win_panel_width = win_wave_plot_width / 3;

      wresize(win_wave_plot, win_wave_plot_height, win_wave_plot_width);
      wresize(win_description, win_panel_height, win_panel_width);
      wresize(win_feedback, win_panel_height, win_panel_width);
      wresize(win_toggle, win_panel_height, win_panel_width);

      mvwin(win_wave_plot, y_padding, x_padding);
      mvwin(win_description, y_padding + win_wave_plot_height, x_padding);
      mvwin(win_feedback, y_padding + win_wave_plot_height,
            x_padding + win_panel_width);
      mvwin(win_toggle, y_padding + win_wave_plot_height,
            x_padding + 2 * win_panel_width);

      wclear(stdscr);
      wclear(win_wave_plot);
      wclear(win_description);
      wclear(win_feedback);
      wclear(win_toggle);

      box(win_wave_plot, 0, 0);
      box(win_description, 0, 0);
      box(win_feedback, 0, 0);
      box(win_toggle, 0, 0);

      mvwprintw(win_wave_plot, 0, 2, " Wave Plot ");
      mvwprintw(win_description, 0, 2, " Description ");
      mvwprintw(win_feedback, 0, 2, " Statistics ");
      mvwprintw(win_toggle, 0, 2, " Controls ");
    }

    wrefresh(stdscr);
    wrefresh(win_wave_plot);
    wrefresh(win_description);
    wrefresh(win_feedback);
    wrefresh(win_toggle);
  }

  // Todo - signal to terminate - run endwin() to exit gracefully
  endwin(); /* End curses mode */
  return 0;
}