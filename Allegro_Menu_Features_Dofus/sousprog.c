#include "header.h"
void initAllegro()
{

    allegro_init();

    ///initialisation de program Allegro 4
    set_window_title("ARENA WANO KUNI"); // nom de program
    install_keyboard();
    install_mouse();
    set_color_depth(16);
    /// taille de l'écran avec 800 en largeur et 600 en hauteur
    set_gfx_mode(GFX_AUTODETECT_WINDOWED,1500,1050,0,0);

    readkey();

}

void Changement(bool * variablebool)
{
    *variablebool=true;
}


void initPartie(t_sauvegarde *PartieDeSauvegarde,int nbJoueurs)
{

    int x;

    PartieDeSauvegarde->indexjEnTour=0;
    for(x=0; x<nbJoueurs; x++)
    {
        printf("a");
    }

}

void menuDeJeu()
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
    int cmpt =0;

    ///ecran double buffer
    BITMAP *menuScreen = create_bitmap(w,h);

    ///image de fond
    BITMAP *ImageDeFond = malloc(sizeof(BITMAP));
    /// fermer le programme
    //set_close_button_callback(Changement);

    while(!Fermer)
    {


        /// Logique de selection
        if(mouse_y>550 && mouse_y<600)
        {
            cmpt=1;
            rest(50);

        }

        if(mouse_y>600 && mouse_y<650)
        {
            cmpt=2;
            rest(50);

        }

        if(mouse_y>650 && mouse_y<700)
        {
            cmpt=3;
            rest(50);

        }

        if(mouse_y>700 && mouse_y<750)
        {
            cmpt=4;
            rest(50);

        }

        if(mouse_y>750 && mouse_y<800)
        {
            cmpt=5;
            rest(50);

        }

        if(mouse_y>850 && mouse_y<900)
        {
            cmpt=6;
            rest(50);

        }

        if(mouse_y>900 && mouse_y<950)
        {
            cmpt=7;
            rest(50);

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
            ImageDeFond = load_bitmap("arena/menu/0.bmp",NULL);
            if(key[KEY_ENTER])
            {
                ///ici on met le sous prog de lancement d'une partie
                //stop_sample(musique);
                clear_bitmap(menuScreen);
                MenuDesJoueurs(w,h,1);
                //play_sample(musique,255,128,1000,true);
                rest(50);

            }

            break;
        case 2:
            ImageDeFond = load_bitmap("arena/menu/1.bmp",NULL);
            if(key[KEY_ENTER])
            {
                ///ici on met l'action et l'appel du sous prog de sauvegarde d'une partie

            }
            break;
        case 3:
            ImageDeFond = load_bitmap("arena/menu/2.bmp",NULL);
            if(key[KEY_ENTER])
            {


                clear_bitmap(menuScreen);
                rest(50);

                //   play_sample(musique,255,128,1000,true);
            }
            break;
        case 4:
            ImageDeFond = load_bitmap("arena/menu/3.bmp",NULL);
            if(key[KEY_ENTER])
            {
                ///ici on appel le sous prog des Membres
                clear_bitmap(menuScreen);
                Regles(w,h);
                rest(50);
            }


            break;
        case 5:
            ImageDeFond = load_bitmap("arena/menu/4.bmp",NULL);
            if(key[KEY_ENTER])
            {

                ///ici on appel le sous prog d'affichage des membres de l'équipe et de leur score(solde etc)



                ///ici on appel le sous prog des Membres
                clear_bitmap(menuScreen);
                //affichageMembres(w,h);
                rest(50);


            }

            break;

        case 6:
            ImageDeFond = load_bitmap("arena/menu/5.bmp",NULL);
            if(key[KEY_ENTER])
            {

                Changement(&Fermer);
            }

            break;

        default:
            ///image menu quand rien n'est selectionné
            ImageDeFond = load_bitmap("arena/menu/0.bmp",NULL);
            break;

        }


        ///afficher l'image
        blit(ImageDeFond,menuScreen,0,0,0,0,w,h);

        ///texte à afficher dans l'application
        textout_ex (menuScreen,font,"Appuyer sur Q pour quitter",0,h-10,makecol(50,255,38),makecol(176,176,176));

        /// double buffer
        blit(menuScreen,screen,0,0,0,0,w,h);

        ///montrer souris
        show_mouse(screen);
        rest(50);
        clear_bitmap(menuScreen);

    }

}

