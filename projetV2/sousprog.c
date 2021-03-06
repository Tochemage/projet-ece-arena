#include "header.h"

/*
void initAllegro()
{

    allegro_init();

    ///initialisation de program Allegro 4
    set_window_title("WANO KUNI"); // nom de program
    install_keyboard();
    install_mouse();
    set_color_depth(16);
    set_alpha_blender();
    drawing_mode(DRAW_MODE_TRANS, 0, 0, 0);
    enable_hardware_cursor();
    show_os_cursor(MOUSE_CURSOR_ALLEGRO);
    select_mouse_cursor(MOUSE_CURSOR_ARROW);
    show_mouse(screen);
    /// taille de l'?cran avec 800 en largeur et 600 en hauteur


    ///appel sous prog menu
    //menuDeJeu();
    //readkey();

}
*/

///bouton qui fait quitter
void Changement(bool * variablebool)
{
    *variablebool=true;
}
/// <- menuDeJeu.h
void affichageMembres(int w,int h)
{




    ///double buffer
    BITMAP *Membre = create_bitmap(w,h);
    ///image de fond
    BITMAP *menuImg = load_bitmap("img/affichage_nom_joueurs/affichage_nom.bmp",NULL);


    /// ne quitte pas tant que "esc" n'est pas press?e
    bool isDone= false;
    while(!isDone)
    {
        ///fonctionnalit?s du menu
        if(key[KEY_ESC])
        {
            isDone=true;
        }

        //switch(compteur){

        //case 0:
        menuImg = load_bitmap("img/affichage_nom_joueurs/affichage_nom.bmp",NULL);
        //  break;

        //  }





        ///initialiser et afficher l'image
        blit(menuImg,Membre,0,0,0,0,w,h);
        ///texte ? afficher dans l'application

        textout_ex (Membre,font,"Appuyer sur ESC pour retourner",0,h-10,makecol(50,255,38),makecol(176,176,176));


        /// double buffer
        blit(Membre,screen,0,0,0,0,w,h);
        ///montrer souris
        show_mouse(screen);
        rest(50);
        clear_bitmap(Membre);
    }

}

