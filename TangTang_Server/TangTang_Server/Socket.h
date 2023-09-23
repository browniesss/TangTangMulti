#pragma once
#include "Global.h"

class Socket
{
protected:
	WSAOVERLAPPED_EX r_overlapped;
	WSAOVERLAPPED_EX s_overlapped;

	SOCKET m_socket;
	SOCKADDR_IN m_addr;

public:
	Socket();	//���� ������


	bool Create_socket();				//1. ���� ����
	bool Bind_socket(int p_port);		//2. ���ϰ� ��Ʈ��ȣ ����
	bool Listen_socket();				//3. ���������� ���� Ŭ���̾�Ʈ�� ���� ��û�� �޾Ƶ��� �غ� ���Ŵ�� ����
	SOCKET Accept_socket();				//4. ���������� ���� ��û��ȣ�� �������� ��� ť�� ���ν��Ѽ� ����ó���� ��.


	//Socket���� Send, Recv�� ����Ѵ�.
	bool Send_socket(char* p_buf, int p_size);
	bool Recv_socket(char* p_buf, int p_size);

	//Session�Ŵ������� ����� ���� ����� �ּҺ���
	int Get_peername();
	void Set_socket(SOCKET p_socket) { this->m_socket = p_socket; };
};