void MenuDesJoueurs(int w,int h,int nbDePartie)
{
    ///Utiliser l'heure actuelle comme parametre pour le générateur aléatoire
    srand(time(NULL));

///compteur pour choisir element du menu
    int compteur =0;

    ///configuration de la police à partir du dossier source


    /// écran double buffer
    BITMAP *menuScreen = create_bitmap(w,h);
    /// image de fond
    BITMAP *menuImg = load_bitmap("arena/joueur/nbjoueur/0.bmp",NULL);

    ///text a afficher pour le test de la boucle voir si elle fonctionne
    ///textout_ex (backGroundImage,font1,"Hello World",round(w/2) -150 ,round(h/2),makecol(207,14,19),makecol(0,0,0)); ///texte à afficher dans l'application


    ///ne pas quitter tant que "esc" na pas été pressée
    bool isDone= false;
    while(!isDone)
    {

        ///Fonctionnalités du menu
        if(key[KEY_ESC])
        {
            isDone=true;
        }

        ///logique de la selection


        if(key[KEY_DOWN])
        {
            compteur++;
            rest(50);
        }


        if(key[KEY_UP])
        {
            compteur--;
            rest(50);
        }

        if(compteur>3 )
        {
            compteur=1;
        }


        if(compteur<0)
        {
            compteur=3;
        }


        ///animer les écrans
        switch(compteur)
        {
        case 1:
            menuImg = load_bitmap("arena/joueur/nbjoueur/1.bmp",NULL);
            if(key[KEY_ENTER])
            {
                /// -> partie.h
                t_sauvegarde newPartie;
                initPartie(&newPartie,2);

                clear_bitmap(menuScreen);
                ///ICI CA CLEAR LA BITMAP DU MENU JOUEURS QUAND ON APPUIE SUR ENTER CEST NORMAL QUE CA DONNE LIMPRESSION DE REVENIR EN ARRIERE ENFT CA ENVOIE JUSTE PAS LE MENU

                /// -> nomDeJoueurs.h
                nomDeJoueurs(w,h,2,&newPartie);

                /// plateauDeJeu.h
//                plateauDeJeu(&newPartie);
                rest(50);
                set_gfx_mode(GFX_AUTODETECT_WINDOWED,800,600,0,0);

                isDone=true;

            }

            break;
        case 2:
            menuImg = load_bitmap("arena/joueur/nbjoueur/2.bmp",NULL);
            if(key[KEY_ENTER])
            {

                t_sauvegarde newPartie ;
                initPartie(&newPartie,2);

                clear_bitmap(menuScreen);

                /// -> nomDeJoueurs.h
                nomDeJoueurs(w,h,3,&newPartie);

                /// plateauDeJeu.h
//                plateauDeJeu(&newPartie);
                rest(50);
                set_gfx_mode(GFX_AUTODETECT_WINDOWED,800,600,0,0);

                isDone=true;

            }
            break;
        case 3:
            menuImg = load_bitmap("arena/joueur/nbjoueur/3.bmp",NULL);
            if(key[KEY_ENTER])
            {
                t_sauvegarde newPartie ;
                initPartie(&newPartie,2);

                clear_bitmap(menuScreen);

                /// -> nomDeJoueurs.h
                nomDeJoueurs(w,h,4,&newPartie);

                /// plateauDeJeu.h
               // plateauDeJeu(&newPartie);
                rest(50);
                set_gfx_mode(GFX_AUTODETECT_WINDOWED,800,600,0,0);

                isDone=true;
            }
            break;
        default:
            menuImg = load_bitmap("img/nombre_de_joueurs/nombrejoueur0.bmp",NULL);
            break;

        }
        ///afficher image de menu
        blit(menuImg,menuScreen,0,0,0,0,w,h);

        ///texte à afficher dans l'application
        textout_ex (menuScreen,font,"Appuyer sur ESC pour retourner",0,h-10,makecol(50,255,38),makecol(176,176,176));
        /// changer couleur
        /// double buffer
        blit(menuScreen,screen,0,0,0,0,w,h);

        ///montrer souris
        show_mouse(screen);
        rest (50);
        clear_bitmap(menuScreen);


    }


}

void *_allocator(size_t element, size_t typeSize)
{
    void *ptr = NULL;///INITIALISATION POINTEUR
    /* verifier l'allocation dynamique */
    if( (ptr = calloc(element, typeSize)) == NULL)
    {
        printf("PAS ASSEZ DE MEMOIRE");
        exit(1);
    }
    /* retourner le pointeur à l'appelant */
    return ptr;
}

/// ajouter un caractere dans le nom avec chaque touche pressée
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
    /* copier cractère à la fin */

    *ptr = c;
    /* retourner la nouvelle chaine (pour dealloc utilisons free().) */
    return ChainePrenom;
}

