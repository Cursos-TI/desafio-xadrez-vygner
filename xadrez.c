#include <stdio.h>
#include <string.h>


// Tema 4 - Movimentação de Peças de Xadrez
// Usa apenas variáveis inteiras e strings (char arrays)
// Estruturas usadas: for, while, do-while, loops aninhados, recursão, continue, break


// PROTÓTIPOS (para seção Mestre)
void torre_recursiva(int passos, char direcao[]);
void rainha_recursiva(int passos, char direcao[]);
void bispo_recursivo_com_loops(int passos);


// FUNÇÃO PRINCIPAL
int main() {
    // Variáveis (apenas inteiros e strings/char arrays, conforme exigido)
    int torre_passos_novato = 5;     // Torre: 5 casas para a direita (novato)
    int bispo_passos_novato  = 5;    // Bispo: 5 casas diagonal cima-direita (novato)
    int rainha_passos_novato = 8;    // Rainha: 8 casas para a esquerda (novato)


    // Strings descritivas (char arrays)
    char nome_torre[20];
    char nome_bispo[20];
    char nome_rainha[20];
    char nome_cavalo[20];


    strcpy(nome_torre, "Torre");
    strcpy(nome_bispo, "Bispo");
    strcpy(nome_rainha, "Rainha");
    strcpy(nome_cavalo, "Cavalo");


    /* NÍVEL NOVATO
       - Torre (for)
       - Bispo (while)
       - Rainha (do-while) */
    printf("NÍVEL NOVATO: Movimentos básicos\n\n");


    // Torre: Move 5 casas para a direita — usar FOR
    printf("-> %s (usando for): movimento 5 casas para a Direita\n", nome_torre);
    for (int i = 0; i < torre_passos_novato; i++) {
        // A cada iteração imprimimos a direção
        printf("Direita\n");
    }
    printf("\n"); //separador visual


    // Bispo: Move 5 casas diagonal (Cima, Direita) — usar WHILE
    printf("-> %s (usando while): movimento 5 casas na diagonal Cima-Direita\n", nome_bispo);
    int cont_bispo = 0;
    while (cont_bispo < bispo_passos_novato) {
        // Impressão combinada para diagonal
        printf("Cima, Direita\n");
        cont_bispo++;
    }
    printf("\n"); // separador visual


    // Rainha: Move 8 casas para a esquerda — usar DO-WHILE
    printf("-> %s (usando do-while): movimento 8 casas para a Esquerda\n", nome_rainha);
    int cont_rainha = 0;
    do {
        printf("Esquerda\n");
        cont_rainha++;
    } while (cont_rainha < rainha_passos_novato);
    printf("\n"); // separador visual


    /* NÍVEL AVENTUREIRO
       - Cavalo em "L" (loops aninhados)
       - Para este nível: Cavalo se move duas casas para baixo e uma para a esquerda
       - Usa pelo menos um for e outro while/do-while aninhados */
    printf("NÍVEL AVENTUREIRO: Movimento do Cavalo (L)\n\n");


    printf("-> %s (L simples com loops aninhados): 2 Baixo, 1 Esquerda\n\n", nome_cavalo);


    // Implementação exigida: pelo menos dois loops aninhados, sendo um for
    /* Estrutura: for externo (uma 'tentativa' do movimento L), inner while para
       vertical, inner for para horizontal */
    for (int tentativa = 0; tentativa < 1; tentativa++) {
        int passos_verticais = 2; // duas casas para baixo
        int passos_horizontais = 1; // uma casa para esquerda


        // loop vertical usando while (aninhado dentro do for)
        int v = 0;
        while (v < passos_verticais) {
            printf("Baixo\n");
            v++;
        }


        // loop horizontal usando for (aninhado dentro do for)
        for (int h = 0; h < passos_horizontais; h++) {
            printf("Esquerda\n");
        }
    }
    printf("\n"); // separar seções


    /* NÍVEL MESTRE
       - Substituir Torre, Bispo, Rainha por funções recursivas
       - Bispo: recursividade + loops aninhados (outer vertical, inner horizontal)
       - Cavalo avançado: loops aninhados com múltiplas variáveis/condições, usar continue/break
       - Para este nível, o Cavalo move 2 casas para cima e 1 para a direita (L invertido) */
    printf("NÍVEL MESTRE: Movimentos recursivos e loops complexos\n\n");


    // Valores (definidos em código)
    int torre_passos_mestre = 5;     // manter 5 para consistência
    int bispo_passos_mestre  = 5;    // manter 5
    int rainha_passos_mestre = 8;    // manter 8


    // Torre recursiva: 5 passos para a Direita
    printf("-> %s (recursiva): %d casas para a Direita\n", nome_torre, torre_passos_mestre);
    torre_recursiva(torre_passos_mestre, "Direita");
    printf("\n");


    /* Bispo recursivo + loops aninhados:
       - Requisito: função recursiva que, a cada chamada, executa loops aninhados:
         loop externo para componente vertical, loop interno para componente horizontal.
       - A cada "passo recursivo" imprime "Cima" e "Direita" na ordem solicitada. */
    printf("-> %s (recursiva + loops aninhados): %d casas Cima e Direita (diagonal)\n", nome_bispo, bispo_passos_mestre);
    bispo_recursivo_com_loops(bispo_passos_mestre);
    printf("\n");


    // Rainha recursiva: 8 passos para a Esquerda
    printf("-> %s (recursiva): %d casas para a Esquerda\n", nome_rainha, rainha_passos_mestre);
    rainha_recursiva(rainha_passos_mestre, "Esquerda");
    printf("\n");


    // Cavalo avançado: duas casas para CIMA e uma para DIREITA.
    // Requisito: utilizar loops aninhados com múltiplas variáveis/condições, e usar continue/break.
    
    printf("-> %s (avançado com loops complexos): 2 Cima, 1 Direita (movimento em L)\n\n", nome_cavalo);


    // Implementação com loops aninhados, múltiplas variáveis e controle de fluxo */
    for (int tentativa = 0; tentativa < 1; tentativa++) {
        int need_up = 2;
        int need_right = 1;
        int up_done = 0;
        int right_done = 0;


        // loop externo: tentará construir a sequência em L
        for (int outer = 0; outer < 10; outer++) { // limite para segurança; será quebrado internamente
            // se ainda precisamos subir, fazemos os movimentos verticais
            if (up_done < need_up) {
                // movimento vertical: usar loop interno para subir, demonstrando aninhamento
                for (int v = 0; v < (need_up - up_done); v++) {
                    printf("Cima\n");
                    up_done++;
                    // continue usado para pular para a próxima iteração do loop externo se necessário
                    if (up_done < need_up) {
                        continue;
                    }
                }
            }


            // quando terminar os up, fazemos o movimento horizontal
            while (up_done >= need_up && right_done < need_right) {
                // se uma condição especial fosse vérificada poderíamos pular, aqui apenas demonstramos break
                if (right_done >= need_right) {
                    break;
                }
                printf("Direita\n");
                right_done++;
                // break para sair do while após completar
                if (right_done >= need_right) {
                    break;
                }
            }


            // condição de término geral
            if (up_done >= need_up && right_done >= need_right) {
                break; // movimento L completo
            }


            // segurança para evitar loop infinito
            if (outer == 9) {
                // não deveria acontecer com os valores atuais
                break;
            }
        } // fim do for outer
    } // fim tentativa


    printf("\n"); // separador final


    printf("Simulação concluída.\n"); // despedida  


    return 0;
}


