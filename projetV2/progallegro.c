#include "header.h"


BITMAP* recup_sprites( BITMAP*scr,int w,int h,int startx,int starty,int col,int element)
// bitmap origine
// taille de l’image élément d’une animation
//
// début de la séquence voulue à partir de la position
// x et y
// nombre de colonnes dans la bitmap origine
// numéro de l’image voulue dans la séquence

{

    BITMAP *bmp;

    int x,y;

    bmp=create_bitmap(w,h);
    // création d’une bitmap pour le sprite

    if (bmp!=NULL)
    {

        x = startx + (element%col)*w;
        // calcul de la position réelle du sprite dans la bitmap

        y = starty + (element/col)*h;
        // d’origine

        blit( scr, bmp, x, y, 0, 0, w, h);
        //recopie du sprite voulu

    }

return bmp;
// retour de la bitmap du sprite

}

/*
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
	set_display_switch_mode(SWITCH_BACKGROUND);
}
*/
