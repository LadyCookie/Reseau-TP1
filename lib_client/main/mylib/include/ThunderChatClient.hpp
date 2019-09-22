#include <string>
#include "Message.hpp"

#ifdef _WIN32

#define WIN32_LEAN_AND_MEAN
#define NOMINMAX
#include <WinSock2.h>
#include <WS2tcpip.h>

#else

#include <sys/socket.h>
#include <unistd.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <sys/types.h>
#include <netdb.h>
#include <errno.h>

using SOCKET = inet
#define SD_BOTH SHUT_RDWR
#define closesocket(s) close(s)

#endif

class ThunderChatClient{
    public:
    ThunderChatClient(std::string serverName,std::string playerId,int team);
    ~ThunderChatClient();
    bool Connect();
    void OnMessage(const Message& msg);
    void OnDisconnet();
    void SendToParty(const std::string& msg);
    void SendToTeam(const std::string& msg);

    private:
    std::string serverName;
    std::string playerId;
    int team;
    SOCKET sock;
};