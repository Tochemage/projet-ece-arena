#include "header.h"

/*
chaque arme a un sort de predilection, il y a 3 autres sort basiques dispo pour tous


*/


void setKatana(t_weapon *arme)// sort tranchant en ligne droite
{
    arme->WEAP_attack=1.20;
    arme->accuracy=0.80;
    arme->sortilege=0;
}

void setArc(t_weapon *arme)// sort attaque a distance
{
    arme->WEAP_attack=0.80;
    arme->accuracy=0.95;
    arme->sortilege=1;
}

void setBatonMagique(t_weapon *arme)// sort regen
{
    arme->WEAP_attack=1.10;
    arme->accuracy=1;
    arme->sortilege=2;
}

void setDague(t_weapon *arme)// sort poison
{
    arme->WEAP_attack=1.10;
    arme->accuracy=1.05;
    arme->sortilege=3;
}
