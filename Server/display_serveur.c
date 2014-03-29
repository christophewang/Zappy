/*
** display_serveur.c for display_serveur in /home/wang_c//Desktop/Zappy_Final
** 
** Made by christophe wang
** Login   <wang_c@epitech.net>
** 
** Started on  Sun Jul 10 15:13:21 2011 christophe wang
** Last update Sun Jul 10 15:13:24 2011 christophe wang
*/

#include <stdio.h>
#include "serveur.h"

void		display_serveur(t_serv *serv)
{
  int		i;

  i = 0;
  printf("%s%s", R, ZAPPY);
  printf("%sListening on port %d...\n", G, serv->port);
  printf("%sConfiguration : Max(%d) WorldX(%d) WorldY(%d) T(%d)\n", Y,
	 serv->max_clients, serv->world_x, serv->world_y, serv->speed);
  printf("%sTeams :\n", P);
  while (i < serv->nb_team)
    printf("\tName(%s) Max(%d)\n", serv->team[i++].name, serv->max_clients);
  printf("%sGenerating world...%s\n", W, D);
}
