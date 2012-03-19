/*
 * author Ashish Soni for Gameloft
 */
#include<iostream> 
#include <stdio.h>
#include <stdlib.h>
#include <GL/gl.h>
#include <GL/glu.h>
#include "SDL.h"
#include "SDLtext.h"
#include "SDL/SDL_mixer.h"
using namespace std;
TTF_Font* font;
int cameraAngleX=0;
int cameraAngleY=0;
float RATIO;
int mouseX,mouseY;
bool buttonPressed=false;
bool show=true;

int channel;				//Channel on which our sound is played
int channel1;				//Channel on which our sound is played
int channel2;				//Channel on which our sound is played
Mix_Chunk *sound = NULL;		//Pointer to our sound, in memory
Mix_Chunk *sound1 = NULL;		//Pointer to our sound, in memory
Mix_Chunk *sound2 = NULL;		//Pointer to our sound, in memory
int angleX=0, angleY=0, angleZ=0;

float cubeX = 0.0f;
float cubeZ = 0.0f;
float cubeY = 0.0f;
float stpSz = 2.0f;
float translate = stpSz / 2.0f;
float translateX = stpSz / 2.0f;
float translateY = stpSz / 2.0f;
float translateZ = stpSz / 2.0f;

bool horiz=false;
bool vert=false;
bool single=true;
bool Forward = false;
bool Backward = false;
bool Left = false;
bool Right = false;

