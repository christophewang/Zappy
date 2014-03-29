/*
** incantation_high.c for incantation in /home/wang_c//Desktop/Zappy_Final
** 
** Made by christophe wang
** Login   <wang_c@epitech.net>
** 
** Started on  Sun Jul 10 19:01:59 2011 christophe wang
** Last update Sun Jul 10 19:02:47 2011 christophe wang
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "serveur.h"

int		elevation6(t_serv *serveur, t_client *client, int cs)
{
  int		i;
  t_case	*c;

  c = &serveur->map_case[client[cs].drone->posy][client[cs].drone->posx];
  i = check_level(serveur, client[cs].drone->posy, client[cs].drone->posx, 6);
  if (c->players == 6 && c->linemate == 1 && c->deraumere == 2 &&
      c->sibur == 3 && !c->mendiane && c->phiras == 1 && !c->thystame && i)
    {
      if (client[cs].flag == 0)
	start_inc(serveur, client, cs, 7);
      if (client[cs].flag == 2)
	{
	  c->linemate = 0;
	  c->deraumere = 0;
	  c->sibur = 0;
	  c->phiras = 0;
	  success(serveur, client, cs);
	}
    }
  else if (client[cs].flag == 0 || client[cs].flag == 2)
    fail(serveur, client, cs);
  return (0);
}

int		elevation7(t_serv *serveur, t_client *client, int cs)
{
  int		i;
  t_case	*c;

  c = &serveur->map_case[client[cs].drone->posy][client[cs].drone->posx];
  i = check_level(serveur, client[cs].drone->posy, client[cs].drone->posx, 7);
  if (c->players == 6 && c->linemate == 2 &&
      c->deraumere == 2 && c->sibur == 2 && c->mendiane == 2 &&
      c->phiras == 2 && c->thystame == 1 && i)
    {
      if (client[cs].flag == 0)
	start_inc(serveur, client, cs, 8);
      if (client[cs].flag == 2)
	{
	  c->linemate = 0;
	  c->deraumere = 0;
	  c->sibur = 0;
	  c->mendiane = 0;
	  c->phiras = 0;
	  c->thystame = 0;
	  success(serveur, client, cs);
	}
    }
  else if (client[cs].flag == 0 || client[cs].flag == 2)
    fail(serveur, client, cs);
  return (0);
}
