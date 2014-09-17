/*
** maintest.c for maintest in /home/loisel_k/travail/C-Prog-Elem/get_next_line/src
** 
** Made by kevin loiseleur
** Login   <loisel_k@epitech.net>
** 
** Started on  Sat Nov 23 16:46:52 2013 kevin loiseleur
** Last update Tue Nov 26 16:47:20 2013 kevin loiseleur
*/

#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include "../include/get_next_line.h"

int		main(int ac, char **av)
{
  int		fd;
  char		*s;

  fd = open(av[1], O_RDONLY);
  while ((s = get_next_line2(fd)) != 0)
    {
      printf("%s", s);
      free(s);
    }
  return (0);
}
