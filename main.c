#include <SDL/SDL.h>
#include"play.h"
int main ( int argc, char** argv )
{
    SDL_Init( SDL_INIT_VIDEO );// initialize SDL video
    SDL_WM_SetIcon(SDL_LoadBMP("images/icon.bmp"), NULL);
    SDL_Surface* screen = SDL_SetVideoMode(720, 600, 32,SDL_HWSURFACE|SDL_DOUBLEBUF);// create a new window
    SDL_Surface* intro = SDL_LoadBMP("images/intro.bmp");// load intro image
    SDL_Rect dstrect; // centre the bitmap on screen
    dstrect.x = 0;dstrect.y = 0;
    SDL_WM_SetCaption("Block Puzzle !",NULL);
    int done = 1;
    while (done)// program main loop
    {
        SDL_Event event;// message processing loop
        while (SDL_PollEvent(&event))
        {
            switch (event.type)// check for messages
            {
            case SDL_QUIT:done = 0;break; // exit if the window is closed
            case SDL_KEYDOWN:// check for keypresses
                {
                    if (event.key.keysym.sym == SDLK_ESCAPE)
                        done = 0;
                    break;
                }
            case SDL_MOUSEBUTTONUP:
                {
                    if((event.motion.x>=265)&&(event.motion.x<=365)&&(event.motion.y<=245)&&(event.motion.y>=200))
                        playSolo(screen);
                    else if((event.motion.x>=265)&&(event.motion.x<=410)&&(event.motion.y<=315)&&(event.motion.y>=275))
                        playRebot(screen);
                    else if((event.motion.x>=265)&&(event.motion.x<=600)&&(event.motion.y<=400)&&(event.motion.y>=365))
                        playVsRebot(screen);
                    else if((event.motion.x>=265)&&(event.motion.x<=570)&&(event.motion.y<=475)&&(event.motion.y>=435))
                        introduction(screen);
                    else if((event.motion.x>=265)&&(event.motion.x<=360)&&(event.motion.y<=555)&&(event.motion.y>=510))
                            done = 0;
                    break;
                }
            } // end switch
        } // end of message processing
        SDL_BlitSurface(intro, 0, screen, &dstrect);
        SDL_Flip(screen);// finally, update the screen :)
    } // end main loop
    SDL_FreeSurface(intro);// free loaded bitmap
    printf("Exited cleanly\n");
    return 0;
}
