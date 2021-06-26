/*
========= DESENVOLVEDORES =========

ANA PAULA BESSA MEDEIROS
MATEUS XIMENES DE OLIVEIRA
MATHEUS FERRAZ CAPUCHO
PEDRO HENRIQUE BRIGAGÃO DE AVILA
RENATO MASTEGUIM NETO

*/
#include <iostream>
#include <string>
#include <stdlib.h>
#include <ctime>
#include <cmath>
#include "Fate.h"
#include "Texto.h"

using namespace std;

//função para passar um tempo
void loading(int value) {
	int tempo = clock(); //começa a contar o tempo
	while (clock() - tempo < value); //value equivale ao tempo gasto em ms // MUDAR A DIVISAO DO TEMPO
	tempo = clock();
}

Personagem::Personagem() {
	vida = 100;
	atack = 50;
	defesa = 50;
	agilidade = 50;
	poder_magico = 50;
	nivel = 1;
	nome = " ";
}

void Personagem::imprime_dados() {
	cout << "Nome: " << get_nome() << endl;
	cout << "Vida: " << get_vida() << endl;
	cout << "Ataque: " << get_ataque() << endl;
	cout << "Defesa: " << get_defesa() << endl;
	cout << "Agilidade: " << get_agilidade() << endl;
	cout << "Poder Magico: " << get_poder() << endl;
	cout << "Nivel: " << get_nivel() << endl;
	barra_xp();
}
void Personagem::textoBatalha() {
	return;
}
void Personagem::textoFim() {
	return;
}

void Personagem::set_vida(int life) {
	vida = life;
}
void Personagem::set_ataque(int atk) {
	atack += atk;
}
void Personagem::set_defesa(int def) {
	defesa += def;
}
void Personagem::set_agilidade(int agi) {
	agilidade += agi;
}
void Personagem::set_poder(int pm) {
	poder_magico += pm;
}
void Personagem::set_nivel(int lvl) {
	nivel = lvl;
}
void Personagem::set_nome(string name) {
	nome = name;
}
void Personagem::set_nick(string name) {
	nick = name;
}
int Personagem::get_vida() {
	return vida;
}
int Personagem::get_ataque() {
	return atack;
}
int Personagem::get_defesa() {
	return defesa;
}
int Personagem::get_agilidade() {
	return agilidade;
}
int Personagem::get_poder() {
	return poder_magico;
}
int Personagem::get_nivel() {
	return nivel;
}
int Personagem::get_cdHabilidade() {
	return cdHabilidade;
}
int Personagem::get_cdDesviar() {
	return cdDesviar;
}
string Personagem::get_nome() {
	return nome;
}
int Personagem::get_exp() {
	return xp;
}
void Personagem::set_xprodada(int xpatual) {
	xprodada = xpatual;
}
//------------- CALCULO DOS ATAQUES / COMBATE ---------------
int Personagem::ataque() { // retorna o valor do dano de ataque
	int x;
	x = (get_ataque() / 5) * 3;
	calcularCDs();
	return x;
}
int Personagem::ataque_especial() { // retorna o valor do dano de ataque especial
	int x;
	x = ((1 + 2 * get_poder()) / 10) * 3;
	calcularCDs();
	cdHabilidade = 2;
	return x;
}
bool Personagem::desviar() { // retorna o true, se conseguir desviar
	int x, y;
	x = rand() % 10;
	y = (get_agilidade() / 10) + 1;
	calcularCDs();
	if (y > x)
	{
		cout << "\n" << nome << " vai desviar dos proximos 2 ataques ...\n";
		cdDesviar = 1;
		desviou = true;
		return true;
		loading(200);
	}
	else
	{
		//cout << "\nNada Acontece...\n";
		desviou = false;
		return false;
		loading(200);
	}
}
void Personagem::receber_dano(int atk) { // funcao para retirar a vida do personagem, tanto player quanto inimigo.
	vida -= (int)(atk - (double)(get_defesa() / 10) * 2.5);
	if (vida <= 0) {
		morrer();
	}
}
void Personagem::morrer() { // escopo
	cout << get_nome() << " morreu.\n";
}

void Personagem::calcularCDs() {
	if (cdDesviar > 0) {
		cdDesviar--;
	}
	else {
		desviou = false;
	}
	if (cdHabilidade > 0) {
		cdHabilidade--;
	}
}

