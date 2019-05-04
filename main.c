#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Joueur.h"
#include <math.h>
#define BASE 2
int main()
{

   int choix,choixM;
   int verif;
    do{
   choix= Menuprincipal();
    system("cls");
        switch(choix) {
            case 1:
                Inscription();
            break;
            case 2:

                Connexion();

                do{
                        choixM=MenuConversion();
                    switch(choixM){
                    case 1:
                         printf("\n\t\t\t\t\t\t **Base(2) vers Base(10)** \n");
                            int k,trouve,set,convert=0;
                            int length,luf;
                            char nbin[25];
                            char resdec[100];
                            system("cls");
                            do{
                                 printf("Entrer un nombre en base 2:\t");
                                 fflush(stdin);
                                 gets(nbin);
                                    if(verif_binaire(nbin)==0){
                                        puts("Veuillez entrer un nombre binaire(0 ou 1)\n");
                                    }
                            }while(verif_binaire(nbin)==0);

                               length=my_strlen(nbin);
                                luf=length-1;

                            for(k=0;k<length;k++){
                                set=nbin[k]-48;
                                convert+=(pow(2,luf)*set);
                                luf--;
                                }

                            do{
                                 printf("Entrer son resultat en base 10:\t");
                                 gets(resdec);
                                     if(verif_decimal(resdec)==0){
                                            puts("Veuillez entrer un nombre decimal svp!!!!\n");
                                        }
                            }while(verif_decimal(resdec)==0);

                                trouve=verif_decimal(resdec);

                                if(convert==trouve){
                                printf("Bravo resultat correct\n");
                                Add_points();
                                system("pause");
                                system("cls");
                             }else{
                                    printf("Desole resultat incorrect vous avez perdu\n");
                                     system("pause");
                                     system("cls");

                                }


                        break;
                     case 2:
                         printf("\n\t\t\t\t\t\t **Base(10) vers Base(2)** \n");

                                    int  nbdec;
                                    char resbin[50];
                                    char dec[50];

                                    do{
                                        printf("Entrer un nombre en Base 10:\t");
                                        fflush(stdin);
                                        gets(dec);
                                        nbdec=verif_decimal(dec);
                                            if(verif_decimal(dec)==0){
                                                puts("Veuillez entre un nombre decimal svp!!!!!\n");
                                            }
                                        }while(verif_decimal(dec)==0);
                                        long tempdecimal;
                                        char binaire[65];
                                        int i=0;
                                        tempdecimal=nbdec;
                                        while(tempdecimal>0){

                                            binaire[i]= (tempdecimal % 2) + '0';
                                            tempdecimal /=2;
                                            i++;
                                            }
                                            binaire[i]= '\0';
                                            strrev(binaire);  /** strrev inverse le nombre binaire converti **/

                                        do{
                                            printf("\n\nEntrer son resultat en base 2:\t");
                                            fflush(stdin);
                                            gets(resbin);
                                            if(verif_binaire(resbin)==0){
                                                puts("Veuillez entre un nombre binaire (0 ou 1) svp!!!!!\n");
                                            }

                                        }while(verif_binaire(resbin)==0);
                                        if(strcmp(resbin,binaire)==0){

                                            printf("Bravo resultat correct\n");
                                            Add_points();
                                            system("pause");
                                            system("cls");
                                        //MenuConversion();
                                        }
                                        else{
                                              printf("Desole resultat incorrect vous avez perdu\n");
                                              system("pause");
                                              system("cls");
                                                //MenuConversion();
                                        }
                    break;
                     case 3:
                         printf("\n\t\t\t\t\t\t **Base(16) vers Base(2)** \n");
                                char nbhex[17], bin[65] = "";
                            int h = 0;
                            char resbin2[50];
                            do{
                            printf("Entrer un nombre en Base 16:\t");
                            fflush(stdin);
                            gets(nbhex);
                                if(verif_hexa(nbhex)==0){
                                    puts("Veuillez un nombre en hexadecimal svp!!!");
                                }
                            }while(verif_hexa(nbhex)==0);
                            do{
                            printf("Entrer son resultat en base 2:\t");
                            gets(resbin2);
                                if(verif_binaire(resbin2)==0){
                                    puts("Veuillez un nombre binaire (0 ou 1) svp!!!");
                                }
                            }while(verif_binaire(resbin2)==0);
                            for(h=0; nbhex[h]!='\0'; h++)
                            {
                                switch(nbhex[h])
                                {
                                    case '0':
                                        strcat(bin, "0000");
                                        break;
                                    case '1':
                                        strcat(bin, "0001");
                                        break;
                                    case '2':
                                        strcat(bin, "0010");
                                        break;
                                    case '3':
                                        strcat(bin, "0011");
                                        break;
                                    case '4':
                                        strcat(bin, "0100");
                                        break;
                                    case '5':
                                        strcat(bin, "0101");
                                        break;
                                    case '6':
                                        strcat(bin, "0110");
                                        break;
                                    case '7':
                                        strcat(bin, "0111");
                                        break;
                                    case '8':
                                        strcat(bin, "1000");
                                        break;
                                    case '9':
                                        strcat(bin, "1001");
                                        break;
                                    case 'a':
                                    case 'A':
                                        strcat(bin, "1010");
                                        break;
                                    case 'b':
                                    case 'B':
                                        strcat(bin, "1011");
                                        break;
                                    case 'c':
                                    case 'C':
                                        strcat(bin, "1100");
                                        break;
                                    case 'd':
                                    case 'D':
                                        strcat(bin, "1101");
                                        break;
                                    case 'e':
                                    case 'E':
                                        strcat(bin, "1110");
                                        break;
                                    case 'f':
                                    case 'F':
                                        strcat(bin, "1111");
                                        break;
                                    default:
                                        printf("Erreur.");
                                }
                            }

                          if(strcmp(resbin2,bin)==0){

                            printf("Bravo resultat correct\n");
                            Add_points();
                            system("pause");
                            system("cls");
                            }
                            else{
                            printf("Desole resultat incorrect vous avez perdu\n");
                            system("pause");
                            system("cls");

                            }

                    break;
                     case 4:
                         printf("\n\t\t\t\t\t\t **Base(10) vers Base(16)** \n");
                            int nbdec2;
                            printf("Entrer un nombre en base 10:");
                            scanf("%d",&nbdec2);
                            ConversionDecHexa(nbdec2);

                    break;
                     case 5:
                         printf("\n\t\t\t\t\t\t **Conversion Reel Base(10) vers Base(2)** \n");
                         ConversionReelDecBin();
                    break;
                     case 6:
                         Menuprincipal();
                         system("cls");

                    break;
                    default:
                        printf("Votre choix est invalide (Reesayer).");






                        break;
                    }
                }while(choixM!=6);
            break;
                     case 3:
                         system("cls");
                         printf(" MERCI DE VOTRE VISITE A BIENTOT");
                         exit(0);
                     break;
        default:
                printf("Votre choix est invalide (Reesayer).");
                break;
            }
   }while(choix!=3);
    return 0;
}
