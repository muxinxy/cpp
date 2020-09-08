#include <winsock2.h>
#include <winsock.h>
#include <iostream>
#include <stdio.h>
#include <sstream>
#include <time.h>
using namespace std;

#pragma comment(lib,"ws2_32.lib")
#pragma comment(lib,"ws2_32")


int scan(char *Ip, int StartPort, int EndPort);


int main(int argc, char **argv)
{
    int ret;


    if (argc != 4)
    {
        printf("Usage: %s \n", argv[0]);
        exit(1);
    }


    ret = scan(argv[1], atoi(argv[2]), atoi(argv[3]));


    if (ret)
        printf("Scan OK\n");


    return 0;
}


int scan(char *Ip, int StartPort, int EndPort)
{
    clock_t StartTime, EndTime;
    float CostTime;


    TIMEVAL TimeOut;
    FD_SET mask;


    WSADATA wsa;
    SOCKET s;
    struct sockaddr_in server;


    int CurrPort;
    int ret;
    unsigned long mode = 1;  //ioctlsocket函数的最后一个参数


    WSAStartup(MAKEWORD(2, 2), &wsa);


    TimeOut.tv_sec = 0;
    TimeOut.tv_usec = 50;  //超时为50ms


    FD_ZERO(&mask);


    server.sin_family = AF_INET;
    server.sin_addr.s_addr = inet_addr(Ip);


    StartTime = clock();
    for (CurrPort = StartPort; CurrPort <= EndPort; CurrPort++)
    {
        s = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP);
        FD_SET(s, &mask);
        ioctlsocket(s, FIONBIO, &mode);  //设置为非阻塞模式


        server.sin_port = htons(CurrPort);
        connect(s, (struct sockaddr *)&server, sizeof(server));


        ret = select(0, NULL, &mask, NULL, &TimeOut);  //查询可写入状态


        if (0 == ret || -1 == ret)
        {
            closesocket(s);
        }
        else
        {
            printf("%s:%d\n", Ip, CurrPort);
            closesocket(s);
        }
    }
    EndTime = clock();
    CostTime = (float)(EndTime - StartTime) / CLOCKS_PER_SEC;
    printf("Cost time:%f second\n", CostTime);


    WSACleanup();


    return 1;
}
