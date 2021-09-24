#include <stdio.h>
#include <string.h>
#include <time.h>
#include <stdlib.h>

int main(void)
{
    FILE *file;

    double temperatura = 0;
    double umidade = 0;
    double temperaturaMaior = 0;
    double umidadeMaior = 0;
    double temperaturaMenor = 1000000;
    double umidadeMenor = 1000000;

    char dataTemperaturaMaior[1000] = "";
    char dataTemperaturaMenor[1000] = "";
    char dataUmidadeMaior[1000] = "";
    char dataUmidadeMenor[1000] = "";

    char leitura[1000] = "";
    char l[10] = "";

    char c;
    int n = 0;
    int i = 0;
    
    file = fopen("prog.csv", "r");
    if (file == NULL) {
        printf("Erro ao abrir o arquivo\n");
        return 1;
    }

    //fgets(leitura, 120, file);
    char delim[] = ",";
    c = fgetc(file);
    while (c != EOF) {
        i++;
        if(c == '\n'){
            n++;
            printf("%s\n", leitura);

            char *ptr = strtok(leitura, delim);

            char data[1000] = ""; 
            int contador = 0;

            while(ptr != NULL)
            {
              if(contador == 0){
                strcpy(data, ptr);
              }
              
              if(contador == 1){
                temperatura = atof(ptr);
           
                if(temperatura > temperaturaMaior) {
                    temperaturaMaior = temperatura;
                    strcpy(dataTemperaturaMaior, data);
                }
        
                if(temperatura < temperaturaMenor) {
                    temperaturaMenor = temperatura;
                    strcpy(dataTemperaturaMenor, data);
                }
              }
                            
              if(contador == 2){
                umidade = atof(ptr);
                
                if(umidade > umidadeMaior) {
                  umidadeMaior = umidade;
                  strcpy(dataUmidadeMaior, data);
                }
    
                if(umidade < umidadeMenor) {
                    umidadeMenor = umidade;
                    strcpy(dataUmidadeMenor, data);
                }
              }
            
                          //printf("%s\n", ptr);

              ptr = strtok(NULL, delim);

              contador++;
            }

            memset(leitura, 0, 255);
        }

        l[0]= c;
        strcat(leitura, l);

        c = fgetc(file);
    }
    

    
    printf("\nExistem %d lançamentos\n\n", n);

    printf("\n %f temperaturaMaior -- %s", temperaturaMaior, dataTemperaturaMaior);
    printf("\n %f temperaturaMenor -- %s", temperaturaMenor, dataTemperaturaMenor);
    
    printf("\n %f umidadeMaior -- %s", umidadeMaior, dataUmidadeMaior);
    printf("\n %f umidadeMenor -- %s", umidadeMenor, dataUmidadeMenor);
    
    fclose(file);

    return 0;
}
