// Practice make perfect :)
// Author: Duan Lian

#include <sys/types.h>
#include <sys/stat.h>
#include <sys/wait.h>
#include <unistd.h>
#include <fcntl.h>

#include <iostream>
#include <string>
#include <cstring>

using namespace std;

void client(int readfd, int writefd) {
  size_t len;
  ssize_t n;
  char buff[1024];

  // read pathname
  fgets(buff, 1024, stdin);
  len = strlen(buff);
  if (buff[len-1] == '\n') {
    // delete newline from fgets()
    len--;
  }
  // write pathname to IPC channel
  write(writefd, buff, len);

  // read from IPC, write to standard output
  while ((n = read(readfd, buff, 1024)) > 0) {
    write(STDOUT_FILENO, buff, n);
  }
}

void server(int readfd, int writefd) {
  ssize_t n;
  char buff[1024];
  int fd;
  if ((n = read(readfd, buff, 1024)) == 0) {
    cout << "end-of-file while reading pathname" << endl;
  }
  buff[n] = '\0';  // null terminate pathname
  if ((fd = open(buff, O_RDONLY)) < 0) {
    string res = "can't open file";
    n = res.size();
    write(writefd, res.c_str(), n);
  } else {
    while ((n = read(fd, buff, 1024)) > 0) {
      write(writefd, buff, n);
    }
    close(fd);
  }
}

int main(int argc, char **argv) {
  int pipe1[2], pipe2[2];
  pid_t child;
  // Create two pipes
  pipe(pipe1);
  pipe(pipe2);
  // father -> pipe1[1] --> pipe1[0] --> child
  // child -> pipe2[1] --> pipe2[0] --> father

  if ((child = fork()) == 0) {
    // child process as server
    close(pipe1[1]);
    close(pipe2[0]);

    server(pipe1[0], pipe2[1]);
    exit(0);
  }
  // father process
  close(pipe1[0]);
  close(pipe2[1]);

  client(pipe2[0], pipe1[1]);
  waitpid(child, NULL, 0);
  exit(0);
};
