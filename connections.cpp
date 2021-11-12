//#undef UNICODE
//
//#define WIN32_LEAN_AND_MEAN
//
//#include <windows.h>
//#include <winsock2.h>
//#include <ws2tcpip.h>
//#include <stdlib.h>
//#include <stdio.h>
//#include <iostream>
//#include "Http.cpp"
//#include "thread"
//// Need to link with Ws2_32.lib
//#pragma comment (lib, "Ws2_32.lib")
//// #pragma comment (lib, "Mswsock.lib")
//
//#define DEFAULT_BUFLEN 1024
//#define DEFAULT_PORT "80"
//using namespace std;
//class connections{
//
//public:
//    void recieve_data(){
//
//    }
//    void operator()( SOCKET ClientSocket){
//        int iResult;
//        char recvbuf[DEFAULT_BUFLEN];
//        int recvbuflen = DEFAULT_BUFLEN;
//        DWORD timeout = 1*1000;
////        struct timeval timeout;
////        timeout.tv_sec = 60;
////        timeout.tv_usec = 0;
//        setsockopt(ClientSocket,SOL_SOCKET,SO_RCVTIMEO,(char *)&timeout,sizeof(timeout));
//
//        do {
//            cout << "before recv\n";
//            iResult = recv(ClientSocket, recvbuf, recvbuflen, 0);
//            cout << iResult << "== iresult\n";
//            if (iResult > 0) {
//                printf("Bytes received: %d\n", iResult);
//                string s(recvbuf, iResult);
//                Http http(s);
//                string ss = http.message;
//                char sd[ss.size()];
//                for (int i = 0; i < ss.size(); i++)sd[i] = ss[i];
//                // Echo the buffer back to the sender
//                int iSendResult = send(ClientSocket, sd, ss.size(), 0);
//                if (iSendResult == SOCKET_ERROR) {
//                    printf("send failed with error: %d\n", WSAGetLastError());
//                    closesocket(ClientSocket);
//                    WSACleanup();
////                return 1;
//                }
//                printf("Bytes sent: %d\n", iSendResult);
//            } else if (iResult == 0)
//                printf("Connection closing...\n");
//            else {
//                printf("recv failed with error: %d\n", WSAGetLastError());
//            }
//        }while (iResult >0);
//        cout << iResult;
//        cout << " shutting down connection\n";
//
////     shutdown the connection since we're done
//        iResult = shutdown(ClientSocket, SD_SEND);
//        if (iResult == SOCKET_ERROR) {
//            printf("shutdown failed with error: %d\n", WSAGetLastError());
//            closesocket(ClientSocket);
//            WSACleanup();
////            return 1;
//        }
//    }
//
//
//
//
//
//
//};