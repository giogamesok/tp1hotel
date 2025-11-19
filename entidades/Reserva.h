// Reserva.h
#pragma once
#include "../dominios/Data.h"
#include "../dominios/Dinheiro.h"
#include "../dominios/Codigo.h"

/**
 * @brief Representa uma reserva no hotel.
 */
class Reserva {
private:
    Data chegada;
    Data partida;
    Dinheiro valor;
    Codigo codigo;
public:
    Reserva(const Data& ch, const Data& pa, const Dinheiro& v, const Codigo& c)
        : chegada(ch), partida(pa), valor(v), codigo(c) {}
    void setChegada(const Data& ch) { chegada = ch; }
    void setPartida(const Data& pa) { partida = pa; }
    void setValor(const Dinheiro& v) { valor = v; }
    void setCodigo(const Codigo& c) { codigo = c; }
    Data getChegada() const { return chegada; }
    Data getPartida() const { return partida; }
    Dinheiro getValor() const { return valor; }
    Codigo getCodigo() const { return codigo; }
};
