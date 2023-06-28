#ifndef SERVER
#define SERVER

#include <string>
#include <vector>
#include <set>
#include <Channel.h>

using std::string;
using std::vector;
using std::set;

/**
 * @class Server
 * @brief Representa um servidor em um aplicativo de chat.
 */
class Server{

private:
    int ownerUserId; /**< O ID do usuário que é proprietário do servidor. */
    string name; /**< O nome do servidor. */
    string description; /**< A descrição do servidor. */
    string invitationCode; /**< O código de convite do servidor. */

    vector<Channel *> channels; /**< Os canais do servidor. */
    vector<int> participantsIDs; /**< Os IDs dos participantes no servidor. */

public:
    /**
     * @brief Construtor padrão para Server.
     */
    Server();

    /**
     * @brief Construtor para Server com proprietário e nome.
     * @param ownerUserId O ID do usuário que é proprietário do servidor.
     * @param name O nome do servidor.
     */
    Server(int ownerUserId, string name);

    /**
     * @brief Construtor para Server com proprietário, nome, descrição e código de convite.
     * @param ownerUserId O ID do usuário que é proprietário do servidor.
     * @param name O nome do servidor.
     * @param description A descrição do servidor.
     * @param invitationCode O código de convite do servidor.
     */
    Server(int ownerUserId, string name, string description, string invitationCode);

    /**
     * @brief Destrutor para Server.
     * Deleta todos os objetos de canal pertencentes ao servidor.
     */
    ~Server();

    /**
     * @brief Obtém o ID do proprietário do servidor.
     * @return O ID do proprietário do servidor.
     */
    int getOwnerUserId();

    /**
     * @brief Obtém o nome do servidor.
     * @return O nome do servidor.
     */
    string getName();

    /**
     * @brief Define o nome do servidor.
     * @param name O nome do servidor.
     */
    void setName(string name);

    /**
     * @brief Obtém a descrição do servidor.
     * @return A descrição do servidor.
     */
    string getDescription();

    /**
     * @brief Define a descrição do servidor.
     * @param description A descrição do servidor.
     */
    void setDescription(string description);

    /**
     * @brief Obtém o código de convite do servidor.
     * @return O código de convite do servidor.
     */
    string getInvitationCode();

    /**
     * @brief Define o código de convite do servidor.
     * @param invitationCode O código de convite do servidor.
     */
    void setInvitationCode(string invitationCode);

    /**
     * @brief Obtém os canais do servidor.
     * @return Um vetor de ponteiros para Channel representando os canais do servidor.
     */
    vector<Channel *> getChannels();

    /**
     * @brief Obtém os IDs dos participantes no servidor.
     * @return Um vetor de inteiros representando os IDs dos participantes no servidor.
     */
    vector<int> getParticipantsIDs();

    /**
     * @brief Verifica se o servidor possui um código de convite.
     * @return True se o servidor possuir um código de convite, false caso contrário.
     */
    bool hasInvitationCode();

    /**
     * @brief Adiciona um participante ao servidor.
     * @param id O ID do participante a ser adicionado.
     */
    void addParticipant(int id);

    /**
     * @brief Verifica se um usuário com o ID fornecido é um participante no servidor.
     * @param id O ID do usuário a ser verificado.
     * @return True se o usuário for um participante no servidor, false caso contrário.
     */
    bool containsUser(int id);
};

#endif