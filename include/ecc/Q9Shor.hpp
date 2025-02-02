/*
* This file is part of MQT QFR library which is released under the MIT license.
* See file README.md or go to https://www.cda.cit.tum.de/research/quantum/ for more information.
*/

#pragma once

#include "Ecc.hpp"
#include "QuantumComputation.hpp"
namespace ecc {
    class Q9Shor: public Ecc {
    public:
        Q9Shor(std::shared_ptr<qc::QuantumComputation> qc, std::size_t measureFq):
            Ecc({ID::Q9Shor, N_REDUNDANT_QUBITS, N_CORRECTING_BITS, "Q9Shor", {{2, "qeccX1"}, {2, "qeccX2"}, {2, "qeccX3"}, {2, "qeccZ"}}}, std::move(qc), measureFq) {}

    protected:
        void writeEncoding() override;

        void measureAndCorrect() override;

        void writeDecoding() override;

        void mapGate(const qc::Operation& gate) override;

        static constexpr std::size_t N_REDUNDANT_QUBITS = 9;
        static constexpr std::size_t N_CORRECTING_BITS  = 8;
    };
} // namespace ecc
