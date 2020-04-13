// Practice make perfect :)
// Author: Duan Lian

#include <sys/types.h>
#include <sys/wait.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>

#include <cstring>
#include <iostream>
#include <cerrno>

using namespace std;

#define FIFO1 "/tmp/fifo1"
#define FIFO2 "/tmp/fifo2"
#define FILE_MODE (S_IRUSR | S_IWUSR | S_IRGRP | S_IWGRP)

void client(int, int);
void server(int, int);

int main() {
  int read_fd, write_fd;
  pid_t child;
  if ((mkfifo(FIFO1, FILE_MODE) < 0) && errno != EEXIST) {
    cout << "cant create fifo 1" << endl;
  }
  if ((mkfifo(FIFO2, FILE_MODE) < 0) && errno != EEXIST) {
    unlink(FIFO1);
    cout << "cant create fofo 2" << endl;
  }
  if ((child = fork()) == 0) {
    // child process
    read_fd = open(FIFO1, O_RDONLY, 0);
    write_fd = open(FIFO2, O_WRONLY, 0);

    server(read_fd, write_fd);
    exit(0);
  }
  // parent process
  // must keep this order
  write_fd = open(FIFO1, O_WRONLY, 0);
  read_fd = open(FIFO2, O_RDONLY, 0);
  client(read_fd, write_fd);
  waitpid(child, NULL, 0);
  close(read_fd);
  close(write_fd);
  unlink(FIFO1);
  unlink(FIFO2);
  exit(0);
}

