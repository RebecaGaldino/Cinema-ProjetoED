#include <stdio.h>
#include <ctype.h>
#define inteira 18.00
#define meia 6.00
#define especial 0.00 //Para portadores de deficiencia e idosos

int sessao[10][10];
int MeiasOcupadas = 0, InteirasOcupadas = 0, EspeciaisOcupadas = 0;
int cadeira,fileira;

/*Inicializar o vetor sessão. Reinicializado a cada fim dessa. */
void iniciarSessao(){
    int i,j;
    for (i = 0;i < 10;i++){
        for (j = 0;j < 10;j++){
            sessao[i][j] = 0;
        }
    }
}

/* Verifica se a cadeira está ou não disponível para a compra. */
int pesquisarCadeira(){
    printf("	---------------------------------------                    \n");
	printf("    | Insira o numero da cadeira e da fila |                   \n");
	printf("    ---------------------------------------                    \n");
	scanf("%d %d",&cadeira,&fileira);
	if (sessao[cadeira][fileira] != 0){
		system("cls");
		printf("Cadeira ocupada!\n");
		return 1;
	}
	else{
		system("cls");
		printf("Cadeira disponivel!\n");
		return 0;
	}

}

/* Verifica, por base na função pesquisarCadeira, se a compra é realizável ou não. Se for, a posição referente a cadeira
 * e à fileira recebem o valor dependendo do seu tipo, passado como parametro.
 */
int ocuparCadeira(int tipo){
    if (pesquisarCadeira() == 1){
        printf("Impossivel efetuar compra. Por favor, escolha outra cadeira.");
        return 0;
    }
    else{
       if(tipo == 1)
            sessao[cadeira][fileira] = 1;
       else if(tipo == 2)
            sessao[cadeira][fileira] = 2;
       else
            sessao[cadeira][fileira] = 3;
        return 1;
    }

}

/* Método de compra do ingresso, recebendo o tipo dele como parametro e ocupando os assentos. */
void comprarIngresso(int ing){
	char r;
	switch (ing){
		case 1:
			printf("Valor - Meia entrada: %.2f\n",meia);
			printf("Efetuar compra? (S - Sim, N - Nao)\n");
			fflush(stdin);
			scanf("%c",&r);
			if(toupper(r) == 'S'){
                if (ocuparCadeira(1)){
                  printf("Ingresso comprado com sucesso!\n");
                  MeiasOcupadas++;
                }
                break;
			}
			else{
                system("cls");
                menuCliente();
                break;
			}
        case 2:
			printf("Valor - Entrada Inteira: %.2f\n",inteira);
			printf("Efetuar compra? (S - Sim, N - Nao)\n");
			fflush(stdin);
			scanf("%c",&r);
			if(toupper(r) == 'S'){
                if (ocuparCadeira(2)){
                  printf("Ingresso comprado com sucesso!\n");
                  InteirasOcupadas++;
                }
                break;
			}
			else{
                system("cls");
                menuCliente();
                break;
			}
		case 3:
			printf("Valor - Entrada especial(idosos e eficientes): %.2f - gratuidade\n",especial);
			printf("Efetuar compra? (S - Sim, N - Nao)\n");
			fflush(stdin);
			scanf("%c",&r);
			if(toupper(r) == 'S'){
                if (ocuparCadeira(3)){
                  printf("Ingresso comprado com sucesso!\n");
                  EspeciaisOcupadas++;
                }
                break;
			}
			else{
                system("cls");
                menuCliente();
                break;
			}


      }
}

/*Oferece a parte visual do processo de compra, chamando o método comprarIngresso para realizá-la. */
void efetuarCompra(){
	int tipoIng;
	printf("**********************************************\n");
	printf("                                			\n");
	printf("   Insira o tipo de ingresso (4 - voltar):  \n");
	printf("                                    		\n");
	printf("                  1. Meia                   \n");
	printf("                                  		    \n");
	printf("                 2. Inteira                 \n");
	printf("                                    		\n");
	printf("        3. Especial(idosos e deficientes)   \n");
	printf("                                   		    \n");
	printf("**********************************************\n");
	scanf("%d",&tipoIng);
	system("cls");
	comprarIngresso(tipoIng);

}