int menuDeJeu(t_sauvegarde *newPartie)
{

    //t_sauvegarde Partie;
    ///pour la musique
    /* install_sound(DIGI_AUTODETECT,MIDI_AUTODETECT,"A");

     SAMPLE* musique;
     musique = load_sample("menuMusique.wav");
     play_sample(musique,255,128,1000,true);
    */
    bool Fermer = false ;
    ///quitter si il tape sur x
    //LOCK_FUNCTION(Changement);
    int w = 1500;
    int h = 1050;
    ///compteur de selection de menu
    int cmpt =0,var=0,returnvar=0;

    ///ecran double buffer
    BITMAP *menuScreen = create_bitmap(w,h);

    ///image de fond
    BITMAP *ImageDeFond = malloc(sizeof(BITMAP));
    /// fermer le programme
    //set_close_button_callback(Changement);

    while((!Fermer)&& (var==0))
    {


        /// Logique de selection
        if((mouse_y>350 && mouse_y<390)&&(mouse_x>550 && mouse_x<950))
        {
            cmpt=1;


        }

        if((mouse_y>420 && mouse_y<464)&&(mouse_x>520 && mouse_x<975))
        {
            cmpt=2;

        }

        if((mouse_y>490 && mouse_y<525)&&(mouse_x>665 && mouse_x<835))
        {
            cmpt=3;

        }

        if((mouse_y>555 && mouse_y<595)&&(mouse_x>665 && mouse_x<835))
        {
            cmpt=4;


        }

        if((mouse_y>625 && mouse_y<663)&&(mouse_x>660 && mouse_x<842))
        {
            cmpt=5;


        }

        if((mouse_y>990 && mouse_y<1030)&&(mouse_x>11 && mouse_x<55))
        {
            cmpt=6;


        }

        if(cmpt>6 )
        {
            cmpt=1;
        }


        if(cmpt<0)
        {
            cmpt=6;
        }


        switch(cmpt)
        {
        case 1:
            ImageDeFond = load_bitmap("arena/menu/1.bmp",NULL);
            if((mouse_b&1)==1)
            {
                ///ici on met le sous prog de lancement d'une partie
                //stop_sample(musique);
                clear_bitmap(menuScreen);
                var = MenuDesJoueurs(w,h,1,newPartie);

                //play_sample(musique,255,128,1000,true);
                //rest(50);

            }

            break;
        case 2:
            ImageDeFond = load_bitmap("arena/menu/2.bmp",NULL);
            if((mouse_b&1)==1)
            {
                ///ici on met l'action et l'appel du sous prog de sauvegarde d'une partie

            }
            break;
        case 3:
            ImageDeFond = load_bitmap("arena/menu/3.bmp",NULL);
            if((mouse_b&1)==1)
            {
                /// ?cran double buffer

                clear_bitmap(menuScreen);
                Score(w,h);

                //rest(50);
                set_gfx_mode(GFX_AUTODETECT_WINDOWED,1500,1050,0,0);

            }
            break;
        case 4:
            ImageDeFond = load_bitmap("arena/menu/4.bmp",NULL);
            if((mouse_b&1)==1)
            {
                ///ici on appel le sous prog des Membres
                clear_bitmap(menuScreen);
                Regles(w,h);
                //rest(50);
            }


            break;
        case 5:
            ImageDeFond = load_bitmap("arena/menu/5.bmp",NULL);
            if((mouse_b&1)==1)
            {

                Changement(&Fermer);

            }

            break;

        case 6:
            ImageDeFond = load_bitmap("arena/menu/0.bmp",NULL);
            if((mouse_b&1)==1)
            {
                clear_bitmap(menuScreen);
                Options(w,h);
                //rest(50);

            }

            break;

        default:
            ///image menu quand rien n'est selectionn?
            ImageDeFond = load_bitmap("arena/menu/0.bmp",NULL);
            break;

        }


        ///afficher l'image
        blit(ImageDeFond,menuScreen,0,0,0,0,w,h);

        ///texte ? afficher dans l'application
        //textout_ex (menuScreen,font,"Appuyer sur Q pour quitter",0,h-10,makecol(50,255,38),makecol(176,176,176));

        /// double buffer
        blit(menuScreen,screen,0,0,0,0,w,h);

        ///montrer souris
        show_mouse(screen);
        rest(50);
        clear_bitmap(menuScreen);

    }

    return var;
}