bool Personagem::restart_battle() {
	int i;
	cout << "\nVoce foi subjulgado, mas nao desista ainda guerreiro! Recomecar batalha?\n";
	while (1) {
		cout << "1 - SIM\n2 - NAO\n\n";
		cin >> i;
		switch (i) {
		case 1:
			imprime_dados();
			return true;
			break;
		case 2:
			cout << "\nO jogo terminou, mais sorte da proxima!!!\n";
			cout << "\n ============ Fim de jogo ============ \n";
			exit(0);
			break;
		default:
			cout << "opcao invalida. Escolher novamente.\n\n";
		}
	}
}
//;
//------------ FIM = CALCULO DOS ATAQUES / COMBATE -------------

//------------ IMPLEMENTACAO XP / LEVEL UP -------------

void Personagem::exp(int vidap) {
	int xpant = xp;
	if (vidap > 0) {
		if (vidap >= 45)
			vidap = 45;
		xp += abs((vidap * 15) / 5);
	}
	else {
		xp += abs(vidap * 10 / 5);
	}
	set_xprodada(xp - xpant);
	level_up();
}

void Personagem::level_up() {
	int aux = (rand() % 4) + 3;
	if (xp > 99) {
		if (xp >= 100 && xp < 235 && nivel != 2) {
			nivel = 2;
			cout << "\n" << nome << " (" << nomeClasse << ") LEVEL UP!!!!!!\n\n";
			set_vida(vida + 2*aux);
			set_ataque(aux);
			set_defesa(aux);
			set_agilidade(aux/3);
			set_poder(aux);
		}
		if (xp >= 235 && xp < 370 && nivel != 3) {
			nivel = 3;
			cout << "\n" << nome << " (" << nomeClasse << ") LEVEL UP!!!!!!\n\n";
			set_vida(vida + 2 * aux);
			set_ataque(aux);
			set_defesa(aux);
			set_agilidade(aux / 3);
			set_poder(aux);
		}
		if (xp >= 370 && xp < 510 && nivel != 4) {
			nivel = 4;
			cout << "\n" << nome << " (" << nomeClasse << ") LEVEL UP!!!!!!\n\n";
			set_vida(vida + 2 * aux);
			set_ataque(aux);
			set_defesa(aux);
			set_agilidade(aux / 3);
			set_poder(aux);
		}
		if (xp >= 510 && xp < 645 && nivel != 5) {
			nivel = 5;
			cout << "\n" << nome << " (" << nomeClasse << ") LEVEL UP!!!!!!\n\n";
			set_vida(vida + 2 * aux);
			set_ataque(aux);
			set_defesa(aux);
			set_agilidade(aux / 3);
			set_poder(aux);
		}
		if (xp >= 645 && nivel != 6) {
			nivel = 6;
			cout << "\n" << nome << " (" << nomeClasse << ") LEVEL UP!!!!!!\n\n";
			set_vida(vida + 2 * aux);
			set_ataque(aux);
			set_defesa(aux);
			set_agilidade(aux / 3);
			set_poder(aux);
		}

	}
}

void Personagem::lvl_enemy(int i) {
	srand(time(NULL));
	int aux = (rand() % 4) + 4;
	set_vida(vida + (i - 1) * aux);
	set_ataque((i - 1) * aux);
	set_defesa((i - 1) * aux);
	set_agilidade((i - 1) * aux / 2);
	set_poder((i - 1) * aux);
	set_nivel(i);
	xp += (i - 1) * 135;
}

void Personagem::barra_xp() {
	if (xp < 100)
		cout << "Seu xp: " << xp << " / 100 (Lvl 2)" << endl;
	else if (xp >= 100 && xp < 235)
		cout << "Seu xp: " << xp << " / 235 (Lvl 3)" << endl;
	else if (xp >= 235 && xp < 370)
		cout << "Seu xp: " << xp << " / 370 (Lvl 4)" << endl;
	else if (xp >= 370 && xp < 510)
		cout << "Seu xp: " << xp << " / 510 (Lvl 5)" << endl;
	else if (xp >= 510 && xp < 645)
		cout << "Seu xp: " << xp << " / 645 (Lvl 6)" << endl;
	else if (xp >= 645)
		cout << "Lvl MAX\n";

}


