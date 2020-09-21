// Practice make perfect :)
// Duan Lian

#include <arpa/inet.h>
#include <cstring>
#include <iostream>
#include <string>

using namespace std;

int main() {
  string l1 = "127.0.0.1";
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

  in_addr res;
  inet_pton(AF_INET, l1.c_str(), &res);
  cout << res.s_addr << endl;  // 342075584
}

/*
 * htonl()  --- Host to Network long
 * ntohl()  --- Network to Host long
 * htons()  --- Host to Network short
 * ntohs()  --- Network to Host short
 *
 * Ipv4:
 * ip string -> network order stream
 * inet_addr(): ipv4 string -> binary data in network byte order
 * inet_network(): ipv4 string -> binary data in host byte order
 * inet_ntoa(): in_addr in network byte order -> ipv4 string
 * inet_aton(): ipv4 string -> sockaddr_in in network byte order
 * inet_pton(): ipv4 string -> in_addr size binary data in network byte order
 *              but inet_pton support ipv6 type, by inet_pton only accept
 *              dotted-decimal ipv4 string.
 *              whereas inet_aton and inet_addr allow the more general
 *              numbers-and-dots notation(hex, octal...)
 */
