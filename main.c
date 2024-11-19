#include <stdio.h>
#include <stdlib.h>
#define MAX 200
typedef struct{
    char nome[MAX];
    char isbn[MAX];
    float preco;
    int score;
    char editora[MAX];
}livro, *pLivro;

pLivro livro_aloc(int qtde);
void livro_ler(pLivro livros, int qtde);
void livro_exibe(pLivro livros, int qtde);
void livro_desaloca(pLivro livros);

void clear(){
    int c;
    while ((c = getchar()) != '\n' && c != EOF) { }
}


int main(){
    int qtde;
    scanf("%d ", &qtde);
    if(qtde>0){
        pLivro livros=livro_aloc(qtde);
        livro_ler(livros, qtde);
        livro_exibe(livros, qtde);
        livro_desaloca(livros); 
    }else
        printf("Sem livros");
    return 0;
}


pLivro livro_aloc(int qtde){
    pLivro livros=(pLivro)malloc(qtde*sizeof(livro));
    return livros;
}
void livro_ler(pLivro livros, int qtde){
    for(int i=0; i<qtde; i++){
        scanf("%[^\n]s ", livros[i].nome);
        clear();
        scanf("%[^\n]s ", livros[i].isbn);
        clear();
        scanf("%f ", &livros[i].preco);
        scanf("%d ", &livros[i].score);
        scanf("%[^\n]s ", livros[i].editora);
        clear();
    }
}
void livro_exibe(pLivro livros, int qtde){
    for(int i=0; i<qtde; i++){
        printf("Livro %d:\n", i+1);
        printf("Nome: %s\n", livros[i].nome);
        printf("ISBN: %s\n", livros[i].isbn);
        printf("Preço: R$ %.2f\n", livros[i].preco);
        printf("Score: %d\n", livros[i].score);
        printf("Editora: %s\n", livros[i].editora);
        printf("\n");
    }
}
void livro_desaloca(pLivro livros){
    free(livros);
}