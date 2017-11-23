#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
int camas[7062];

void quartosOcupados(int *reservasOcupadas[181][6][7]) //Inicializa quartos.
{
    int i, j, q, randI, randJ, randQ, contLugarOcup=0, aux=0, randomico, random = 0, randC, c;
    int cpf;

    for(q = 0; q < 181; q++)
    {
        for (i = 0; i<6; i++) //Limpa as listas de reservas dos quartos.
        {
            for(j=0; j<7; j++)
            {
                reservasOcupadas[q][i][j] = 0;
            }
        }
    }

    while (contLugarOcup <= 1000) //Preenche os quartos vagos aleatoriamente.
    {
        randQ = rand ()% 182;
        randI =  rand()%7;
        randJ = rand()%8;



        aux = 0;
        //Verifica se o quarto esta vago.
        if (reservasOcupadas[randQ][randI][randJ] == 0)
        {
            // Guarda um numero de 10 dígitos
            cpf= 100000000000 + rand() % 999999999999;

            //Verifica se o usuario ja esta em alguma reserva.

            for (j=0; j<7; j++)
            {
                if (cpf==reservasOcupadas[randQ][randI][j])
                {
                    aux = 1; //Indica que o cliente ja possui reserva.
                }

            }
            if (aux==0)  // Adiciona o cliente ao quarto.
            {
                randomico = 3 + rand() % 5;

                random = randQ + randomico;

                reservasOcupadas[randQ][randI][randJ] = cpf;

                contLugarOcup ++;
            }
        }
    }
    return;
}
int exibirReservas (int *reservasOcupadas[181][6][7]) //Exibe as vagas de todos os quartos existentes.
{
    int i, j, q, c, dia = 1, andar=1, quarto=101;
    char jan[15], fev[15], mar[15], abr[15], mai[15], jun[15];
    for(q = 0; q < 181; q++ ) //Imprimir Reservas já feitas
    {
        //Indica os meses
        if(reservasOcupadas[q] == reservasOcupadas[0])
        {
            sprintf(jan, "[JANEIRO]");
            for(int i = 0; i < strlen(jan); i++)
            {
                printf("%c", jan[i]);
            }
        }
        if(reservasOcupadas[q] == reservasOcupadas[31])
        {
            sprintf(fev, "[FEVEREIRO]");
            for(int i = 0; i < strlen(fev); i++)
            {
                printf("%c", fev[i]);
            }
        }
        if(reservasOcupadas[q] == reservasOcupadas[59])
        {
            sprintf(mar, "[MARCO]");
            for(int i = 0; i < strlen(mar); i++)
            {
                printf("%c", mar[i]);
            }
        }
        if(reservasOcupadas[q] == reservasOcupadas[90])
        {
            sprintf(abr, "[ABRIL]");
            for(int i = 0; i < strlen(abr); i++)
            {
                printf("%c", abr[i]);
            }
        }
        if(reservasOcupadas[q] == reservasOcupadas[120])
        {
            sprintf(mai, "[MAIO]");
            for(int i = 0; i < strlen(mai); i++)
            {
                printf("%c", mai[i]);
            }
        }
        if(reservasOcupadas[q] == reservasOcupadas[151])
        {
            sprintf(jun, "[JUNHO]");
            for(int i = 0; i < strlen(jun); i++)
            {
                printf("%c", jun[i]);
            }
        }


        //Indica os dias nos meses
        printf("\n   ###Dia %d###   ", dia);
        dia++;
        if(reservasOcupadas[q] == reservasOcupadas[30])
        {
            dia = 1;
        }
        if(reservasOcupadas[q] == reservasOcupadas[58])
        {
            dia = 1;
        }
        if(reservasOcupadas[q] == reservasOcupadas[89])
        {
            dia = 1;
        }
        if(reservasOcupadas[q] == reservasOcupadas[119])
        {
            dia = 1;
        }
        if(reservasOcupadas[q] == reservasOcupadas[150])
        {
            dia = 1;
        }

        for (i = 0; i<6; i++)
        {
            printf("\n** Andar %d **\n", andar);

            for(j=0; j<7; j++)
            {
                for(int i = 0; i< 7063; i++)
                {
                    camas[i] = 1 + rand()% 3;
                }
                printf("%d - %010d %d cama(s)    ", quarto, reservasOcupadas[q][i][j], camas[i]);

                quarto ++;
            }
            printf("\n\n");
            andar ++;

            if(andar == 7 )
            {
                andar = 1;
            }

            if (quarto==108 || quarto==208 || quarto==308 || quarto==408 || quarto==508 )
            {
                quarto = quarto + 93;
            }
            if(quarto > 607)
                quarto = 101;
        }
    }
}

