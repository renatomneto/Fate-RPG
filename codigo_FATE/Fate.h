/*
========= DESENVOLVEDORES =========

ANA PAULA BESSA MEDEIROS
MATEUS XIMENES DE OLIVEIRA
MATHEUS FERRAZ CAPUCHO
PEDRO HENRIQUE BRIGAGÃO DE AVILA
RENATO MASTEGUIM NETO

*/
#ifndef FATE_H
#define FATE_H

#include <iostream>
#include <string>
#include <ctime>

using namespace std;

void loading(int value);

class  Personagem { //abstrata
protected:
    int vida;
    int atack;
    int defesa;
    int agilidade;
    int poder_magico;
    int nivel;


    int cdHabilidade = 0;
    int cdDesviar = 0;
    int xp = 0;

public:

    bool desviou = false; //fica true quando o personagem puder desviar. 
    string nomeClasse; //  Saber, Archer, Lancer, Caster, Assassin, Rider, Berserker  
    string nome;
    string nick;
    int xprodada = 0;
    Personagem();
    virtual ~Personagem() { }
    virtual void imprime_dados();
    virtual void set_vida(int); //funcao virtual 
    virtual void set_ataque(int); //funcao virtual
    virtual void set_defesa(int); //funcao virtual
    virtual void set_agilidade(int); //funcao virtual
    virtual void set_poder(int); //funcao virtual
    virtual void set_nivel(int); //funcao virtual
    virtual void set_nick(string);
    void set_nome(string);
    virtual void set_xprodada(int);


    virtual int get_vida(); //funcao virtual
    virtual int get_ataque();//funcao virtual
    virtual int get_defesa(); //funcao virtual
    virtual int get_agilidade(); //funcao virtual
    virtual int get_poder(); //funcao virtual
    virtual int get_nivel(); //funcao virtual
    virtual int get_cdHabilidade(); //funcao virtual
    virtual int get_cdDesviar(); //funcao virtual
    virtual string get_nome(); //funcao virtual
    virtual int get_exp();


    virtual int ataque();
    virtual int ataque_especial();
    virtual bool desviar();
    virtual void receber_dano(int);
    virtual void morrer();
    virtual void calcularCDs();
    virtual void level_up();
    virtual void exp(int);
    virtual void barra_xp();
    virtual bool restart_battle();
    virtual void lvl_enemy(int);

    virtual void textoBatalha();
    virtual void textoFim();

};

class Archer : public Personagem {

public:

    Archer();
    ~Archer() { }
    void imprime_dados();
    void textoBatalha();
    void textoFim();
};


class Caster : public Personagem {

public:
    Caster();
    ~Caster() { }
    void imprime_dados();
    void textoBatalha();
    void textoFim();
};

class Saber : public Personagem {

public:
    Saber();
    ~Saber() { }
    void imprime_dados();
    void textoBatalha();
    void textoFim();
};

class Assassin : public Personagem {

public:
    Assassin();
    ~Assassin() { }
    void imprime_dados();
    void textoBatalha();
    void textoFim();
};

class Rider : public Personagem {

public:
    Rider();
    ~Rider() { }
    void imprime_dados();
    void textoBatalha();
    void textoFim();
};

class Lancer : public Personagem {

public:
    Lancer();
    ~Lancer() { }
    void imprime_dados();
    void textoBatalha();
    void textoFim();
};

class Berserker : public Personagem {


public:
    Berserker();
    ~Berserker() { }
    void imprime_dados();
    void textoBatalha();
    void textoFim();

};


class Kirei : public Personagem {

public:
    Kirei();
    ~Kirei() { }
    void imprime_dados();
    void textoBatalha();
    void textoFim();

};

#endif //FATE.H  