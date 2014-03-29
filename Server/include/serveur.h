/*
** serveur.h for serveur in /home/wang_c//Zappy/src_serveur
** 
** Made by christophe wang
** Login   <wang_c@epitech.net>
** 
** Started on  Thu Jun  9 19:25:38 2011 christophe wang
** Last update Sun Jul 10 22:41:29 2011 christophe wang
*/

#ifndef		__SERVEUR_H__
#define		__SERVEUR_H__

#define R "\033[1m\033[31m"
#define G "\033[1m\033[32m"
#define Y "\033[1m\033[33m"
#define B "\033[1m\033[34m"
#define P "\033[1m\033[35m"
#define C "\033[1m\033[36m"
#define W "\033[1m\033[37m"
#define D "\033[0m"

#define ZAPPY	"(¯`·._.·(¯`·._.· Zappy Serveur ·._.·´¯)·._.·´¯)\n"
#define USAGE	"Usage: ./zappy_serveur [-p port] [-x world_x] [-y world_y] [-c max_clients] [-t speed] -n team_name_1 team_name_2 ...\n"
#define	ERRNBTEAM "Error : you must create at least two teams\n"
#define ERRTEAMNAME "Error : each team name must be unique\n"
#define ERRSPEED "Error : the speed must be between 1 and 1000000\n"
#define ERRWORLD "Error : the world is too small\n"
#define ERRPORT "Warning : port is out of range, listening on default port 4242\n"
#define	ERRMAX	"Error: the maximum number of clients is reached\n"
#define	SERVMAX "%sLimite maximum de clients connectes atteinte%s\n"
#define	SIGC	"\nRéception du signal CTRL + C\n"
#define	SIGQ	"\nRéception du signal CTRL + \\\n"
#define	QUIT	"Déconnections des clients...\nFermeture du serveur\n"

#define	OK "ok\n"
#define KO "ko\n"
#define	INCANTATION "elevation en cours\n"
#define	LVLUP "niveau actuel : %d\n"
#define	INV "{nourriture %d,linemate %d,deraumere %d,sibur %d,mendiane %d,phiras %d,thystame %d}\n"
#define	BROADCAST "message %d,%s\n"
#define CONNECTION "%s--> Connection Client %d (%s : %d)%s\n"
#define DECONNECTION "%s--> Deconnection Client %d%s\n"
#define CODRONE "%s ** (%s) - Drone %d Status -> Actif (Pos Y:%d / Pos X:%d) **%s\n"
#define	DECOGHOST "%s ** (%s) - Drone %d Status -> Ghost **%s\n"
#define DEAD "%s ** (%s) - Drone %d Status -> Mort **%s\n"
#define COMMAND "%s (%ld:%ld) Client %d: %s%s"
#define PING "%s--> Ping Timeout Client %d%s\n"
#define	TIMEOUT "%s --> Timeout (%ld:%ld) <-- \n%s"
#define	EGG "%sPonte Oeuf (Pos Y:%d / Pos X:%d)\n%s"
#define	HATCH "%sEclosion Oeuf (Pos Y:%d / Pos X:%d)\n%s"
#define	MOVE "%s (%s) - Drone %d - Nouvelle Position (Pos Y:%d / Pos X:%d)\n%s"
#define	LE "%s (%s) - Drone %d - Regarde vers la Gauche\n%s"
#define	RI "%s (%s) - Drone %d - Regarde vers la Droite\n%s"
#define	LOOK "%s (%s) - Drone %d - Regarde au Sol\n%s"
#define	INVENTORY "%s (%s) - Drone %d - Regarde dans son Inventaire\n%s"
#define	EXPULSE "%s (%s) - Drone %d - Expulse (Pos Y:%d / Pos X:%d)\n%s"
#define UP "%s (%s) - Drone %d - S'eleve au niveau %d\n%s"
#define	WIN "%s ------------> L'Equipe (%s%s%s) a gagne la partie !! <------------\n%s"

#define	DEFAULT_MAXCLIENTS	1
#define	DEFAULT_PORT		4242
#define	DEFAULT_SPEED		100
#define	DEFAULT_WORLD		20
#define	MIN_PORT		1024
#define	MAX_PORT		65535
#define	MIN_SPEED		1
#define	MAX_SPEED		1000000
#define	BUFF_SIZE		12000
#define FD_FREE			0
#define	FD_SERVEUR		1
#define	FD_CLIENT		2
#define	INACTIVE		0
#define	ACTIVE			1
#define	GHOST			2
#define	NORTH			0
#define	EAST			1
#define	SOUTH			2
#define	WEST			3

#include <sys/time.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <sys/resource.h>
#include <netinet/in.h>
#include <unistd.h>

int			g_exit;

typedef			int(*fct)();

typedef struct		s_drone
{
  int			cs;
  int			posx;
  int			posy;
  int			level;
  int			id_egg;
  int			direction;
  int			status;
  int			nourriture;
  int			linemate;
  int			deraumere;
  int			sibur;
  int			mendiane;
  int			phiras;
  int			thystame;
}			t_drone;

