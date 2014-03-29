/*
** graph_cmd.c for graph_cmd in /home/wang_c//Desktop/Zappy_Final/Serveur
** 
** Made by christophe wang
** Login   <wang_c@epitech.net>
** 
** Started on  Sun Jul 10 20:19:56 2011 christophe wang
** Last update Sun Jul 10 20:26:23 2011 christophe wang
*/

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "serveur.h"

void		msz(t_serv *serveur, t_client *client, int cs)
{
  memset(client[cs].buffer, 0, BUFF_SIZE);
  sprintf(client[cs].buffer, "msz %d %d\n", serveur->world_x,
	  serveur->world_y);
  xsend(cs, client[cs].buffer, strlen(client[cs].buffer), 0);
}

void		sgt(t_serv *serveur, t_client *client, int cs)
{
  memset(client[cs].buffer, 0, BUFF_SIZE);
  sprintf(client[cs].buffer, "sgt %d\n", serveur->speed);
  xsend(cs, client[cs].buffer, strlen(client[cs].buffer), 0);
}

void		bct(t_serv *serveur, t_client *client, int cs)
{
  int		x;
  int		y;

  y = 0;
  while (y < serveur->world_y)
    {
      x = 0;
      while (x < serveur->world_x)
	{
	  memset(client[cs].buffer, 0, BUFF_SIZE);
	  sprintf(client[cs].buffer, "bct %d %d %d %d %d %d %d %d %d\n",
		  x, y, serveur->map_case[y][x].nourriture,
		  serveur->map_case[y][x].linemate,
		  serveur->map_case[y][x].deraumere,
		  serveur->map_case[y][x].sibur,
		  serveur->map_case[y][x].mendiane,
		  serveur->map_case[y][x].phiras,
		  serveur->map_case[y][x].thystame);
	  xsend(cs, client[cs].buffer, strlen(client[cs].buffer), 0);
	  x++;
	}
      y++;
    }
}

void		tna(t_serv *serveur, t_client *client, int cs)
{
  int		i;

  i = 0;
  while (i < serveur->nb_team)
    {
      memset(client[cs].buffer, 0, BUFF_SIZE);
      sprintf(client[cs].buffer, "tna %s\n", serveur->team[i].name);
      xsend(cs, client[cs].buffer, strlen(client[cs].buffer), 0);
      i++;
    }
}

void		pnw(t_serv *serveur, t_client *client, int cs)
{
  int		i;

  i = 0;
  while (i < serveur->limit)
    {
      if (serveur->fd_type[i] == FD_CLIENT && client[i].teamflag == 1)
	{
	  memset(client[cs].buffer, 0, BUFF_SIZE);
	  sprintf(client[cs].buffer, "pnw %d %d %d %d %d %s\n", client[i].id,
		  client[i].drone->posx, client[i].drone->posy,
		  client[i].drone->direction + 1, client[i].drone->level,
		  serveur->team[client[i].team].name);
	  xsend(cs, client[cs].buffer, strlen(client[cs].buffer), 0);
	}
      i++;
    }
}
