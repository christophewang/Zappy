/*
** init_drones.c for init_drones in /home/wang_c//Desktop/Zappy_Final
** 
** Made by christophe wang
** Login   <wang_c@epitech.net>
** 
** Started on  Sun Jul 10 19:15:46 2011 christophe wang
** Last update Sun Jul 10 19:16:37 2011 christophe wang
*/

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "serveur.h"

void		init_drones(t_serv *serveur, int i, int j)
{
  serveur->team[i].drone[j].status = INACTIVE;
  serveur->team[i].drone[j].level = 1;
  serveur->team[i].drone[j].id_egg = 0;
  serveur->team[i].drone[j].direction = NORTH;
  serveur->team[i].drone[j].nourriture = 0;
  serveur->team[i].drone[j].linemate = 0;
  serveur->team[i].drone[j].deraumere = 0;
  serveur->team[i].drone[j].sibur = 0;
  serveur->team[i].drone[j].mendiane = 0;
  serveur->team[i].drone[j].phiras = 0;
  serveur->team[i].drone[j].thystame = 0;
}

void		create_drones(t_serv *serveur)
{
  int		i;
  int		j;

  i = 0;
  while (i < serveur->nb_team)
    {
      j = 0;
      serveur->team[i].drone = xmalloc(sizeof(*serveur->team[i].drone) *
				       serveur->team[i].max_clients);
      while (j < serveur->team[i].max_clients)
	init_drones(serveur, i, j++);
      i++;
    }
}
