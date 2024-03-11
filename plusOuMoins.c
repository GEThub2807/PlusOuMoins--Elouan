#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

unsigned int MaxNumber= 0;
unsigned int MinNumber= 0;

int AskInt(){
    unsigned int number;
    while(scanf(" %u", &number) != 1){
        printf("\nEntrez un nombre positif entier entre %u et %u: ", MinNumber, MaxNumber);
    }
}

unsigned int AskIntInRange(uint min, uint  max){
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
        unsigned int UserChoice;
        unsigned int searchedValue = MinNumber + rand() % (MaxNumber + 1); //remplacer les var par 101
        unsigned int Try = 3;
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
        scanf( "%d", & editedValue );
        if ( editedValue == 0 ) break;
    }

    printf( "Bye bye !\n" );

    return EXIT_SUCCESS;
}

/*
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>


int main() {

    // On commence par initialiser le générateur de nombre pseudo-aléatoires.
    srand( time( NULL ) );

    while( true ) {
        // Tirer une valeur aléatoire entre 0 et 100.
        int searchedValue = rand() % 101;       // % => Reste de la division entière
        int editedValue;
        int score = 0;
        printf( "MegaGame V1.0 - Valeur secrète == %d\n", searchedValue );

        while( true ) {
            printf( "Veuillez saisir un entier (entre 0 et 100) : " );
            fflush( stdout );
            scanf( "%d", & editedValue );
            score++;

            if ( editedValue == searchedValue ) {
                printf( "Félicitation : trouvé en %d coups !\n", score );
                break;      // intérrompre la boucle des manches (pas celle des parties)
            }
            if ( editedValue < searchedValue ) {
                printf( "La valeur à trouver est plus grande.\n" );
            } else {
                printf( "La valeur à trouver est plus petite.\n" );
            }
        }

        printf( "Souhaitez-vous recommencer une partie (0 Non / 1 Oui) : " );
        fflush( stdout );
        scanf( "%d", & editedValue );
        if ( editedValue == 0 ) break;
    }

    printf( "Bye bye !\n" );

    return EXIT_SUCCESS;
}*/