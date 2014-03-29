/*
** xfree.c for Xfunctions in /home/wang_c//Zappy/Xfunctions
** 
** Made by christophe wang
** Login   <wang_c@epitech.net>
** 
** Started on  Thu Jun  9 19:11:11 2011 christophe wang
** Last update Tue Jun 21 17:20:21 2011 christophe wang
*/

#include <stdlib.h>
#include "serveur.h"

void		xfree(void *ptr)
{
  if (ptr != NULL)
    free(ptr);
}
