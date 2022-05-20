#ifndef HEADER_H_INCLUDED
#define HEADER_H_INCLUDED
#include <allegro.h>
#include <winalleg.h>
#include  <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include <conio.h>
#define allocator(element, type) _allocator(element, sizeof(type))


typedef struct joueur
{
    char nom[50];
    int scorepv;

} t_joueur;

typedef struct sauvegarde
{

    int indexjEnTour;
    int nbDePartie ;
    int nbJoueurs;
    t_joueur tabjoueur[4];
} t_sauvegarde;

void menuDeJeu();
void MenuDesJoueurs(int w,int h,int nbDePartie);

void *_allocator(size_t element, size_t typeSize);
char *ajoutLettre( char *input, const char c);
void saisieLesNoms(int w,int h,int nbj, t_sauvegarde * partie,BITMAP* menuScreen );
void nomDeJoueurs(int w,int h,int nbDeJoueurs,t_sauvegarde * newPartie);
void Regles(int w,int h);

void initPartie(t_sauvegarde *PartieDeSauvegarde,int nbJoueurs/*,int nbDePartie*/);
void Changement(bool * variablebool);
void initAllegro();
#endif // HEADER_H_INCLUDED
