#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#define tamL 10
#define tamC 8

void LimpaBuffer()
{
    int c;
    while(c = getchar() != '\n' && c != EOF);
}

int main()
{
    setlocale(LC_ALL,"portuguese");
    float pagamento[3]={0, 0, 0};

    float valor=50, valorM=25, porcentagem;

    int i, j, N=0, linha, coluna, quantidade=tamC*tamL, v, k, N4, cancelar, escolha;

    int ocupados[tamL]= {0}, Maior_ocupado= 0, Menor_ocupado= tamL, ocupado_Total, livres=tamC*tamL;

    int ingressoI[2]={0, 0}, ingressoM[2]={0, 0}, ingresso;

    int sala[tamL][tamC]={0}, salaP[tamL][tamC];

    int vizEsq, vizDir;

    int pontuacaoBase;

    int distColuna, distColuna2, melhorDistColuna;

    int melhorLinha=-1, melhorColuna, melhorScore;

    int scoreAtual, colunaDoMeio, todosLivres;


    while(N!=100)
    {
        do
        {
            printf("+--------------------------------------------------------------------------------+\n");
            printf("|         Filme: Star Wars                                                       |\n");
            printf("|         Seção: 3h 30mim                                                        |\n");
            printf("|         Sala:  1D                                                              |\n");
            printf("+--------------------------------------------------------------------------------+\n");
            printf("|         Ingressos                                                              |\n");
            printf("+--------------------------------------------------------------------------------+\n");
            printf("|         Valor:                                                                 |\n");
            printf("|                                                                                |\n");
            printf("|         Inteiro.........................R$%.2f\t                         |\n",valor);
            printf("|                                                                                |\n");
            printf("|         Meia............................R$%.2f\t                         |\n",valorM);
            printf("|                                                                                |\n");
            printf("+--------------------------------------------------------------------------------+\n");
            printf("|         Funções                                                                |\n");
            printf("+--------------------------------------------------------------------------------+\n");
            printf("|         1 Estatísticas gerais da sala                                          |\n");
            printf("|         2 Compra dos ingressos                                                 |\n");
            printf("|         3 Cancelar a compra do ingresso                                        |\n");
            printf("|         4 Pagamento dos ingressos                                              |\n");
            printf("|         5 Sugetão de assentos                                                  |\n");
            printf("|         6 Verificar fileiras críticas                                          |\n");
            printf("|         7 Fechar o programa                                                    |\n");
            printf("+--------------------------------------------------------------------------------+\n");
            printf("          Escolha uma função:");
            v = scanf("%d",&N);
            LimpaBuffer();

            system("cls");
        }while((N<1)||(N>7) || v == 0);
        switch(N)
        {
        case 1:
            system("cls");

            ocupado_Total= quantidade - livres;
            porcentagem=((float)ocupado_Total/quantidade)*100;

            printf("+--------------------------------------------------------------------------------+\n");
            printf("|                    Mapa de assentos (1 = ocupado, 0 = livre)                   |\n");
            printf("+--------------------------------------------------------------------------------+\n");
            printf("|                           ##  1  2  3  4  5  6  7  8                           |\n");
            printf("|                                                                                |\n");
            for(i=0;i<tamL;i++)
            {
                i++;
                printf("|                           %.02d  ",i);
                i--;
                for(j=0;j<tamC;j++)
                {
                    printf("%d  ",sala[i][j]);
                    if (sala[i][j] == 1)
                    {
                        ocupados[i]++;
                    }
                }
                if(ocupados[i] > Maior_ocupado)
                {
                    Maior_ocupado= ocupados[i];
                }
                if(ocupados[i] < Menor_ocupado)
                {
                    Menor_ocupado= ocupados[i];
                }
                printf("                         |\n");
            }
            printf("+--------------------------------------------------------------------------------+\n");
            printf("|      Total de assentos: %d       |     Fileira com a maior\\menor ocupação      |\n", quantidade);
            printf("+--------------------------------------------------------------------------------+\n");
            printf("|  Ocupados: %.02d                    |                                             |\n", ocupado_Total);
            printf("|                                  | Mais ocupada: ");
            for(i=0; i<tamL; i++)
            {
                if(ocupados[i] == Maior_ocupado)
                {
                    i++;
                    printf("%.02d ", i);
                    i--;
                }
                else
                {
                    printf("   ", i);
                }

            }
            printf("|\n");
            printf("|  Livres:%.02d                       |                                             |\n", livres);
            printf("|                                  | Menos ocupada:");
            for(i=0; i<tamL; i++)
            {
                if(ocupados[i] == Menor_ocupado)
                {
                    i++;
                    printf("%.02d ", i);
                    i--;
                }
                else
                {
                    printf("   ", i);
                }
            }
            printf("|\n");
            printf("|  Porcentagem de ocupação: %6.2f%%|                                             |\n", porcentagem);
            printf("+--------------------------------------------------------------------------------+\n");

            system("pause");
            system("cls");
        break;



        case 2:
            do
            {
                do
                {
                    system("cls");
                    printf("+--------------------------------------------------------------------------------+\n");
                    printf("|                    Mapa de assentos (1 = ocupado, 0 = livre)                   |\n");
                    printf("+--------------------------------------------------------------------------------+\n");
                    printf("|                           ##  1  2  3  4  5  6  7  8                           |\n");
                    printf("|                                                                                |\n");
                    for(i=0;i<tamL;i++)
                    {
                        i++;
                        printf("|                           %.02d  ",i);
                        i--;
                        for(j=0;j<tamC;j++)
                        {
                            printf("%d  ",sala[i][j]);
                        }
                        printf("                         |\n");
                    }
                    printf("+--------------------------------------------------------------------------------+\n");
                    printf("|         Assentos disponiveis restantes:%.02d\t                                 |\n", livres);
                    printf("+--------------------------------------------------------------------------------+\n");
                    printf("|         Sugestão (Função 5)                                                    |\n");
                    printf("|                                                                                |\n");
                    if(melhorLinha == -1)
                    {
                        printf("|         Não há sugestão disponível                                             |\n");
                    }
                    else
                    {
                        if(escolha == 1)
                        {
                            printf("|         Melhor assento: Fileira %.02d, Assento %d                                  |\n", melhorLinha + 1, melhorColuna + 1);
                        }
                        else
                        {
                            printf("|         Melhor grupo: Fileira %.02d: Assentos %d até %d                             |\n", melhorLinha + 1, melhorColuna + 1, melhorColuna + N4);
                        }
                    }
                    printf("|                                                                                |\n");
                    printf("|                                                                                |\n");
                    printf("+--------------------------------------------------------------------------------+\n");
                    printf("Digite o número de ingressos(Inteiro):");
                    if (scanf("%d",&ingresso) == 0)
                    {
                        ingresso = 0;
                    }
                    LimpaBuffer();
                    ingressoI[0]=ingresso;

                    printf("Digite o número de ingressos(Meia):");
                    if (scanf("%d",&ingresso) == 0)
                    {
                        ingresso = 0;
                    }
                    LimpaBuffer();
                    ingressoM[0]=ingresso;
                }while(ingressoI[0]>livres || ingressoM[0]>livres || (ingressoI[0]+ingressoM[0])>livres);

                if(ingressoI[0] > 0 || ingressoM[0] > 0)
                {

                pagamento[0]=(ingressoI[0]+ingressoI[1])*valor;
                pagamento[1]=(ingressoM[0]+ingressoM[1])*valorM;
                pagamento[2]=pagamento[0]+pagamento[1];
                }

                N=1;
                while(N <= ingressoI[0])
                {

                    system("cls");
                    printf("+--------------------------------------------------------------------------------+\n");
                    printf("|                    Mapa de assentos (1 = ocupado, 0 = livre)                   |\n");
                    printf("+--------------------------------------------------------------------------------+\n");
                    printf("|                           ##  1  2  3  4  5  6  7  8                           |\n");
                    printf("|                                                                                |\n");
                    for(i=0;i<tamL;i++)
                    {
                        i++;
                        printf("|                           %.02d  ",i);
                        i--;
                        for(j=0;j<tamC;j++)
                        {
                            printf("%d  ",sala[i][j]);
                        }
                        printf("                         |\n");
                    }
                    printf("+--------------------------------------------------------------------------------+\n");
                    printf("|         Carrinho                                                               |\n");
                    printf("+--------------------------------------------------------------------------------+\n");
                    printf("|         %.02d*Inteiro.........................R$%.2f\t                         |\n", ingressoI[0], pagamento[0]);
                    printf("|                                                                                |\n");
                    printf("|         %.02d*Meia............................R$%.2f\t                         |\n", ingressoM[0], pagamento[1]);
                    printf("|         -----------------------------------------                              |\n");
                    printf("|         Total..............................R$%.2f\t                         |\n", pagamento[2]);
                    printf("+--------------------------------------------------------------------------------+\n");

                    printf("Ingresso %d (Inteiro)", N);
                    printf("\nDigite o assento desejado");

                    printf("\nFileira(01-10):");
                    if(scanf("%d",&linha) == 0)
                    {
                        linha = 0;
                    }
                    LimpaBuffer();

                    printf("\nColuna(1-8):");
                    if(scanf("%d",&coluna) == 0)
                    {
                        coluna = 0;
                    }
                    LimpaBuffer();

                    if(linha>=100 || coluna>=100)
                    {
                        linha = 0;
                        coluna = 0;
                    }

                    if((sala[(linha-1)][(coluna-1)]==1) || (linha<=0) || (linha>tamL) || (coluna<=0) || (coluna>tamC))
                    {
                        system("cls");
                        printf("+--------------------------------------------------------------------------------+\n");
                        printf("|                    Mapa de assentos (1 = ocupado, 0 = livre)                   |\n");
                        printf("+--------------------------------------------------------------------------------+\n");
                        printf("|                           ##  1  2  3  4  5  6  7  8                           |\n");
                        printf("|                                                                                |\n");
                        for(i=0;i<tamL;i++)
                        {
                            i++;
                            printf("|                           %.02d  ",i);
                            i--;
                            for(j=0;j<tamC;j++)
                            {
                                printf("%d  ",sala[i][j]);
                            }
                            printf("                         |\n");
                        }
                        printf("+--------------------------------------------------------------------------------+\n");
                        printf("|         Assento %.02d-%.2d inválido                                                 |\n",linha,coluna);
                        printf("+--------------------------------------------------------------------------------+\n");
                        printf("|         Deseja cancelar esse ingresso?                                         |\n");
                        printf("|                                                                                |\n");
                        printf("|         0-Não                                                                  |\n");
                        printf("|                                                                                |\n");
                        printf("|         1-Sim                                                                  |\n");
                        printf("+--------------------------------------------------------------------------------+\n");
                        scanf("%d",&cancelar);
                        if(cancelar==1)
                        {
                            N--;
                            ingressoI[0]--;
                            pagamento[0]= pagamento[0] - valor;
                            pagamento[2]= pagamento[2] - valor;
                        }
                        else
                        {
                            N--;
                        }


                    }
                    else
                    {
                        system("cls");
                        printf("+--------------------------------------------------------------------------------+\n");
                        printf("|                    Mapa de assentos (1 = ocupado, 0 = livre)                   |\n");
                        printf("+--------------------------------------------------------------------------------+\n");
                        printf("|                           ##  1  2  3  4  5  6  7  8                           |\n");
                        printf("|                                                                                |\n");
                        for(i=0;i<tamL;i++)
                        {
                            i++;
                            printf("|                           %.02d  ",i);
                            i--;
                            for(j=0;j<tamC;j++)
                            {
                                printf("%d  ",sala[i][j]);
                            }
                            printf("                         |\n");
                        }
                        printf("+--------------------------------------------------------------------------------+\n");
                        printf("|         Assento disponível %.02d-%d                                                |\n",linha,coluna);
                        printf("+--------------------------------------------------------------------------------+\n");
                        printf("|         Deseja realizar esta operação?                                         |\n");
                        printf("|                                                                                |\n");
                        printf("|         0-Não                                                                  |\n");
                        printf("|                                                                                |\n");
                        printf("|         1-Sim                                                                  |\n");
                        printf("+--------------------------------------------------------------------------------+\n");
                        linha--;
                        coluna--;
                        do
                        {
                            scanf("%d",&sala[linha][coluna]);
                        }while((sala[linha][coluna]>1)||(sala[linha][coluna]<0));

                        if(sala[linha][coluna]==1)
                        {
                            livres--;
                            ingressoI[1]++;
                        }
                        else
                        {
                            N--;
                        }
                    }
                    N++;
                }

                N=1;
                while(N <= ingressoM[0])
                {
                    system("cls");
                    printf("+--------------------------------------------------------------------------------+\n");
                    printf("|                    Mapa de assentos (1 = ocupado, 0 = livre)                   |\n");
                    printf("+--------------------------------------------------------------------------------+\n");
                    printf("|                           ##  1  2  3  4  5  6  7  8                           |\n");
                    printf("|                                                                                |\n");