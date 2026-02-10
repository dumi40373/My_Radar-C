/*
** EPITECH PROJECT, 2025
** my_radar
** File description:
** main
*/

#include "include/my.h"

int main(int argc, char **argv)
{
    if (argc != 2) {
        my_printf("./my_radar: bad arguments: 0 given"
            "but 84 is required\nretry with -h\n");
        return 84;
    }
    if (my_strcmp(argv[1], "-h")) {
        my_printf("Air traffic simulation panel\n"
            "USAGE\n"
            "   ./my_radar [OPTIONS] path_to_script\n"
            "   path_to_script The path to the script file.\n"
            "OPTIONS\n"
            "   -h          print the usage and quit.\n"
            "USER INTERACTIONS\n"
            "   None.\n");
        return 0;
    }
    if (execute_window(argv[1]) == 84)
        return 84;
    return 0;
}
