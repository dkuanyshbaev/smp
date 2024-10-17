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
bool is_file(const char *path)
{
    struct stat path_stat;
    stat(path, &path_stat);
    return S_ISREG(path_stat.st_mode);
}

int main(int argc, char *argv[]) {
    if (argc < 2) {
        puts("no files");
        return EXIT_SUCCESS;
    }

    initscr();
    noecho();

    char * path = argv[1];
    if (is_file(path)) {
        printw("it's file!\n\n");
        printw("%s", path);

        // TODO: add file to empty play list
    } else {
        printw("it's dir!\n\n");

        // TODO: errors check!
        DIR *d = opendir(path);
        struct dirent *dir;
        if (d) {
            while ((dir = readdir(d)) != NULL) {
                if (dir->d_type == DT_REG)
                {
                    // TODO: add files to empty play list
                    printw("%s\n", dir->d_name);
                }
            }
            closedir(d);
        }
    }

    getch();

    endwin();
    return EXIT_SUCCESS;
}
