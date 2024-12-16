#ifndef FUNCTION_H_INCLUDED
#define FUNCTION_H_INCLUDED
#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include <string.h>
#include <ctype.h>
#include <conio.h>
#include <time.h>
#define N 30
#define M 20
#define nomFile "liste_livre.txt"
#define nomFile_1 "liste_livre_1.txt"
#define nomFile_2 "liste_inscription_eleve.txt"
#define nomFile_3 "lliste d'administration"
#define nomFile_4 "test.txt"
#define MAX_PASSWORD_LENGTH 20
#define CORRECT_PASSWORD "motdepasse" // Mot de passe correct (à remplacer par une vraie logique de vérification)
void convertirEnMajuscules(char *chaine) {
    for (int i = 0; chaine[i] != '\0'; i++) {
        chaine[i] = toupper(chaine[i]);
    }
}
void masquer_mot_de_passe(char *password) {
    int i = 0;
    char ch;

    while ((ch = getch()) != '\r') {
        if (ch == '\b') {
            if (i > 0) {
                i--;
                printf("\b \b");
            }
        } else if (ch != '\t' && ch != '\n') {
            if (i < MAX_PASSWORD_LENGTH - 1) {
                password[i] = ch;
                i++;
                printf("*");
            }
        }
    }

    password[i] = '\0';
    printf("\n");
}
FILE* fp = NULL;
FILE* fp_1 = NULL;


char c;
int choix, id, n, m;
long pos = 0.0;


typedef struct{
char nom[20];
char prenom[20];
char CNE[15];
char CIN[15];
char email[40];
char adresse[30];
char password[30];

}user;


typedef struct info_livre
{
    float prix_jour, prix_semaine ;
    int ID , ans_publication , qte ;
    char titre[N] , auteur[M] , editeur[N] ;
}info_livre;
typedef struct {
    int id;
    char titre[50];
    char acteur[50];
    char editeur[50];
    int annee;
    int quantite;
    float prix_jour;
    float prix_fixe;
}Livre;

void current_datetime(struct tm* local) {
    time_t now = time(NULL);
    *local = *localtime(&now);
}

int isTextPrint(char* str)
{
    if(*str == '\0') return 1;
    else if(!isprint(*str)) return 0;
    return isTextPrint(str + 1);
}
info_livre *tmp = NULL;



int isTextOnly(char* str)
{
    if(*str == '\0') return 1;
    else if(!isalpha(*str) && !isspace(*str)) return 0;
    return isTextOnly(str + 1);
}

void head_ensah()
{
    setcolor(9); // Set text color to bleau
    printf("****************************************************************************************************************************************************************************");
    gotoxy(65, 2);
    printf("-\tBIENVENUE A LA BIBLIOTHEQUE DE L'ENSAH\t-\n\n");
    printf("****************************************************************************************************************************************************************************\n");
    setcolor(7);
}
void head()
{

    setcolor(9); // Set text color to bleau
    printf("████████████████████████████████████████████████████████████████████████████████████████████████████████████████████████████████████████████████████████████████████████████");
    gotoxy(50, 3);
    printf("-LA BIBLIOTHEQUE DE L'ECOLE NATIONALE DES SCIENCES APPLIQUEES AL HOCEIMA-\n\n");
    gotoxy(0,6);
    printf("████████████████████████████████████████████████████████████████████████████████████████████████████████████████████████████████████████████████████████████████████████████\n");
    setcolor(7);
} // Reset text color to white
void setBackgroundColor(int bg) {
    // Get the current console handle
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);

    // Get the current attributes (foreground color)
    CONSOLE_SCREEN_BUFFER_INFO csbi;
    GetConsoleScreenBufferInfo(hConsole, &csbi);

    // Extract the current foreground color
    int fg = csbi.wAttributes & 0x0F; // Get the foreground color (lower 4 bits)

    // Combine foreground and new background color
    int color = (bg << 4) | fg; // Shift background color and combine with foreground
    SetConsoleTextAttribute(hConsole, color);
}


void gotoxy(int x, int y) {
    COORD coord;
    coord.X = x;
    coord.Y = y;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}


void setcolor(int color) {
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(hConsole, color);
}


void sign_in1()
{
    user u;
    fp = fopen(nomFile_2,"at");
    if (fp == NULL)
    {
        printf("\.\.\.\.\.\.\.\.\.\.Impossible d\'ouvrir le fichier %s\.\.\.\.\.\.\.\.\.\.\. \n", nomFile_2);
        exit(0);
    }
erreur_nom:
    setcolor(9); // Set text color to bleau
    printf("****************************************************************************************************************************************************************************");
    gotoxy(70, 3);
    printf("-E S P A C E  D' E L E V E-\n\n");
    printf("****************************************************************************************************************************************************************************\n");
    setcolor(9); // Set color for the borders
    gotoxy(65, 8);
    printf("**********************************************");
    gotoxy(65, 10);
    printf("-\t\tSE CONNECTER\t\t-");
    gotoxy(65, 11);
    printf("**********************************************");
    gotoxy(55,10);
    printf("----------");
    gotoxy(101,10);
    printf("----------");
    gotoxy(65,21);
    printf("**********************************************");
    setcolor(7); // Reset color for text input fields
    gotoxy(65,13);
    printf("Enter votre nom:\n");
    gotoxy(65,14);
    printf("Enter votre prenom:\n");
    gotoxy(65,15);
    printf("Enter votre CIN:\n");
    gotoxy(65,16);
    printf("Enter votre CNE:\n");
    gotoxy(65,17);
    printf("Enter votre e-mail:\n");
    gotoxy(65,18);
    printf("Enter adresse :\n");
    gotoxy(65,19);
    printf("Enter votre mot de passe :\n");
    gotoxy(81,13);
    fflush(stdin);
    scanf("%[^\n]", u.nom);
    if(!isTextOnly(u.nom))
    {
        gotoxy(60,23);
        printf("\n\t!!! N.B : Seul de CARACTERE et ESPACE\nVoyez saisir un NOM valide");
        Sleep(2000);
        system("cls");
        goto erreur_nom;
    }
    gotoxy(84,14);
    fflush(stdin);
    scanf("%[^\n]",u.prenom);
    if(!isTextOnly(u.prenom))
    {
        gotoxy(60,23);
        printf("\n\t!!! N.B : Seul de CARACTERE et ESPACE\nVoyez saisir un PRENOM valide");
        Sleep(2000);
        system("cls");
        goto erreur_nom;
    }
    gotoxy(81,15);
    fflush(stdin);
    scanf("%s",u.CIN);
    if(!isTextPrint(u.CIN))
    {
        gotoxy(60,23);
        printf("\n\t!!! N.B : Seul de CARACTERE, ESPACE et CHIFFRE\nVoyez saisir une CIN valide");
        Sleep(2000);
        system("cls");
        goto erreur_nom;
    }
    gotoxy(81,16);
    fflush(stdin);
    scanf("%s",u.CNE);
    if(!isTextPrint(u.CNE))
    {
        gotoxy(60,23);
        printf("\n\t!!! N.B : Seul de CARACTERE, ESPACE et CHIFFRE\nVoyez saisir une CNE valide");
        Sleep(2000);
        system("cls");
        goto erreur_nom;
    }
    gotoxy(84,17);
    fflush(stdin); scanf("%s",u.email);
    gotoxy(81,18);
    fflush(stdin);     scanf("%[^\n]",u.adresse);//fgets(u.adresse,sizeof(u.adresse),stdin);
    u.adresse[strcspn(u.adresse, "\n")] = '\0'; //A questionner ??
    gotoxy(91,19);
    fflush(stdin); scanf("%s",u.password);
    fprintf(fp, "%s|%s|%s|%s|%s|%s|%s\n", u.nom, u.prenom, u.CIN, u.CNE, u.email, u.adresse, u.password);
    n = fclose(fp);
    if(n) printf("\n\n\.\.\.\.\.\.\.\.\.\.Erreur de fermer le fichier %s\.\.\.\.\.\.\.\.\.\.\. ", nomFile_2);
    gotoxy(70,23);
    setcolor(10);
    printf("VOUS ETES INSCRIT AVEC SUCCES!\n");
        setcolor(9);
        gotoxy(65,26);
     printf("Voulez-vous aller à la page de connexion ? (y/n) : ");
    char choix;
    scanf(" %c", &choix);
    setcolor(7);
    if (choix == 'y' || choix == 'Y') {
        printf("\nRedirection vers la page de connexion...\n");
        sleep(3);
        system("cls");
        LOGIN1();

    } else {
     erreur_page();
    }
}


