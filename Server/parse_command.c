/*
** parse_command.c for parse_command in /home/wang_c//Desktop/Zappy_Final
** 
** Made by christophe wang
** Login   <wang_c@epitech.net>
** 
** Started on  Sun Jul 10 19:42:04 2011 christophe wang
** Last update Sun Jul 10 19:42:36 2011 christophe wang
*/

#include <stdio.h>
#include <string.h>
#include "serveur.h"

void		parse_command(t_serv *serveur, t_client *client, int cs)
{
  client[cs].len = strlen(client[cs].request[0]);
  if (client[cs].len > 1 && client[cs].request[0][client[cs].len - 1] == '\n')
    {
      if (client[cs].teamflag == 1)
	{
	  if (check_commandlist(serveur, client, cs) == -1)
	    {
	      xsend(cs, KO, strlen(KO), 0);
	      delete_command(client, cs);
	      parse_command(serveur, client, cs);
	    }
	}
      else if (client[cs].teamflag == 2)
	{
	  if (check_graphlist(serveur, client, cs) == -1)
	    xsend(cs, "suc\n", strlen("suc\n"), 0);
	  delete_command(client, cs);
	}
    }
}
