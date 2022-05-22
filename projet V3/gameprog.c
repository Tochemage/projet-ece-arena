#include "header.h"


void deplacementloop(BITMAP*doublebuffer,t_perso*ninja,t_carre plateau[12][12],int*tour,t_perso tabjoueur[4], int nbjoueurs)
{
    /*
    int i,j;
    for(i=0;i<12;i++)
        {
            for(j=0;j<12;j++)
            {
                //rect(doublebuffer,plateau[j][i].x-24,plateau[j][i].y+24,plateau[j][i].x+24,plateau[j][i].y-24,makecol(0,0,0));
            }
        }
    */
        deplacement(ninja,plateau,tour,tabjoueur,nbjoueurs);
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
    //tabjoueur->img=create_bitmap(37,70);
    //rectfill(tabjoueur->img,0,600,800,0,makecol(255,0,0));
    tabjoueur->deplacementx=-24;
    tabjoueur->deplacementy=-24;
    return tabjoueur;
}



t_perso initperso()
{
    t_perso ran;
    ran.classe=0;
    //ran.img=create_bitmap(37,70);
    //rectfill(ran.img,0,600,800,0,makecol(255,0,0));
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
        tab[i].num=i;
    }
}

void deplacement(t_perso*seven, t_carre tab[12][12],int*tour,t_perso tabjoueur[4], int nbjoueurs)
{
    int i,j,cmpt;
    int casediffx;
    int casediffy;

    if(mouse_b&1 && seven->deplacementx==(-24) && seven->deplacementy==(-24))
    {
        for(j=0;j<12;j++)
        {
            for(i=0;i<12;i++)
            {
                if((mouse_x-tab[i][j].x)<24 && (mouse_x-tab[i][j].x)>(-24) && (mouse_y-tab[i][j].y)<24 && (mouse_y-tab[i][j].y)>(-24) && tab[i][j].obstacle==0 && tab[i][j].autrejoueur==0)
                {

                    casediffx=abs(seven->pos.numx-tab[i][j].numx);
                    casediffy=abs(seven->pos.numy-tab[i][j].numy);
                    if((((seven->Stamina)/10)-(casediffx+casediffy))>=0)
                    {

                        seven->deplacementx=i;
                        seven->deplacementy=j;


                    }
                }
            }
        }
    }
    if(seven->deplacementy!=(-24) || seven->deplacementx!=(-24))
        {
            seven->pospre=seven->pos;
            rest(50);
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
            if(seven->deplacementy==(-24))
            {
                (*tour)++;
            }
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
            if(seven->deplacementx==(-24))
            {
                (*tour)++;
            }
        }
    }

    cmpt=0;
    for(i=0;i<nbjoueurs;i++)
    {
        if(seven->pos.numx==tabjoueur[i].pos.numx && seven->pos.numy==tabjoueur[i].pos.numy && seven->num!=tabjoueur[i].num)
        {
            cmpt++;
        }
    }

    if(seven->pos.obstacle==1 || seven->pos.obstacle==2 || cmpt>0)
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

void attackingprocess(t_perso*attacker, t_perso*defender)
{
    int damage;
    int success=rand()%100;
    int isnear;
    isnear=checkifnear(attacker,defender);

    if(isnear==1)
    {
    switch(attacker->arme.sortilege)
    {
    case 0:
        {
            if(success*attacker->arme.accuracy>50)
            {
                damage=attacker->arme.WEAP_attack*attacker->ATT_Multiplier*50*defender->DEF_Multiplier;
            }
            else
            {
                damage=0;
            }
            break;
        }
        case 1:
        {
            if(success*attacker->arme.accuracy>60)
            {
                damage=attacker->arme.WEAP_attack*attacker->ATT_Multiplier*50*defender->DEF_Multiplier;
            }
            else
            {
                damage=0;
            }
            break;
        }
        case 2:
        {
            if(success*attacker->arme.accuracy>65)
            {
                damage=attacker->arme.WEAP_attack*attacker->ATT_Multiplier*50*defender->DEF_Multiplier;
            }
            else
            {
                damage=0;
            }
            break;
        }
        case 3:
        {
            if(success*attacker->arme.accuracy>67)
            {
                damage=attacker->arme.WEAP_attack*attacker->ATT_Multiplier*50*defender->DEF_Multiplier;
            }
            else
            {
                damage=0;
            }
            break;
        }
    }
    if(damage==0)
    {
        //attack failed
    }
    else
    {
        defender->PV-=damage;
    }
    }
    else
    {
    //attaque impossible car joueur trop loin
    }
}

void attackingviasort(t_perso*attacker,t_perso*defender)
{
    switch(attacker->arme.sortilege)
    {

    }
}

void generationobstacles(t_carre tabb[12][12])
{
    int x[3],y[3];
    for(int i=0;i<3;i++)
    {
        x[i]=rand()%(10)+1;
        y[i]=rand()%(10)+1;
    }

    for(int i=0;i<3;i++)
    {
        tabb[x[i]][y[i]].obstacle=1;
        tabb[x[i]][y[i]-1].obstacle=2;
    }
}



int checkifnear(t_perso*attacker, t_perso*defender)
{
    int isnear;

    if(attacker->pos.numx==defender->pos.numx+1 ||attacker->pos.numx==defender->pos.numx-1 || attacker->pos.numx==defender->pos.numy+1 || attacker->pos.numx==defender->pos.numy-1)
    {
        isnear=1;
    }
    else
    {
        isnear=0;
    }

    return isnear;
}

void affichagepointer(BITMAP*doublebuffer,t_carre tab[12][12],BITMAP*pointer,t_perso*player)
{
    int casediffx,casediffy;
    for(int j=0;j<12;j++)
        {
            for(int i=0;i<12;i++)
            {
                if((mouse_x-tab[i][j].x)<24 && (mouse_x-tab[i][j].x)>(-24) && (mouse_y-tab[i][j].y)<24 && (mouse_y-tab[i][j].y)>(-24) && tab[i][j].obstacle==0)
                {
                    casediffx=abs(player->pos.numx-tab[i][j].numx);
                    casediffy=abs(player->pos.numy-tab[i][j].numy);
                    if((((player->Stamina)/10)-(casediffx+casediffy))>=0)
                    {
                    draw_sprite(doublebuffer,pointer,tab[i][j].x-25,tab[i][j].y-25);
                    }
                }
            }
        }
}

void showmovement(t_perso* ninja,BITMAP* doublebuffer, BITMAP* canmove, t_carre plateau[12][12])
{
    //int capmove=ninja->Stamina;
    for(int i=0;i>ninja->Stamina+1;i++)
    {
        if(ninja->pos.numx+i<=12 && ninja->pos.numx+i>=0 && plateau[ninja->pos.numx+i][ninja->pos.numy].obstacle==0)
        {
            draw_sprite(doublebuffer,canmove,ninja->pos.x+(48*i)-25,ninja->pos.y-24);
            draw_sprite(doublebuffer,canmove,ninja->pos.x-(48*i)-25,ninja->pos.y-24);
        }
    }
    for(int i=0;i>ninja->Stamina;i++)
    {
        if(ninja->pos.numy+i<24 && ninja->pos.numy+i>-24)
        {
            draw_sprite(doublebuffer,canmove,ninja->pos.x-24,ninja->pos.y-(48*i));
            draw_sprite(doublebuffer,canmove,ninja->pos.x-24,ninja->pos.y+(48*i));
        }
    }
}