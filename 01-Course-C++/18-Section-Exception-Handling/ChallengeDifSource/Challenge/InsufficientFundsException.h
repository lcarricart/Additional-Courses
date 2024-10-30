#ifndef INSUFFICIENTFUNDSEXCEPTION_H
#define INSUFFICIENTFUNDSEXCEPTION_H

class InsufficientFundsException: public std::exception
{
public:
    InsufficientFundsException() {};
    virtual const char* what() const noexcept {
        return "Insufficient funds exception";
    };
    ~InsufficientFundsException() {};

};

#endif // INSUFFICIENTFUNDSEXCEPTION_H
