#pragma once
#include "Session.h"
#include "Singleton.h"


class M_Session : public Singleton<M_Session>
{
protected:
	list<Session*> list_client;
public:
	Session* AddClientInfo(SOCKET p_socket);
	void RemoveClientInfo(Session* p_client);
};
