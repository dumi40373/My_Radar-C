/*
** EPITECH PROJECT, 2025
** my str to word array
** File description:
** my str to word array
*/

#include "my2.h"
#include <stdlib.h>

int is_delim(char value, char *delim)
{
    for (int i = 0; delim[i] != '\0'; i++) {
        if (value == delim[i])
            return 1;
    }
    return 0;
}

int number_of_words(char *str, char *delim)
{
    int count = 0;

    if (!str)
        return 84;
    for (int i = 0; str[i] != '\0'; i++) {
        if (is_delim(str[i], delim))
            count++;
        if (!is_delim(str[i], delim) && str[i + 1] == '\0')
            count++;
    }
    return count;
}

int words_size(char *str, char *delim, int i)
{
    int a = 0;

    if (!str)
        return 84;
    while (str[i] != '\0' && is_delim(str[i], delim) == 0) {
        a++;
        i++;
    }
    return a;
}

char **my_str_to_word_array(char *str, char *delim)
{
    int nb_words = number_of_words(str, delim);
    char **res = malloc(sizeof(char *) * (nb_words + 1));
    int i = 0;
    int a = 0;

    if (!str)
        return NULL;
    for (int j = 0; j < nb_words; j++) {
        res[j] = malloc(sizeof(char) * (words_size(str, delim, i) + 1));
        a = 0;
        while (str[i] != '\0' && is_delim(str[i], delim) == 0) {
            res[j][a] = str[i];
            i++;
            a++;
        }
        res[j][a] = '\0';
        i++;
    }
    res[nb_words] = NULL;
    return res;
}
