#include<stdio.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>

void mycopy(char *source_file, char* dest_file){
    int fp_a, fp_b; 
    fp_a = open(source_file, O_RDONLY);
    fp_b = open(dest_file,O_WRONLY | O_CREAT,0644);

    if(fp_a < 0){
        printf("problem");
        return;
    }
    char buffer[1024];
    float curr;
    while((curr = read(fp_a,buffer, sizeof(buffer))) > 0){
        if (write(fp_b, buffer, curr) != curr) { // Corrected to use curr instead of sizeof(char)
            perror("Error writing to destination file");
            close(fp_a);
            close(fp_b);
            return;
        }
    }
    close(fp_a); 
    close(fp_b);

    
return;
}

int main(){
    char *si = "cap.txt";
    char *sis = "kap2.txt"; 
    mycopy(si, sis);
    return 0;
}