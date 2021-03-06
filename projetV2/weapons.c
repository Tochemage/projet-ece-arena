#include "header.h"

/*
chaque arme a un sort de predilection, il y a 3 autres sort basiques dispo pour tous

*/


void setKatana(t_weapon *arme)// sort tranchant en ligne droite
{
    arme->WEAP_attack=40;
    arme->accuracy=0.80;
    arme->sortilege=0;
}

void setArc(t_weapon *arme)// sort attaque a distance
{
    arme->WEAP_attack=27;
    arme->accuracy=0.95;
    arme->sortilege=1;
}

void setBatonMagique(t_weapon *arme)// sort regen
{
    arme->WEAP_attack=37;
    arme->accuracy=1;
    arme->sortilege=2;
}

void setDague(t_weapon *arme)// sort poison
{
    arme->WEAP_attack=37;
    arme->accuracy=1.05;
    arme->sortilege=3;
}

int weaponMenuScreen(t_perso *character, BITMAP *fondmenu[48])
{
    int cmpt=0, imnum, desc_num, desc_active=0, mouse_prev=1, status=0, back_status=0, return_status=0;
    BITMAP *buffer, *katana, *dagger, *wand, *bow, *desc[4], *confirm, *back;
    buffer=create_bitmap(SCREEN_W, SCREEN_H);

    katana=load_bitmap("./image/big_weapons/katana.bmp", NULL);
    dagger=load_bitmap("./image/big_weapons/dagger.bmp", NULL);
    wand=load_bitmap("./image/big_weapons/wand.bmp", NULL);
    bow=load_bitmap("./image/big_weapons/bow.bmp", NULL);
    desc[0]=load_bitmap("./image/big_weapons/katana_desc.bmp", NULL);
    desc[1]=load_bitmap("./image/big_weapons/dagger_desc.bmp", NULL);
    desc[2]=load_bitmap("./image/big_weapons/wand_desc.bmp", NULL);
    desc[3]=load_bitmap("./image/big_weapons/bow_desc.bmp", NULL);
    confirm=load_bitmap("./image/menu/button/confirm.bmp", NULL);
    back=load_bitmap("./image/menu/button/back.bmp", NULL);



    /*
    if(ninja==NULL || tank==NULL || wizard==NULL)
    {
        allegro_message("pas pu trouver un perso");
        exit(EXIT_FAILURE);
        //a;
    }
    */

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
            masked_blit(katana, buffer, 0,0,80,150, katana->w, katana->h);
            masked_blit(dagger, buffer, 0,0,240,150, dagger->w, dagger->h);
            masked_blit(wand, buffer, 0,0,400,150, wand->w, wand->h);
            masked_blit(bow, buffer, 0,0,560,150, bow->w, bow->h);
        }


        if(desc_active==0 && mouse_y>150 && mouse_y<150+katana->h)
        {
            if(mouse_x>100 && mouse_x<100-50+katana->w)
            {
                rectfill(buffer,100,150, 100-50+katana->w, 150+katana->h, makeacol(200,200,200,150));

                if(mouse_prev==0 && mouse_b==1)
                {
                    desc_active=1;
                    desc_num=0;
                }
            }

            if(mouse_x>260 && mouse_x<260-50+katana->w)
            {
                rectfill(buffer,260,150, 260-50+katana->w, 150+katana->h, makeacol(200,200,200,150));

                if(mouse_prev==0 && mouse_b==1)
                {
                    desc_active=1;
                    desc_num=1;
                }
            }

            if(mouse_x>420 && mouse_x<420-50+katana->w)
            {
                rectfill(buffer,420,150, 420-50+katana->w, 150+katana->h, makeacol(200,200,200,150));

                if(mouse_prev==0 && mouse_b==1)
                {
                    desc_active=1;
                    desc_num=2;
                }
            }

            if(mouse_x>580 && mouse_x<580-50+katana->w)
            {
                rectfill(buffer,580,150, 580-50+katana->w, 150+katana->h, makeacol(200,200,200,150));

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
        character->weapon_num=desc_num;
        return_status=1;
    }
    //classe modifi??? -> status 1, sinon 0
    return return_status;
}
