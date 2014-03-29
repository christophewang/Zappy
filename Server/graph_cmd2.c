/*
** graph_cmd2.c for graph_cmd2 in /home/wang_c//Desktop/Zappy_Final/Serveur
** 
** Made by christophe wang
** Login   <wang_c@epitech.net>
** 
** Started on  Sun Jul 10 20:20:52 2011 christophe wang
** Last update Sun Jul 10 20:21:24 2011 christophe wang
*/

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "serveur.h"

void		send_pnw(t_serv *serveur, t_client *client, int cs)
{
  if (client[cs].drone->id_egg)
    {
      memset(client[cs].buffer, 0, BUFF_SIZE);
      sprintf(client[cs].buffer, "ebo %d\n", client[cs].drone->id_egg);
      xsend(serveur->gcs, client[cs].buffer, strlen(client[cs].buffer), 0);
    }
  memset(client[cs].buffer, 0, BUFF_SIZE);
  sprintf(client[cs].buffer, "pnw %d %d %d %d %d %s\n", client[cs].id,
	  client[cs].drone->posx, client[cs].drone->posy,
	  client[cs].drone->direction + 1, client[cs].drone->level,
	  serveur->team[client[cs].team].name);
  xsend(serveur->gcs, client[cs].buffer, strlen(client[cs].buffer), 0);
}

void		send_ppo(t_serv *serveur, t_client *client, int cs)
{
  memset(client[cs].buffer, 0, BUFF_SIZE);
  sprintf(client[cs].buffer, "ppo %d %d %d %d\n", client[cs].id,
	  client[cs].drone->posx, client[cs].drone->posy,
	  client[cs].drone->direction + 1);
  xsend(serveur->gcs, client[cs].buffer, strlen(client[cs].buffer), 0);
}

void		send_pgt(t_serv *serveur, t_client *client, int cs, int res)
{
  memset(client[cs].buffer, 0, BUFF_SIZE);
  sprintf(client[cs].buffer, "pgt %d %d\n", client[cs].id, res);
  xsend(serveur->gcs, client[cs].buffer, strlen(client[cs].buffer), 0);
  send_pin(serveur, client, cs);
  send_bct(serveur, client[cs].drone->posx, client[cs].drone->posy);
}

void		send_pdr(t_serv *serveur, t_client *client, int cs, int res)
{
  memset(client[cs].buffer, 0, BUFF_SIZE);
  sprintf(client[cs].buffer, "pdr %d %d\n", client[cs].id, res);
  xsend(serveur->gcs, client[cs].buffer, strlen(client[cs].buffer), 0);
  send_pin(serveur, client, cs);
  send_bct(serveur, client[cs].drone->posx, client[cs].drone->posy);
}

void		send_pin(t_serv *serveur, t_client *client, int cs)
{
  memset(client[cs].buffer, 0, BUFF_SIZE);
  sprintf(client[cs].buffer, "pin %d %d %d %d %d %d %d %d %d %d\n",
	  client[cs].id, client[cs].drone->posx, client[cs].drone->posy,
	  client[cs].drone->nourriture, client[cs].drone->linemate,
	  client[cs].drone->deraumere, client[cs].drone->sibur,
	  client[cs].drone->mendiane, client[cs].drone->phiras,
	  client[cs].drone->thystame);
  xsend(serveur->gcs, client[cs].buffer, strlen(client[cs].buffer), 0);
}
