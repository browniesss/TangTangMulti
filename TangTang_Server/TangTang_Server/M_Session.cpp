#include "M_Session.h"

Session* M_Session::AddClientInfo(SOCKET p_socket)
{
	Session* ptr = new Session;

	ptr->Set_socket(p_socket);
	ptr->Get_peername();

	// list �߰�
	list_client.push_back(ptr);

	return ptr;
}

void M_Session::RemoveClientInfo(Session* p_client)
{

	// list ����ų� find �Լ� �����
	list_client.remove(p_client);

}