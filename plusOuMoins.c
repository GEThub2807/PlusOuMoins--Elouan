#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int AskInt() { //Vérifie que le joueur entre un numéro//
    int number;
    while (scanf_s("%d", &number) != 1) {
        printf("Veuillez rentrer un nombre entier positif\n");
        number = getchar(); //clear le buffer//
        return 1;
    }
    return number; 
}

void Bornes(int* NumMin, int* NumMax) { //Demande au joueurs les bornes du + ou -//
    printf("Quel sera le plus petit numéro de votre jeu ?\n");
    *NumMin = AskInt(); //vérifie que le joueur rentre bien un nombre//

    printf("Quel sera le plus grand numéro de votre jeu ?\n");
    *NumMax = AskInt();
    while (*NumMin > *NumMax) { //vérifie que la borne maximale est bien supérieure à la minimale//
        printf("Le nombre minimum doit être inférieur au nombre maximum.\n");
        *NumMax = getchar();
        *NumMax = AskInt();
    }
}

int AskIntInRange(int NumMin, int NumMax) { //vérifie que le joueurs rentre bien un numéro entre les bornes qu'il a définit en amont//
    int number;
    while (1) {
        number = AskInt();
        if (number >= NumMin && number <= NumMax) {
            break;
        }
        printf("Veuillez inscrire un nombre entre %d et %d: \n", NumMin, NumMax);
    }
    return number;
}

char Replay() { //demande au joueur de rejouer ou non, ou de voir son score//
    char replay;
    while (scanf_s("%c", &replay, 1) != 1 || (replay != 'y' && replay != 'n' && replay != 'Y' && replay != 'N' && replay != 'h' && replay != 'H')) { 
        while( getchar() != '\n' );
        printf("Veuillez rentrer une réponse valide : y ou n \n");
    }
    return replay;
}

int main() {
    srand(time(NULL));

    int numberToGuess, numMin, numMax, userChoice, essais, historique;
    char replay;

    while (1) {
        Bornes(&numMin, &numMax);
        numberToGuess = rand() % (numMax - numMin + 1) + numMin;
        essais = 10;

        printf("J'ai choisi un nombre entre %d et %d, à vous de le trouver !\n", numMin, numMax);

        while (1){
            printf("Entrez votre idée ! Il vous reste %d essais : ", essais);
            userChoice = AskIntInRange(numMin, numMax);
            essais--;

            if (userChoice < numberToGuess) {
                printf("C'est plus !\n");
            }
            else if (userChoice > numberToGuess) {
                printf("C'est moins !\n");
            }
            else {
                printf("Bravo, vous avez trouvé le nombre en %d essais !\n", 3-essais);
                break;
            }if (essais == 0){
                printf("Vous aviez 3 essais, dommage, le nombre recherché était %u .", numberToGuess);
                break;
            }
        }

        printf("Voulez vous rejouer ? Ou voir votre score total ? [y/n/h]");
        replay = Replay();

        if (replay == 'n' && replay == 'N'){
            printf( "Bye bye !\n" );
            return EXIT_SUCCESS;
        }
        if (replay != 'y' && replay != 'Y'){
            break;
        }
        if (replay == 'h' && replay == 'H'){
            printf("Voici l'historique de vos nombres dévinés: \n", historique);
            Replay();
        }
    }
}