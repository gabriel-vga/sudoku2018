#include <stdio.h>
#include <stdlib.h> //para usar rand e afins. E tambem para para limpar a tela
#include <conio.h> //para mudar a cor da tela
#include <windows.h> // para utilizar sleep
#define LARG_TABELA 20

//apresentacao do sudoku
void titulo(){
  printf("               000000000   000000    0000000   000000 \n");
  printf("               000000000  00000000  00000000  00000000\n");
  printf("                  000     000  000  000       000  000\n");
  printf("                  000     000  000  000  000  000  000\n");
  printf("                  000     000  000  000  000  000  000\n");
  printf("               000000     00000000  00000000  00000000\n");
  printf("               00000       000000    000000    000000\n\n");
  printf("                                  Do \n\n");
  printf("      00000000  000  000  0000000    000000   000   000  000  000 \n");
  printf("     000000000  000  000  00000000  00000000  000   000  000  000 \n");
  printf("     000        000  000  000  000  000  000  000  000   000  000 \n");
  printf("      0000000   000  000  000  000  000  000  0000000    000  000 \n");
  printf("           000  000  000  000  000  000  000  0000000    000  000 \n");
  printf("     000000000  00000000  00000000  00000000  000  000   00000000  \n");
  printf("     00000000    000000   0000000    000000   000   000   000000  \n\n");
  printf("   -=-=-=-=-=-=-=-=-=-=--=-=--=-=--=-=--=-=--=-=--=-=--=-=--=-=-=-");
  printf(" \n\t\t\t\t\tJogo do Sudoku v1.0\n\n");
  printf("         Grupo: Gabriel, Gessica, Larissa e Lucas - turma A\n\n");
   printf("                        IFSP - Hortolandia - 2018");
}

//bordas do menu
void borda_superior(){
int i;
printf("%c", 201);
for(i=0; i < LARG_TABELA; i++)
  printf("%c", 205);
printf("%c\n", 187);
}

void borda_inferior(int tamX){
int i;
printf("%c", 200);
for(i=0; i < LARG_TABELA; i++)
  printf("%c", 205);
printf("%c\n", 188);
}


void coluna(int tamX, char str[]){
int i;

printf("%c",186);
printf("%-19s",str);
  printf("%c",32);
printf("%c\n",186);
}
void linha_horizontal(int tamX){
int i;
printf("%c",204);
for(i=0; i < tamX; i++)
  printf("%c",205);
printf("%c\n",185);
}


void bordas1(){ //função para gerar o menu
borda_superior();
coluna(LARG_TABELA,"  SUDOKU: THE GAME");
linha_horizontal(LARG_TABELA);
coluna(LARG_TABELA,"     DIFICULDADE ");
coluna(LARG_TABELA," ");
coluna(LARG_TABELA,"    f -> FACIL ");
coluna(LARG_TABELA,"    m -> MEDIO ");
coluna(LARG_TABELA,"    d -> DIFICIL ");
linha_horizontal(LARG_TABELA);
coluna(LARG_TABELA,"       MODELO  ");
coluna(LARG_TABELA," ");
coluna(LARG_TABELA,"    1 -> Jogo 1 ");
coluna(LARG_TABELA,"    2 -> Jogo 2 ");
coluna(LARG_TABELA,"    3 -> Jogo 3 ");
coluna(LARG_TABELA,"    4 -> Jogo 4 ");
coluna(LARG_TABELA,"    5 -> Jogo 5 ");
coluna(LARG_TABELA,"    6 -> Jogo 6 ");
coluna(LARG_TABELA,"    7 -> Jogo 7 ");
coluna(LARG_TABELA,"    8 -> Jogo 8 ");
coluna(LARG_TABELA,"    9 -> Jogo 9 ");
coluna(LARG_TABELA," ");
coluna(LARG_TABELA,"     0 -> Sair ");
borda_inferior(LARG_TABELA);

printf("\n");
}

