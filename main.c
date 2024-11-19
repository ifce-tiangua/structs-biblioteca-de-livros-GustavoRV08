#include <stdio.h>
#include <stdlib.h>

typedef struct{
    char* nome;
    char* isbn;
    float preco;
    int score;
    char* editora;
}livro, *pLivro;

pLivro livro_aloc(int qtde);
void livro_ler(pLivro livros, int qtde);
void livro_exibe(pLivro livros, int qtde);
void livro_desaloca(pLivro livros);


int main(){
    int qtde;
    scanf("%d", &qtde);
    pLivro livros=livro_aloc(qtde);
    livro_ler(livros, qtde);
    livro_exibe(livros, qtde);
    livro_desaloca(livros);    
    return 0;
}


pLivro livro_aloc(int qtde){
    pLivro livros=(pLivro)malloc(qtde*sizeof(pLivro));
    return livros;
}
void livro_ler(pLivro livros, int qtde){
    for(int i=0; i<qtde; i++){
        scanf("%s", livros[i].nome);
        scanf("%s", livros[i].isbn);
        scanf("%f", livros[i].preco);
        scanf("%d", livros[i].score);
        scanf("%s", livros[i].editora);
    }
}
void livro_exibe(pLivro livros, int qtde){
    for(int i=0; i<qtde; i++){
        printf("Livro %d:\n", i+1);
        printf("Nome: %s\n", livros[i].nome);
        printf("ISBN: %s\n", livros[i].isbn);
        printf("Preço: R$ %f\n", livros[i].preco);
        printf("Score: %d\n", livros[i].score);
        printf("Editora: %s\n", livros[i].editora);
    }
    printf("\n");
}
void livro_desaloca(pLivro livros){
    free(livros);
}