/*
** items.c for items in /home/wang_c//Desktop/Zappy_Final
** 
** Made by christophe wang
** Login   <wang_c@epitech.net>
** 
** Started on  Sun Jul 10 15:14:57 2011 christophe wang
** Last update Sun Jul 10 19:35:48 2011 christophe wang
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "serveur.h"

int		inventaire(t_serv *serveur, t_client *client, int cs, char **tab)
{
  if (tab[1])
    return (-1);
  if (client[cs].flag == 0)
    {
      client[cs].timelaps = 1000000 * 7 / serveur->speed;
      client[cs].flag = 1;
    }
  if (client[cs].flag == 2)
    {
      printf(INVENTORY, B, serveur->team[client[cs].team].name,
	     client[cs].id_drone, D);
      memset(client[cs].buffer, 0, BUFF_SIZE);
      sprintf(client[cs].buffer, INV, client[cs].drone->nourriture,
	      client[cs].drone->linemate, client[cs].drone->deraumere,
	      client[cs].drone->sibur, client[cs].drone->mendiane,
	      client[cs].drone->phiras, client[cs].drone->thystame);
      xsend(cs, client[cs].buffer, strlen(client[cs].buffer), 0);
      delete_command(client, cs);
      parse_command(serveur, client, cs);
    }
  return (0);
}

int		prend(t_serv *serveur, t_client *client, int cs, char **tab)
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
      if (get_items(serveur, client, cs, tab[1]))
	xsend(cs, OK, strlen(OK), 0);
      else
	xsend(cs, KO, strlen(KO), 0);
      delete_command(client, cs);
      parse_command(serveur, client, cs);
    }
  return (0);
}

int		pose(t_serv *serveur, t_client *client, int cs, char **tab)
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
      if (put_items(serveur, client, cs, tab[1]))
	xsend(cs, OK, strlen(OK), 0);
      else
	xsend(cs, KO, strlen(KO), 0);
      delete_command(client, cs);
      parse_command(serveur, client, cs);
    }
  return (0);
}
