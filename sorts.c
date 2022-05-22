#include "header.h"

void sortpriere(t_perso *user)
{
    if(user->Faith<200)
    {
        user->Faith+=20;
    }

}

void sortboostattaque(t_perso *user)
{
    if(user->Faith>=25)
    {
      user->Faith-=25;
      user->ATT_Multiplier+=0.05;
    }

}

void sortboostdefence(t_perso *user)
{
    if(user->Faith>=20)
    {
        user->Faith-=20;
        user->DEF_Multiplier+=0.05;
    }
}

void sortheal(t_perso*user)
{
    if(user->arme.sortilege==2 && user->Faith>=50)
    {
        user->Faith-=50;
        user->PV+=20;
    }
}
void sortpoison(t_perso* user,t_perso allperso[4], int nbjoueurs)
{
    int isnear=0;
    for(int i=0;i<nbjoueurs;i++)
    {
        isnear=checkifnear(user,&allperso[i]);
        if(isnear==1 && user->Faith>=50)
        {
            user->Faith-=50;
            allperso[i].PV-=50;
        }
    }
}

void sortfleche(t_perso*user,t_perso allperso[4],int nbjoueurs,t_carre tab[12][12])
{
    int casediffx,casediffy;


    for(int k=0;k<nbjoueurs;k++)
    {
        for(int j=0;j<12;j++)
        {
            for(int i=0;i<12;i++)
            {
                casediffx=abs(user->pos.numx-tab[i][j].numx);
                casediffy=abs(user->pos.numy-tab[i][j].numy);
                if(5-(casediffx+casediffy)>=0 && 5-(casediffx+casediffy)<=3 && user->Faith>=50)
                {
                   user->Faith-=50;
                   allperso[k].PV-=30;

                }
            }

        }
    }
}

void sortslash(t_perso*user,t_perso allperso[4],int nbjoueurs,t_carre tab[12][12])
{
    for(int k=0;k<nbjoueurs;k++)
    {
        for(int j=0;j<12;j++)
        {
            for(int i=0;i<12;i++)
            {
                if((user->pos.numx==allperso[k].pos.numx && j==allperso[k].pos.numy) || (user->pos.numy==allperso[k].pos.numy && i==allperso[k].pos.numx))
                {
                    if(user->Faith>=50)
                    {
                      user->Faith-=50;
                      allperso[k].PV-=30;
                    }

                }
            }
        }
    }
}