user *u = NULL;

void LOGIN1(){
    head();
 u = (user *)malloc(sizeof(user));
     int found = 0;
    fp = fopen(nomFile_2, "r");
    if (fp == NULL) {
    printf("Error opening file.\n");
    exit(1); // Ensure you handle the error appropriately
}
    char email[40];
    char password[30];

    setcolor(9);
    gotoxy(65, 10);
    printf("************************************\n");

    gotoxy(65, 11);
    printf("-      LOGIN TO YOUR ACCOUNT       -\n");

    gotoxy(65, 12);
    printf("************************************\n");
    gotoxy(55,11);
    printf("----------");
    gotoxy(101,11);
    printf("----------");
    gotoxy(65,19);
    printf("************************************");
    setcolor(7); // Reset color for text input fields
    gotoxy(65, 14);
    printf("Email: ");
    gotoxy(65, 16);
    printf("Password: ");
    gotoxy(65 + strlen("Email: "), 14);
    scanf("%s", email);
    gotoxy(65 + strlen("Password: "), 16);
    masquer_mot_de_passe(password);

while (fscanf(fp, "%[^|]|%[^|]|%[^|]|%[^|]|%[^|]|%[^|]|%s\n", u->nom, u->prenom, u->CIN, u->CNE, u->email, u->adresse, u->password) == 7) {
    if (strcmp(u->email, email) == 0 && strcmp(u->password, password) == 0) {
        found = 1;
        break;
    }
}

    fclose(fp);
      if (found == 1) {
        gotoxy(65, 22);
        setcolor(10);
        printf("Connexion reussie ! Bienvenue %s %s.\n", u->nom, u->prenom);
        setcolor(7);


        sleep(2);
        system("cls");
        espace_etudiant(u); // Assurez-vous que cette fonction est bien définie et fonctionne
    } else {
        gotoxy(68, 20);
        setcolor(12);
                    printf("%s %s",u->email,u->password);
       /* printf("Email ou mot de passe incorrect.\n");*/
        sleep(2);
        system("cls");
        LOGIN1();
    }
}
void LOGIN2(){
     head();
    fp = fopen("liste d'administration.txt","r");
    char password[30],pass[20];
    int found=0;

    setcolor(9); // Set color for the borders
    gotoxy(65, 10);
    printf("************************************\n");

    gotoxy(65, 12);
    printf("-      LOGIN TO YOUR ACCOUNT       -\n");

    gotoxy(65, 14);
    printf("************************************\n");
    gotoxy(55,12);
    printf("----------");
    gotoxy(101,12);
    printf("----------");
    gotoxy(65,20);
    printf("************************************");
    setcolor(7);
    gotoxy(65, 17);
    printf("Password:");
    gotoxy(65+strlen("Password: "),17);
    masquer_mot_de_passe(password);
    while(fscanf(fp,"%s",pass)==1){
        if(strcmp(password,pass)==0){
        found=1;
        break;
        }
    }if (found == 1) {
        gotoxy(75, 22);
        setcolor(10);
        printf("Connexion réussie!\n");
        sleep(3);  // Pause for a moment
        system("cls");
        espace_administration();
        exit(0);
    }
    else {
        setcolor(4);
        gotoxy(73, 24);
        printf("Mot de passe incorrect\n");
        sleep(3);
        system("cls");
        LOGIN2();
    }




    fclose(fp);}


void erreur_page(){
    system("cls");
    system("color F9");
    gotoxy(65, 12);
    printf("********************************************");
    gotoxy(65, 13);
    printf("                                            ");
    gotoxy(62, 14);
    printf("      consulter cette page ulterieurement !!");
    gotoxy(65, 15);
    printf("                                            ");
    gotoxy(65, 16);
    printf("                     MERCI...               ");
    gotoxy(65, 17);
    printf("                                            ");
    gotoxy(65, 18);
    printf("********************************************");
    gotoxy(0,27);
            setcolor(07);
            getch();
                exit(0); // Exit the program
    return 0;
}


