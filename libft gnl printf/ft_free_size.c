
#include "ft_free.h"

int	ft_free_size(t_m_free *m_free)
{
	int	i;

	i = 0;
	if (m_free->list)
	{
		while (m_free->list->next)
		{
			i++;
			m_free->list = m_free->list->next;
		}
		i++;
	}
	return (i);
}
