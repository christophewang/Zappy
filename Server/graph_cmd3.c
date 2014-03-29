/*
** graph_cmd3.c for graph_cmd in /home/wang_c//Desktop/Zappy_Final/Serveur
** 
** Made by christophe wang
** Login   <wang_c@epitech.net>
** 
** Started on  Sun Jul 10 20:21:32 2011 christophe wang
** Last update Sun Jul 10 20:22:27 2011 christophe wang
*/

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "serveur.h"

void		send_bct(t_serv *serveur, int x, int y)
{
  char		tmp[BUFF_SIZE];

  memset(tmp, 0, BUFF_SIZE);
  sprintf(tmp, "bct %d %d %d %d %d %d %d %d %d\n", x, y,
	  serveur->map_case[y][x].nourriture,
	  serveur->map_case[y][x].linemate,
	  serveur->map_case[y][x].deraumere,
	  serveur->map_case[y][x].sibur,
	  serveur->map_case[y][x].mendiane,
	  serveur->map_case[y][x].phiras,
	  serveur->map_case[y][x].thystame);
  xsend(serveur->gcs, tmp, strlen(tmp), 0);
}

void		send_pex(t_serv *serveur, t_client *client, int cs)
{
  memset(client[cs].buffer, 0, BUFF_SIZE);
  sprintf(client[cs].buffer, "pex %d\n", client[cs].id);
  xsend(serveur->gcs, client[cs].buffer, strlen(client[cs].buffer), 0);
}

void		send_pbc(t_serv *serveur, t_client *client, int cs, char *msg)
{
  memset(client[cs].buffer, 0, BUFF_SIZE);
  sprintf(client[cs].buffer, "pbc %d %s\n", client[cs].id, msg);
  xsend(serveur->gcs, client[cs].buffer, strlen(client[cs].buffer), 0);
}

void		send_pic(t_serv *serveur, t_client *client, int cs, int lvl)
{
  char		id[BUFF_SIZE];
  char		tmp[BUFF_SIZE];
  int		i;

  i = 0;
  memset(id, 0, BUFF_SIZE);
  while (i < serveur->limit)
    {
      if (serveur->fd_type[i] == FD_CLIENT && client[i].teamflag == 1)
	{
	  if (client[i].drone->posx == client[cs].drone->posx &&
	      client[i].drone->posy == client[i].drone->posy)
	    {
	      memset(tmp, 0, BUFF_SIZE);
	      sprintf(tmp, " %d", client[i].id);
	      strcat(id, tmp);
	    }
	}
      i++;
    }
  memset(client[cs].buffer, 0, BUFF_SIZE);
  sprintf(client[cs].buffer, "pic %d %d %d%s\n", client[cs].drone->posx,
	  client[cs].drone->posy, lvl, id);
  xsend(serveur->gcs, client[cs].buffer, strlen(client[cs].buffer), 0);
}

void		send_pie(t_serv *serveur, t_client *client, int cs, int i)
{
  memset(client[cs].buffer, 0, BUFF_SIZE);
  sprintf(client[cs].buffer, "pie %d %d %d\n",
	  client[cs].drone->posx, client[cs].drone->posy, i);
  xsend(serveur->gcs, client[cs].buffer, strlen(client[cs].buffer), 0);
}
