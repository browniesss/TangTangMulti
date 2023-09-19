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
};

