#include <zmq.h>
#include <string.h>
#include <stdio.h>
#include <unistd.h>
#include "zhelpers.h"

#define PORT 6005
#define MAX 100

int main(void)
{
  void *context = zmq_ctx_new();
  void *subscriber = zmq_socket(context, ZMQ_PULL);
  zmq_connect(subscriber, "tcp://unixlab:6005");

  while (1)
  {
    //  Read message from the publisher
    char *message = s_recv(subscriber);
    printf("Message: %s\n", message);
    free(message);
  }

  //  We never get here, but clean up anyhow
  zmq_close(subscriber);
  zmq_ctx_destroy(context);
  return 0;
}