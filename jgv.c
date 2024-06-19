#include <stdio.h>
#include <time.h>
#include <stdlib.h>

#define QNT_LINHAS 3
#define QNT_COLUNAS 3
#define JOGADOR_X 'X'
#define JOGADOR_O 'O'
#define EMPATE 'E'

int jogar(char tabul[3][3], char jogada)
{
int pos;
        scanf("%d", &pos);
        if(pos > 9 || pos < 1){
            printf("Posicao invalida, digite numeros entre 1 e 9\n");
            return 1;
        }
        if(pos >= 1 &&pos <= 3){
        if(tabul[0][pos - 1] == '_'){
            tabul[0][pos - 1] = jogada;
            }
        else{
            printf("Essa posicao ja foi escolhida\n");
            return 1;
        }
        }
        else if(pos >= 4 && pos <= 6){
        if(tabul[1][pos - 4] == '_'){
            tabul[1][pos - 4] = jogada;
            }
        else{
            printf("Essa posicao ja foi escolhida\n");
            return 1;
        }
        }
        else if(pos >= 7 && pos <= 9){
        if(tabul[2][pos - 7] == '_'){
            tabul[2][pos - 7] = jogada;
            }
        else{
            printf("Essa posicao ja foi escolhida\n");
            return 1;
        }
        }
        return 0;
        }

char vencedor(char tabul[QNT_LINHAS][QNT_COLUNAS], char jogador){
    int i;
    char ganhador = EMPATE;
     for(i = 0; i < QNT_COLUNAS; i++){
        if(tabul[0][i] == jogador && tabul[1][i] == jogador && tabul[2][i] == jogador)
        ganhador = jogador;      
    }
    for(i = 0; i < QNT_LINHAS; i++){
        if(tabul[i][0] == jogador && tabul[i][1] == jogador && tabul[i][2] == jogador)
        ganhador = jogador;
    }
        if(tabul[0][0] == jogador && tabul[1][1] == jogador && tabul[2][2] == jogador){
            ganhador = jogador;  
    }
    else if(tabul[0][2] == jogador && tabul[1][1] == jogador && tabul[2][0] == jogador){
        ganhador = jogador;
    }
    return ganhador;
}


void maquinaJog(char tabul[QNT_LINHAS][QNT_COLUNAS]){
    srand(time(NULL));
    while(1){
    int lin = rand() % 3;
    int col = rand() % 3;
    if(tabul[lin][col] == '_'){
        tabul[lin][col] = 'O';
        break;
    }
    else continue;
    }
}

int main()
{
int i, j, k;
char ganhador = EMPATE;
int cont = 1;
char tabul[QNT_LINHAS][QNT_COLUNAS];
for(i = 0; i < QNT_COLUNAS; i++){
    for(j = 0; j < QNT_LINHAS; j++){ // Underline a todas as posicoes da matriz
        tabul[i][j] = '_';
    }
}

while(1){
    if(cont % 2 != 0){
        printf("Jogador X sua vez, digite a posicao desejada\n");
         for(i = 0; i < 3; i++){
            for(j = 0; j < 3; j++){
            printf("%c", tabul[i][j]);
            }
            printf("\n");
        }
        k = jogar(tabul, JOGADOR_X);
        if(k == 1)
        continue;
    }
    else{
        maquinaJog(tabul);
    }
    ganhador = vencedor(tabul, JOGADOR_X);
    if(ganhador != JOGADOR_X){
        ganhador = vencedor(tabul, JOGADOR_O);
        
        }
   
    if(ganhador != EMPATE){
        printf("O vencedor foi o Jogador %c\n", ganhador);
        for(i = 0; i < 3; i++){
            for(j = 0; j < 3; j++){
            printf("%c", tabul[i][j]);
            }
            printf("\n");
        }
        break;
    }
    else if(cont == 10){
        printf("EMPATE\n");
         for(i = 0; i < 3; i++){
            for(j = 0; j < 3; j++){
                printf("%c", tabul[i][j]);
            }
            printf("\n");
        
    }
    break;

}

cont++;
}
return 0;
}