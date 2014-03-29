/*
** regen_ress.c for regen_ress in /home/wang_c//Desktop/Zappy_Final
** 
** Made by christophe wang
** Login   <wang_c@epitech.net>
** 
** Started on  Sun Jul 10 18:58:03 2011 christophe wang
** Last update Sun Jul 10 18:59:37 2011 christophe wang
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "serveur.h"

void		regen_ressources(t_serv *serveur)
{
  int		i;
  int		x;
  int		y;

  i = 0;
  srand(time(NULL));
  while (i < 3)
    {
      x = rand() % serveur->world_x;
      y = rand() % serveur->world_y;
      serveur->map_case[y][x].linemate = rand() % 3;
      serveur->map_case[y][x].deraumere = rand() % 3;
      serveur->map_case[y][x].sibur = rand() % 3;
      serveur->map_case[y][x].mendiane = rand() % 2;
      serveur->map_case[y][x].phiras = rand() % 2;
      serveur->map_case[y][x].thystame = rand() % 2;
      i++;
    }
}

void		regen_food(t_serv *serveur)
{
  int		x;
  int		y;

  srand(time(NULL));
  x = rand() % serveur->world_x;
  y = rand() % serveur->world_y;
  serveur->map_case[y][x].nourriture++;
}
