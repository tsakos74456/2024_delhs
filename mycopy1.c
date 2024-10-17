#include<stdio.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>

void mycopy(char *source_file, char* dest_file){
    int fp_a, fp_b; 
    fp_a = open(source_file, O_RDONLY);
    fp_b = open(dest_file,O_WRONLY | O_CREAT,0644);

    // various sanity checks
    if(fp_a < 0){
        printf("The source file doen't exist!");
        return;
    }
    if(fp_b < 0){
        printf("Error with the destination file!");
        return;
    }
    char buffer[1024];
    ssize_t curr;
    while((curr = read(fp_a,buffer, sizeof(buffer))) > 0){
        write(fp_b, buffer, curr);
    }
    write(fp_b, buffer, curr);
    close(fp_a); 
    close(fp_b);

    
return;
}

// u give in the commmand line the source and the dest file with this order
int main(int argc, char *argv[]){
    if (argc != 3){
        printf("Inavlid input");
        return -1;
    }
    char *si = argv[1];
    char *sis = argv[2]; 
    mycopy(si, sis);
    return 0;
}