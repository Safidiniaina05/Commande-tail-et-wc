#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "prototype5.h"
#define taille 1000

FILE *openFile (char argv[100])
{
    FILE* fichier=NULL;
    fichier = fopen(argv,"r+");
    if (fichier==NULL)
        {
            perror("Il y a une erreur!!: ");
            exit(1);
        }
    return (fichier);
}

void affichage (FILE *fichier, int n)
{
    int nbLine=1;
    char nomFichier[taille];
    int compteur=1;
    while (feof(fichier)!=1)
        {
           fgets (nomFichier, taille, fichier);
           nbLine++;
        }
    nbLine=nbLine-n;
    rewind(fichier);
    while (feof(fichier)!=1)
        {
            fgets (nomFichier, taille, fichier);
            compteur++;
            if (compteur > nbLine)
                {
                    printf("%s", nomFichier);
                }
        } 
}
FILE *options (int argc, char *argv[])
{
    FILE *fichier=NULL;
    if (strcmp(argv[1],"-n")==0)
    {
        option_n(argv);
    }
    else if (strcmp(argv[1],"-v")==0)
    {
        option_v(argv);
    }
    else if (strcmp(argv[1],"-z")==0)
        {
            option_z(argv);
        }
    else if (strcmp(argv[1],"-q")==0)
        {
            option_q(argv);
        }
    else
        {
            sans_options(argv);
        }
    return (fichier);
}
FILE *option_n (char *argv[])
{
    FILE* fichier=NULL;
    int n;
    fichier = openFile (argv[3]);
    n= atoi(argv[2]);
    affichage (fichier, n);
    return (fichier);
}
FILE *option_v (char *argv[])
{
    int n=10;
    FILE *fichier=NULL;
    fichier = openFile (argv[2]);
    printf("==> %s <==\n", argv[2]);
    affichage(fichier, n);
    return (fichier);
}
FILE *option_z (char *argv[])
{
    FILE *fichier=NULL;
    char name[taille];
    fichier = openFile (argv[2]);
    while (feof(fichier)!=1)
        {
            fgets(name, taille, fichier);
            printf("%s", name);
        }
    return (fichier);
}
FILE *option_q (char *argv[])
{
    int n=10;
    FILE *fichier=NULL;
    fichier = openFile (argv[2]);
    affichage (fichier, n);
    return (fichier);
}
void closing (FILE *fichier)
{
    if (fichier!=NULL)
        {
            fclose(fichier);
        }
}
FILE *sans_options(char *argv[])
{
    int n=10;
    FILE *fichier=NULL;
    fichier = openFile (argv[1]);
    affichage (fichier, n);
    return (fichier);
}