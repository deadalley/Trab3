#ifndef H_THREAD
#define H_THREAD

#include <thread> //C++11 !!
#include "team.h"

class Thread{
	private:
		int static count;
		int id;
		thread &t;
	public:
		//Construtor
		Thread();
		//Destrutor
		~Thread();
};

void battle(Character &a, Character &b);

void parallel_battle(Team &a, Team &b);

#endif