GLfloat cubeVertexV[] = {
    // FRONT
    -1.0f, -1.0f,  2.0f,
     1.0f, -1.0f,  2.0f,
    -1.0f,  1.0f,  2.0f,
     1.0f,  1.0f,  2.0f,
    // BACK
    -1.0f, -1.0f,  -2.0f,
     1.0f, -1.0f,  -2.0f,
    -1.0f,  1.0f,  -2.0f,
     1.0f,  1.0f,  -2.0f,
    // LEFT
    -1.0f, -1.0f,  2.0f,
    -1.0f,  1.0f,  2.0f,
    -1.0f, -1.0f, -2.0f,
    -1.0f,  1.0f, -2.0f,
    // RIGHT
     1.0f, -1.0f, -2.0f,
     1.0f,  1.0f, -2.0f,
     1.0f, -1.0f,  2.0f,
     1.0f,  1.0f,  2.0f,
    // TOP
    -1.0f,  1.0f,  2.0f,
     1.0f,  1.0f,  2.0f,
     -1.0f,  1.0f, -2.0f,
     1.0f,  1.0f, -2.0f,
    // BOTTOM
    -1.0f, -1.0f,  2.0f,
    -1.0f, -1.0f, -2.0f,
     1.0f, -1.0f,  2.0f,
     1.0f, -1.0f, -2.0f,
};
GLfloat cubeVertexS[] = {
    // FRONT
    -1.0f, -2.0f,  1.0f,
     1.0f, -2.0f,  1.0f,
    -1.0f,  2.0f,  1.0f,
     1.0f,  2.0f,  1.0f,
    // BACK
    -1.0f, -2.0f,  -1.0f,
     1.0f, -2.0f,  -1.0f,
    -1.0f,  2.0f,  -1.0f,
     1.0f,  2.0f,  -1.0f,
    // LEFT
    -1.0f, -2.0f,  1.0f,
    -1.0f,  2.0f,  1.0f,
    -1.0f, -2.0f, -1.0f,
    -1.0f,  2.0f, -1.0f,
    // RIGHT
     1.0f, -2.0f, -1.0f,
     1.0f,  2.0f, -1.0f,
     1.0f, -2.0f,  1.0f,
     1.0f,  2.0f,  1.0f,
    // TOP
    -1.0f,  2.0f,  1.0f,
     1.0f,  2.0f,  1.0f,
     -1.0f,  2.0f, -1.0f,
     1.0f,  2.0f, -1.0f,
    // BOTTOM
    -1.0f, -2.0f,  1.0f,
    -1.0f, -2.0f, -1.0f,
     1.0f, -2.0f,  1.0f,
     1.0f, -2.0f, -1.0f,
};
GLfloat cubeVertexH[] = {
    // FRONT
    -2.0f, -1.0f,  1.0f,
     2.0f, -1.0f,  1.0f,
    -2.0f,  1.0f,  1.0f,
     2.0f,  1.0f,  1.0f,
    // BACK
    -2.0f, -1.0f,  -1.0f,
     2.0f, -1.0f,  -1.0f,
    -2.0f,  1.0f,  -1.0f,
     2.0f,  1.0f,  -1.0f,
    // LEFT
    -2.0f, -1.0f,  1.0f,
    -2.0f,  1.0f,  1.0f,
    -2.0f, -1.0f, -1.0f,
    -2.0f,  1.0f, -1.0f,
    // RIGHT
     2.0f, -1.0f, -1.0f,
     2.0f,  1.0f, -1.0f,
     2.0f, -1.0f,  1.0f,
     2.0f,  1.0f,  1.0f,
    // TOP
    -2.0f,  1.0f,  1.0f,
     2.0f,  1.0f,  1.0f,
     -2.0f,  1.0f, -1.0f,
     2.0f,  1.0f, -1.0f,
    // BOTTOM
    -2.0f, -1.0f,  1.0f,
    -2.0f, -1.0f, -1.0f,
     2.0f, -1.0f,  1.0f,
     2.0f, -1.0f, -1.0f,
};
GLfloat texVertices[] = {
 0.0f, 1.0f ,
 1.0f, 1.0f ,
 1.0f, 0.0f ,
 0.0f, 0.0f ,
 0.0f, 0.0f ,
 0.0f, 1.0f ,
 1.0f, 1.0f ,
 1.0f, 0.0f ,
 1.0f, 1.0f ,
 1.0f, 0.0f ,
 0.0f, 0.0f ,
 0.0f, 1.0f ,
 0.0f, 1.0f ,
 1.0f, 1.0f ,
 1.0f, 0.0f ,
 0.0f, 0.0f ,
 0.0f, 0.0f ,
 0.0f, 1.0f ,
 1.0f, 1.0f ,
 1.0f, 0.0f ,
 1.0f, 0.0f ,
 0.0f, 0.0f ,
 0.0f, 1.0f ,
 1.0f, 1.0f ,
};
bool playLost=false;
bool playWon=false;
GLuint texture[2];
#define RMAX 6
#define CMAX 10
class Block
{
    public:
        Block();
        char grid[RMAX][CMAX];//grid on which block rolls
        bool single;//whether Block occupies single/two blocks
        bool vertical;//in case of occopying two blocks,layout is vert/horiz?
        int i;//current row of first occupied sq on grid
        int j;//current collumn of first occupied sq on grid
        int gX,gY;
        bool searchFirstO();
        bool searchG();
        bool validMove(int);
        void Print();
};
Block block;
Block::Block()
{
    /*
     * '.'=vacant
     * ' '=hollow
     * 'g'=goal
     * 'o'=occupied
     * */
    single=true;
    char gr[6][10]={'.','.','.',' ',' ',' ',' ',' ',' ',' ',
        '.','o','.','.','.','.',' ',' ',' ',' ',
        '.','.','.','.','.','.','.','.','.',' ',
        ' ','.','.','.','.','.','.','.','.','.',//// this grid has to be generated depending upon level
        ' ',' ',' ',' ',' ','.','.','.','.','.',
        ' ',' ',' ',' ',' ',' ','.','.','.',' ',};
srand ( time(NULL) );
  int X = rand() % 6;
  int Y = rand() % 10;
  gr[X][Y]='g';
    memcpy(grid,gr,60);
    searchG();
}
bool Block::searchFirstO()
{
    for(int i=0;i<6;i++)
        for(int j=0;j<10;j++)
            if(grid[i][j]=='o')
            {
                this->i=i;
                this->j=j;
                return true;
            }
    return false;
}
bool Block::searchG()
{
    for(int i=0;i<6;i++)
        for(int j=0;j<10;j++)
            if(grid[i][j]=='g')
            {
                this->gX=i;
                this->gY=j;
                return true;
            }
    return false;
}
bool Block::validMove(int key )
{
    if(single)//occupies one square
    {
        switch(key)
        {
            case SDLK_LEFT:
                {
                    if(j>1 && (grid[i][j-1]=='.' || grid[i][j-1]=='g') && (grid[i][j-2]=='.' || grid[i][j-2]=='g') )
                    {
                        grid[i][j]='.';
                            grid[i][j-1]='o';
                            grid[i][j-2]='o';
                        vertical=false;
                        single=false;
                        return true;
                    }
                    else
                    {
                        grid[i][j]='x';
                        return false;
                    }
                }
                break;
            case SDLK_RIGHT:
                {
                    if(j<CMAX-2 && (grid[i][j+1]=='.' || grid[i][j+1]=='g') && (grid[i][j+2]=='.' || grid[i][j+2]=='g' ) )
                    {
                        grid[i][j]='.';
                            grid[i][j+1]='o';
                            grid[i][j+2]='o';
                        vertical=false;
                        single=false;
                        return true;
                    }
                    else
                    {
                        grid[i][j]='x';
                        return false;
                    }
                }
                break;
            case SDLK_UP:
                {
                    if(i>1 && (grid[i-1][j]=='.' || grid[i-1][j]=='g') && (grid[i-2][j]=='.' || grid[i-2][j]=='g')  )
                    {
                        grid[i][j]='.';
                            grid[i-1][j]='o';
                            grid[i-2][j]='o';
                        vertical=true;
                        single=false;
                        return true;
                    }
                    else
                    {
                        grid[i][j]='x';
                        return false;
                    }
                }
                break;
            case SDLK_DOWN:
                {
                    if(i<RMAX-2 && (grid[i+1][j]=='.' || grid[i+1][j]=='g') && (grid[i+2][j]=='.' || grid[i+2][j]=='g' ))
                    {
                        grid[i][j]='.';
                        grid[i+1][j]='o';
                        grid[i+2][j]='o';
                        vertical=true;
                        single=false;
                        return true;
                    }
                    else
                    {
                        grid[i][j]='x';
                        return false;
                    }
                }
                break;
        }
    }
    else//occupies two squares
    {
        if(vertical)//vertical layout
        {
            switch(key)
            {
                case SDLK_LEFT:
                    {
                        if(j>0 && i<RMAX-1 && (grid[i][j-1]=='.' || grid[i][j-1]=='g') && (grid[i+1][j-1]=='.' || grid[i+1][j-1]=='g'))
                        {
                            grid[i][j]='.';
                            grid[i+1][j]='.';
                            grid[i][j-1]='o';
                            grid[i+1][j-1]='o';
                            vertical=true;
                            return true;
                        }
                        else
                        {
                            grid[i][j]='x';
                            return false;
                        }
                    }
                    break;
                case SDLK_RIGHT:
                    {
if(j<CMAX-1 && i<RMAX-1 && (grid[i][j+1]=='.' || grid[i][j+1]=='g') && (grid[i+1][j+1]=='.' || grid[i+1][j+1]=='g'))
                        {
                            grid[i][j]='.';
                            grid[i+1][j]='.';
                            grid[i][j+1]='o';
                            grid[i+1][j+1]='o';
                            vertical=true;
                            return true;
                        }
                        else
                        {
                            grid[i][j]='x';
                            return false;
                        }
                    }
                    break;
                case SDLK_UP:
                    {
                        if(i>0 &&  grid[i-1][j]=='g')//winning conditon
                        {
                            grid[i][j]='.';
                            grid[i+1][j]='.';
                            grid[i-1][j]='w';
                            return true;
                        }
                        if(i>0 && grid[i-1][j]=='.' )
                        {
                            grid[i][j]='.';
                            grid[i+1][j]='.';
                            grid[i-1][j]='o';
                            single=true;
                            return true;
                        }
                        else
                        {
                            grid[i][j]='x';
                            grid[i+1][j]='x';
                            return false;
                        }
                    }
                    break;
                case SDLK_DOWN:
                    {
                        if(i<RMAX-1 &&  grid[i+2][j]=='g')//wining condition
                        {
                            grid[i][j]='.';
                            grid[i+1][j]='.';
                            grid[i+2][j]='w';
                            return true;
                        }
                        if(i<RMAX-1 && grid[i+2][j]=='.' )
                        {
                            grid[i][j]='.';
                            grid[i+1][j]='.';
                            grid[i+2][j]='o';
                            single=true;
                            return true;
                        }
                        else
                        {
                            grid[i][j]='x';
                            grid[i+1][j]='x';
                            return false;
                        }
                    }
                    break;
            }
        }
        else//horizontal layout
        {
            switch(key)
            {
                case SDLK_LEFT:
                    {
                        if(j>0 && grid[i][j-1]=='g' )//winning condition
                        {
                            grid[i][j]='.';
                            grid[i][j+1]='.';
                            grid[i][j-1]='w';
                            return true;
                        }
                        if(j>0 && grid[i][j-1]=='.' )
                        {
                            grid[i][j]='.';
                            grid[i][j+1]='.';
                            grid[i][j-1]='o';
                            single=true;
                            return true;
                        }
                        else
                        {
                            grid[i][j]='x';
                            grid[i][j+1]='x';
                            return false;
                        }
                    }
                    break;
                case SDLK_RIGHT:
                    {
                        if(j<CMAX-2 && grid[i][j+2]=='g' )//winning condition
                        {
                            grid[i][j]='.';
                            grid[i][j+1]='.';
                            grid[i][j+2]='w';
                            return true;
                        }
                        if(j<CMAX-2 && grid[i][j+2]=='.' )
                        {
                            grid[i][j]='.';
                            grid[i][j+1]='.';
                            grid[i][j+2]='o';
                            single=true;
                            return true;
                        }
                        else
                        {
                            grid[i][j]='x';
                            grid[i][j+1]='x';
                            return false;
                        }
                    }
                    break;
                case SDLK_UP:
                    {
                        if(i>0 && j<CMAX-1 && (grid[i-1][j]=='.' || grid[i-1][j]=='g') &&( grid[i-1][j+1]=='.' || grid[i-1][j+1]=='g') )
                        {
                            grid[i][j]='.';
                            grid[i][j+1]='.';
                            grid[i-1][j]='o';
                            grid[i-1][j+1]='o';
                            vertical=false;
                            return true;
                        }
                        else
                        {
                            grid[i][j]='x';
                            grid[i][j+1]='x';
                            return false;
                        }
                    }
                    break;
                case SDLK_DOWN:
                    {
                        if(i<RMAX-1 && j<CMAX-1 && (grid[i+1][j]=='.' || grid[i+1][j]=='g') && (grid[i+1][j+1]=='.' || grid[i+1][j+1]=='g') )
                        {
                            grid[i][j]='.';
                            grid[i][j+1]='.';
                            grid[i+1][j]='o';
                            grid[i+1][j+1]='o';
                            vertical=false;
                            return true;
                        }
                        else
                        {
                            grid[i][j]='x';
                            grid[i][j+1]='x';
                            return false;
                        }
                    }
                    break;
            }
        }
    }
}
void Block::Print()
{
    for(int i=0;i<RMAX;i++)
    {
        for(j=0;j<CMAX;j++)
        {
            cout<<grid[i][j];
        }
        cout<<endl;
    }
}

