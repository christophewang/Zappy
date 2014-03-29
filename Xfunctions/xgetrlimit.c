/*
** xgetrlimit.c for Xfunctions in /home/wang_c//Zappy/Xfunctions
** 
** Made by christophe wang
** Login   <wang_c@epitech.net>
** 
** Started on  Thu Jun  9 19:11:11 2011 christophe wang
** Last update Tue Jun 21 17:20:21 2011 christophe wang
*/

#include <errno.h>
#include <stdio.h>
#include <sys/time.h>
#include <sys/resource.h>
#include <unistd.h>
#include "serveur.h"

int		xgetrlimit(int resource, struct rlimit *rlim)
{
  int		i;

  if ((i = getrlimit(resource, rlim)) == -1)
    {
      perror("Getrlimit");
      return (FD_SETSIZE);
    }
  return (rlim->rlim_cur);
}
