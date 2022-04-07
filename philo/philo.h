/* ************************************************************************** */
/*																			*/
/*														:::	  ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*													+:+ +:+		 +:+	 */
/*   By: naben-za <marvin@42.fr>					+#+  +:+	   +#+		*/
/*												+#+#+#+#+#+   +#+		   */
/*   Created: 2022/03/23 11:21:10 by naben-za		  #+#	#+#			 */
/*   Updated: 2022/03/30 19:09:01 by naben-za         ###   ########.fr       */
/*																			*/
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <string.h>
# include <sys/time.h>
# include <pthread.h>

typedef struct s_infos
{
	unsigned int		nb_philo;
	unsigned int		time_to_die;
	unsigned int		time_to_eat;
	unsigned int		time_to_sleep;
	unsigned int		nb_times_eat;
	int					six_args;
	long int			time_start;
	pthread_mutex_t		print;
	pthread_mutex_t		death;
	pthread_mutex_t		eat;
	int					dead;
	int					end_eat;
}				t_infos;

typedef struct s_philo
{
	int				philo_n;
	pthread_mutex_t	l_fork;
	pthread_mutex_t	*r_fork;
	long int		last_time_eat;
	t_infos			*infos;
	unsigned int	eat_counter;
	int				dead;
}					t_philo;

typedef struct s_check
{
	t_philo		*ph;
	t_infos		*infos;
}				t_check;

typedef struct s_args
{
	int		*tab;
	t_philo	*philo;
}				t_args;

void			args_nbr_error(void);
void			args_syntax_error(int ac);
void			allocation_error(void);
void			negativ_args(int *tab, int ac);
void			anti_lock_order(t_philo *ph);
int				ft_atoi(const char *nptr, int ac);
int				ft_isspace(int c);
void			init_t_args(int ac, char **arg, t_args *args);
void			*start(void *arg);
void			init_t_infos(t_infos *ithread, t_args *args, int ac);
long int		get_time(void);
long int		get_time_now(t_philo *info);
void			ft_usleep(long int time_in_ms);
void			ft_die(t_philo *ph);
void			ft_think(t_philo *ph);
void			ft_sleep(t_philo *ph);
void			ft_eat(t_philo *ph);
void			ft_fork(t_philo *ph);
void			init_t_philo(t_args *args, t_infos *info);
void			odd_without_six_arg(t_philo *ph);
void			odd_with_six_arg(t_philo *ph);
void			pair_without_six_arg(t_philo *ph);
void			pair_with_six_arg(t_philo *ph);
int				ft_check_death(t_check *ph);
void			*philo(void *arg);
void			*checker(void *arg);
void			launch_threads(t_args *args, t_infos *info, t_check *ch);
void			ft_death(t_check *ph);

#endif
