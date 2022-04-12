#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int v[10];
    int nElementos;
} t_lista;

void zerar(t_lista *lista) {
    lista->nElementos = 0;
}

void inserir(t_lista *lista) {
    // inserir elemento na lista
    if(lista->nElementos == 10)
         printf("Lista cheia!\n");
    else {
        printf("Insira um número: ");
        scanf("%d%*c", &lista->v[lista->nElementos]);
        lista->nElementos++;
    }
}

void listar(t_lista *lista) {
    // listar elementos da lista
    if(lista->nElementos == 0)
        printf("Lista vazia!\n");
    else {
        for(int i = 0; i < lista->nElementos; i++) {
            printf("lista[%d]: %d\n", i, lista->v[i]);
        }
        printf("Pressione enter para continuar!\n");
    }
    
    getchar();
}

void consultar(t_lista *lista); // valor 1.0 ponto
void editar(t_lista *lista); // valor 1.0 ponto
void deletar(t_lista *lista); // valor 1.0 ponto
void ordenar(t_lista *lista); // valor 2.0 pontos (crescente e decrescente)

int main() {
    // criar lista
    t_lista lista;
    lista.nElementos = 0;
    

    while(1) {
        system("clear"); // linux
        // ststem("cls"); // windows
        int opcao = 0;
        printf("0 - Zerar lista.\n");
        printf("1 - Inserir elemento.\n");
        printf("2 - Listar.\n");
        printf("3 - Consultar.\n");
        printf("4 - Editar.\n");
        printf("5 - Deletar.\n");
        printf("6 - Ordenar.\n");
        printf("7 - Sair.\n");
        printf("Opção: ");
        scanf("%d%*c", &opcao);

        switch(opcao) {
            case 0: 
                zerar(&lista);
                break;
            case 1: 
                inserir(&lista);
                break;
            case 2:
                listar(&lista);
                break;
            case 3:
                consultar(&lista);
                break;
            case 4:
                editar(&lista);
                break;
            case 5:
                deletar(&lista);
                break;
            case 6:
                ordenar(&lista);
                break;
            case 7:
                return 0;
            default:
                printf("Opção inválida!");
                getchar();
        }
    }

}

void consultar(t_lista *lista) { 
    // passo 1
    int n;
    printf("Insira o número a ser consultado na lista: ");
    scanf("%d%*c", &n);
    // passo 2
    for(int i = 0; i < lista->nElementos; i++) {
        // busca sequencial -> melhor caso O(1), pior caso O(n)
        if(n == lista->v[i]) {
            printf("lista[%d]: %d\n", i, lista->v[i]);
            getchar();
            break;
        }
    }
 }
void editar(t_lista *lista) { 
    int indice, n;
    // passo 1
    printf("Insira um indice da lista para edição: ");
    scanf("%d%*c", &indice);
    
    if(indice < 0 || indice >= lista->nElementos) {
        // posição inválida
        printf("Índice inválido!\n");
        getchar();
    } else {
        printf("Insira um número para edição: ");
        scanf("%d%*c", &n);
        lista->v[indice] = n;
    }
}
void deletar(t_lista *lista) { 
    int indice;
    // passo 1
    printf("Insira um indice da lista para deleção: ");
    scanf("%d%*c", &indice);
    if(indice < 0 || indice >= lista->nElementos) {
        printf("Índice inválido!\n");
        getchar();
    } else {
        // deleção no fim
        if(indice == lista->nElementos-1)
            lista->nElementos--;
        else {
            for(int i = indice; i < lista->nElementos-1; i++) {
                lista->v[i] = lista->v[i+1];
            }
            lista->nElementos--;
        }
    }
}
void ordenar(t_lista *lista) { 
    int criterio;
    printf("Selecione um critério de ordenação:\n");
    printf("1 - Crescente\n");
    printf("2 - Decrescente\n");
    scanf("%d%*c", &criterio);
    if(criterio != 1 && criterio != 2) {
        printf("Critério inválido!");
        getchar();
    } else {
        for(int i = 0; i < lista->nElementos-1; i++) {
            for(int j = i+1; j < lista->nElementos; j++) {
                if(criterio == 1) { // crescente
                    if(lista->v[j] < lista->v[i]) {
                        int aux = lista->v[i];
                        lista->v[i] = lista->v[j];
                        lista->v[j] = aux;
                    }
                } else { // decrescente
                    if(lista->v[j] > lista->v[i]) {
                        int aux = lista->v[i];
                        lista->v[i] = lista->v[j];
                        lista->v[j] = aux;
                    }
                }
            }
        }
    }
    
}
