

#include <SDL2/SDL.h>
#include <SDL2_image/SDL_image.h>
#include <stdio.h>
#include <string>
#include <vector>
#include <iostream>
using namespace std;
//Screen dimension constants
const int SCREEN_WIDTH = 1300;
const int SCREEN_HEIGHT = 600;
const int FIGURE_WIDTH = 91;
const int FIGURE_HEIGHT = 91;


//Texture wrapper class
class LTexture
{
public:
    //Initializes variables
    LTexture();
    
    //Deallocates memory
    ~LTexture();
    
    //Loads image at specified path
    bool loadFromFile( std::string path );
    
    //Deallocates texture
    void free();
    
    //Set color modulation
    void setColor( Uint8 red, Uint8 green, Uint8 blue );
    
    //Set blending
    void setBlendMode( SDL_BlendMode blending );
    
    //Set alpha modulation
    void setAlpha( Uint8 alpha );
    
    //Renders texture at given point
    void render( int x, int y, SDL_Rect* clip = NULL );
    
    //Gets image dimensions
    int getWidth();
    int getHeight();
    void setWidth(int);
    void setheight(int);
    
    int getX();
    int getY();
    void setX(int);
    void setY(int);
    
    
private:
    //The actual hardware texture
    SDL_Texture* mTexture;
    
    //Image dimensions
    int mWidth;
    int mHeight;
    int x;
    int y;
};

//Starts up SDL and creates window
bool init();

//Loads media
bool loadMedia();

//Frees media and shuts down SDL
void close();

//The window we'll be rendering to
SDL_Window* gWindow = NULL;

//The window renderer
SDL_Renderer* gRenderer = NULL;

//Images
LTexture gBackground;
LTexture imageForCrop;

SDL_Rect rec;

LTexture::LTexture()
{
    //Initialize
    mTexture = NULL;
    mWidth = 0;
    mHeight = 0;
    x = 0;
    y = 0;
}

LTexture::~LTexture()
{
    //Deallocate
    free();
}

bool LTexture::loadFromFile( std::string path )
{
    //Get rid of preexisting texture
    free();
    
    //The final texture
    SDL_Texture* newTexture = NULL;
    
    //Load image at specified path
    SDL_Surface* loadedSurface = IMG_Load( path.c_str() );
    if( loadedSurface == NULL )
    {
        printf( "Unable to load image %s! SDL_image Error: %s\n", path.c_str(), IMG_GetError() );
    }
    else
    {
        //Color key image
        SDL_SetColorKey( loadedSurface, SDL_TRUE, SDL_MapRGB( loadedSurface->format, 0, 0xff, 0xff ) );
        
        //Create texture from surface pixels
        newTexture = SDL_CreateTextureFromSurface( gRenderer, loadedSurface );
        if( newTexture == NULL )
        {
            printf( "Unable to create texture from %s! SDL Error: %s\n", path.c_str(), SDL_GetError() );
        }
        else
        {
            //Get image dimensions
            mWidth = loadedSurface->w;
            mHeight = loadedSurface->h;
        }
        
        
        
        //Get rid of old loaded surface
        SDL_FreeSurface( loadedSurface );
    }
    
    //Return success
    mTexture = newTexture;
    return mTexture != NULL;
}

void LTexture::free()
{
    //Free texture if it exists
    if( mTexture != NULL )
    {
        SDL_DestroyTexture( mTexture );
        mTexture = NULL;
        mWidth = 0;
        mHeight = 0;
        
        
    }
}

void LTexture::setColor( Uint8 red, Uint8 green, Uint8 blue )
{
    //Modulate texture rgb
    SDL_SetTextureColorMod( mTexture, red, green, blue );
}

void LTexture::setBlendMode( SDL_BlendMode blending )
{
    //Set blending function
    SDL_SetTextureBlendMode( mTexture, blending );
}

void LTexture::setAlpha( Uint8 alpha )
{
    //Modulate texture alpha
    SDL_SetTextureAlphaMod( mTexture, alpha );
}