typedef struct		s_egg
{
  int			state;
  int			posx;
  int			posy;
  int			team;
  int			father;
  long			hatch;
  struct timeval	hatchtime;
}			t_egg;

typedef	struct		s_cmd
{
  char			*cmd;
  int			(*ptr_func)();
}			t_cmd;

typedef struct		s_elev
{
  int			level;
  int			(*ptr_func)();
}			t_elev;

typedef struct		s_graph
{
  char			*cmd;
  void			(*ptr_func)();
}			t_graph;

typedef struct		s_team
{
  char			*name;
  int			max_clients;
  int			nb_clients;
  t_drone		*drone;
}			t_team;

typedef struct		s_view
{
  char			buffer[BUFF_SIZE];
  int			line;
  int			x;
  int			y;
  int			delta;
  int			max;
}			t_view;

typedef struct		s_client
{
  int			nb_read;
  char			buffer[BUFF_SIZE];
  char			request[10][BUFF_SIZE];
  int			len;
  int			id;
  int			level;
  int			team;
  int			teamflag;
  t_drone		*drone;
  int			id_drone;
  int			flag;
  long			timelaps;
  long			timelife;
  struct timeval	life;
  struct timeval	delay;
}			t_client;

typedef struct		s_case
{
  int			players;
  int			eggs;
  int			nourriture;
  int			linemate;
  int			deraumere;
  int			sibur;
  int			mendiane;
  int			phiras;
  int			thystame;
}			t_case;

typedef struct		s_serv
{
  int			sock;
  int			world_x;
  int			world_y;
  int			max_clients;
  int			speed;
  int			port;
  int			nb_team;
  struct timeval	time;
  struct timeval	timeout;
  t_team		*team;
  t_case		**map_case;
  int			max_eggs;
  int			nb_eggs;
  t_egg			*egg;
  int			limit;
  int			graphic_flag;
  int			gcs;
  char			fd_type[FD_SETSIZE];
  fct			fct_read[FD_SETSIZE];
  fct			fct_write[FD_SETSIZE];
}			t_serv;

/*
** Core Functions
*/

void			display_serveur(t_serv *);
int			init_serveur(t_serv *, char **);
void			init_world(t_serv *, char **);
int			init_team(t_serv *, char **);
void			free_serveur(t_serv *, t_client *);
void			free_tab(char **);
void			free_map(t_serv *);
void			start_serveur(t_serv *);
void			do_serveur(t_serv *);
void			quit_serveur(t_serv *, t_client *);
int			serveur_read(t_serv *, t_client *, int);
int			serveur_write(t_serv *, t_client *, int);
void			init_select(t_serv *, t_client *, fd_set *, fd_set *);
void			check_fd(t_serv *, t_client *, fd_set *, fd_set *);
int			do_connection(t_serv *, t_client *, int, int);
int			get_fdmax(t_serv *, fd_set *);
int			check_validteam(t_serv *, t_client *, int);
void			create_drones(t_serv *);
void			init_drones(t_serv *, int, int);
void			init_commandlist(t_client *, int);
long			timer_egg(t_serv *, long);
int			check_commandlist(t_serv *, t_client *, int);
int			check_graphlist(t_serv *, t_client *, int);
void			get_command(t_client *, int);
void			parse_command(t_serv *, t_client *, int);
void			delete_command(t_client *, int);
void			create_world(t_serv *);
void			check_signal(void);
void			check_timer(t_serv *, t_client *);
long			convert_usec(struct timeval);
int			connect_graphic(t_serv *, t_client *, int);
void			regen_food(t_serv *);
void			regen_ressources(t_serv *);
void			check_victory(t_serv *);
void			check_action(t_serv *, t_client *);
void			check_eggs(t_serv *);
void			hatching_eggs(t_serv *, int);
void			init_new_drones(t_serv *, int, int, int);
void			check_pingtimeout(t_serv *, t_client *, int);
void			check_life(t_serv *, t_client *, int);
void			set_timer(t_serv *, t_client *, int);
void			show_players(char *, t_serv *, int, int);
void			show_res(char *, t_serv *, int, int);
void			do_voir(t_serv*, t_client *, int);

/*
** Commands Functions
*/