void login_sign_in1(){
system("color 9");
printf("\n\n\n\n");
printf("****************************************************************************************************************************************************************************");
printf("                                                                   -E S P A C E   D' E T U D I A N T -\n");
printf("****************************************************************************************************************************************************************************\n\n\n\n");
    int n;
    while(1){
    // Set color for the top border
    setcolor(9); // Blue for the border
    gotoxy(65, 9);
    printf("***************************************\n");

    // Set color for the login option
    setcolor(9);
    gotoxy(65, 10);
    printf("|            ");
    setcolor(7);
    printf("1. se connecter          ");
    setcolor(9);
    printf("|\n");

    // Set color for the sign-in option
    setcolor(9);
    gotoxy(65, 12);
    printf("|            ");
    setcolor(7);
    printf("2. s'inscrire            ");
    setcolor(9);
    printf("|\n");
    // Set color for the exit option
    setcolor(9);
    gotoxy(65, 14);
    printf("|            ");
    setcolor(7);
    printf("3. Exit                  ");
    setcolor(9);
    printf("|\n");
    setcolor(9);
        gotoxy(65, 15);
        printf("***************************************\n");

        setcolor(07);
        gotoxy(57, 18);
        setcolor(9);
        printf("******************************************************\n");
        gotoxy(57, 19);
        printf("|");
        setcolor(7);
        gotoxy(65, 19);
        printf("Please select a valid option (1-3): ");
        setcolor(9);
        gotoxy(110, 19);
        printf("|");
        gotoxy(57, 20);
        printf("******************************************************\n");
        gotoxy(101, 19);
        setcolor(7);
        scanf("%d", &n);
        tarik:
    // Read user input
    switch (n) {
            case 1:
               system("cls"); // Clear the screen
               LOGIN1(); // Call the login function
               return; // Exit the function after successful login
            case 2:
                system("cls");
                sign_in1();
                return ;
            case 3:
                system("cls");
                homepage();

                exit(0); // Exit the program
           default:
                    gotoxy(57, 22);
                    setcolor(9);
                    printf("******************************************************\n");
                    gotoxy(57, 23);
                    printf("|");
                    setcolor(7);
                    gotoxy(60, 23);
                    printf("Invalid input.Please select a valid option (1-3): ");
                    setcolor(9);
                    gotoxy(110, 23);
                    printf("|\n");
                    setcolor(9);
                    gotoxy(57, 24);
                    printf("******************************************************\n");
                    gotoxy(109, 23);
                    setcolor(7);
                    scanf("%d",&n);
                    goto tarik;

    }
    }
}


void login_sign_in2(){
system("color 9");
printf("\n\n\n\n");
printf("****************************************************************************************************************************************************************************");
printf("                                                              -E S P A C E   D' A D M I N I S T R A T I O N-\n");
printf("****************************************************************************************************************************************************************************\n\n\n\n");
    int n;
    while(1){
    // Set color for the top border
    setcolor(9); // Blue for Fthe border
    gotoxy(65, 9);
    printf("***************************************\n");

    // Set color for the login option
    setcolor(9);
    gotoxy(65, 11);
    printf("|            ");
    setcolor(7);
    printf("1. Login                 ");
    setcolor(9);
    printf("|\n");

    // Set color for the sign-in option
    setcolor(9);
    gotoxy(65, 13);
    printf("|            ");
    setcolor(7);
    printf("2. Exit                  ");
    setcolor(9);
    printf("|\n");
    setcolor(9);
        gotoxy(65, 15);
        printf("***************************************\n");

        setcolor(07);
        gotoxy(57, 18);
        setcolor(9);
        printf("******************************************************\n");
        gotoxy(57, 19);
        printf("|");
        setcolor(7);
        gotoxy(65, 19);
        printf("Please select a valid option (1-3): ");
        setcolor(9);
        gotoxy(110, 19);
        printf("|");
        gotoxy(57, 20);
        printf("******************************************************\n");

        gotoxy(101, 19);
        setcolor(7);
        scanf("%d", &n);
        tarik:
    // Read user input
    switch (n) {
            case 1:
               system("cls"); // Clear the screen
               LOGIN2(); // Call the login function
               return; // Exit the function after successful login
            case 2:
                system("cls");
                homepage();

                exit(0); // Exit the program
           default:
                    gotoxy(57, 22);
                    setcolor(9);
                    printf("******************************************************\n");
                    gotoxy(57, 23);
                    printf("|");
                    setcolor(7);
                    gotoxy(60, 23);
                    printf("Invalid input.Please select a valid option (1-3): ");
                    setcolor(9);
                    gotoxy(110, 23);
                    printf("|\n");
                    setcolor(9);
                    gotoxy(57, 24);
                    printf("******************************************************\n");
                    gotoxy(109, 23);
                    setcolor(7);
                    scanf("%d",&n);
                    goto tarik;

    }
    }
}


void homepage() {
           int n;

system("color 9");
printf("\n\n\n\n");
printf("***************************************************************************************************************************************************************************");
printf("                                                                      *M E N U  P R I N C I P A L*\n");
printf("***************************************************************************************************************************************************************************\n\n\n\n");
gotoxy(18,10);
printf("                              veuillez choisir l'espace que vous voulez souhaiter faire des operations :");

gotoxy(50,15);
printf("1-espace d'etudiants:                          2-espace administration :");
gotoxy(35,19);
printf("                                            3-QUITTER : \n\n\n");
printf("****************************************************************************************************************************************************************************\n");
gotoxy(130,40);
printf("2024 ENSAH LIBARY. All rights reserved.");
gotoxy(68,25);
printf("Veuillez entrer votre choix : ");
gotoxy(97,25);

scanf("%d", &n);
tarik:
switch (n) {
            case 1:
               system("cls"); // Clear the screen
              login_sign_in1(); // Call the login sign in function
               return; // Exit the function after successful login
            case 2:
               system("cls"); // Clear the screen
              login_sign_in2(); // Call the login sign in function
               return; // Exit the function after successful login
            case 3:
                erreur_page();

                exit(0); // Exit the program
           default:
                    gotoxy(57, 22);
                    setcolor(9);
                    printf("******************************************************\n");
                    gotoxy(57, 23);
                    printf("|");
                    setcolor(7);
                    gotoxy(60, 23);
                    printf("Invalid input.Please select a valid option (1-3): ");
                    setcolor(9);
                    gotoxy(110, 23);
                    printf("|\n");
                    setcolor(9);
                    gotoxy(57, 24);
                    printf("******************************************************\n");
                    gotoxy(109, 23);
                    setcolor(7);
                    scanf("%d",&n);
                    goto tarik;

    }
}
void affiche_livre(const char *fichier_source){
   Livre l;
   int i=0;
fp = fopen(fichier_source, "r");
if (fp == NULL) {
    puts("Erreur: Impossible d'ouvrir le fichier ");
    return;
} gotoxy(30,34);
  printf("_____________________________________________________________________________________________________________________________\n");
  gotoxy(30,35);
    printf("| ID         | Titre               | Auteur              | Éditeur            | Année   | Quantité | Prix/Jour | Prix Fixe |\n");
    gotoxy(30,36);
    printf("____________________________________________________________________________________________________________________________\n");

    // Lecture ligne par ligne
    while (fscanf(fp, "%d|%[^|]|%[^|]|%[^|]|%d|%d|%f|%f\n",
                  &l.id,
                  l.titre,
                  l.acteur,
                  l.editeur,
                  &l.annee,
                  &l.quantite,
                  &l.prix_jour,
                  &l.prix_fixe) == 8) {
                          gotoxy(30,37+i);
        printf("| %-10d | %-19s | %-19s | %-18s | %-7d | %-8d | %-9.2f | %-9.2f |\n",
               l.id, l.titre, l.acteur, l.editeur,
               l.annee, l.quantite, l.prix_jour, l.prix_fixe);
               i++;
    }
    gotoxy(30,37+i);
    printf("____________________________________________________________________________________________________________________________\n");
   fclose(fp);
}
int charger_livre_par_id(Livre *livre, const char *nom_fichier, int id_recherche) {
    FILE *fp = fopen(nom_fichier, "r");
    if (fp == NULL) {
        printf("Erreur : Impossible d'ouvrir le fichier %s.\n", nom_fichier);
        return 0;
    }

    char buffer[256]; // Buffer pour lire les lignes
    while (fgets(buffer, sizeof(buffer), fp)) {
        // Supprimer le saut de ligne à la fin de la ligne, si présent
        buffer[strcspn(buffer, "\n")] = '\0';

        // Lire les données de la ligne avec `sscanf`
        if (sscanf(buffer, "%d %49s %49s %49s %d %d %f %f",
                   &livre->id, livre->titre, livre->acteur, livre->editeur,
                   &livre->annee, &livre->quantite, &livre->prix_jour, &livre->prix_fixe) == 8) {

            // Vérifier si l'ID correspond
            if (livre->id == id_recherche) {
                fclose(fp);
                return 1; // Livre trouvé
            }
        } else {
            printf("Erreur de format sur la ligne : %s\n", buffer);
        }
    }

    fclose(fp);
    return 0; // Livre non trouvé
}
void afficher_livre(const Livre *livre) {
    printf("\n=== Détails du Livre ===\n");
    printf("ID          : %d\n", livre->id);
    printf("Titre       : %s\n", livre->titre);
    printf("Acteur      : %s\n", livre->acteur);
    printf("Editeur     : %s\n", livre->editeur);
    printf("Année       : %d\n", livre->annee);
    printf("Quantité    : %d\n", livre->quantite);
    printf("Prix par jour : %.2f\n", livre->prix_jour);
    printf("Prix par semaine : %.2f\n", livre->prix_fixe);
    printf("=========================\n");
}


