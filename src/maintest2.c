/*
** maintest2.c for maintest 2 in /home/loisel_k/travail/C-Prog-Elem/get_next_line/src
** 
** Made by kevin loiseleur
** Login   <loisel_k@epitech.net>
** 
** Started on  Sun Nov 24 17:53:27 2013 kevin loiseleur
** Last update Sun Nov 24 18:12:31 2013 kevin loiseleur
*/

#include <stdlib.h>
#include <stdio.h>

int		main(void)
{
  char		*s;

  while (s = get_next_line(0))
    {
      printf("%s\n", s);
      free(s);
    }
  return (0);
}
