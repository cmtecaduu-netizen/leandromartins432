#include <iostream>
#include "../src/sigma_core.hpp"

/**
 * @brief Test Suite for Σ-Clock 2.5 Logic
 * Demonstrates the detection of "False Peace" (Goodhart Effect).
 */
int main() {
    using namespace Sigma;

    // SCENARIO 1: Real Convergence (High Effort)
    State real_state = {0.98, 0.85, 100}; // k=0.98, E=0.85
    Status result1 = Engine::evaluate(real_state, 0.95);
    
    std::cout << "Scenario 1 (Real Peace): " 
              << (result1 == Status::ADVANCE ? "ADVANCE AUTHORIZED" : "FAILED") 
              << std::endl;

    // SCENARIO 2: False Peace (Low Effort / Mimicry)
    State fake_state = {0.99, 0.005, 100}; // k=0.99, E=0.005
    Status result2 = Engine::evaluate(fake_state, 0.95);

    std::cout << "Scenario 2 (False Peace): " 
              << (result2 == Status::ABORT_CRITICAL ? "ABORT TRIGGERED (SUCCESS)" : "FAILED") 
              << std::endl;

    return 0;
}
