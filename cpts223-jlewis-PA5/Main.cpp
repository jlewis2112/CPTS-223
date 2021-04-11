#include"Header.h"
int main(void)
{
	company comp = company(24);

	do {//ticks until complete all jobs
		comp.tick();
	} while (comp.queueempty() == false);

	return 0;
}