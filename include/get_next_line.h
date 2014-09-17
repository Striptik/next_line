/*
** get_next_line.h for Get next line header in /home/loisel_k/travail/C-Prog-Elem/get_next_line/include
** 
** Made by kevin loiseleur
** Login   <loisel_k@epitech.net>
** 
** Started on  Tue Nov 19 16:07:10 2013 kevin loiseleur
** Last update Tue Nov 26 12:44:55 2013 kevin loiseleur
*/

#ifndef GET_NEXT_LINE_H_
# define GET_NEXT_LINE_H_

#define SIZE_READ		10
#define SIZE_BUF		SIZE_READ + 1

char				*get_next_line(const int fd);
void				clearmem(char *, char, int);
int				my_read(int fd, void *buf, size_t i);
char				*my_strdup(char *);
int				my_strlen(char *);

#endif /* GET_NEXT_LINE_H_ */
