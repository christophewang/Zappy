/*
** connect_nbr.c for connect_nbr in /home/wang_c//Desktop/Zappy_Final
** 
** Made by christophe wang
** Login   <wang_c@epitech.net>
** 
** Started on  Sun Jul 10 15:12:48 2011 christophe wang
** Last update Sun Jul 10 15:12:50 2011 christophe wang
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "serveur.h"

int		connect_nbr(t_serv *serv, t_client *client, int cs, char **tab)
{
  if (tab[1])
    return (-1);
  memset(client[cs].buffer, 0, BUFF_SIZE);
  sprintf(client[cs].buffer, "%d\n", serv->team[client[cs].team].nb_clients);
  xsend(cs, client[cs].buffer, strlen(client[cs].buffer), 0);
  delete_command(client, cs);
  parse_command(serv, client, cs);
  return (0);
}
