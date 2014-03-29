/*
** incantation_low.c for incantation_low in /home/wang_c//Desktop/Zappy_Final
** 
** Made by christophe wang
** Login   <wang_c@epitech.net>
** 
** Started on  Sun Jul 10 19:00:27 2011 christophe wang
** Last update Sun Jul 10 19:01:44 2011 christophe wang
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "serveur.h"

int		elevation1(t_serv *serveur, t_client *client, int cs)
{
  int		i;
  t_case	*c;

  c = &serveur->map_case[client[cs].drone->posy][client[cs].drone->posx];
  i = check_level(serveur, client[cs].drone->posy, client[cs].drone->posx, 1);
  if (c->players == 1 && c->linemate == 1 && !c->deraumere && !c->sibur &&
      !c->mendiane && !c->phiras && !c->thystame && i)
    {
      if (client[cs].flag == 0)
	start_inc(serveur, client, cs, 2);
      if (client[cs].flag == 2)
	{
	  c->linemate = 0;
	  success(serveur, client, cs);
	}
    }
  else if (client[cs].flag == 0 || client[cs].flag == 2)
    fail(serveur, client, cs);
  return (0);
}

int		elevation2(t_serv *serveur, t_client *client, int cs)
{
  int		i;
  t_case	*c;

  c = &serveur->map_case[client[cs].drone->posy][client[cs].drone->posx];
  i = check_level(serveur, client[cs].drone->posy, client[cs].drone->posx, 2);
  if (c->players == 2 && c->linemate == 1 && c->deraumere == 1 &&
      c->sibur == 1 && !c->mendiane && !c->phiras && !c->thystame && i)
    {
      if (client[cs].flag == 0)
	start_inc(serveur, client, cs, 3);
      if (client[cs].flag == 2)
	{
	  c->linemate = 0;
	  c->deraumere = 0;
	  c->sibur = 0;
	  success(serveur, client, cs);
	}
    }
  else if (client[cs].flag == 0 || client[cs].flag == 2)
    fail(serveur, client, cs);
  return (0);
}

int		elevation3(t_serv *serveur, t_client *client, int cs)
{
  int		i;
  t_case	*c;

  c = &serveur->map_case[client[cs].drone->posy][client[cs].drone->posx];
  i = check_level(serveur, client[cs].drone->posy, client[cs].drone->posx, 3);
  if (c->players == 2 && c->linemate == 2 && !c->deraumere &&
      c->sibur == 1 && !c->mendiane && c->phiras == 2 && !c->thystame && i)
    {
      if (client[cs].flag == 0)
	start_inc(serveur, client, cs, 4);
      if (client[cs].flag == 2)
	{
	  c->linemate = 0;
	  c->sibur = 0;
	  c->phiras = 0;
	  success(serveur, client, cs);
	}
    }
  else if (client[cs].flag == 0 || client[cs].flag == 2)
    fail(serveur, client, cs);
  return (0);
}

int		elevation4(t_serv *serveur, t_client *client, int cs)
{
  int		i;
  t_case	*c;

  c = &serveur->map_case[client[cs].drone->posy][client[cs].drone->posx];
  i = check_level(serveur, client[cs].drone->posy, client[cs].drone->posx, 4);
  if (c->players == 4 && c->linemate == 1 && c->deraumere == 1 &&
      c->sibur == 2 && !c->mendiane && c->phiras == 1 && !c->thystame && i)
    {
      if (client[cs].flag == 0)
	start_inc(serveur, client, cs, 5);
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

int		elevation5(t_serv *serveur, t_client *client, int cs)
{
  int		i;
  t_case	*c;

  c = &serveur->map_case[client[cs].drone->posy][client[cs].drone->posx];
  i = check_level(serveur, client[cs].drone->posy, client[cs].drone->posx, 5);
  if (c->players == 4 && c->linemate == 1 && c->deraumere == 2 &&
      c->sibur == 1 && c->mendiane == 3 && !c->phiras&& !c->thystame && i)
    {
      if (client[cs].flag == 0)
	start_inc(serveur, client, cs, 6);
      if (client[cs].flag == 2)
	{
	  c->linemate = 0;
	  c->deraumere = 0;
	  c->sibur = 0;
	  c->mendiane = 0;
	  success(serveur, client, cs);
	}
    }
  else if (client[cs].flag == 0 || client[cs].flag == 2)
    fail(serveur, client, cs);
  return (0);
}
