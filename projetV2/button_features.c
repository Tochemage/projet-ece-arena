#include "header.h"

int button_maker(int posX, int posY, BITMAP *confirm, BITMAP *buffer, int mouse_prev)
{
    int status=0;

    blit(confirm, buffer, 0, 0, posX, posY, confirm->w, confirm->h);

    if(mouse_x>posX && mouse_x<posX+confirm->w && mouse_y>posY && mouse_y<posY+confirm->h)
    {
        rectfill(buffer, posX, posY, posX+confirm->w, posY+confirm->h, makeacol(200,200,200,150));

        if(mouse_b==1 && mouse_prev==0)
        {
            status=1;
        }
    }
    return status;
}