int			avance(t_serv *, t_client *, int, char **);
int			droite(t_serv *, t_client *, int, char **);
int			gauche(t_serv *, t_client *, int, char **);
int			voir(t_serv *, t_client *, int, char **);
void			north_view(t_serv *, t_client *, int, t_view *);
void			east_view(t_serv *, t_client *, int, t_view *);
void			south_view(t_serv *, t_client *, int, t_view *);
void			west_view(t_serv *, t_client *, int, t_view *);
int			inventaire(t_serv *, t_client *, int, char **);
int			prend(t_serv *, t_client *, int, char **);
int			get_items(t_serv *, t_client *, int, char *);
void			get_nourriture(t_serv *, t_client *, int);
void			get_linemate(t_serv *, t_client *, int);
void			get_deraumere(t_serv *, t_client *, int);
void			get_sibur(t_serv *, t_client *, int);
void			get_mendiane(t_serv *, t_client *, int);
void			get_phiras(t_serv *, t_client *, int);
void			get_thystame(t_serv *, t_client *, int);
int			pose(t_serv *, t_client *, int, char **);
int			put_items(t_serv *, t_client *, int, char *);
void			put_nourriture(t_serv *, t_client *, int);
void			put_linemate(t_serv *, t_client *, int);
void			put_deraumere(t_serv *, t_client *, int);
void			put_sibur(t_serv *, t_client *, int);
void			put_mendiane(t_serv *, t_client *, int);
void			put_phiras(t_serv *, t_client *, int);
void			put_thystame(t_serv *, t_client *, int);
int			expulse(t_serv *, t_client *, int, char **);
void			check_drones(t_serv *, t_client *, int, int);
void			check_drone_north(t_client *, int, int, int);
void			check_drone_east(t_client *, int, int, int);
void			check_drone_south(t_client *, int, int, int);
void			check_drone_west(t_client *, int, int, int);
void			check_north(t_serv *, t_client *, int, int);
void			check_east(t_serv *, t_client *, int, int);
void			check_south(t_serv *, t_client *, int, int);
void			check_west(t_serv *, t_client *, int, int);
void			start_inc(t_serv *, t_client *, int, int);
void			send_incantation_msg(t_serv *, t_client *, int);
void			success(t_serv *, t_client *, int);
void			fail(t_serv *, t_client *, int);
void			lvl_up(t_serv *, t_client *, int, t_drone *);
void			fail_elevation(t_serv *, t_client *, int);
int			check_level(t_serv *, int, int, int);
int			incantation(t_serv *, t_client *, int, char **);
int			fork_cmd(t_serv *, t_client *, int, char **);
int			connect_nbr(t_serv *, t_client *, int, char **);
int			broadcast(t_serv *, t_client *, int, char **);
void			send_bcast(t_serv *, t_client *, int, char *);
int			check_pos(t_drone *, t_client *, int);
int			check_drone_dir1(t_drone *);
int			check_drone_dir2(t_drone *);
int			check_drone_dir3(t_drone *);
int			check_drone_dir4(t_drone *);
int			check_drone_dir5(t_drone *);
int			check_drone_dir6(t_drone *);
int			check_drone_dir7(t_drone *);
int			check_drone_dir8(t_drone *);

int			elevation1(t_serv *, t_client *, int);
int			elevation2(t_serv *, t_client *, int);
int			elevation3(t_serv *, t_client *, int);
int			elevation4(t_serv *, t_client *, int);
int			elevation5(t_serv *, t_client *, int);
int			elevation6(t_serv *, t_client *, int);
int			elevation7(t_serv *, t_client *, int);

/*
** Graphic Functions
*/

void			msz(t_serv *, t_client *, int);
void			sgt(t_serv *, t_client *, int);
void			bct(t_serv *, t_client *, int);
void			tna(t_serv *, t_client *, int);
void			pnw(t_serv *, t_client *, int);
void			enw(t_serv *, t_client *, int);
void			send_pnw(t_serv *, t_client *, int);
void			send_ppo(t_serv *, t_client *, int);
void			send_pgt(t_serv *, t_client *, int, int);
void			send_pdr(t_serv *, t_client *, int, int);
void			send_pic(t_serv *, t_client *, int, int);
void			send_pin(t_serv *, t_client *, int);
void			send_bct(t_serv *, int, int);
void			send_pex(t_serv *, t_client *, int);
void			send_pbc(t_serv *, t_client *, int, char *);
void			send_pie(t_serv *, t_client *, int, int);
void			send_plv(t_serv *, t_client *, int);
void			send_pfk(t_serv *, t_client *, int);
void			send_enw(t_serv *, t_client *, int, int);
void			send_eht(t_serv *, int);
void			send_pdi(t_serv *, t_client *, int);
void			send_seg(t_serv *, char *);
void			cmd_bct(t_serv *, t_client *, int, char **);
void			cmd_ppo(t_serv *, t_client *, int, char **);
void			cmd_plv(t_serv *, t_client *, int, char **);
void			cmd_pin(t_serv *, t_client *, int, char **);
void			cmd_sst(t_serv *, t_client *, int, char **);

/*
** Utils Functions
*/

char			**str_to_wordtab(char *, char *);

/*
** XFunctions
*/

int			xaccept(int, struct sockaddr *, socklen_t *);
int			xbind(int, struct sockaddr *, socklen_t);
int			xclose(int);
void			xfree(void *);
struct protoent		*xgetprotobyname(const char *);
int			xgetrlimit(int, struct rlimit *);
int			xlisten(int, int);
void			*xmalloc(size_t);
void			*xrealloc(void *, size_t);
int			xrecv(int, void *, int, unsigned int);
int			xselect(int, fd_set *, fd_set *, fd_set *, struct timeval *);
int			xsend(int, const void *, size_t, int);
int			xsocket(int, int, int);
int			xsetsockopt(int, int, int, void *, socklen_t);
void			*xsignal(int, void(*handler)());
int			xgettimeofday(struct timeval *);

#endif
