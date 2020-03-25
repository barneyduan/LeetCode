// Practice make perfect :)
// Duan Lian

#include <arpa/inet.h>
#include <cstring>
#include <iostream>
#include <string>

using namespace std;

int main() {
  string l1 = "192.168.99.20";
  auto r1 = inet_addr(l1.c_str());  // network order

  struct sockaddr_in ip_addr;
  inet_aton(l1.c_str(), &ip_addr.sin_addr);

  auto r2 = ntohl(ip_addr.sin_addr.s_addr); // network -> host

  in_addr test_addr;
  test_addr.s_addr = r2;
  auto r3 = inet_ntoa(test_addr);

  cout << r1 << endl;  // 342075584
  cout << r2 << endl;  // 3232260884
  cout << r3 << endl;  // 20.99.168.192
}

/*
 * htonl()  --- Host to Network long
 * ntohl()  --- Network to Host long
 * htons()  --- Host to Network short
 * ntohs()  --- Network to Host short
 *
 * Ipv4:
 * ip string -> network order stream
 * inet_addr, inet_network, inet_aton
 */
