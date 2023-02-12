
#include "libft.h"

void	*ft_free_malloc(t_m_free *m_free, size_t size)
{
	void	*ptr;

	ptr = malloc(size);
	if (ptr == NULL)
		return (NULL);
	ft_free_add(m_free, ptr);
	return (ptr);
}