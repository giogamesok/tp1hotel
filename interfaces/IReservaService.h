#pragma once
#include "../entidades/Reserva.h"
#include <vector>

/**
 * @interface IReservaService
 * @brief Interface para gerenciamento de reservas.
 */
class IReservaService {
public:
    virtual ~IReservaService() = default;

    /**
     * @brief Lista todas as reservas cadastradas.
     * @return Vetor de reservas.
     */
    virtual std::vector<Reserva> listarReservas() const = 0;

    /**
     * @brief Cria uma nova reserva.
     * @param reserva Reserva a ser criada.
     */
    virtual void criarReserva(const Reserva& reserva) = 0;

    /**
     * @brief Remove uma reserva pelo código.
     * @param codigo Código da reserva.
     */
    virtual void removerReserva(const std::string& codigo) = 0;
};
