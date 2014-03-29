/*
** put_ress2.c for put_ress in /home/wang_c//Desktop/Zappy_Final
** 
** Made by christophe wang
** Login   <wang_c@epitech.net>
** 
** Started on  Sun Jul 10 19:35:14 2011 christophe wang
** Last update Sun Jul 10 19:36:17 2011 christophe wang
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "serveur.h"

void		put_mendiane(t_serv *serveur, t_client *client, int cs)
{
  int		x;
  int		y;

  x = client[cs].drone->posx;
  y = client[cs].drone->posy;
  serveur->map_case[y][x].mendiane++;
  client[cs].drone->mendiane--;
  if (serveur->graphic_flag)
    send_pdr(serveur, client, cs, 4);
}

void		put_phiras(t_serv *serveur, t_client *client, int cs)
{
  int		x;
  int		y;

  x = client[cs].drone->posx;
  y = client[cs].drone->posy;
  serveur->map_case[y][x].phiras++;
  client[cs].drone->phiras--;
  if (serveur->graphic_flag)
    send_pdr(serveur, client, cs, 5);
}

void		put_thystame(t_serv *serveur, t_client *client, int cs)
{
  int		x;
  int		y;

  x = client[cs].drone->posx;
  y = client[cs].drone->posy;
  serveur->map_case[y][x].thystame++;
  client[cs].drone->thystame--;
  if (serveur->graphic_flag)
    send_pdr(serveur, client, cs, 6);

}
