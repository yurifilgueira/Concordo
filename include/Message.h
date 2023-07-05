#ifndef MESSAGE
#define MESSAGE

#include <string>

using std::string;

/**
 * @brief Classe que representa uma mensagem.
 */
class Message {
private:
    string dateHour; /**< Data e hora da mensagem. */
    int sentBy; /**< Remetente da mensagem. */
    string content; /**< Conteúdo da mensagem. */

public:
    /**
     * @brief Construtor padrão da classe Message.
     */
    Message();

    /**
     * @brief Construtor da classe Message que recebe a data e hora, o remetente e o conteúdo da mensagem como parâmetros.
     * @param dateHour Data e hora da mensagem.
     * @param sentBy Remetente da mensagem.
     * @param content Conteúdo da mensagem.
     */
    Message(string dateHour, int sentBy, string content);

    /**
     * @brief Destrutor da classe Message.
     */
    ~Message();

    /**
     * @brief Obtém a data e hora da mensagem.
     * @return Data e hora da mensagem.
     */
    string getDateHour();

    /**
     * @brief Define a data e hora da mensagem.
     * @param dateHour Data e hora da mensagem.
     */
    void setDateHour(string dateHour);

    /**
     * @brief Obtém o remetente da mensagem.
     * @return Remetente da mensagem.
     */
    int getSentBy();

    /**
     * @brief Define o remetente da mensagem.
     * @param sentBy Remetente da mensagem.
     */
    void setSentBy(int sentBy);

    /**
     * @brief Obtém o conteúdo da mensagem.
     * @return Conteúdo da mensagem.
     */
    string getContent();

    /**
     * @brief Define o conteúdo da mensagem.
     * @param content Conteúdo da mensagem.
     */
    void setContent(string content);
};

#endif
