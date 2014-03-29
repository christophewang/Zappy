/*
** view.c for view in /home/wang_c//Desktop/Zappy_Final
** 
** Made by christophe wang
** Login   <wang_c@epitech.net>
** 
** Started on  Sun Jul 10 15:17:33 2011 christophe wang
** Last update Sun Jul 10 20:18:49 2011 christophe wang
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "serveur.h"

void		show_players(char *buffer, t_serv *serveur, int y, int x)
{
  int		i;

  i = serveur->map_case[y][x].players;
  while (i-- > 0)
    strcat(buffer, " joueur");
}

void		show_res(char *buffer, t_serv *serveur, int y, int x)
{
  int		i;

  show_players(buffer, serveur, y, x);
  i = serveur->map_case[y][x].nourriture;
  while (i-- > 0)
    strcat(buffer, " nourriture");
  i = serveur->map_case[y][x].linemate;
  while (i-- > 0)
    strcat(buffer, " linemate");
  i = serveur->map_case[y][x].deraumere;
  while (i-- > 0)
    strcat(buffer, " deraumere");
  i = serveur->map_case[y][x].sibur;
  while (i-- > 0)
    strcat(buffer, " sibur");
  i = serveur->map_case[y][x].mendiane;
  while (i-- > 0)
    strcat(buffer, " mendiane");
  i = serveur->map_case[y][x].phiras;
  while (i-- > 0)
    strcat(buffer, " phiras");
  i = serveur->map_case[y][x].thystame;
  while (i-- > 0)
    strcat(buffer, " thystame");
}

void		do_voir(t_serv *serveur, t_client *client, int cs)
{
  t_view	view;

  printf(LOOK, B, serveur->team[client[cs].team].name, client[cs].id_drone, D);
  memset(view.buffer, 0, BUFF_SIZE);
  strcat(view.buffer, "{");
  if (client[cs].drone->direction == NORTH)
    north_view(serveur, client, cs, &view);
  else if (client[cs].drone->direction == EAST)
    east_view(serveur, client, cs, &view);
  else if (client[cs].drone->direction == SOUTH)
    south_view(serveur, client, cs, &view);
  else if (client[cs].drone->direction == WEST)
    west_view(serveur, client, cs, &view);
  strcat(view.buffer, "}\n");
  xsend(cs, view.buffer, strlen(view.buffer), 0);
  delete_command(client, cs);
  parse_command(serveur, client, cs);
}

int		voir(t_serv *serveur, t_client *client, int cs, char **tab)
{
  if (tab[1])
    return (-1);
  if (client[cs].flag == 0)
    {
      client[cs].timelaps = 1000000 * 7 / serveur->speed;
      client[cs].flag = 1;
    }
  if (client[cs].flag == 2)
    do_voir(serveur, client, cs);
  return (0);
}
