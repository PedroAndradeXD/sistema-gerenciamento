#ifndef USERREPOSITORY_H
#define USERREPOSITORY_H

#include <optional>
#include <string>
#include <vector>

class User;

class UserRepository {
    private:
        std::vector<User> users;
        
    public:
        void save(const User& user);

        std::optional<User> findById(int id);

        std::optional<User> findByEmail(const std::string& email);

        std::vector<User> findAll();
};

#endif