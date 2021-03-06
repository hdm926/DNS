#include <stdio.h>
#include <winsock2.h>

#pragma comment(lib, "ws2_32.lib")

int main(int argc, char* argv[])
{
    WORD socketVersion = MAKEWORD(2,2);
    WSADATA wsaData;
    if(WSAStartup(socketVersion, &wsaData) != 0)//服务初始化
    {
        return 0;
    }
    SOCKET sclient = socket(AF_INET, SOCK_DGRAM, IPPROTO_UDP);

    struct sockaddr_in sin;
    sin.sin_family = AF_INET;
    sin.sin_port = htons(8888);
    sin.sin_addr.S_un.S_addr = inet_addr("127.0.0.1");
    int len = sizeof(sin);

    char * sendData = "A DATAGRAM FROM CLIENT.\n";

    sendto(sclient, sendData, strlen(sendData), 0, (SOCKADDR*)&sin, len);
    char recvData[255];
    int ret = recvfrom(sclient, recvData, 255, 0, (SOCKADDR*)&sin, &len);
    if(ret > 0)
    {
        recvData[ret] = 0x00;
        printf(recvData);
    }

    closesocket(sclient);
    WSACleanup();

    return 0;
}