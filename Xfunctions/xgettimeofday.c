/*
** xxgettimeofday.c for Xfunctions in /home/wang_c//Zappy/Xfunctions
** 
** Made by christophe wang
** Login   <wang_c@epitech.net>
** 
** Started on  Thu Jun  9 19:11:11 2011 christophe wang
** Last update Tue Jun 21 17:20:21 2011 christophe wang
*/

#include <sys/time.h>
#include <unistd.h>
#include <errno.h>
#include <stdio.h>
#include "serveur.h"

int		xgettimeofday(struct timeval *tv)
{
  int		i;

  i = 0;
  if ((i = gettimeofday(tv, NULL)) == -1)
    perror("Gettimeofday");
  return (i);
}