/* Cancela a compra, inserindo o valor inicial na posição dela. */
void cancelarCompra(){
	printf(" _______________________________________________________\n");
	printf("*                                           		    *\n");
	printf("*  Insira a cadeira e a fileria do ingresso comprado:   *\n");
	printf("*                                           			*\n");
	printf("*_______________________________________________________*\n");
	scanf("%d %d",&cadeira,&fileira);
	sessao[cadeira][fileira] = 0;
	system("cls");
	printf("Ingresso devolvido com sucesso. Lamentamos sua devolucao. Volte sempre.\n");
}

/* Menu principal do cliente. Retorna a seleção que, no main, será direcionada para os métodos de compra, cancelamento
 * e pesquisa dos assentos. */
int menuCliente(){
    int resposta;
	printf("-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*\n");
	printf("                 BEM VINDO(A)!              \n");
	printf("        Digite o que deseja fazer:          \n");
	printf("                                    		\n");
	printf("           1. Comprar ingresso.             \n");
	printf("                                  		    \n");
	printf("          2. Cancelar uma compra.           \n");
	printf("                                    		\n");
	printf("        3. Pesquisar por uma cadeira.       \n");
	printf("                                    		\n");
	printf("                   4.Sair.                  \n");
	printf("                                    		 \n");
    printf("-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*\n");
	scanf("%d",&resposta);
	system("cls");
	return resposta;
}

/* Função que retorna o total arrecadado por sessão. */
void totalArrecadado(){
    int total = (MeiasOcupadas * meia) + (InteirasOcupadas * inteira);
    printf("----------------------------------------------\n");
    printf("     Valor arrecadado total: R$ %.2f \n", total);
    printf("----------------------------------------------\n");
}

/*Função que separa por sessão os valores. */
void arrecadacao(){
    printf("--->  Foram compradas:                                    \n");
    printf("   # %d entradas inteiras, resultando em: R$ %.2f no total.\n", InteirasOcupadas, (InteirasOcupadas * inteira));
    printf("   # %d meia entradas, resultando em: R$ %.2f no total.     \n", MeiasOcupadas, (MeiasOcupadas * meia));
    printf("   # %d entradas especiais, gratuitas.                       \n", EspeciaisOcupadas);
}

/* Menu principal do funcionário. Retorna a seleção que, no main, será direcionada para os métodos de veirificação do
 * total arrecadado e de início de uma nova sessão. */
int menuFunc(){
    int resposta;
	printf("-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*\n");
	printf("                 BEM VINDO(A)!              \n");
	printf("        Digite o que deseja fazer:          \n");
	printf("                                    		\n");
	printf("           1. Ver total arrecadado.         \n");
	printf("                                  		    \n");
	printf("          2. Ver valores individuais.       \n");
	printf("                                    		\n");
	printf("           3. Iniciar nova sessao.          \n");
	printf("                                    		\n");
	printf("                   4.Sair.                  \n");
	printf("                                    		 \n");
    printf("-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*\n");
	scanf("%d",&resposta);
	system("cls");
	return resposta;
}
/* Main do programa. Separa as funções entre pertencentes ao cliente e ao funcionário. */
//Falha na repetição, ele aborta assim que conclui alguma das operações.                               TO DO
int main(){
    iniciarSessao();
    int op;
    char user = 'A';
    while (toupper(user) !=  'S'){
            printf("Quem esta gerenciando? (C - cliente / F - fucionario)  [S - Sair] \n");
            scanf("%c",&user);
            if(toupper(user) == 'C'){
                    system("cls");
                    while ((op = menuCliente()) != 4){
                        switch(op){
                            case 1:
                                efetuarCompra();
                                break;
                            case 2:
                                cancelarCompra();
                                break;
                            case 3:
                                pesquisarCadeira();
                                break;
                            case 4:
                                printf("Agradecemos o uso dos nossos servicos! Volte sempre. ");
                                break;
                            default:
                                printf("Caracter invalido! Por favor, digite um numero das escolhas apresentadas. \n");
                        }
                  }
            } else if(toupper(user) == 'F') {
                            system("cls");
                            while ((op = menuFunc()) != 4){
                                switch(op){
                                case 1:
                                    totalArrecadado();
                                    break;
                                case 2:
                                    arrecadacao();
                                    break;
                                case 3:
                                    iniciarSessao();
                                    break;
                                case 4:
                                    break;
                                default:
                                    printf("Caracter invalido! Por favor, digite um numero das escolhas apresentadas. \n");
                                }
                            }
            }
        }

}
