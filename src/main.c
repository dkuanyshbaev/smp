/* #define MINIAUDIO_IMPLEMENTATION */
/* #include <miniaudio.h> */
#include <ncurses.h>
#include <stdlib.h>
#include <stdio.h>

#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>

#include <dirent.h>

// is it file or directory
bool is_file(const char *path) {
    struct stat path_stat;
    stat(path, &path_stat);
    return S_ISREG(path_stat.st_mode);
}

bool make_play_list(char *path, char *play_list[]) {
    if (is_file(path)) {
        // it's file

        printw("%s", path);
        // TODO: add file to play list
    } else {
        // it's directory

        // TODO: errors check!
        DIR *d = opendir(path);
        struct dirent *dir;
        if (d) {
            while ((dir = readdir(d)) != NULL) {
                if (dir->d_type == DT_REG)
                {
                    printw("%s\n", dir->d_name);
                    // TODO: add files to play list
                }
            }
            closedir(d);
        }
    }
    return true;
}

void destroy_play_list(char **play_list) {
    // loop?
    /* free(play_list); */
}

int main(int argc, char *argv[]) {
    if (argc < 2) {
        puts("no files");
        return EXIT_FAILURE;
    }
    initscr();
    noecho();

    char **play_list = {0};
    int number_of_tracks = make_play_list(argv[1], play_list);
    if (number_of_tracks == 0) {
        puts("can't play");
        return EXIT_FAILURE;
    }

    getch();

    destroy_play_list(play_list);
    endwin();
    return EXIT_SUCCESS;
}
