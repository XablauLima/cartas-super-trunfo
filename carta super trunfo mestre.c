#include <stdio.h>
#include <stdlib.h> // Necessário para usar funções como system("cls")

int main() {
    // Variáveis para as cartas
    char estado1[50], estado2[50];
    char codigo1[10], codigo2[10]; // Aumentei o tamanho para evitar overflow
    char cidade1[50], cidade2[50];
    int pontosturisticos1, pontosturisticos2;
    float areakm1, pib1, areakm2, pib2, densidade1, densidade2, pibpercapta1, pibpercapta2;
    unsigned long int populacao1, populacao2;

    // Entrada de dados para a carta 1
    printf("Insira as informações da carta 1:\n");
    printf("Estado: ");
    scanf(" %[^\n]s", estado1); // Use %[^\n]s para ler strings com espaços

    printf("Código da carta: ");
    scanf(" %s", codigo1);

    printf("Nome da cidade: ");
    scanf(" %[^\n]s", cidade1);

    printf("População: ");
    scanf(" %lu", &populacao1);

    printf("Área em Km²: ");
    scanf(" %f", &areakm1);

    printf("PIB em bilhões: ");
    scanf(" %f", &pib1);

    printf("Número de pontos turísticos: ");
    scanf(" %d", &pontosturisticos1);

    // Entrada de dados para a carta 2 (similar à carta 1)
    printf("\nInsira as informações da carta 2:\n");
    printf("Estado: ");
    scanf(" %[^\n]s", estado2);

    printf("Código da carta: ");
    scanf(" %s", codigo2);

    printf("Nome da cidade: ");
    scanf(" %[^\n]s", cidade2);

    printf("População: ");
    scanf(" %lu", &populacao2);

    printf("Área em Km²: ");
    scanf(" %f", &areakm2);

    printf("PIB em bilhões: ");
    scanf(" %f", &pib2);

    printf("Número de pontos turísticos: ");
    scanf(" %d", &pontosturisticos2);


    // Cálculos
    densidade1 = (areakm1 > 0) ? (float)populacao1 / areakm1 : 0; // operador ternário para evitar divisão por zero
    pibpercapta1 = (populacao1 > 0) ? (pib1 * 1000000000.0) / populacao1 : 0;

    densidade2 = (areakm2 > 0) ? (float)populacao2 / areakm2 : 0;
    pibpercapta2 = (populacao2 > 0) ? (pib2 * 1000000000.0) / populacao2 : 0;


    // Impressão das informações das cartas (melhorei a formatação)
    printf("\n--- Carta 1 ---\n");
    printf("Estado: %s\n", estado1);
    printf("Código: %s\n", codigo1);
    printf("Cidade: %s\n", cidade1);
    printf("População: %lu\n", populacao1);
    printf("Área (km²): %.2f\n", areakm1);
    printf("PIB (bilhões): %.2f\n", pib1);
    printf("Pontos Turísticos: %d\n", pontosturisticos1);
    printf("Densidade Populacional (hab/km²): %.2f\n", densidade1);
    printf("PIB per Capita: R$ %.2f\n", pibpercapta1);

    printf("\n--- Carta 2 ---\n");
    printf("Estado: %s\n", estado2);
    printf("Código: %s\n", codigo2);
    printf("Cidade: %s\n", cidade2);
    printf("População: %lu\n", populacao2);
    printf("Área (km²): %.2f\n", areakm2);
    printf("PIB (bilhões): %.2f\n", pib2);
    printf("Pontos Turísticos: %d\n", pontosturisticos2);
    printf("Densidade Populacional (hab/km²): %.2f\n", densidade2);
    printf("PIB per Capita: R$ %.2f\n", pibpercapta2);


    // Comparação (Exemplo com múltiplos atributos e pesos - você pode ajustar os pesos)
    printf("\n--- Comparação ---\n");
    float peso_area = 0.2;
    float peso_pib = 0.3;
    float peso_populacao = 0.3;
    float peso_pontos = 0.2;

    float pontuacao1 = (areakm1 * peso_area) + (pib1 * peso_pib) + (populacao1 * peso_populacao) + (pontosturisticos1 * peso_pontos);
    float pontuacao2 = (areakm2 * peso_area) + (pib2 * peso_pib) + (populacao2 * peso_populacao) + (pontosturisticos2 * peso_pontos);

    if (pontuacao1 > pontuacao2) {
        printf("Carta 1 (%s) venceu!\n", cidade1);
    } else if (pontuacao2 > pontuacao1) {
        printf("Carta 2 (%s) venceu!\n", cidade2);
    } else {
        printf("Empate!\n");
    }

    return 0;
}
