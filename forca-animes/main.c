#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <time.h>

#define MAX_ERROS 4

char* escolherPalavra(char palavras[][50], int numPalavras) {
    srand(time(NULL)); 
    int indice = rand() % numPalavras; 
    return palavras[indice];
}


void imprimirPalavra(char* palavra, char letrasAdivinhadas[]) {
    int tamanho = strlen(palavra);
    for (int i = 0; i < tamanho; i++) {
        if (letrasAdivinhadas[i] == 1) { 
            printf("%c ", palavra[i]);
        } else { 
            printf("_ ");
        }
    }
    printf("\n");

}


int checarLetra(char* palavra, char letra, char letrasAdivinhadas[]) {
    int tamanho = strlen(palavra);
    int acertou = 0;
    for (int i = 0; i < tamanho; i++) {
        if (tolower(palavra[i]) == tolower(letra)) { 
            letrasAdivinhadas[i] = 1;
            acertou = 1;
        }
    }
    return acertou;
}

int main() {
    char palavras[][50] = { "Naruto", "Kimetsu-no-Yaiba", "Bleach", "Jujutsu-Kaisen", "One-Piece", "Your-Name", "Tensei-Shitara", "Solo-Leveling", "Dororo", "Dorohedoro", "No-Game No-Life", "Haikyuu", "Chainsaw-Man", "Kuroko-no-Basket", "Golden-Time", "KonoSuba", "Koe-No-Katachi", "Arifureta", "Your-Lie-in-April", "Shuumatsu-no-Valkyrie", "SpyXFamily", "Dragon-Ball", "Violet-Evergarden", "Castelvania", "Kakegurui", "Hellsing", "Sailor-moon", "Blue-Lock", "Super-Onze", "Tokyo-Revengers", "Tokyo-Ghoul", "Tonikaku-Kawaii", "Kaijuu-n8", "Toradora", "Shingeki-no-Kyojin", "One-Punch-Man", "Berseker", "JOJO", "Yu-Gi-Oh", "SK8", "Bubbles", "A-Viagem-de-Chihiro", "Yo-kai-Watch", "Meu-Amigo-Totoro", "Ponyo", "Assassination-Classroom", "Fullmetal-Alchemist", "HunterXHunter", "Death-Note", "Boku-no-hero", "Black-Clover", "Bakugo", "Evangelion", "Sword-Art-Online", "Ao-no-Exorcist", "Fumetsu-no-Anata-e", "Soul-Eater", "Fire-Force", "Another" };
    int numPalavras = 59 ;
    char* palavra = escolherPalavra(palavras, numPalavras);

    int tamanho = strlen(palavra), pon=0;
    char letrasAdivinhadas[tamanho];
    memset(letrasAdivinhadas, 0, tamanho); 

    int numErros = 0;
   printf("Bem Vindo á forca dos animes, você terá 4 chances de acertar qual o anime. \n Algumas palavras podem conter hífen (-), que é utlizado como o 'espaço' entre as palavras.\nSe colocar uma palavra, e errar, perde. Se você não acertar, tu perde, morô? Essa é a vida. \n \t\t\t\tBOA SORTE!!\n\n");
    while (numErros < MAX_ERROS) {
        printf("Palavra: ");
        imprimirPalavra(palavra, letrasAdivinhadas);

        printf("Digite uma letra: ");
        char letra;
        scanf(" %c", &letra);

        if (checarLetra(palavra, letra, letrasAdivinhadas)) {
            printf("Acertou!\n\n");
          pon+20;
            int todasAdivinhadas = 1;
            for (int i = 0; i < tamanho; i++) {
                if (letrasAdivinhadas[i] == 0) {
                    todasAdivinhadas = 0;
                    break;
                }
            }
            if (todasAdivinhadas) {
                printf("Parabéns, você ganhou!!\nEra %s. \nPontuação: %d.\n\n\n\n\nCréditos:\nCriado por: Gabriel Gustavo Mostowski\nCristian Emmanuel Sampietro dos Santos",palavra, pon);
                return 0;
            }
        } else {
            printf("Errou!\n\n");
          pon-15;
            numErros++;
          printf("Você tem %d erro.\n",numErros);
        }
    }

    printf("Você perdeu o jogo! A palavra era %s. \nPontuação: %d.\n\n\n\n\nCréditos:\nCriado por: Gabriel Gustavo Mostowski\nCristian Emmanuel Sampietro dos Santos", palavra, pon);
    return 0;
}
