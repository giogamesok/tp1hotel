// Quarto.h
#pragma once
#include "../dominios/Numero.h"
#include "../dominios/Capacidade.h"
#include "../dominios/Dinheiro.h"
#include "../dominios/Ramal.h"
#include "../dominios/Codigo.h"

/**
 * @brief Representa um quarto do hotel.
 */
class Quarto {
private:
    Numero numero;
    Capacidade capacidade;
    Dinheiro diaria;
    Ramal ramal;
    Codigo codigo;
public:
    Quarto(const Numero& n, const Capacidade& c, const Dinheiro& d, const Ramal& r, const Codigo& cod)
        : numero(n), capacidade(c), diaria(d), ramal(r), codigo(cod) {}
    void setNumero(const Numero& n) { numero = n; }
    void setCapacidade(const Capacidade& c) { capacidade = c; }
    void setDiaria(const Dinheiro& d) { diaria = d; }
    void setRamal(const Ramal& r) { ramal = r; }
    void setCodigo(const Codigo& cod) { codigo = cod; }
    Numero getNumero() const { return numero; }
    Capacidade getCapacidade() const { return capacidade; }
    Dinheiro getDiaria() const { return diaria; }
    Ramal getRamal() const { return ramal; }
    Codigo getCodigo() const { return codigo; }
};