void emprunter_livre(const char *liste_livre) {
    struct tm local;
    Livre livre;
    char line[100];
    int id_recherche, jours;
    FILE *fp;

    // Demander l'ID à l'utilisateur
    printf("Entrez l'ID du livre : ");
    scanf("%d", &id_recherche);
    // Charger le livre correspondant à l'ID
    if (charger_livre_par_id(&livre, liste_livre, id_recherche)) {
        if (livre.quantite == 0) {
            printf("Nous sommes désolés, mais nous n'avons pas ce livre en stock pour le moment\n");
            return;
        }
        printf("Entrez le nombre de jours d'emprunt : ");
        scanf("%d", &jours);

        // Calculer le coût
        float total = (jours <= 6) ? livre.prix_jour * jours : livre.prix_fixe;
        printf("Le coût total pour %d jours est : %.2f\n", jours, total);

        copier_livres("liste_livre.txt", nomFile_1, id_recherche);

        fp = fopen("liste_emprunter.txt", "a");
        if (fp == NULL) {
            printf("Impossible d'ouvrir le fichier liste_emprunter\n");
            return;
        }

        // Fill the struct tm with current date and time
        current_datetime(&local);

        // Write the book information and the current date and time
        fprintf(fp, "%-7d  %-21s  %-20s  %-20s  %-18d  %-28.2f  %-28.2f %02d-%02d-%d %02d:%02d:%02d\n",
                livre.id, livre.acteur, livre.titre, livre.editeur, livre.annee,
                livre.prix_jour, livre.prix_fixe,
                local.tm_mday, local.tm_mon + 1, local.tm_year + 1900,
                local.tm_hour, local.tm_min, local.tm_sec);

        fclose(fp);
        printf("Votre emprunt a été effectué sans erreur.\n");

    } else {
        printf("Aucun livre trouvé avec l'ID %d.\n", id_recherche);
    }

}




    void copier_livres(const char *fichier_source, const char *fichier_destination,int id_livre_emprunter) {
    FILE *source = fopen(fichier_source, "r");
    FILE *destination = fopen(fichier_destination, "w");

    // Vérification de l'ouverture des fichiers
    if (source == NULL) {
        printf("Erreur : Impossible d'ouvrir le fichier source %s.\n", fichier_source);
        return;
    }
    if (destination == NULL) {
        printf("Erreur : Impossible d'ouvrir le fichier destination %s.\n", fichier_destination);
        fclose(source); // Fermer le fichier source avant de quitter
        return;
    }

    Livre livre;
    while (fscanf(source, "%d %s %s %s %d %d %f %f",
                  &livre.id,
                  livre.titre,
                  livre.acteur,
                  livre.editeur,
                  &livre.annee,
                  &livre.quantite,
                  &livre.prix_jour,
                  &livre.prix_fixe) == 8)
                  if(livre.id != id_livre_emprunter ){
        fprintf(destination, "%d %s %s %s %d %d %.2f %.2f\n",
                livre.id,
                livre.titre,
                livre.acteur,
                livre.editeur,
                livre.annee,
                livre.quantite,
                livre.prix_jour,
                livre.prix_fixe);
    }else{
    fprintf(destination, "%d %s %s %s %d %d %.2f %.2f\n",
                livre.id,
                livre.titre,
                livre.acteur,
                livre.editeur,
                livre.annee,
                (livre.quantite) - 1,
                livre.prix_jour,
                livre.prix_fixe);





    }

    fclose(source);
    fclose(destination);
    rename("liste_livre.txt","liste_livre_2.txt");
    rename("liste_livre_1.txt","liste_livre.txt");

    remove("liste_livre_2.txt");
    }

//Mes traveaux situent ci-dessous (Ilyas)

void afficher_menu_etu()
{

    setcolor(9);
    gotoxy(60,12);
    puts("━━━━━━━━━━━━━━━━━━ESPACE ETUDIANT━━━━━━━━━━━━━━━━━━");
    gotoxy(60, 14);
    printf("*\t1           Emprunter un livre               *");
    gotoxy(60, 16);
    printf("---------------------------------------------------");
    gotoxy(60, 18);
    printf("*\t2           Rechercher un livre             *");
    gotoxy(60, 20);
    printf("---------------------------------------------------");
    gotoxy(60, 22);
    printf("*\t3       Lister les livres disponibles       *");
    gotoxy(60, 24);
    printf("---------------------------------------------------");
    gotoxy(60, 26);
    printf("*\t0                Exit                        *");
    gotoxy(60, 28);
    puts("━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━");
    gotoxy(64, 30);
    printf("Veuillez entrer une meilleure choix (0-3):  ");
    setcolor(07);
    gotoxy(64+strlen("Veuillez entrer une meilleure choix (0-3): "),30);
    scanf("%d", &choix);
}



