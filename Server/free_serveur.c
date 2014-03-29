/*
** free_serveur.c for free_serveur in /home/wang_c//Desktop/Zappy_Final
** 
** Made by christophe wang
** Login   <wang_c@epitech.net>
** 
** Started on  Sun Jul 10 15:13:52 2011 christophe wang
** Last update Sun Jul 10 15:13:54 2011 christophe wang
*/

#include <stdlib.h>
#include "serveur.h"

void			free_serveur(t_serv *serveur, t_client *client)
{
  int		i;

  i = 0;
  while (i < serveur->nb_team)
    {
      xfree(serveur->team[i].name);
      xfree(serveur->team[i].drone);
      i++;
    }
  xfree(serveur->egg);
  xfree(serveur->team);
  xfree(client);
}

void			free_map(t_serv *serveur)
{
  int		i;

  i = 0;
  while (i < serveur->world_y)
    xfree(serveur->map_case[i++]);
  xfree(serveur->map_case);
}

void			free_tab(char **tab)
{
  int			i;

  i = 0;
  while (tab[i])
    xfree(tab[i++]);
  xfree(tab);
}
