/*
** start_serveur.c for start_serveur in /home/wang_c//Desktop/Zappy_Final
** 
** Made by christophe wang
** Login   <wang_c@epitech.net>
** 
** Started on  Sun Jul 10 15:17:06 2011 christophe wang
** Last update Sun Jul 10 15:17:07 2011 christophe wang
*/

#include <netdb.h>
#include <string.h>
#include "serveur.h"

void			start_serveur(t_serv *serveur)
{
  struct protoent	*pe;
  struct sockaddr_in	sin;
  struct rlimit		rlim;
  int			on;

  on = 1;
  g_exit = 1;
  pe = xgetprotobyname("TCP");
  serveur->sock = xsocket(AF_INET, SOCK_STREAM, pe->p_proto);
  xsetsockopt(serveur->sock, SOL_SOCKET, SO_REUSEADDR, &on, sizeof(on));
  memset(&sin, 0, sizeof(sin));
  sin.sin_family = AF_INET;
  sin.sin_addr.s_addr = INADDR_ANY;
  sin.sin_port = htons(serveur->port);
  xbind(serveur->sock, (struct sockaddr *)&sin, sizeof(sin));
  xlisten(serveur->sock, SOMAXCONN);
  serveur->limit = xgetrlimit(RLIMIT_NOFILE, &rlim);
  memset(serveur->fd_type, FD_FREE, serveur->limit);
  serveur->fd_type[serveur->sock] = FD_SERVEUR;
  serveur->fct_read[serveur->sock] = serveur_read;
  serveur->fct_write[serveur->sock] = serveur_write;
  display_serveur(serveur);
  create_world(serveur);
  check_signal();
  do_serveur(serveur);
}
