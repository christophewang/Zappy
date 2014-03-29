/*
** graph_cmd5.c for graph_cmd5 in /home/wang_c//Desktop/Zappy_Final/Serveur
** 
** Made by christophe wang
** Login   <wang_c@epitech.net>
** 
** Started on  Sun Jul 10 20:23:23 2011 christophe wang
** Last update Sun Jul 10 20:24:04 2011 christophe wang
*/

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "serveur.h"

void		send_seg(t_serv *serveur, char *name)
{
  char		tmp[BUFF_SIZE];

  memset(tmp, 0, BUFF_SIZE);
  sprintf(tmp, "seg %s\n", name);
  xsend(serveur->gcs, tmp, strlen(tmp), 0);
}

void		enw(t_serv *serveur, t_client *client, int cs)
{
  int		i;

  i = 0;
  while (i < serveur->nb_eggs)
    {
      if (serveur->egg[i].state == ACTIVE)
	{
	  memset(client[cs].buffer, 0, BUFF_SIZE);
	  sprintf(client[cs].buffer, "enw %d %d %d %d\n", i,
		  serveur->egg[i].father, serveur->egg[i].posx,
		  serveur->egg[i].posy);
	  xsend(cs, client[cs].buffer, strlen(client[cs].buffer), 0);
	}
      i++;
    }
}

void		cmd_bct(t_serv *serveur, t_client *client, int cs, char **tab)
{
  int		x;
  int		y;

  (void)client;
  if (tab[0] && tab[1] && tab[2])
    {
      x = atoi(tab[1]);
      y = atoi(tab[2]);
      if (x >= 0 && x < serveur->world_x && y >= 0 && y < serveur->world_y)
	send_bct(serveur, x, y);
      else
	xsend(cs, "sbp\n", strlen("sbp\n"), 0);
    }
  else
    xsend(cs, "sbp\n", strlen("sbp\n"), 0);
}

void		cmd_ppo(t_serv *serveur, t_client *client, int cs, char **tab)
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
	      send_ppo(serveur, client, i);
	      return ;
	    }
	  i++;
	}
    }
  xsend(cs, "sbp\n", strlen("sbp\n"), 0);
}

void		cmd_plv(t_serv *serveur, t_client *client, int cs, char **tab)
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
	      send_plv(serveur, client, i);
	      return ;
	    }
	  i++;
	}
    }
  xsend(cs, "sbp\n", strlen("sbp\n"), 0);
}
