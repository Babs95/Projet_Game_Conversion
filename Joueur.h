#ifndef JOUEUR_H_INCLUDED
#define JOUEUR_H_INCLUDED
#include <stdio.h>
//DEFINITION FONCTIONS

/** STRUCTURE **/
typedef struct{
    char nom[20];
    char prenom[20];
    char login[20];
    char MOP[20];
    int point;
}joueur;

typedef struct{
    char login[20];
    char MOP[20];
}joueurCo;

void Couleur(int t,int f);
void get_password(char* pass);
int Menuprincipal();
int Inscription();
int Connexion();
int MenuConversion();
int verifier(char *mot);
int verif_binaire(char* number);
int verif_decimal(char* number);
int Base16egalitycheck(int *T1, int *T2,int N);
char* verif_hexa(char* number);
void ConversionDecHexa(int N);
void ConversionReelDecBin();
int my_strlen(char ch[]);
int nbline(FILE *fichj);
int Ficounter();
int  Add_points();
void Chargement();
void gotoxy(int x, int y);
#endif // JOUEUR_H_INCLUDED
