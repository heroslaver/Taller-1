/*
 * Este programa simula un shell
 *
 * Modificado por: Sebastian Peñaranda Hurtado 
                   Miguel Ángel Ospina Hernández 
                   Natalia Riaños Horta

 * Fecha: 2022-06-07
 */

#include <assert.h>
#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h> 
#include "leercadena.h" 

//Main

int main(int argc, char* argv[]) {

        //Variables

    	char command[256];
        char tarea[256];
    	char **comando;
        char **texto;
        char cadena[11];

    	while (1) {
            	printf("> ");

                //leer en teclado
            	leer_de_teclado(256, command);
                int number = 0;
                //llamada si se escribe "tareas"
                if (strcmp(command,"tareas") == 0) number=1;

                //llamada si se escribe "detener(numero)"
                if(command[0] == 'd' ){
                    if(command[1] =='e'){
                        if(command[2] == 't'){
                            if(command[3] == 'e'){
                                if(command[4] == 'n'){
                                    if(command[5] == 'e'){
                                        if(command[6] == 'r'){
                                            number=2;
                                            // el bucle for eliminan los parentesis de la palabra "detener(numero)"
                                            // para que la funcion de_cadena_a_vector(command)
                                            for(int i=0; i <= 30; i++){
                                                if(command[i] == 40){
                                                    command[i] = ' ';
                                                }
                                                if(command[i] == 41){
                                                    command[i] = ' ';
                                                }
                                            }
                                        }
                                    }
                                }
                            }
                        }
                    }
                }

                //llamada si se escribe "salir"
                if (strcmp(command,"salir") == 0) break;

                //Convierte la llamada en un array de cadenas
            	comando = de_cadena_a_vector(command);

                //se crea el fork()
            	int rc = fork();
            	assert(rc >= 0);
            	if (rc == 0){
                    //proceso hijo
                    if(number == 1 ){
                        execlp("ps","ps", NULL);
                    }else if(number == 2){
                        execlp("kill", "kill", "-9", comando[1], NULL);
                        printf("No se ha escrito bien el comando\n");
                    }else if (number == 0 ){
                        execvp(comando[0], comando);
                    }
                }else{
                    //proceso padre
                    wait(NULL);
                }
    	}
    	return 0;
} //final de la funcion.