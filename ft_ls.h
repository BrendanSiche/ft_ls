/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsiche <bsiche@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/27 16:30:16 by bsiche            #+#    #+#             */
/*   Updated: 2018/03/03 05:13:32 by bsiche           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_LS_H
# define FT_LS_H
# include <dirent.h>
# include <sys/stat.h>
# include <stdlib.h>
# include "libft.h"
# include <grp.h>
# include <pwd.h>
# include <time.h>
# include <errno.h>
# include <sys/types.h>

typedef	struct	s_ls
{
	char	*permission;
	char	*name;
	char	*date;
	char	*size;
	char	*time;
	char	*symlink;
	char	*path;
	int		hardlink;
	char	*usrname;
	char	*group;
	int		timeswitch;
	char	*itoardlink;
	char	*spacing;
	long	epoch;
	long	block;
	char	done;
	char	*maj;
	char	*min;
	char	*error;
}				t_ls;

int		main(int argc, char **argv);
char	ft_type(mode_t c);
char	*ft_usrmode(mode_t mode);
t_ls	*ft_stat(char *buf, struct dirent *lu);
t_ls	*ft_stat2(t_ls *info, struct stat *tmp);
t_ls	*ft_stat3(t_ls *info, struct stat *tmp, char *str);
char	*ft_getusr(uid_t pw);
char	*ft_getgroup(uid_t gr);
int		ft_ismod(char *str);
char 	*ft_themmods(char *str);
int		ft_ls(char *loc, char *mod);
int		ft_printls(t_ls *dir, char *mod, int i);
int		ft_chckmode(char *str, int c);
void	ft_apply(t_ls *dir, char *mod, int a);
void	ft_cleantime(t_ls *dir);
void	ft_spacelink(t_ls *dir, int a);
void	ft_spacesize(t_ls *dir, int a);
void	ft_spacegroup(t_ls *dir, int a);
void	ft_spaceusr(t_ls *dir, int a);
void	ft_sizesort(t_lstcontainer *liste);
void	ft_lexico(t_lstcontainer *liste);
void	ft_timesort(t_lstcontainer *liste);
void	ft_rev(t_ls *dir, int i, int a);
int		ft_recur(t_ls *dir, char *mod);
t_ls	ft_test(char *str);
void	ft_cleanid(t_ls *dir, int a);
size_t	ft_getidlen(t_ls *dir, int i, int j);
int		ft_checkroot(char *str);
int		ft_printlong(t_lstcontainer *liste);
int		ft_hidden(t_lstcontainer *liste);
int		ft_keepdir(t_lstcontainer *liste);
int		ft_recursimple(t_lstcontainer *liste);
int		ft_ls2(char *loc);
int		ft_normal(t_lstcontainer *liste);
void 	ft_errordir(t_lstcontainer *liste);
int		ft_rmroot(t_lstcontainer *liste);
#endif