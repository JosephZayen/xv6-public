#include "kernel/types.h"
#include "user/user.h"

int main(int argc, char *argv[]){
    int ping[2];
    int pong[2];
    pipe(ping);
    pipe(pong);
    int pid = fork();
    if(pid != 0){
        char ping_send = 'h';
        char pong_recv;
        write(ping[1], &ping_send, 1);
        close(ping[1]);
        close(ping[0]);
        wait(0);
        read(pong[0], &pong_recv, 1);
        printf("%d: received pong", getpid())
    }else{
        char ping_recv;
        char pong_send = 'i';
        read(ping[0], &ping_recv, 1);
        printf("%d: received ping", getpid());
        write(pong[1], &pong_send, 1);
        close(pong[0]);
        close(pong[1]);
    }
    exit(0);
}