/// <- menuDeJeu.h
int MenuDesJoueurs(int w,int h,int nbDePartie,t_sauvegarde *newPartie)
{
    ///Utiliser l'heure actuelle comme parametre pour le g?n?rateur al?atoire
    srand(time(0));

///compteur pour choisir element du menu
    int compteur =0,x=0;

    ///configuration de la police ? partir du dossier source


    /// ?cran double buffer
    BITMAP *menuScreen = create_bitmap(w,h);
    /// image de fond
    BITMAP *menuImg = load_bitmap("arena/joueur/nbjoueur/0.bmp",NULL);

    ///text a afficher pour le test de la boucle voir si elle fonctionne
    ///textout_ex (backGroundImage,font1,"Hello World",round(w/2) -150 ,round(h/2),makecol(207,14,19),makecol(0,0,0)); ///texte ? afficher dans l'application


    ///ne pas quitter tant que "esc" na pas ?t? press?e
    bool isDone= false;
    while(!isDone)
    {

        ///Fonctionnalit?s du menu
        if(key[KEY_ESC])
        {
            isDone=true;
        }

        ///logique de la selection


        if((mouse_y>470 && mouse_y<720)&&(mouse_x>219 && mouse_x<432))
        {
            compteur=1;


        }

        if((mouse_y>440 && mouse_y<760)&&(mouse_x>673 && mouse_x<897))
        {
            compteur=2;


        }

        if((mouse_y>420 && mouse_y<765)&&(mouse_x>1072 && mouse_x<1303))
        {
            compteur=3;


        }
        if(compteur>3 )
        {
            compteur=1;
        }


        if(compteur<0)
        {
            compteur=3;
        }


        ///animer les ?crans
        switch(compteur)
        {
        case 1:
            menuImg = load_bitmap("arena/joueur/nbjoueur/1.bmp",NULL);
            if((mouse_b&1)==1)
            {
                /// -> partie.h

                initPartie(newPartie,2);

                clear_bitmap(menuScreen);
                ///ICI CA CLEAR LA BITMAP DU MENU JOUEURS QUAND ON APPUIE SUR ENTER CEST NORMAL QUE CA DONNE LIMPRESSION DE REVENIR EN ARRIERE ENFT CA ENVOIE JUSTE PAS LE MENU

                /// -> nomDeJoueurs.h
                nomDeJoueurs(w,h,2,newPartie);

                /// plateauDeJeu.h
                x=5;
                //  plateauDeJeu(&newPartie);
                /*rest(50);
                set_gfx_mode(GFX_AUTODETECT_WINDOWED,1500,1050,0,0);
                */
                isDone=true;

            }

            break;
        case 2:
            menuImg = load_bitmap("arena/joueur/nbjoueur/2.bmp",NULL);
            if((mouse_b&1)==1)
            {


                initPartie(newPartie,2);

                clear_bitmap(menuScreen);

                /// -> nomDeJoueurs.h
                nomDeJoueurs(w,h,3,newPartie);

                /// plateauDeJeu.h
                x=6;
                // plateauDeJeu(&newPartie);
                /*rest(50);
                set_gfx_mode(GFX_AUTODETECT_WINDOWED,1500,1050,0,0);*/

                isDone=true;

            }
            break;
        case 3:
            menuImg = load_bitmap("arena/joueur/nbjoueur/3.bmp",NULL);
            if((mouse_b&1)==1)
            {

                initPartie(newPartie,2);


                clear_bitmap(menuScreen);

                /// -> nomDeJoueurs.h
                nomDeJoueurs(w,h,4,newPartie);

                x=7;
                /// plateauDeJeu.h
                // plateauDeJeu(&newPartie);
                /*rest(50);
                set_gfx_mode(GFX_AUTODETECT_WINDOWED,1500,1050,0,0);*/

                isDone=true;
            }
            break;
        default:
            menuImg = load_bitmap("arena/joueur/nbjoueur/0.bmp",NULL);
            break;

        }
        ///afficher image de menu
        blit(menuImg,menuScreen,0,0,0,0,w,h);

        ///texte ? afficher dans l'application
        textout_ex (menuScreen,font,"Appuyer sur ESC pour retourner",0,h-10,makecol(50,255,38),makecol(176,176,176));
        /// changer couleur
        /// double buffer
        blit(menuScreen,screen,0,0,0,0,w,h);

        ///montrer souris
        show_mouse(screen);
        rest (50);
        clear_bitmap(menuScreen);


    }

    return x;
}

