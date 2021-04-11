#include"Header.h"

int main(void)
{
	company comp = company(6);
	fstream file;
	file.open("Jobs.txt");
	do//ticks until done getting input
	{
		comp.tickFromFile(&file);
	} while (!file.eof());
	comp.tickFromFile(&file);//ticks until complete

	return 0;
}