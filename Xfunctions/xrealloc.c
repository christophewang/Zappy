/*
** xrealloc.c for Xfunctions in /home/wang_c//Zappy/Xfunctions
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
#include "serveur.h"

void		*xrealloc(void *ptr, size_t size)
{
  if ((ptr = realloc(ptr, size)) == NULL)
    {
      perror("Realloc");
      exit(EXIT_FAILURE);
    }
  return (ptr);
}
