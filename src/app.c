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

  Trie* trie = criaTrie();

  if (trie == NULL){
    printf("Problemas para criar a arvore\n");
    return 0;
  }

  FILE *arq = fopen("palavras.txt", "r");
  if (arq == NULL)
    return 0;
//Insercao das palavras----------------------------------------------------------------

  char palavra[50];
  while(1){
    if(feof(arq))
        break;
    fscanf(arq,"%s", palavra);
   // printf("%s\n",palavra); apenas para teste
    if(insereTrie(trie, palavra))
        printf("Sucesso ao inserir %s\n",palavra);
    else{
        printf("Falha ao inserir %s\n",palavra);
        break;
        }
    }
//-------------------------------------------------------------------------------------
      //system("pause"); //windows
      //setbuf(stdin, NULL); //linux
      //int c = getchar(); //linux
      //system("clear"); //linux
      //system("cls"); //windows

   char op;
   while(1){
    switch(op){
        setbuf(stdin,NULL);
        printf("1-Remover palavra\n2-Buscar palavra\n3-Finalizar execucao");
        op = gechar();
//-------------------------------------------------------------------------------------
        case '1':
            printf("Qual palavra deseja remover?\n");
            scanf("%s",palavra);
            if(removeTrie(trie,palavra)){
                printf("Sucesso na remocao de %s\n",palavra);
            } else {
                printf("Falha na remocao %s\n",palavra);
            } break;
//-------------------------------------------------------------------------------------
        case '2':
            printf("Qual palavra deseja buscar?\n");
            scanf("%s",palavra);
            if(buscaTrie(trie,palavra)){
                printf("Esta palavra esta na arvore\n");
            } else{
                printf("Esta palavra nao esta na arvore\n");
            } break;
//-------------------------------------------------------------------------------------
        case '3':
            printf("Liberando a arvore\n");
            liberaTrie(trie);
            printf("Fim da execucao\n");
            return 0;
//-------------------------------------------------------------------------------------
        }
    }
    return 0;
}
