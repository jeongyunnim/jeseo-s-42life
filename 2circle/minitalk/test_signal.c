#include <stdio.h>
#include <unistd.h>
#include <signal.h>

struct sigaction act_new;
struct sigaction act_old;

void sigint_handler(int signo)
{
	printf("Ctrl-C 키를 눌렀군요~!\n");
	printf("또 누르면 종료 됩니다.\n");
	signaction(SIGINT, &act_old, NULL);
}

int main(void)
{
	act_new.sa_handler = sigint_handler;
	while(1)
	{
		printf("running...\n");
		sleep(1);
	}
}