void espace_etudiant(){
    head();
    convertirEnMajuscules(u->nom);
    convertirEnMajuscules(u->prenom);
        gotoxy(73,9);
    printf("BIENVENUE %s %s ", u->nom, u->prenom);
    Is_Fichier_Livre();
    afficher_menu_etu();
    do
    {
    switch(choix)
    {
        case 0 :
            erreur_page();
            break;
        case 1 : emprunter_livre("liste_livre.txt");
        break ;
        case 2 :
            recherche_livre();
            if(pos == -2.0) puts("\nDesole!!! Actuellement, Il n'y a pas de livre !!!\n\tVoyez revenir ulterierement\n\tMERCI POUR VOTRE COMPREHENSION.");
            else
            {
                espace_recherche_livre();
                afficher_fpos();
                getch();
            }
            break;
        case 3 : affiche_livre("liste_livre.txt");
        break;
        default :
            setcolor(4);
            gotoxy(62,32);
            puts("Erreur!!! entrer un nombre valide entre (0-3):");
            sleep(2);
            gotoxy(65,33);
            puts("Appuyez sur une touche pour continuer...");
            break;
    }
    printf("Appuyez sur une touche pour continuer");
    getch();
    system("cls");

    if(choix) espace_etudiant();
    }while(choix != 0);

}


void afficher_menu_admini()
{
    setcolor(9);
    gotoxy(35,11);
    puts("━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━│ESPACE ADMINISTRATION│━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━");
    gotoxy(50,15);
    printf("1-Ajouter un livre");
    gotoxy(107,15);
    printf("2-Supprimer un livre                      ");
    gotoxy(50,19);
    printf("3-Modifier les informations d\'un livre    ");
    gotoxy(107,19);
    printf("4-Retourner un livre                      ");
    gotoxy(50,23);
    printf("5-Statistique");
    gotoxy(107,23);
    printf("6-Recherche un livre");
    gotoxy(50,27);
    printf("7-Lister les livres empruntes");
    gotoxy(107,27);
    printf("8-Exit");
    gotoxy(35,30);
    puts("━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━");
    gotoxy(70,33);
    printf("Veuillez entrer une meilleur choix (0-7): ");
    scanf("%d", &choix);
}
void affiche_livre_emprunter(){
    setcolor(9);
char line[100];
 fp=fopen("liste_emprunter.txt","r");
 if(fp==NULL){
    printf("impossible d;ouvrir le fichier liste_emprunter");
    exit(1);}
while (fgets(line, sizeof(line), fp) != NULL) {
        printf("%s", line);
    }

    fclose(fp);
}
void espace_administration()
{    head();
    Is_Fichier_Livre();
    afficher_menu_admini();
    do
    {
    switch(choix)
    {
        case 0 :
            erreur_page();
            break;
        case 1 :
            ajouter_livre();
            break;

        case 2 :
            supprimer_livre();
            break;
        case 3 :
            modifier_livre();
            puts("Merci Pour Votre Visite !!!");
            break;
        case 4 : retourner_livre();
            break;
        case 5 : break;
        case 6 :
                recherche_livre();
            if(pos == -2.0) puts("\nLa liste est vide !!!");
            else
            {
                espace_recherche_livre();
                afficher_fpos();
                getch();
            }
            break;
        case 7 :affiche_livre_emprunter();
        break;
        case 8: erreur_page();
        default :
           setcolor(4);
    gotoxy(62,34);
            puts("Erreur!!! entrer un nombre valide entre (0-3):");
            sleep(2);
            gotoxy(65,35);
            puts("Appuyez sur une touche pour continuer...");
            break;
    }
    getch();
    system("cls");

    if(choix) espace_administration();
    }while(choix != 0);

    getch();
}

void liste_livre_emprunter(){
    Livre livre;
fp=fopen("liste_emprunter.txt","r");
if(fp==NULL){
    printf("impossible d'ouvrir fichier liste_emprunter");
    return ;
}
    while (fscanf(fp, "%d %49s %49s %49s %d %d %f %f",
                  &livre.id,
                  livre.titre,
                  livre.acteur,
                  livre.editeur,
                  &livre.annee,
                  &livre.quantite,
                  &livre.prix_jour,
                  &livre.prix_fixe) == 8){

                  fprintf(fp, "%d %49s %49s %49s %d %d %f %f",
                  &livre.id,
                  livre.titre,
                  livre.acteur,
                  livre.editeur,
                  &livre.annee,
                  &livre.quantite,
                  &livre.prix_jour,
                  &livre.prix_fixe);

                  }

                  fclose(fp);





}

void Is_Fichier_Livre()
{
    fp = fopen(nomFile , "r+t");
    if(fp == NULL)
    {
        fp = fopen(nomFile , "w+t");
        if(fp == NULL)
        {
            printf("\.\.\.\.\.\.\.\.\.\.Impossible d\'ouvrir le fichier %s\.\.\.\.\.\.\.\.\.\.\. \n", nomFile);
            exit(1);
        }
    }
    n = fclose(fp);
    if(n) printf("\n\n\.\.\.\.\.\.\.\.\.\.Erreur de fermer le fichier %s\.\.\.\.\.\.\.\.\.\.\. ", nomFile);
}






void espace_recherche_livre()
{
    printf("Donner ID de livre : ");
erreur_num2:
    fflush(stdin);
    n = scanf("%d", &id);
    if((n != 1) || (id <= 0))
    {
        printf("Voyez saisir une valeur correcte (>0) : ");
        goto erreur_num2;
    }
    recherche_livre();
    if((pos != -1.0) && (pos != -2.0)) puts("Les informations du livre sont comme suit : ");
}



void afficher_informations(info_livre *b)
{
    printf("ID du livre : %d \n",b->ID);
    printf("Le titre du livre : %s \n",b->titre) ;
    printf("Nom d'acteur du livre : %s \n",b->auteur) ;
    printf("L'ans du publication du livre : %d \n",b->ans_publication) ;
    printf("L'editeur du livre : %s \n",b->editeur) ;
    printf("La quantite du livres en stock : %d \n",b->qte) ;
    printf("Le prix de livre pour emprunter par jour (en MAD) : %.2f \n",b->prix_jour) ;
    printf("Le prix de livre pour emprunter de plus une semaine (en MAD) : %.2f \n",b->prix_semaine) ;
}


