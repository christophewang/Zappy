/*
** manage_select.c for manage_select in /home/wang_c//Desktop/Zappy_Final
** 
** Made by christophe wang
** Login   <wang_c@epitech.net>
** 
** Started on  Sun Jul 10 15:15:57 2011 christophe wang
** Last update Sun Jul 10 20:00:00 2011 christophe wang
*/

#include <arpa/inet.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <signal.h>
#include "serveur.h"

static int    		client_read(t_serv *serveur, t_client *client, int cs)
{
  xgettimeofday(&serveur->time);
  memset(client[cs].buffer, 0, BUFF_SIZE);
  client[cs].nb_read = xrecv(cs, client[cs].buffer, BUFF_SIZE, 0);
  if (client[cs].nb_read > 0)
    {
      get_command(client, cs);
      printf(COMMAND, C, serveur->time.tv_sec, serveur->time.tv_usec,
	     client[cs].id, client[cs].buffer, D);
    }
  return (cs);
}

static int    		client_write(t_serv *serv, t_client *client, int cs)
{
  if (!client[cs].teamflag && client[cs].nb_read > 0)
    client[cs].teamflag = check_validteam(serv, client, cs);
  if (client[cs].nb_read <= 0 || client[cs].teamflag == -1)
    {
      if (client[cs].nb_read <= 0 && client[cs].teamflag == 1)
	{
	  serv->team[client[cs].team].nb_clients++;
	  serv->map_case[client[cs].drone->posy][client[cs].drone->posx].players--;
	  client[cs].drone->status = GHOST;
	  printf(DECOGHOST, P, serv->team[client[cs].team].name,
		 client[cs].id_drone, D);
	  if (serv->graphic_flag)
	    send_pdi(serv, client, cs);
	}
      if (client[cs].teamflag == 2)
	serv->graphic_flag--;
      printf(DECONNECTION, R, client[cs].id, D);
      serv->fd_type[cs] = FD_FREE;
      xclose(cs);
    }
  return (0);
}

int		serveur_read(t_serv *serveur, t_client *client, int s)
{
  int			cs;
  static int		id = 0;
  struct sockaddr_in	addr;
  socklen_t		client_sin_len;

  client_sin_len = sizeof(addr);
  cs = xaccept(s, (struct sockaddr *)&addr, &client_sin_len);
  if (cs < serveur->limit && cs != -1)
    {
      client[cs].id = ++id;
      serveur->fd_type[cs] = FD_CLIENT;
      serveur->fct_read[cs] = client_read;
      xgettimeofday(&client[cs].delay);
      printf(CONNECTION, G, client[cs].id, inet_ntoa(addr.sin_addr),
	     ntohs(addr.sin_port), D);
    }
  else
    {
      printf(SERVMAX, R, D);
      xsend(cs, ERRMAX, strlen(ERRMAX), 0);
    }
  return (cs);
}

int		serveur_write(t_serv *serveur, t_client *client, int cs)
{
  if (cs < serveur->limit && cs != -1)
    {
      client[cs].teamflag = 0;
      client[cs].timelife = 0;
      client[cs].timelaps = 10000000;
      client[cs].len = 0;
      init_commandlist(client, cs);
      serveur->fct_write[cs] = client_write;
      xsend(cs, "BIENVENUE\n", strlen("BIENVENUE\n"), 0);
    }
  return (0);
}

void		do_serveur(t_serv *serveur)
{
  fd_set		fd_read;
  fd_set		fd_write;
  t_client		*client;

  client = xmalloc(sizeof(*client) * serveur->limit + 1);
  while (g_exit)
    {
      init_select(serveur, client, &fd_read, &fd_write);
      if ((xselect(get_fdmax(serveur, &fd_read) + 1, &fd_read, &fd_write, NULL,
		   (serveur->timeout.tv_sec || serveur->timeout.tv_usec) ?
		   &serveur->timeout : NULL)) != -1)
	{
	  check_fd(serveur, client, &fd_read, &fd_write);
	  check_timer(serveur, client);
	  check_action(serveur, client);
	  check_victory(serveur);
	}
    }
  quit_serveur(serveur, client);
}
