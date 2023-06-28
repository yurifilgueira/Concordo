#ifndef USER
#define USER

#include <string>

using std::string;

/**
 * @class User
 * @brief Representa um usuário no sistema de chat.
 */
class User
{
private:
    int id; /**< O ID do usuário. */
    string email; /**< O endereço de e-mail do usuário. */
    string password; /**< A senha do usuário. */
    string name; /**< O nome do usuário. */

public:
    /**
     * @brief Construtor padrão para User.
     */
    User();

    /**
     * @brief Construtor para User com ID, nome, e-mail e senha.
     * @param id O ID do usuário.
     * @param name O nome do usuário.
     * @param email O endereço de e-mail do usuário.
     * @param password A senha do usuário.
     */
    User(int id, string name, string email, string password);

    /**
     * @brief Destrutor para User.
     */
    ~User();

    /**
     * @brief Obtém o ID do usuário.
     * @return O ID do usuário.
     */
    int getId();

    /**
     * @brief Obtém o nome do usuário.
     * @return O nome do usuário.
     */
    string getName();

    /**
     * @brief Define o nome do usuário.
     * @param name O nome a ser definido para o usuário.
     */
    void setName(string name);

    /**
     * @brief Obtém o endereço de e-mail do usuário.
     * @return O endereço de e-mail do usuário.
     */
    string getEmail();

    /**
     * @brief Define o endereço de e-mail do usuário.
     * @param email O endereço de e-mail a ser definido para o usuário.
     */
    void setEmail(string email);

    /**
     * @brief Obtém a senha do usuário.
     * @return A senha do usuário.
     */
    string getPassword();

    /**
     * @brief Define a senha do usuário.
     * @param password A senha a ser definida para o usuário.
     */
    void setPassword(string password);
};

#endif