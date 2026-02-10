/*
** EPITECH PROJECT, 2025
** my_radar
** File description:
** read file
*/

#include <unistd.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <stdlib.h>

static char *close_null(int fd)
{
    close(fd);
    return NULL;
}

static char *free_close_null(char *buf, int fd)
{
    free(buf);
    close(fd);
    return NULL;
}

char *read_file(const char *filename)
{
    struct stat st;
    char *buffer;
    int fd = open(filename, O_RDONLY);
    int size;

    if (fd == -1)
        return NULL;
    if (stat(filename, &st) == -1)
        return close_null(fd);
    buffer = malloc(st.st_size + 1);
    if (!buffer)
        return close_null(fd);
    size = read(fd, buffer, st.st_size);
    if (size == -1)
        return free_close_null(buffer, fd);
    buffer[size] = '\0';
    close(fd);
    return buffer;
}
