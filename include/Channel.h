#ifndef CHANNEL
#define CHANNEL

#include <string>
#include <Message.h>

using std::string;

/**
 * @brief Classe que representa um canal.
 */
class Channel {

protected:
    string name; /**< Nome do canal. */

public:
    /**
     * @brief Construtor padrão da classe Channel.
     */
    Channel();

    /**
     * @brief Construtor da classe Channel que recebe o nome do canal como parâmetro.
     * @param name Nome do canal.
     */
    Channel(string name);

    /**
     * @brief Destrutor da classe Channel.
     */
    virtual ~Channel();

    /**
     * @brief Obtém o nome do canal.
     * @return Nome do canal.
     */
    string getName();

    /**
     * @brief Define o nome do canal.
     * @param name Nome do canal.
     */
    void setName(string name);

    /**
     * @brief Adiciona uma mensagem ao canal.
     * @param message Mensagem a ser adicionada.
     */
    virtual void addMessage(Message message);
};

#endif