int initSound()
{
	  
	int audio_rate = 22050;			//Frequency of audio playback
	Uint16 audio_format = AUDIO_S16SYS; 	//Format of the audio we're playing
	int audio_channels = 2;			//2 channels = stereo
	int audio_buffers = 1024;		//Size of the audio buffers in memory
	
	//Initialize SDL_mixer with our chosen audio settings
	if(Mix_OpenAudio(audio_rate, audio_format, audio_channels, audio_buffers) != 0) {
		printf("Unable to initialize audio: %s\n", Mix_GetError());
		exit(1);
	}
	
	//Load our WAV file from disk
	sound = Mix_LoadWAV("ding.wav");
	if(sound == NULL) {
		printf("Unable to load WAV file: %s\n", Mix_GetError());
	}
	sound1 = Mix_LoadWAV("lost.wav");
	if(sound1 == NULL) {
		printf("Unable to load WAV file: %s\n", Mix_GetError());
	}
	sound2 = Mix_LoadWAV("won.wav");
	if(sound2 == NULL) {
		printf("Unable to load WAV file: %s\n", Mix_GetError());
	}
	return 0;
}
int playSound()
{
	channel = Mix_PlayChannel(-1, sound, 0);
	if(channel == -1) {
		printf("Unable to play WAV file: %s\n", Mix_GetError());
	}
	while(Mix_Playing(channel) != 0);
}
int playSoundLost()
{
	channel1 = Mix_PlayChannel(-1, sound1, 0);
	if(channel1 == -1) {
		printf("Unable to play WAV file: %s\n", Mix_GetError());
	}
	while(Mix_Playing(channel1) != 0);
}
int playSoundWon()
{
	channel2 = Mix_PlayChannel(-1, sound2, 0);
	if(channel2 == -1) {
		printf("Unable to play WAV file: %s\n", Mix_GetError());
	}
	while(Mix_Playing(channel2) != 0);
}

////GAME logic ENDS and OpenGL logic Begins

#define SCREEN_WIDTH  600
#define SCREEN_HEIGHT 600
#define SCREEN_BPP     16

#define TRUE  1
#define FALSE 0

SDL_Surface *surface;

void Quit( int returnCode )
{
    SDL_Quit( );

	Mix_FreeChunk(sound);
	Mix_FreeChunk(sound1);
	Mix_FreeChunk(sound2);
	
	Mix_CloseAudio();
    exit( returnCode );
}


int LoadGLTextures( )
{
    int Status = FALSE;

    SDL_Surface *TextureImage[2]; 

    if ( ( TextureImage[0] = SDL_LoadBMP( "tile6.bmp" ) ) )
        {

	    Status = TRUE;

	    glGenTextures( 1, &texture[0] );

	    glBindTexture( GL_TEXTURE_2D, texture[0] );

	    glTexImage2D( GL_TEXTURE_2D, 0, 3, TextureImage[0]->w,
			  TextureImage[0]->h, 0, GL_BGR,
			  GL_UNSIGNED_BYTE, TextureImage[0]->pixels );

	    glTexParameteri( GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR );
	    glTexParameteri( GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR );
        }

    if ( ( TextureImage[1] = SDL_LoadBMP( "tile4.bmp" ) ) )
        {

	    Status = TRUE;

	    glGenTextures( 2, &texture[1] );

	    glBindTexture( GL_TEXTURE_2D, texture[1] );

	    glTexImage2D( GL_TEXTURE_2D, 0, 3, TextureImage[0]->w,
			  TextureImage[0]->h, 0, GL_BGR,
			  GL_UNSIGNED_BYTE, TextureImage[1]->pixels );

	    glTexParameteri( GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR );
	    glTexParameteri( GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR );
        }
    if ( TextureImage[0] )
	    SDL_FreeSurface( TextureImage[0] );
    if ( TextureImage[1] )
	    SDL_FreeSurface( TextureImage[1] );

    return Status;
}

int resizeWindow( int width, int height )
{
    GLfloat ratio;

    if ( height == 0 )
        height = 1;

    RATIO=ratio = ( GLfloat )width / ( GLfloat )height;

    glViewport( 0, 0, ( GLsizei )width, ( GLsizei )height );

    glMatrixMode( GL_PROJECTION );
    glLoadIdentity( );

    //gluPerspective( 45.0f, ratio, 0.1f, 100.0f );
    //glOrtho(-50,50,-50,50,-50,50);
        glOrtho(-15,15,-15,15,-100,100);

    glMatrixMode( GL_MODELVIEW );

    glLoadIdentity( );

    return( TRUE );
}

/* function to handle mouse move events */
void handleMouseMove(int xrel,int yrel,int x,int y)
{
    cameraAngleX+=y-mouseY;
    cameraAngleY+=x-mouseX;
    mouseX=x;
    mouseY=y;
}
/* function to handle mouse press events */
void handleMousePress(int down,int button,int x,int y)
{
    mouseX=x;
    mouseY=y;
    if(down && button==1)
        buttonPressed=true;
    else
        buttonPressed=false;
}
/* function to handle key press events */
    static bool restart=false;