void LTexture::render( int x, int y, SDL_Rect* clip )
{
    //Set rendering space and render to screen
    SDL_Rect renderQuad = { x, y, mWidth, mHeight };
    
    //Set clip rendering dimensions
    if( clip != NULL )
    {
        renderQuad.w = clip->w;
        renderQuad.h = clip->h;
    }
    
    //Render to screen
    SDL_RenderCopy( gRenderer, mTexture, clip, &renderQuad );
    
}

int LTexture::getWidth()
{
    return mWidth;
}

int LTexture::getHeight()
{
    return mHeight;
}

void LTexture::setWidth( int width)
{
    mWidth = width;
}
void LTexture::setheight(int height)
{
    mHeight = height;
}


int LTexture::getX()
{
    return  x;
}

int LTexture::getY()
{
    return  y;
}

void LTexture::setX(int x_){
    x = x_ ;
}

void LTexture::setY(int y_)
{
    y = y_;
}


//help vectors for function cropImages()

vector<SDL_Rect> v_PullYellow;
vector<SDL_Rect> v_PullGreen;

//TODO: other colors



void pushInVector()
{
    if ( !imageForCrop.loadFromFile( "Roulette3.jpg" ) )
    {
        printf("Failed to load figures");
    }
    else
    {
        //yellow
        rec.x = 500;
        rec.y = 500;
        rec.w = FIGURE_WIDTH;
        rec.h = FIGURE_HEIGHT;
        v_PullYellow.push_back(rec);
        
        //green
        rec.x = 600;
        rec.y = 500;
        rec.w = FIGURE_WIDTH;
        rec.h = FIGURE_HEIGHT;
        v_PullGreen.push_back(rec);
        
        
        //TODO : other colors
        
    }
}

//todo::::add count!!!!!!!
class Point
{
public:
    int X;
    int Y;
    string m_PullColor;
    
    Point()
    {
        X = 0;
        Y = 0;
        m_PullColor = "";
    }
    
    Point(int x, int y, string color)
    {
        X = x;
        Y = y;
        m_PullColor = color;
    }
};

