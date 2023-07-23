#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//Função responsável por listar os agendamentos

char listar(char semana[15]){

  char listagem[150];
  FILE *pont_file;

  pont_file = fopen(semana, "r");

                  printf("\n\n");

                  while(fgets(listagem, 150, pont_file) != NULL){

                         printf("%s", listagem);
                    
                  }

                  fclose(pont_file);
                
                  printf("\n");
  
return 0;  
} 

int main() {

  char diasemana[15]; 
  int comando;
  FILE *pont_file;

  while(comando !=0){
    
         printf("\n\nAgenda da Semana \n\n\n");
         printf("|1|-> Listar Agenda |2|-> Adicionar Agenda |3|-> Editar Agenda |4|-> Excluir Agenda |0|-> Sair\n\n");

         scanf("%d", &comando);

         //if responsável por começar toda a parte de listar os agendamentos 
    
         if(comando==1){

              printf("\n\nQual dia da semana você quer ver ?\n\n\n");
              printf("|1|-> Segunda |2|-> Terça |3|-> Quarta |4|-> Quinta |5|-> Sexta |6|-> Sábado |7|-> Domingo\n\n");

              scanf("%d", &comando);

              //switch case que chama a função listar conforme o número do dia da semana que foi digitado

              switch(comando){

                case 1:
                        listar("segunda.txt");
                break;
                
                case 2:
                        listar("terça.txt");
                break;
                
                case 3:
                        listar("quarta.txt");
                break;
                
                case 4:
                        listar("quinta.txt");
                break;
                
                case 5:
                        listar("sexta.txt");
                break;
                
                case 7:
                        listar("sábado.txt");
                break;
                
                case 6:
                        listar("domingo.txt");
                break;

              }
         }
  }
  return 0;
}




