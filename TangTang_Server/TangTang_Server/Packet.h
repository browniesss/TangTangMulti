#pragma once
#include "Global.h"
#include "Socket.h"
#include <queue>

class Packet : public Socket
{
protected:
	queue<char*> m_recvq;
	int m_size;

};

