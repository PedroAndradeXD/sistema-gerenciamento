#ifndef USER_H
#define USER_H

#include <string>

// Representa a entidade usuário
class User {
    private:
        int id;
        std::string name;
        std::string email;
        bool active;

    public:
        // Inicializa um usuário com id, nome e email; ativo por padrão
        User(int id, const std::string& name, const std::string& email)
        : id(id), name(name), email(email), active(true) {}

        // Retorna o ID do usuário
        int getId() const {
            return id;
        }

        // Retorna o nome do usuário
        std::string getName() const {
            return name;
        }

        // Retorna o email do usuário
        std::string getEmail() const {
            return email;
        }

        // Atualiza o nome do usuário
        void setName(const std::string& newName) {
            name = newName;
        }

        // Atualiza o email do usuário
        void setEmail(const std::string& newEmail) {
            email = newEmail;
        }

        // Retorna se o usuário está ativo
        bool isActive() const {
            return active;
        }

        // Torna o usuário inativo (muda o próprio estado)
        void disable() {
            active = false;
        }

        // Torna o usuário ativo  (muda o próprio estado)
        void enable() {
            active = true;
        }
};

#endif