/*------------- Implementações Assassin ---------------*/

Assassin::Assassin() : Personagem{} {
	vida -= 15;
	agilidade += 15;
	nomeClasse = "Assassin";
	nome = "Charles-Henri";
}

void Assassin::imprime_dados() {
	cout << "Classe Assassin" << endl;
	Personagem::imprime_dados();
}

void Assassin::textoBatalha() {
	batalha_assassin(Personagem::nick);
}

void Assassin::textoFim() {
	derrota_assassin();
}

/*------------- Implementações Archer ---------------*/

Archer::Archer() : Personagem{} {
	atack += 5;
	defesa -= 10;
	agilidade += 5;
	nomeClasse = "Archer";
	nome = "Napoleao Bonaparte";
}

void Archer::imprime_dados() {
	cout << "Classe Archer" << endl;
	Personagem::imprime_dados();
}
void Archer::textoBatalha() {
	batalha_archer();
}

void Archer::textoFim() {
	derrota_archer();
}

/*------------- Implementações Caster ---------------*/

Caster::Caster() : Personagem{} {
	atack -= 5;
	vida -= 5;
	defesa -= 5;
	poder_magico += 15;
	nomeClasse = "Caster";
	nome = "Anastasia Romanov";
}

void Caster::imprime_dados() {
	cout << "Classe Caster" << endl;
	Personagem::imprime_dados();
}
void Caster::textoBatalha() {
	batalha_caster();
}

void Caster::textoFim() {
	derrota_caster();
}

/*------------- Implementações Saber ---------------*/

Saber::Saber() : Personagem{} {
	atack += 10;
	poder_magico -= 10;
	nomeClasse = "Saber";
	nome = "Arthur Pendragon";
}

void Saber::imprime_dados() {
	cout << "Classe Saber" << endl;
	Personagem::imprime_dados();
}
void Saber::textoBatalha() {
	batalha_saber(Personagem::nick);
}

void Saber::textoFim() {
	derrota_saber();
}
/*------------- Implementações Lancer ---------------*/

Lancer::Lancer() : Personagem{} {
	poder_magico -= 10;
	defesa += 5;
	agilidade += 5;
	nomeClasse = "Lancer";
	nome = "Cu Chulainn";
}

void Lancer::imprime_dados() {
	cout << "Classe Lancer" << endl;
	Personagem::imprime_dados();
}

void Lancer::textoBatalha() {
	batalha_lancer();
}

void Lancer::textoFim() {
	derrota_lancer();
}

/*------------- Implementações Berserker ---------------*/

Berserker::Berserker() : Personagem{} {
	vida += 20;
	atack += 5;
	poder_magico -= 15;
	agilidade -= 10;
	nomeClasse = "Berserker";
	nome = "Florence Nightingale";
}

void Berserker::imprime_dados() {
	cout << "Classe Berserker" << endl;
	Personagem::imprime_dados();
}
void Berserker::textoBatalha() {
	batalha_berserker(Personagem::nick);
}

void Berserker::textoFim() {
	derrota_berserker();
}

/*-------------- Implementações Rider ----------------*/

Rider::Rider() : Personagem{} {
	vida -= 5;
	defesa += 5;
	agilidade += 10;
	poder_magico -= 10;
	nomeClasse = "Rider";
	nome = "Alexandre Magno";
}

void Rider::imprime_dados() {
	cout << "Classe Rider" << endl;
	Personagem::imprime_dados();
}
void Rider::textoBatalha() {
	batalha_rider();
}

void Rider::textoFim() {
	derrota_rider();
}

/*-------------- Implementações Kirei ----------------*/

Kirei::Kirei() : Personagem{} {
	vida += 30;
	atack += 5;
	defesa += 5;
	poder_magico += 5;
	nomeClasse = "Kirei";
	nome = "Kirei Kotomine";
	xp = 700;
	nivel = 6;
}

void Kirei::imprime_dados() {
	cout << "Classe Kirei" << endl;
	Personagem::imprime_dados();
}
void Kirei::textoBatalha() {
	batalha_kirei();
}

void Kirei::textoFim() {
	derrota_kirei();
}

