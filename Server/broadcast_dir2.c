/*
** broadcast_dir2.c for broadcast_dir in /home/wang_c//Desktop/Zappy_Final
** 
** Made by christophe wang
** Login   <wang_c@epitech.net>
** 
** Started on  Sun Jul 10 21:20:38 2011 christophe wang
** Last update Sun Jul 10 21:28:25 2011 christophe wang
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "serveur.h"

int	check_drone_dir5(t_drone *tmp)
{
  if (tmp->direction == NORTH)
    return (7);
  if (tmp->direction == EAST)
    return (1);
  if (tmp->direction == SOUTH)
    return (3);
  if (tmp->direction == WEST)
    return (5);
  return (0);
}

int	check_drone_dir6(t_drone *tmp)
{
  if (tmp->direction == NORTH)
    return (3);
  if (tmp->direction == EAST)
    return (5);
  if (tmp->direction == SOUTH)
    return (7);
  if (tmp->direction == WEST)
    return (1);
  return (0);
}

int	check_drone_dir7(t_drone *tmp)
{
  if (tmp->direction == NORTH)
    return (1);
  if (tmp->direction == EAST)
    return (3);
  if (tmp->direction == SOUTH)
    return (5);
  if (tmp->direction == WEST)
    return (7);
  return (0);
}

int	check_drone_dir8(t_drone *tmp)
{
  if (tmp->direction == NORTH)
    return (5);
  if (tmp->direction == EAST)
    return (7);
  if (tmp->direction == SOUTH)
    return (1);
  if (tmp->direction == WEST)
    return (3);
  return (0);
}
