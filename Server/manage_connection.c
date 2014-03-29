/*
** manage_connection.c for manage_connection in /home/wang_c//Desktop/Zappy_Final
** 
** Made by christophe wang
** Login   <wang_c@epitech.net>
** 
** Started on  Sun Jul 10 15:15:27 2011 christophe wang
** Last update Sun Jul 10 20:07:12 2011 christophe wang
*/

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>
#include "serveur.h"

static void	init_ndrones(t_serv *serv, t_client *client, int cs, int n)
{
  client[cs].drone->nourriture = 10;
  client[cs].id_drone = n;
  client[cs].drone->cs = cs;
  client[cs].drone->direction = (rand() % 4);
  client[cs].drone->posx = (rand() % serv->world_x);
  client[cs].drone->posy = (rand() % serv->world_y);
  serv->map_case[client[cs].drone->posy][client[cs].drone->posx].players++;
  printf(CODRONE, P, serv->team[client[cs].team].name, n,
	 client[cs].drone->posy, client[cs].drone->posx, D);
}

static void	init_ghost_drones(t_serv *serv, t_client *client, int cs, int n)
{
  client[cs].id_drone = n;
  client[cs].drone->cs = cs;
  serv->map_case[client[cs].drone->posy][client[cs].drone->posx].players++;
  printf(CODRONE, P, serv->team[client[cs].team].name, n,
	 client[cs].drone->posy, client[cs].drone->posx, D);
}

void            connect_to_drone(t_serv *serv, t_client *client, int cs, int i)
{
  int           n;

  n = 0;
  srand(time(NULL));
  while (n <= serv->team[i].max_clients)
    {
      if (serv->team[i].drone[n].status == GHOST)
        {
          serv->team[i].drone[n].status = ACTIVE;
          client[cs].drone = &serv->team[i].drone[n];
          init_ghost_drones(serv, client, cs, n);
	  return ;
        }
      else if (serv->team[i].drone[n].status == INACTIVE)
        {
          serv->team[i].drone[n].status = ACTIVE;
          client[cs].drone = &serv->team[i].drone[n];
          init_ndrones(serv, client, cs, n);
          return ;
        }
      n++;
    }
}

int		do_connection(t_serv *serveur, t_client *client, int cs, int i)
{
  if (serveur->team[i].nb_clients - 1 >= 0)
    {
      client[cs].team = i;
      connect_to_drone(serveur, client, cs, i);
      client[cs].timelife = 1000000 *
	(client[cs].drone->nourriture * 126 / serveur->speed);
      client[cs].timelaps = 0;
      client[cs].flag = 0;
      xgettimeofday(&client[cs].life);
      delete_command(client, cs);
      memset(client[cs].buffer, 0, BUFF_SIZE);
      sprintf(client[cs].buffer, "%d\n%d %d\n",
	      --serveur->team[client[cs].team].nb_clients,
	      serveur->world_x, serveur->world_y);
      xsend(cs, client[cs].buffer, strlen(client[cs].buffer), 0);
      if (serveur->graphic_flag)
	send_pnw(serveur, client, cs);
      return (1);
    }
  xsend(cs, KO, strlen(KO), 0);
  return (-1);
}

int		check_validteam(t_serv *serveur, t_client *client, int cs)
{
  int			i;
  int			len;

  i = 0;
  len = strlen(client[cs].request[0]);
  if (client[cs].request[0][len - 1] != '\n')
    return (0);
  if (client[cs].request[0][len - 2] == '\r')
    client[cs].request[0][len - 2] = '\0';
  else
    client[cs].request[0][len - 1] = '\0';
  while (i < serveur->nb_team)
    {
      if (!strcmp(client[cs].request[0], serveur->team[i].name))
	return (do_connection(serveur, client, cs, i));
      i++;
    }
  if (!strcmp(client[cs].request[0], "GRAPHIC"))
    return (connect_graphic(serveur, client, cs));
  xsend(cs, KO, strlen(KO), 0);
  return (-1);
}
