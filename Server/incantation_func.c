/*
** incatation_func.c for incantation_func in /home/wang_c//Desktop/Zappy_Final
** 
** Made by christophe wang
** Login   <wang_c@epitech.net>
** 
** Started on  Sun Jul 10 19:03:42 2011 christophe wang
** Last update Sun Jul 10 22:42:09 2011 christophe wang
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "serveur.h"

int		check_level(t_serv *serveur, int y, int x, int level)
{
  int		i;
  int		j;
  t_drone	*tmp;

  i = 0;
  while (i < serveur->nb_team)
    {
      j = 0;
      while (j < serveur->team[i].max_clients)
	{
	  tmp = &serveur->team[i].drone[j];
	  if (tmp->status == ACTIVE && tmp->posy == y && tmp->posx == x &&
	      tmp->level != level)
	    return (0);
	  j++;
	}
      i++;
    }
  return (1);
}

void		fail_elevation(t_serv *serveur, t_client *client, int cs)
{
  int		i;
  int		j;
  t_drone	*tmp;

  i = 0;
  while (i < serveur->nb_team)
    {
      j = 0;
      while (j < serveur->team[i].max_clients)
	{
	  tmp = &serveur->team[i].drone[j];
	  if (tmp->status == ACTIVE && tmp->posy == client[cs].drone->posy &&
	      tmp->posx == client[cs].drone->posx)
	    xsend(tmp->cs, KO, strlen(KO), 0);
	  j++;
	}
      i++;
    }
  delete_command(client, cs);
  parse_command(serveur, client, cs);
}

void		lvl_up(t_serv *serveur, t_client *client, int cs, t_drone *tmp)
{
  printf(UP, B, serveur->team[client[tmp->cs].team].name,
	 client[tmp->cs].id_drone, ++tmp->level, D);
  memset(client[cs].buffer, 0, BUFF_SIZE);
  sprintf(client[cs].buffer, LVLUP, tmp->level);
  xsend(tmp->cs, client[cs].buffer, strlen(client[cs].buffer), 0);
  regen_ressources(serveur);
  if (serveur->graphic_flag)
    {
      send_plv(serveur, client, cs);
      send_bct(serveur, tmp->posx, tmp->posy);
    }
}

void		send_incantation_msg(t_serv *serveur, t_client *client, int cs)
{
  int		i;
  int		j;
  t_drone	*tmp;

  i = 0;
  while (i < serveur->nb_team)
    {
      j = 0;
      while (j < serveur->team[i].max_clients)
	{
	  tmp = &serveur->team[i].drone[j];
	  if (tmp->status == ACTIVE && tmp->posy == client[cs].drone->posy &&
	      tmp->posx == client[cs].drone->posx)
	    lvl_up(serveur, client, cs, tmp);
	  j++;
	}
      i++;
    }
}

void		start_inc(t_serv *serveur, t_client *client, int cs, int lvl)
{
  client[cs].timelaps = 1000000 * 300 / serveur->speed;
  client[cs].flag = 1;
  xsend(cs, INCANTATION, strlen(INCANTATION), 0);
  if (serveur->graphic_flag)
      send_pic(serveur, client, cs, lvl);
}
