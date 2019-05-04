#include <stdio.h>
#include <math.h>
#define BASE 2
#include <windows.h>
/**COULEUR**/
void Couleur(int t,int f){
    HANDLE H=GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(H,f*16+t);
}
/**HIDE PASSWORD**/

void get_password(char* pass)
{
    char temp_passP[25];
    int i=0;
     while(1)
    {
            temp_passP[i]=getch();
            if(temp_passP[i]==13){
                    break;
            }
            else if(temp_passP[i]==8)
            {
                if(i!=0) {
                printf("\b \b");
                i--;
                } else {printf("\a");}
            }
            else
            {
                printf("*");
                *(pass+i) = temp_passP[i];
                i++;
            }
             *(pass+i)='\0';
     }
}
void gotoxy(int x, int y){
COORD coord;
coord.X = x;
coord.Y = y;
SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}
   void Chargement(){
   int i;

   gotoxy(11,12);printf("LOADING");

   gotoxy(10,15);printf("*********************************************************");
   gotoxy(10,16);printf("^^");
  /* gotoxy(43,16);printf("*");*/
   gotoxy(10,17);printf("*********************************************************");
   for(i=0;i<=52;i++)
   {
      gotoxy(11+i,16);printf("^^");
      Sleep(100);
    }


  }
/**MENU PRINCIPAL**/
int Menuprincipal(){
int choix1;
   Couleur(9,15);
    do{

        printf("\t\t\t\t\t**^^*^^*^^*^^*MENU INSCRIPTION/CONNEXION**^^*^^*^^*^^*^^*\n\n\n");
        printf("\t\t\t\t\t 1-Inscription\n");
        printf("\t\t\t\t\t 2-Connexion\n");
        printf("\t\t\t\t\t 3-Quitter\n");
        printf("\n\n\n\t\t\t\t\t Faites votre choix (Taper 1 ou 2 ou 3):");
        scanf("%d",&choix1);

    }while((choix1 !=1) && (choix1 !=2) && (choix1 !=3));

    return choix1;
}
/**MENU INSCRIPTION**/
int Inscription(){
    /** STRUCTURE **/
typedef struct{
    char nom[20];
    char prenom[20];
    char login[20];
    char MOP[20];
    int point;
}joueur;
       int i;
     /** ALLOCATION STRUCTURE **/
     joueur *j;
     j=(joueur*)malloc(1*sizeof(joueur));
         /** Ouverture FICHIER **/
   FILE *fichj=fopen("Fjoueur.txt","a+");

    printf("\t\t\t\t------.....^^^^^^^^^^BIENVENUE DANS LE MENU INSCRIPTION^^^^^^^^^^.....------\n");
                    printf("Entrer votre nom:");
                    fflush(stdin);
                    gets(j->nom);
                    printf("Entrer votre prenom:");
                    gets(j->prenom);
                    printf("Entrer votre login:");
                    gets(j->login);
                    fflush(stdin);
                    printf("Entrer votre Mot de passe:");
                    get_password(j->MOP);
                    j->point=0;
                    printf("\n");
                    i=verifier(j->login);
                    if(i==1){
                    if(fichj==NULL)
                        exit(1);
                    fprintf(fichj,"%s %s %s %s %d\n",j->nom,j->prenom,j->login,j->MOP,j->point);
                    printf("\n\n\nVous etes maintenant inscrit.\n");
                    printf("\n");
                    system("PAUSE");
                    remove("FjoueurSvg.txt");
                    FILE *fihcopie=fopen("FjoueurSvg.txt","w");
                        if (fihcopie != NULL)
                        {

                    fprintf(fihcopie,"%s %s\n",j->login,j->MOP);
                    }
                    fclose(fihcopie);
                    }
                    else{
                        printf("\nCe login est deja utiliser essayer un autre\n");
                        system("pause");
                        system("cls");
                        Inscription();
                    }

                    fclose(fichj);
                    system("cls");
    return 100;
}

/**MENU CONNEXION**/
int Connexion(){
typedef struct{
    char login[20];
    char MOP[20];
}joueur;
     joueur *j;
     j=(joueur*)malloc(sizeof(joueur));
     signed char name[40] ,pren[40],identifiant[40],secretcode[40],chaine[320];
     int pt ,save=0;


printf("\t\t\t\tBIENVENUE DANS LE MENU CONNEXION\n");
                printf("Entrer votre login:\n");
                fflush(stdin);
                gets(j->login);
                printf("Entrer votre Mot de passe:\n");
                get_password(j->MOP);
                system("cls");
    FILE *fichj=fopen("Fjoueur.txt","r");
    if (fichj != NULL)
    {
       do {
        fscanf(fichj,"%s %s %s %s %d",name,pren,identifiant,secretcode,&pt);


if(strcmp(identifiant,j->login)==0 && strcmp(secretcode,j->MOP)==0 ){
         printf("CONNECTION REUSSI\n\n");
         Chargement();
         system("cls");
        save=1;
remove("FjoueurSvg.txt");
FILE *fichj=fopen("FjoueurSvg.txt","w");
    if (fichj != NULL)
    {

fprintf(fichj,"%s %s\n",j->login,j->MOP);
}
fclose(fichj);

return 0;
break;

   }


}while (fgets(chaine,320, fichj) != NULL);
}
fclose(fichj);
if(save==0){

    printf("Le login ou  le mot de passe que vous avez entrer est incorrect reesayer SVP!!!\n");
    system("pause");
    Connexion();
}


return 1;

}