void handleKeyPress( SDL_keysym *keysym )
{
    if(restart && keysym->sym == SDLK_SPACE)
    {
        block=Block();
        cubeX=cubeY=cubeZ=0.0;
        translateZ=translateY=translateX=0.0;
        single=true;
        vert=horiz=false;
        restart=false;
        show=true;
        Forward=Backward=Left=Right=false;
    }

    switch ( keysym->sym )
    {
        case SDLK_DOWN:
            if (!Forward && !Left && !Right)
                Backward = true;
            break;
        case SDLK_UP:
            if (!Backward && !Left && !Right)
                Forward = true;
            break;
        case SDLK_LEFT:
            if (!Backward && !Forward && !Right)
                Left = true;
            break;
        case SDLK_RIGHT:
            if (!Backward && !Left && !Forward)
                Right = true;
            break;
    }

    switch ( keysym->sym )
    {
        case SDLK_ESCAPE:
            Quit( 0 );
            break;
        case SDLK_F1:
            SDL_WM_ToggleFullScreen( surface );
            break;
        case SDLK_DOWN:
        case SDLK_UP:
        case SDLK_LEFT:
        case SDLK_RIGHT:
            cout<<"\n\n****LEVEL 1 BOARD****\n\n";
            cout<<". represents vacant square;\n";
            cout<<"g represents target/goal square;\n";
            cout<<"o represents occupied square(s);\n\n";
            block.Print();
            if(!restart)
            {
                block.searchFirstO();
                if(block.validMove(keysym->sym))
                {
                    if(block.grid[block.gX][block.gY]=='.' )
                        block.grid[block.gX][block.gY]='g';
                    block.Print();
                    if(!block.searchFirstO())
                    {
                        cout<<"\n You Have Won!!";
                        playWon=true;
                        restart=true;
                    }
                }
                else
                {
                    if(block.grid[block.gX][block.gY]=='.' )
                        block.grid[block.gX][block.gY]='g';
                    block.Print();
                    cout<<"\nYou Lost!!";
                    playLost=true;
                    restart=true;
                }
            }
            break;
    }
    return;
}

void initLights() {
    GLfloat lightKa[] = {.2f, .2f, .2f, 1.0f};  // ambient light
    GLfloat lightKd[] = {.8f, .8f, .8f, 1.0f};  // diffuse light
    GLfloat lightKs[] = {1, 1, 1, 1};           // specular light
    glLightfv(GL_LIGHT0, GL_AMBIENT, lightKa);
    glLightfv(GL_LIGHT0, GL_DIFFUSE, lightKd);
    glLightfv(GL_LIGHT0, GL_SPECULAR, lightKs);

    float lightPos[4] = {0, 0, 20, 1.0}; // positional light
    glLightfv(GL_LIGHT0, GL_POSITION, lightPos);

    glEnable(GL_LIGHT0);  
}
void Init() {

   glClearColor(0.0,0.0,0.0,1.0);
   
   glEnable(GL_DEPTH_TEST);
   glDepthFunc(GL_LEQUAL);

   glShadeModel(GL_SMOOTH);
   glEnableClientState(GL_VERTEX_ARRAY);
   glEnableClientState(GL_TEXTURE_COORD_ARRAY_EXT);
   glEnable(GL_VERTEX_ARRAY);

   initLights();
   glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);

   glVertexPointer(3, GL_FLOAT, 0, cubeVertexS);

}
int initGL( )
{

    if ( !LoadGLTextures( ) )
	return FALSE;
    glEnable(GL_TEXTURE_2D);
    glShadeModel( GL_SMOOTH );

    glClearColor( 0.0f, 0.0f, 0.0f, 0.0f );

    glClearDepth( 1.0f );

    glEnable( GL_DEPTH_TEST );

    glDepthFunc( GL_LEQUAL );

    glHint( GL_PERSPECTIVE_CORRECTION_HINT, GL_NICEST );
Init();



    return( TRUE );
}

void drawCubeVarray() {
    if(horiz)
    {
        glVertexPointer(3, GL_FLOAT, 0, cubeVertexH);
    }
    else if(single) 
    {
        glVertexPointer(3, GL_FLOAT, 0, cubeVertexS);
    }
    else if(vert) 
    {
        glVertexPointer(3, GL_FLOAT, 0, cubeVertexV);
    }

    //FRONT AND BACK
   glColor4f(1.0f, 1.0f, 1.0f, 1.0f);
   glDrawArrays(GL_TRIANGLE_STRIP, 0, 4);
   glDrawArrays(GL_TRIANGLE_STRIP, 4, 4);

   //LEFT AND RIGHT
   glDrawArrays(GL_TRIANGLE_STRIP, 8, 4);
   glDrawArrays(GL_TRIANGLE_STRIP, 12, 4);

   //TOP AND BOTTOM
   glDrawArrays(GL_TRIANGLE_STRIP, 16, 4);
   glDrawArrays(GL_TRIANGLE_STRIP, 20, 4);
}

