// Numero.h
#pragma once
#include <stdexcept>

class Numero {
private:
    int valor;
    void validar(int v) {
        if (v < 1 || v > 50)
            throw std::invalid_argument("Número deve estar entre 1 e 50.");
    }
public:
    Numero(int v) { validar(v); valor = v; }
    void setValor(int v) { validar(v); valor = v; }
    int getValor() const { return valor; }
};
