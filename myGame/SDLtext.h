#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#include <GL/gl.h>
#include <GL/glu.h>

#include <SDL/SDL.h>
#include <SDL/SDL_ttf.h>

/* adjust these accordingly */
char fontpath[] = "VeraMono.ttf";
int screenwidth = 640;
int screenheight = 480;

int Round(double x)
{
    return (int)(x + 0.5);
}

int nextpoweroftwo(int x)
{
    double logbase2 = log(x) / log(2);
    return Round(pow(2,ceil(logbase2)));
}

char *init_sdl(SDL_Surface** screen)
{
    if(SDL_Init(SDL_INIT_VIDEO))
        return SDL_GetError();
    atexit(SDL_Quit);
    
    *screen = SDL_SetVideoMode(screenwidth, screenheight, 0, SDL_OPENGL);
    
    SDL_WM_SetCaption("C-Junkie's SDLGL text example", 0);
    
    if(TTF_Init())
        return TTF_GetError();
    atexit(TTF_Quit);
    
    return 0;
}

void SDL_GL_RenderText(const char *text, 
                      TTF_Font *font,
                      SDL_Color color,
                      SDL_Rect *location)
{
    SDL_Surface *initial;
    SDL_Surface *intermediary;
    SDL_Rect rect;
    int w,h;
    //int texture;
    GLuint texture;
    
    /* Use SDL_TTF to render our text */
    initial = TTF_RenderText_Blended(font, text, color);
    
    /* Convert the rendered text to a known format */
    w = nextpoweroftwo(initial->w);
    h = nextpoweroftwo(initial->h);
    
    intermediary = SDL_CreateRGBSurface(0, w, h, 32, 
            0x00ff0000, 0x0000ff00, 0x000000ff, 0xff000000);

    SDL_BlitSurface(initial, 0, intermediary, 0);
    
    /* Tell GL about our new texture */
    glGenTextures(1, &texture);
    glBindTexture(GL_TEXTURE_2D, texture);
    glTexImage2D(GL_TEXTURE_2D, 0, 4, w, h, 0, GL_BGRA, 
            GL_UNSIGNED_BYTE, intermediary->pixels );
    
    /* GL_NEAREST looks horrible, if scaled... */
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);   

    /* prepare to render our texture */
    glEnable(GL_TEXTURE_2D);
    glBindTexture(GL_TEXTURE_2D, texture);
    glColor3f(1.0f, 1.0f, 1.0f);
    
    /* Draw a quad at location */
    glBegin(GL_QUADS);
        /* Recall that the origin is in the lower-left corner
           That is why the TexCoords specify different corners
           than the Vertex coors seem to. */
        glTexCoord2f(0.0f, 1.0f); 
            glVertex2f(location->x    , location->y);
        glTexCoord2f(1.0f, 1.0f); 
            glVertex2f(location->x + w, location->y);
        glTexCoord2f(1.0f, 0.0f); 
            glVertex2f(location->x + w, location->y + h);
        glTexCoord2f(0.0f, 0.0f); 
            glVertex2f(location->x    , location->y + h);
    glEnd();
    
    /* Bad things happen if we delete the texture before it finishes */
    glFinish();
    
    /* return the deltas in the unused w,h part of the rect */
    location->w = initial->w;
    location->h = initial->h;
    
    /* Clean up */
    SDL_FreeSurface(initial);
    SDL_FreeSurface(intermediary);
    glDeleteTextures(1, &texture);
}

void glEnable2D()
{
    int vPort[4];
  
    glGetIntegerv(GL_VIEWPORT, vPort);
  
    glMatrixMode(GL_PROJECTION);
    glPushMatrix();
    glLoadIdentity();
  
    glOrtho(0, vPort[2], 0, vPort[3], -1, 1);
    glMatrixMode(GL_MODELVIEW);
    glPushMatrix();
    glLoadIdentity();
}

void glDisable2D()
{
    glMatrixMode(GL_PROJECTION);
    glPopMatrix();   
    glMatrixMode(GL_MODELVIEW);
    glPopMatrix();      
}




