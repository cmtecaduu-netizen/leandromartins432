#include <iostream>
#include <cassert>
#include "../src/sigma_core.hpp"

/**
 * @brief Test Suite para Arquitetura Dual (v2.6)
 * Valida o Core (NASA/Stateless) e o Supervisor (Google/Stateful).
 */
int main() {
    using namespace Sigma;

    // --- TESTE DA CAMADA 1: ENGINE CORE (Matemática Pura) ---
    // Deve ser capaz de avaliar múltiplos estados sem travar internamente.
    Status c1 = EngineCore::evaluate(0.99, 0.00001, 0.95); // Abort
    Status c2 = EngineCore::evaluate(0.98, 0.80, 0.95);    // Advance
    
    assert(c1 == Status::ABORT);
    assert(c2 == Status::ADVANCE);
    std::cout << "Layer 1 (Core): OK" << std::endl;


    // --- TESTE DA CAMADA 2: ENGINE SUPERVISOR (Observabilidade) ---
    // Deve travar (Latch) após o primeiro Abort e exigir Reset.
    
    // 1. Trigger Abort
    EngineSupervisor::evaluate(0.99, 0.00001, 0.95); 
    
    // 2. Tentar nova avaliação (deve continuar em ABORT mesmo com dados bons)
    Status s1 = EngineSupervisor::evaluate(0.98, 0.80, 0.95);
    assert(s1 == Status::ABORT); 
    assert(EngineSupervisor::get_report().is_latched == true);
    
    // 3. Reset Manual (O "botão" do operador)
    EngineSupervisor::reset();
    Status s2 = EngineSupervisor::evaluate(0.98, 0.80, 0.95);
    assert(s2 == Status::ADVANCE);
    
    std::cout << "Layer 2 (Supervisor): OK" << std::endl;
    std::cout << "Sigma-Clock 2.6 Dual: All Systems Green." << std::endl;

    return 0;
}