/// saisie des  noms
void saisieLesNoms(int w,int h,int nbj, t_sauvegarde * partie,BITMAP* menuScreen )
{
    FONT *font1 =load_font("font1.pcx",NULL,NULL);

    blit(menuScreen,screen,0,0,0,0,w,h);

    int x = 323;
    int y = 136; //add 80 every next name

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
            textout_ex (menuScreen,font1,"Saisir le nom",x-175,y+120,makecol(207,14,19),makecol(164,194,244));

        }

        else if(nbj==3)
        {
            textout_ex (menuScreen,font1,"Saisir le nom",x-175,y+80,makecol(207,14,19),makecol(164,194,244));

        }

        else if(nbj==4)
        {
            textout_ex (menuScreen,font1,"Saisir le nom",x-175,y+50,makecol(207,14,19),makecol(164,194,244));

        }
        //textout_ex (menuScreen,font1,"Saisir le nom",x-160,y+50,makecol(207,14,19),makecol(164,194,244));

        blit(menuScreen,screen,0,0,0,0,w,h);

        while(!enterClicked)
        {
            ///passer nom suivant quand "enter" est pressée ou "espace"
            if((key[KEY_ENTER]) && strlen(nom)>3 )
            {
                if(nbj==2)
                {
                    y+=180;
                }

                else if(nbj==3)
                {
                    y+=125;
                }
                else if(nbj==4)
                {
                    y+=115;
                }
                enterClicked = true;



            }
            else
            {

                nomC=readkey();

                nom = ajoutLettre(nom,nomC);
                if (nbj==2)
                {
                    textout_ex (menuScreen,font1,nom,x,y+120,makecol(207,14,19),makecol(255,255,255));
                }
                else if (nbj==3)
                {
                    textout_ex (menuScreen,font1,nom,x,y+80,makecol(207,14,19),makecol(255,255,255));
                }
                else if (nbj==4)
                {
                    textout_ex (menuScreen,font1,nom,x,y+50,makecol(207,14,19),makecol(255,255,255));
                }
                //textout_ex (menuScreen,font1,nom,x,y+50,makecol(207,14,19),makecol(255,255,255));

            }
            // partie->joueurs[i].nom[20]=nom ;
            strcpy(partie->tabjoueur[i].nom,nom);
            textout_ex (menuScreen,font,"Appuyer sur entree pour valider",0,590,makecol(50,255,38),makecol(176,176,176));
            blit(menuScreen,screen,0,0,0,0,w,h);
        }

        //y+=110;
    }

    // blit(menuScreen,screen,0,0,0,0,w,h);

}

/// <-- menu.h
void nomDeJoueurs(int w,int h,int nbDeJoueurs,t_sauvegarde * newPartie)
{
    ///configuration de la police à partir du dossier source
    //FONT *font1 =load_font("font1.pcx",NULL,NULL);

    /// écran double buffer
    BITMAP *menuScreen = create_bitmap(w,h);
    /// image de fond
    BITMAP *menuImg = malloc(sizeof(BITMAP));


    /// ne pas quitter tant que "esc" n'est pas pressée
    bool isDone= false;
    while(!isDone)
    {
        /// focntionnalités du menu
        if(key[KEY_ESC])
        {
            isDone=true;
        }

        /// animer les "écrans"
        switch(nbDeJoueurs)
        {
        case 2: ///
            menuImg = load_bitmap("arena/joueur/saisie/0.bmp",NULL);
            if(key[KEY_ENTER])
            {
                clear_keybuf();
                blit(menuImg,menuScreen,0,0,0,0,w,h);

                saisieLesNoms(w,h,nbDeJoueurs,newPartie,menuScreen);

                isDone=true;
            }


            break;
        case 3:

            menuImg = load_bitmap("arena/joueur/saisie/1.bmp",NULL);
            if(key[KEY_ENTER])
            {
                clear_keybuf();
                //rest(40);
                blit(menuImg,menuScreen,0,0,0,0,w,h);
                saisieLesNoms(w,h,nbDeJoueurs,newPartie,menuScreen);

                isDone=true;
            }
            break;
        case 4:
            menuImg = load_bitmap("arena/joueur/saisie/2.bmp",NULL);
            if(key[KEY_ENTER])
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
        ///préparer ("à l'affichage) image de fond du menu

        blit(menuImg,menuScreen,0,0,0,0,w,h);

        ///texte à afficher dans l'application
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

void Regles(int w,int h)
{

///compteur pour chosiir element du menu
    int compteur =0;

    ///double buffer
    BITMAP *Regle = create_bitmap(w,h);
    ///image de fond
    BITMAP *menuImg = load_bitmap("arena/regles/0.bmp",NULL);


    /// ne quitte pas tant que "esc" n'est pas pressée
    bool isDone= false;
    while(!isDone)
    {
        ///fonctionnalités du menu
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


        if(key[KEY_RIGHT])
        {
            rest(50);
            compteur++;
        }


        if(key[KEY_LEFT])
        {
            rest(50);
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
            menuImg = load_bitmap("img/Regles/Regles 0.bmp",NULL);
            break;

        }
        ///initialiser et afficher l'image
        blit(menuImg,Regle,0,0,0,0,w,h);
        ///texte à afficher dans l'application

        textout_ex (Regle,font,"Appuyer sur ESC pour retourner",0,h-10,makecol(50,255,38),makecol(176,176,176));


        /// double buffer
        blit(Regle,screen,0,0,0,0,w,h);
        ///montrer souris
        show_mouse(screen);
        rest(50);
        clear_bitmap(Regle);


    }


}
