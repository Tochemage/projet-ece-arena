#include "header.h"


void boucleDeJeu();
int main()
{
    InitAllegro();

    t_sauvegarde newPartie;
    int i,j,valeur=0,variable,variablebis;
    char nomfichier[100];
    t_carre plateau[12][12];
    BITMAP*doublebuffer;
    BITMAP*obstacle;


    srand(time(NULL));

    for(i=0; i<12; i++)
    {
        for(j=0; j<12; j++)
        {
            plateau[j][i].numx=j;
            plateau[j][i].numy=i;
            plateau[j][i].x=137+(j*48);
            plateau[j][i].y=37+(i*48);
            plateau[j][i].obstacle=0;
            plateau[j][i].autrejoueur=0;
        }
    }

    generationobstacles(plateau);
    obstacle=create_bitmap(20,48);
    rectfill(obstacle,0,600,800,0,makecol(0,255,0));

    /*
    t_perso joe;
    joe.classe=-1;
    joe.weapon_num=-1;
    */

    doublebuffer=create_bitmap(SCREEN_W,SCREEN_H);
    clear_bitmap(doublebuffer);

    BITMAP* fondmenu[48];
    /* BITMAP* playbutton[2];
     BITMAP* selectplayer[3];*/



    SAMPLE *menusong = load_wav("menusong.wav");
    if (!menusong)
    {
        allegro_message("error loading");
        exit(EXIT_FAILURE);
    }

    for (int i=0; i<48; i++)
    {
        sprintf(nomfichier,"image/menu/fondmenubmp/fond%d.bmp",i+1);

        fondmenu[i] = load_bitmap(nomfichier,NULL);
        if (!fondmenu[i])
        {
            allegro_message("pas pu trouver %s",nomfichier);
            exit(EXIT_FAILURE);
        }
    }
    /* playbutton[0]=load_bitmap("image/menu/button/playbutton.bmp",NULL);
     if (!playbutton[0])
     {
         allegro_message("pas pu trouver button play");
         exit(EXIT_FAILURE);
     }
     playbutton[1]=load_bitmap("image/menu/button/playbutton_onit.bmp",NULL);
     if (!playbutton[1])
     {
         allegro_message("pas pu trouver button play 2");
         exit(EXIT_FAILURE);
     }

     selectplayer[0]=load_bitmap("image/menu/selectplayer/player2.bmp",NULL);
     if (!selectplayer[0])
     {
         allegro_message("pas pu trouver player");
         exit(EXIT_FAILURE);
     }
     selectplayer[1]=load_bitmap("image/menu/selectplayer/player3.bmp",NULL);
     if (!selectplayer[1])
     {
         allegro_message("pas pu trouver player 3");
         exit(EXIT_FAILURE);
     }
     selectplayer[2]=load_bitmap("image/menu/selectplayer/player4.bmp",NULL);
     if (!selectplayer[2])
     {
         allegro_message("pas pu trouver player 4");
         exit(EXIT_FAILURE);
     }*/







    while(!key[KEY_ESC])
    {

        valeur=menuDeJeu(&newPartie);
        switch(valeur)
        {

        case 5:
            set_gfx_mode(GFX_AUTODETECT_WINDOWED,800,600,0,0);

            enable_hardware_cursor();
            show_os_cursor(MOUSE_CURSOR_ALLEGRO);
            select_mouse_cursor(MOUSE_CURSOR_ARROW);
            show_mouse(screen);
            variable = -12;
            variablebis= -15;

            variable = characterSetupRoutine(&(newPartie.tabjoueur[0]),fondmenu);

            variablebis = characterSetupRoutine(&(newPartie.tabjoueur[1]),fondmenu);

            if((variable==1)&& (variablebis==1))
            {
                boucleDeJeu(&doublebuffer,plateau,2,(newPartie.tabjoueur));
            }
            break;



        }

        /*
        switch(joe.classe)
        {
            case -1:
                printf("Joe is undefined with ");
                break;

            case 0:
                printf("Joe is ninja with ");
                break;

            case 1:
                printf("Joe is samurai with ");
                break;

            case 2:
                printf("Joe is wizard with ");
                break;

            case 3:
                printf("Joe is apprentice with ");
                break;
        }

        switch(joe.weapon_num)
        {
            case -1:
                printf("undefined\n");
                break;

            case 0:
                printf("katana\n");
                break;

            case 1:
                printf("dagger\n");
                break;

            case 2:
                printf("wand\n");
                break;

            case 3:
                printf("bow\n");
                break;
        }


        if(inmenu==1)
        {
            if(songplaying==0)
            {
                play_sample(menusong,200,123,1000,1);
                songplaying=1;
            }


            comptfond++;
            if(comptfond>5)
            {
                comptfond=0;
                numimage++;
            }
            if(numimage>47)
            {
                numimage=0;
            }
            if(mouse_x>307 && mouse_x<476 && mouse_y>241 && mouse_y<331 && undermenu==0)
            {
                cmpt=1;
            }
            else
            {
                cmpt=0;
            }
            if(cmpt==1 && mouse_b&1)
            {
                undermenu=1;
                //position_mouse(0,0);
            }

            blit(fondmenu[numimage],doublebuffer,0,0,0,0,SCREEN_W,SCREEN_H);

            if(undermenu==0)
            {
              draw_sprite(doublebuffer,playbutton[cmpt],290,230);
            }
            if(undermenu==1)
            {
                //characterSetupRoutine(&joe, fondmenu);


                undermenu=0;
                /
                draw_sprite(doublebuffer,selectplayer[0],290,230);
                draw_sprite(doublebuffer,selectplayer[1],290,350);
                draw_sprite(doublebuffer,selectplayer[2],290,470);
                if(mouse_x>350 && mouse_x<430 && mouse_y>240 && mouse_y<320 && mouse_b&1)
                {
                nbjoueurs=2;
                undermenu=2;
                }
                if(mouse_x>350 && mouse_x<430 && mouse_y>360 && mouse_y<440 && mouse_b&1)
                {
                nbjoueurs=3;
                undermenu=2;
                }
                if(mouse_x>350 && mouse_x<430 && mouse_y>480 && mouse_y<460 && mouse_b&1)
                {
                nbjoueurs=4;
                undermenu=2;
                }

            }
            if(undermenu==2)
            {
                inmenu=0;
                ingame=1;
            }




        }
        if(inmenu==0)
        {
            songplaying=0;
            stop_sample(menusong);
        }

        if(ingame==1)
        {

            if(initplayer==0)
            {
                for(int i=0;i<nbjoueurs;i++)
                {
                    ninja[i]=initperso();
                    ninja[i].num=i;
                }
                if(nbjoueurs==2)
                {
                    ninja[0].pos=plateau[0][6];
                    ninja[1].pos=plateau[11][5];
                }
                else if(nbjoueurs==3)
                {
                    ninja[0].pos=plateau[0][6];
                    ninja[1].pos=plateau[6][0];
                    ninja[2].pos=plateau[11][5];

                    ninja[1].classe=1;//test
                    ninja[2].classe=2;//test

                    ninja[0].arme.sortilege=0;//test
                    ninja[1].arme.sortilege=1;//test
                    ninja[2].arme.sortilege=2;
                }
                else if(nbjoueurs==4)
                {
                    ninja[0].pos=plateau[0][6];
                    ninja[1].pos=plateau[6][0];
                    ninja[2].pos=plateau[11][5];
                    ninja[3].pos=plateau[5][11];
                }


                for(int i=0;i<nbjoueurs;i++)
                {
                    for(int j=0;j<24;j++)
                    {
                        if(ninja[i].classe==0)
                        {
                           setSupportStats(&ninja[i]);
                        }
                        if(ninja[i].classe==1)
                        {
                            setTankStats((&ninja[i]));
                        }
                        if(ninja[i].classe==2)
                        {
                            setWizardStats(&ninja[i]);

                        }
                        if(ninja[i].classe==3)
                        {
                           setAssassinStats(&ninja[i]);
                        }
                    }
                }

                for(int i=0;i<nbjoueurs;i++)
                {
                    for(int j=0;j<24;j++)
                    {
                        if(choixarme==0)
                        {
                           setArc(&(ninja[i].arme));
                        }
                        if(choixarme==1)
                        {
                           setKatana(&(ninja[i].arme));
                        }
                        if(choixarme==2)
                        {
                           setBatonMagique(&(ninja[i].arme));
                        }
                        if(choixarme==3)
                        {
                           setDague(&(ninja[i].arme));
                        }
                    }
                    //choixarme++;
                }


                for(int i=0;i<nbjoueurs;i++)
                {
                    for(int j=0;j<24;j++)
                    {
                        if(ninja[i].arme.sortilege==0)
                        {
                           ninja[i].img[j]=tank[j];
                        }
                        if(ninja[i].arme.sortilege==1)
                        {
                           ninja[i].img[j]=archer[j];
                        }
                        if(ninja[i].arme.sortilege==2)
                        {
                           ninja[i].img[j]=mage[j];
                        }
                        if(ninja[i].arme.sortilege==3)
                        {
                           ninja[i].img[j]=assassin[j];
                        }
                    }
                }

                //initpartie(nbjoueurs,&ninja[4],plateau,choixarme[4],assassin,mage,tank,archer);
                initplayer=1;
                position_mouse(0,0);

            }

            }
            */



        for(int i=0; i<48; i++)
        {
            destroy_bitmap(fondmenu[i]);
        }

        destroy_sample(menusong);

        allegro_exit();
        return 0;

    }



}
END_OF_MAIN();

