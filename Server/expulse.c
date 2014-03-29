/*
** expulse.c for expulse in /home/wang_c//Desktop/Zappy_Final
** 
** Made by christophe wang
** Login   <wang_c@epitech.net>
** 
** Started on  Sun Jul 10 15:13:32 2011 christophe wang
** Last update Sun Jul 10 18:54:40 2011 christophe wang
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "serveur.h"

static void	do_expulse(t_serv *serveur, t_client *client, int cs)
{
  int		x;
  int		y;
  int		i;

  i = 0;
  x = client[cs].drone->posx;
  y = client[cs].drone->posy;
  printf(EXPULSE, B, serveur->team[client[cs].team].name,
	 client[cs].id_drone, y, x, D);
  xsend(cs, OK, strlen(OK), 0);
  if (serveur->graphic_flag)
    send_pex(serveur, client, cs);
  while (i < serveur->limit)
    {
      if (serveur->fd_type[i] == FD_CLIENT)
	check_drones(serveur, client, cs, i);
      i++;
    }
}

int		expulse(t_serv *serveur, t_client *client, int cs, char **tab)
{
  int		x;
  int		y;

  x = client[cs].drone->posx;
  y = client[cs].drone->posy;
  if (tab[1])
    return (-1);
  if (client[cs].flag == 0)
    {
      client[cs].timelaps = 1000000 * 7 / serveur->speed;
      client[cs].flag = 1;
    }
  if (client[cs].flag == 2)
    {
      if (serveur->map_case[y][x].players < 2)
	xsend(cs, KO, strlen(KO), 0);
      else
	do_expulse(serveur, client, cs);
      delete_command(client, cs);
      parse_command(serveur, client, cs);
    }
  return (0);
}
