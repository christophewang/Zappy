/*
** init_team.c for init_team in /home/wang_c//Desktop/Zappy_Final
** 
** Made by christophe wang
** Login   <wang_c@epitech.net>
** 
** Started on  Sun Jul 10 15:14:27 2011 christophe wang
** Last update Sun Jul 10 19:16:14 2011 christophe wang
*/

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "serveur.h"

static int		count_team(char **argv)
{
  int		i;
  int		nb;

  i = 0;
  nb = 0;
  while (argv[i])
    {
      if (!strcmp("-n", argv[i]))
	{
	  while (argv[i + 1] && argv[i + 1][0] != '-')
	    {
	      nb++;
	      i++;
	    }
	}
      i++;
    }
  return (nb);
}

static void		get_teamname(t_serv *serveur, char **argv)
{
  int		i;
  int		j;

  i = 0;
  j = 0;
  serveur->team = xmalloc(sizeof(*serveur->team) * serveur->nb_team + 1);
  while (argv[i])
    {
      if (!strcmp("-n", argv[i]))
	{
	  while (argv[i + 1] && argv[i + 1][0] != '-')
	    {
	      serveur->team[j].max_clients = serveur->max_clients;
	      serveur->team[j].nb_clients = serveur->max_clients;
	      serveur->team[j].name = xmalloc(sizeof(serveur->team[j].name) *
					      strlen(argv[i + 1]));
	      strcpy(serveur->team[j].name, argv[i + 1]);
	      i++;
	      j++;
	    }
	}
      i++;
    }
}

static void	check_teamname(t_serv *serveur)
{
  int		i;
  int		j;

  i = 0;
  while (i < serveur->nb_team)
    {
      j = 0;
      while (j < serveur->nb_team)
	{
	  if (i != j && !strcmp(serveur->team[i].name, serveur->team[j].name))
	    {
	      fprintf(stderr, ERRTEAMNAME);
	      exit(EXIT_FAILURE);
	    }
	  j++;
	}
      i++;
    }
}

int		init_team(t_serv *serveur, char **argv)
{
  if ((serveur->nb_team = count_team(argv)) >= 2)
    {
      get_teamname(serveur, argv);
      check_teamname(serveur);
      create_drones(serveur);
      serveur->nb_eggs = 0;
      serveur->max_eggs = 0;
      serveur->egg = xmalloc(sizeof(*serveur->egg));
    }
  else if (serveur->nb_team == 1)
    {
      fprintf(stderr, ERRNBTEAM);
      exit(EXIT_FAILURE);
    }
  else if (serveur->nb_team == 0)
    return (-1);
  return (0);
}
