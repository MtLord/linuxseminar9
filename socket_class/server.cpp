#include "TcpLib.hpp"
#include <stdio.h>
#include <vector>
#include <unistd.h>
int nWrite = 0;
int main(int argc, char *argv[])
{
    TcpServer server;  //TCPサーバ用オブジェクト
    int PORT = 50001;  //サーバのポート番号
    server.Init(PORT); //初期化

    std::vector<char> SendData;
    SendData.push_back(0x01);
    SendData.push_back(0x02);
    SendData.push_back(0x03);
    SendData.push_back(0x04);
    SendData.push_back(0x07);
    while (1)
    {
        nWrite = server.Write(SendData); //送信
        //sleep(1);
        usleep(10000);
    }

    return 0;
    //0x01というデータを送る
}