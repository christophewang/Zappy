/*
** manage_timer.c for manage_timer in /home/wang_c//Desktop/Zappy_Final
** 
** Made by christophe wang
** Login   <wang_c@epitech.net>
** 
** Started on  Sun Jul 10 15:16:11 2011 christophe wang
** Last update Sun Jul 10 20:14:46 2011 christophe wang
*/

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <time.h>
#include "serveur.h"

long	       	convert_usec(struct timeval time)
{
  long	       	value;

  value = time.tv_sec * 1000000;
  value = value + time.tv_usec;
  return (value);
}

void		check_pingtimeout(t_serv *serveur, t_client *client, int i)
{
  if (!client[i].timelaps && !client[i].teamflag)
    {
      serveur->fd_type[i] = FD_FREE;
      printf(PING, R, client[i].id, D);
      xsend(i, "Ping Timeout\n", strlen("Ping Timeout\n"), 0);
      xclose(i);
    }
}

void		check_life(t_serv *serv, t_client *client, int i)
{
  long			life_delay;

  life_delay = convert_usec(serv->time) - convert_usec(client[i].life);
  xgettimeofday(&client[i].life);
  client[i].timelife -= life_delay;
  client[i].drone->nourriture = (client[i].timelife * serv->speed) / 126000000;
  if (client[i].timelife <= 0)
    {
      serv->team[client[i].team].nb_clients++;
      serv->fd_type[i] = FD_FREE;
      client[i].drone->status = INACTIVE;
      serv->map_case[client[i].drone->posy][client[i].drone->posx].players--;
      printf(DEAD, P, serv->team[client[i].team].name, client[i].id_drone, D);
      xsend(i, "mort\n", strlen("mort\n"), 0);
      xclose(i);
      if (serv->graphic_flag)
	send_pdi(serv, client, i);
    }
}

void		set_timer(t_serv *serv, t_client *client, int i)
{
  long	       	delay;

  if (client[i].teamflag == 1)
    {
      client[i].drone = &serv->team[client[i].team].drone[client[i].id_drone];
      check_life(serv, client, i);
    }
  delay = convert_usec(serv->time) - convert_usec(client[i].delay);
  xgettimeofday(&client[i].delay);
  client[i].timelaps -= delay;
  if (client[i].timelaps < 0)
    client[i].timelaps = 0;
  check_pingtimeout(serv, client, i);
  if (!client[i].timelaps && client[i].teamflag == 1 && client[i].flag == 1)
    client[i].flag = 2;
}

void	       	check_timer(t_serv *serveur, t_client *client)
{
  int	       	i;

  i = 0;
  xgettimeofday(&serveur->time);
  check_eggs(serveur);
  while (i < serveur->limit)
    {
      if (serveur->fd_type[i] == FD_CLIENT)
	set_timer(serveur, client, i);
      i++;
    }
}