void jogox(int dif, int jogo[9][9], int i, int j, int randomc, int desafio[9][9]){ //função para imprimir a matriz com o jogo que será jogado pelo usuário
    int aux; //auxiliar para transferência segura dos valores
    if (dif=='d'){ //se a dificuldade for dificil
        for (i = 0; i < 9; i++){
            if (i==3 || i==6){
                printf("------+-------+-------"); //vai imprimir faixas antes da quarta e sétima linhas
                printf("\n");
            }
            for (j = 0; j < 9; j++){
                if (j==3 || j==6){
                    printf("| "); //vai imprimir faixas antes da quarta e sétima colunas
                }
                if (((i==rand()%9 || j==rand()%9) || ((rand()%9)%2==0) || ((rand()%9)%7==0) || ((rand()%9)%3==0) || ((rand()%9)%5==0) && randomc<8)){
                /*rand's para gerar números, se eles corresponderem as condições propostas, esses valores não estarão na matriz exibida nem na que o usuário
                deverá preencher. Mais alto a dificuldade, mais condições e maior limite de espaços vazios por linha. Menor a dificuldade, menos condições*/
                    printf("  "); //imprime um espaço aonde que representa a casa vazia que o usuário deverá achar o valor
                    desafio[i][j]=NULL; //dá valor nulo para a matriz desafio, que deverá depois ser preenchida pelo usuário
                    randomc++;//contador de casas vazias, nesse caso o limite é 8 por linha, sendo menor nas outras dificuldades
                }else{
                    printf("%d ",jogo[i][j]); //se os rand's não equivalerem às condições, é impresso o valor da posição normalmente
                    aux=jogo[i][j];
                    desafio[i][j]=aux; //nesse caso, o valor daquela posição na matriz original será passada para a matriz desafio, não sendo mais necessário preencher
                }
            }
            randomc=0; //zera o contador, para que na próxima linha ainda possa ter 7 espaços vazios
            printf("\n");//pula para a próxima linha
        }
        //abaixo, exatamente as mesmas coisas, mas para as dificuldades médio e fácil, com condições menos variadas, logo mais números exibidos
        }else if (dif=='m'){
            for (i = 0; i < 9; i++){
                if (i==3 || i==6){
                    printf("------+-------+-------");
                    printf("\n");
                }
                    for (j = 0; j < 9; j++){
                        if (j==3 || j==6){
                            printf("| ");
                        }
                        if (((i==rand()%9 || j==rand()%9) || ((rand()%9)%2==0) || ((rand()%9)%3==0)  && randomc<6)){
                            printf("  ");
                            desafio[i][j]=NULL;
                            randomc++;
                        }else{
                            printf("%d ",jogo[i][j]);
                            aux=jogo[i][j];
                            desafio[i][j]=aux;
                          }
                    }
                    randomc=0;
                    printf("\n");
            }
        }else{
            for (i = 0; i < 9; i++){
                if (i==3 || i==6){
                    printf("------+-------+-------");
                    printf("\n");
                }
                for (j = 0; j < 9; j++){
                    if (j==3 || j==6){
                        printf("| ");
                    }
                    if (((i==rand()%9 || j==rand()%9) || ((rand()%9)%2==0) || ((rand()%9)%7==0) && randomc<4)){
                        printf("  ");
                        desafio[i][j]=NULL;
                        randomc++;
                    }else{
                        printf("%d ",jogo[i][j]);
                        aux=jogo[i][j];
                        desafio[i][j]=aux;
                    }
                }
                randomc=0;
                printf("\n");
            }
        }
}

