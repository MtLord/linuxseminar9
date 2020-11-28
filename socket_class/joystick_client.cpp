#include "TcpLib.hpp"
#include <stdio.h>
#include <vector>
#include <unistd.h>
#include <iostream>
int nSend = 0;
using namespace std;
int16_t con_data[23] = {
    0,
};

//メインのプログラムをクライアントにしたほうがいい
int main(int argc, char **argv)
{
    vector<char> ReadData;
    TcpClient client;               //TCPクライアント用オブジェクトの作成
    string LOCALHOST = "127.0.0.1"; //ローカルホストのIPアドレス
    int PORT = 50001;               //ポート番号

    client.Init(LOCALHOST, PORT);
    while (1)
    {
        nSend = client.Read(ReadData); //受信

        ((char *)&con_data[17])[0] = ReadData[17];
        ((char *)&con_data[17])[1] = ReadData[18];
        ((char *)&con_data[18])[0] = ReadData[19];
        ((char *)&con_data[18])[1] = ReadData[20];
        ((char *)&con_data[19])[0] = ReadData[21];
        ((char *)&con_data[19])[1] = ReadData[22];
        ((char *)&con_data[20])[0] = ReadData[23];
        ((char *)&con_data[20])[1] = ReadData[24];
        ((char *)&con_data[21])[0] = ReadData[25];
        ((char *)&con_data[21])[1] = ReadData[26];
        ((char *)&con_data[22])[0] = ReadData[27];
        ((char *)&con_data[22])[1] = ReadData[28];
        for (int i = 0; i < 17; i++)
        {
            printf("%d ", (int)ReadData[i]);
        }
        printf("%d %d %d %d %d %d", con_data[17], con_data[18], con_data[19], con_data[20], con_data[21], con_data[22]);
        printf("\n");
        //cout << endl;
    }

    // vector<char> SendData;
    // SendData.push_back(0x01);        //0x01というデータを送る
    // int nWrite = client.Write(data); //送信
    return 0;
}
