#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Função responsável por listar os agendamentos

void listar(char semana[15]) {

  char listagem[150];
  FILE *pont_file;

  pont_file = fopen(semana, "r");

  printf("\n\n");

  while (fgets(listagem, 150, pont_file) != NULL) {

    printf("\t\t─────────────────────────────────────────────────────────────────────────────────────\n");
    printf("                                           %s", listagem);
    printf("\t\t─────────────────────────────────────────────────────────────────────────────────────\n");
  }

  fclose(pont_file);

  printf("\n");

  return;
}

// Função responsável por adicionar os agendamentos

void adicionar(char semana[15]) {

  char agendamento[150], caractere;
  int count = 5;
  FILE *pont_file;

  printf("\n\nHorário (obs: o formato da hora é 00:00)\n\n");
  scanf("%s", &agendamento[0]);
  printf("\nDescrição (obs: colocar ponto no final da frase)\n\n");

  // While que ler a descrição que o usuário digitou para o agendamento

  while (caractere != '.') {

    scanf("%c", &caractere);

    agendamento[count] = caractere;

    count++;
  }

  // Colocando o \0 no lugar do ponto indicando o final da string

  agendamento[count - 1] = '\0';

  // Substituindo o \n por um espaço vazio

  agendamento[5] = ' ';

  pont_file = fopen(semana, "a");

  fprintf(pont_file, "%s\n", agendamento);

  fclose(pont_file);

  return;
}

// Função responsável por editar os agendamentos

void editar(char semana[15]){
  
  char excluir[150], comparacao[150], editar[150], caractere;
  int count;
  FILE *pont_file01;
  FILE *pont_file02;

  printf("\n\nHorário que você quer editar (obs: o formato da hora é 00:00)\n\n");
  
  scanf("%s", &excluir[0]);
  
  printf("\n\nDescrição que você quer editar (obs: colocar um ponto no final da frase)\n\n");

  // For que ler a descrição que o usuário digitou para o agendamento

  for (count = 5; caractere != '.'; count++) {

    scanf("%c", &caractere);

    excluir[count] = caractere;
  }

  // Colocando o \0 no lugar do ponto indicando o final da string

  excluir[count - 1] = '\0';

  // Substituindo o \n por um espaço vazio

  excluir[5] = ' ';

  // Zerando a variável caractere 
  
  caractere ='a';

  printf("\n\nQual é o novo horário (obs: o formato da hora é 00:00)\n\n");
  
  scanf("%s", &editar[0]);
  
  printf("\n\nQual é a nova descrição (obs: colocar um ponto no final da frase)\n\n");

  // For que ler a descrição que o usuário digitou para o agendamento

  for (count = 5; caractere != '.'; count++) {

        scanf("%c", &caractere);

        editar[count] = caractere;
  }

  // Colocando o \0 no lugar do ponto indicando o final da string

  editar[count - 1] = '\0';

  // Substituindo o \n por um espaço vazio

  editar[5] = ' ';

  // Abrindo os arquivos necessários para a operação do while 

  pont_file01 = fopen(semana, "r");
  pont_file02 = fopen("temp.txt", "a");

  // While que transfere os dados do arquivo semana para o arquivo temp.txt sem o agendamento que o usuário quer excluir 

  while (fgets(comparacao, 150, pont_file01) != NULL) {

    if(strcmp(excluir, comparacao) != -10){
      
       fprintf(pont_file02, "%s", comparacao);
      
    }else{

       fprintf(pont_file02, "%s\n", editar);
       
    }
    
  }

  // Fechando os arquivos
  
  fclose(pont_file01);
  fclose(pont_file02);
  
  // Excluindo o arquivo semana
  
  remove(semana);

  // Abrindo os arquivos necessários para a operação do while 

  pont_file01 = fopen(semana, "a");
  pont_file02 = fopen("temp.txt", "r");

  // While que transfere os dados do arquivo temp.txt para o arquivo semana sem o agendamento que o usuário queria excluir 

  while (fgets(comparacao, 150, pont_file02) != NULL) {

         fprintf(pont_file01, "%s", comparacao);    
    
  }

  // Fechando os arquivos

  fclose(pont_file01);
  fclose(pont_file02);

  // Excluindo o temp.txt

  remove("temp.txt");
   
}

// Função responsável por excluir os agendamentos

