#ifndef NOTIFY_H
#define NOTIFY_H

#include <iostream>
#include <string>

namespace template_library {

class NotifierBase {
    public:
        virtual void Notify(const std::string& message) const = 0;
        
        virtual ~NotifierBase() {}
    };
    
    class SmsNotifier : public NotifierBase {
        std::string number;
    public:
        SmsNotifier(const std::string& num) : number(num) {}
        
        void Notify(const std::string& message) const override;
    };
    
    class EmailNotifier : public NotifierBase {
        std::string email; 
    public:
        EmailNotifier(const std::string& mail) : email(mail) {}
        
        void Notify(const std::string& message) const override;
    };
} 

#endif 