#include <stdio.h>

/*Aprendendo Ponteiros!!!*/

void calcula(int *c);

int main()
{
    int c = 10;

    printf("main %d %d\n", c, &c);

    //& passa o endereço de memoria
    calcula(&c);

    printf("main %d %d\n", c, &c);
}

void calcula(int *c)
{
    // o * pega o valor da variavel
    printf("Calcula %d %d \n", (*c), c);
    (*c)++;
    printf("Calcula %d %d \n", (*c), c);
}