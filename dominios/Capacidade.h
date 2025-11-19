// Capacidade.h
#pragma once
#include <stdexcept>

class Capacidade {
private:
    int valor;
    void validar(int v) {
        if (v < 1 || v > 4)
            throw std::invalid_argument("Capacidade deve ser 1, 2, 3 ou 4.");
    }
public:
    Capacidade(int v) { validar(v); valor = v; }
    void setValor(int v) { validar(v); valor = v; }
    int getValor() const { return valor; }
};
