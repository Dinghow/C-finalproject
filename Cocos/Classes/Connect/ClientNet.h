#ifndef _CLIENTNET_H_
#define _CLIENTNET_H_

#include<windows.h> 

class ClientNet
{
private:
	SOCKET m_sock;

public:
	// ����ָ���ķ�����  
	int ClientConnect(int port, const char* address);
	// ������Ϣ  
	int ClientSend(const char* msg, int len);
	// �ر�����  
	void ClientClose();
};

#endif // _CLIENTNET_H_