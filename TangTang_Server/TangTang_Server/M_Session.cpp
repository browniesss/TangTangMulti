#include "M_Session.h"

Session* M_Session::AddClientInfo(SOCKET p_socket)
{
	Session* ptr = new Session;

	ptr->Set_socket(p_socket);
	ptr->Get_peername();

	// list 추가
	list_client.push_back(ptr);

	return ptr;
}

void M_Session::RemoveClientInfo(Session* p_client)
{

	// list 만들거나 find 함수 만들기
	list_client.remove(p_client);

}