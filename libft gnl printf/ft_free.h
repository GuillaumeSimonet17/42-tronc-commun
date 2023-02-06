
#ifndef FT_FREE_H
# define FT_FREE_H

# include <stdlib.h>

typedef struct s_free
{
	void			*ptr;
	struct s_free	*next;
}	t_free;

typedef struct s_m_free
{
	struct s_free	*list;
}	t_m_free;

#endif