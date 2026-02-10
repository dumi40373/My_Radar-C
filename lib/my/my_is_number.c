/*
** EPITECH PROJECT, 2025
** organized
** File description:
** is_number
*/

int my_is_number(char *str)
{
    for (int i = 0; str[i]; i++) {
        if (str[i] < 48 || str[i] > 57)
            return 0;
    }
    return 1;
}