/* IMPLEMENTAÇÕES DE FUNÇÕES RECURSIVAS (NÍVEL MESTRE)
   - torre_recursiva: imprime direção e chama recursivamente até 0
   - rainha_recursiva: idem para a rainha
   - bispo_recursivo_com_loops: recursiva + loops aninhados (vertical externo, horizontal interno)
   Observação: todas usam apenas variáveis inteiras e strings (char arrays para direções passadas). */


// Torre recursiva: imprime 'direcao' e chama até passos == 0
void torre_recursiva(int passos, char direcao[]) {
    if (passos <= 0) {
        return; // caso base: nada a fazer
    }
    // A cada chamada imprimimos a direção correspondente a uma casa
    printf("%s\n", direcao); // ex: "Direita"
    // chamada recursiva decremente os passos
    torre_recursiva(passos - 1, direcao);
}


// Rainha recursiva: similar
void rainha_recursiva(int passos, char direcao[]) {
    if (passos <= 0) {
        return;
    }
    printf("%s\n", direcao); // ex: "Esquerda"
    rainha_recursiva(passos - 1, direcao);
}


/* Bispo recursivo com loops aninhados:
   - Para cada passo recursivo, executa um loop externo (vertical) e um interno (horizontal).
   - Aqui o loop externo representa a componente "Cima" e o interno a componente "Direita". */
void bispo_recursivo_com_loops(int passos) {
    if (passos <= 0) {
        return; // caso base
    }


    // Exemplo de loops aninhados: outer -> vertical (Cima), inner -> horizontal (Direita)
    int vertical_loops = 1;   // cada recursão representa 1 passo vertical
    int horizontal_loops = 1; // cada recursão representa 1 passo horizontal


    for (int v = 0; v < vertical_loops; v++) {
        // movimento vertical
        printf("Cima\n");


        // loop interno para component horizontal
        for (int h = 0; h < horizontal_loops; h++) {
            printf("Direita\n");
        }
    }


    // chamada recursiva para o próximo passo diagonal
    bispo_recursivo_com_loops(passos - 1);
}
