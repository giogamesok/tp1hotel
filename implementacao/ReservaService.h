#pragma once
#include "../interfaces/IReservaService.h"
#include "../entidades/Reserva.h"
#include <vector>
#include <algorithm>

/**
 * @class ReservaService
 * @brief Implementação do serviço de reservas com lista em memória.
 */
class ReservaService : public IReservaService {
private:
    std::vector<Reserva> reservas;
public:
    std::vector<Reserva> listarReservas() const override {
        return reservas;
    }

    void criarReserva(const Reserva& reserva) override {
        reservas.push_back(reserva);
    }

    void removerReserva(const std::string& codigo) override {
        reservas.erase(std::remove_if(reservas.begin(), reservas.end(),
            [&codigo](const Reserva& r) {
                return r.getCodigo().getValor() == codigo;
            }), reservas.end());
    }
};
