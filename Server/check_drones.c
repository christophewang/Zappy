/*
** check_drones.c for check_drones in /home/wang_c//Desktop/Zappy_Final
** 
** Made by christophe wang
** Login   <wang_c@epitech.net>
** 
** Started on  Sun Jul 10 18:49:50 2011 christophe wang
** Last update Sun Jul 10 18:52:48 2011 christophe wang
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "serveur.h"

void		check_drone_north(t_client *client, int i, int y, int x)
{
  if (client[i].drone->posy == y && client[i].drone->posx == x)
    sprintf(client[i].buffer, "deplacement: %d\n", 0);
  else if (client[i].drone->direction == NORTH)
    sprintf(client[i].buffer, "deplacement: %d\n", 5);
  else if (client[i].drone->direction == EAST)
    sprintf(client[i].buffer, "deplacement: %d\n", 7);
  else if (client[i].drone->direction == SOUTH)
    sprintf(client[i].buffer, "deplacement: %d\n", 1);
  else if (client[i].drone->direction == WEST)
    sprintf(client[i].buffer, "deplacement: %d\n", 3);
  xsend(i, client[i].buffer, strlen(client[i].buffer), 0);
}

void		check_drone_east(t_client *client, int i, int y, int x)
{
  if (client[i].drone->posy == y && client[i].drone->posx == x)
  sprintf(client[i].buffer, "deplacement: %d\n", 0);
  else if (client[i].drone->direction == NORTH)
    sprintf(client[i].buffer, "deplacement: %d\n", 3);
  else if (client[i].drone->direction == EAST)
    sprintf(client[i].buffer, "deplacement: %d\n", 5);
  else if (client[i].drone->direction == SOUTH)
    sprintf(client[i].buffer, "deplacement: %d\n", 7);
  else if (client[i].drone->direction == WEST)
    sprintf(client[i].buffer, "deplacement: %d\n", 1);
  xsend(i, client[i].buffer, strlen(client[i].buffer), 0);
}

void		check_drone_south(t_client *client, int i, int y, int x)
{
  if (client[i].drone->posy == y && client[i].drone->posx == x)
    sprintf(client[i].buffer, "deplacement: %d\n", 0);
 else if (client[i].drone->direction == NORTH)
    sprintf(client[i].buffer, "deplacement: %d\n", 1);
  else if (client[i].drone->direction == EAST)
    sprintf(client[i].buffer, "deplacement: %d\n", 3);
  else if (client[i].drone->direction == SOUTH)
    sprintf(client[i].buffer, "deplacement: %d\n", 5);
  else if (client[i].drone->direction == WEST)
    sprintf(client[i].buffer, "deplacement: %d\n", 7);
  xsend(i, client[i].buffer, strlen(client[i].buffer), 0);
}

void		check_drone_west(t_client *client, int i, int y, int x)
{
  if (client[i].drone->posy == y && client[i].drone->posx == x)
    sprintf(client[i].buffer, "deplacement: %d\n", 0);
  else if (client[i].drone->direction == NORTH)
    sprintf(client[i].buffer, "deplacement: %d\n", 7);
  else if (client[i].drone->direction == EAST)
    sprintf(client[i].buffer, "deplacement: %d\n", 1);
  else if (client[i].drone->direction == SOUTH)
    sprintf(client[i].buffer, "deplacement: %d\n", 3);
  else if (client[i].drone->direction == WEST)
    sprintf(client[i].buffer, "deplacement: %d\n", 5);
  xsend(i, client[i].buffer, strlen(client[i].buffer), 0);
}

void		check_drones(t_serv *serveur, t_client *client, int cs, int i)
{
  int		x;
  int		y;

  x = client[cs].drone->posx;
  y = client[cs].drone->posy;
  memset(client[i].buffer, 0, BUFF_SIZE);
  if (client[i].teamflag == 1 && i != cs && client[i].drone->posx == x
      && client[i].drone->posy == y)
    {
      serveur->map_case[y][x].players--;
      check_north(serveur, client, cs, i);
      check_east(serveur, client, cs, i);
      check_south(serveur, client, cs, i);
      check_west(serveur, client, cs, i);
      if (serveur->graphic_flag)
	send_ppo(serveur, client, i);
    }
}

