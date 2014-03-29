/*
** get_fdmax.c for get_fdmax in /home/wang_c//Desktop/Zappy_Final/Serveur
** 
** Made by christophe wang
** Login   <wang_c@epitech.net>
** 
** Started on  Sun Jul 10 19:46:02 2011 christophe wang
** Last update Sun Jul 10 19:46:57 2011 christophe wang
*/

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "serveur.h"

int		get_fdmax(t_serv *serveur, fd_set *fd_read)
{
  int			i;
  int			fd_max;

  i = 0;
  fd_max = 0;
  while (i < serveur->limit)
    {
      if (serveur->fd_type[i] != FD_FREE)
	{
	  FD_SET(i, fd_read);
	  fd_max = i;
	}
      i++;
    }
  return (fd_max);
}
