/*
 * Este programa es de prueba para hacer procesos en segundo plano
 *
 * Modificado por: Sebastian Peñaranda Hurtado 
                   Miguel Ángel Ospina Hernández 
                   Natalia Riaños Horta

 * Fecha: 2022-06-07
*/

#include <stdio.h>
#include <assert.h>
#include <unistd.h>

int main(int argc, char *argv[]) {
  int rc = fork();
  assert(rc >= 0);
  if (rc == 0) {
    while (1) {
        sleep(9);
        printf("Soy el hijo\n");

    }
  } else {
    printf("Soy el padre\n");
  }
}