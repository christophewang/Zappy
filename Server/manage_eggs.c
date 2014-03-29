/*
** manage_eggs.c for manage_eggs in /home/wang_c//Desktop/Zappy_Final/Serveur
** 
** Made by christophe wang
** Login   <wang_c@epitech.net>
** 
** Started on  Sun Jul 10 20:07:45 2011 christophe wang
** Last update Sun Jul 10 21:00:13 2011 christophe wang
*/

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <time.h>
#include "serveur.h"

void		init_new_drones(t_serv *serveur, int i, int id, int id_egg)
{
  srand(time(NULL));
  serveur->team[i].drone[id].status = GHOST;
  serveur->team[i].drone[id].level = 1;
  serveur->team[i].drone[id].id_egg = id_egg + 1;
  serveur->team[i].drone[id].direction = (rand() % 4);
  serveur->team[i].drone[id].posy = serveur->egg[id_egg].posy;
  serveur->team[i].drone[id].posx = serveur->egg[id_egg].posx;
  serveur->team[i].drone[id].nourriture = 10;
  serveur->team[i].drone[id].linemate = 0;
  serveur->team[i].drone[id].deraumere = 0;
  serveur->team[i].drone[id].sibur = 0;
  serveur->team[i].drone[id].mendiane = 0;
  serveur->team[i].drone[id].phiras = 0;
  serveur->team[i].drone[id].thystame = 0;
}

void		hatching_eggs(t_serv *serveur, int i)
{
  int	       	id;

  printf(HATCH, B, serveur->egg[i].posy, serveur->egg[i].posx, D);
  id = serveur->egg[i].team;
  serveur->team[id].nb_clients++;
  serveur->team[id].max_clients++;
  serveur->egg[i].state = INACTIVE;
  serveur->team[id].drone = xrealloc(serveur->team[id].drone,
				     sizeof(*serveur->team[id].drone) *
				     serveur->team[id].max_clients);
  init_new_drones(serveur, id, serveur->team[id].max_clients - 1, i);
  serveur->map_case[serveur->egg[i].posy][serveur->egg[i].posx].eggs--;
  if (serveur->graphic_flag)
    send_eht(serveur, i);
}

void	       	check_eggs(t_serv *serveur)
{
  int  		i;
  long	       	hatchdelay;

  i = 0;
  while (i < serveur->nb_eggs)
    {
      if (serveur->egg[i].state == ACTIVE)
	{
	  hatchdelay = convert_usec(serveur->time) -
	    convert_usec(serveur->egg[i].hatchtime);
	  xgettimeofday(&serveur->egg[i].hatchtime);
	  serveur->egg[i].hatch -= hatchdelay;
	  if (serveur->egg[i].hatch <= 0)
	    hatching_eggs(serveur, i);
	}
      i++;
    }
}
