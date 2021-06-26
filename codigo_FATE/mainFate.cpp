/*
========= DESENVOLVEDORES =========

ANA PAULA BESSA MEDEIROS 
MATEUS XIMENES DE OLIVEIRA 
MATHEUS FERRAZ CAPUCHO 
PEDRO HENRIQUE BRIGAGÃO DE AVILA  
RENATO MASTEGUIM NETO 

*/


//g++ Fate.cpp Texto.cpp mainFate.cpp -o FATE_RPG.exe


#include <iostream>
#include <string>
#include <ctime>
#include <cstdlib>
#include <typeinfo>
#include "Fate.h"
#include "Texto.h"

using namespace std;

Personagem player_aux;
Personagem enemy_aux;
int vetor_enemy[7] = { 99, 99, 99, 99, 99, 99, 99 };


bool Hora_Da_Batalha(Personagem&, Personagem&);
void Distribuicao_Pontos(Personagem&);
void enemy_turn(Personagem&, Personagem&);
void random_enemies();

int main() {
	srand(time(NULL));

	Personagem* vetor_personagens[7];
	vetor_personagens[0] = new Archer();
	vetor_personagens[1] = new Rider();
	vetor_personagens[2] = new Saber();
	vetor_personagens[3] = new Lancer();
	vetor_personagens[4] = new Caster();
	vetor_personagens[5] = new Assassin();
	vetor_personagens[6] = new Berserker();
	Personagem p1;

	introducao();

	string nick;
	getline(cin, nick);
	p1.set_nick(nick);
	cout << "\nMuito bem, " << p1.nick << ". O Graal te considera merecedor de participar desse conflito, porem, voce nao estara sozinho.\n";
	cout << "Pronto para escolher a classe do seu servo?\n\n";
	system("pause");

	int clas = 99;
	string escolha;
	cout << "Escolha sua classe, sendo 0 = Archer, 1 = Rider, 2 = Saber, 3 = Lancer, 4 = Caster, 5 = Assassin, 6 = Berserker\n";
	cin >> escolha;


	while (((escolha[0] != '1' && escolha[0] != '2') && (escolha[0] != '3' && escolha[0] != '4') && (escolha[0] != '5' && escolha[0] != '6') && (escolha[0] != '0')) || (escolha[1]))
	{
		cout << "\nOpcao Invalida! Digite novemente sua classe\n\nEscolha sua classe, sendo 0 = Archer, 1 = Rider, 2 = Saber, 3 = Lancer, 4 = Caster, 5 = Assassin, 6 = Berserker\n" << endl;
		cin >> escolha;
	}

	if (escolha[0] == '0') {
		clas = 0;
		escolha_archer(nick);
	}
	else if (escolha[0] == '1') {
		clas = 1;
		escolha_rider(nick);
	}
	else if (escolha[0] == '2') {
		clas = 2;
		escolha_saber(nick);
	}
	else if (escolha[0] == '3') {
		clas = 3;
		escolha_lancer(nick);
	}
	else if (escolha[0] == '4') {
		clas = 4;
		escolha_caster(nick);
	}
	else if (escolha[0] == '5') {
		clas = 5;
		escolha_assassin(nick);
	}
	else if (escolha[0] == '6') {
		clas = 6;
		escolha_berserker(nick);
	}

	cout << "\nVoce selecinou a classe " << vetor_personagens[clas]->nomeClasse << endl;
	vetor_personagens[clas]->set_nick(nick);

	Distribuicao_Pontos(*vetor_personagens[clas]);

	//SISTEMA DE INIMIGOS ALEATORIOS
	vetor_enemy[0] = clas;
	random_enemies();

	cout << "\n";
	
	while (Hora_Da_Batalha(*vetor_personagens[clas], *vetor_personagens[vetor_enemy[1]]));
	cout << "\nXP adquirido: " << vetor_personagens[clas]->xprodada << endl;
	cout << "Seu nivel atual: " << vetor_personagens[clas]->get_nivel() << "\n\n";
	vetor_personagens[clas]->imprime_dados();
	cout << "\n";
	system("pause");
	player_aux = *vetor_personagens[clas];

	vetor_personagens[vetor_enemy[2]]->lvl_enemy(2);
	while (Hora_Da_Batalha(*vetor_personagens[clas], *vetor_personagens[vetor_enemy[2]]));
	cout << "\nXP adquirido: " << vetor_personagens[clas]->xprodada << endl;
	cout << "Seu nivel atual: " << vetor_personagens[clas]->get_nivel() << "\n\n";
	vetor_personagens[clas]->imprime_dados();
	cout << "\n";
	system("pause");
	player_aux = *vetor_personagens[clas];


	vetor_personagens[vetor_enemy[3]]->lvl_enemy(3);
	while (Hora_Da_Batalha(*vetor_personagens[clas], *vetor_personagens[vetor_enemy[3]]));
	cout << "\nXP adquirido: " << vetor_personagens[clas]->xprodada << endl;
	cout << "Seu nivel atual: " << vetor_personagens[clas]->get_nivel() << "\n\n";
	vetor_personagens[clas]->imprime_dados();
	cout << "\n";
	system("pause");
	player_aux = *vetor_personagens[clas];

	vetor_personagens[vetor_enemy[4]]->lvl_enemy(4);
	while (Hora_Da_Batalha(*vetor_personagens[clas], *vetor_personagens[vetor_enemy[4]]));
	cout << "\nXP adquirido: " << vetor_personagens[clas]->xprodada << endl;
	cout << "Seu nivel atual: " << vetor_personagens[clas]->get_nivel() << "\n\n";
	vetor_personagens[clas]->imprime_dados();
	cout << "\n";
	system("pause");
	player_aux = *vetor_personagens[clas];
	
	vetor_personagens[vetor_enemy[5]]->lvl_enemy(5);
	while (Hora_Da_Batalha(*vetor_personagens[clas], *vetor_personagens[vetor_enemy[5]]));
	cout << "\nXP adquirido: " << vetor_personagens[clas]->xprodada << endl;
	cout << "Seu nivel atual: " << vetor_personagens[clas]->get_nivel() << "\n\n";
	vetor_personagens[clas]->imprime_dados();
	cout << "\n";
	system("pause");
	player_aux = *vetor_personagens[clas];

	vetor_personagens[vetor_enemy[6]]->lvl_enemy(6);
	while (Hora_Da_Batalha(*vetor_personagens[clas], *vetor_personagens[vetor_enemy[6]]));
	cout << "\nXP adquirido: " << vetor_personagens[clas]->xprodada << endl;
	cout << "Seu nivel atual: " << vetor_personagens[clas]->get_nivel() << "\n\n";
	vetor_personagens[clas]->imprime_dados();
	cout << "\n";
	system("pause");
	player_aux = *vetor_personagens[clas];
	

	Personagem* finalboss[1];
	finalboss[0] = new Kirei();
	finalboss[0]->lvl_enemy(6);
	if (endgame(nick)) {
		cout << "\n ============ Fim de jogo ============ \n";
	}else{
		while (Hora_Da_Batalha(*vetor_personagens[clas], *finalboss[0]));
		cout << "\n ============ Fim de jogo ============ \n";
	}
	
	creditos();
	return 0;

}//end main

