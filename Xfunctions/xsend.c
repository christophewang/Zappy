/*
** xsend.c for Xfunctions in /home/wang_c//Zappy/Xfunctions
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
#include "serveur.h"

int		xsend(int s, const void *msg, size_t len, int f)
{
  int	       i;

  if ((i = send(s, msg, len, f | MSG_NOSIGNAL)) == -1 && errno != EINTR && errno != EBADF)
    fprintf(stderr, "Send error\n");
  return (i);
}
