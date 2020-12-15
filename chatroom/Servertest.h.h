#ifndef SERVERTEST_H_INCLUDED
#define SERVERTEST_H_INCLUDED
#include <stdio.h>
#include <iostream>
#include <sys/epoll.h>
#include <sys/socket.h>
#include <stdlib.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <sys/ioctl.h>
#include <unistd.h>
#include <errno.h>
#include <fcntl.h>
#include <list>
#include <typeinfo>
#include <cstring>
#define SERVER_IP           "0.0.0.0"
#define SERVER_PORT      6666
#define EPOLL_SIZE          100
#define BUFF_SIZE            2048
#define LISTEN_NUM       10
class Servertest
{
public:
    int serverSocket;                       //������socket
    struct sockaddr_in serverAddr;
    struct epoll_event event;
    struct epoll_event events[EPOLL_SIZE];      //�¼���������
    std::list<int> clientSocket;               //�ͻ���socket
    struct sockaddr_in clientAddr;
    int epollFd;                                //epoll���
    char buf[BUFF_SIZE];                 //���ݻ���
    void serverRun();
    Servertest();
    ~Servertest();
};
#endif
