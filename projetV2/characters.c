#include "header.h"

void setTankStats(t_perso *character)
{
    character->PV=150;
    character->Stamina=50;
    character->Faith=100;

    character->PV_Base=150;
    character->Stamina_Base=50;
    character->Faith_Base=100;

    character->ATT_Multiplier=1.10;
    character->DEF_Multiplier=0.70;

    character->ATT_Multiplier_Base=1.10;
    character->DEF_Multiplier_Base=0.70;
}

void setWizardStats(t_perso *character)
{
    character->PV=50;
    character->Stamina=100;
    character->Faith=150;

    character->PV_Base=50;
    character->Stamina_Base=100;
    character->Faith_Base=150;

    character->ATT_Multiplier=0.90;
    character->DEF_Multiplier=1.10;

    character->ATT_Multiplier_Base=0.90;
    character->DEF_Multiplier_Base=1.10;
}

void setAssassinStats(t_perso *character)
{
    character->PV=100;
    character->Stamina=150;
    character->Faith=50;

    character->PV_Base=100;
    character->Stamina_Base=150;
    character->Faith_Base=50;

    character->ATT_Multiplier=1.30;
    character->DEF_Multiplier=0.90;

    character->ATT_Multiplier_Base=1.30;
    character->DEF_Multiplier_Base=0.90;
}

void setSupportStats(t_perso *character)
{
    character->PV=100;
    character->Stamina=100;
    character->Faith=100;

    character->PV_Base=100;
    character->Stamina_Base=100;
    character->Faith_Base=100;

    character->ATT_Multiplier=1.30;
    character->DEF_Multiplier=0.90;

    character->ATT_Multiplier_Base=1.00;
    character->DEF_Multiplier_Base=1.00;
}

void characterMenuScreen(t_perso *character, BITMAP *fondmenu[48])
{
    int cmpt=0, imnum;
    BITMAP *buffer, *ninja, *tank;
    buffer=create_bitmap(SCREEN_W, SCREEN_H);

    ninja=load_bitmap("./image/big_characters/assassin.bmp", NULL);
    tank=load_bitmap("./image/big_characters/tank.bmp", NULL);
    if(ninja==NULL)
    {
        allegro_message("pas pu trouver ninja");
        exit(EXIT_FAILURE);
    }

    while(!key[KEY_ENTER])
    {
        blit(fondmenu[imnum], buffer, 0, 0, 0, 0, SCREEN_W, SCREEN_H);
        cmpt=(cmpt+1)%6;
        if(cmpt==0)
        {
            imnum=(imnum+1)%48;
        }
        masked_blit(ninja, buffer, 0,0,80,150, ninja->w, ninja->h);
        masked_blit(tank, buffer, 0,0,240,150, tank->w, tank->h);
        masked_blit(ninja, buffer, 0,0,400,150, ninja->w, ninja->h);
        masked_blit(ninja, buffer, 0,0,560,150, ninja->w, ninja->h);
        blit(buffer, screen, 0,0,0,0, SCREEN_W, SCREEN_H);
        rest(5);
    }

}
