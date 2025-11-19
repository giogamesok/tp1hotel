// HospedeService.h
#pragma once

#include "../interfaces/IHospedeService.h"
#include "../entidades/Hospede.h"
#include <vector>
#include <algorithm>

/**
 * @class HospedeService
 * @brief Implementação do serviço de hóspedes que mantém uma lista em memória.
 */
class HospedeService : public IHospedeService {
private:
    std::vector<Hospede> hospedes;
public:
    std::vector<Hospede> listarHospedes() const override {
        return hospedes;
    }

    void criarHospede(const Hospede& hospede) override {
        hospedes.push_back(hospede);
    }

    void removerHospede(const std::string& email) override {
        hospedes.erase(std::remove_if(hospedes.begin(), hospedes.end(),
            [&email](const Hospede& h) {
                return h.getEmail().getValor() == email;
            }), hospedes.end());
    }
};
