#include "UserRepository.h"
#include "User.h"

void UserRepository::save(const User& user) {
    for(auto& existingUser : users) {
        if(existingUser.getId() == user.getId()) {
            existingUser = user;
            return;
        }
    }
    users.push_back(user);
}

std::optional<User> UserRepository::findById(int id) {
    for(const auto& existingUser : users) {
        if(existingUser.getId() == id) {
            return existingUser;
        }
    }
    return std::nullopt;
}

std::optional<User> UserRepository::findByEmail(const std::string& email) {
    for(const auto& existingUser : users) {
        if(existingUser.getEmail() == email) {
            return existingUser;
        }
    }
    return std::nullopt;
}

std::vector<User> UserRepository::findAll() {
    return users;
}