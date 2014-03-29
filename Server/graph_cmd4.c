/*
** graph_cmd4.c for graph_cmd4 in /home/wang_c//Desktop/Zappy_Final/Serveur
** 
** Made by christophe wang
** Login   <wang_c@epitech.net>
** 
** Started on  Sun Jul 10 20:22:38 2011 christophe wang
** Last update Sun Jul 10 20:23:04 2011 christophe wang
*/

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "serveur.h"

void		send_plv(t_serv *serveur, t_client *client, int cs)
{
  memset(client[cs].buffer, 0, BUFF_SIZE);
  sprintf(client[cs].buffer, "plv %d %d\n",
	  client[cs].id, client[cs].drone->level);
  xsend(serveur->gcs, client[cs].buffer, strlen(client[cs].buffer), 0);
}

void		send_pfk(t_serv *serveur, t_client *client, int cs)
{
  memset(client[cs].buffer, 0, BUFF_SIZE);
  sprintf(client[cs].buffer, "pfk %d\n", client[cs].id);
  xsend(serveur->gcs, client[cs].buffer, strlen(client[cs].buffer), 0);
}

void		send_enw(t_serv *serveur, t_client * client, int cs, int i)
{
  memset(client[cs].buffer, 0, BUFF_SIZE);
  sprintf(client[cs].buffer, "enw %d %d %d %d\n", i, client[cs].id,
	  client[cs].drone->posx, client[cs].drone->posy);
  xsend(serveur->gcs, client[cs].buffer, strlen(client[cs].buffer), 0);
}

void		send_eht(t_serv *serveur, int i)
{
  char		tmp[BUFF_SIZE];

  memset(tmp, 0, BUFF_SIZE);
  sprintf(tmp, "eht %d\n", i);
  xsend(serveur->gcs, tmp, strlen(tmp), 0);
}

void		send_pdi(t_serv *serveur, t_client *client, int cs)
{
  memset(client[cs].buffer, 0, BUFF_SIZE);
  sprintf(client[cs].buffer, "pdi %d\n", client[cs].id);
  xsend(serveur->gcs, client[cs].buffer, strlen(client[cs].buffer), 0);
}
