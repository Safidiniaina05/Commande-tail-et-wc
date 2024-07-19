#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "prototype5.h"
#define taille 1000

FILE *openFile (char argv[100])
{
    FILE* file=NULL;
    file = fopen(argv,"r+");
    if (file==NULL)
        {
            perror("Il y a une erreur!!: ");
            exit(1);
        }
    return (file);
}
FILE *options(int argc, char *argv[])
{
   FILE *file=NULL;
   if (strcmp(argv[1],"-c")==0||strcmp(argv[1], "-m")==0  )
        {
            option_c(argv);
        }
    else if (strcmp(argv[1], "-w")==0)
        {
        	option_w(argv);
        }
     else if (strcmp(argv[1], "-l")==0)
     	{
     	 	option_l(argv);
     	 }
     else
     	{
     	 sans_option(argv);
     	 }
        return (file);
}
void closing (FILE *fichier)
{
    if (fichier!=NULL)
        {
            fclose(fichier);
        }
}
FILE *option_c (char *argv[])
{
    int caract=0;
    int nb=-1;
    FILE *file=NULL;
    file =openFile (argv[2]);
    while(feof(file)!=1)
        {
            caract= fgetc(file);
            nb++;
        }
    printf("%d %s\n",nb, argv[2]);
    return (file);
}
FILE *option_w (char *argv[])
{
    int n=0;
    char chaine[taille];
    FILE *file=NULL;
    file =openFile (argv[2]);
    while (feof(file)!=1)
        {
            fscanf(file, "%s", chaine);
                    n++;
        }
    printf("%d %s\n", n, argv[2]);
    return (file);
}
FILE *option_l (char *argv[])
{
    int line=-1;
    char chaine[taille];
    FILE *file=NULL;
    file =openFile (argv[2]);	
    while (feof(file)!=1)
        {
        	fgets (chaine, taille, file);
        	line++;
    	}	
    	printf("%d %s\n", line, argv[2]);
    	return (file);
}
FILE *sans_option (char *argv[])
{
    char chaine[taille];
    int line=-1, mot=0, c=0 , caract=-1;
    FILE *file=NULL;
    file =openFile (argv[1]);
    while (feof(file)!=1)
        {
        	fgets (chaine, taille, file);
        	line++;
        }
    rewind(file);
    while (feof(file)!=1)
        {
        	fscanf(file, "%s", chaine);
        	mot++;
        }
    rewind(file);
    while (feof(file)!=1)
        {
        	c = fgetc(file);
        	caract++;
    	}	
    	printf(" %d  %d %d %s\n", line, mot , caract,  argv[1]);  	
    	return (file);
}