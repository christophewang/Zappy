/*
** broadcast_dir.c for broadcastdir in /home/wang_c//Desktop/Zappy_Final
** 
** Made by christophe wang
** Login   <wang_c@epitech.net>
** 
** Started on  Sun Jul 10 21:19:32 2011 christophe wang
** Last update Sun Jul 10 21:28:07 2011 christophe wang
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "serveur.h"

int	check_drone_dir1(t_drone *tmp)
{
  if (tmp->direction == NORTH)
    return (2);
  if (tmp->direction == EAST)
    return (4);
  if (tmp->direction == SOUTH)
    return (6);
  if (tmp->direction == WEST)
    return (8);
  return (0);
}

int	check_drone_dir2(t_drone *tmp)
{
  if (tmp->direction == NORTH)
    return (4);
  if (tmp->direction == EAST)
    return (6);
  if (tmp->direction == SOUTH)
    return (8);
  if (tmp->direction == WEST)
    return (2);
  return (0);
}

int	check_drone_dir3(t_drone *tmp)
{
  if (tmp->direction == NORTH)
    return (8);
  if (tmp->direction == EAST)
    return (2);
  if (tmp->direction == SOUTH)
    return (4);
  if (tmp->direction == WEST)
    return (6);
  return (0);
}

int	check_drone_dir4(t_drone *tmp)
{
  if (tmp->direction == NORTH)
    return (6);
  if (tmp->direction == EAST)
    return (8);
  if (tmp->direction == SOUTH)
    return (2);
  if (tmp->direction == WEST)
    return (4);
  return (0);
}