/**MENU Conversion**/
int MenuConversion(){
    int choix2;

        do{
            printf("\n\t\t\t\t       _________________________________  ");
            printf("\n\t\t\t\t    /                                 /");
            printf("\n\t\t\t \t  /          MENU CONVERSION        / ");
            printf("\n\t\t\t\t  /                                 /  ");
            printf("\n\t\t\t\t /                                 /   ");
            printf("\n\t\t\t\t/_______________________________ _/\n\n\n\n\n");

            printf("\t\t\t\t\t1-Base(2) vers Base(10)\n");
            printf("\t\t\t\t\t2-Base(10) vers Base(2)\n");
            printf("\t\t\t\t\t3-Base(16) vers Base(2)\n");
            printf("\t\t\t\t\t4-Base(10) vers Base(16)\n");
            printf("\t\t\t\t\t5-Conversion Reel Base(10) vers Base(2)\n");
            printf("\t\t\t\t\t6-Deconnexion");
            printf("\n\n\n\t\t\t\t\tFaites votre choix(1 a 6):\t");
            scanf("%d",&choix2);
            system("cls");
        }while((choix2 !=1) && (choix2 !=2) && (choix2 !=3) && (choix2 !=4) && (choix2 !=5) && (choix2 !=6));

        return choix2;
}

/**FONCTION VERIFICATION Login & Mot de passe**/
int verifier(char *mot){
    signed char name[40] ,pren[40],identifiant[40],secretcode[40],chaine[320];

FILE *fichj=fopen("Fjoueur.txt","r");
    if (fichj != NULL)
    {
       do {
        fscanf(fichj,"%s %s %s %s",name,pren,identifiant,secretcode);

if(strcmp(identifiant,mot)==0 ){
return 0;
break;
   }
}while (fgets(chaine,320,fichj) != NULL);
}
fclose(fichj);
return 1;
}

/**Verification Binaire**/
int verif_binaire(char* number){
char *i;

for(i=number;i<number+my_strlen(number);i++){
        if(*i!='0' && *i!='1'){
            return 0;
            break;
        }
    }
    return atoi(number);
}
/**Verification Decimal**/
int verif_decimal(char* number){
char *i;

for(i=number;i<number+my_strlen(number);i++){

        if(*i<48 || *i>57){
            return 0;
            break;
        }
    }
    return atoi(number);

}
/**Equality check**/
int Base16egalitycheck(int *T1, int *T2,int N){
int i,j;

for(i=0;i<N;i++){


  if(T1[i]!=T2[i]){
      return 1;

}
return 0;

}
}

/**Verification Hexadecimal**/
char* verif_hexa(char* number){
char *i;
int conv[50];
for(i=number;i<number+my_strlen(number);i++){

        if(!(*i>=48 && *i<=57) && !(*i>=65 && *i<=70) && !(*i>=97 && *i<=102)){
            return 0;
            break;
        }
    }
    return number;

}
/**FONCTION COMPTEUR FICHIER**/
int Ficounter(){
    int j;
signed char  test1[30], test2[25],name[40] ,pren[40],identifiant[40],secretcode[40],chaine[320];
int pt;
FILE *fichj=fopen("Fjoueur.txt","r");
j=nbline(fichj);

    if (fichj != NULL)
    {
       do {
        fscanf(fichj,"%s %s %s %s %d",name,pren,identifiant,secretcode,&pt);
}while (fgets(chaine,320, fichj) != NULL);
}
fclose(fichj);

return j;
}

            /**Base10_Base16**/
void ConversionDecHexa(int N){
int *i,*tab;
int j=0,k,s,cpt=0;
i=(int*)malloc(10*sizeof(int));
tab=(int*)malloc(10*sizeof(int));
char *ch;
char *ch1;
ch=(char*)malloc(sizeof(char));
ch1=(char*)malloc(sizeof(char));
        do{
            i[j]=N%16;

            N=N/16;
            j++;

        }while(N>0);
        fflush(stdin);
        printf("\n");
        do{
        printf("Entrer le resultat en Base 16:\t");
        gets(ch1);
            if(verif_hexa(ch1)==0){
                puts("Veuillez enter un nombre en hexadecimal svp!!!");
            }
        }while(verif_hexa(ch1)==0);
        k=0;
        ch=ch1+strlen(ch1)-1;
        while(ch>=ch1){

        s=(int)(*ch);
        if(s<65){
        tab[k]= s-48;

        }
        if(s>=65 & s<97){
        tab[k]=s-55;


        }
        if(s>=97){
        tab[k]=s-87;

        }

        ch=ch-1;
        k++;
        }
        cpt=0;

if(j!=k || Base16egalitycheck(i,tab,j)==1){
printf("Desole resultat incorrect vous avez perdu\n");
system("pause");
system("cls");
}
else{
printf("Bravo resultat correct");
Add_points();
system("pause");
system("cls");
}

}

    /**Base10reel_Base2reel**/
