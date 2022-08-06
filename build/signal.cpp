#include <iostream>
#include <csignal>

void hndlr(int sig)
{
	std::cout << "Signal " << sig << std::endl;
	exit(sig);
}

int main()
{
	std::signal(SIGINT, hndlr);
	while(true){}
	return 0;
}