/// <- menuDeJeu.h
void Regles(int w,int h)
{

///compteur pour chosiir element du menu
    int compteur =0;

    ///double buffer
    BITMAP *Regle = create_bitmap(w,h);
    ///image de fond
    BITMAP *menuImg = load_bitmap("arena/regles/1.bmp",NULL);


    /// ne quitte pas tant que "esc" n'est pas press?e
    bool isDone= false;
    while(!isDone)
    {
        ///fonctionnalit?s du menu
        if(key[KEY_ESC])
        {
            isDone=true;
        }

        ///logique pour la selection des elements du menu
        if(compteur>3 )
        {
            compteur=1;
        }

        if(compteur<0)
        {
            compteur=3;
        }


        if((mouse_y>611 && mouse_y<670)&&(mouse_x>1202 && mouse_x<1277)&&(mouse_b&1)==1)
        {

            compteur++;
        }

        if((mouse_y>605 && mouse_y<674)&&(mouse_x>213 && mouse_x<294)&&(mouse_b&1)==1)
        {

            compteur--;
        }


        /// animer les ecrans
        switch(compteur)
        {
        case 1:
            menuImg = load_bitmap("arena/regles/1.bmp",NULL);
            break;
        case 2:
            menuImg = load_bitmap("arena/regles/2.bmp",NULL);

            break;
        case 3:
            menuImg = load_bitmap("arena/regles/3.bmp",NULL);

            break;

        default:
            menuImg = load_bitmap("arena/regles/1.bmp",NULL);
            break;

        }
        ///initialiser et afficher l'image
        blit(menuImg,Regle,0,0,0,0,w,h);
        ///texte ? afficher dans l'application

        textout_ex (Regle,font,"Appuyer sur ESC pour retourner",0,h-10,makecol(50,255,38),makecol(176,176,176));


        /// double buffer
        blit(Regle,screen,0,0,0,0,w,h);
        ///montrer souris
        show_mouse(screen);
        rest(50);
        clear_bitmap(Regle);


    }


}

/// pour allouer dynamiquement l'espace pour le nom
void *_allocator(size_t element, size_t typeSize)
{
    void *ptr = NULL;///INITIALISATION POINTEUR
    /* verifier l'allocation dynamique */
    if( (ptr = calloc(element, typeSize)) == NULL)
    {
        printf("PAS ASSEZ DE MEMOIRE");
        exit(1);
    }
    /* retourner le pointeur ? l'appelant */
    return ptr;
}

/// ajouter un caractere dans le nom avec chaque touche press?e
char *ajoutLettre( char *input, const char c)
{
    if(c == '0' || c == '1' || c == '2' || c == '3' || c == '4' || c == '5' ||c == '6' || c == '7'|| c == '8' ||c == '9' || c == '\x0D'  ) // \x0D
        return input;

    char *ChainePrenom, *ptr;

    /* allouer */
    ChainePrenom = allocator((strlen(input) + 2), char);
    /* copier l'ancienne chaine dans la nouvelle (avec pointeur) */
    ptr = ChainePrenom;
    for(; *input; input++)
    {
        *ptr = *input;
        ptr++;
    }
    /* copier cract?re ? la fin */

    *ptr = c;
    /* retourner la nouvelle chaine (pour dealloc utilisons free().) */
    return ChainePrenom;
}

/// saisie des  noms
void saisieLesNoms(int w,int h,int nbj, t_sauvegarde * partie,BITMAP* menuScreen )
{
    FONT *font1 =load_font("font1.pcx",NULL,NULL);

    blit(menuScreen,screen,0,0,0,0,w,h);

    int x = 480;
    int y = 250; //add 80 every next name

    /// Les noms des joueurs
    bool enterClicked ;
    char nomC;
    // char  nom;
    for(int i=0; i<nbj; i++)
    {

        char  *nom = "";

        enterClicked=false;
        if(nbj==2)
        {
            textout_ex (menuScreen,font1,"Saisir le nom",x-190,y+120,makeacol(253,108,158,255),-1);

        }

        else if(nbj==3)
        {
            textout_ex (menuScreen,font1,"Saisir le nom",x-190,y+110,makecol(253,108,158),-1);

        }

        else if(nbj==4)
        {
            textout_ex (menuScreen,font1,"Saisir le nom",x-190,y+90,makecol(253,108,158),-1);

        }
        //textout_ex (menuScreen,font1,"Saisir le nom",x-160,y+50,makecol(207,14,19),makecol(164,194,244));

        blit(menuScreen,screen,0,0,0,0,w,h);

        while(!enterClicked)
        {
            ///passer nom suivant quand "enter" est press?e ou "espace"
            if((key[KEY_ENTER]) && strlen(nom)>3 )
            {
                if(nbj==2)
                {
                    y+=180;
                }

                else if(nbj==3)
                {
                    y+=180;
                }
                else if(nbj==4)
                {
                    y+=180;
                }
                enterClicked = true;



            }
            else
            {

                nomC=readkey();

                nom = ajoutLettre(nom,nomC);
                if (nbj==2)
                {
                    textout_ex (menuScreen,font1,nom,x+60,y+120,makecol(253,108,158),-1);
                }
                else if (nbj==3)
                {
                    textout_ex (menuScreen,font1,nom,x+60,y+120,makecol(253,108,158),-1);
                }
                else if (nbj==4)
                {
                    textout_ex (menuScreen,font1,nom,x+60,y+80,makecol(253,108,158),-1);
                }
                //textout_ex (menuScreen,font1,nom,x,y+50,makecol(207,14,19),makecol(255,255,255));

            }
            // partie->joueurs[i].nom[20]=nom ;
            strcpy(partie->tabjoueur[i].nom,nom);
            textout_ex (menuScreen,font,"Appuyer sur entree pour valider",60,1030,makecol(253,108,158),-1);
            blit(menuScreen,screen,0,0,0,0,w,h);
        }

        //y+=110;
    }

    // blit(menuScreen,screen,0,0,0,0,w,h);

}

