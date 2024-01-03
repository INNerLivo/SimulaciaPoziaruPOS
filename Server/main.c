#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <strings.h>
#include <pthread.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>
#include "buffer.h"
#include "char_buffer.h"
#include "active_socket.h"
#include "passive_socket.h"

/*
 * Tu to na serveri budeme ukladať svety na server.
 *
 */

typedef struct ohen {
    double x;
    double y;
} OHEN;



int main(int argc, char* argv[]) {
    pthread_t th_produce;
    pthread_t th_receive;
    struct thread_data data;
    struct active_socket my_socket;

    active_socket_init(&my_socket);
    thread_data_init(&data, 100000, 10, 12345, &my_socket);

    pthread_create(&th_produce, NULL, produce, &data);
    pthread_create(&th_receive, NULL, process_client_data, &data);

    consume(&data);

    pthread_join(th_produce, NULL);
    pthread_join(th_receive, NULL);

    thread_data_destroy(&data);
    active_socket_destroy(&my_socket);

    return 0;
}