void saiser_informations(info_livre **b)
{
    if(!id)
    {
        printf("Entrer id du livre : ") ;
erreur_num1:
        fflush(stdin);
        n = scanf("%d",&((*b)->ID));
        if((n != 1) || (((*b)->ID) < 0))
        {
            printf("Voyez saisir une valeur correcte (>0) : ");
            goto erreur_num1;
        }
    }
    printf("Entrer le titre du livre : ") ;
erreur_print1:
    fflush(stdin);
scanf(" %[^\n]", (*b)->titre);
    if(!isTextPrint((*b)->titre))
    {
        printf("\n\t!!! N.B : Seul de CARACTERE, ESPACE et CHIFFRE\nVoyez saisir un titre valide : ");
        goto erreur_print1;
    }
    printf("Entrer nom d'acteur du livre : ") ;
erreur_nom1:
    fflush(stdin);
scanf(" %[^\n]", (*b)->auteur);
    if(!isTextOnly((*b)->auteur))
    {
        printf("\n\t!!! N.B : Seul de CARACTERE et ESPACE\nVoyez saisir un nom valide : ");
        goto erreur_nom1;
    }
    printf("Entrer l'ans du publication du livre : ") ;
erreur_num2:
    fflush(stdin);
    n = scanf("%d",&((*b)->ans_publication)) ;
    if((n != 1) || (((*b)->ans_publication) < 0))
    {
        printf("Voyez saisir une annee correcte (>0) : ");
        goto erreur_num2;
    }
    printf("Entrer l'editeur du livre : ") ;
erreur_print2:
    fflush(stdin);
scanf(" %[^\n]", (*b)->editeur);
    if(!isTextPrint((*b)->editeur))
    {
        printf("\n\t!!! N.B : Seul de CARACTERE, ESPACE et CHIFFRE\nVoyez saisir un editeur valide : ");
        goto erreur_print2;
    }
    printf("Entrer la quantite du livres en stock : ") ;
erreur_num3:
    fflush(stdin);
    n = scanf("%d",&((*b)->qte)) ;
    if((n != 1) || (((*b)->qte) < 0))
    {
        printf("Voyez saisir une valeur correcte (>0) : ");
        goto erreur_num3;
    }
    printf("Entrer le prix de livre pour emprunter par jour (en MAD) : ") ;
erreur_flo:
    fflush(stdin);
    n = scanf("%f",&((*b)->prix_jour)) ;
    if((n != 1) || (((*b)->prix_jour) < 0))
    {
        printf("Voyez saisir un prix correct (>0) : ");
        goto erreur_flo;
    }
    printf("Entrer le prix de livre pour emprunter de plus une semaine (en MAD): ") ;
erreur_flo1:
    fflush(stdin);
    n = scanf("%f",&((*b)->prix_semaine)) ;
    if((n != 1) || (((*b)->prix_semaine) < 0))
    {
        printf("Voyez saisir un prix correct (>0) : ");
        goto erreur_flo1;
    }
}

void ajouter_livre()
{
        // ajout des livres :
        puts("Entrer les informations sur livre : \n");
        printf("Entrer id du livre : ") ;
erreur_num6:
        fflush(stdin);
        n = scanf("%d",&id);
        if((n != 1) || (id <= 0))
        {
            printf("Voyez saisir une valeur correcte (>0): ");
            goto erreur_num6;
        }

        recherche_livre();
        if((pos != -1.0) && (pos != -2.0)) printf("\nERREUR!!! VOYEZ ENTRER UN AUTRE ID!!! Cette ID est deja remplie.\n");
        else
        {
            info_livre *debut = (info_livre*)malloc(sizeof(info_livre));
            debut->ID = id;
            saiser_informations(&debut);
            info_livre_equ(debut);
            if((pos != -1.0) && (pos != -2.0))
            {
                puts("\n\nS'il vous plait !!!\nVeuillez entrer un autre livre cette livre deja existe\nSes informations sont representent comme suit :\n");
                afficher_fpos();
            }
            else
            {
                fp = fopen(nomFile , "a+t");
                if(fp == NULL)
                {
                    printf("\.\.\.\.\.\.\.\.\.\.Impossible d\'ouvrir le fichier %s\.\.\.\.\.\.\.\.\.\.\. \n", nomFile);
                    exit(1);
                }
                fprintf(fp , "%d|%s|%s|%s|%d|%d|%f|%f\n", (debut->ID) , (debut->titre) , (debut->auteur) , (debut->editeur) , (debut->ans_publication) , (debut->qte) , (debut->prix_jour) , (debut->prix_semaine));
                puts("\nL'enregesretement des informations s'effectue avec succee") ;

                n = fclose(fp);
                if(n) printf("\n\n\.\.\.\.\.\.\.\.\.\.Erreur de fermer le fichier %s\.\.\.\.\.\.\.\.\.\.\. ", nomFile);
            }

        }
        printf("Voulez-vous ajouter une autre livre (O/N) ? ");
erreur_alpha:
        fflush(stdin);
        scanf(" %c", &c);
        if(toupper(c) != 'O' && toupper(c) != 'N')
        {
            printf("Voyez saisir une choix correcte (O/N) : ");
            goto erreur_alpha;
        }
        else if(toupper(c) == 'O') ajouter_livre();
}


void afficher_fpos()
{    setcolor(7);
    tmp = (info_livre*)malloc(sizeof(info_livre));
    if((pos != -1.0) && (pos != -2.0))
    {
        fp = fopen(nomFile , "r+t");
        if(fp == NULL)
        {
            printf("\.\.\.\.\.\.\.\.\.\.Impossible d\'ouvrir le fichier %s\.\.\.\.\.\.\.\.\.\.\. \n", nomFile);
            exit(1);
        }
        fseek(fp , pos , SEEK_SET);
        fscanf(fp , "%d|%[^|]|%[^|]|%[^|]|%d|%d|%f|%f\n", &(tmp->ID) , &(tmp->titre) , &(tmp->auteur) , &(tmp->editeur) , &(tmp->ans_publication) , &(tmp->qte) , &(tmp->prix_jour) , &(tmp->prix_semaine));
        afficher_informations(tmp);

        n = fclose(fp);
        if(n) printf("\n\n\.\.\.\.\.\.\.\.\.\.Erreur de fermer le fichier %s\.\.\.\.\.\.\.\.\.\.\. ", nomFile);
    }
    else if(pos == -1.0) printf("Ce livre n'existe pas !!! \n");
    else printf("\nLa liste est vide !!!\n");

}

void info_livre_equ(info_livre *debut)
{
    tmp = (info_livre*)malloc(sizeof(info_livre));
    fp = fopen(nomFile , "r+t");
    if(fp == NULL) {
        printf("\.\.\.\.\.\.\.\.\.\.Impossible d\'ouvrir le fichier %s\.\.\.\.\.\.\.\.\.\.\. \n", nomFile);
        exit(1);
    }
    n = 0;
    while(!feof(fp))
    {
        n++;
        m = fscanf(fp , "%d|%[^|]|%[^|]|%[^|]|%d|%d|%f|%f\n" , &(tmp->ID) , &(tmp->titre) , &(tmp->auteur) , &(tmp->editeur) , &(tmp->ans_publication) , &(tmp->qte) , &(tmp->prix_jour) , &(tmp->prix_semaine));
        if(!stricmp(debut->titre , tmp->titre) && !stricmp(debut->auteur , tmp->auteur) && !stricmp(debut->editeur , tmp->editeur) && (debut->ans_publication == tmp->ans_publication)) break;
    }
    if(!stricmp(debut->titre , tmp->titre) && !stricmp(debut->auteur , tmp->auteur) && !stricmp(debut->editeur , tmp->editeur) && (debut->ans_publication == tmp->ans_publication))
    {
        pos = ftell(fp);
        pos -= pos / n ;
    }
    else if((m == -1) && (n == 1)) pos = -2.0;
    else pos = -1.0;

    n = fclose(fp);
    if(n) printf("\n\n\.\.\.\.\.\.\.\.\.\.Erreur de fermer le fichier %s\.\.\.\.\.\.\.\.\.\.\. ", nomFile);

}


