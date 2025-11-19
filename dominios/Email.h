// Email.h
#pragma once
#include <string>
#include <regex>
#include <stdexcept>

class Email {
private:
    std::string valor;
    void validar(const std::string& s) {
        if (s.length() < 6 || s.length() > 255)
            throw std::invalid_argument("Email deve ter entre 6 e 255 caracteres.");
        // Regex mais flexível para validação de email comum
        std::regex re(R"(^[A-Za-z0-9._%+-]+@[A-Za-z0-9.-]+\.[A-Za-z]{2,}$)");
        if (!std::regex_match(s, re))
            throw std::invalid_argument("Formato de email inválido.");
    }
public:
    Email(const std::string& s) { validar(s); valor = s; }
    void setValor(const std::string& s) { validar(s); valor = s; }
    std::string getValor() const { return valor; }
};
