#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>


int camas[7062];

void quartosOcupados(int *reservasOcupadas[181][6][7]) //Inicializa quartos.
{
    int i, j, q, randI, randJ, randQ, contLugarOcup=0, aux=0, randomico, random = 0, randC, c, cpf1, cpf2;
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
            cpf1 =  rand() % 10000;
            cpf2 =  cpf1 +(rand() % 10000)*10000;
            cpf  =  cpf2 + (rand()% 1000)* 1000000;



            //Verifica se o usuario ja esta em alguma reserva.

            for (j=0; j<7; j++)
            {
                if (cpf==reservasOcupadas[randQ][randI][j])
                {
                    aux = 1; //Indica que o cliente ja possui reserva.
                }int dia = 1;

            }
            if (aux==0)  // Adiciona o cliente ao quarto.
            {
                randomico = 3 + rand() % 5;

                random = randQ + randomico;
                // Populando o vetor camas com randomico de 1 a 3
                for(int i = 0; i< 7063; i++)
                {
                    camas[i] = 1 + rand()% 3;
                }

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

int incluirReserva(int numcamas, int diaentrada, int mesentrada, int diasaida, int messaida, int cpf, int *reservasOcupadas[181][6][7]){

    int diasentrada, diassaida, quartos;
    int q,i,j,aux;
    aux = 0;
    int dia = 1;
    int preco = 0;

    //CORRIGINDO OS DIAS PARA FAZER FICAR DE 1 A 180
    if(mesentrada == 1)
    {
        if(diaentrada > 0 && diaentrada <= 30)
        {
            diaentrada = diaentrada - 1;
        }
    }
    if(mesentrada == 2)
    {
        diaentrada = diaentrada + 31;
    }
    if(mesentrada == 3)
    {
        diaentrada = diaentrada + 59;
    }
    if(mesentrada == 4)
    {
        diaentrada = diaentrada + 89;
    }
    if(mesentrada == 5)
    {
        diaentrada = diaentrada + 119;
    }
    if(mesentrada == 6)
    {
        diaentrada = diaentrada + 150;
    }

    diasentrada = diaentrada;

    if(messaida == 1)
    {
        if(diasaida > 0 && diasaida <= 30)
        {
            diasaida = diasaida - 1;
        }
    }
    if(messaida == 2)
    {
        diasaida = diasaida + 31;
    }
    if(messaida == 3)
    {
        diasaida = diasaida + 59;
    }
    if(messaida == 4)
    {
        diasaida = diasaida + 89;
    }
    if(messaida == 5)
    {
        diasaida = diasaida + 119;
    }
    if(messaida == 6)
    {
        diasaida = diasaida + 150;
    }

    diassaida = diasaida;

    if(diassaida <= 181 && diasentrada > 0){
        for(q=diasentrada; q<diassaida; q++ )
        {
            for(i=0; i<6; i++)
            {
                printf("\n** Andar %d **\n", i+1);

                for(j=0; j<=7; j++)
                {
                    if(reservasOcupadas[q][i][j] != cpf){
                        if(reservasOcupadas[q][i][j] == 0){
                            if(numcamas > 0 && numcamas <= 3){
                                if(camas[i] == numcamas){
                                    if(numcamas == 1){
                                        preco = 117;
                                    }
                                    if(numcamas == 2){
                                        preco = 150;
                                    }
                                    if(numcamas == 3){
                                        preco = 180;
                                    }
                                    printf("Dia: %d - Andar: %d - Quarto: %d,  %d cama(s) -- PRECO: RS %d.::\n", q, i+1, j, camas[i], preco);
                                    aux = aux +1;
                                }
                            }else{
                                //printf("Numero de camas fornecidos errados, temos quartos de 1,2 e 3 camas.");
                                return 5;
                            }
                        }else{
                            return 2;
                        }
                    }else{
                        return 3;
                    }
                }
            }
        }
    }else{
        return 1;
    }
}

int confirmarReserva(int andar, int quarto, int numcamas, int diaentrada, int mesentrada, int diasaida, int messaida, int cpf, int *reservasOcupadas[181][6][7]){
    int diasentrada, diassaida, quartos;
    int q,i,j,aux;
    aux = 0;
    int dia = 1;
    int preco = 0;

    //CORRIGINDO OS DIAS PARA FAZER FICAR DE 1 A 180
    if(mesentrada == 1)
    {
        if(diaentrada > 0 && diaentrada <= 30)
        {
            diaentrada = diaentrada - 1;
        }
    }
    if(mesentrada == 2)
    {
        diaentrada = diaentrada + 31;
    }
    if(mesentrada == 3)
    {
        diaentrada = diaentrada + 59;
    }
    if(mesentrada == 4)
    {
        diaentrada = diaentrada + 89;
    }
    if(mesentrada == 5)
    {
        diaentrada = diaentrada + 119;
    }
    if(mesentrada == 6)
    {
        diaentrada = diaentrada + 150;
    }

    diasentrada = diaentrada;

    if(messaida == 1)
    {
        if(diasaida > 0 && diasaida <= 30)
        {
            diasaida = diasaida - 1;
        }
    }
    if(messaida == 2)
    {
        diasaida = diasaida + 31;
    }
    if(messaida == 3)
    {
        diasaida = diasaida + 59;
    }
    if(messaida == 4)
    {
        diasaida = diasaida + 89;
    }
    if(messaida == 5)
    {
        diasaida = diasaida + 119;
    }
    if(messaida == 6)
    {
        diasaida = diasaida + 150;
    }

    diassaida = diasaida;

    for(q=diasentrada; q<diassaida; q++ )
    {
        for(i=0; i<6; i++)
        {
            printf("\n** Andar %d **\n", i+1);

            for(j=0; j<=7; j++)
            {
                if(quarto > 100 && quarto <= 607){
                    if(reservasOcupadas[q][i][j] == 0){
                        if(numcamas > 1 && numcamas <= 3){
                            if(camas[i] == numcamas){
                                if(numcamas == 1){
                                    preco = 117;
                                }
                                if(numcamas == 2){
                                    preco = 150;
                                }
                                if(numcamas == 3){
                                    preco = 180;
                                }
                                printf("Dia: %d - Andar: %d - Quarto: %d,  %d cama(s) -- PRECO: RS %d.::\n", q, i+1, j, camas[i], preco);
                                aux = aux +1;
                            }
                        }else{
                            return 5;
                        }
                    }else if(aux == 0){
                        return 2;
                    }
                }else{
                    return 0;
                }
            }
        }
    }
}

int excluirReserva(int exclandar, int exclquarto, int exclcpf, int excldiaentrada, int exclmesentrada,int excldiasaida, int exclmessaida,int *reservasOcupadas[181][6][7]){

int confirmarescolha,corridias, corriquartos,confirmacaodias,confirmacaomes,confirmacaoquarto,confirmacaoandar,a,b,c;

    if(((excldiaentrada>0)&&(excldiasaida>0))&&((excldiaentrada<=31)&&(excldiasaida<=31))){
    if(exclmesentrada == 1){
        excldiaentrada = excldiaentrada;
        excldiasaida = excldiasaida;
        }
    if((exclmesentrada == 2)||(exclmessaida==2)){
        excldiaentrada = excldiaentrada + 31;
        excldiasaida = excldiasaida + 31;
    }
    if(exclmesentrada == 3){
        excldiaentrada = excldiaentrada + 59;
        excldiasaida = excldiasaida + 59;
    }
    if(exclmesentrada == 4){
        excldiaentrada = excldiaentrada + 89;
        excldiasaida = excldiasaida + 89;
    }
    if(exclmesentrada == 5){
        excldiaentrada = excldiaentrada + 119;
        excldiasaida = excldiasaida + 119;
    }
    if(exclmesentrada == 6){
        excldiaentrada = excldiaentrada + 150;
        excldiasaida = excldiasaida + 150;
    }

    confirmacaodias=1;
    }else{
    confirmacaodias=0;
    }

    confirmacaoquarto=0;
    if(exclquarto == 101){
        corriquartos = 0;
        confirmacaoquarto=1;
    }
    if(exclquarto == 102){
        corriquartos = 1;
        confirmacaoquarto=1;
    }
    if(exclquarto == 103){
        corriquartos = 2;
        confirmacaoquarto=1;
    }
    if(exclquarto == 104){
        corriquartos = 3;
        confirmacaoquarto=1;
    }
    if(exclquarto == 105){
        corriquartos = 4;
        confirmacaoquarto=1;
    }
    if(exclquarto == 106){
        corriquartos = 5;
        confirmacaoquarto=1;
    }
    if(exclquarto == 107){
        corriquartos = 6;
        confirmacaoquarto=1;
    }
    if(exclquarto == 201){
        corriquartos = 0;
        confirmacaoquarto=1;
    }
    if(exclquarto == 202){
        corriquartos = 1;
        confirmacaoquarto=1;
    }
    if(exclquarto == 203){
        corriquartos = 2;
        confirmacaoquarto=1;
    }
    if(exclquarto == 204){
        corriquartos = 3;
        confirmacaoquarto=1;
    }
    if(exclquarto == 205){
        corriquartos = 4;
        confirmacaoquarto=1;
    }
    if(exclquarto == 206){
        corriquartos = 5;
        confirmacaoquarto=1;
    }
    if(exclquarto == 207){
        corriquartos = 6;
        confirmacaoquarto=1;
    }
    if(exclquarto == 301){
        corriquartos = 0;
        confirmacaoquarto=1;
    }
    if(exclquarto == 302){
        corriquartos = 1;
        confirmacaoquarto=1;
    }
    if(exclquarto == 303){
        corriquartos = 2;
        confirmacaoquarto=1;
    }
    if(exclquarto == 304){
        corriquartos = 3;
        confirmacaoquarto=1;
    }
    if(exclquarto == 305){
        corriquartos = 4;
        confirmacaoquarto=1;
    }
    if(exclquarto == 306){
        corriquartos = 5;
        confirmacaoquarto=1;
    }
    if(exclquarto == 307){
        corriquartos = 6;
        confirmacaoquarto=1;
    }
    if(exclquarto == 401){
        corriquartos = 0;
        confirmacaoquarto=1;
    }
    if(exclquarto == 402){
        corriquartos = 1;
        confirmacaoquarto=1;
    }
    if(exclquarto == 403){
        corriquartos = 2;
        confirmacaoquarto=1;
    }
    if(exclquarto == 404){
        corriquartos = 3;
        confirmacaoquarto=1;
    }
    if(exclquarto == 405){
        corriquartos = 4;
        confirmacaoquarto=1;
    }
    if(exclquarto == 406){
        corriquartos = 5;
        confirmacaoquarto=1;
    }
    if(exclquarto == 407){
        corriquartos = 6;
        confirmacaoquarto=1;
    }
    if(exclquarto == 501){
        corriquartos = 0;
        confirmacaoquarto=1;
    }
    if(exclquarto == 502){
        corriquartos = 1;
        confirmacaoquarto=1;
    }
    if(exclquarto == 503){
        corriquartos = 2;
        confirmacaoquarto=1;
    }
    if(exclquarto == 504){
        corriquartos = 3;
        confirmacaoquarto=1;
    }
    if(exclquarto == 505){
        corriquartos = 4;
        confirmacaoquarto=1;
    }
    if(exclquarto == 506){
        corriquartos = 5;
        confirmacaoquarto=1;
    }
    if(exclquarto == 507){
        corriquartos = 6;
        confirmacaoquarto=1;
    }
    if(exclquarto == 601){
        corriquartos = 0;
        confirmacaoquarto=1;
    }
    if(exclquarto == 602){
        corriquartos = 1;
        confirmacaoquarto=1;
    }
    if(exclquarto == 603){
        corriquartos = 2;
        confirmacaoquarto=1;
    }
    if(exclquarto == 604){
        corriquartos = 3;
        confirmacaoquarto=1;
    }
    if(exclquarto == 605){
        corriquartos = 4;
        confirmacaoquarto=1;
    }
    if(exclquarto == 606){
        corriquartos = 5;
        confirmacaoquarto=1;
    }
    if(exclquarto == 607){
        corriquartos = 6;
        confirmacaoquarto=1;
    }
    if(((exclmesentrada<=0)&&(exclmessaida<=0))||((exclmesentrada>6)&&(exclmessaida>6))){
        confirmacaodias=0;
    }
    if((exclandar<=0)||(exclandar>6)){
        confirmacaoquarto=0;
    }
    if((confirmacaoquarto==0)&&(confirmacaodias==0)){
    return(3);
    }
    if(confirmacaodias==0){
    return(1);
    }
    if(confirmacaoquarto==0){
    return(2);
    }
    if((excldiasaida <= 181) && (excldiaentrada > 0)){
        for(a=excldiaentrada; a<excldiasaida; a++ )
        {
            for(b=0; b<6; b++)
            {
                for(c=0; c<=7; c++)
                {
                    if(reservasOcupadas[a][b][c] == exclcpf){
                            printf("Deseja excluir a reserva?\n1-Sim\n2-Nao\n");
                            scanf("%d",&confirmarescolha);
                    if(confirmarescolha==1){
                        reservasOcupadas[a][b][c]=0;
                        return(4);
                    }
                    if(confirmarescolha==2){
                        return(5);
                    }
                    }
                    if(reservasOcupadas[a][b][c]!=exclcpf){
                        return(6);
                    }
                }
            }
        }
    }




       //for(a=0; a<= 181; a++ ){
        //for(b=0; b<=6; b++){
            //for(c=0; c<=7; c++){
                    //if(reservasOcupadas[a] == reservasOcupadas[excldia])
                   // {
                       // if(reservasOcupadas[b] == reservasOcupadas[exclandar])
                        //{
                            //if(reservasOcupadas[c] == reservasOcupadas[exclquarto])
                           // {
                                //if(reservasOcupadas[a][b][c] == 0){
                                    //return(6);
                               // break;
                               // }
                        //    }
                      //  }
                  //  }
           // }
        //}
      // }
 //   if(reservasOcupadas[a][b][c] != 0){
   //     printf("Deseja excluir a reserva?\n\n1-Sim\n2-Nao\n");
  /////      scanf("%d",&confirmarescolha);
   // }
//
   // if(confirmarescolha==1){
    //for(a=0; a<= 181; a++ ){
      //  for(b=0; b<=6; b++){
           // for(c=0; c<=7; c++){
                  //  if(reservasOcupadas[a] == reservasOcupadas[excldia])
                    //{
                       // if(reservasOcupadas[b] == reservasOcupadas[exclandar])
                      //  {
                           // if(reservasOcupadas[c] == reservasOcupadas[exclquarto])
                           // {
                              //  reservasOcupadas[a][b][c] = 0;

                              //  if(reservasOcupadas[a][b][c] == 0){

                                //return(4);
                              //  }
                              //  if(reservasOcupadas[a][b][c]!=0){
                              //      return(5);
                             //   }
                          //  }
                       // }
                   // }
                //}
           // }
        //}
   // }
   // if(confirmarescolha!=1){
        //return(5);
   // }


    }

typedef struct
{
    int cpf;
    int numcamas, mesentrada, messaida, diaentrada, diasaida, andar, quarto;
} Cliente;

int main()
{
    int excandar,excquarto,exccpf,excdiaentrada,excmesentrada,excdiasaida,excmessaida;
    int *reservasOcupadas[181][6][7];

    quartosOcupados(reservasOcupadas);    // chama a funcao de preencher automaticamente os dados
    exibirReservas(reservasOcupadas);      //mostrar todas as vagas


    char funcionario[20];

    int opcaoMenu = 10, confirMenu;

    int andar,quarto;

    Cliente cliente;


    printf("||======||Bem Vindo ao Hotel Madrid||======||");
    printf("\n\nDigite primeiro nome para Entrar: ");
    scanf("%s", &funcionario);
    system("cls");

    while (opcaoMenu != 0)
    {
        printf("\n||======||Bem Vindo: %s - Hotel Madrid||======||\n", funcionario);
        //MENU
        printf("\nEscolha uma tarefa:");
        printf("\n\n1 - Fazer Reserva\n2 - Ver Reserva\n3 - Excluir Reserva\n0 - Sair do Programa");
        printf("\n\nDigite a opcao: ");
        scanf("%d", &opcaoMenu);

        switch ( opcaoMenu )
        {
        case 1 :
            printf("\n=====|FAZER RESERVA|=====");
            printf("\nNumero de Camas.: ");
            scanf("%d%*c", &cliente.numcamas);
            printf("Dia de Entrada.: ");
            scanf("%d%*c", &cliente.diaentrada);
            printf("Mes de Entrada.: ");
            scanf("%d%*c", &cliente.mesentrada);
            printf("Dia de Saida.: ");
            scanf("%d%*c", &cliente.diasaida);
            printf("Mes de Saida.: ");
            scanf("%d%*c", &cliente.messaida);
            printf("CPF.: ");
            scanf("%d%*c", &cliente.cpf);

            int retorno;
            retorno = incluirReserva(cliente.numcamas, cliente.diaentrada, cliente.mesentrada, cliente.diasaida, cliente.messaida, cliente.cpf, &reservasOcupadas);

            if(retorno == 1)
            {
                printf("\nPeriodo Invalido.\n");
            }

            if(retorno == 2)
            {
                printf("\nNao a quartos disponivel nesse periodo com a quantidade de cama Informada.\n");
            }

            if(retorno == 3)
            {
                printf("\nja possui reserva em pelo menos algum dia do mesmo periodo.\n");
            }

            if(retorno == 5)
            {
                printf("\nNumero de camas fornecidos errados, temos quartos de 1,2 e 3 camas.\n");
            }

            if(retorno != 0 && retorno != 1 && retorno != 2 && retorno != 3 && retorno != 4){
                printf("\nConfirmar Reserva?:");
                printf("\n\n1 - Sim\n2 - Nao");
                printf("\n\nDigite a opcao: ");
                scanf("%d", &opcaoMenu);

                switch ( confirMenu ){
                    case 1 :
                        printf ("\nDigite o Numero do Andar: ");
                        scanf("%d", &andar);
                        printf ("\nDigite o Numero do Quarto: ");
                        scanf("%d", &quarto);

                        int confirmar;
                        confirmar = confirmarReserva(andar, quarto, cliente.numcamas, cliente.diaentrada, cliente.mesentrada, cliente.diasaida, cliente.messaida, cliente.cpf, &reservasOcupadas);

                        if(retorno == 0)
                        {
                            printf("\nO quarto nao existe.\n");
                        }

                    break;

                    default :
                        printf ("Opcao Invalida!\n");
                }
            }
            break;

        case 2 :
            exibirReservas(reservasOcupadas);
            break;

        case 3 :
           printf("\n=====|EXCLUIR RESERVA|=====");
            printf("\nNumero do andar.: ");
            scanf("%d%*c", &excandar);
            printf("Numero do quarto.: ");
            scanf("%d%*c", &excquarto);
            printf("Digite numero do CPF.: ");
            scanf("%d%*c", &exccpf);
            printf("Digite o dia de entrada.: ");
            scanf("%d%*c", &excdiaentrada);
            printf("Digite o mes de entrada.:");
            scanf("%d*c", &excmesentrada);
            printf("Digite o dia de saida.: ");
            scanf("%d%*c", &excdiasaida);
            printf("Digite o mes de saida.:");
            scanf("%d*c", &excmessaida);

    int exclusao;
    exclusao=excluirReserva(excandar, excquarto, exccpf, excdiaentrada, excmesentrada,excdiasaida,excmessaida, &reservasOcupadas);
    if (exclusao==1){
        printf("\nData invalida");
    }
    if (exclusao==2){
        printf("\nQuarto invalido");
    }
     if (exclusao==3){
        printf("\nQuarto e data invalidos!");
    }
     if (exclusao==4){
        printf("\nExclusao realizada com sucesso!");
    }
     if (exclusao==5){
        printf("\nCancelado!");
    }
    if (exclusao==6){
        printf("\nReserva invalida!\n");
    }
         break;

         default:
           printf ("Opcao Invalida!\n");
      }
    }
}
