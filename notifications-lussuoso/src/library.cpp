#include "library.hpp"

namespace template_library {

    

// Функция для отправки смс. Не менять!
void SendSms(const std::string& number, const std::string& message) {
    std::cout << "Send '" << message << "' to number " << number << std::endl;
}

// Функция для отправки email. Не менять!
void SendEmail(const std::string& email, const std::string& message) {
    std::cout << "Send '" << message << "' to e-mail " << email << std::endl;
}

void SmsNotifier::Notify(const std::string& message) const {
    SendSms(number, message);
}

void EmailNotifier::Notify(const std::string& message) const {
    SendEmail(email, message);
}

} 
