##
## Makefile for Makefile in /home/wang_c//Zappy
## 
## Made by christophe wang
## Login   <wang_c@epitech.net>
## 
## Started on  Thu Jun  9 19:12:07 2011 christophe wang
## Last update Sun Jul 10 21:23:31 2011 christophe wang
##

SERVERDIR		= ./Server/
CLIENTDIR		= ./Client/
XFUNCDIR		= ./Xfunctions/

SERVEUR_NAME		= zappy_server
SERVER_SRC		= $(SERVERDIR)serveur.c		\
			  $(SERVERDIR)init_world.c		\
			  $(SERVERDIR)init_team.c		\
			  $(SERVERDIR)init_serveur.c		\
			  $(SERVERDIR)display_serveur.c	\
			  $(SERVERDIR)start_serveur.c		\
			  $(SERVERDIR)free_serveur.c		\
			  $(SERVERDIR)manage_select.c		\
			  $(SERVERDIR)init_select.c		\
			  $(SERVERDIR)get_fdmax.c		\
			  $(SERVERDIR)manage_connection.c	\
			  $(SERVERDIR)manage_command.c		\
			  $(SERVERDIR)parse_command.c		\
			  $(SERVERDIR)manage_timer.c		\
			  $(SERVERDIR)manage_graphic.c		\
			  $(SERVERDIR)manage_eggs.c		\
			  $(SERVERDIR)broadcast.c		\
			  $(SERVERDIR)check_signal.c		\
			  $(SERVERDIR)check_view.c		\
			  $(SERVERDIR)quit_serveur.c		\
			  $(SERVERDIR)create_world.c		\
			  $(SERVERDIR)str_to_wordtab.c		\
			  $(SERVERDIR)move.c			\
			  $(SERVERDIR)view.c			\
			  $(SERVERDIR)items.c			\
			  $(SERVERDIR)expulse.c		\
			  $(SERVERDIR)check_drones.c		\
			  $(SERVERDIR)check_directions.c	\
			  $(SERVERDIR)check_action.c		\
			  $(SERVERDIR)check_victory.c		\
			  $(SERVERDIR)regen_ress.c		\
			  $(SERVERDIR)incantation_low.c	\
			  $(SERVERDIR)incantation_high.c	\
			  $(SERVERDIR)incantation_func.c	\
			  $(SERVERDIR)init_drones.c		\
			  $(SERVERDIR)get_ress.c		\
			  $(SERVERDIR)get_ress2.c		\
			  $(SERVERDIR)put_ress.c		\
			  $(SERVERDIR)put_ress2.c		\
			  $(SERVERDIR)fork.c			\
			  $(SERVERDIR)connect_nbr.c		\
			  $(SERVERDIR)incantation.c		\
			  $(SERVERDIR)graph_cmd.c		\
			  $(SERVERDIR)graph_cmd2.c		\
			  $(SERVERDIR)graph_cmd3.c		\
			  $(SERVERDIR)graph_cmd4.c		\
			  $(SERVERDIR)graph_cmd5.c		\
			  $(SERVERDIR)graph_cmd6.c		\
			  $(SERVERDIR)broadcast_dir.c		\
			  $(SERVERDIR)broadcast_dir2.c		\
			  $(XFUNCDIR)xaccept.c			\
			  $(XFUNCDIR)xbind.c			\
			  $(XFUNCDIR)xclose.c			\
			  $(XFUNCDIR)xfree.c			\
			  $(XFUNCDIR)xgetprotobyname.c		\
			  $(XFUNCDIR)xgetrlimit.c		\
			  $(XFUNCDIR)xlisten.c			\
			  $(XFUNCDIR)xmalloc.c			\
			  $(XFUNCDIR)xrealloc.c			\
			  $(XFUNCDIR)xrecv.c			\
			  $(XFUNCDIR)xselect.c			\
			  $(XFUNCDIR)xsend.c			\
			  $(XFUNCDIR)xsocket.c			\
			  $(XFUNCDIR)xsetsockopt.c		\
			  $(XFUNCDIR)xgettimeofday.c		\
			  $(XFUNCDIR)xsignal.c


SERVER_OBJS		= $(SERVER_SRC:.c=.o)


CLIENT_NAME		= zappy_client
CLIENT_SRC		= $(CLIENTDIR)Main.cpp		\
			  $(CLIENTDIR)Parser.cpp	\
			  $(CLIENTDIR)Client.cpp

CLIENT_OBJS		= $(CLIENT_SRC:.cpp=.o)

GCC			= gcc
CXX			= g++
INCLUDE			= -I$(SERVERDIR)include -I$(CLIENTDIR)include
CFLAGS			+= -W -Wall -ansi -pedantic
RM			= rm -rf

B			= \033[1;34m
N			= \033[00m
G			= \033[0;38;5;2m
R			= \033[31m

$(SERVER_NAME)		: $(SERVER_OBJS)
			  @$(GCC) -o $(SERVER_NAME) $(SERVER_OBJS) $(INCLUDE)

$(CLIENT_NAME)		: $(CLIENT_OBJS)
			  @$(CXX) -o $(CLIENT_NAME) $(CLIENT_OBJS) $(INCLUDE)

all			: $(SERVER_NAME)

.c.o			:
			  @$(CC) $(CFLAGS) -c $< -o $@ $(INCLUDE)
			  @echo -e "$(B) Compiling$(N) $@ ...$(G) OK !$(N)"

.cpp.o			:
			  @$(CXX) $(CFLAGS) -c $< -o $@ $(INCLUDE)
			  @echo -e "$(B) Compiling$(N) $@ ...$(G) OK !$(N)"

clean			:
			  @$(RM) $(SERVER_OBJS) $(CLIENT_OBJS) *~
			  @echo -e "$(R)Deleting$(N) $(SERVER_OBJS) ...$(G) OK !$(N)"
			  @echo -e "$(R)Deleting$(N) $(CLIENT_OBJS) ...$(G) OK !$(N)"
			  @echo -e "$(R)Deleting temp files$(N) ...$(G) OK !$(N)\n"

fclean			: clean
			  @$(RM) $(SERVER_NAME) $(CLIENT_NAME)
			  @echo -e "$(R)Deleting binary $(N)$(SERVER_NAME) ...$(G) OK !$(N)"
			  @echo -e "$(R)Deleting binary $(N)$(CLIENT_NAME) ...$(G) OK !$(N)"

re			: fclean all

.PHONY			: all clean fclean re