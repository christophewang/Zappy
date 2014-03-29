/*
** manage_graphic.c for manage_graphic in /home/wang_c//Desktop/Zappy_Final
** 
** Made by christophe wang
** Login   <wang_c@epitech.net>
** 
** Started on  Sun Jul 10 15:15:40 2011 christophe wang
** Last update Sun Jul 10 20:24:38 2011 christophe wang
*/

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "serveur.h"

int		connect_graphic(t_serv *serveur, t_client *client, int cs)
{
  client[cs].timelaps = 0;
  serveur->graphic_flag++;
  serveur->gcs = cs;
  delete_command(client, cs);
  msz(serveur, client, cs);
  sgt(serveur, client, cs);
  bct(serveur, client, cs);
  tna(serveur, client, cs);
  pnw(serveur, client, cs);
  enw(serveur, client, cs);
  return (2);
}
