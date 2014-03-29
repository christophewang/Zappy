/*
** move.c for move in /home/wang_c//Desktop/Zappy_Final
** 
** Made by christophe wang
** Login   <wang_c@epitech.net>
** 
** Started on  Sun Jul 10 15:16:26 2011 christophe wang
** Last update Sun Jul 10 17:49:06 2011 christophe wang
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "serveur.h"

static void	do_avance(t_serv *serv, t_client *client, int cs)
{
  serv->map_case[client[cs].drone->posy][client[cs].drone->posx].players--;
  if (client[cs].drone->direction == NORTH && --client[cs].drone->posy < 0)
    client[cs].drone->posy = serv->world_y - 1;
  else if (client[cs].drone->direction == EAST &&
	   ++client[cs].drone->posx >= serv->world_x)
    client[cs].drone->posx = 0;
  else if (client[cs].drone->direction == SOUTH &&
	   ++client[cs].drone->posy >= serv->world_y)
    client[cs].drone->posy = 0;
  else if (client[cs].drone->direction == WEST &&
	   --client[cs].drone->posx < 0)
    client[cs].drone->posx = serv->world_x - 1;
  serv->map_case[client[cs].drone->posy][client[cs].drone->posx].players++;
  printf(MOVE, B, serv->team[client[cs].team].name, client[cs].id_drone,
	 client[cs].drone->posy, client[cs].drone->posx, D);
  xsend(cs, OK, strlen(OK), 0);
  delete_command(client, cs);
  parse_command(serv, client, cs);
  if (serv->graphic_flag)
    send_ppo(serv, client, cs);
}

int		avance(t_serv *serveur, t_client *client, int cs, char **tab)
{
  if (tab[1])
    return (-1);
  if (client[cs].flag == 0)
    {
      client[cs].timelaps = 1000000 * 7 / serveur->speed;
      client[cs].flag = 1;
    }
  if (client[cs].flag == 2)
    do_avance(serveur, client, cs);
  return (0);
}

int		droite(t_serv *serv, t_client *client, int cs, char **tab)
{
  if (tab[1])
    return (-1);
  if (client[cs].flag == 0)
    {
      client[cs].timelaps = 1000000 * 7 / serv->speed;
      client[cs].flag = 1;
    }
  if (client[cs].flag == 2)
    {
      printf(RI, B, serv->team[client[cs].team].name, client[cs].id_drone, D);
      if (client[cs].drone->direction == NORTH)
	client[cs].drone->direction = EAST;
      else if (client[cs].drone->direction == EAST)
	client[cs].drone->direction = SOUTH;
      else if (client[cs].drone->direction == SOUTH)
	client[cs].drone->direction = WEST;
      else if (client[cs].drone->direction == WEST)
	client[cs].drone->direction = NORTH;
      xsend(cs, OK, strlen(OK), 0);
      delete_command(client, cs);
      parse_command(serv, client, cs);
      if (serv->graphic_flag)
	send_ppo(serv, client, cs);
    }
  return (0);
}

int		gauche(t_serv *serv, t_client *client, int cs, char **tab)
{
  if (tab[1])
    return (-1);
  if (client[cs].flag == 0)
    {
      client[cs].timelaps = 1000000 * 7 / serv->speed;
      client[cs].flag = 1;
    }
  if (client[cs].flag == 2)
    {
      printf(LE, B, serv->team[client[cs].team].name, client[cs].id_drone, D);
      if (client[cs].drone->direction == NORTH)
	client[cs].drone->direction = WEST;
      else if (client[cs].drone->direction == WEST)
	client[cs].drone->direction = SOUTH;
      else if (client[cs].drone->direction == SOUTH)
	client[cs].drone->direction = EAST;
      else if (client[cs].drone->direction == EAST)
	client[cs].drone->direction = NORTH;
      xsend(cs, OK, strlen(OK), 0);
      delete_command(client, cs);
      parse_command(serv, client, cs);
      if (serv->graphic_flag)
	send_ppo(serv, client, cs);
    }
  return (0);
}
