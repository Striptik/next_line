/*
** get_next_line2.c for get_next_line2 in /home/loisel_k/travail/C-Prog-Elem/get_next_line/src
** 
** Made by kevin loiseleur
** Login   <loisel_k@epitech.net>
** 
** Started on  Sun Nov 24 20:40:14 2013 kevin loiseleur
** Last update Sun Nov 24 21:04:30 2013 kevin loiseleur
*/

#include <stdlib.h>
#include <stdio.h>
#include "../include/get_next_line.h"

void			clearmem1(char *str,  int len)
{
  int			i;
  char			c;

  c = '\0';
  i = 0;
  while (i < len)
    str[i++] = c;
  return ;
}

int			save_position(char *str, int i)
{
  int			copy;
  int			position;

  copy = 0;
  while (str[i])
    str[copy++] = str[i++];
  position = copy;
  clearmem1((str + copy), (SIZE_BUF - copy));
  return (position);
}

char			*get_next_line2(const int fd)
{
  static char		buffer[SIZE_BUF];
  static int		position = 0;
  char			*returned;
  int			i;
  int			ret;

  i = 0;
  if((ret = read(fd, buffer + position, SIZE_READ - position)) <= 0)
    return (NULL);
  buffer[SIZE_BUF] = '\0';
  if ((returned = malloc(sizeof(char) * SIZE_BUF)) == NULL)
    return (NULL);
  returned[i] = '\0';
  while (buffer[i] && buffer[i] != '\n')
    returned[i] = buffer[i++];
  if (buffer[i] == '\n')
    i++;
  position = save_position(buffer, i);
  return (returned);
}

int		main(void)
{
  char		*str;
  int		i;

  i = 0;
  while ((str = get_next_line2(0)))
    {
      i++;
	printf("%s            %d\n", str, i);
      free(str);
    }
  return (0);
}
