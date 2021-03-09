#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <locale.h>

int main()
{
    setlocale(LC_ALL, "Portuguese"); //Permite a utilização de caracteres especiais
    int opcao, escolhaVetor, posicao, vetor1[8], vetor2[8], valor, n1, n2, result, i, j, moda1, moda2, mediana1, mediana2;
    int cont1 = 8, cont2 = 8, cont3 = 0, cont4 = 0, cont5 = 0, cont6 = 0;

    // vetor1, vetor2, i - utilizados na opção 1
    // vetor1, vetor2, i - utilizados na opção 2
    // vetor1, vetor2, escolhaVetor, posicao, i - utilizados na opção 3
    // vetor1, vetor2, valor, i - utilizado na opção 4
    // vetor1, vetor2, n1, i, j - utilizado na opção 5
    // vetor1, vetor2, result, i - utilizado na opção 6
    // vetor1, vetor2, moda1, moda2, mediana1, mediana2, cont3, cont4, cont6, i, j - utilizados na opção 7
    // vetor1, vetor2, cont1, cont2, i - utilizados na opção 8

    srand(time(NULL));

    printf("======== CALCULADORA DE VETOES ======== \n1 – Gerar vetores \n2 – Imprimir vetores \n3 – Eliminar elemento do vetor \n4 – Pesquisar elemento nos vetores \n5 – Ordenar os vetores\n");
    printf("6 – Calcular operações matemáticas \n7 – Calcular métodos estatísticos \n8 – Total de elementos válidos \n9 - Sair \n======================================= \n");

    // Inicialização da calculadora

    do
    {
        printf("\nEscolha a sua opção:\n");
        scanf("%i", &opcao);

        if(opcao == 1)
        {

            ///////////////// 1 - GERAR VETORES /////////////////

            for(i = 0; i < 8; i++)
            {
                vetor1[i] = rand()%500 + 1;            //Gera números aleatórios de 1 a 500 para o Vetor 1.
                vetor2[i] = rand()%500 + 1;            //Gera números aleatórios de 1 a 500 para o Vetor 2
            }                                          //Sendo que o resto da divisão sempre estará entre 0 e 499 para 'rand()%500'. Somamos 1 '+ 1', para a geração de números de 1 a 500.
        }

        ////////////// 2 - IMPRIMIR VETORES /////////////////


        if(opcao == 2)
        {
            printf("Vetor 1\n [ ");                    //Imprime: "Vetor 1
            for(i = 0; i < 7; i++)                     //["
            {
                printf("%i - ", vetor1[i]);            //Imprime os sete primeros números do vetor: "1 - 2 - 3 - 4 - 5 - 6 - 7 - " (exemplo de números aleatórios que podem ser impressos)        O que resulta em => Vetor 1
            }                                          //                                                                                                                           [ 1 - 2 - 3 - 4 - 5 - 6 - 7 - 8]
            printf("%i ]\n\n", vetor1[7]);             //Imprime o último número do vetor: "8 ]"
                                                       //A mesma lógica é usada a seguir, no Vetor 2

            printf("Vetor 2\n [ ");
            for(i = 0; i < 7; i++)
            {
                printf("%i - ", vetor2[i]);
            }
            printf("%i ]\n", vetor2[7]);
        }

        ////////////// 3 - ELIMINAR VETORES ////////////////

        if(opcao == 3)
        {
            printf("Com qual vetor deseja trabalhar? \n");
            scanf("%i", &escolhaVetor);                        //Armazena qual vetor terá um elemento eliminado


            if(escolhaVetor == 1)
            {
                printf("Digite a posição do vetor que deseja excluir: \n");
                scanf("%i", &posicao);                        //Armazena qual posição será excluída

                if(vetor1[posicao] == 0 || posicao < 0 || posicao > 7)   // Analisa se o vetor na posição escolhida é igual a zero OU
                {                                                        // se a posição é menor que 0 (posição do primeiro elemento
                    printf("ERRO! Tente novamente.\n");                  // do vetor) OU maior que 7 (posição do último elemento do vetor)
                }                                                        // Imprimindo, caso ocorra alma dessas opções: "ERRO! Tente novamente."
                else
                {
                    vetor1[posicao] = 0;                                 // Caso contrário, troca o valor da posição escolhida por 0
                }
            }                                                            // A MESMA LÓGICA É SEGUIDA CASO "escolhaVetor" SEJA IGUAL A 2

            else
            {
                if(escolhaVetor == 2)
                {
                    printf("Digite a posição do vetor que deseja excluir: \n");
                    scanf("%i", &posicao);

                    if(vetor2[posicao] == 0 || posicao < 0 || posicao > 7)
                    {
                        printf("ERRO! Tente novamente.\n");
                    }
                    else
                    {
                        vetor2[posicao] = 0;
                    }
                }
                else
                {
                    if(escolhaVetor != 1 || escolhaVetor != 2)
                    {
                        printf("Opção inválida!! Vetor inexistente para essa calculadora");
                    }
                }
            }

        }

        ////////////// 4 - PESQUISAR ELEMENTO NOS VETORES /////////////////

        if(opcao == 4)
        {
            printf("Digite um valor: \n");
            scanf("%i", &valor);                                                             // Armazena a valor que será comparado com os valores do vetor1 e vetor2

            for(i = 0; i < 8; i++)
            {
                if(vetor1[i] == valor && valor != 0)                                         // Cria uma condição de comparação entre todas as posições do vetor1 (de 0 a 7),
                {                                                                            // sendo o valor também diferente de zero
                    printf("O valor digitado existe no vetor 1 na posição %i\n", i);
                }
                if(vetor2[i] == valor && valor != 0)                                         // Cria uma condição de comparação entre todas as posições do vetor2 (de 0 a 7),
                {                                                                            // sendo o valor também diferente de zero
                    printf("O valor digitado existe no vetor 2 na posição %i\n", i);
                }
            }
            if(valor == 0)
                {
                    printf("ERRO!! O zero não é um elemento válido.\n");
                }
        }

        /////////////// 5 - ORDENAR OS VETORES (ORDEM CRESCENTE) ////////

        if(opcao == 5)
        {
            for(i = 0; i < 8; i++)
            {
                for(j = i; j < 8; j ++)
                {
                    if(vetor1[i] > vetor1[j])
                    {
                        n1 = vetor1[i];                 // Variável para armazenar o valor temporariamente
                        vetor1[i] = vetor1[j];          // responsavel por passar os valores de casa em casa para ficar em ordem crescente
                        vetor1[j] = n1;                 // devolve o valor armazenado temporariamente para o vetor
                    }
                    if(vetor2[i] > vetor2[j])
                    {
                        n1 = vetor2[i];
                        vetor2[i] = vetor2[j];
                        vetor2[j] = n1;
                    }
                }
            }
            printf("Vetor 1: \n[ ");                    // impressão do vetor 1 em ordem crescente

            for(i = 0; i < 7; i++)
            {
                printf("%i - ", vetor1[i]);
            }

            printf("%i ] \n\n", vetor1[7]);
            printf("Vetor 2: \n[ ");                   // impressão do vetor 2 em ordem crescente

            for(i = 0; i < 7; i++)
            {
                printf("%i - ", vetor2[i]);
            }
            printf("%i ] \n", vetor2[7]);
        }

        ///////////// 6 - Calcular Operações Matemáticas /////////////////////

        if(opcao == 6)
        {
            printf("SOMA: \n");
            for(i = 0; i < 8; i++)                                                 // Esse laço salva o resultado da soma de cada posição dos vetores 1 e 2
            {                                                                      // e imprime o valores dos vetores e seu resultado em seguida
                result = vetor1[i] + vetor2[i];
                printf("[%i] + [%i] = %i \n", vetor1[i], vetor2[i], result);
            }
            printf("=========================\n");

            printf("SUBTRAÇÃO: \n");
            for(i = 0; i < 8; i++)                                                 // Esse laço salva o resultado da subtração de cada posição dos vetores 1 e 2
            {                                                                      // e imprime o valores dos vetores e seu resultado em seguida
                result = vetor1[i] - vetor2[i];
                printf("[%i] - [%i] = %i \n", vetor1[i], vetor2[i], result);
            }
            printf("=========================\n");

            printf("MULTIPLICAÇÃO: \n");
            for(i = 0; i < 8; i++)                                                // Esse laço salva o resultado da multiplicação de cada posição dos vetores 1 e 2
            {                                                                     // e imprime o valores dos vetores e seu resultado em seguida
                result = vetor1[i] * vetor2[i];
                printf("[%i] x [%i] = %i \n", vetor1[i], vetor2[i], result);
            }
            printf("=========================\n");

            printf("DIVISÃO: \n");
            for(i = 0; i < 8; i++)
            {
                if(vetor2[i] == 0)                                                                    // Cria uma condição, caso o vetor2 seja 0, imprimindo, por exemplo:
                {                                                                                     // "[2] / [0] = Impossível dividir!!"
                    printf("[%i] / [%i] = Impossível dividir!! \n", vetor1[i], vetor2[i]);
                }
                if(vetor2[i] != 0)
                {
                    result = vetor1[i] / vetor2[i];                               // Caso contrário, esse laço salva o resultado da multiplicação de cada posição dos vetores 1 e 2
                    printf("[%i] / [%i] = %i \n", vetor1[i], vetor2[i], result);  // e imprime o valores dos vetores e seu resultado em seguida
                }
            }
        }
        ////////////// 7 - mediana e moda //////////////////

        if(opcao == 7){
            ///////////////// Moda ///////////////
            for(i = 0; i < 8; i++){
                for(j = i + 1; j < 8; j++){
                    if(vetor1[i] == vetor1[j]){            // confere se o valores são iguais
                        cont3++;                           // se o valor for igual, ele realiza o a soma para a proxima etapa
                    }
                    if(cont3 > cont4){                     // confirma se o valor do vetor do valor pode ser considerado a moda
                        moda1 = vetor1[i];                 // o valor de determinada posicao passa a ser a moda
                        cont4 = cont3;
                        cont3 = 0;                         // reinicia a contagem, para que realize a verificação com a proxima posição
                    }
                }
            }
            for(i = 0; i < 8; i++){
                for(j = i + 1; j < 8; j++){
                    if(vetor2[i] == vetor2[j]){
                        cont3++;
                    }
                    if(cont3 > cont4){
                        moda2 = vetor2[i];
                        cont4 = cont3;
                        cont3 = 0;
                    }
                }
            }
            for(i = 0; i < 8; i++){                        // responsavel por verificar se existe a moda ou não
                if(moda1 == vetor1[i]){
                    cont5++;
                }
                if(moda2 == vetor2[i]){
                    cont6++;
                }
            }
            printf("Moda: \n");
            if(cont5 == 0){                                // se o valor de cont5 for diferente de 0 existe moda, o que se deve a verificação
                printf("vetor 1: nao possui moda. \n");    // da ultima etapa
            }
            else{
                printf("vetor 1: %i \n", moda1);           // impressão da moda ou que não existe moda
            }
            if(cont6 == 0){
                printf("vetor 2: não possui moda. \n\n");
            }
            else{
                printf("vetro 2: %i \n\n", moda2);
            }
            //////////// mediana /////////////////
            for(i = 0; i < 8; i++){
                for(j = i; j < 8; j++){                    // realiza a ordenagem de forma crescente nos vetores
                    if(vetor1[i] > vetor1[j]){
                        n2 = vetor1[i];
                        vetor1[i] = vetor1[j];
                        vetor1[j] = n2;
                    }
                    if(vetor2[i] > vetor2[j]){
                        n2 = vetor2[i];
                        vetor2[i] = vetor2[j];
                        vetor2[j] = n2;
                    }
                }
            }
            mediana1 = (vetor1[3] + vetor1[4]) / 2;        // as contas realizadas para se obter a mediana
            mediana2 = (vetor2[3] + vetor2[4]) / 2;
            printf("mediana: \n");                         // impressão da mediana
            printf("vetor 1: %i \n", mediana1);
            printf("vetor 2: %i \n", mediana2);
        }

        ///////////// 8 - Calcular métodos estatísticos /////////////////////

        if(opcao == 8)
        {
            for(i = 0; i < 8; i++)
            {
                if(vetor1[i] == 0){                        // "cont1" e "cont2" são inicializados valendo 8 (o número do tamanho do vetor e quantidade de valores que podem
                    cont1--;                               // ser armazenados neles), caso o valor do "vetor1" ou do "vetor2" seja igual a 0 em determinada posição, será subtraído 1 de
                }                                          // "cont1" e "cont2", respectivamente
                if(vetor2[i] == 0){
                    cont2--;
                }
            }

            if(cont1 == 0 && cont2 == 0)
            {
                printf("Nenhum dos vetores possui elementos válidos. \n");
            }

            else
            {
                if(cont1 == 0)
                {
                    printf("O vetor 1 não possui elementos válidos.\n");
                }
                else
                {
                    if(cont2 == 0)
                    {
                        printf("O vetor 2 não possui elementos válidos.\n");
                    }
                }
            }

            if(cont1 != 0)
            {
                printf("O vetor 1 possui %i elementos válidos. \n", cont1);
            }
            if(cont2 != 0)
            {
                printf("O vetor 2 possui %i elementos válidos. \n", cont2);
            }
            cont1 = 8;       // Atribuição do valor 8 para o "cont1" e "cont2" para que não haja erro se o usuário
            cont2 = 8;       // escolha a opção 8, novamente
        }

        ////////////// 9 - Sair ////////////////////////////////////////////

        if(opcao == 9)
        {
            exit(0);               //"O exit(0);" é usado para encerrar o programa, também seria possível usar o "break;"
        }

        if(opcao < 1 || opcao > 9)
        {
            printf("Opção inválida!!\n"); // Imprime "Opção Inválida!!" para valores escolhidos para a variável "opcao"
        }                                 // que são menores que 1 ou maiores que 9

    }while(opcao > - RAND_MAX);           // Executa o programa enquanto O valor escolhido para "opcao" for maior que
                                          // "- RAND_MAX" ( -32767 )
    return 0;
}