void recherche_livre()
{    setcolor(9);
    tmp = (info_livre*)malloc(sizeof(info_livre));
    fp = fopen(nomFile , "r+t");
    if(fp == NULL) {
        printf("\.\.\.\.\.\.\.\.\.\.Impossible d\'ouvrir le fichier %s\.\.\.\.\.\.\.\.\.\.\. \n", nomFile);
        exit(1);
    }
    n = 0;
    while(!feof(fp))
    {
        n++;
        m = fscanf(fp , "%d|%[^|]|%[^|]|%[^|]|%d|%d|%f|%f\n", &(tmp->ID) , &(tmp->titre) , &(tmp->auteur) , &(tmp->editeur) , &(tmp->ans_publication) , &(tmp->qte) , &(tmp->prix_jour) , &(tmp->prix_semaine));
        if(id == tmp->ID) break;
    }
    if(id == tmp->ID)
    {
        pos = ftell(fp);
        pos -= pos / n ;
    }
    else if((m == -1) && (n == 1)) pos = -2.0;
    else pos = -1.0;

    n = fclose(fp);
    if(n) printf("\n\n\.\.\.\.\.\.\.\.\.\.Erreur de fermer le fichier %s\.\.\.\.\.\.\.\.\.\.\. ", nomFile);

}




void supprimer_livre()
{
    recherche_livre();
    if(pos == -2.0) printf("\nLa liste est vide !!!\n");
    else
    {
        printf("Donner ID de livre que vous souhaitez supprimer : ");
erreur_num5:
        fflush(stdin);
        n = scanf("%d", &id);
        if((n != 1) || (id < 0))
        {
            printf("Voyez saisir une valeur correcte (>0) : ");
            goto erreur_num5;
        }
        recherche_livre();
        if (pos == -1.0) printf("Ce livre n'existe pas !!! \n");
        else
        {
            n = 1 ;
            puts("Les informations du livre que vous voulez supprimer sont comme suit :\n");
            afficher_fpos();
            printf("Voulez-vous suiver cette operation (O/N) : ");
erreur_alpha1:
            fflush(stdin);
            scanf(" %c", &c);
            if(toupper(c) != 'O' && toupper(c) != 'N')
            {
                printf("Voyez saisir une choix correcte (O/N) : ");
                goto erreur_alpha1;
            }
            else if(toupper(c) == 'O')
            {
                fp = fopen(nomFile , "r+t");
                fp_1 = fopen(nomFile_1 , "w+t");
                if(fp == NULL)
                {
                    printf("\.\.\.\.\.\.\.\.\.\.Impossible d\'ouvrir le fichier %s\.\.\.\.\.\.\.\.\.\.\. \n", nomFile);
                    exit(1);
                }
                if(fp_1 == NULL)
                {
                    printf("\.\.\.\.\.\.\.\.\.\.Impossible d\'ouvrir le fichier %s\.\.\.\.\.\.\.\.\.\.\. \n", nomFile_1);
                    exit(1);
                }

                tmp = (info_livre*)malloc(sizeof(info_livre));
                while(!feof(fp))
                {
                    fscanf(fp , "%d|%[^|]|%[^|]|%[^|]|%d|%d|%f|%f\n", &(tmp->ID) , &(tmp->titre) , &(tmp->auteur) , &(tmp->editeur) , &(tmp->ans_publication) , &(tmp->qte) , &(tmp->prix_jour) , &(tmp->prix_semaine));
                    if(id != tmp->ID) fprintf(fp_1 , "%d|%s|%s|%s|%d|%d|%f|%f\n" , (tmp->ID) , (tmp->titre) , (tmp->auteur) , (tmp->editeur) , (tmp->ans_publication) ,  (tmp->qte) , (tmp->prix_jour) , (tmp->prix_semaine));
                }

                n = fclose(fp);
                if(n) printf("\n\n\.\.\.\.\.\.\.\.\.\.Erreur de fermer le fichier %s\.\.\.\.\.\.\.\.\.\.\. ", nomFile);

                n = fclose(fp_1);
                if(n) printf("\n\n\.\.\.\.\.\.\.\.\.\.Erreur de fermer le fichier %s\.\.\.\.\.\.\.\.\.\.\. ", nomFile_1);

                remove(nomFile);
                n = rename(nomFile_1 , nomFile);
            }
            if(!n) printf("\nLa suppression des informations de livre de ID = %d s'effectue avec succee \n", id) ;
            else printf("\nLa suppression des informations de livre de ID = %d s'effectue avec echoue \n", id) ;
        }
        printf("\nVoulez-vous supprimer une autre livre (O/N) ? ");
erreur_alpha2:
        fflush(stdin);
        scanf(" %c", &c);
        if(toupper(c) != 'O' && toupper(c) != 'N')
        {
            printf("Voyez saisir une choix correcte (O/N) : ");
            goto erreur_alpha2;
        }
        else if(toupper(c) == 'O') supprimer_livre();
    }
}
void retourner_livre() {
    int found = 0;              // Flag pour indiquer si le livre est trouvé
    char nom[100];              // Titre du livre à retourner
    FILE *fp, *fp_1;            // Fichiers source et temporaire

    // Ouverture des fichiers
    fp = fopen(nomFile, "r");
    fp_1 = fopen(nomFile_1, "w");

    if (fp == NULL) {
        printf("Erreur : Impossible d'ouvrir le fichier source %s.\n", nomFile);
        return;
    }
    if (fp_1 == NULL) {
        printf("Erreur : Impossible d'ouvrir le fichier destination %s.\n", nomFile_1);
        fclose(fp);
        return;
    }

    // Lecture du titre du livre
    printf("Entrez le titre du livre : ");
    fflush(stdin);
    scanf("%[^\n]",nom);

    Livre livre;

    // Lecture ligne par ligne du fichier source
    while (fscanf(fp, "%d|%[^|]|%[^|]|%[^|]|%d|%d|%f|%f\n",
                  &livre.id,
                  livre.titre,
                  livre.acteur,
                  livre.editeur,
                  &livre.annee,
                  &livre.quantite,
                  &livre.prix_jour,
                  &livre.prix_fixe) == 8) {

        // Affiche le livre lu pour vérifier
        printf("Vérification du livre : %s\n", livre.titre);

        // Comparer le titre
        if (strcmp(livre.titre, nom) == 0) {  // Si le livre est trouvé
            livre.quantite += 1;             // Incrémenter la quantité
            found = 1;                       // Marquer comme trouvé
        }

        // Écrire le livre (modifié ou non) dans le fichier temporaire
        fprintf(fp_1, "%d|%s|%s|%s|%d|%d|%.2f|%.2f\n",
                livre.id,
                livre.titre,
                livre.acteur,
                livre.editeur,
                livre.annee,
                livre.quantite,
                livre.prix_jour,
                livre.prix_fixe);
    }

    // Fermeture des fichiers
    fclose(fp);
    fclose(fp_1);

    // Vérification si le livre a été trouvé
    if (found) {
        remove(nomFile);            // Supprime le fichier source
        rename(nomFile_1, nomFile); // Renomme le fichier temporaire
        printf("Le livre a été retourné avec succès.\n");
    } else {
        remove(nomFile_1);          // Supprime le fichier temporaire
        printf("Erreur : Le livre n'existe pas.\n");
    }
}


