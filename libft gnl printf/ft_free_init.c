
#include "libft.h"

t_m_free	*ft_free_init(void)
{
	t_m_free	*m_free;

	m_free = (t_m_free *)malloc(sizeof(t_m_free));
	if (!m_free)
		return (NULL);
	m_free->list = NULL;
	return (m_free);
}