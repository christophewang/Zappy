/*
** check_directions.c for check_direction in /home/wang_c//Desktop/Zappy_Final
** 
** Made by christophe wang
** Login   <wang_c@epitech.net>
** 
** Started on  Sun Jul 10 18:54:20 2011 christophe wang
** Last update Sun Jul 10 18:57:02 2011 christophe wang
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "serveur.h"

void		check_north(t_serv *serveur, t_client *client, int cs, int i)
{
  int		x;
  int		y;

  x = client[cs].drone->posx;
  y = client[cs].drone->posy;
  if (client[cs].drone->direction == NORTH)
    {
      client[i].drone->posy--;
      if (client[i].drone->posy < 0)
	client[i].drone->posy = serveur->world_y - 1;
      serveur->map_case[client[i].drone->posy][x].players++;
      check_drone_north(client, i, y, x);
    }
}

void		check_east(t_serv *serveur, t_client *client, int cs, int i)
{
  int		x;
  int		y;

  x = client[cs].drone->posx;
  y = client[cs].drone->posy;
  if (client[cs].drone->direction == EAST)
    {
      client[i].drone->posx++;
      if (client[i].drone->posx > serveur->world_x - 1)
	client[i].drone->posx = 0;
      serveur->map_case[y][client[i].drone->posx].players++;
      check_drone_east(client, i, y, x);
    }
}

void		check_south(t_serv *serveur, t_client *client, int cs, int i)
{
  int		x;
  int		y;

  x = client[cs].drone->posx;
  y = client[cs].drone->posy;
  if (client[cs].drone->direction == SOUTH)
    {
      client[i].drone->posy++;
      if (client[i].drone->posy > serveur->world_y - 1)
	client[i].drone->posy = 0;
      serveur->map_case[client[i].drone->posy][x].players++;
      check_drone_south(client, i, y, x);
    }
}

void		check_west(t_serv *serveur, t_client *client, int cs, int i)
{
  int		x;
  int		y;

  x = client[cs].drone->posx;
  y = client[cs].drone->posy;
  if (client[cs].drone->direction == WEST)
    {
      client[i].drone->posx--;
      if (client[i].drone->posx < 0)
	client[i].drone->posx = serveur->world_x - 1;
      serveur->map_case[y][client[i].drone->posx].players++;
      check_drone_west(client, i, y, x);
    }
}
