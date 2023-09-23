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
	Socket();	//소켓 실행자


	bool Create_socket();				//1. 소켓 세팅
	bool Bind_socket(int p_port);		//2. 소켓과 포트번호 결합
	bool Listen_socket();				//3. 서버소켓을 통해 클라이언트의 연결 요청을 받아들일 준비 수신대기 상태
	SOCKET Accept_socket();				//4. 실질적으로 받은 요청신호를 서버소켓 대기 큐에 매핑시켜서 연결처리를 함.


	//Socket에서 Send, Recv를 담당한다.
	bool Send_socket(char* p_buf, int p_size);
	bool Recv_socket(char* p_buf, int p_size);

	//Session매니저에서 사용할 소켓 복사및 주소복사
	int Get_peername();
	void Set_socket(SOCKET p_socket) { this->m_socket = p_socket; };
};

