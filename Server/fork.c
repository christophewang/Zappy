/*
** fork.c for fork in /home/wang_c//Desktop/Zappy_Final
** 
** Made by christophe wang
** Login   <wang_c@epitech.net>
** 
** Started on  Sun Jul 10 15:13:41 2011 christophe wang
** Last update Sun Jul 10 15:13:43 2011 christophe wang
*/

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "serveur.h"

static void	active_egg(t_serv *serveur, t_client *client, int cs, int i)
{
  serveur->egg[i].state = ACTIVE;
  serveur->egg[i].team = client[cs].team;
  serveur->egg[i].posx = client[cs].drone->posx;
  serveur->egg[i].posy = client[cs].drone->posy;
  serveur->egg[i].father = client[cs].id;
  serveur->egg[i].hatch = 1000000 * 600 / serveur->speed;
  xgettimeofday(&serveur->egg[i].hatchtime);
}

static void	hatching(t_serv *serveur, t_client *client, int cs)
{
  int		i;

  i = 0;
  serveur->nb_eggs++;
  if (serveur->nb_eggs > serveur->max_eggs)
    {
      serveur->max_eggs = serveur->nb_eggs;
      serveur->egg = xrealloc(serveur->egg, sizeof(*serveur->egg) *
			      serveur->nb_eggs);
      serveur->egg[serveur->nb_eggs - 1].state = INACTIVE;
    }
  while (i < serveur->nb_eggs)
    {
      if (serveur->egg[i].state == INACTIVE)
	{
	  active_egg(serveur, client, cs, i);
	  if (serveur->graphic_flag)
	    send_enw(serveur, client, cs, i);
	  return ;
	}
      i++;
    }
}

int		fork_cmd(t_serv *serveur, t_client *client, int cs, char **tab)
{
  if (tab[1])
    return (-1);
  if (client[cs].flag == 0)
    {
      client[cs].timelaps = 1000000 * 42 / serveur->speed;
      client[cs].flag = 1;
      if (serveur->graphic_flag)
	send_pfk(serveur, client, cs);
    }
  if (client[cs].flag == 2)
    {
      printf(EGG, B, client[cs].drone->posy, client[cs].drone->posx, D);
      serveur->map_case[client[cs].drone->posy][client[cs].drone->posx].eggs++;
      xsend(cs, OK, strlen(OK), 0);
      hatching(serveur, client, cs);
      delete_command(client, cs);
      parse_command(serveur, client, cs);
    }
  return (0);
}
