#include <stdio.h>
#include <string.h>

/*============= Prototipos de Funções================*/
void abertura();
void palavraEscolida(char palavraSecreta[20]);
int letrasChutadas(char letra, char chutes[26], int *tentativas);
void achandoPalavra(char chutes[26], char palavraSecreta[20], int *tentativas);
void chuta(char chutes[26], int *tentativas);
/*===================================================*/

int main()
{
    int acertou = 0;
    int enforcou = 0;
    char chutes[26];
    int tentativas = 0;

    char palavraSecreta[20];

    printf("%d %d\n", &chutes[0], chutes);
    abertura();
    palavraEscolida(palavraSecreta);

    do
    {
        // imprime a palavra secreta
        achandoPalavra(chutes, palavraSecreta, &tentativas);

        printf("\n");

        chuta(chutes, &tentativas);

    } while (!acertou && !enforcou);
}

void abertura()
{
    printf("\n");
    printf("*****************************************\n");
    printf("*             Jogo de Forca             *\n");
    printf("*****************************************\n\n");
}

void palavraEscolida(char palavraSecreta[20])
{
    sprintf(palavraSecreta, "MELANCIA");
}

void chuta(char chutes[26], int *tentativas)

{
    char chute;
    scanf(" %c", &chute);
    chutes[(*tentativas)] = chute;
    (*tentativas)++;
}

int letrasChutadas(char letra, char chutes[26], int *tentativas)
{
    int achou = 0;
    for (int j = 0; j < (*tentativas); j++)
    {
        if (chutes[j] == letra)
        {
            achou = 1;
            break;
        }
    }

    return achou;
}

void achandoPalavra(char chutes[26], char palavraSecreta[20], int *tentativas)
{
    printf("Voce ja deu %d chutes\n", *tentativas);

    for (int i = 0; i < strlen(palavraSecreta); i++)
    {
        int achou = letrasChutadas(palavraSecreta[i], chutes, tentativas);
        if (achou)
        {
            printf("%c ", palavraSecreta[i]);
        }
        else
        {
            printf("_ ");
        }
    }
}