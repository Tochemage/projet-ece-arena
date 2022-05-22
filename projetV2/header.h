#ifndef HEADER_H_INCLUDED
#define HEADER_H_INCLUDED
#include <stdio.h>
#include <stdlib.h>
#include <allegro.h>
#include <time.h>

typedef struct carre
{
    int numx;
    int numy;
    int x;
    int y;
    int obstacle;
    int autrejoueur;
}t_carre;

typedef struct weapon
{
    float WEAP_attack;
    float accuracy;
    int sortilege;
}t_weapon;

typedef struct perso
{
    BITMAP*img[24];
    t_carre pospre;
    t_carre pos;
    int classe;
    char*nom;
    int deplacementx;
    int deplacementy;
    int deplacementxre;
    int deplacementyre;
    struct perso*suivant;
    int num;


/************ Character stats************/

    int PV_Base;
    int Stamina_Base;
    int Faith_Base;

    int PV;
    int Stamina;
    int Faith;

    float ATT_Multiplier_Base;
    float DEF_Multiplier_Base;

    float ATT_Multiplier;
    float DEF_Multiplier;

    t_weapon arme;
    int weapon_num;
}t_perso;


////////////////proto////////////////

void deplacementloop(BITMAP*doublebuffer,t_perso*ninja,t_carre plateau[12][12],int*tour,t_perso tabjoueur[4], int nbjoueurs);

t_perso*ajout(t_perso*oldlist,int num);

t_perso*saisi(int*nbjoueurs);

void InitAllegro();

BITMAP* recup_sprites( BITMAP*scr,int w,int h,int startx,int starty,int col,int element);

t_perso initperso();

void remptab(t_perso tab[4],int*nbjoueurs);

void deplacement(t_perso*seven, t_carre tab[12][12],int*tour,t_perso tabjoueur[4], int nbjoueurs);

void generationobstacles(t_carre tabb[12][12]);

void affichagepointer(BITMAP*doublebuffer,t_carre tab[12][12],BITMAP*pointer,t_perso*player);

void showmovement(t_perso* player,BITMAP* doublebuffer, BITMAP* canmove, t_carre tab[12][12]);


/************ Character stats setup ************/


void setTankStats(t_perso *character);
void setWizardStats(t_perso *character);
void setAssassinStats(t_perso *character);
void setSupportStats(t_perso *character);

void attackingprocess(t_perso*attacker, t_perso*defender);
int checkifnear(t_perso*attacker, t_perso*defender);

void setArc(t_weapon *arme);
void setKatana(t_weapon *arme);
void setBatonMagique(t_weapon *arme);
void setDague(t_weapon *arme);

int characterMenuScreen(t_perso *character, BITMAP *fondmenu[48]);

int weaponMenuScreen(t_perso *character, BITMAP *fondmenu[48]);

int characterSetupRoutine(t_perso *character, BITMAP *fondmenu[48]);

/************ Buttons ************/

int button_maker(int posX, int posY, BITMAP *confirm, BITMAP *buffer, int mouse_prev);
void initpartie(int nbjoueurs,t_perso ninja[4], t_carre plateau[12][12],int choixarme[4],BITMAP* assassin[24],BITMAP* mage[24],BITMAP* tank[24],BITMAP* archer[24]);





#endif // HEADER_H_INCLUDED
