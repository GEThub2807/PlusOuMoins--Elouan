/* #include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int MaxNumber= 0;
int MinNumber= 0;

int AskInt(){
    int number;
    while(scanf(" %u", &number) != 1){
        printf("\nEntrez un nombre positif entier entre %d et %d: ", MinNumber, MaxNumber);
    }
}

int AskIntInRange(int min, int  max){
    unsigned int number;
    while(true){
        number= AskInt();
        if  (number >= min && number <= max){
            break;
        }
        printf("Veuillez inscrire un nombre entre %u et %u: \n" ,min, max);
    }
    return number;
}

int main() {
    srand( time( NULL ) ); //générateur de random

    printf("Quel sera le plus petit numéro ?");
    unsigned int Min;
    Min = AskIntInRange();

    printf("Quel sera le plus grand numéro ?");
    unsigned int Max;
    Max = AskIntInRange();

    while( true ) {
        int UserChoice;
        int searchedValue = MinNumber + rand() % (MaxNumber + 1); //remplacer les var par 101
        int Try = 3;
        printf( " Débug: Valeur secrète == %d\n", searchedValue );

        while( true ) {
            printf("Veuillez saisir un entier (entre 0 et 100) : " );
            fflush( stdout );
            scanf( "%d", & UserChoice );
            Try--;

            if ( UserChoice == searchedValue ) {
                printf( "Félicitation : Il vous restait %d essais !\n", Try );
                break;
            }
            if ( UserChoice < searchedValue ) {
                printf( "La valeur à trouver est plus grande.\n" );
            } else {
                printf( "La valeur à trouver est plus petite.\n" );
            }
            if Try == 0{
                printf("Vous aviez 3 essais, dommage, le nombre recherché était %u .", searchedValue);
                break;
            }
        }

        printf( "Souhaitez-vous recommencer une partie (0 Non / 1 Oui) : " );
        fflush( stdout );
        scanf( "%d", & editedValue);
        if ( editedValue == 0 ) break;
    }

    printf( "Bye bye !\n" );

    return EXIT_SUCCESS;
}*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int AskInt(){
    int number;
    int numberError = scanf_s("%d", &number);

    while (number =! 1){
        if (numberError == 0){
            printf("Veuillez rentrer un nombre entier positif");
            return 1;
        }else{
            return number;
        }
    }
}

int AskIntInRange(int min, int  max){
    int number;
    while(1){
        number= AskInt();
        if  (number >= min && number <= max){
            break;
        }
        printf("Veuillez inscrire un nombre entre %u et %u: \n" ,min, max);
    }
    return number;
}

char Replay(){
    char replay[256];
    int rError = scanf_s("%s", replay, 256);

    if (rError == 0 || (replay != 'y' && 'n' && 'Y' && 'N')){
        printf("Veuillez rentrer une réponse valide : y ou n \n");
        return 1;
    }else{
        return replay;
    }
}


int main() {

    srand( time( NULL ) );

    while( 1 ) {
        /*printf("Quel sera le plus petit numéro ?");
        int min;
        min = AskIntInRange();

        printf("Quel sera le plus grand numéro ?");
        int max;
        max = AskIntInRange();*/
        int min = 0;
        int max = 100;
        int searchedValue = (rand() * (max - min) / RAND_MAX) + min;
        int editedValue;
        int Essais = 3;
        printf("Valeur à trouver == %d\n", searchedValue );

        while(1) {
            printf( "Veuillez saisir un entier (entre 0 et 100) : " );
            editedValue = AskInt();
            Essais--;

            if ( editedValue == searchedValue ) {
                printf( "Félicitation : il vous restait %d !\n", Essais );
                break;
            }
            if ( editedValue < searchedValue ) {
                printf( "La valeur à trouver est plus grande.\n" );
            } else {
                printf( "La valeur à trouver est plus petite.\n" );
            }
            if (Essais == 0){
                printf("Vous aviez 3 essais, dommage, le nombre recherché était %u .", searchedValue);
                break;
            }
        }

        printf( "Souhaitez-vous recommencer une partie (0 Non / 1 Oui) : " );
        scanf( "%d", & editedValue );
        if ( editedValue == 0 ) break;
    }

    printf( "Bye bye !\n" );

    return EXIT_SUCCESS;
}