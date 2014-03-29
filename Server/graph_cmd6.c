/*
** graph_cmd6.c for graph_cmd6 in /home/wang_c//Desktop/Zappy_Final/Serveur
** 
** Made by christophe wang
** Login   <wang_c@epitech.net>
** 
** Started on  Sun Jul 10 20:24:15 2011 christophe wang
** Last update Sun Jul 10 20:24:45 2011 christophe wang
*/

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "serveur.h"

void		cmd_pin(t_serv *serveur, t_client *client, int cs, char **tab)
{
  int		i;
  int		id;

  if (tab[0] && tab[1] && !tab[2])
    {
      i = 0;
      id = atoi(tab[1]);
      while (i < serveur->limit)
	{
	  if (serveur->fd_type[i] == FD_CLIENT &&
	      client[i].teamflag == 1 && client[i].id == id)
	    {
	      send_pin(serveur, client, i);
	      return ;
	    }
	  i++;
	}
    }
  xsend(cs, "sbp\n", strlen("sbp\n"), 0);
}

void		cmd_sst(t_serv *serveur, t_client *client, int cs, char **tab)
{
  int		speed;

  if (tab[0] && tab[1] && !tab[2])
    {
      speed = atoi(tab[1]);
      if (speed >= 1 && speed <= 1000000)
	{
	  serveur->speed = speed;
	  memset(client[cs].buffer, 0, BUFF_SIZE);
	  sprintf(client[cs].buffer, "sgt %d\n", serveur->speed);
	  xsend(cs, client[cs].buffer, strlen(client[cs].buffer), 0);
	  return ;
	}
    }
  xsend(cs, "sbp\n", strlen("sbp\n"), 0);
}
