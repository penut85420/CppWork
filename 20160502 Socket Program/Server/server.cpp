//
// Server.cpp
//
// Extremely simple, stream server example.
// Works in conjunction with Client.cpp.
//
// The program sets itself up as a server using the TCP
// protoocl. It waits for data from a client, displays
// the incoming data, sends a message back to the client
// and then exits.
//
// Compile and link with wsock32.lib
//
// Pass the port number that the server should bind() to
// on the command line. Any port number not already in use
// can be specified.
// Example: Server 2000

#include <stdio.h>
#include <winsock.h>   //socket程式所需的函式庫

// Function prototype
void StreamServer(short nPort);

// Helper macro for displaying errors
#define PRINTERROR(s)   \
		fprintf(stderr,"\n%: %d\n", s, WSAGetLastError())

int main(int argc, char **argv) {
	WORD wVersionRequested = MAKEWORD(1, 1);  //協定版本編號
	WSADATA wsaData;          //winsock的一種資料結構
	int nRet;
	short nPort = 2135;              //port number

	// Initialize WinSock and check version (winsock的初始化)
	nRet = WSAStartup(wVersionRequested, &wsaData);
	if (wsaData.wVersion != wVersionRequested) {
		fprintf(stderr, "\n Wrong version\n");
		return 0;
	}

	// Do the stuff a stream server does
	StreamServer(nPort); //建立一個server，函式內容在下面

	// Release WinSock
	WSACleanup();
	return 0;
}

void StreamServer(short nPort) {
	// Create a TCP/IP stream socket to "listen" with
	SOCKET	listenSocket;    //宣告一個socket變數

	// socket(Address_Family, Socket_Type, Protocol);
	// http://msdn.microsoft.com/en-us/library/windows/desktop/ms740506(v=vs.85).aspx
	listenSocket = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP);
	if (listenSocket == INVALID_SOCKET) {
		PRINTERROR("socket()");
		return;
	}

	// Fill in the address structure
	SOCKADDR_IN saServer;		// socket address的變數，此部分及其設定不需改變
	/*
	struct sockaddr_in
	{
	    short   sin_family;
	    u_short sin_port;
	    struct  in_addr sin_addr;
	    char    sin_zero[8];
	};
	    sin_family	用來說明socket所使用的定址模式，在此必須設為 AF_INET，表示internet domain的socket。
	    sin_port	用來表示TCP/IP的port umber，設定 sin_port 必需使用htons函數作位元排序的動作
	    sin_addr	是一個in_addr的結構變數，用來表示ip位址。

	AF_INET:    http://topic.csdn.net/t/20040803/10/3236925.html
	    就是指本地址為 TCP/IP 協議族的地址
	    #define   AF_UNIX                   1        //   local   to   host   (pipes,   portals)
	    #define   AF_INET                   2        //   internetwork:   UDP,   TCP,   etc.
	    #define   AF_IMPLINK                3        //   arpanet   imp   addresses
	    #define   AF_PUP                    4        //   pup   protocols:   e.g.   BSP
	    .......

	INADDR_ANY          (0.0.0.0)   表示任何可被定位的地址；

	htons		http://msdn.microsoft.com/en-us/library/windows/desktop/ms738557(v=vs.85).aspx
		The htons function converts a u_short from host to TCP/IP network byte order (which is big-endian).
	*/
	saServer.sin_family = AF_INET;
	saServer.sin_addr.s_addr = INADDR_ANY;	// Let WinSock supply address
	saServer.sin_port = htons(nPort);		// Use port from command line

	// bind the name to the socket
	int nRet;

	// 將IPv4 socket定址結構連結到所建立的socket，以後當有封包抵達網路介面時，Linux核心便會將這個封包導向到其連結的socket。
	// bind(Socket, Address, Size_Of_Address_Structure);
	// http://msdn.microsoft.com/en-us/library/windows/desktop/ms737550(v=vs.85).aspx
	nRet = bind(listenSocket, (LPSOCKADDR)&saServer, sizeof(struct sockaddr));
	if (nRet == SOCKET_ERROR) {  //檢查是否建立成功
		PRINTERROR("bind()");
		closesocket(listenSocket);
		return;
	}

	// This isn't normally done or required, but in this
	// example we're printing out where the server is waiting
	// so that you can connect the example client.
	int nLen = sizeof(SOCKADDR);
	char szBuf[256];

	nRet = gethostname(szBuf, sizeof(szBuf));  //取得本機名稱
	if (nRet == SOCKET_ERROR) {
		PRINTERROR("gethostname()");
		closesocket(listenSocket);
		return;
	}

	// Show the server name and port number
	printf("\nServer named %s waiting on port %d\n",    //印出成功建立的字串
		   szBuf, nPort);

	// Set the socket to listen
	printf("\nlisten()");
	// listen(Bound_Socket, Number_Of_Connection_Request_Queue);
	// http://msdn.microsoft.com/en-us/library/windows/desktop/ms739168(v=vs.85).aspx
	nRet = listen(listenSocket, SOMAXCONN);
	if (nRet == SOCKET_ERROR) {       //檢查是否有錯誤
		PRINTERROR("listen()");
		closesocket(listenSocket);
		return;
	}

	// Wait for an incoming request
	SOCKET	remoteSocket;       //建立一個新的socket，用來和另一端傳送資料
	// 一開始的socket只負責等待連線，需創另一個socket和client連線，負責傳送資料
	do {
		printf("\nBlocking at accept()");
		// 將新的socket接到listening socket，等待連線
		// accept(Listen_Socket, Optional);
		remoteSocket = accept(listenSocket, NULL, NULL);
		if (remoteSocket == INVALID_SOCKET) { //檢查是否有錯誤
			PRINTERROR("accept()");
			closesocket(listenSocket);
			return;
		}

		// We're connected to a client
		// New socket descriptor returned already
		// has clients address

		// Receive data from the client
		// 將 szBuf 初始化
		memset(szBuf, 0, sizeof(szBuf));
		// 接收對方的訊息，並把訊息存入buffer中
		// recv(Connected_Client, Receive_Buffer, Size_Of_Buffer, Flags);
		nRet = recv(remoteSocket, szBuf, sizeof(szBuf), 0);
		if (nRet == INVALID_SOCKET) {   //檢查是否有錯誤
			PRINTERROR("recv()");
			closesocket(listenSocket);
			closesocket(remoteSocket);
			return;
		}

		// Display received data
		printf("\nData received: %s", szBuf);      //將buffer的內容印出來

		// Send data back to the client
		// send(Connected_Socket, Send_Buffer, Size_Of_Buffer, Flags)
		strcpy(szBuf, "From the Server");       //將 "From the Server" 存入buffer
		nRet = send(remoteSocket, szBuf, strlen(szBuf), 0);
	} while (1);
	// Close BOTH sockets before exiting
	closesocket(remoteSocket);    //關閉remoteSocket
	closesocket(listenSocket);    //關閉listenSocket
	return;
}