int incluirReserva(int andar, int quarto, int mes, int dia, int *reservasOcupadas[181][6][7])
{

    int dias,quartos;
    int q,i,j;

    //CORRIGINDO O MÊS
    andar = andar - 1;

    //CORRIGINDO OS DIAS PARA FAZER FICAR DE 1 A 180
    if(mes == 1)
    {
        if(dia >= 0 && dia <= 30)
        {
            dia = dia - 1;
        }
    }
    if(mes == 2)
    {
        dia = dia + 31;
    }
    if(mes == 3)
    {
        dia = dia + 59;
    }
    if(mes == 4)
    {
        dia = dia + 89;
    }
    if(mes == 5)
    {
        dia = dia + 119;
    }
    if(mes == 6)
    {
        dia = dia + 150;
    }

    dias = dia;


    //CORRIGIR NUMERO DO QUARTO 538664004
    if(quarto == 101)
    {
        quartos = 0;
    }
    if(quarto == 102)
    {
        quartos = 1;
    }
    if(quarto == 103)
    {
        quartos = 2;
    }
    if(quarto == 104)
    {
        quartos = 3;
    }
    if(quarto == 105)
    {
        quartos = 4;
    }
    if(quarto == 106)
    {
        quartos = 5;
    }
    if(quarto == 107)
    {
        quartos = 6;
    }
    if(quarto == 201)
    {
        quartos = 0;
    }
    if(quarto == 202)
    {
        quartos = 1;
    }
    if(quarto == 203)
    {
        quartos = 2;
    }
    if(quarto == 204)
    {
        quartos = 3;
    }
    if(quarto == 205)
    {
        quartos = 4;
    }
    if(quarto == 206)
    {
        quartos = 5;
    }
    if(quarto == 207)
    {
        quartos = 6;
    }
    if(quarto == 301)
    {
        quartos = 0;
    }
    if(quarto == 302)
    {
        quartos = 1;
    }
    if(quarto == 303)
    {
        quartos = 2;
    }
    if(quarto == 304)
    {
        quartos = 3;
    }
    if(quarto == 305)
    {
        quartos = 4;
    }
    if(quarto == 306)
    {
        quartos = 5;
    }
    if(quarto == 307)
    {
        quartos = 6;
    }
    if(quarto == 401)
    {
        quartos = 0;
    }
    if(quarto == 402)
    {
        quartos = 1;
    }
    if(quarto == 403)
    {
        quartos = 2;
    }
    if(quarto == 404)
    {
        quartos = 3;
    }
    if(quarto == 405)
    {
        quartos = 4;
    }
    if(quarto == 406)
    {
        quartos = 5;
    }
    if(quarto == 407)
    {
        quartos = 6;
    }
    if(quarto == 501)
    {
        quartos = 0;
    }
    if(quarto == 502)
    {
        quartos = 1;
    }
    if(quarto == 503)
    {
        quartos = 2;
    }
    if(quarto == 504)
    {
        quartos = 3;
    }
    if(quarto == 505)
    {
        quartos = 4;
    }
    if(quarto == 506)
    {
        quartos = 5;
    }
    if(quarto == 507)
    {
        quartos = 6;
    }
    if(quarto == 601)
    {
        quartos = 0;
    }
    if(quarto == 602)
    {
        quartos = 1;
    }
    if(quarto == 603)
    {
        quartos = 2;
    }
    if(quarto == 604)
    {
        quartos = 3;
    }
    if(quarto == 605)
    {
        quartos = 4;
    }
    if(quarto == 606)
    {
        quartos = 5;
    }
    if(quarto == 607)
    {
        quartos = 6;
    }

    for(q=0; q<= 181; q++ )
    {
        for(i=0; i<=6; i++)
        {
            for(j=0; j<=7; j++)
            {
                if(reservasOcupadas[q] == reservasOcupadas[dias])
                {
                    if(reservasOcupadas[i] == reservasOcupadas[andar])
                    {
                        if(reservasOcupadas[j] == reservasOcupadas[quartos])
                        {
                            if(reservasOcupadas[q][i][j] == 0)
                            {
                                return 1;
                            }
                            else
                            {
                                printf("\n\nQuarto ocupado, Cliente: %d\n\n", reservasOcupadas[q][i][j]);
                                return 0;
                            }
                        }
                    }
                }
            }
        }
    }
}

