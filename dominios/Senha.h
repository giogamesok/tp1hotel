// Senha.h
#pragma once
#include <string>
#include <stdexcept>
#include <cctype>

class Senha {
private:
    std::string valor;
    void validar(const std::string& s) {
        if (s.length() < 5)
            throw std::invalid_argument("Senha deve ter no mínimo 5 caracteres.");
        bool hasUpper=false, hasLower=false, hasDigit=false, hasSpecial=false;
        for (char c : s) {
            if (isupper(c)) hasUpper=true;
            else if (islower(c)) hasLower=true;
            else if (isdigit(c)) hasDigit=true;
            else hasSpecial=true;
        }
        if (!hasUpper || !hasLower || !hasDigit || !hasSpecial)
            throw std::invalid_argument("Senha deve conter maiúscula, minúscula, dígito e caractere especial.");
    }
public:
    Senha(const std::string& s) { validar(s); valor = s; }
    void setValor(const std::string& s) { validar(s); valor = s; }
    std::string getValor() const { return valor; }
};
