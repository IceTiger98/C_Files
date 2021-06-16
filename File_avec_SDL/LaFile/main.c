#include <stdio.h>
#include <stdlib.h>
#include <SDL2/SDL.h>


//Les structures
typedef struct Element Element;
struct Element{

    SDL_Texture* pTextureImage;                                   //Les éléments de la file seront des images
    Element *suivant;
};

typedef struct File File;
struct File{

    Element *premier;
    Element *dernier;
    int n_taille;
};



//Les prototypes
File* initialise();
void enfile(File *file, SDL_Texture* pTextureImage);
void afficheFile(File *file);


int main( int argc, char *argv[])
{

    int main(int argc, char* argv[])
{

     if (SDL_Init(SDL_INIT_EVERYTHING)!=0)
    {
        SDL_Log("unable to initialize SDL : %s", SDL_GetError());
        return 1;
    }else{
        pWindow = SDL_CreateWindow("an SDL2 window",250,255,WINDOW_WIDTH,WINDOW_HEIGHT,SDL_WINDOW_SHOWN);

        if (pWindow)
        {
            pRenderer = SDL_CreateRenderer(pWindow,-1,SDL_RENDERER_PRESENTVSYNC);
        }
    }

   SDL_Event events;
   SDL_bool isOpen = SDL_TRUE;
   SDL_Texture* pTextureImage= NULL;




    File *file = NULL;
    file = (File*)malloc(sizeof(File));



    SDL_Surface* image = IMG_Load("./assets/Mario.PNG");
    pTextureImage =SDL_CreateTextureFromSurface(pRenderer, image);

    File* maFile = initialise();

    enfile(maFile, pTextureImage);



    image = IMG_Load("./assets/Sonic.PNG")
    pTextureImage =SDL_CreateTextureFromSurface(pRenderer, image);

    enfile(maFile, pTextureImage);

    image = IMG_Load("./assets/Rayman.PNG")
    pTextureImage =SDL_CreateTextureFromSurface(pRenderer, image);

    enfile(maFile, pTextureImage);

    image = IMG_Load("./assets/Megaman.PNG")
    pTextureImage =SDL_CreateTextureFromSurface(pRenderer, image);

    enfile(maFile, pTextureImage);

    image = IMG_Load("./assets/Banjoo.PNG")
    pTextureImage =SDL_CreateTextureFromSurface(pRenderer, image);

    enfile(maFile, pTextureImage);

    image = IMG_Load("./assets/Pacman.PNG")
    pTextureImage =SDL_CreateTextureFromSurface(pRenderer, image);

    enfile(maFile, pTextureImage);


    SDL_FreeSurface(image);


      while (isOpen)
    {
         while (SDL_PollEvent(&events))
        {
            switch (events.type)
            {
            case SDL_QUIT:
                isOpen = SDL_FALSE ;
                break;
            }
        }
       afficheFile(maFile);
    }






	return 0;
}



//Initialisation de la file
File* initialise(){

    File* file = (File*)malloc(sizeof(*file));
    file->premier = NULL;
    file->n_taille = NULL;

    return file;
}


//Insertion d'un élément de la file
void enfile(File *file, SDL_Texture* pTextureImage){

    Element *nouveau = malloc(sizeof(*nouveau));
    if (file == NULL || nouveau == NULL)
    {
        exit(EXIT_FAILURE);
    }

    nouveau->pTextureImage = pTextureImage;
    nouveau->suivant = NULL;


    if (file->premier != NULL){

        Element *elementActuel = file->premier;
        while (elementActuel->suivant != NULL)
        {
            elementActuel = elementActuel->suivant;
            file->dernier = nouveau;
        }
        elementActuel->suivant = nouveau;
        file->n_taille++;
    }
    else
    {
        file->premier = nouveau;
    }
}


//Affiche la file
void afficheFile(File *file){

    if (file == NULL){

        exit(EXIT_FAILURE);
    }

    SDL_SetRenderDrawColor(pRenderer, 255, 255, 255, 255);
    SDL_RenderClear(pRenderer);

	SDL_Rect dst={ 0, 0, 100, 100 };


    Element *actuel = file->premier;

    while (actuel != NULL){

        SDL_RenderCopy(pRenderer, actuel->pTextureImage, NULL,&dst);
        actuel = actuel->suivant;
        dst.y += 100;
    }
    SDL_RenderPresent(pRenderer);
}
