#include <thread>
#include "character.h"
#include "thread.h"

using namespace std;

int Battle::cbattle = 0;

//Construtor
Thread::Thread(std::thread th) : t(th){ }

//Destrutor
Thread::~Thread(){
	//Aguardando todas as threads terminarem
	if( t.joinable() ) {
		t.join();
		//std::cout << " is joinable() then join()\n";
	}
}

//Construtor
Battle::Battle(Character *c1, Character *c2){
	this->a = c1;
	this->b = c2;
	this->id = cbattle;
	cbattle++;
}

//Destrutor
Battle::~Battle(){ 
	this->a = NULL;
	this->b = NULL;
}

//Função de atribuição Character A
void Battle::setCharacterA(Character *x){
	this->a = x;
}

//Função de atribuição Character B
void Battle::setCharacterB(Character *x){
	this->b = x;
}

//Função que imprime os resultados finais da batalha
void Battle::getResults(int r){
	std::cout << "A batalha #"<< id <<" entre " << a->getName() << " e " << b->getName() << " terminou, e " << (a->isAlive() ? a->getName() : b->getName()) << " foi o VENCEDOR!"<<endl;
	std::cout << "\t - Nº rodadas: " << r << "\n\t - Vida restante de " << (a->isAlive() ? a->getName() : b->getName()) << " : " << (a->isAlive() ? a->getHP() : b->getHP()) << endl; 
}

//Sobrecarga do operador () para a realização da batalha
void Battle::operator() (){
	int round = 0;
	while(this->a->isAlive() && this->b->isAlive()){
		std::cout << "====== ROUND " << round << " ======" <<endl;
		//Atacando
		this->a->attack(*this->b);
		this->b->attack(*this->a);

		if(this->a->getHP() < 50)
			this->a->useHealthPotion();
		if(this->b->getHP() < 50)
			this->b->useHealthPotion();

		//incrementando a rodada
		round++;
	}

	getResults(round);
}