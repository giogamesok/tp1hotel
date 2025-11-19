// Ramal.h
#pragma once
#include <string>
#include <stdexcept>
#include <cctype>

class Ramal {
private:
    std::string valor;
    void validar(const std::string& s) {
        if (s.length() < 2 || s.length() > 50)
            throw std::invalid_argument("Ramal deve ter entre 2 e 50 caracteres.");
        for (char c : s)
            if (!isdigit(c))
                throw std::invalid_argument("Ramal só pode conter dígitos.");
    }
public:
    Ramal(const std::string& s) { validar(s); valor = s; }
    void setValor(const std::string& s) { validar(s); valor = s; }
    std::string getValor() const { return valor; }
};
