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
}t_carre;

typedef struct perso
{
    BITMAP*img;
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

    int ATT_Multiplier_Base;
    int DEF_Multiplier_Base;

    int ATT_Multiplier;
    int DEF_Multiplier;

}t_perso;

////////////////proto////////////////

deplacementloop(BITMAP*doublebuffer,t_perso*ninja,t_carre plateau[8][8],int*tourx,int*toury);

t_perso*ajout(t_perso*oldlist,int num);

t_perso*saisi(int*nbjoueurs);

void InitAllegro();

t_perso initperso();

void remptab(t_perso tab[4],int*nbjoueurs);

void deplacement(t_perso*seven, t_carre tab[8][8],int*tourx,int*toury);


/************ Character stats setup ************/


void setTankStats(t_perso *character);
void setWizardStats(t_perso *character);
void setAssassinStats(t_perso *character);
void setSupportStats(t_perso *character);



#endif // HEADER_H_INCLUDED
