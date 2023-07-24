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

          printf("───────────────────────────────────────────────────────────────────────────────────\n");
          printf(" \t\t\t\t\t\t\t\t%s", listagem);
printf("───────────────────────────────────────────────────────────────────────────────────\n");
       
                    
   }

  fclose(pont_file);
                
  printf("\n");
  
return 0;  
} 

//Função responsável por adicionar agendamentos

char adicionar(char semana[15]){

  char agendamento[150], caractere;
  int count=5;
  FILE *pont_file;
  
  printf("\n\nHorário (obs: o formato da hora é 00:00)\n\n");
  scanf("%s", &agendamento[0]);
  printf("\n\nDescrição (obs:colocar ponto no final da frase)\n\n");

  //While que ler a descrição que o usuário digitou para o agendamento
  
  while(caractere != '.'){
    
         scanf("%c", &caractere);
    
         agendamento[count] = caractere;
    
         count++;
  }

  //Colocando o \0 no lugar do ponto indicando o final da string 
  
  agendamento[count-1] = '\0';

  //Substituindo o \n por um espaço vazio 
  
  agendamento[5] = ' ';

  pont_file = fopen(semana, "a");

  fprintf(pont_file, "%s\n", agendamento);

  fclose(pont_file);
                
return 0;  
} 

//Função que printa os comandos dos dias da semana

void printsemana(void){

   printf("\n\nQual é o dia da semana?\n\n\n");
   printf("|1|-> Segunda |2|-> Terça |3|-> Quarta |4|-> Quinta |5|-> Sexta |6|-> Sábado |7|-> Domingo\n\n");

  return;
}

int main() {

  char diasemana[15]; 
  int comando;
  FILE *pont_file;

  while(comando !=0){
    
         printf("\n\n                              ╔════════════════════════════╗\n");
         printf("                              ║      Agenda da Semana      ║\n");
         printf("                              ╚════════════════════════════╝\n\n\n");
         printf("|1|-> Listar Agenda |2|-> Adicionar Agenda |3|-> Editar Agenda |4|-> Excluir Agenda |0|-> Sair\n\n");

         scanf("%d", &comando);

         //If responsável por começar toda a parte de listar os agendamentos 
    
         if(comando==1){

              printsemana();

              scanf("%d", &comando);

              //Switch case que chama a função listar conforme o número do dia da semana que foi digitado

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
                
                case 6:
                        listar("sábado.txt");
                break;
                
                case 7:
                        listar("domingo.txt");
                break;

              }
         }

         if(comando==2){

              printsemana();

              scanf("%d", &comando);

              //Switch case que chama a função adicionar conforme o número do dia da semana que foi digitado

              switch(comando){

                case 1:
                        adicionar("segunda.txt");
                break;
                
                case 2:
                        adicionar("terça.txt");
                break;
                
                case 3:
                        adicionar("quarta.txt");
                break;
                
                case 4:
                        adicionar("quinta.txt");
                break;
                
                case 5:
                        adicionar("sexta.txt");
                break;
                
                case 6:
                        adicionar("sábado.txt");
                break;
                
                case 7:
                        adicionar("domingo.txt");
                break;

              } 
         }
  }
  
  return 0;
}




