/*
** get_ress.c for get_ress.c in /home/wang_c//Desktop/Zappy_Final
** 
** Made by christophe wang
** Login   <wang_c@epitech.net>
** 
** Started on  Sun Jul 10 19:18:11 2011 christophe wang
** Last update Sun Jul 10 19:23:45 2011 christophe wang
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "serveur.h"

void		get_nourriture(t_serv *serveur, t_client *client, int cs)
{
  int		x;
  int		y;

  x = client[cs].drone->posx;
  y = client[cs].drone->posy;
  client[cs].timelife += 1000000 * 126 / serveur->speed;
  serveur->map_case[y][x].nourriture--;
  client[cs].drone->nourriture++;
  regen_food(serveur);
  if (serveur->graphic_flag)
    send_pgt(serveur, client, cs, 0);
}

void		get_linemate(t_serv *serveur, t_client *client, int cs)
{
  int		x;
  int		y;

  x = client[cs].drone->posx;
  y = client[cs].drone->posy;
  serveur->map_case[y][x].linemate--;
  client[cs].drone->linemate++;
  if (serveur->graphic_flag)
    send_pgt(serveur, client, cs, 1);
}

void		get_deraumere(t_serv *serveur, t_client *client, int cs)
{
  int		x;
  int		y;

  x = client[cs].drone->posx;
  y = client[cs].drone->posy;
  serveur->map_case[y][x].deraumere--;
  client[cs].drone->deraumere++;
  if (serveur->graphic_flag)
    send_pgt(serveur, client, cs, 2);
}

void		get_sibur(t_serv *serveur, t_client *client, int cs)
{
  int		x;
  int		y;

  x = client[cs].drone->posx;
  y = client[cs].drone->posy;
  serveur->map_case[y][x].sibur--;
  client[cs].drone->sibur++;
  if (serveur->graphic_flag)
    send_pgt(serveur, client, cs, 3);
}

int		get_items(t_serv *serveur, t_client *client, int cs, char *name)
{
  int		x;
  int		y;

  x = client[cs].drone->posx;
  y = client[cs].drone->posy;
  if (!strcmp(name, "nourriture") && serveur->map_case[y][x].nourriture)
    get_nourriture(serveur, client, cs);
  else if (!strcmp(name, "linemate") && serveur->map_case[y][x].linemate)
    get_linemate(serveur, client, cs);
  else if (!strcmp(name, "deraumere") && serveur->map_case[y][x].deraumere)
    get_deraumere(serveur, client, cs);
  else if (!strcmp(name, "sibur") && serveur->map_case[y][x].sibur)
    get_sibur(serveur, client, cs);
  else if (!strcmp(name, "mendiane") && serveur->map_case[y][x].mendiane)
    get_mendiane(serveur, client, cs);
  else if (!strcmp(name, "phiras") && serveur->map_case[y][x].phiras)
    get_phiras(serveur, client, cs);
  else if (!strcmp(name, "thystame") && serveur->map_case[y][x].thystame)
    get_thystame(serveur, client, cs);
  else
    return (0);
  return (1);
}

