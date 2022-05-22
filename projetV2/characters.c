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

int characterMenuScreen(t_perso *character, BITMAP *fondmenu[48])
{
    int cmpt=0, imnum, desc_num, desc_active=0, mouse_prev=1, status=0, back_status=0, return_status=0;
    BITMAP *buffer, *ninja, *tank, *wizard, *support, *desc[4], *confirm, *back;
    buffer=create_bitmap(SCREEN_W, SCREEN_H);

    ninja=load_bitmap("./image/big_characters/assassin.bmp", NULL);
    tank=load_bitmap("./image/big_characters/tank.bmp", NULL);
    wizard=load_bitmap("./image/big_characters/wizard.bmp", NULL);
    support=load_bitmap("./image/big_characters/support.bmp", NULL);
    desc[0]=load_bitmap("./image/big_characters/ninja_desc.bmp", NULL);
    desc[1]=load_bitmap("./image/big_characters/samurai_desc.bmp", NULL);
    desc[2]=load_bitmap("./image/big_characters/pretre_desc.bmp", NULL);
    desc[3]=load_bitmap("./image/big_characters/apprenti_desc.bmp", NULL);
    confirm=load_bitmap("./image/menu/button/confirm.bmp", NULL);
    back=load_bitmap("./image/menu/button/back.bmp", NULL);



    if(ninja==NULL || tank==NULL || wizard==NULL)
    {
        allegro_message("pas pu trouver un perso");
        exit(EXIT_FAILURE);
        //a;
    }

    while(!key[KEY_ENTER] && status==0)
    {
        blit(fondmenu[imnum], buffer, 0, 0, 0, 0, SCREEN_W, SCREEN_H);
        cmpt=(cmpt+1)%6;
        if(cmpt==0)
        {
            imnum=(imnum+1)%48;
        }

        if(desc_active==0)
        {
            masked_blit(ninja, buffer, 0,0,80,150, ninja->w, ninja->h);
            masked_blit(tank, buffer, 0,0,240,150, tank->w, tank->h);
            masked_blit(wizard, buffer, 0,0,400,150, ninja->w, ninja->h);
            masked_blit(support, buffer, 0,0,560,150, ninja->w, ninja->h);
        }


        if(desc_active==0 && mouse_y>150 && mouse_y<150+ninja->h)
        {
            if(mouse_x>100 && mouse_x<100-50+ninja->w)
            {
                rectfill(buffer,100,150, 100-50+ninja->w, 150+ninja->h, makeacol(200,200,200,150));

                if(mouse_prev==0 && mouse_b==1)
                {
                    desc_active=1;
                    desc_num=0;
                }
            }

            if(mouse_x>260 && mouse_x<260-50+ninja->w)
            {
                rectfill(buffer,260,150, 260-50+ninja->w, 150+ninja->h, makeacol(200,200,200,150));

                if(mouse_prev==0 && mouse_b==1)
                {
                    desc_active=1;
                    desc_num=1;
                }
            }

            if(mouse_x>420 && mouse_x<420-50+ninja->w)
            {
                rectfill(buffer,420,150, 420-50+ninja->w, 150+ninja->h, makeacol(200,200,200,150));

                if(mouse_prev==0 && mouse_b==1)
                {
                    desc_active=1;
                    desc_num=2;
                }
            }

            if(mouse_x>580 && mouse_x<580-50+ninja->w)
            {
                rectfill(buffer,580,150, 580-50+ninja->w, 150+ninja->h, makeacol(200,200,200,150));

                if(mouse_prev==0 && mouse_b==1)
                {
                    desc_active=1;
                    desc_num=3;
                }
            }
        }
        else if(desc_active==1)
        {
            masked_blit(desc[desc_num], buffer, 0,0,120,100,120+desc[desc_num]->w,100+desc[desc_num]->h);
            status=button_maker(640, 520, confirm, buffer, mouse_prev);


            /*
            if(mouse_prev==0 && mouse_b==2)
            {
                desc_active=0;
            }
            */
        }

        back_status=button_maker(140, 520, back, buffer, mouse_prev);

        if(back_status!=0)
        {
            if(desc_active==1)
            {
                desc_active=0;
                back_status=0;
            }
            else
            {
                status=2;
            }
        }

        blit(buffer, screen, 0,0,0,0, SCREEN_W, SCREEN_H);
        mouse_prev=mouse_b;
        rest(5);
    }
    if(status==1)
    {
        character->classe=desc_num;
        return_status=1;
    }
    //classe modifi� -> status 1, sinon 0
    return return_status;
}
