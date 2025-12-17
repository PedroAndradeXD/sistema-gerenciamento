#ifndef USER_H
#define USER_H

#include <string>

class User {
    private:
        int id;
        std::string name;
        std::string email;
        bool active;

    public:
        User(int id, const std::string& name, const std::string& email)
        : id(id), name(name), email(email), active(true) {}

        int getId() const {
            return id;
        }
        std::string getName() const {
            return name;
        }
        std::string getEmail() const {
            return email;
        }
        bool isActive() const{
            return active;
        }
        void disable() {
            active = false;
        }
};

#endif