void gameplay(int x, int y, int res, int desafio[9][9], int jogo[9][9],int vida){ //função do gameplay em si, aonde o usuário irá preencher o sudoku
    int fim=0; //declara uma variável para conferir se o sudoku está todo preenchido

    do{
        printf("\nVOCE POSSUI %d VIDAS\n",vida); //exibe quantas vidas o usuário ainda possui, perdendo uma a uma conforme erra uma casa
        fim=0;
        do{
            printf("\n\nInsira uma linha (1 a 9): ");
            scanf("%d",&x); //recebe o número da linha que o usuário deseja preencher
        }while(x!=1 && x!=2 && x!=3 && x!=4 && x!=5 && x!=6 && x!=7 && x!=8 && x!=9); //se o número não estiver entre 1 e 9, a mensagem será reexibida
        x=x-1; //como a matriz se inicia em 0, será diminuido 1 do valor dado pelo usuário
        do{
            printf("\n\nInsira uma coluna (1 a 9): ");
            scanf("%d",&y); //recebe o número da coluna que o usuário deseja preencher
        }while(y!=1 && y!=2 && y!=3 && y!=4 && y!=5 && y!=6 && y!=7 && y!=8 && y!=9); //se o número não estiver entre 1 e 9, a mensagem será reexibida
        y=y-1; //como a matriz se inicia em 0, será diminuido 1 do valor dado pelo usuário
        if(desafio[x][y]!=NULL){
            printf("\nPosicao ja preenchida.\n"); //se o usuário der a posição de um espaço já preenchido, ele deverá dar outras coordenadas (não perdendo vida por isso)
        }else{
            printf("\nInsira um valor para preencher (1 a 9): ");
            scanf("%d",&res); //usuário responde que valor acha que deverá ser preenchido no campo vazio
            if(res==jogo[x][y]){
                printf("\nRESPOSTA CORRETA!!!\n\n"); //se o valor dado pelo usuário for exatamente o mesmo presente na matriz original, naquela posição, ele acertou
                desafio[x][y]=res; //como acertou, o valor será atribuido ao campo que estava vazio
                }else{
                printf("\nRESPOSTA ERRADA, TENTE NOVAMENTE\n\n"); //se o valor dado não for igual ao da matriz original naquela posição, ele errou
                vida--; //como errou, perderá uma vida
            }
            //abaixo, será impresso o sudoku inteiro, se o usuário tiver acertado, o valor respondido também será exibido dentro da tabela
            for (x = 0; x < 9; x++){
                if (x==3 || x==6){
                    printf("------+-------+-------");
                    printf("\n");
                }
                for (y = 0; y < 9; y++){
                    if (y==3 || y==6){
                        printf("| ");
                    }
                    if (desafio[x][y]==NULL){
                        printf("  ");//se o valor for nulo, a tabela apenas mostrará um espaço vazio
                    }else{
                        printf("%d ",desafio[x][y]); //se não for vazio, exibe o valor
                    }
                }
                printf("\n");
            }
        }
        for (x = 0; x < 9; x++){
                for (y = 0; y < 9; y++){
                    if(desafio[x][y]==jogo[x][y]){ //aqui o sistema confere casa por casa se na tabela preenchida estão iguais a da matriz original
                        fim++; //se a casa estiver preenchida, soma +1 para a variável fim
                    }
                }
        }
        if(vida==0){
            printf("\nVOCE PERDEU!!!\n"); //se o usuário perder todas as vidas, ele perde
            exit(0); //se perder, o jogo fecha
        }
    }while(fim<81); //o ciclo do DO será feito enquanto a variável fim valer menos que 81, se chegar a 81 todos os campos estão preenchidos
    printf("\nPARABENS, VOCE VENCEU!!!!!!\n"); //se todos os campos estão preenchidos, você venceu
}


