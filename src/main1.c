#include "../minishell.h"

char	*redirect_test(void)
{
	// >INF
	open("111", O_WRONLY | O_CREAT | O_TRUNC, 0644);
	// |>>|
	open("222", O_WRONLY | O_CREAT | O_APPEND, 0644);	
	// |<|
	open("333", O_RDONLY, 0644);
	return ("WOW\n");
}

int main()
{

	redirect_test(); 
//	printf("MAKE\n");
}