int confirmarReserva(int andar, int quarto, int mes, int dia, int *reservasOcupadas[181][6][7])
{

    int dias, quartos;
    int novocpf;
    int q,i,j;

    //CORRIGINDO O MÊS
    andar = andar - 1;

    //CORRIGINDO OS DIAS PARA FAZER FICAR DE 1 A 180
    if(mes == 1)
    {
        if(dia >= 1 && dia <= 31)
        {
            dia = dia - 1;
        }
    }
    if(mes == 2)
    {
        dia = dia + 31;
    }
    if(mes == 3)
    {
        dia = dia + 59;
    }
    if(mes == 4)
    {
        dia = dia + 89;
    }
    if(mes == 5)
    {
        dia = dia + 119;
    }
    if(mes == 6)
    {
        dia = dia + 150;
    }

    dias = dia;

    //CORRIGIR NUMERO DO QUARTO 538664004
    if(quarto == 101)
    {
        quartos = 0;
    }
    if(quarto == 102)
    {
        quartos = 1;
    }
    if(quarto == 103)
    {
        quartos = 2;
    }
    if(quarto == 104)
    {
        quartos = 3;
    }
    if(quarto == 105)
    {
        quartos = 4;
    }
    if(quarto == 106)
    {
        quartos = 5;
    }
    if(quarto == 107)
    {
        quartos = 6;
    }
    if(quarto == 201)
    {
        quartos = 0;
    }
    if(quarto == 202)
    {
        quartos = 1;
    }
    if(quarto == 203)
    {
        quartos = 2;
    }
    if(quarto == 204)
    {
        quartos = 3;
    }
    if(quarto == 205)
    {
        quartos = 4;
    }
    if(quarto == 206)
    {
        quartos = 5;
    }
    if(quarto == 207)
    {
        quartos = 6;
    }
    if(quarto == 301)
    {
        quartos = 0;
    }
    if(quarto == 302)
    {
        quartos = 1;
    }
    if(quarto == 303)
    {
        quartos = 2;
    }
    if(quarto == 304)
    {
        quartos = 3;
    }
    if(quarto == 305)
    {
        quartos = 4;
    }
    if(quarto == 306)
    {
        quartos = 5;
    }
    if(quarto == 307)
    {
        quartos = 6;
    }
    if(quarto == 401)
    {
        quartos = 0;
    }
    if(quarto == 402)
    {
        quartos = 1;
    }
    if(quarto == 403)
    {
        quartos = 2;
    }
    if(quarto == 404)
    {
        quartos = 3;
    }
    if(quarto == 405)
    {
        quartos = 4;
    }
    if(quarto == 406)
    {
        quartos = 5;
    }
    if(quarto == 407)
    {
        quartos = 6;
    }
    if(quarto == 501)
    {
        quartos = 0;
    }
    if(quarto == 502)
    {
        quartos = 1;
    }
    if(quarto == 503)
    {
        quartos = 2;
    }
    if(quarto == 504)
    {
        quartos = 3;
    }
    if(quarto == 505)
    {
        quartos = 4;
    }
    if(quarto == 506)
    {
        quartos = 5;
    }
    if(quarto == 507)
    {
        quartos = 6;
    }
    if(quarto == 601)
    {
        quartos = 0;
    }
    if(quarto == 602)
    {
        quartos = 1;
    }
    if(quarto == 603)
    {
        quartos = 2;
    }
    if(quarto == 604)
    {
        quartos = 3;
    }
    if(quarto == 605)
    {
        quartos = 4;
    }
    if(quarto == 606)
    {
        quartos = 5;
    }
    if(quarto == 607)
    {
        quartos = 6;
    }

    printf("\nDigite o CPF.: ");
    scanf("%d", &novocpf);

    for(q=0; q<= 181; q++ )
    {
        for(i=0; i<=6; i++)
        {
            for(j=0; j<=7; j++)
            {
                if(reservasOcupadas[q] == reservasOcupadas[dias])
                {
                    if(reservasOcupadas[i] == reservasOcupadas[andar])
                    {
                        if(reservasOcupadas[j] == reservasOcupadas[quartos])
                        {
                            reservasOcupadas[q][i][j] = novocpf;

                            if(reservasOcupadas[q][i][j] == novocpf)
                            {

                                printf("\nCADASTRO DE RESERVA CONCLUIDO COM SUCESSO!\n\n");
                            }
                            else
                            {
                                printf("\nFalha ao modificar!\n");
                            }
                        }
                    }
                }
            }
        }
    }
}