int main(){
    system("color 5F"); //cor de fundo roxo (5) e cor das letras branco brilhante (F)
    system("color 5F"); //cor de fundo roxo (5) e cor das letras branco brilhante (F)
    titulo();
    Sleep(5000);//utilizamos sleep para aguardar 5 segundos antes de limpar a tela e mostrar o menu
    system("cls");
    system("color 5F");//cor de fundo roxo (5) e cor das letras branco brilhante (F)

    printf("BEM-VINDO AO SUDOKU\n\n");
    printf("O objetivo deste jogo e a colocacao de numeros de 1 a 9 ");
    printf("em cada uma das celulas vazias numa grade de 9x9, constituida por 3x3 subgrades chamadas regioes.\n");
    printf("Este quebra-cabeca contem algumas pistas iniciais, que sao numeros inseridos");
    printf(" em algumas celulas, de maneira a permitir uma inducao ou deducao dos numeros em celulas que estejam vazias.\n");
    printf("Cada coluna, linha e regiao so pode ter um numero de cada um dos 1 a 9.\n");
    printf("Resolver o problema requer apenas raciocinio logico e algum tempo.\n\n");
    printf("BOA SORTE!\n");
    Sleep(15000);//utilizamos sleep para aguardar 15 segundos antes de limpar a tela e mostrar o menu
    system("cls"); // utilizamos system("cls") para limpar a tela

    char dif; //variável da dificuldade
    int i,j,op, desafio[9][9], randomc=0, x, y, res,vida=20, /*auxiliares para contar e imprimir matrizes, matriz jogável, contador de condições de
    dificuldade, resposta do usuário no jogo e vidas, iniciadas em 20*/
        //abaixo, 9 modelos prontos de sudoku, os quais terão casas escondidas e não transferidas para a matriz de jogo e que serão usadas para conferir
         jogo1[9][9]=
        {{8,3,5,4,1,6,9,2,7},
         {2,9,6,8,5,7,4,3,1},
         {4,1,7,2,9,3,6,5,8},
         {5,6,9,1,3,4,7,8,2},
         {1,2,3,6,7,8,5,4,9},
         {7,4,8,5,2,9,1,6,3},
         {6,5,2,7,8,1,3,9,4},
         {9,8,1,3,4,5,2,7,6},
         {3,7,4,9,6,2,8,1,5}},
         jogo2[9][9]=
        {{8,7,6,5,4,3,2,1,9},
         {2,5,3,6,1,9,7,8,4},
         {1,9,4,8,7,2,3,6,5},
         {4,8,5,7,3,1,9,2,6},
         {3,6,2,9,5,8,4,7,1},
         {9,1,7,2,6,4,5,3,8},
         {6,2,9,4,8,7,1,5,3},
         {5,4,1,3,2,6,8,9,7},
         {7,3,8,1,9,5,6,4,2}},
         jogo3[9][9]=
        {{5,6,3,2,1,9,8,4,7},
         {7,1,8,4,5,3,9,2,6},
         {2,9,4,6,7,8,3,1,5},
         {1,2,5,7,9,6,4,3,8},
         {6,8,7,3,4,2,1,5,9},
         {3,4,9,1,8,5,7,6,2},
         {4,5,1,8,2,7,6,9,3},
         {9,7,6,5,3,1,2,8,4},
         {8,3,2,9,6,4,5,7,1}},
         jogo4[9][9]=
        {{1,3,2,6,5,8,9,4,7},
         {5,7,8,1,9,4,2,3,6},
         {9,4,6,7,3,2,5,8,1},
         {8,1,7,9,2,3,4,6,5},
         {6,2,3,5,4,1,7,9,8},
         {4,9,5,8,7,6,3,1,2},
         {2,8,9,4,1,7,6,5,3},
         {7,5,1,3,6,9,8,2,4},
         {3,6,4,2,8,5,1,7,9}},
         jogo5[9][9]=
        {{9,2,5,4,7,8,3,6,1},
         {6,7,3,1,5,9,4,8,2},
         {4,8,1,6,3,2,9,5,7},
         {2,3,8,7,6,1,5,4,9},
         {7,6,4,2,9,5,8,1,3},
         {1,5,9,8,4,3,7,2,6},
         {5,9,6,3,2,4,1,7,8},
         {3,1,2,5,8,7,6,9,4},
         {8,4,7,9,1,6,2,3,5}},
         jogo6[9][9]=
        {{7,5,9,1,2,8,4,6,3},
         {1,2,6,4,9,3,7,5,8},
         {3,8,4,6,7,5,9,1,2},
         {4,3,7,8,5,9,1,2,6},
         {6,9,5,2,4,1,3,8,7},
         {8,1,2,7,3,6,5,4,9},
         {2,6,3,5,1,7,8,9,4},
         {9,4,1,3,8,2,6,7,5},
         {5,7,8,9,6,4,2,3,1}},
         jogo7[9][9]=
        {{8,2,7,1,3,9,6,5,4},
         {6,3,4,2,5,7,1,8,9},
         {1,5,9,4,8,6,3,7,2},
         {4,9,5,3,6,2,7,1,8},
         {7,8,6,9,1,4,5,2,3},
         {3,1,2,5,7,8,4,9,6},
         {5,4,8,6,2,1,9,3,7},
         {2,6,1,7,9,3,8,4,5},
         {9,7,3,8,4,5,2,6,1}},
         jogo8[9][9]=
        {{3,7,4,1,6,8,2,5,9},
         {5,1,9,4,2,7,6,8,3},
         {2,8,6,3,9,5,7,1,4},
         {6,9,8,5,4,1,3,7,2},
         {1,2,3,7,8,6,9,4,5},
         {4,5,7,9,3,2,1,6,8},
         {9,6,2,8,7,4,5,3,1},
         {8,3,5,6,1,9,4,2,7},
         {7,4,1,2,5,3,8,9,6}},
         jogo9[9][9]=
        {{3,6,1,4,7,2,5,8,9},
         {9,8,4,5,1,6,7,2,3},
         {5,7,2,9,3,8,6,1,4},
         {4,5,3,7,2,1,9,6,8},
         {6,1,7,8,9,3,2,4,5},
         {2,9,8,6,4,5,1,3,7},
         {8,4,6,1,5,7,3,9,2},
         {7,2,9,3,6,4,8,5,1},
         {1,3,5,2,8,9,4,7,6}};

    bordas1();
    do{
        printf("Selecione a dificuldade (f, m ou d): ");
        scanf("%c", &dif); //jogador responde a dificuldade em que deseja jogar
        if (dif!='f' && dif!='m' && dif!='d'){
            printf("\nDificuldade incorreta, insira novamente. \n"); //se a dificuldade não ser nenhuma das 3 existentes, será enviado um aviso
        }
    }while(dif!='f' && dif!='m' && dif!='d'); //o sistema irá pedir a dificuldade até que seja respondido uma resposta válida
    do{
        printf("\nSelecione qual modelo de jogo deseja (de 1 a 9, 0 para sair): ");
        scanf("%d", &op); //usuário responde qual dos jogos quer jogar, responde 0 se quiser sair
        printf("\n");
        printf("\n");
        switch(op)
        {
            case 1:
                jogox(dif,jogo1,i,j,randomc,desafio); /*chama a função para exibir o sudoku a ser resolvido, usando as variáveis equivalentes.
                Apenas a matriz jogo será diferente de caso para caso, mantendo as mesmas variáveis nos outros casos*/
                gameplay(x,y,res,desafio,jogo1,vida);/*chama a função aonde será feito o gameplay, usando as variáveis equivalentes.
                Apenas a matriz jogo será diferente de caso para caso, mantendo as mesmas variáveis nos outros casos*/
                break;

            case 2:
                jogox(dif,jogo2,i,j,randomc,desafio);
                gameplay(x,y,res,desafio,jogo2,vida);
                break;

            case 3:
                jogox(dif,jogo3,i,j,randomc,desafio);
                gameplay(x,y,res,desafio,jogo3,vida);
                break;

            case 4:
                jogox(dif,jogo4,i,j,randomc,desafio);
                gameplay(x,y,res,desafio,jogo4,vida);
                break;

            case 5:
                jogox(dif,jogo5,i,j,randomc,desafio);
                gameplay(x,y,res,desafio,jogo5,vida);
                break;

            case 6:
                jogox(dif,jogo6,i,j,randomc,desafio);
                gameplay(x,y,res,desafio,jogo6,vida);
                break;

            case 7:
                jogox(dif,jogo7,i,j,randomc,desafio);
                gameplay(x,y,res,desafio,jogo7,vida);
                break;

            case 8:
                jogox(dif,jogo8,i,j,randomc,desafio);
                gameplay(x,y,res,desafio,jogo8,vida);
                break;

            case 9:
                jogox(dif,jogo9,i,j,randomc,desafio);
                gameplay(x,y,res,desafio,jogo9,vida);
                break;

            case 0:
                printf("\n\nFECHANDO...");
                exit(0); //se o usuário responder '0', o jogo se encerrará
                break;

            default:
                printf("Comando incorreto, responda novamente.\n\n");//se o usuário não responder nenhum valor inteiro entre 0 e 9, será avisado e terá que responder novamente
        }
    }while(op!=0 && op!=1 && op!=2 && op!=3 && op!=4 && op!=5 && op!=6 && op!=7 && op!=8 && op!=9); //sistema pedirá qual jogo o usuário quer até que dê uma resposta válida
    return 0;
}

