#include "cluedo.h"
#include <stdio.h>
#include <stdlib.h>

bool caso_resuelto;
int n_teoria, max_teorias;
int sospechoso, ubicacion, arma;

int Teoria(int c, int u, int a) {
  printf("Teoria #%d: %d %d %d.\n",
    n_teoria + 1, c, u, a);
  fflush(stdout);
  
  if (max_teorias <= n_teoria++) {
    puts("Excediste el numero maximo de teorias.");
    fclose(stdout); return 0;
  }
  if (sospechoso != c) {
    puts("El sospechoso es incorrecto.");
    fflush(stdout); return 1;
  }
  if (ubicacion != u) {
    puts("La ubicacion es incorrecta.");
    fflush(stdout); return 2;
  }
  if (arma != a) {
    puts("El arma es incorrecta.");
    fflush(stdout); return 3;
  }
  
  puts("La teoria es correcta!");
  caso_resuelto = true;
  fflush(stdout);
  return 0;
}

int main(){
  // Aqui puedes modificar el numero
  // maximo de teorias que tu funcion
  // puede hacer para resolver el caso.
  max_teorias = 10;

  scanf("%d%d%d", &sospechoso, &ubicacion, &arma);
  caso_resuelto = false;
  ResolverCaso();
  
  if (caso_resuelto)
    puts("Has resuelto el caso, detective! :)");
  else
    puts("El caso no ha sido resuelto :(");
  fclose(stdout);
  return 0;
}