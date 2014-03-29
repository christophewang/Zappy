/*
** quit_serveur.c for quit_serveur in /home/wang_c//Desktop/Zappy_Final
** 
** Made by christophe wang
** Login   <wang_c@epitech.net>
** 
** Started on  Sun Jul 10 15:16:40 2011 christophe wang
** Last update Sun Jul 10 15:16:42 2011 christophe wang
*/

#include <stdio.h>
#include <string.h>
#include "serveur.h"

void		quit_serveur(t_serv *serveur, t_client *client)
{
  int		i;

  i = 0;
  while (i < serveur->limit)
    {
      if (serveur->fd_type[i] == FD_CLIENT)
	{
	  xsend(i, "mort\n", strlen("mort\n"), 0);
	  xclose(i);
	}
      i++;
    }
  printf("%s%s%s%s%s", G, QUIT, R, ZAPPY, D);
  free_map(serveur);
  free_serveur(serveur, client);
  xclose(serveur->sock);
}
