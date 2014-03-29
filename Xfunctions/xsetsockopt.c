/*
** xsetsockopt.c for Xfunctions in /home/wang_c//Zappy/Xfunctions
** 
** Made by christophe wang
** Login   <wang_c@epitech.net>
** 
** Started on  Thu Jun  9 19:11:11 2011 christophe wang
** Last update Tue Jun 21 17:20:21 2011 christophe wang
*/

#include <errno.h>
#include <stdlib.h>
#include <stdio.h>
#include <sys/types.h>
#include <sys/socket.h>
#include "serveur.h"

int		xsetsockopt(int sock, int l, int opt, void *v, socklen_t len)
{
  int		i;

  if ((i = setsockopt(sock, l, opt, v, len)) == -1)
    {
      perror("Setsockopt");
      exit(EXIT_FAILURE);
    }
  return (i);
}