// =============== FUNCAO DISTRIBUICAO DE PONTOS ===============

void Distribuicao_Pontos(Personagem& player) {
	cout << "\n======= Distribuicao dos Pontos =======\n\n";
	cout << "Estes sao seus atributos atuais\n\n";
	loading(1000);
	player.imprime_dados();
	loading(1000);
	cout << "\nVoce possui 10 pontos para distribuir entre seus atributos!\n";
	cout << "Use os com muita sabedoria!!!\n";

	int pontos = 10, dist;

	cout << "Adicionar ao Ataque: ";
	cin >> dist;
	if (dist >= pontos) {
		dist = pontos;
	}
	pontos -= dist;
	player.set_ataque(dist);
	if (pontos > 0) {
		cout << "Restam " << pontos << " para voce distribuir\n";

		cout << "Adicionar a Defesa: ";
		cin >> dist;
		if (dist >= pontos) {
			dist = pontos;
		}
		pontos -= dist;
		player.set_defesa(dist);
		if (pontos > 0) {
			cout << "Restam " << pontos << " para voce distribuir\n";

			cout << "Adicionar a Agilidade: ";
			cin >> dist;
			if (dist >= pontos) {
				dist = pontos;
			}
			pontos -= dist;
			player.set_agilidade(dist);
			if (pontos > 0) {
				cout << "Restam " << pontos << " para voce distribuir\n";
				cout << "Adicionar ao Poder Magico: ";
				cin >> dist;
				if (dist >= pontos) {
					dist = pontos;
				}
				pontos -= dist;
				player.set_poder(dist);
				cout << "\nRestaram " << pontos << " pontos!\n";
			}
		}
	}
	player_aux = player;
	loading(1000);
	cout << "\nA distribuicao de pontos terminou. Estes sao seus novos atributos:\n\n";
	loading(2500);
	player.imprime_dados();
	loading(2000);
}

// =============== FUNCAO BATALHA  ===============

