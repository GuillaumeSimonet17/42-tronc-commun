
#include "libft.h"

void	ft_free(t_m_free *m_free)
{
	t_free	*tmp;

	while (m_free->list)
	{
		tmp = m_free->list;
		m_free->list = m_free->list->next;
		if (tmp->ptr)
			free(tmp->ptr);
		free(tmp);
	}
	free(m_free);
}
