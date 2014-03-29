/*
** check_action.c for check_action in /home/wang_c//Desktop/Zappy_Final/Serveur
** 
** Made by christophe wang
** Login   <wang_c@epitech.net>
** 
** Started on  Sun Jul 10 19:59:35 2011 christophe wang
** Last update Sun Jul 10 20:00:48 2011 christophe wang
*/

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "serveur.h"

void		check_action(t_serv *serveur, t_client *client)
{
  int		cs;

  cs = 0;
  while (cs < serveur->limit)
    {
      if (serveur->fd_type[cs] == FD_CLIENT &&
	  (client[cs].teamflag == 1 || client[cs].teamflag == 2))
	parse_command(serveur, client, cs);
      cs++;
    }
}
