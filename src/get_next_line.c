/*
** get_next_line.c for get_next_line.c in /home/loisel_k/travail/C-Prog-Elem/get_next_line/src
** 
** Made by kevin loiseleur
** Login   <loisel_k@epitech.net>
** 
** Started on  Tue Nov 19 19:10:19 2013 kevin loiseleur
** Last update Tue Nov 26 17:08:44 2013 kevin loiseleur
*/

#include <stdlib.h>
#include "../include/get_next_line.h"

char		*my_strncpy(char *src, char *dest, int len)
{
  int		i;

  i = 0;
  while (i < len)
    dest[i] = src[i++];
  dest[++len] = '\0';
  return (dest);
}

int		my_read(int fd , void *buf, size_t i)
{
  int		res;
  char		*tmp;

  res = read(fd, buf, i);
  if (buf == NULL || res <= 0)
    return (-1);
  return(res);
}

char		*my_malloc(size_t len)
{
  char		*str;

  str = malloc(sizeof(char) * len);
  if (str == NULL)
    return (NULL);
  return (str);
}

void		clearmem(char *str, char c, int len)
{
  int		i;

  i = 0;
  while (i < len)
    {
      str[i] = c;
      ++i;
    }
  return ;
}

int		buf_after_line(char *buf, int current)
{
  int		set;

  set = 0;
  while (buf[current])
    buf[set++] = buf[current++];
  buf[set] = '\0';
  clearmem((buf + set), '\0', (SIZE_BUF - set));
  return (set);
}

char		*get_next_line(const int fd)
{
  static int	save = 0;
  static char	buf[SIZE_BUF];
  char		*line;
  int		current;
  int		ret;

  current = 0;
  ret = my_read(fd, (buf + save), SIZE_READ - save);
  buf[SIZE_BUF] = '\0';
  line = my_malloc(SIZE_BUF);
  if (line <= 0 || ret <= 0)
    return (NULL);
  line[SIZE_BUF] = '\0';
  while (buf[current] && buf[current] != '\n')
    line[current] =  buf[current++];
  if (buf[current] == '\n')
      current++;
  save = buf_after_line(buf, current);
  return (line);
}

char		*get_next_line2(const int fd)
{
  static int	save = 0;
  static char	buf[SIZE_BUF];
  char		*line;
  int		current;
  int		ret;

  current = 0;
  if ((ret = read(fd, (buf + save), SIZE_READ - save)) <= 0)
    return (NULL);
  buf[SIZE_BUF] = '\0';
  while (buf[current] && buf[current] != '\n')
    buf[current++];
  if ((line = malloc(sizeof(char) * (current + 1))) == NULL)
      return (NULL);
  line[current] = '\0';
  my_strncpy(buf, line, (current - 1));
  if (buf[current] == '\n')
    save = buf_after_line(buf, current++);
  else
    save = 0;
  return (line);
}
