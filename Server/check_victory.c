/*
** check_victory.c for check_victory in /home/wang_c//Desktop/Zappy_Final/Serveur
** 
** Made by christophe wang
** Login   <wang_c@epitech.net>
** 
** Started on  Sun Jul 10 19:57:25 2011 christophe wang
** Last update Sun Jul 10 19:58:08 2011 christophe wang
*/

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "serveur.h"

void		check_victory(t_serv *serveur)
{
  int		i;
  int		j;
  int		check;

  i = 0;
  while (i < serveur->nb_team)
    {
      j = 0;
      check = 0;
      while (j < serveur->team[i].max_clients)
	{
	  if (serveur->team[i].drone[j].level == 8)
	    check++;
	  if (check >= 6)
	    {
	      g_exit = 0;
	      printf(WIN, R, W, serveur->team[i].name, R, D);
	      if (serveur->graphic_flag)
		send_seg(serveur, serveur->team[i].name);
	      return ;
	    }
	  j++;
	}
      i++;
    }
}
