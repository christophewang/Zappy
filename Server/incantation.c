/*
** incantation.c for incantation in /home/wang_c//Desktop/Zappy_Final
** 
** Made by christophe wang
** Login   <wang_c@epitech.net>
** 
** Started on  Sun Jul 10 15:14:04 2011 christophe wang
** Last update Sun Jul 10 19:11:50 2011 christophe wang
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "serveur.h"

t_elev		elev_tab[8] = {
  {1, elevation1},
  {2, elevation2},
  {3, elevation3},
  {4, elevation4},
  {5, elevation5},
  {6, elevation6},
  {7, elevation7},
  {0, NULL},
};

void		success(t_serv *serveur, t_client *client, int cs)
{
  send_incantation_msg(serveur, client, cs);
  delete_command(client, cs);
  parse_command(serveur, client, cs);
  if (serveur->graphic_flag)
    send_pie(serveur, client, cs, 1);
}

void		fail(t_serv *serveur, t_client *client, int cs)
{
  if (serveur->graphic_flag && client[cs].flag == 2)
    send_pie(serveur, client, cs, 0);
  fail_elevation(serveur, client, cs);
}

int		incantation(t_serv *serv, t_client *client, int cs, char **tab)
{
  int		i;

  if (tab[1])
    return (-1);
  i = 0;
  while (elev_tab[i].level != 0)
    {
      if (elev_tab[i].level == client[cs].drone->level)
	return (elev_tab[i].ptr_func(serv, client, cs));
      i++;
    }
  return (0);
}
