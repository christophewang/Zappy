/*
** init_world.c for init_world in /home/wang_c//Desktop/Zappy_Final
** 
** Made by christophe wang
** Login   <wang_c@epitech.net>
** 
** Started on  Sun Jul 10 15:14:42 2011 christophe wang
** Last update Sun Jul 10 15:14:43 2011 christophe wang
*/

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "serveur.h"

void		init_world(t_serv *serveur, char **argv)
{
  int		i;

  i = 0;
  serveur->world_x = DEFAULT_WORLD;
  serveur->world_y = DEFAULT_WORLD;
  while (argv[i])
    {
      if (!strcmp("-x", argv[i]) && argv[i + 1])
	serveur->world_x = atoi(argv[i + 1]);
      if (!strcmp("-y", argv[i]) && argv[i + 1])
	serveur->world_y = atoi(argv[i + 1]);
      i++;
    }
  if (!serveur->world_x || !serveur->world_y)
    {
      fprintf(stderr, ERRWORLD);
      exit(EXIT_FAILURE);
    }
}
