    //Desafio 1 -- Super Trunfo -- Países

#include <stdio.h>
#include <stdlib.h>

#define numestados 8
#define numcidadesporestado 4

//Estrutura pra determinar cidade
typedef struct {
    char estado;
    int cidade;
    long populacao;
    long pib;
    float area;
    int numponturisticos;
} Cidade;

int CadastrarCidade(Cidade *cidade) //Cadastrando de cidade
{
    printf("\n cadastro da cidade %c%02d\n", cidade -> estado, cidade -> cidade );
    printf("\n Digite a População: \n");
    if (scanf("%ld", &cidade -> populacao) != 1) return 0; //retorna 0 em caso de erro
    printf("\n Digite o Pib: \n");
    if (scanf("%ld", &cidade -> pib) != 1) return 0; //retorna 0 em caso de erro
    printf("\n Digite o tamanho da área do lugar: \n");
    if (scanf("%f", &cidade -> area) != 1) return 0; //retorna 0 em caso de erro
    printf("\n Digite o número de pontos turísticos do local: \n");
    if (scanf("%d", &cidade -> numponturisticos) != 1) return 0; //retorna 0 em caso de erro
    return 1; //em caso de sucesso
}

int ExibirCidade(Cidade cidade) //Exibindo Cidades
{
    printf("\n Cidade %c%02d\n", cidade.estado, cidade.cidade);
    printf("\n De população: %ld\n", cidade.populacao);
    printf("\n De pib; %ld\n", cidade.pib);
    printf("\n A área do lugar é: %.2f\n", cidade.area);
    printf("\n E que possui %d pontos turísticos.\n", cidade.numponturisticos);
    return 1; //Pra indicar que foi um sucesso
}

int main()
{
    Cidade cidades[numestados][numcidadesporestado];
    char estados[] = {'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H'};


    //cadastro de cidade:
    for (int i = 0; i < numestados; i++)
    {
        for (int j = 0; j < numcidadesporestado; j++)
        {
            cidades[i][j].estado = estados[i];
            cidades[i][j].cidade = j + 1;

            if(!CadastrarCidade(&cidades[i][j]))
            {
                printf("Erro ao cadastrar cidade %c%02d\n", estados[i], j + 1);
                return 1; //finalizando em caso de erro
            }

        }
    }

    //exibir os dados da cidade:
    printf("Dados das cidades: \n");
    for (int i = 0; i < numestados; i++)
    {
        for (int j = 0; j < numcidadesporestado; j++)
        {
            if(!ExibirCidade(cidades[i][j]))
            {
                printf("Erro ao exibir a cidade %c%02d\n", estados [i], j + 1);
                return 1; //finalizando em caso de erro
            }
        }
    }

return 0; //indicador de programa finalizando com sucesso

}
