#include <stdio.h>
#include <string.h>
#include <stdlib.h>


int main(int argc, char *argv[]){
    
    // check if the program is called correctly
    if (argc != 5){
        printf("The program isn't called correctly!\n");
        return -1;
    }

    if(strcmp(argv[1],"-i") || strcmp(argv[3],"-o")){
        printf(argv[1]," ",argv[3]);
        printf("ERROR!\n");
        return -1;
    }

    FILE *input, *output;
    input = fopen(argv[2],"r");
    output = fopen(argv[4],"w");

    // reading the instruction by the user
    printf("I wait for your instruction:\n");
    char cmd[32];
    int numbers[32]; 
    fgets(cmd,sizeof(cmd),stdin);
    char *token = strtok(cmd, " "); 

    // 12. e(xit)
    while(strncmp(cmd,"e",1)){
        // 1. i(nsert) Ni [Nj Nk ...]
        if(!strncmp(cmd,"i",1)){
            int count = 0;
            while ((token = strtok(NULL, " ")) != NULL) {   
                numbers[count] = atoi(token);
                count++;
            }
        }

        // 2. (i)n(sert2) Ni Nj sum date
        else if(!strcmp(token,"n")) {

        }
        
        // 3. d(elete) Ni [Nj Nk ...]
        else if(!strcmp(token,"d")) {
            int count = 0;
            while ((token = strtok(NULL, " ")) != NULL) {   
                numbers[count] = atoi(token);
                count++;
            }
        }  
    
        // 4. (de)l(ete2) Ni Nj
        else if(!strcmp(token,"l")) {

        }

        // 5. m(odify) Ni Nj sum sum1 date date1
        else if(!strcmp(token,"m")) {

        }

        // 6. f(ind) Ni
        else if(!strcmp(token,"f")) {

        }

        // 7. r(eceiving) Ni
        else if(!strcmp(token,"r")){

        }

        // 8. c(irclefind) Ni
        else if(!strcmp(token,"c")) {

        }

        // 9. fi(ndcircles) Ni k
        else if(!strcmp(token,"fi")) {

        }

        // 10. t(raceflow) Ni m
        else if(!strcmp(token,"t")) {

        }

        // 11. (c)o(nnected) Ni Nj
        else if(!strcmp(token,"o")) {

        }

        // read the new instruction
        fgets(cmd,sizeof(cmd),stdin);
        token = strtok(cmd, " ");  // Get the first token (the command)
    }

    fclose(input);
    fclose(output);
}