int main( int argc, char* args[] )
{
    //Start up SDL and create window
    if( !init() )
    {
        printf( "Failed to initialize!\n" );
    }
    else
    {
        //Load media
        if( !loadMedia() )
        {
            printf( "Failed to load media!\n" );
        }
        else
        {
            //Main loop flag
            bool quit = false;
            SDL_Event e;
            
            vector<Point> v_coordsAllBetPulls;
            
            vector<Point> v_coordsYellow;
            vector<Point> v_coordsGreen;
            //TODO

            int currentX = 0 ;
            int currentY = 0 ;
            int pullYellow = 0;
            int pullGreen = 0;
            //TODO
            
            
            //While application is running
            while( !quit )
            {
                //Handle events on queue
                while( SDL_PollEvent( &e ) != 0 )
                {
                    
                    
                    //User requests quit
                    if( e.type == SDL_QUIT )
                    {
                        quit = true;
                    }
                    
                    //tuk hvashta mouse click i si zapazvam koordinatite
                    if (e.type == SDL_MOUSEBUTTONDOWN )
                    {
//                        if (e.button.button == SDL_BUTTON_RIGHT)
//                        {
//                            pullYellow = 0 ;
//                            pullGreen = 0 ;
//                        }
                        if (e.button.button == SDL_BUTTON_LEFT)
                        {
                            
                            
                            SDL_GetMouseState(&currentX, &currentY);
                            currentX = e.button.x;
                            currentY = e.button.y;
                            
                            //cout << currentX<< ":" << currentY<<endl;
                            
                            if(pullGreen==0 && pullYellow == 1)
                            {
                              if(currentY<=350)
                              {
                                    Point pYellow(currentX, currentY, "yellow");
                                   // v_coordsYellow.push_back(pYellow);
                                  
                                  //push in main vector
                                    v_coordsAllBetPulls.push_back(pYellow);
                              }
                            }
                            
                            if(pullGreen==1 && pullYellow == 0)
                            {
                                if(currentY <= 350)
                                {
                                    Point pGreen(currentX, currentY, "green");
                                   // v_coordsGreen.push_back(pGreen);
                                    
                                    v_coordsAllBetPulls.push_back(pGreen);
                                    
                                }
                                
                            }

                            //TODO: other ...
                            
                            if(currentX >= 420 && currentX <= 500 && currentY>=490 && currentY<=600)
                            {
                                cout<<"yellow";
                                pullYellow = 1;
                                pullGreen = 0;
                                
                            }
                            
                            if(currentX >= 500 && currentX <= 600 && currentY>=490 && currentY<=600)
                            {
                                cout << "green";
                                pullGreen = 1;
                                pullYellow = 0;
                            }
                            
                            //TOOD: other pull for bet

                        }
                        
                       
                        
                    }
                    
                }
                
                //Clear screen
                SDL_SetRenderDrawColor( gRenderer, 0xff, 0xff, 0xff, 0xff );
                SDL_RenderClear( gRenderer );
                
                
                gBackground.setWidth(1300);
                gBackground.setheight(600);
                //Render background
                gBackground.render( 0, 0, NULL );

                
                
                for(int i=0; i< v_coordsAllBetPulls.size(); i++)
                {
                    if(v_coordsAllBetPulls.at(i).m_PullColor == "yellow")
                    {
                        imageForCrop.render(v_coordsAllBetPulls.at(i).X, v_coordsAllBetPulls.at(i).Y, &v_PullYellow.at(0));
                    }

                    if(v_coordsAllBetPulls.at(i).m_PullColor == "green")
                    {
                        
                        imageForCrop.render(v_coordsAllBetPulls.at(i).X, v_coordsAllBetPulls.at(i).Y, &v_PullGreen.at(0));
                    }

                    
                    //TODO:other ..
                
                }
                
                
                SDL_RenderPresent(gRenderer);
                
            }
            
            
            
            // SDL_RenderCopy()
            SDL_RenderPresent(gRenderer);
            
            
        }
    }
    
    //Free resources and close SDL
    close();
    
    return 0;
}
bool init()
{
    //Initialization flag
    bool success = true;
    
    //Initialize SDL
    if( SDL_Init( SDL_INIT_VIDEO ) < 0 )
    {
        printf( "SDL could not initialize! SDL Error: %s\n", SDL_GetError() );
        success = false;
    }
    else
    {
        //Set texture filtering to linear
        if( !SDL_SetHint( SDL_HINT_RENDER_SCALE_QUALITY, "1" ) )
        {
            printf( "Warning: Linear texture filtering not enabled!" );
        }
        
        //Create window
        gWindow = SDL_CreateWindow( "pepi", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN );
        if( gWindow == NULL )
        {
            printf( "Window could not be created! SDL Error: %s\n", SDL_GetError() );
            success = false;
        }
        else
        {
            //Create vsynced renderer for window
            gRenderer = SDL_CreateRenderer( gWindow, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC );
            if( gRenderer == NULL )
            {
                printf( "Renderer could not be created! SDL Error: %s\n", SDL_GetError() );
                success = false;
            }
            else
            {
                //Initialize renderer color
                SDL_SetRenderDrawColor( gRenderer, 0xFF, 0xFF, 0xFF, 0xFF );
                
                //Initialize PNG loading
                int imgFlags = IMG_INIT_PNG;
                if( !( IMG_Init( imgFlags ) & imgFlags ) )
                {
                    printf( "SDL_image could not initialize! SDL_image Error: %s\n", IMG_GetError() );
                    success = false;
                }
            }
        }
    }
    
    return success;
}

bool loadMedia()
{
    //Loading success flag
    bool success = true;
    
    //Load sprite sheet texture
    if( !gBackground.loadFromFile( "Roulette3.jpg" ) )
    {
        printf( "Failed to load texture!\n" );
        success = false;
    }
    
    if( !imageForCrop.loadFromFile( "Roulette3.jpg" ) )
    {
        printf( "Failed to load texture!\n" );
        success = false;
    }
    else
    {
        pushInVector();
    }
    
    
    return success;
}

void close()
{
    
    gBackground.free();
    imageForCrop.free();
    
    
    //Destroy window
    SDL_DestroyRenderer( gRenderer );
    SDL_DestroyWindow( gWindow );
    gWindow = NULL;
    gRenderer = NULL;
    
    //Quit SDL subsystems
    IMG_Quit();
    SDL_Quit();
}