typedef struct
{
    int cpf[12];
    int andar, quarto, mes, dia;
} Cliente;

int main()
{
    int *reservasOcupadas[181][6][7];

    quartosOcupados(reservasOcupadas);    // chama a funcao de preencher automaticamente os dados
    exibirReservas(reservasOcupadas);      //mostrar todas as vagas


    char funcionario[20];

    int opcaoMenu = 10, confirMenu;

    Cliente cliente;


    printf("||======||Bem Vindo ao Hotel Madrid||======||");
    printf("\n\nDigite primeiro nome para Entrar: ");
    scanf("%s", &funcionario);
    system("cls");

    while (opcaoMenu != 0)
    {
        printf("||======||Bem Vindo: %s - Hotel Madrid||======||\n", funcionario);
        //MENU
        printf("\nEscolha uma tarefa:");
        printf("\n\n1 - Fazer Reserva\n2 - Ver Reserva\n3 - Excluir Reserva\n0 - Sair do Programa");
        printf("\n\nDigite a opcao: ");
        scanf("%d", &opcaoMenu);

        switch ( opcaoMenu )
        {
        case 1 :
            printf("\n=====|FAZER RESERVA|=====");
            printf("\nNumero do Andar.: ");
            scanf("%d%*c", &cliente.andar);
            printf("Numero do Quarto.: ");
            scanf("%d%*c", &cliente.quarto);
            printf("Digite numero do Mes.: ");
            scanf("%d%*c", &cliente.mes);
            printf("Digite o Dia.: ");
            scanf("%d%*c", &cliente.dia);

            int retorno;
            retorno = incluirReserva(cliente.andar, cliente.quarto, cliente.mes, cliente.dia, &reservasOcupadas);

            if(retorno == 1)
            {
                printf("\nQuarto vazio, deseja confirmar a rezerva? ");
                printf("\n1 - Sim\n2 - Nao");
                printf("\n\nConfirmar?: ");
                scanf("%d", &confirMenu);

                switch( confirMenu )
                {
                case 1 :
                    confirmarReserva(cliente.andar, cliente.quarto, cliente.mes, cliente.dia, &reservasOcupadas);

                    break;
                default :
                    printf ("\nOpcao Cancelada!\n");
                }
            }

            break;

        case 2 :
            exibirReservas(reservasOcupadas);
            break;

        case 3 :
            printf ("\nCodigo Excluir Reserva\n\n");
            break;

        default :
            printf ("Opcao Invalida!\n");
        }
    }
}
