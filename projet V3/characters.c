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
    character->Stamina=70;
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
    character->Stamina=90;
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
    character->Stamina=70;
    character->Faith=100;

    character->PV_Base=100;
    character->Stamina_Base=100;
    character->Faith_Base=100;

    character->ATT_Multiplier=1.30;
    character->DEF_Multiplier=0.90;

    character->ATT_Multiplier_Base=1.00;
    character->DEF_Multiplier_Base=1.00;
}