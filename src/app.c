/*
  Integrantes:
  Guilherme Alves Carvalho - 11921BCC016
  João Batista de Sousa Paula - 11911BCC008
  Pedro Leale - 11921BCC008
*/

#include <stdio.h>
#include <stdlib.h>
#include "./trie/trie.h"
int main() {
  Trie *trie = criaTrie();
  if (trie == NULL) {
    printf("Problemas para criar a arvore\n");
    return 0;
  }

  FILE *arq = fopen("./test/words.txt", "r");
  if (arq == NULL) {
    printf("Erro a abrir o arquivo\n");
    return 0;
  }
  //Insercao das palavras----------------------------------------------------------------

  char palavra[50];
  while (1) {
    if (feof(arq))
      break;
    fscanf(arq, "%s", palavra);
    insereTrie(trie, palavra);
    // if (insereTrie(trie, palavra))
    //   printf("Sucesso ao inserir %s\n", palavra);
    // else {
    //   printf("Falha ao inserir %s\n", palavra);
    //   break;
    // }
  }
  //-------------------------------------------------------------------------------------
  
  char op;
  while (1) {
    printf("1-Inserir palavra\n2-Buscar palavra\n3-Finalizar execucao\n4-Imprimir Trie\n5-ORA ORA ORA ORA ORA ORA ORA\n6-Imprimir prefixo\nQual opcao?: ");
    op = getchar();
    switch (op) {
      //-------------------------------------------------------------------------------------
    case '1':
      printf("Qual palavra deseja inserir?\n");
      scanf("%s", palavra);
      if (insereTrie(trie, palavra)) {
        printf("Sucesso na insercao de %s\n", palavra);
      } else {
        printf("Falha na insercao %s\n", palavra);
      }
      break;
      //-------------------------------------------------------------------------------------
    case '2':
      printf("Qual palavra deseja buscar?\n");
      scanf("%s", palavra);
      if (buscaTrie(trie, palavra)) {
        printf("Esta palavra esta na arvore\n");
      } else {
        printf("Esta palavra nao esta na arvore\n");
      }
      break;
      //-------------------------------------------------------------------------------------
    case '3':
      printf("Liberando a arvore\n");
      liberaTrie(trie);
      printf("Fim da execucao\n");
      return 0;
    case '4':
      printf("----------PRINTANDO O TRIE FILHO EXQUECE----------\n");
      imprimeTrie(trie);
      break;
    case '5': 
        printf("⣿⣿⣿⣿⣿⣿⣿⡿⡛⠟⠿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿\n");
        printf("⣿⣿⣿⣿⣿⣿⠿⠨⡀⠄⠄⡘⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿\n");
        printf("⣿⣿⣿⣿⠿⢁⠼⠊⣱⡃⠄⠈⠹⢿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿\n");
        printf("⣿⣿⡿⠛⡧⠁⡴⣦⣔⣶⣄⢠⠄⠄⠹⣿⣿⣿⣿⣿⣿⣿⣤⠭⠏⠙⢿⣿\n");
        printf("⣿⡧⠠⠠⢠⣾⣾⣟⠝⠉⠉⠻⡒⡂⠄⠙⠻⣿⣿⣿⣿⣿⡪⠘⠄⠉⡄⢹\n");
        printf("⣿⠃⠁⢐⣷⠉⠿⠐⠑⠠⠠⠄⣈⣿⣄⣱⣠⢻⣿⣿⣿⣿⣯⠷⠈⠉⢀⣾\n");
        printf("⣿⣴⠤⣬⣭⣴⠂⠇⡔⠚⠍⠄⠄⠁⠘⢿⣷⢈⣿⣿⣿⣿⡧⠂⣠⠄⠸⡜\n");
        printf("⣿⣇⠄⡙⣿⣷⣭⣷⠃⣠⠄⠄⡄⠄⠄⠄⢻⣿⣿⣿⣿⣿⣧⣁⣿⡄⠼⡿\n");
        printf("⣿⣷⣥⣴⣿⣿⣿⣿⠷⠲⠄⢠⠄⡆⠄⠄⠄⡨⢿⣿⣿⣿⣿⣿⣎⠐⠄⠈\n");
        printf("⣿⣿⣿⣿⣿⣿⢟⠕⠁⠈⢠⢃⢸⣿⣿⣶⡘⠑⠄⠸⣿⣿⣿⣿⣿⣦⡀⡉\n");
        printf("⣿⣿⣿⡟⠄⠄⠄⠄⠄⠋⢀⣼⣿⣿⣿⣿⣿⣿⣿⣶⣦⣀⢟⣻⣿⣿⣿⣿\n");
        printf("⣿⣿⣿⡆⠆⠄⠠⡀⡀⠄⣽⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿\n");
        printf("⣿⣿⡿⡅⠄⠄⢀⡰⠂⣼⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿\n");
      break;
    case '6':
      printf("Qual palavra deseja utilizar?\n");
      scanf("%s", palavra);
      autocompletarTrie(trie, palavra);
      break;
      //-------------------------------------------------------------------------------------
    }
    //system("pause"); //windows
    setbuf(stdin, NULL); //linux
    // int c = getchar(); //linux
    // system("clear"); //linux
    //system("cls"); //windows
  }
  liberaTrie(trie);
  free(arq);
  return 0;
}
