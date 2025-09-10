#include "fractol.h"

int ft_strncmp(char *s1, char *s2, int n)
{
    if (s1 == NULL || s2 == NULL || n <= 0)
        return (0);
    while (*s1 && *s1 == *s2 && n --)
    {
        s1 ++;
        s2 ++;
    }
    return (*s1 - *s2);
}

void putstr_fd(char *s, int fd)
{
    if (s == NULL || fd < 0)
        return ;
    while (*s)
        write(fd, s ++, 1);
}