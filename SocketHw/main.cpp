#include <stdio.h>
#include <winsock.h>
#include <windows.h>
#include <thread>
#include <ctime>
using namespace std;

void Server(char[]); // Build server
void Client(char[]); // Connect to server

void Sender(SOCKET, char[]); // Both need a sender and receiver
void Receiver(SOCKET, char[]);

void SetTime();

// Some UI
void DisplayTitle(const char[], int);
void gotoxy(short, short);
void cls(char);

#define PRINTERROR(s)   \
		fprintf(stderr,"\n%s: %d\n", s, WSAGetLastError())

int main() {
	int n; char username[256] = {0};
	thread local;

	DisplayTitle("Pinkie Chat", 35);
	printf("Nickname: ");
	scanf("%s", username);
	cls(0);
	// Choose server or client
	printf("[0] Server\n[1] Client\n > ");
	scanf("%d", &n);

	cls(0);

	if (n) local = thread(Client, username);
	else local = thread(Server, username);

	local.join();

	return 0;
}

void Client(char name[]) {
	char szServer[256], servername[256] = {0}; int nPort;
	WORD wVersionRequested = MAKEWORD(1, 1);
	WSADATA wsaData;

	int nRet = WSAStartup(wVersionRequested, &wsaData);

	printf("Connect Server: ");
	scanf("%s", szServer);
	printf("Connect Port: ");
	scanf("%d", &nPort);
	printf("Connecting...");

	LPHOSTENT lpHostEntry;

	lpHostEntry = gethostbyname(szServer);
	if (lpHostEntry == NULL) {
		PRINTERROR("gethostbyname()");
		return;
	}

	SOCKET theSocket;
	theSocket = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP);
	if (theSocket == INVALID_SOCKET) {
		PRINTERROR("socket()");
		return;
	}

	SOCKADDR_IN saServer;

	saServer.sin_family = AF_INET;
	saServer.sin_addr = *((LPIN_ADDR) * lpHostEntry->h_addr_list);
	saServer.sin_port = htons(nPort);

	nRet = connect(theSocket, (LPSOCKADDR)&saServer, sizeof(struct sockaddr));
	if (nRet == SOCKET_ERROR) {
		PRINTERROR("socket()");
		closesocket(theSocket);
		return;
	}

	send(theSocket, name, strlen(name), 0);
	recv(theSocket, servername, sizeof(servername), 0);
	cls(0);
	printf("You are chatting with %s\n", servername);

	thread S(Sender, theSocket, name), R(Receiver, theSocket, servername);
	S.join(); R.join();
	closesocket(theSocket);
	WSACleanup();
	return;
}

void Server(char name[]) {
	int nPort; char clientname[256] = {0};

	printf("Port: ");
	scanf("%d", &nPort);
	printf("Wait for client...");

	WORD wVersionRequested = MAKEWORD(1, 1);
	WSADATA wsaData;
	int nRet = WSAStartup(wVersionRequested, &wsaData);
	if (wsaData.wVersion != wVersionRequested) {
		fprintf(stderr, "\n Wrong version\n");
		return;
	}

	SOCKET	listenSocket;

	listenSocket = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP);
	if (listenSocket == INVALID_SOCKET) {
		PRINTERROR("socket()");
		return;
	}

	SOCKADDR_IN saServer;

	saServer.sin_family = AF_INET;
	saServer.sin_addr.s_addr = INADDR_ANY;
	saServer.sin_port = htons(nPort);

	nRet = bind(listenSocket, (LPSOCKADDR)&saServer, sizeof(struct sockaddr));
	if (nRet == SOCKET_ERROR) {
		PRINTERROR("bind()");
		closesocket(listenSocket);
		return;
	}

	char szBuf[256];

	nRet = gethostname(szBuf, sizeof(szBuf));
	if (nRet == SOCKET_ERROR) {
		PRINTERROR("gethostname()");
		closesocket(listenSocket);
		return;
	}

	nRet = listen(listenSocket, SOMAXCONN);
	if (nRet == SOCKET_ERROR) {
		PRINTERROR("listen()");
		closesocket(listenSocket);
		return;
	}

	SOCKET	remoteSocket;

	remoteSocket = accept(listenSocket, NULL, NULL);
	if (remoteSocket == INVALID_SOCKET) {
		PRINTERROR("accept()");
		closesocket(listenSocket);
		return;
	}

	recv(remoteSocket, clientname, sizeof(clientname), 0);
	send(remoteSocket, name, strlen(name), 0);

	cls(0);

	printf("You are chatting with %s\n", clientname);

	thread S(Sender, remoteSocket, name), R(Receiver, remoteSocket, clientname);
	S.join(); R.join();

	closesocket(remoteSocket);
	closesocket(listenSocket);
	WSACleanup();

	return;
}

void Sender(SOCKET theSocket, char name[]) {
	do {
		char szBuf[256];
		getchar();
		scanf("%s", szBuf);
		if (szBuf[0] != 18) {
			SetTime();
			printf("%s: %s\n", name, szBuf);
			if (send(theSocket, szBuf, strlen(szBuf), 0) == SOCKET_ERROR)
				break;
		}
	} while(1);
}

void Receiver(SOCKET remoteSocket, char name[]) {
	do {
		char szBuf[256] = {0};
		if (recv(remoteSocket, szBuf, sizeof(szBuf), 0) == SOCKET_ERROR)
			break;
		SetTime();
		printf("%s: %s\n", name, szBuf);
	} while (1);
}

void SetTime() {
	time_t now = time(NULL);
	struct tm *t = gmtime(&now);
	printf("[%2d:%2d] ", t->tm_min, t->tm_sec);
}

void DisplayTitle(const char title[], int width) {
	for (int i = 0; i < width; i++)
		putchar('=');
	gotoxy((width - strlen(title)) / 2, 1);
	printf("%s\n", title);
	for (int i = 0; i < width; i++)
		putchar('=');
	putchar('\n');
}

void gotoxy(short x, short y) {
	HANDLE h = GetStdHandle(STD_OUTPUT_HANDLE);
	COORD c = {x, y};
	SetConsoleCursorPosition(h, c);
}

void cls(char all) {
	if (all) gotoxy(0, 0);
	else gotoxy(0, 3);
	for (int i = 0; i < 10; i++, putchar('\n'))
		for (int j = 0; j < 40; j++) putchar(' ');
	if (all) gotoxy(0, 0);
	else gotoxy(0, 3);
}
