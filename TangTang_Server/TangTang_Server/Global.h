#pragma once
#pragma comment(lib, "ws2_32")

#define SERVERPORT 9000
#define BUFSIZE 1024

#include <WinSock2.h>
#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <Windows.h>
#include <tchar.h>


using namespace std;

enum E_type
{
	RECV_OVERLAPPED,
	SEND_OVERLAPPED
};




class WSAOVERLAPPED_EX
{
public:
	WSAOVERLAPPED m_overlapped;
	void* m_ptr;
	E_type m_type;
};
