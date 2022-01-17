#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#define TAMANHO 100

typedef struct 
{
  int nif;
  char codigo[50];
  int tempo;
  int distancia;
  int nrPedido;
}Utilizacao;

typedef struct 
{ 
 float custo;
 char tipo[50];
 int livre;
 int autonomia;
 char codigo[50];
}Equipamento;

int menu(); // onde vou criar o menu para o Utilizacao
int inserirEquipamento(Equipamento M[TAMANHO], int qt, char cod[50], char tp[50], int autonom, float ct); // inserir a Equipamento 
void listarEquipamento(Equipamento M[TAMANHO], int qt);
int removerEquipamento(Equipamento M[TAMANHO], int qt, char cod[50]);
int pedidoutilizacao(Equipamento M[TAMANHO], Utilizacao U[TAMANHO], int nPedido, int num, char cod[50], int temp, int dist, int qt);
int verificarcodigo(Equipamento M[TAMANHO], int qt, char cod[50]);
//int verificarlivre(Equipamento M[TAMANHO], Utilizacao U[TAMANHO], char cod[50], int qt, int nPedido);
int verificardistancia(Equipamento M[TAMANHO], int qt, int dist, char cod[50]);
void listarpedidos(Utilizacao U[TAMANHO], int nPedido);
int removerpedidos(Equipamento M[TAMANHO],Utilizacao U[TAMANHO], int qt, int contaPed, int nPedido);
int calcularpreco(Utilizacao U[TAMANHO], Equipamento M[TAMANHO], int qt, int nPedido);
//int vertransacoes(Utilizacao U[TAMANHO], Equipamento M[TAMANHO], char cod[50]);
int entregarEquipamento(Utilizacao U[TAMANHO], Equipamento M[TAMANHO], int qt, char cod[50]);

int menu()
{
  int opcao;
  
  do
      {
       printf(" M E N U \n");
       printf("1- Inserir Equipamento\n");
       printf("2- Listar Equipamento\n");
       printf("3- Remover Equipamento\n");
       printf("4- Pedido de utilizacao\n");
       printf("5- Listar pedidos\n");
       printf("6- Remover pedido de utilizacao\n");
       printf("7- Entregar Equipamento\n");
       printf("8- Calcular custo do pedido\n");
       printf("9- Ver Transacoes\n");
       printf("0- Sair\n");
       printf("Opcao: ");
       scanf("%d", &opcao);
      }
  while ((opcao>10)||(opcao<0));  // as opcoes para ja vao de 8 ate 0, logo tem de ser sempre menores que 9 e maiores que 0 
  
  return (opcao);
}

int inserirEquipamento(Equipamento M[TAMANHO], int qt, char cod[50], char tp[50], int autonom, float ct)
{
  if (qt<TAMANHO){
    strcpy(M[qt].codigo,cod);
    strcpy(M[qt].tipo,tp);
    M[qt].autonomia = autonom;
    M[qt].custo = ct; 
    M[qt].livre = 1;
    return(1);
  }
 
  return (0);
}

void listarEquipamento(Equipamento M[TAMANHO], int qt)
{
  int i;

  for ( i = 0; i < qt; i++)
  {
    printf("----------------\n");
    printf("Codigo: %s\n",M[i].codigo);
    printf("Tipo: %s\n",M[i].tipo);
    printf("Autonomia: %d\n",M[i].autonomia);
    printf("Custo: %.2f\n",M[i].custo);
    printf("Livre: %d\n", M[i].livre);
    printf("----------------\n");
  }
}

int removerEquipamento(Equipamento M[TAMANHO], int qt, char cod[50]) // se tiver 3 Equipamentos nao remove a segunda
{
  int i;
  for ( i = 0; i < qt; i++){
    if (strcmp(M[i].codigo,cod)==0){
      if (i == qt-1)
          return (1);
      else