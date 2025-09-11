#include <stdio.h>
#include <stdlib.h>

// EP 2: Jogo da velha
/*********************************************************************/
/**   ACH2001 - Introdução à Programação                            **/
/**   EACH-USP - Primeiro Semestre de 2024                          **/
/**   Turma: 2024194 - Prof: Marcelo Morandini                      **/
/**   Segundo Exercí­cio-Programa                                    **/
/**                                                                 **/
/**   Integrantes                                                   **/
/**   - Daniel Lima; nº usp: 9331249                                **/
/**   - Guilherme Padun; nº usp: 13828007                           **/
/**   - Gustavo Henrique; nº usp: 15674466                          **/
/**                                                                 **/
/*********************************************************************/

char jogo[3][3]; // criando uma matriz de caracteres global para facilitar na criação de funções e procedimentos
int i, j;		 // criando as variáveis globais de indices de linha e coluna

// procedimento para imprimir o jogo
void imprimirJogo()
{
	printf("\n   Coluna\n\n");
	printf(" 0   1   2   Linha\n\n"); // indicando o índice da linha e coluna para o jogador

	for (i = 0; i < 3; i++)
	{
		printf(" "); // ajuste para alinhar as colunas

		for (j = 0; j < 3; j++)
		{
			printf(" %c ", jogo[i][j]);

			// agora adicionaremos barras horizontais e verticais a fim de separar as linhas e colunas e simular um tabuleiro de jogo da velha (#):
			if (j < 2) // adicionaremos uma barra entre as colunas 0 e 1, e 1 e 2, por isso a barra será adicionada somente para a coluna j<2
				printf("|");
		}

		printf("  %d", i); // imprime o índice da linha
		if (i < 2)		   // adicionaremos uma linha entre as linhas 0 e 1, e 1 e 2 da matriz por isso as linhas serão adicionadas somente para a linha i<2
			printf("\n -----------\n");
		else
			printf("\n");
	}
}

// função que retorna a quantidade de posições vazias
int qtdeCasasVazias()
{
	int qtde = 0;
	for (i = 0; i < 3; i++)
	{
		for (j = 0; j < 3; j++)
			if (jogo[i][j] == ' ') // conta as casas que contém o caracter espaço
				qtde++;
	}
	return qtde;
}

// função para verificar a vitória em uma linha
int ganhouALinha(int linha, char c)
{
	if (jogo[linha][0] == c && jogo[linha][1] == c && jogo[linha][2] == c) // verifica se todos os elementos de uma linha são iguais; funciona tanto para X e O
		return 1;														   // ganhou
	else
		return 0; // nao ganhou ainda
}

// verifica a vitoria da partida por linhas
int ganhouPorLinhas(char c)
{
	int ganhou = 0;
	for (i = 0; i < 3; i++)
	{
		ganhou += ganhouALinha(i, c);
	}
	return ganhou;
}

// função para verificar a vitória em uma coluna
int ganhouAColuna(int coluna, char c)
{
	if (jogo[0][coluna] == c && jogo[1][coluna] == c && jogo[2][coluna] == c) // verifica se todos os elementos de uma coluna são iguais; funciona tanto para X e O
		return 1;															  // ganhou
	else
		return 0; // nao ganhou ainda
}

// verifica a vitoria da partida por colunas
int ganhouPorColunas(char c)
{
	int ganhou = 0;
	for (j = 0; j < 3; j++)
	{
		ganhou += ganhouAColuna(j, c);
	}
	return ganhou;
}

// função que verifica se houve vitória na diagonal principal
int ganhouADiagPrincipal(char c)
{
	if (jogo[0][0] == c && jogo[1][1] == c && jogo[2][2] == c) // verifica se todos os elementos de da diagonal principal são iguais
		return 1;											   // ganhou
	else
		return 0; // nao ganhou ainda
}

// função que verifica se houve vitória na diagonal secundária
int ganhouADiagSecundaria(char c)
{
	if (jogo[0][2] == c && jogo[1][1] == c && jogo[2][0] == c) // verifica se todos os elementos da diagonal secundária são iguais
		return 1;											   // ganhou
	else
		return 0; // não ganhou ainda
}

// função para verificar se as coordenadas inseridas pelo jogador são válidas
int ehValida(int linha, int coluna)
{
	if (linha < 0 || linha > 2 || coluna < 0 || coluna > 2 || jogo[linha][coluna] != ' ')
		return 0;
	else
		return 1;
}

// procedimento para ler as coordenadas do jogador
void lerCoordenadas(char c)
{
	int linha, coluna;
	printf("Digite a linha e a coluna que deseja jogar: ");
	scanf("%d%d", &linha, &coluna);

	// enquanto as condições de coordenadas inválidas forem falsas, o jogador deverá inserir coordenadas válidas
	while (ehValida(linha, coluna) == 0)
	{
		printf("Coordenadas invalidas. Insira coordenadas validas: ");
		scanf("%d%d", &linha, &coluna);
	}

	jogo[linha][coluna] = c;
}

// procedimento para jogar o jogo
void jogar()
{
	int jogador = 1, vitoriaX = 0, vitoriaO = 0;
	do
	{
		imprimirJogo(); // imprime o tabuleiro vazio
		if (jogador == 1)
		{
			lerCoordenadas('X'); // caso o jogador 1 esteja jogando, X será atribuido nas coordenadas jogadas por este jogador
			vitoriaX = ganhouPorLinhas('X') || ganhouPorColunas('X') || ganhouADiagPrincipal('X') || ganhouADiagSecundaria('X');
			jogador++; // passando a vez para o próximo jogador
		}
		else
		{
			lerCoordenadas('O'); // quando o outro jogador jogar, será atribuido O nas coordenadas jogadas por este jogador
			vitoriaO = ganhouPorLinhas('O') || ganhouPorColunas('O') || ganhouADiagPrincipal('O') || ganhouADiagSecundaria('O');
			jogador = 1; // volta a vez para o primeiro jogador
		}
	} while (vitoriaX == 0 && vitoriaO == 0 && qtdeCasasVazias() > 0);

	imprimirJogo(); // imprime o tabuleiro ao final do jogo, mostrando a vitória de um dos jogadores ou o empate
	if (vitoriaX == 1)
		printf("Jogador 1 venceu!");
	else if (vitoriaO == 1)
		printf("Jogador 2 venceu!");
	else
		printf("Empatou.");
}

int main()
{
	int opcao;
	for (i = 0; i < 3; i++)
	{
		for (j = 0; j < 3; j++)
		{
			jogo[i][j] = ' ';
		}
	}

	do
	{
		jogar();
		printf("\nDigite 1 para jogar novamente: ");
		scanf("%d", &opcao);
		if (opcao == 1)
		{ // reseta o tabuleiro para um novo jogo
			for (i = 0; i < 3; i++)
			{
				for (j = 0; j < 3; j++)
					jogo[i][j] = ' ';
			}
		}
	} while (opcao == 1);

	return 0;
}