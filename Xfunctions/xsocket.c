/*
** xsocket.c for Xfunctions in /home/wang_c//Zappy/Xfunctions
** 
** Made by christophe wang
** Login   <wang_c@epitech.net>
** 
** Started on  Thu Jun  9 19:11:11 2011 christophe wang
** Last update Tue Jun 21 17:20:21 2011 christophe wang
*/

#include <errno.h>
#include <stdio.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <stdlib.h>
#include "serveur.h"

int		xsocket(int domain, int type, int protocol)
{
  int		s;

  if ((s = socket(domain, type, protocol)) == -1)
    {
      perror("Socket");
      exit(EXIT_FAILURE);
    }
  return (s);
}

