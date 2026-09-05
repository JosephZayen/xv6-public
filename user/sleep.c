#include "kernel/types.h"
#include "user/user.h"

int main(int argc, char *argv[]){
    if(argc < 1){
        exit(1);
    }
    int ticks = atoi(argv[1]);
    printf("sleep %d", ticks);
    sleep(ticks);
    exit(0);
}
