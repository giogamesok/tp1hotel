//
// Created by Leonardo Sequeira on 15/11/25.
//

#include "../../include/implementacao/HospedeService.h"
#include "../../include/entidades/Hospede.h"
#include <algorithm>
#include <stdexcept>

void HospedeService::criarHospede(const Hospede& hospede) {
    // Verifica se já existe hóspede com mesmo email
    for (const auto& h : hospedes) {
        if (h.getEmail().getValor() == hospede.getEmail().getValor()) {
            throw std::invalid_argument("Já existe um hóspede com este email");
        }
    }
    hospedes.push_back(hospede);
}

std::vector<Hospede> HospedeService::listarHospedes() const {
    return hospedes;
}

Hospede HospedeService::buscarHospedePorEmail(const std::string& email) const {
    for (const auto& hospede : hospedes) {
        if (hospede.getEmail().getValor() == email) {
            return hospede;
        }
    }
    throw std::invalid_argument("Hóspede não encontrado");
}

Hospede HospedeService::buscarHospedePorCartao(const std::string& cartao) const {
    for (const auto& hospede : hospedes) {
        if (hospede.getCartao().getValor() == cartao) {
            return hospede;
        }
    }
    throw std::invalid_argument("Hóspede não encontrado");
}

bool HospedeService::editarHospede(const std::string& email, const Hospede& hospedeAtualizado) {
    for (auto& hospede : hospedes) {
        if (hospede.getEmail().getValor() == email) {
            hospede = hospedeAtualizado;
            return true;
        }
    }
    return false;
}

bool HospedeService::excluirHospede(const std::string& email) {
    auto it = std::remove_if(hospedes.begin(), hospedes.end(),
        [&email](const Hospede& hospede) {
            return hospede.getEmail().getValor() == email;
        });
    
    if (it != hospedes.end()) {
        hospedes.erase(it, hospedes.end());
        return true;
    }
    return false;
}

size_t HospedeService::quantidadeHospedes() const {
    return hospedes.size();
}
