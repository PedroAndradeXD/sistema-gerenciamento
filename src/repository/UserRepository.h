#ifndef USERREPOSITORY_H
#define USERREPOSITORY_H

#include <optional>
#include <string>
#include <vector>

class User;

// Gerencia o armazenamento da entidade usuário (simula um banco de dados)
class UserRepository {
    private:
        std::vector<User> users;

    public:
        // Salva ou atualiza um usuário no repositório
        void save(const User& user);

        // Retorna o usuário com o ID especificado, ou nullopt se não existir
        std::optional<User> findById(int id);

        // Retorna o usuário com o email especificado, ou nullopt se não existir
        std::optional<User> findByEmail(const std::string& email);

        // Retorna todos os usuários cadastrados
        std::vector<User> findAll();
};

#endif
