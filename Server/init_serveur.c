/*
** init_serveur.c for init_serveur in /home/wang_c//Desktop/Zappy_Final
** 
** Made by christophe wang
** Login   <wang_c@epitech.net>
** 
** Started on  Sun Jul 10 15:14:16 2011 christophe wang
** Last update Sun Jul 10 15:14:18 2011 christophe wang
*/

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "serveur.h"

static void		init_max_clients(t_serv *serveur, char **argv)
{
  int		i;

  i = 0;
  serveur->max_clients = DEFAULT_MAXCLIENTS;
  while (argv[i])
    {
      if (!strcmp("-c", argv[i]) && argv[i + 1])
	serveur->max_clients = atoi(argv[i + 1]);
      i++;
    }
}

static void		init_port(t_serv *serveur, char **argv)
{
  int		i;

  i = 0;
  serveur->port = DEFAULT_PORT;
  while (argv[i])
    {
      if (!strcmp("-p", argv[i]) && argv[i + 1])
	serveur->port = atoi(argv[i + 1]);
      i++;
    }
  if (serveur->port < MIN_PORT || serveur->port > MAX_PORT)
    {
      fprintf(stderr, ERRPORT);
      serveur->port = DEFAULT_PORT;
    }
}

static void		init_speed(t_serv *serveur, char **argv)
{
  int		i;

  i = 0;
  serveur->speed = DEFAULT_SPEED;
  while (argv[i])
    {
      if (!strcmp("-t", argv[i]) && argv[i + 1])
	serveur->speed = atoi(argv[i + 1]);
      i++;
    }
  if (serveur->speed < MIN_SPEED || serveur->speed > MAX_SPEED)
    {
      fprintf(stderr, ERRSPEED);
      exit(EXIT_FAILURE);
    }
}

int		init_serveur(t_serv *serveur, char **argv)
{
  int		value;

  serveur->graphic_flag = 0;
  init_port(serveur, argv);
  init_world(serveur, argv);
  init_max_clients(serveur, argv);
  init_speed(serveur, argv);
  value = init_team(serveur, argv);
  return (value);
}