void ConversionReelDecBin(){
  float reeldec,reel;
  int entier,quotient,reste,temp,g,x,l,t;
  char ch[11],m;
  char reelbin[20];
  puts("Entrer un reel en base 10:\t");
  scanf("%f",&reeldec);
  entier = (int)reeldec;
  temp = entier;
  g=0;
    do{
        quotient = entier/2;
        reste = entier%2;
        entier = quotient;
        if(reste==1){
            ch[g] = '1';
            }else{
                ch[g] = '0';
                }
            g++;
        }while(quotient!=0);
        for(l=g-1,t=0;t<=(g-1)/2;l--,t++){
            m=ch[l];
            ch[l]=ch[t];
            ch[t]=m;
            }
            reel = reeldec - temp;
            x=0;
            ch[g]='.';
            while(x!=2){
                g++;
                reel = reel*2;
                entier = (int)reel;
                if(entier==1){
                    ch[g] = '1';
                }else{
                    ch[g] = '0';
                }
                x++;
                }
                ch[g+1]='\0';

                printf("Entrer son resultat en base 2 reel:\t");;
                fflush(stdin);
                gets(reelbin);

                    if(strcmp(ch,reelbin)==0){
                        printf("Bravo resultat correct\n");
                        Add_points();
                        system("pause");
                        system("cls");
                        }

                    if(strcmp(ch,reelbin)!=0){
                        printf("Desole resultat incorrect vous avez perdu\n");
                        system("pause");
                        system("cls");
                        }

}
int my_strlen(char ch[])
{
    int i=0;
    while(ch[i]!='\0')
        i++;
    return i;
}
/* COMPTEUR LIGNES*/
int nbline(FILE *fichj){
  int nblignes =0;
  int c;
  while((c = fgetc(fichj)) != EOF){
  if(c == '\n') nblignes++;
  }
  fclose(fichj);

  return(nblignes);
}


/**FONCTION COMPTEUR POINT**/
int  Add_points(){
signed char  test1[30], test2[25],name[40] ,pren[40],identifiant[40],secretcode[40],chaine[320];
int pt;
int p;
int h;
int g=0;
int ct=0;

h=Ficounter();

FILE *FICHADD=fopen("FjoueurSvg.txt","r");
    if (FICHADD != NULL)
    {

fscanf(FICHADD,"%s %s\n",test1,test2);

}
fclose(FICHADD);


FILE *FICHTEMP=fopen("temp.txt","w");
FILE *fichj=fopen("Fjoueur.txt","r");

    if (fichj != NULL)
    {
       do {
        fscanf(fichj,"%s %s %s %s %d",name,pren,identifiant,secretcode,&pt);

if(strcmp(identifiant,test1)==0 && strcmp(secretcode,test2)==0 && ct<1 ){

      pt=pt+2;
      ct++;
       printf("\nVous avez %d points\n",pt);
     fprintf(FICHTEMP,"%s %s %s %s %d\n",name,pren,identifiant,secretcode,pt);
   }
if(strcmp(identifiant,test1)!=0 && strcmp(secretcode,test2)!=0 ){
    fprintf(FICHTEMP,"%s %s %s %s %d\n",name,pren,identifiant,secretcode,pt);
   }
g++;
}while (fgets(chaine,320, fichj) != NULL && g!=h);
}
fclose(fichj);
fclose(FICHTEMP);

FILE *fichjw=fopen("Fjoueur.txt","w+");
    if (fichjw != NULL)
    {

}
fclose(fichjw);
g=0;
FILE *fichjw2=fopen("Fjoueur.txt","w");
FILE *FICHTEMPr=fopen("temp.txt","r");
ct=0;
    if (FICHTEMPr != NULL)
    {
       do {
        fscanf(FICHTEMPr,"%s %s %s %s %d",name,pren,identifiant,secretcode,&pt);

if(strcmp(identifiant,test1)==0 && strcmp(secretcode,test2)==0 && ct<1){

     fprintf(fichjw2,"%s %s %s %s %d\n",name,pren,identifiant,secretcode,pt);
   }
if(strcmp(identifiant,test1)!=0 && strcmp(secretcode,test2)!=0 ){
    fprintf(fichjw2,"%s %s %s %s %d\n",name,pren,identifiant,secretcode,pt);
   }
g++;
}while (fgets(chaine,320, FICHTEMPr) != NULL && g!=h);
}
fclose(FICHTEMPr);
fclose(fichjw2);
remove("temp.txt");
return 10;
}
