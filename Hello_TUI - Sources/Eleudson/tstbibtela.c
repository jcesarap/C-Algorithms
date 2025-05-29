/**
 * Programa base para uma biblioteca de interface texto com caracteres ASCII estendidos e
 * terminal baseado na biblioteca ncurses.
 *
 * Ref:
 * https://stackoverflow.com/questions/74615279/problem-with-printing-extended-ascii-using-ncurses
 *
 */

/*
   Subconjunto de caracteres gráficos da Tabela ASCII
   {"■","┌","┐","┘","└","─","│","╔","╗","╝","╚","═","║","█","█","█","█","█","█"}
*/

#include "bibtela.h"

/**
 * Main program.
 *
 * @return Return code to operating system.
 */
int main(void) {
  char key; // para ler tecla

  // configura dos caracteres do idioma configurado no sistema
  setlocale(LC_ALL, "");
  setlocale(LC_CTYPE, "");

  init_screen(25, 80);
  while (TRUE) {
    clear_screen();

    xywindow(10, 10, 20, 20, 1);
    xywindow(8, 8, 22, 22, 2);
    xywindow(0, 0, 24, 79, 3);
    xyprint(10, 15, "Hey");
    xygoto(24, 79);
    scanf("%c", &key);

    break;
  }
  end_screen();

  return 0;
}

