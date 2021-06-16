#include <stdio.h>
#include <stdlib.h>


//Les structures
typedef struct Element Element;
struct Element{

    char* str_chaine;                                   //Les éléments de la file seront des chaînes de caractères
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
void enfile(File *file, char* str_newChaine);
int defile(File *file);
void afficheFile(File *file);
void tailleElement(File* file);
void premierElement(File *file);
void dernierElement(File *file);

int main()
{
    File *file = NULL;
    file = (File*)malloc(sizeof(File));

    File* maFile = initialise();                        //Ma file est créer

    enfile(maFile, "Mario");                            //On remplit cette file
    enfile(maFile, "Sonic");
    enfile(maFile, "Rayman");
    enfile(maFile, "Megaman");
    enfile(maFile, "Banjoo");
    enfile(maFile, "Pacman");

    printf("\nMa file:\n");                             //La taille de la file est afficher
    afficheFile(maFile);

    printf("\On defile %s\n", defile(maFile));          //On enlève un élément de la file avec la logique FIFO

    printf("On defile encore %s\n", defile(maFile));    //Encore une fois

    printf("\nMa file actuelle:\n");                    //On réaffiche la file après modification
    afficheFile(maFile);

    tailleElement(maFile);                              //La taille après modifications de la file est afficher

    premierElement(maFile);                             //On affiche le premier élément de la file

    dernierElement(maFile);                             //On affiche le dernier élément de la file

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
void enfile(File *file, char* str_newChaine){

    Element *nouveau = malloc(sizeof(*nouveau));
    if (file == NULL || nouveau == NULL)
    {
        exit(EXIT_FAILURE);
    }

    nouveau->str_chaine = str_newChaine;
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


//Enlève un élément de la file
int defile(File *file){

    if (file == NULL){

        exit(EXIT_FAILURE);
    }

    int nbrFile = 0;


    if (file->premier != NULL)
    {
        Element *elementFile = file->premier;

        nbrFile = elementFile->str_chaine;
        file->premier = elementFile->suivant;
        free(elementFile);
        file->n_taille--;
    }
    return nbrFile;
}



//Affiche la file
void afficheFile(File *file){

    if (file == NULL){

        exit(EXIT_FAILURE);
    }
    Element *actuel = file->premier;

    while (actuel != NULL){

        printf("%s\n", actuel->str_chaine);
        actuel = actuel->suivant;
    }
    printf("\n");
}



//Retourne la taile de la file
void tailleElement(File *file){

    printf("Taille de la file: %d\n", file->n_taille+1);
}



//Consulte le premier élément de la file
void premierElement(File *file){

    Element *element = file->premier;

    if(file->premier != NULL){
        printf("Premier element: %s\n", element->str_chaine);
    }
}



//Consulte le dernier élément de la file
void dernierElement(File *file){

    Element *element = file->dernier;

    if(file->dernier != NULL){
        printf("Dernier element: %s\n", element->str_chaine);
    }
}