/*void retourner_livre(){
   int  found=0;
   int nom ;
 fp = fopen(nomFile, "r");
 fp_1 = fopen(nomFile_1, "w");

    if (fp == NULL) {
        printf("Erreur : Impossible d'ouvrir le fichier source %s.\n", nomFile);
        return;
    }
    if (fp_1 == NULL) {
        printf("Erreur : Impossible d'ouvrir le fichier destination %s.\n", nomFile_1);
        return;
    }
   fflush(stdin);
    printf("enter le titre de le livre:");
    fgets(nom, sizeof(nom), stdin);
    nom[strcspn(nom, "\n")] = '\0';
    Livre livre;
    while (fscanf(fp, "%d|%[^|]%[^|]%[^|]%d|%d|%f|%f\n",
                  &livre.id,
                  livre.titre,
                  livre.acteur,
                  livre.editeur,
                  &livre.annee,
                  &livre.quantite,
                  &livre.prix_jour,
                  &livre.prix_fixe) == 8) {
    if((livre.id,nom)!=0){
    fprintf(fp_1, "%d %s %s %s %d %d %.2f %.2f\n",
                livre.id,
                livre.titre,
                livre.acteur,
                livre.editeur,
                livre.annee,
                (livre.quantite),
                livre.prix_jour,
                livre.prix_fixe);
    }else{
        fprintf(fp_1, "%d %s %s %s %d %d %.2f %.2f\n",
                livre.id,
                livre.titre,
                livre.acteur,
                livre.editeur,
                livre.annee,
                (livre.quantite) + 1,
                livre.prix_jour,
                livre.prix_fixe);
                    found=1;}
    }
    if (found != 1) {
        printf("Erreur : Le livre n'existe pas.\n");
        fclose(fp);
        fclose(fp_1);
    }else
    printf("succee");
        fclose(fp);
        fclose(fp_1);
    rename(nomFile,"xi7aja.txt");
    rename(nomFile_1,nomFile);
    remove("xi7aja.txt");

}*/


void modifier_livre()
{
    recherche_livre();
    if(pos == -2.0) printf("\nLa liste est vide !!!\n");
    else
    {
        printf("Donner ID de livre que vous souhaitez modifier ses informations : ");
erreur_num6:
        fflush(stdin);
        n = scanf("%d", &id);
        if((n != 1) || (id < 0))
        {
            printf("Voyez saisir une valeur correcte (>0) : ");
            goto erreur_num6;
        }
        recherche_livre();
        if(pos != -1.0)
        {
            n = 1 ;
            fp = fopen(nomFile , "r+t");
            fp_1 = fopen(nomFile_1 , "w+t");
            if(fp == NULL)
            {
                printf("\.\.\.\.\.\.\.\.\.\.Impossible d\'ouvrir le fichier %s\.\.\.\.\.\.\.\.\.\.\. \n", nomFile);
                exit(1);
            }
            if(fp_1 == NULL)
            {
                printf("\.\.\.\.\.\.\.\.\.\.Impossible d\'ouvrir le fichier %s\.\.\.\.\.\.\.\.\.\.\. \n", nomFile_1);
                exit(1);
            }

            tmp = (info_livre*)malloc(sizeof(info_livre));
            while(!feof(fp))
            {
                fscanf(fp, "%d|%[^|]|%[^|]|%[^|]|%d|%d|%f|%f\n", &(tmp->ID) , &(tmp->titre) , &(tmp->auteur) , &(tmp->editeur) , &(tmp->ans_publication) , &(tmp->qte) , &(tmp->prix_jour) , &(tmp->prix_semaine));
                if(id != tmp->ID) fprintf(fp_1 , "%d|%s|%s|%s|%d|%d|%0.2f|%.2f\n" , (tmp->ID) , (tmp->titre) , (tmp->auteur) , (tmp->editeur) , (tmp->ans_publication) , (tmp->qte) , (tmp->prix_jour) , (tmp->prix_semaine));
                else
                {
                    puts("Les anciennes informations de ce livre sont comme suit : \n");
                    afficher_informations(tmp);
                }
            }
            puts("Donner les nouveaux informations de ce livre : \n");
            saiser_informations(&tmp);
            fprintf(fp_1 , " %d|%s|%s|%s|%d|%d|%0.2f|%.2f\n" , (tmp->ID) , (tmp->titre) , (tmp->auteur) , (tmp->editeur) , (tmp->ans_publication) , (tmp->qte) , (tmp->prix_jour) , (tmp->prix_semaine));

            n = fclose(fp);
            if(n) printf("\n\n\.\.\.\.\.\.\.\.\.\.Erreur de fermer le fichier %s\.\.\.\.\.\.\.\.\.\.\. ", nomFile);

            n = fclose(fp_1);
            if(n) printf("\n\n\.\.\.\.\.\.\.\.\.\.Erreur de fermer le fichier %s\.\.\.\.\.\.\.\.\.\.\. ", nomFile_1);

            remove(nomFile);
            n = rename(nomFile_1 , nomFile);
            if(!n) printf("\nLa modification des informations de livre de ID = %d s'effectue avec succee \n", id) ;
            else printf("\nLa modification des informations de livre de ID = %d s'effectue avec echoue \n", id) ;
        }
        else printf("Ce livre n'existe pas !!! \n");
        printf("\nVoulez-vous modifier une autre livre (O/N) ? ");
erreur_alpha3:
        fflush(stdin);
        scanf(" %c", &c);
        if(toupper(c) != 'O' && toupper(c) != 'N')
        {
            printf("Voyez saisir une choix correcte (O/N) : ");
            goto erreur_alpha3;
        }
        else if(toupper(c) == 'O') modifier_livre();
    }
}

#endif // FUNCTION_H_INCLUDED
