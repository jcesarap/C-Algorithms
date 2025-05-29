/*
Programa Caça Letras
Nome: José Herbert Rodrigues Moreno
*/

/*
Subconjunto de caracteres gráficos da Tabela ASCII
{"■","┌","┐","┘","└","─","│","╔","╗","╝","╚","═","║","█","█","█","█","█","█"}
*/

#include "bibtela.h"

int main(void) {
  char palavra[26];
  char key; // para ler tecla
  int finalizar = 1;
  int qnt_letras = 0;
  int qnt_acertos = 0;

  // configura dos caracteres do idioma configurado no sistema
  setlocale(LC_ALL, ".UTF-8");
  setlocale(LC_CTYPE, ".UTF-8");

  init_screen(25, 80);
  clear_screen();

  xywindow(2, 6, 14, 75, 1);
  xywindow(15, 6, 17, 75, 1);
  xyprint(3, 35, "Caça Letras");

  xyprint(16, 7, "Digite uma palavra:");
  xyscanf(16, 26, palavra);
  xyprint(8, 32, palavra);
  xygoto(16, 26);

  for (int c = 0; c < strlen(palavra); c++) {
    if (palavra[c] != '\0') {
      qnt_letras++;
    }
  }

  while (finalizar == 1) {
    clear_screen();
    xywindow(2, 6, 14, 75, 1);
    xywindow(15, 6, 17, 75, 1);
    xyprint(3, 35, "Caça Letras");
    xyprint(12, 24, "                              ");
    xyprint(16, 7, "Digite uma letra:");
    xyprint(8, 32, palavra);
    // xygoto(0, 0);
    // printw("%d", qnt_acertos);
    // xygoto(1, 1);
    // printw("%d", qnt_letras);
    xygoto(16, 24);

    key = getch();
    getch();
    refresh();

    for (int c = 0; c < strlen(palavra); c++) {
      if ((int)palavra[c] == key) {
        palavra[c] = '*';
        xyprint(8, 35, "                              ");
        xyprint(8, 35, palavra);
        xyprint(12, 24, "                              ");
        xyprint(12, 24, "essa letra esta na palavra");
        xygoto(16, 24);
        qnt_acertos++;
        refresh();
      } else {
        xyprint(8, 35, "                              ");
        xyprint(8, 35, palavra);
        xyprint(12, 24, "                              ");
        xyprint(12, 24, "essa letra nao esta na palavra");
        xygoto(16, 24);
        refresh();
      }
    }
    if (qnt_acertos == qnt_letras) {
      xyprint(8, 35, "                              ");
      xyprint(8, 35, palavra);
      xyprint(12, 24, "                              ");
      xyprint(12, 24, "O jogo Acabou");
      finalizar = 0;
      refresh();
    }
    xygoto(16, 24);
    getch();
  }
  getch();
  end_screen();

  return 0;
}
