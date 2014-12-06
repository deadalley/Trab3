#ifndef H_THREAD
#define H_THREAD

#include <iostream>
#include <thread> //C++11 !!
#include "team.h"

//Classe que ficará responsável por gerneciar as threads
class Thread{
	private:
		std::thread &t;
	public:
		//Construtor
		Thread(std::thread th);
		//Destrutor
		~Thread();
};

//Classe que ficará responsável por gerenciar as batalhas
class Battle{
	private:
		static int cbattle;
		int id;
		Character *a;
		Character *b;
	public:
		//Construtor
		Battle(Character*, Character*);
		//Destrutor
		~Battle();
		//Setters
		void setCharacterA(Character*);
		void setCharacterB(Character*);
		//Getters
		void getResults(int);
		//Funções Auxiliares
		void operator () ();
};

#endif