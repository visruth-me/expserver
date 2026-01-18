#include <arpa/inet.h>
#include <netdb.h>
#include <netinet/in.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <unistd.h>

#define PORT 8080
#define BUFF_SIZE 10000
#define MAX_ACCEPT_BACKLOG 5

int main() {
  int listen_sock_fd = socket(AF_INET, SOCK_STREAM, 0);


  int enable = 1;
  setsockopt(listen_sock_fd, SOL_SOCKET, SO_REUSEADDR, &enable, sizeof(int));


  struct sockaddr_in server_addr;

  server_addr.sin_family = AF_INET;
  server_addr.sin_addr.s_addr = htonl(INADDR_ANY);
  server_addr.sin_port = htons(PORT);

  bind(listen_sock_fd, (struct sockaddr *)&server_addr, sizeof(server_addr));

  listen(listen_sock_fd, MAX_ACCEPT_BACKLOG);
  printf("[INFO] Server listening on port %d\n", PORT);