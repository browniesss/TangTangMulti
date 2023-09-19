#include "Socket.h"

Socket::Socket()
{
	ZeroMemory(&r_overlapped, sizeof(WSAOVERLAPPED_EX));
	ZeroMemory(&s_overlapped, sizeof(WSAOVERLAPPED_EX));
	ZeroMemory(&m_socket, sizeof(SOCKET));
	ZeroMemory(&m_addr, sizeof(SOCKADDR_IN));

	r_overlapped.m_ptr = this;
	r_overlapped.m_type = RECV_OVERLAPPED;

	s_overlapped.m_ptr = this;
	s_overlapped.m_type = SEND_OVERLAPPED;
}

bool Socket::Create_socket()
{
	m_socket = socket(AF_INET, SOCK_STREAM, 0);
	if (m_socket == INVALID_SOCKET)
	{
		return false;
	}

	return true;
}

bool Socket::Bind_socket(int p_port)
{
	int retval;

	ZeroMemory(&m_addr, sizeof(m_addr));
	m_addr.sin_family = AF_INET;
	m_addr.sin_addr.s_addr = htonl(INADDR_ANY);
	m_addr.sin_port = htons(p_port);
	retval = bind(m_socket, (SOCKADDR*)&m_addr, sizeof(m_addr));
	if (retval == SOCKET_ERROR)
	{
		return false;
	}

	return true;
}

bool Socket::Listen_socket()
{
	int retval;

	retval = listen(m_socket, SOMAXCONN);
	if (retval == SOCKET_ERROR)
	{
		return false;
	}

	return true;
}

SOCKET Socket::Accept_socket()
{
	int addrlen;

	//Socket m_sock;
	addrlen = sizeof(m_addr);

	SOCKET cl_sock;
	SOCKADDR_IN clientaddr;

	cl_sock = accept(this->m_socket, (SOCKADDR*)&clientaddr, &addrlen);
	if (cl_sock == INVALID_SOCKET)
	{
		printf("����\n");
		return cl_sock;
	}

	return cl_sock;
}