void excluir(char semana[15]) {

  char excluir[150], comparacao[150], caractere;
  int count;
  FILE *pont_file01;
  FILE *pont_file02;

  printf("\n\nHorário (obs: o formato da hora é 00:00)\n\n");
  
  scanf("%s", &excluir[0]);
  
  printf("\n\nDescrição (obs: colocar ponto no final da frase)\n\n");

  // For que ler a descrição que o usuário digitou para o agendamento

  for (count = 5; caractere != '.'; count++) {

    scanf("%c", &caractere);

    excluir[count] = caractere;
  }

  // Colocando o \0 no lugar do ponto indicando o final da string

  excluir[count - 1] = '\0';

  // Substituindo o \n por um espaço vazio

  excluir[5] = ' ';

  // Abrindo os arquivos necessários para a operação do while 

  pont_file01 = fopen(semana, "r");
  pont_file02 = fopen("temp.txt", "a");

  // While que transfere os dados do arquivo semana para o arquivo temp.txt sem o agendamento que o usuário quer excluir 

  while (fgets(comparacao, 150, pont_file01) != NULL) {

    if(strcmp(excluir, comparacao) != -10){
      
       fprintf(pont_file02, "%s", comparacao);
      
    }
    
  }

  // Fechando os arquivos
  
  fclose(pont_file01);
  fclose(pont_file02);
  
  // Excluindo o arquivo semana
  
  remove(semana);

  // Abrindo os arquivos necessários para a operação do while 

  pont_file01 = fopen(semana, "a");
  pont_file02 = fopen("temp.txt", "r");

  // While que transfere os dados do arquivo temp.txt para o arquivo semana sem o agendamento que o usuário queria excluir 

  while (fgets(comparacao, 150, pont_file02) != NULL) {

         fprintf(pont_file01, "%s", comparacao);    
    
  }

  // Fechando os arquivos

  fclose(pont_file01);
  fclose(pont_file02);

  // Excluindo o temp.txt

  remove("temp.txt");
  
}

// Função que printa os comandos dos dias da semana

void printsemana(void) {

  printf("\n\nQual é o dia da semana?\n\n");
  printf("|1|-> Segunda |2|-> Terça |3|-> Quarta |4|-> Quinta |5|-> Sexta "
         "|6|-> Sábado |7|-> Domingo\n\n\n");

  return;
}

int main() {

  char diasemana[15];
  int comando01, comando02;
  FILE *pont_file;

  while (comando01 != 0) {

    //  Função para limpar o console

    if(comando01 ==-1){
      
      system("clear");
    
    }

    printf("\n\n        \t\t\t\t\t\t\t╔════════════════════════════╗\n");
    printf("        \t\t\t\t\t\t\t║      Agenda da Semana      ║\n");
    printf("        \t\t\t\t\t\t\t╚════════════════════════════╝\n\n\n");
    printf("|1|-> Listar Agenda |2|-> Adicionar Agenda |3|-> Editar Agenda |4|-> Excluir Agenda |-1|-> Limpar |0|-> Sair\n\n");

    scanf("%d", &comando01);

    // If que chama a função listar

    if (comando01 == 1) {
      
        printsemana();

        scanf("%d", &comando02);

        // Switch case que chama a função listar conforme o número do dia da
        // semana que foi digitado

        switch (comando02) {

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

    // If que chama a função adicionar
    
    if (comando01 == 2) {

         printsemana();

         scanf("%d", &comando02);

         // Switch case que chama a função adicionar conforme o número do dia da
         // semana que foi digitado

         switch (comando02) {

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

    // If que chama a função editar

    if (comando01 == 3) {

         printsemana();

         scanf("%d", &comando02);

         // Switch case que chama a função adicionar conforme o número do dia da
         // semana que foi digitado

         switch (comando02) {

         case 1:
           editar("segunda.txt");
           break;

         case 2:
           editar("terça.txt");
           break;

         case 3:
           editar("quarta.txt");
           break;

         case 4:
           editar("quinta.txt");
           break;

         case 5:
           editar("sexta.txt");
           break;

         case 6:
           editar("sábado.txt");
           break;

         case 7:
           editar("domingo.txt");
           break;

      }
    }

    // If que chama a função excluir
    
    if (comando01 == 4) {

         printsemana();

         scanf("%d", &comando02);

         // Switch case que chama a função excluir conforme o número do dia da
         // semana que foi digitado

         switch (comando02) {

         case 1:
           excluir("segunda.txt");
           break;

         case 2:
           excluir("terça.txt");
           break;

         case 3:
           excluir("quarta.txt");
           break;

         case 4:
           excluir("quinta.txt");
           break;

         case 5:
           excluir("sexta.txt");
           break;

         case 6:
           excluir("sábado.txt");
           break;

         case 7:
           excluir("domingo.txt");
           break;
      }
    }
  }
  
  return 0;
}
