/*
========= DESENVOLVEDORES =========

ANA PAULA BESSA MEDEIROS
MATEUS XIMENES DE OLIVEIRA
MATHEUS FERRAZ CAPUCHO
PEDRO HENRIQUE BRIGAGÃO DE AVILA
RENATO MASTEGUIM NETO

*/
#ifndef TEXTO_H
#define TEXTO_H

#include <iostream>
#include <string>
#include <time.h>
#include "Fate.h"

void introducao();
void escolha_saber(string nome);
void escolha_archer(string nome);
void escolha_lancer(string nome);
void escolha_caster(string nome);
void escolha_rider(string nome);
void escolha_berserker(string nome);
void escolha_assassin(string nome);
void derrota_assassin();
void batalha_assassin(string nome);
void batalha_saber(string nome);
void derrota_saber();
void batalha_caster();
void derrota_caster();
void batalha_berserker(string nome);
void derrota_berserker();
void batalha_lancer();
void derrota_lancer();
void batalha_rider();
void derrota_rider();
void batalha_archer();
void derrota_archer();
bool endgame(string nome);
void derrota_kirei();
void batalha_kirei();
void creditos();
#endif
