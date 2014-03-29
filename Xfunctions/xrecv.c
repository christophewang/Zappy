/*
** xrecv.c for Xfunctions in /home/wang_c//Zappy/Xfunctions
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

int		xrecv(int s, void *buf, int len, unsigned int flags)
{
  int		nb_read;

  nb_read = recv(s, buf, len, flags);
  if (nb_read == -1 && errno != EAGAIN && errno != EINTR)
    perror("Recv");
  return (nb_read);
}
