/*This source code copyrighted by MATHEUS OLIVEIRA LIMA
and may not be redistributed without written permission.*/

//Using SDL and standard IO
#include <stdio.h>
#include <SDL.h>
#define SCREEN_WIDTH 600
#define SCREEN_HEIGHT 600
//starts up SDL and creates windows
bool init();

//loads midia
bool loadMedia();

//frees media and shuts down SDL
void close();

// the  window well be rendering to
SDL_Window* gWindow = NULL;

//the surface contained  by the window
SDL_Surface* gScreenSurface = NULL;

// the imagen the image we will load and show on the screen
SDL_Surface* gHelloWorld = NULL;

bool init()
{
    //initialization flag
    bool success = true;

    //initialize SDL
    if( SDL_Init( SDL_INIT_VIDEO ) < 0 )
    {

        printf("SDL couldnt initialize! SDL_ERROR:%s\n",SDL_GetError() );
        success = false;
    }
    else
    {
        //create window
        gWindow = SDL_CreateWindow("SDL Tutorial", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_RESIZABLE);
        if(gWindow == NULL)
        {
            printf("window could not be created! SDL_ERROR: %s\n", SDL_GetError() );
            success=false;
        }
        else
        {
            //get window surface
            gScreenSurface = SDL_GetWindowSurface( gWindow );
        }
    }
    return success;
}


bool loadMedia()
{
    //loading success flag
    bool success = true;

    //load splash image
    gHelloWorld = SDL_LoadBMP( "02_getting_an_image_on_the_screen/hello_world.bmp" );
    if( gHelloWorld == NULL )
    {
        printf("unable to load image %s !\n", "02_getting_an_image_on_the_screen/hello_world.bmp", SDL_GetError() );
        success = false;
    }
    return success;
}



void close()
{
    //Deallocate surface
    SDL_FreeSurface( gHelloWorld );
    gHelloWorld = NULL;

    //destroy window
    SDL_DestroyWindow( gWindow );
    gWindow == NULL;

    //quit SDL subsystems
    SDL_Quit();

}

int main(int argc, char* args[] )
{
    //start up SDL and create window
    if( !init() )
    {
        printf("failed to initialize!\n");
    }
    else
    {
        //load media
        if( !loadMedia() )
        {
            printf("failed to load media!\n");       
        }
        else
        {
            //Apply the image
            SDL_BlitSurface(gHelloWorld, NULL, gScreenSurface, NULL);
            //update the surface
            SDL_UpdateWindowSurface( gWindow);
            // wait two seconds
            SDL_Delay( 2000 );



        }
    }

    //free resources and close SDL
    close();
    
    return 0;

}
