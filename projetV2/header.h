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
}t_perso;

////////////////proto////////////////

deplacementloop(BITMAP*doublebuffer,t_perso*ninja,t_carre plateau[8][8],int*tourx,int*toury);

t_perso*ajout(t_perso*oldlist,int num);

t_perso*saisi(int*nbjoueurs);

void InitAllegro();

t_perso initperso();

void remptab(t_perso tab[4],int*nbjoueurs);

void deplacement(t_perso*seven, t_carre tab[8][8],int*tourx,int*toury);

#endif // HEADER_H_INCLUDED