void DrawBlock(void) {
   glPushMatrix();
   glRotatef(90,1,0,0);
      glTranslatef(4.0, 1, -8);          
   usleep(1000);
      //set the block pos
      glTranslatef(cubeX, cubeY, cubeZ);          
      
      //apply cube transfor
      if (Forward) {
          if(horiz)
          {
              translateY=-translate;
              translateZ=-translate;
          }
          else if(vert)
          {
              translateY=-translate;
              translateZ=-translate-0.5;
          }
          else if(single) 
          {
              translateY=-translate-0.5;
              translateZ=-translate;
          }
        angleX -= 5;
          glTranslatef(translateX, translateY, translateZ);
      }
      else
      if (Backward) {
          if(horiz)
          {
              translateY=-translate;
              translateZ=+translate;
          }
          else if(vert)
          {
              translateY=-translate;
              translateZ=translate+0.5;
          }
          else if(single) 
          {
              translateY=-translate-0.5;
              translateZ=+translate;
          }
          angleX += 5;
          glTranslatef(translateX, translateY, translateZ);
      }
      if (Right) {
          if(horiz)
          {
              translateX=translate+0.5;
              translateY=-translate;
          }
          else if(vert)
          {
              translateX=translate;
              translateY=-translate;
          }
          else if(single) 
          {
              translateX=translate;
              translateY=-translate-0.5;
          }
          angleZ -= 5;
          glTranslatef(translateX, translateY, 0.0f);
      } 
      else
      if (Left) {
          if(horiz)
          {
              translateX=-translate-0.5;
              translateY=-translate;
          }
          else if(vert)
          {
              translateX=-translate;
              translateY=-translate;
          }
          else if(single) 
          {
              translateX=-translate;
              translateY=-translate-0.5;
          }
        angleZ += 5;
          glTranslatef(translateX, translateY, 0.0f);
      }

      if(Forward||Backward||Left||Right)
      {
      glRotatef(angleX, 1, 0.0f, 0.0f); 
      glRotatef(angleY, 0.0f, 1, 0.0f);
      glRotatef(angleZ, 0.0f, 0.0f, 1);
      }
      if (Forward) {
          glTranslatef(-translateX, -translateY, -translateZ);
          if (angleX <= -90.0f) {
            angleX = 0.0f;
            if(horiz)
            {
                cubeZ +=-stpSz;
            }
            else if(vert)
            {
                cubeY += translate;
                cubeZ +=-stpSz-translate;
                vert=false;
                single=true;
            }
            else if(single) 
            {
                cubeY += -translate;
                cubeZ +=-stpSz-translate;
                single=false;
                vert=true;
            }
            Forward = false;
            if(playLost)
            {
                playSoundLost();
                playLost=false;
            }
            else if(playWon)
            {
                playSoundWon();
                playWon=false;
            }
            else
                playSound();
            if(restart)
                show=false;
          }
      }
      else
      if (Backward) {
          glTranslatef(-translateX, -translateY, -translateZ);
          if (angleX >= 90.0f) {
            angleX = 0.0f;
            if(horiz)
            {
                cubeZ +=stpSz;
            }
            else if(vert)
            {
                cubeY += translate;
                cubeZ +=stpSz+translate;
                vert=false;
                single=true;
            }
            else if(single) 
            {
                cubeY += -translate;
                cubeZ +=stpSz+translate;
                vert=true;
                single=false;
            }
            Backward = false;
            if(playLost)
            {
                playSoundLost();
                playLost=false;
            }
            else if(playWon)
            {
                playSoundWon();
                playWon=false;
            }
            else
                playSound();
            if(restart)
                show=false;
          }
      }
      if (Right) {
          glTranslatef(-translateX, -translateY, 0.0f);
          if (angleZ <= -90.0f) {
            angleZ = 0.0f;
            if(horiz)
            {
                cubeX +=stpSz+translate;
                cubeY +=translate;
                single=true;
                horiz=false;
            }
            else if(vert)
            {
                cubeX += stpSz;

            }
            else if(single) 
            {
                cubeX += stpSz+translate;
                cubeY +=-translate;
                single=false;
                horiz=true;
            }
            Right = false;
            if(playLost)
            {
                playSoundLost();
                playLost=false;
            }
            else if(playWon)
            {
                playSoundWon();
                playWon=false;
            }
            else
                playSound();
            if(restart)
                show=false;
          }
      }
      else
      if (Left) {
          glTranslatef(-translateX, -translateY, 0.0f);
          if (angleZ >= 90.0f) {
            angleZ = 0.0f;
            if(horiz)
            {
                cubeX +=-stpSz-translate;
                cubeY +=translate;
                single=true;
                horiz=false;
            }
            else if(vert)
            {
                cubeX+=-stpSz;
            }
            else if(single) 
            {
                cubeX += -stpSz-translate;
                cubeY +=-translate;
                single=false;
                horiz=true;
            }
            Left = false;
            if(playLost)
            {
                playSoundLost();
                playLost=false;
            }
            else if(playWon)
            {
                playSoundWon();
                playWon=false;
            }
            else
                playSound();
            if(restart)
                show=false;
          }
      }
      
   drawCubeVarray();
   glPopMatrix();
}


