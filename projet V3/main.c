#include "header.h"



int main()
{
    InitAllegro();
    int i,j,cmpt;
    t_carre plateau[12][12];
    BITMAP*doublebuffer;
    BITMAP*obstacle;
    t_perso ninja[4];
    int tabale[2][5];
    int nbjoueurs=0;
    int tour=0;

    int numimage;
    int comptfond;
    char nomfichier[100];
    int inmenu=1;
    int songplaying=0;

    int ingame=0;
    int initplayer=0;
    int undermenu=0;

    srand(time(NULL));

    for(i=0;i<12;i++)
    {
        for(j=0;j<12;j++)
        {
            plateau[j][i].numx=j;
            plateau[j][i].numy=i;
            plateau[j][i].x=137+(j*48);
            plateau[j][i].y=37+(i*48);
            plateau[j][i].obstacle=0;
        }
    }

    generationobstacles(tabale,plateau);
    obstacle=create_bitmap(20,48);
    rectfill(obstacle,0,600,800,0,makecol(0,255,0));


    doublebuffer=create_bitmap(SCREEN_W,SCREEN_H);
    clear_bitmap(doublebuffer);

    BITMAP* fondmenu[48];
    BITMAP* playbutton[2];
    BITMAP*selectplayer[3];

    SAMPLE *menusong = load_wav("menusong.wav");
    if (!menusong)
    {
        allegro_message("error loading");
        exit(EXIT_FAILURE);
    }

    for (int i=0;i<48;i++)
    {
        sprintf(nomfichier,"image/menu/fondmenubmp/fond%d.bmp",i+1);

        fondmenu[i] = load_bitmap(nomfichier,NULL);
        if (!fondmenu[i]){
            allegro_message("pas pu trouver %s",nomfichier);
            exit(EXIT_FAILURE);
        }
    }
    playbutton[0]=load_bitmap("image/menu/button/playbutton.bmp",NULL);
    if (!playbutton[0]){
            allegro_message("pas pu trouver button play");
            exit(EXIT_FAILURE);
        }
    playbutton[1]=load_bitmap("image/menu/button/playbutton_onit.bmp",NULL);
    if (!playbutton[1]){
            allegro_message("pas pu trouver button play 2");
            exit(EXIT_FAILURE);
        }

    selectplayer[0]=load_bitmap("image/menu/selectplayer/player2.bmp",NULL);
    if (!selectplayer[0]){
            allegro_message("pas pu trouver player");
            exit(EXIT_FAILURE);
        }
    selectplayer[1]=load_bitmap("image/menu/selectplayer/player3.bmp",NULL);
    if (!selectplayer[1]){
            allegro_message("pas pu trouver player 3");
            exit(EXIT_FAILURE);
        }
    selectplayer[2]=load_bitmap("image/menu/selectplayer/player4.bmp",NULL);
    if (!selectplayer[2]){
            allegro_message("pas pu trouver player 4");
            exit(EXIT_FAILURE);
        }





    while(!key[KEY_ESC])
    {

        if(inmenu==1)
        {
            if(songplaying==0)
            {
                play_sample(menusong,255,123,1000,1);
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
                position_mouse(0,0);
            }

            blit(fondmenu[numimage],doublebuffer,0,0,0,0,SCREEN_W,SCREEN_H);

            if(undermenu==0)
            {
              draw_sprite(doublebuffer,playbutton[cmpt],290,230);
            }
            if(undermenu==1)
            {
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
                }
                else if(nbjoueurs==4)
                {
                    ninja[0].pos=plateau[0][6];
                    ninja[1].pos=plateau[6][0];
                    ninja[2].pos=plateau[11][5];
                    ninja[3].pos=plateau[5][11];
                }

                initplayer=1;
                position_mouse(0,0);

            }

            }


        if(ingame==1 && initplayer==1)
        {

                //deplacementloop(doublebuffer,&ninja[tour%nbjoueurs],plateau,&tour);
        clear_bitmap(doublebuffer);
        rectfill(doublebuffer,0,600,800,0,makecol(255,255,255));
        deplacementloop(doublebuffer,&ninja[tour%nbjoueurs],plateau,&tour);

                for(i=0;i<nbjoueurs;i++)
                {
                    draw_sprite(doublebuffer,ninja[i].img,ninja[i].pos.x-10,ninja[i].pos.y-25);
                }
                for(i=0;i<12;i++)
                {
                    for(j=0;j<12;j++)
                    {
                        if(plateau[i][j].obstacle==1)
                        {
                            draw_sprite(doublebuffer,obstacle,plateau[i][j].x-10,plateau[i][j].y-25);
                        }
                    }
                }
        }



        show_mouse(doublebuffer);
        blit(doublebuffer, screen, 0, 0, 0, 0, SCREEN_W, SCREEN_H);
        rest(5);
    }

    for(int i=0;i<48;i++)
    {
        destroy_bitmap(fondmenu[i]);
    }
    destroy_sample(menusong);

    allegro_exit();
    return 0;

}END_OF_MAIN();



