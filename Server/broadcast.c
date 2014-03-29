/*
** broadcast.c for broadcast in /home/wang_c//Desktop/Zappy_Final
** 
** Made by christophe wang
** Login   <wang_c@epitech.net>
** 
** Started on  Sun Jul 10 15:12:18 2011 christophe wang
** Last update Sun Jul 10 21:26:55 2011 christophe wang
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "serveur.h"

int		check_pos(t_drone *tmp, t_client *client, int cs)
{
  int		x;
  int		y;

  x = client[cs].drone->posx;
  y = client[cs].drone->posy;
  if (tmp->posx == x && tmp->posy == y)
    return (0);
  else if (y < tmp->posy && x < tmp->posx)
    return (check_drone_dir1(tmp));
  else if (y > tmp->posy && x < tmp->posx)
    return (check_drone_dir2(tmp));
  else if (y < tmp->posy && x > tmp->posx)
    return (check_drone_dir3(tmp));
  else if (y > tmp->posy && x > tmp->posx)
    return (check_drone_dir4(tmp));
  else if (y == tmp->posy && x < tmp->posx)
    return (check_drone_dir5(tmp));
  else if (y == tmp->posy && x > tmp->posx)
    return (check_drone_dir6(tmp));
  else if (y < tmp->posy && x == tmp->posx)
    return (check_drone_dir7(tmp));
  else if (y > tmp->posy && x == tmp->posx)
    return (check_drone_dir8(tmp));
  return (0);
}

void		send_bcast(t_serv *serveur, t_client *client, int cs, char *msg)
{
  int		i;
  int		j;
  int		pos;
  t_drone	*tmp;

  i = 0;
  while (i < serveur->nb_team)
    {
      j = 0;
      while (j < serveur->team[i].max_clients)
	{
	  tmp = &serveur->team[i].drone[j];
	  if (tmp->status == ACTIVE && tmp->cs != cs)
	    {
	      pos = check_pos(tmp, client, cs);
	      memset(client[cs].buffer, 0, BUFF_SIZE);
	      sprintf(client[cs].buffer, BROADCAST, pos, msg);
	      xsend(tmp->cs, client[cs].buffer, strlen(client[cs].buffer), 0);
	    }
	  j++;
	}
      i++;
    }
}

int		broadcast(t_serv *serveur, t_client *client, int cs, char **tab)
{
  if (!tab[1] || (tab[1] && tab[2]))
    return (-1);
  if (client[cs].flag == 0)
    {
      client[cs].timelaps = 1000000 * 7 / serveur->speed;
      client[cs].flag = 1;
    }
  if (client[cs].flag == 2)
    {
      send_bcast(serveur, client, cs, tab[1]);
      xsend(cs, OK, strlen(OK), 0);
      delete_command(client, cs);
      parse_command(serveur, client, cs);
      if (serveur->graphic_flag)
	send_pbc(serveur, client, cs, tab[1]);
    }
  return (0);
}
