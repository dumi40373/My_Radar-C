/*
** EPITECH PROJECT, 2025
** lib
** File description:
** my str alpha cmp
*/

int my_str_alphacmp(const char *s1, const char *s2)
{
    for (int i = 0; s1[i] != '\0'; i++) {
        if (s1[i] != s2[i])
            return s1[i] - s2[i];
    }
    for (int i = 0; s2[i] != '\0'; i++) {
        if (s2[i] != s1[i])
            return s1[i] - s2[i];
    }
    return 0;
}
