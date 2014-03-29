/*
** put_ress.c for put_ress in /home/wang_c//Desktop/Zappy_Final
** 
** Made by christophe wang
** Login   <wang_c@epitech.net>
** 
** Started on  Sun Jul 10 19:27:08 2011 christophe wang
** Last update Sun Jul 10 19:37:42 2011 christophe wang
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "serveur.h"

void		put_nourriture(t_serv *serveur, t_client *client, int cs)
{
  int		x;
  int		y;

  x = client[cs].drone->posx;
  y = client[cs].drone->posy;
  client[cs].timelife -= 1000000 * 126 / serveur->speed;
  serveur->map_case[y][x].nourriture++;
  client[cs].drone->nourriture--;
  if (serveur->graphic_flag)
    send_pdr(serveur, client, cs, 0);
}

void		put_linemate(t_serv *serveur, t_client *client, int cs)
{
  int		x;
  int		y;

  x = client[cs].drone->posx;
  y = client[cs].drone->posy;
  serveur->map_case[y][x].linemate++;
  client[cs].drone->linemate--;
  if (serveur->graphic_flag)
    send_pdr(serveur, client, cs, 1);

}

void		put_deraumere(t_serv *serveur, t_client *client, int cs)
{
  int		x;
  int		y;

  x = client[cs].drone->posx;
  y = client[cs].drone->posy;
  serveur->map_case[y][x].deraumere++;
  client[cs].drone->deraumere--;
  if (serveur->graphic_flag)
    send_pdr(serveur, client, cs, 2);
}

void		put_sibur(t_serv *serveur, t_client *client, int cs)
{
  int		x;
  int		y;

  x = client[cs].drone->posx;
  y = client[cs].drone->posy;
  serveur->map_case[y][x].sibur++;
  client[cs].drone->sibur--;
  if (serveur->graphic_flag)
    send_pdr(serveur, client, cs, 3);
}

int		put_items(t_serv *serveur, t_client *client, int cs, char *name)
{
  int		x;
  int		y;

  x = client[cs].drone->posx;
  y = client[cs].drone->posy;
  if (!strcmp(name, "nourriture") && client[cs].drone->nourriture)
    put_nourriture(serveur, client, cs);
  else if (!strcmp(name, "linemate") && client[cs].drone->linemate)
    put_linemate(serveur, client, cs);
  else if (!strcmp(name, "deraumere") && client[cs].drone->deraumere)
    put_deraumere(serveur, client, cs);
  else if (!strcmp(name, "sibur") && client[cs].drone->sibur)
    put_sibur(serveur, client, cs);
  else if (!strcmp(name, "mendiane") && client[cs].drone->mendiane)
    put_mendiane(serveur, client, cs);
  else if (!strcmp(name, "phiras") && client[cs].drone->phiras)
    put_phiras(serveur, client, cs);
  else if (!strcmp(name, "thystame") && client[cs].drone->thystame)
    put_thystame(serveur, client, cs);
  else
    return (0);
  return (1);
}