int drawGLScene( )
{
    bool lost=false;
    bool won=false;
    if(buttonPressed)
    {
        glMatrixMode( GL_PROJECTION );
        glLoadIdentity( );

        //gluPerspective( 45.0f, RATIO, 0.1f, 100.0f );
        glOrtho(-15,15,-15,15,-10,10);
        glRotatef(cameraAngleX, 1, 0, 0);   // pitch
        glRotatef(cameraAngleY, 0, 1, 0);   // heading

        glMatrixMode( GL_MODELVIEW );

        glLoadIdentity( );
    }


    SDL_Color color;
    color.r = 255;
    color.g = 255;
    color.b = 255;
    SDL_Rect position;
    position.x=SCREEN_WIDTH/2;
    position.x=SCREEN_WIDTH/2;
    position.x=0;
    position.y=10;
    static GLint T0     = 0;
    static GLint Frames = 0;

    glClear( GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT );

    glLoadIdentity();



    glTranslatef( -10.0f, 8.0f, 0.0f );
    for(int i=0;i<6;i++ )
    {
        glTranslatef( 0.0, -2.01, 0.0f );
        glPushMatrix();
        for(int j=0;j<10;j++)
        {
                glTranslatef( 2.01, 0.0, 0.0f );
                int blk_ht=1;
            switch(block.grid[i][j])//this switch case renders the block and the grid using GL_QUADS depending upon grid[][]
            {
                case '.'://available square positions
                    glBindTexture( GL_TEXTURE_2D, texture[1] );
                    glPushMatrix();
                    glTranslatef(0.0,0.0,-1.0);
                    glColor3f(0.5,0.5,0.5);
                    glBegin( GL_QUADS );                /* Draw A Quad */

                     glTexCoord2f( 0.0f, 1.0f );
                     glVertex3f(  1.0f,  1.0f, -0.2f ); /* Top Right Of The Quad (Top)      */
                     glTexCoord2f( 1.0f, 1.0f );
                     glVertex3f( -1.0f,  1.0f, -0.2f ); /* Top Left Of The Quad (Top)       */
                     glTexCoord2f( 1.0f, 0.0f ); 
                     glVertex3f( -1.0f,  1.0f,  0 ); /* Bottom Left Of The Quad (Top)    */
                     glTexCoord2f( 0.0f, 0.0f );
                     glVertex3f(  1.0f,  1.0f,  0 ); /* Bottom Right Of The Quad (Top)   */

                    //glColor3f(   1.0f,  0.5f,  0.0f ); /* Set The Color To Orange          */
                     glTexCoord2f( 0.0f, 0.0f );
                    glVertex3f(  1.0f, -1.0f,  0 ); /* Top Right Of The Quad (Botm)     */
                     glTexCoord2f( 0.0f, 1.0f );
                    glVertex3f( -1.0f, -1.0f,  0 ); /* Top Left Of The Quad (Botm)      */
                     glTexCoord2f( 1.0f, 1.0f );
                    glVertex3f( -1.0f, -1.0f, -0.2f ); /* Bottom Left Of The Quad (Botm)   */
                     glTexCoord2f( 1.0f, 0.0f );
                    glVertex3f(  1.0f, -1.0f, -0.2f ); /* Bottom Right Of The Quad (Botm)  */

                    //glColor3f(   1.0f,  0.0f,  0.0f ); /* Set The Color To Red             */
                     glTexCoord2f( 1.0f, 1.0f );
                    glVertex3f(  1.0f,  1.0f,  0 ); /* Top Right Of The Quad (Front)    */
                     glTexCoord2f( 1.0f, 0.0f );
                    glVertex3f( -1.0f,  1.0f,  0 ); /* Top Left Of The Quad (Front)     */
                     glTexCoord2f( 0.0f, 0.0f );
                    glVertex3f( -1.0f, -1.0f,  0 ); /* Bottom Left Of The Quad (Front)  */
                     glTexCoord2f( 0.0f, 1.0f );
                    glVertex3f(  1.0f, -1.0f,  0 ); /* Bottom Right Of The Quad (Front) */

                    //glColor3f(   1.0f,  1.0f,  0.0f ); /* Set The Color To Yellow          */
                     glTexCoord2f( 0.0f, 1.0f );
                    glVertex3f(  1.0f, -1.0f, -0.2f ); /* Bottom Left Of The Quad (Back)   */
                     glTexCoord2f( 1.0f, 1.0f );
                    glVertex3f( -1.0f, -1.0f, -0.2f ); /* Bottom Right Of The Quad (Back)  */
                     glTexCoord2f( 1.0f, 0.0f );
                    glVertex3f( -1.0f,  1.0f, -0.2f ); /* Top Right Of The Quad (Back)     */
                     glTexCoord2f( 0.0f, 0.0f );
                    glVertex3f(  1.0f,  1.0f, -0.2f ); /* Top Left Of The Quad (Back)      */

                    //glColor3f(   0.0f,  0.0f,  1.0f ); /* Set The Color To Blue            */
                     glTexCoord2f( 0.0f, 0.0f );
                    glVertex3f( -1.0f,  1.0f,  0 ); /* Top Right Of The Quad (Left)     */
                     glTexCoord2f( 0.0f, 1.0f );
                    glVertex3f( -1.0f,  1.0f, -0.2f ); /* Top Left Of The Quad (Left)      */
                     glTexCoord2f( 1.0f, 1.0f );
                    glVertex3f( -1.0f, -1.0f, -0.2f ); /* Bottom Left Of The Quad (Left)   */
                     glTexCoord2f( 1.0f, 0.0f );
                    glVertex3f( -1.0f, -1.0f,  0 ); /* Bottom Right Of The Quad (Left)  */

                    //glColor3f(   1.0f,  0.0f,  1.0f ); /* Set The Color To Violet          */
                     glTexCoord2f( 1.0f, 0.0f );
                    glVertex3f(  1.0f,  1.0f, -0.2f ); /* Top Right Of The Quad (Right)    */
                     glTexCoord2f( 0.0f, 0.0f );
                    glVertex3f(  1.0f,  1.0f,  0 ); /* Top Left Of The Quad (Right)     */
                     glTexCoord2f( 0.0f, 1.0f );
                    glVertex3f(  1.0f, -1.0f,  0 ); /* Bottom Left Of The Quad (Right)  */
                     glTexCoord2f( 1.0f, 1.0f );
                    glVertex3f(  1.0f, -1.0f, -0.2f ); /* Bottom Right Of The Quad (Right) */
                    
                    glEnd( );                           /* Done Drawing The Quad */
                    glPopMatrix();
                    break;
                case 'w'://wining Square
                    glPushMatrix();
                    glTranslatef(0.0,0.0,-1.0);
                    glColor3f(0.0,1.0,0.0);
                    glBegin( GL_QUADS );                /* Draw A Quad */
                    glVertex3f( -1.0f,  1.0f, 0.0f ); /* Top Left */
                    glVertex3f(  1.0f,  1.0f, 0.0f ); /* Top Right */
                    glVertex3f(  1.0f, -1.0f, 0.0f ); /* Bottom Right */
                    glVertex3f( -1.0f, -1.0f, 0.0f ); /* Bottom Left */
                    glEnd( );                           /* Done Drawing The Quad */
                    glPopMatrix();
                    won=true;
                    break;
                case 'o'://occupied square(s) by the block
                    if(!(i==block.gX && j==block.gY))
                    {
                        glBindTexture( GL_TEXTURE_2D, texture[1] );
                        glPushMatrix();
                        glTranslatef(0.0,0.0,-1.0);
                        glColor3f(0.5,0.5,0.5);
                        glBegin( GL_QUADS );                /* Draw A Quad */

                        glTexCoord2f( 0.0f, 1.0f );
                        glVertex3f(  1.0f,  1.0f, -0.2f ); /* Top Right Of The Quad (Top)      */
                        glTexCoord2f( 1.0f, 1.0f );
                        glVertex3f( -1.0f,  1.0f, -0.2f ); /* Top Left Of The Quad (Top)       */
                        glTexCoord2f( 1.0f, 0.0f ); 
                        glVertex3f( -1.0f,  1.0f,  0 ); /* Bottom Left Of The Quad (Top)    */
                        glTexCoord2f( 0.0f, 0.0f );
                        glVertex3f(  1.0f,  1.0f,  0 ); /* Bottom Right Of The Quad (Top)   */

                        //glColor3f(   1.0f,  0.5f,  0.0f ); /* Set The Color To Orange          */
                        glTexCoord2f( 0.0f, 0.0f );
                        glVertex3f(  1.0f, -1.0f,  0 ); /* Top Right Of The Quad (Botm)     */
                        glTexCoord2f( 0.0f, 1.0f );
                        glVertex3f( -1.0f, -1.0f,  0 ); /* Top Left Of The Quad (Botm)      */
                        glTexCoord2f( 1.0f, 1.0f );
                        glVertex3f( -1.0f, -1.0f, -0.2f ); /* Bottom Left Of The Quad (Botm)   */
                        glTexCoord2f( 1.0f, 0.0f );
                        glVertex3f(  1.0f, -1.0f, -0.2f ); /* Bottom Right Of The Quad (Botm)  */

                        //glColor3f(   1.0f,  0.0f,  0.0f ); /* Set The Color To Red             */
                        glTexCoord2f( 1.0f, 1.0f );
                        glVertex3f(  1.0f,  1.0f,  0 ); /* Top Right Of The Quad (Front)    */
                        glTexCoord2f( 1.0f, 0.0f );
                        glVertex3f( -1.0f,  1.0f,  0 ); /* Top Left Of The Quad (Front)     */
                        glTexCoord2f( 0.0f, 0.0f );
                        glVertex3f( -1.0f, -1.0f,  0 ); /* Bottom Left Of The Quad (Front)  */
                        glTexCoord2f( 0.0f, 1.0f );
                        glVertex3f(  1.0f, -1.0f,  0 ); /* Bottom Right Of The Quad (Front) */

                        //glColor3f(   1.0f,  1.0f,  0.0f ); /* Set The Color To Yellow          */
                        glTexCoord2f( 0.0f, 1.0f );
                        glVertex3f(  1.0f, -1.0f, -0.2f ); /* Bottom Left Of The Quad (Back)   */
                        glTexCoord2f( 1.0f, 1.0f );
                        glVertex3f( -1.0f, -1.0f, -0.2f ); /* Bottom Right Of The Quad (Back)  */
                        glTexCoord2f( 1.0f, 0.0f );
                        glVertex3f( -1.0f,  1.0f, -0.2f ); /* Top Right Of The Quad (Back)     */
                        glTexCoord2f( 0.0f, 0.0f );
                        glVertex3f(  1.0f,  1.0f, -0.2f ); /* Top Left Of The Quad (Back)      */

                        //glColor3f(   0.0f,  0.0f,  1.0f ); /* Set The Color To Blue            */
                        glTexCoord2f( 0.0f, 0.0f );
                        glVertex3f( -1.0f,  1.0f,  0 ); /* Top Right Of The Quad (Left)     */
                        glTexCoord2f( 0.0f, 1.0f );
                        glVertex3f( -1.0f,  1.0f, -0.2f ); /* Top Left Of The Quad (Left)      */
                        glTexCoord2f( 1.0f, 1.0f );
                        glVertex3f( -1.0f, -1.0f, -0.2f ); /* Bottom Left Of The Quad (Left)   */
                        glTexCoord2f( 1.0f, 0.0f );
                        glVertex3f( -1.0f, -1.0f,  0 ); /* Bottom Right Of The Quad (Left)  */

                        //glColor3f(   1.0f,  0.0f,  1.0f ); /* Set The Color To Violet          */
                        glTexCoord2f( 1.0f, 0.0f );
                        glVertex3f(  1.0f,  1.0f, -0.2f ); /* Top Right Of The Quad (Right)    */
                        glTexCoord2f( 0.0f, 0.0f );
                        glVertex3f(  1.0f,  1.0f,  0 ); /* Top Left Of The Quad (Right)     */
                        glTexCoord2f( 0.0f, 1.0f );
                        glVertex3f(  1.0f, -1.0f,  0 ); /* Bottom Left Of The Quad (Right)  */
                        glTexCoord2f( 1.0f, 1.0f );
                        glVertex3f(  1.0f, -1.0f, -0.2f ); /* Bottom Right Of The Quad (Right) */

                        glEnd( );                           /* Done Drawing The Quad */
                        glPopMatrix();
                    }
                    break;
                case 'g':
                       glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);
                       glPushMatrix();
                       glTranslatef(0,0,-1);
                       glColor3f(0.0,1.0,0.0);
                       glBegin(GL_QUADS);
                       glVertex3f( -1.0f,  1.0f, 0.0f ); /* Top Left */
                       glVertex3f(  1.0f,  1.0f, 0.0f ); /* Top Right */
                       glVertex3f(  1.0f, -1.0f, 0.0f ); /* Bottom Right */
                       glVertex3f( -1.0f, -1.0f, 0.0f ); /* Bottom Left */
                       glEnd();
                       glPopMatrix();
                       glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);
                    break;
                case 'x':
                    glBindTexture( GL_TEXTURE_2D, texture[1] );
                    glPushMatrix();
                    glTranslatef(0.0,0.0,-1.0);
                    glColor3f(0.5,0.5,0.5);
                    glBegin( GL_QUADS );                /* Draw A Quad */

                     glTexCoord2f( 0.0f, 1.0f );
                     glVertex3f(  1.0f,  1.0f, -0.2f ); /* Top Right Of The Quad (Top)      */
                     glTexCoord2f( 1.0f, 1.0f );
                     glVertex3f( -1.0f,  1.0f, -0.2f ); /* Top Left Of The Quad (Top)       */
                     glTexCoord2f( 1.0f, 0.0f ); 
                     glVertex3f( -1.0f,  1.0f,  0 ); /* Bottom Left Of The Quad (Top)    */
                     glTexCoord2f( 0.0f, 0.0f );
                     glVertex3f(  1.0f,  1.0f,  0 ); /* Bottom Right Of The Quad (Top)   */

                    //glColor3f(   1.0f,  0.5f,  0.0f ); /* Set The Color To Orange          */
                     glTexCoord2f( 0.0f, 0.0f );
                    glVertex3f(  1.0f, -1.0f,  0 ); /* Top Right Of The Quad (Botm)     */
                     glTexCoord2f( 0.0f, 1.0f );
                    glVertex3f( -1.0f, -1.0f,  0 ); /* Top Left Of The Quad (Botm)      */
                     glTexCoord2f( 1.0f, 1.0f );
                    glVertex3f( -1.0f, -1.0f, -0.2f ); /* Bottom Left Of The Quad (Botm)   */
                     glTexCoord2f( 1.0f, 0.0f );
                    glVertex3f(  1.0f, -1.0f, -0.2f ); /* Bottom Right Of The Quad (Botm)  */

                    //glColor3f(   1.0f,  0.0f,  0.0f ); /* Set The Color To Red             */
                     glTexCoord2f( 1.0f, 1.0f );
                    glVertex3f(  1.0f,  1.0f,  0 ); /* Top Right Of The Quad (Front)    */
                     glTexCoord2f( 1.0f, 0.0f );
                    glVertex3f( -1.0f,  1.0f,  0 ); /* Top Left Of The Quad (Front)     */
                     glTexCoord2f( 0.0f, 0.0f );
                    glVertex3f( -1.0f, -1.0f,  0 ); /* Bottom Left Of The Quad (Front)  */
                     glTexCoord2f( 0.0f, 1.0f );
                    glVertex3f(  1.0f, -1.0f,  0 ); /* Bottom Right Of The Quad (Front) */

                    //glColor3f(   1.0f,  1.0f,  0.0f ); /* Set The Color To Yellow          */
                     glTexCoord2f( 0.0f, 1.0f );
                    glVertex3f(  1.0f, -1.0f, -0.2f ); /* Bottom Left Of The Quad (Back)   */
                     glTexCoord2f( 1.0f, 1.0f );
                    glVertex3f( -1.0f, -1.0f, -0.2f ); /* Bottom Right Of The Quad (Back)  */
                     glTexCoord2f( 1.0f, 0.0f );
                    glVertex3f( -1.0f,  1.0f, -0.2f ); /* Top Right Of The Quad (Back)     */
                     glTexCoord2f( 0.0f, 0.0f );
                    glVertex3f(  1.0f,  1.0f, -0.2f ); /* Top Left Of The Quad (Back)      */

                    //glColor3f(   0.0f,  0.0f,  1.0f ); /* Set The Color To Blue            */
                     glTexCoord2f( 0.0f, 0.0f );
                    glVertex3f( -1.0f,  1.0f,  0 ); /* Top Right Of The Quad (Left)     */
                     glTexCoord2f( 0.0f, 1.0f );
                    glVertex3f( -1.0f,  1.0f, -0.2f ); /* Top Left Of The Quad (Left)      */
                     glTexCoord2f( 1.0f, 1.0f );
                    glVertex3f( -1.0f, -1.0f, -0.2f ); /* Bottom Left Of The Quad (Left)   */
                     glTexCoord2f( 1.0f, 0.0f );
                    glVertex3f( -1.0f, -1.0f,  0 ); /* Bottom Right Of The Quad (Left)  */

                    //glColor3f(   1.0f,  0.0f,  1.0f ); /* Set The Color To Violet          */
                     glTexCoord2f( 1.0f, 0.0f );
                    glVertex3f(  1.0f,  1.0f, -0.2f ); /* Top Right Of The Quad (Right)    */
                     glTexCoord2f( 0.0f, 0.0f );
                    glVertex3f(  1.0f,  1.0f,  0 ); /* Top Left Of The Quad (Right)     */
                     glTexCoord2f( 0.0f, 1.0f );
                    glVertex3f(  1.0f, -1.0f,  0 ); /* Bottom Left Of The Quad (Right)  */
                     glTexCoord2f( 1.0f, 1.0f );
                    glVertex3f(  1.0f, -1.0f, -0.2f ); /* Bottom Right Of The Quad (Right) */

                    glEnd( );                           /* Done Drawing The Quad */
                    glPopMatrix();
                    lost=true;
                    break;
            }
        }
        glPopMatrix();
    }
    if(show)
    {
        glBindTexture( GL_TEXTURE_2D, texture[0] );
        glTexCoordPointer(2, GL_FLOAT, 0, texVertices);
        DrawBlock();
    }
    if(lost)
    {
        glEnable2D();
        SDL_GL_RenderText("You Lost!! Press spacebar to restart this Level", font, color, &position);
        glDisable2D();
        lost=false;
    }
    if(won)
    {
        glEnable2D();
        SDL_GL_RenderText("You Won!! Press sbacebar to restart this Level", font, color, &position);
        glDisable2D();
        won=false;
    }
    SDL_GL_SwapBuffers( );
    return( TRUE );
}