bool Hora_Da_Batalha(Personagem& player, Personagem& enemy) {
	enemy.set_nick(player.nick);
	enemy.textoBatalha();

	cout << "\nAtributos de seu inimigo : \n";
	enemy.imprime_dados();
	loading(1000);
	enemy_aux = enemy;
	cout << "\n======= HORA DA BATALHA ======= \n\n";
	loading(3000);

	while ((player.get_vida() > 0 && enemy.get_vida() > 0)) {

		cout << "\nTurno de " << player.nick << endl;
		cout << "Vida atual do seu servo: " << player.get_vida() << endl;
	inicio:
		string opcao;
		cout << "\n1 - Atacar\n";
		cout << "2 - Desviar (" << player.get_cdDesviar() << " turnos restantes)\n";
		cout << "3 - Ataque Especial (" << player.get_cdHabilidade() << " turnos restantes)\n";
		cout << "Qual acao a ser tomada: ";
		cin >> opcao;

		loading(1000);

		if (!opcao[1]) {
			switch (opcao[0]) {
			case '1':
				cout << player.nick << " ordenou de seu servo atacasse!\n";
				loading(1000);
				if (enemy.desviou == false) {
					enemy.receber_dano(player.ataque()); //calc
					cout << "\nVida do inimigo: " << enemy.get_vida() << "\n\n";
					loading(3000);
				}
				else {
					cout << "\nSem sucesso ...\n\n";
					player.calcularCDs();
					loading(2000);
				}
				break;

			case '2':
				cout << "\n" << player.nome << " faz movimentos rapidos. ";
				if (player.get_cdDesviar() == 0) {
					if(player.desviar())
						cout << "\nE desvia com sucesso!\n";
					else
						cout << "\nE se cansa facilmente...\n";
				}
				else {
					cout << "\nVoce esta muito cansado para isso...\n\n";
					player.calcularCDs();
					loading(2000);
				}
				break;

			case '3':

				if (player.get_cdHabilidade() == 0) {
					cout << player.nick << " ordenou de seu servo atacasse com seu Fantasma Nobre!\n\b";
					loading(1000);
					enemy.receber_dano(player.ataque_especial());
					cout << "\nVida do inimigo: " << enemy.get_vida() << "\n\n";
					loading(3000);
				}
				else {
					cout << "\nVoce esta muito cansado para isso ..." << "\n\n";
					player.calcularCDs();
					loading(2000);
				}
				break;

			default:
				cout << "\n Opcao invalida! Digite novamente: " << endl; cout << "\n";
				loading(2000);
				goto inicio;
				break;
			}
		}
		else
		{
			cout << " \nOpcao invalida! Digite novamente: " << endl; cout << "\n";
			loading(2000);
			goto inicio;
			break;
		}
		if (enemy.get_vida() > 0) {
			enemy_turn(player, enemy);
		}
	}
	int vidap_atual, vidae_atual;
	player.calcularCDs();
	player.calcularCDs();
	vidap_atual = player.get_vida();
	vidae_atual = enemy.get_vida();


	if (enemy.get_vida() > 0) { // inimigo ganha, continua no loop da batalha
		enemy = enemy_aux;
		player = player_aux;
		enemy.exp(15);
		player.exp(vidap_atual);

		return player.restart_battle();
	}

	else {
		enemy.textoFim();
		player = player_aux;
		player.exp(vidap_atual);
		return false;
	}
}

void random_enemies() {
	srand(time(NULL));
	int k = 1;
	while (k < 7)
	{
		int aux = (rand() % 7);
		for (int i = 0; i <= k; i++)
		{
			while (vetor_enemy[i] == aux)
			{
				aux = (rand() % 7);
				i = 0;
			}
		}
		vetor_enemy[k] = aux;
		k++;
	}
}

void enemy_turn(Personagem& player, Personagem& enemy) {
	int aux;
	
	cout << "\n--- TURNO DO INIMIGO ---" << endl;
	cout << "\nVida atual do inimigo: " << enemy.get_vida() << endl;
	loading(3000);
	aux = (rand() % 30);

	if (aux >= 0 && aux < 23)
		aux = 1;
	else if (aux >= 23 && aux < 27)
		aux = 2;
	else
		aux = 3;

	switch (aux) {
	case 1:
		cout << "\nInimigo atacou! ";
		loading(2000);
		if (player.desviou == false) {
			player.receber_dano(enemy.ataque());
			cout << "\nVida do seu servo: " << player.get_vida() <<"\n"<< endl;
			loading(2000);
		}
		else {
			cout << "\nSem sucesso ...\n\n";
			enemy.calcularCDs();
			loading(1000);
		}
		break;
	case 2:
		cout << "\n" << enemy.nome << " faz movimentos rapidos. ";
		loading(1000);
		if (enemy.get_cdDesviar() == 0) {
			enemy.desviar();
			cout << "\nE desvia com sucesso!\n";
			loading(1000);
		}
		else {
			cout << enemy.nome << " esta muito cansado para desviar ...\n";
			enemy.calcularCDs();
			loading(2000);
		}
		cout << "\nVida do seu servo: " << player.get_vida() << "\n" << endl;
		loading(3000);
		break;

	case 3:

		if (enemy.get_cdHabilidade() == 0) {
			cout << enemy.nome << " atacou com seu Fantasma Nobre!\n\n";
			loading(2000);
			player.receber_dano(enemy.ataque_especial());
			cout << "\nVida do seu servo: " << player.get_vida() <<"\n"<< endl;
			loading(3000);
		}
		else {
			cout << "\nO inimigo tenta atacar com o seu Fantasma Nobre, e falha miseravelmente..." << endl << endl;
			enemy.calcularCDs();
			loading(3000);
		}
		break;
	}

}