/// <-- menu.h
void nomDeJoueurs(int w,int h,int nbDeJoueurs,t_sauvegarde * newPartie)
{
    ///configuration de la police ? partir du dossier source

    /// ?cran double buffer

    BITMAP *menuScreen = create_bitmap(w,h);

    printf("dfdfsjcdefxhdsdfres hjklb fges <b,\n");

    /// image de fond
    BITMAP *menuImg = malloc(sizeof(BITMAP));

    printf("dfdfsjcdefxhdsdfres hjklb fges <b,\n");


    /// ne pas quitter tant que "esc" n'est pas press?e
    bool isDone= false;
    while(!isDone)
    {
        /// focntionnalit?s du menu
        if(key[KEY_ESC])
        {
            isDone=true;
        }

        /// animer les "?crans"

        switch(nbDeJoueurs)
        {
        case 2: ///

            menuImg = load_bitmap("arena/joueur/saisie/1.bmp",NULL);


            if((mouse_b&1)==1)
            {
                clear_keybuf();
                blit(menuImg,menuScreen,0,0,0,0,w,h);

                saisieLesNoms(w,h,nbDeJoueurs,newPartie,menuScreen);

                isDone=true;
            }


            break;
        case 3:

            menuImg = load_bitmap("arena/joueur/saisie/2.bmp",NULL);
            if((mouse_b&1)==1)
            {

                clear_keybuf();
                //rest(40);
                blit(menuImg,menuScreen,0,0,0,0,w,h);
                saisieLesNoms(w,h,nbDeJoueurs,newPartie,menuScreen);


                isDone=true;
            }
            break;
        case 4:
            menuImg = load_bitmap("arena/joueur/saisie/3.bmp",NULL);
            if((mouse_b&1)==1)
            {
                clear_keybuf();

                blit(menuImg,menuScreen,0,0,0,0,w,h);
                //rest(40);
                saisieLesNoms(w,h,nbDeJoueurs,newPartie,menuScreen);

                isDone=true;
            }
            break;

        default:
            printf("\n \t erreur dans nomdejoueurs.h \n");
            break;

        }
        /// draw down
        ///pr?parer ("? l'affichage) image de fond du menu

        blit(menuImg,menuScreen,0,0,0,0,w,h);

        ///texte ? afficher dans l'application
        textout_ex (menuScreen,font,"Appuyer sur ESC pour retourner",0,h-10,makecol(207,14,19),makecol(164,194,244));

        ///Draw top
        ///double buffer
        blit(menuScreen,screen,0,0,0,0,w,h);

        ///montrer souris
        show_mouse(screen);

        rest (40);
        clear_bitmap(menuScreen);
    }


}

void initPartie(t_sauvegarde *PartieDeSauvegarde,int nbJoueurs/*,int nbDePartie*/)
{
    PartieDeSauvegarde->indexjEnTour=0;

}