int main( int argc, char **argv )
{
    if(TTF_Init())
        return 0;
    atexit(TTF_Quit);

    if(!(font = TTF_OpenFont(fontpath, 20))) {
        printf("Error loading font: %s", TTF_GetError());
        return 1;
    }

    /* Flags to pass to SDL_SetVideoMode */
    int videoFlags;
    /* main loop variable */
    int done = FALSE;
    /* used to collect events */
    SDL_Event event;
    /* this holds some info about our display */
    const SDL_VideoInfo *videoInfo;
    /* whether or not the window is active */
    int isActive = TRUE;

    /* initialize SDL */
    if ( SDL_Init( SDL_INIT_VIDEO | SDL_INIT_AUDIO) < 0 )
    {
        fprintf( stderr, "Video initialization failed: %s\n",
                SDL_GetError( ) );
        Quit( 1 );
    }

    /* Fetch the video info */
    videoInfo = SDL_GetVideoInfo( );

    if ( !videoInfo )
    {
        fprintf( stderr, "Video query failed: %s\n",
                SDL_GetError( ) );
        Quit( 1 );
    }

    /* the flags to pass to SDL_SetVideoMode */
    videoFlags  = SDL_OPENGL;          /* Enable OpenGL in SDL */
    videoFlags |= SDL_GL_DOUBLEBUFFER; /* Enable double buffering */
    videoFlags |= SDL_HWPALETTE;       /* Store the palette in hardware */
    videoFlags |= SDL_RESIZABLE;       /* Enable window resizing */

    /* This checks to see if surfaces can be stored in memory */
    if ( videoInfo->hw_available )
        videoFlags |= SDL_HWSURFACE;
    else
        videoFlags |= SDL_SWSURFACE;

    /* This checks if hardware blits can be done */
    if ( videoInfo->blit_hw )
        videoFlags |= SDL_HWACCEL;

    /* Sets up OpenGL double buffering */
    SDL_GL_SetAttribute( SDL_GL_DOUBLEBUFFER, 1 );

    /* get a SDL surface */
    surface = SDL_SetVideoMode( SCREEN_WIDTH, SCREEN_HEIGHT, SCREEN_BPP,
            videoFlags );
    SDL_WM_SetCaption("Block Game", 0);

    /* Verify there is a surface */
    if ( !surface )
    {
        fprintf( stderr,  "Video mode set failed: %s\n", SDL_GetError( ) );
        Quit( 1 );
    }
initSound();
    initGL( );

    resizeWindow( SCREEN_WIDTH, SCREEN_HEIGHT );

    while ( !done )
    {
        /* handle the events in the queue */

        while ( SDL_PollEvent( &event ) )
        {
            switch( event.type )
            {
                case SDL_ACTIVEEVENT:
                    /* Something's happend with our focus
                     * If we lost focus or we are iconified, we
                     * shouldn't draw the screen
                     */
                    if ( event.active.gain == 0 )
                        isActive = FALSE;
                    else
                        isActive = TRUE;
                    break;			    
                case SDL_VIDEORESIZE:
                    /* handle resize event */
                    surface = SDL_SetVideoMode( event.resize.w,
                            event.resize.h,
                            16, videoFlags );
                    if ( !surface )
                    {
                        fprintf( stderr, "Could not get a surface after resize: %s\n", SDL_GetError( ) );
                        Quit( 1 );
                    }
                    resizeWindow( event.resize.w, event.resize.h );
                    break;
                case SDL_KEYDOWN:
                    /* handle key presses */
                    handleKeyPress( &event.key.keysym );
                    break;
                case SDL_MOUSEMOTION:
//          printf("Mouse moved by %d,%d to (%d,%d)\n",event.motion.xrel, event.motion.yrel,event.motion.x, event.motion.y);
                    handleMouseMove(event.motion.xrel,event.motion.yrel,event.motion.x,event.motion.y) ;
                    break;
                case SDL_MOUSEBUTTONDOWN:
//                    printf("Mouse button %d pressed at (%d,%d)\n",event.button.button, event.button.x, event.button.y);
                        handleMousePress(1,event.button.button,event.button.x,event.button.y);                    
                    break;
                case SDL_MOUSEBUTTONUP:
//                    printf("Mouse button %d pressed at (%d,%d)\n",event.button.button, event.button.x, event.button.y);
                        handleMousePress(0,event.button.button,event.button.x,event.button.y);                    
                    break;
                case SDL_QUIT:
                    /* handle quit requests */
                    done = TRUE;
                    break;
                default:
                    break;
            }
        }

        if ( isActive )
            drawGLScene( );
    }

    Quit( 0 );

    return( 0 );
}