void boucleDeJeu(BITMAP*doublebuffer,t_carre plateau[12][12],int nbjoueurs,t_perso ninja[4])
{
    set_gfx_mode(GFX_AUTODETECT_WINDOWED,800,600,0,0);




    int i,j;
    int tour=0;
    int numimage;
    int comptfond;

    int inmenu=1;
    int songplaying=0;

    int action=1;
    int choixaction=1;
    //int choixarme[4]={0,0,0,0};

    int ingame=0;
    int initplayer=0;
    int undermenu=0;

    int persoimg[4]= {0,0,0,0};
    int persotmpimg[4]= {8,10,12,14};
    int imageperso[4]= {0,0,0,0};

    BITMAP* fondjeu;
    BITMAP* tree;
    BITMAP* cursor;
    BITMAP* fichearcher;
    BITMAP* ficheassassin;
    BITMAP* fichetank;
    BITMAP* fichemage;
    BITMAP* archer[24];
    BITMAP* mage[24];
    BITMAP* tank[24];
    BITMAP* assassin[24];
    BITMAP* layout;
    BITMAP* moveposs;
    BITMAP* choixcase;
    BITMAP* choix[7];

    tree=load_bitmap("image/images layout/tree.bmp",NULL);
    if (!tree)
    {
        allegro_message("pas pu trouver tree");
        exit(EXIT_FAILURE);
    }
    fondjeu=load_bitmap("image/images layout/grass.bmp",NULL);
    if (!fondjeu)
    {
        allegro_message("pas pu trouver fondjeu");
        exit(EXIT_FAILURE);
    }

    cursor=load_bitmap("image/images layout/cursor.bmp",NULL);
    if (!cursor)
    {
        allegro_message("pas pu trouver cursor");
        exit(EXIT_FAILURE);
    }
    moveposs=load_bitmap("image/images layout/moveposs.bmp",NULL);
    if (!moveposs)
    {
        allegro_message("pas pu trouver moveposs");
        exit(EXIT_FAILURE);
    }

    choixcase=load_bitmap("image/images layout/choixcase.bmp",NULL);
    if(!choixcase)
    {
        allegro_message("pas pu trouver fiche choix");
        exit(EXIT_FAILURE);
    }

    for(int i=0; i<7; i++)
    {
        choix[i]=recup_sprites(choixcase,36,36,2,0,6,i);
        if (!choix[i])
        {
            allegro_message("pas pu trouver choix[%d]",i);
            exit(EXIT_FAILURE);
        }
    }

    layout=load_bitmap("image/images layout/infos.bmp",NULL);
    if (!layout)
    {
        allegro_message("pas pu trouver layout infos");
        exit(EXIT_FAILURE);
    }

    fichearcher=load_bitmap("image/images perso/archer.bmp",NULL);
    if (!fichearcher)
    {
        allegro_message("pas pu trouver fiche archer");
        exit(EXIT_FAILURE);
    }
    for(int i=0; i<24; i++)
    {
        archer[i]=recup_sprites(fichearcher,50,50,0,0,4,i);
        if (!archer[i])
        {
            allegro_message("pas pu trouver archer[%d]",i);
            exit(EXIT_FAILURE);
        }
    }

    ficheassassin=load_bitmap("image/images perso/assassin.bmp",NULL);
    if (!ficheassassin)
    {
        allegro_message("pas pu trouver fiche assassin");
        exit(EXIT_FAILURE);
    }
    for(int i=0; i<24; i++)
    {
        assassin[i]=recup_sprites(ficheassassin,50,50,0,0,4,i);
        if (!assassin[i])
        {
            allegro_message("pas pu trouver assassin[%d]",i);
            exit(EXIT_FAILURE);
        }
    }

    fichemage=load_bitmap("image/images perso/mage.bmp",NULL);
    if (!fichemage)
    {
        allegro_message("pas pu trouver fiche mage");
        exit(EXIT_FAILURE);
    }
    for(int i=0; i<24; i++)
    {
        mage[i]=recup_sprites(fichemage,50,50,0,0,4,i);
        if (!mage[i])
        {
            allegro_message("pas pu trouver mage[%d]",i);
            exit(EXIT_FAILURE);
        }
    }

    fichetank=load_bitmap("image/images perso/tank.bmp",NULL);
    if (!fichetank)
    {
        allegro_message("pas pu trouver fiche tank");
        exit(EXIT_FAILURE);
    }
    for(int i=0; i<24; i++)
    {
        tank[i]=recup_sprites(fichetank,50,50,0,0,4,i);
        if (!tank[i])
        {
            allegro_message("pas pu trouver tank[%d]",i);
            exit(EXIT_FAILURE);
        }
    }


    if(ingame==1 && initplayer==1)
    {


        clear_bitmap(doublebuffer);
        //rectfill(doublebuffer,0,600,800,0,makecol(255,255,255));
        blit(fondjeu,doublebuffer,0,0,0,0,800,600);
        blit(layout,doublebuffer,0,0,10,12,95,580);
        blit(layout,doublebuffer,0,0,697,12,95,580);
        if(choixaction==0)
        {
            switch(ninja[tour%nbjoueurs].arme.sortilege)
            {
            case 0:
            {
                draw_sprite(doublebuffer,choix[0],725,100);
                break;
            }
            case 1:
            {
                draw_sprite(doublebuffer,choix[1],725,100);
                break;
            }
            case 2:
            {
                draw_sprite(doublebuffer,choix[2],725,100);
                break;
            }
            case 3:
            {
                draw_sprite(doublebuffer,choix[3],725,100);
                break;
            }
            }
            draw_sprite(doublebuffer,choix[6],725,146);
            draw_sprite(doublebuffer,choix[4],725,184);
            draw_sprite(doublebuffer,choix[5],725,230);
            if(mouse_x>725 && mouse_x<725+36 && mouse_y>100 && mouse_y<136 && mouse_b&1)
            {
                choixaction=2;
            }
            if(mouse_x>725 && mouse_x<725+36 && mouse_y>146 && mouse_y<146+36 && mouse_b&1)
            {
                choixaction=3;
            }
            if(mouse_x>725 && mouse_x<725+36 && mouse_y>184 && mouse_y<184+36 && mouse_b&1)
            {
                choixaction=1;
            }
            if(mouse_x>725 && mouse_x<725+36 && mouse_y>230 && mouse_y<230+36 && mouse_b&1)
            {
                choixaction=4;
            }

        }
        for(i=0; i<12; i++)
        {
            for(j=0; j<12; j++)
            {
                for(int k=0; k<nbjoueurs; k++)
                {
                    if(ninja[k].pos.numx==plateau[i][j].numx && ninja[k].pos.numy==plateau[i][j].numy)
                    {
                        plateau[i][j].autrejoueur=1;
                    }
                    else
                    {
                        plateau[i][j].autrejoueur=0;
                    }
                }
            }
        }


        if(choixaction==1)
        {
            deplacementloop(doublebuffer,&ninja[tour%nbjoueurs],plateau,&tour,ninja,nbjoueurs);
            affichagepointer(doublebuffer,plateau,cursor,&ninja[tour%nbjoueurs]);
            showmovement(&ninja[tour%nbjoueurs],doublebuffer,moveposs,plateau);

        }
        if(choixaction==2)
        {

            for(int i=0; i<nbjoueurs; i++)
            {
                attackingprocess(&ninja[tour%nbjoueurs],&ninja[i]);
            }
            choixaction=0;
            tour++;
        }
        if(choixaction==3)
        {
            //sort
            choixaction=0;
            tour++;
        }
        if(choixaction==4)
        {
            //ne rien faire
            choixaction=0;
            tour++;
        }


        for(i=0; i<nbjoueurs; i++)
        {
            persoimg[i]++;

            if (persoimg[i]>=persotmpimg[i])
            {
                persoimg[i]=0;
                imageperso[i]++;
            }
            if (imageperso[i]>=4)
            {
                imageperso[i]=0;
            }
            if(ninja[i].PV>0)
            {
                draw_sprite(doublebuffer,ninja[i].img[imageperso[i]],ninja[i].pos.x-25,ninja[i].pos.y-25);
            }


            draw_sprite(doublebuffer,ninja[tour%nbjoueurs].img[imageperso[tour%nbjoueurs]+4*action],30,50);
        }

        for(i=0; i<12; i++)
        {
            for(j=0; j<12; j++)
            {
                if(plateau[i][j].obstacle==1)
                {
                    draw_sprite(doublebuffer,tree,plateau[i][j].x-42,plateau[i][j].y-80);
                }
            }
        }
        //showmovement(&ninja[tour%nbjoueurs],doublebuffer,moveposs,plateau);
    }

    show_mouse(doublebuffer);
    blit(doublebuffer, screen, 0, 0, 0, 0, SCREEN_W, SCREEN_H);
    rest(5);

    destroy_bitmap(fichearcher);
    destroy_bitmap(fichemage);
    destroy_bitmap(fichetank);
    destroy_bitmap(ficheassassin);
    destroy_bitmap(tree);
    destroy_bitmap(fondjeu);
    for(int i=0; i<24; i++)
    {
        destroy_bitmap(archer[i]);
    }
    for(int i=0; i<24; i++)
    {
        destroy_bitmap(tank[i]);
    }
    for(int i=0; i<24; i++)
    {
        destroy_bitmap(mage[i]);
    }
    for(int i=0; i<24; i++)
    {
        destroy_bitmap(assassin[i]);
    }
}





