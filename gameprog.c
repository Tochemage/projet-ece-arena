#include "header.h"


deplacementloop(BITMAP*doublebuffer,t_perso*ninja,t_carre plateau[8][8],int*tourx,int*toury)
{
    int i,j;
    for(i=0;i<8;i++)
        {
            for(j=0;j<8;j++)
            {
                rect(doublebuffer,plateau[j][i].x-37,plateau[j][i].y+37,plateau[j][i].x+37,plateau[j][i].y-37,makecol(0,0,0));
            }
        }

        deplacement(ninja,*plateau,*tourx,*toury);
}

t_perso*ajout(t_perso*oldlist,int num)
{
    t_perso*newlist=(t_perso*)malloc(sizeof(t_perso));
    newlist->num=num;
    newlist->suivant=oldlist;
    return newlist;
}

t_perso*saisi(int*nbjoueurs)
{
    t_perso*tabjoueur;
    int i;
    tabjoueur=(t_perso*)malloc(sizeof(t_perso)/**(*nbjoueurs)*/);
    tabjoueur=NULL;

    for(i=*nbjoueurs;i>0;i--)
    {
        tabjoueur=ajout(tabjoueur,i);
    }
    tabjoueur->deplacementx=-24;
    tabjoueur->deplacementy=-24;
    tabjoueur->classe=0;
    tabjoueur->img=create_bitmap(37,70);
    rectfill(tabjoueur->img,0,600,800,0,makecol(255,0,0));
    tabjoueur->deplacementx=-24;
    tabjoueur->deplacementy=-24;
    return tabjoueur;
}

void InitAllegro()
{
    allegro_init();
    set_color_depth(desktop_color_depth());
    if((set_gfx_mode(GFX_AUTODETECT_WINDOWED,800,600,0,0))!=0)
    {
        allegro_message("Pb de mode graphique") ;
        allegro_exit();
        exit(EXIT_FAILURE);
    }
    install_keyboard();
	install_mouse();
	show_mouse(screen);
	install_sound(DIGI_AUTODETECT, MIDI_AUTODETECT, 0);
}

t_perso initperso()
{
    t_perso ran;
    ran.classe=0;
    ran.img=create_bitmap(37,70);
    rectfill(ran.img,0,600,800,0,makecol(255,0,0));
    ran.deplacementx=-24;
    ran.deplacementy=-24;
    return ran;
}

void remptab(t_perso tab[4],int*nbjoueurs)
{
    int i;
    printf("saisir nombre joueurs: ");
    fflush(stdin);
    do{
        scanf("%d", nbjoueurs);
    }while(*nbjoueurs<2 && *nbjoueurs>4);
    for(i=0;i<(*nbjoueurs);i++)
    {
        tab[i]=initperso();
    }
}

void deplacement(t_perso*seven, t_carre tab[8][8],int*tourx,int*toury)
{
    int i,j,cmpt=0;
    if(mouse_b&1 && seven->deplacementx==(-24) && seven->deplacementy==(-24))
    {
        for(j=0;j<8;j++)
        {
            for(i=0;i<8;i++)
            {
                if((mouse_x-tab[i][j].x)<37 && (mouse_x-tab[i][j].x)>(-37) && (mouse_y-tab[i][j].y)<37 && (mouse_y-tab[i][j].y)>(-37) && tab[i][j].obstacle==0)
                {
                    seven->deplacementx=i;
                    seven->deplacementy=j;
                }
            }

        }
    }

    if(seven->deplacementy!=(-24) || seven->deplacementx!=(-24))
        {
            seven->pospre=seven->pos;
            sleep(1);
        }


    if(seven->deplacementx!=(-24))
    {
        if(seven->pos.numx<seven->deplacementx)
        {
            seven->pos=tab[seven->pos.numx +1][seven->pos.numy];
        }
        else if(seven->pos.numx>seven->deplacementx)
        {
            seven->pos=tab[seven->pos.numx -1][seven->pos.numy];
        }
        else
        {
            seven->deplacementxre=seven->deplacementx;
            seven->deplacementx=(-24);
            *tourx=1;
        }
    }
    if(seven->deplacementy!=(-24))
    {
        if(seven->pos.numy<seven->deplacementy)
        {
            seven->pos=tab[seven->pos.numx][seven->pos.numy +1];
        }
        else if(seven->pos.numy>seven->deplacementy)
        {
            seven->pos=tab[seven->pos.numx][seven->pos.numy -1];
        }
        else
        {
            seven->deplacementyre=seven->deplacementy;
            seven->deplacementy=(-24);
            *toury=1;
        }
    }

    cmpt=0;

    if(seven->pos.obstacle==1)
    {
        if(seven->deplacementx==(-24))
        {
            seven->deplacementx=seven->deplacementxre;
        }
        if(seven->deplacementy==(-24))
        {
            seven->deplacementy=seven->deplacementyre;
        }
        if(seven->pospre.numx<seven->pos.numx && seven->pospre.numy<seven->pos.numy)
        {
            seven->pos=tab[seven->pospre.numx][seven->pospre.numy+1];
        }
        else if(seven->pospre.numx<seven->pos.numx && seven->pospre.numy>seven->pos.numy)
        {
            seven->pos=tab[seven->pospre.numx+1][seven->pospre.numy];
        }
        else if(seven->pospre.numx<seven->pos.numx && seven->pospre.numy==seven->pos.numy)
        {
            seven->pos=tab[seven->pospre.numx][seven->pospre.numy+1];
        }
        else if(seven->pospre.numx>seven->pos.numx && seven->pospre.numy<seven->pos.numy)
        {
            seven->pos=tab[seven->pospre.numx-1][seven->pospre.numy];
        }
        else if(seven->pospre.numx>seven->pos.numx && seven->pospre.numy>seven->pos.numy)
        {
            seven->pos=tab[seven->pospre.numx][seven->pospre.numy-1];
        }
        else if(seven->pospre.numx>seven->pos.numx && seven->pospre.numy==seven->pos.numy)
        {
            seven->pos=tab[seven->pospre.numx][seven->pospre.numy-1];
        }
        else if(seven->pospre.numx==seven->pos.numx && seven->pospre.numy<seven->pos.numy)
        {
            seven->pos=tab[seven->pospre.numx-1][seven->pospre.numy];
        }
        else if(seven->pospre.numx==seven->pos.numx && seven->pospre.numy>seven->pos.numy)
        {
            seven->pos=tab[seven->pospre.numx+1][seven->pospre.numy];
        }

    }
}


