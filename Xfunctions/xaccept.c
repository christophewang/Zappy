/*
** xaccept.c for Xfunctions in /home/wang_c//Zappy/Xfunctions
** 
** Made by christophe wang
** Login   <wang_c@epitech.net>
** 
** Started on  Thu Jun  9 19:11:11 2011 christophe wang
** Last update Tue Jun 21 17:20:21 2011 christophe wang
*/

#include <errno.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/socket.h>
#include "serveur.h"

int		xaccept(int sock, struct sockaddr *addr, socklen_t *len)
{
  int		i;

  if ((i = accept(sock, addr, len)) == -1)
    {
      if (errno != EMFILE)
	perror("Accept");
    }
  return (i);
}
