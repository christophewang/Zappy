/*
** create_world.c for create_map in /home/wang_c//Desktop/Zappy_Final
** 
** Made by christophe wang
** Login   <wang_c@epitech.net>
** 
** Started on  Sun Jul 10 15:13:02 2011 christophe wang
** Last update Sun Jul 10 20:35:13 2011 christophe wang
*/

#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include "serveur.h"

static void	map_failure(t_serv *serveur)
{
  xfree(serveur->map_case);
  free_serveur(serveur, NULL);
  printf("%sCreating map... failure.%s\n", R, D);
  exit(EXIT_FAILURE);
}

static void	*creating_map_size(size_t size, t_serv *serveur)
{
  void		*map;

  map = malloc(size);
  if (map == NULL)
    map_failure(serveur);
  return (map);
}

static void	empty_case(t_serv *serveur, int y, int x)
{
  serveur->map_case[y][x].linemate = 0;
  serveur->map_case[y][x].deraumere = 0;
  serveur->map_case[y][x].sibur = 0;
  serveur->map_case[y][x].mendiane = 0;
  serveur->map_case[y][x].phiras = 0;
  serveur->map_case[y][x].thystame = 0;
}

static void	init_case(t_serv *serveur, int y, int x)
{
  int		i;

  serveur->map_case[y][x].players = 0;
  serveur->map_case[y][x].eggs = 0;
  serveur->map_case[y][x].nourriture = rand() % 3;
  i = rand() % 2;
  if (i == 1)
    {
      serveur->map_case[y][x].linemate = rand() % 3;
      serveur->map_case[y][x].deraumere = rand() % 3;
      serveur->map_case[y][x].sibur = rand() % 3;
      serveur->map_case[y][x].mendiane = rand() % 2;
      serveur->map_case[y][x].phiras = rand() % 2;
      serveur->map_case[y][x].thystame = rand() % 2;
    }
  else
    empty_case(serveur, y, x);
}

void		create_world(t_serv *serveur)
{
  int		y;
  int		x;

  y = 0;
  srand(time(NULL));
  serveur->map_case = creating_map_size(sizeof(*serveur->map_case) *
					serveur->world_y, serveur);
  while (y < serveur->world_y)
    {
      x = 0;
      serveur->map_case[y] = creating_map_size(sizeof(**serveur->map_case) *
					       serveur->world_x, serveur);
      while (x < serveur->world_x)
	init_case(serveur, y, x++);
       y++;
    }
  printf("%s--> %sDone %s\n", W, G, D);
}
