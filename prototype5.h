/* Les differentes options de la commande */
FILE *options (int argc, char *argv[]);

/* Fonction qui ouvre le fichier et affiche une erreur si la fichier est NULL */
FILE *openFile (char argv[100]);

/* Fonction qui éxecute l'option -n de la commande tail */
FILE *option_n (char *argv[]);

/* Fonction qui éxecute l'option -v de la commande tail */
FILE *option_v (char *argv[]);

/* Fonction qui éxecute l'option -z de la commande tail */
FILE *option_z (char *argv[]);

/* Fonction qui éxecute l'option -q de la commande tail */
FILE *option_q (char *argv[]);

/* Fonction sans option de la commande tail */
FILE *sans_option (char *argv[]);

/* Fonction qui éxecute l'option -c de la commande wc (compte le nombre de caracteres dans fichier et de l'afficher)*/
FILE *option_c (char *argv[]);

/* Fonction qui éxecute l'option -w de la commande wc (compte le nombre de mots dans fichier et de l'afficher)*/
FILE *option_w (char *argv[]);

/* Fonction qui éxecute l'option -l de la commande wc (compte le nombre de lignes dans fichier et de l'afficher)*/
FILE *option_l (char *argv[]);

/* Fonction sans option de la commande wc (Affiche à la fois le nombre de lignes, mots et caracteres dans un fichier)*/
FILE *sans_options (char *argv[]);

/* Fonction qui calcul les n premiers lignes et l'affiche de la commande tail */
void affichage (FILE *fichier, int n);

/* Fonction qui ferme le fichier */
void closing(FILE *fichier);