void Options(int w,int h)
{

///compteur pour chosiir element du menu
    int compteur =0;

    ///double buffer
    BITMAP *Options = create_bitmap(w,h);
    ///image de fond
    BITMAP *menuImg = load_bitmap("arena/options/1.bmp",NULL);



    /// ne quitte pas tant que "esc" n'est pas press?e
    bool isDone= false;
    while(!isDone)
    {

        if(key[KEY_ESC])
        {
            isDone=true;
        }

        if (compteur%2==0)
        {

            menuImg = load_bitmap("arena/options/1.bmp",NULL);
            if((mouse_y>440 && mouse_y<608)&&(mouse_x>649 && mouse_x<841)&&(mouse_b&1)==1)
            {
                compteur++;
                clear_bitmap(Options);
                menuImg = load_bitmap("arena/options/2.bmp",NULL);
            }

        }

        else
        {

            if((mouse_y>440 && mouse_y<608)&&(mouse_x>649 && mouse_x<841)&&(mouse_b&1)==1)
            {
                compteur++;
                clear_bitmap(Options);
                menuImg = load_bitmap("arena/options/1.bmp",NULL);
            }
        }







        ///initialiser et afficher l'image
        blit(menuImg,Options,0,0,0,0,w,h);
        ///texte ? afficher dans l'application

        textout_ex (Options,font,"Appuyer sur ESC pour retourner",0,h-10,makecol(50,255,38),makecol(176,176,176));


        /// double buffer
        blit(Options,screen,0,0,0,0,w,h);
        ///montrer souris
        show_mouse(screen);
        rest(50);
        clear_bitmap(Options);

    }
}

void Score(int w,int h)
{



    ///double buffer
    BITMAP *Score = create_bitmap(w,h);
    ///image de fond
    BITMAP *scoreImg = load_bitmap("arena/score.bmp",NULL);


    /// ne quitte pas tant que "esc" n'est pas press?e
    bool isDone= false;
    while(!isDone)
    {
        ///fonctionnalit?s du menu
        if(key[KEY_ESC])
        {
            isDone=true;
        }
        scoreImg = load_bitmap("arena/score.bmp",NULL);

        ///initialiser et afficher l'image
        blit(scoreImg,Score,0,0,0,0,w,h);
        ///texte ? afficher dans l'application

        textout_ex (Score,font,"Appuyer sur ESC pour retourner",60,1030,makecol(253,108,158),makecol(255,255,255));


        /// double buffer
        blit(Score,screen,0,0,0,0,w,h);
        ///montrer souris
        show_mouse(screen);
        rest(50);
        clear_bitmap(Score);


    }


}

///ON LAPPELLE POUR LA SAUVAGARDE DUNE PARTIE LORSQUE LON SELECTIONNE SAUVAGARDER DANS LE MENU
void EcrireDonneePartie(t_sauvegarde *PartieDeSauvegarde)
{
    char partie_nom[] = {"sauvegarde_structure_de_jeu.dat"};
    t_sauvegarde partieTemp;
    partieTemp = *PartieDeSauvegarde;
    FILE *fp = fopen(partie_nom,"wb");  /// Ouvrir le fichier ?crire dans celui ci
    if(! fp)
    {
        printf("erreur d'ouverture fichier");
    }
    ///Enregistrer les donn?es de la partie
    fwrite(&partieTemp,sizeof(t_sauvegarde),1,fp);
    fclose(fp);
}

t_sauvegarde LireDonneePartie()
{
    char partie_nom[] = {"sauvegarde_structure_de_jeu.dat"};
    t_sauvegarde partieTemp ;
    FILE *fp;
    fp = fopen(partie_nom,"rb");  ///Ouvrir et lire dans le fichier
    ///Si le fichier existe seulement
    if(! fp)
    {
        printf("erreur d'ouverture fichier");
    }
    /// Lire les donn?es
    while(1)
    {
        fread(&partieTemp,sizeof(t_sauvegarde),1,fp);
        if(feof(fp))
            break;
    }
    return partieTemp;
    fclose(fp);
}
