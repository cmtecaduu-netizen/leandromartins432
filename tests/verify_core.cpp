#include <iostream>
#include "../src/sigma_core.hpp"

/**
 * @brief Test Suite for Σ-Clock 2.5 Logic (v2.5.Final)
 * Demonstrates the detection of "False Peace" (Goodhart Effect).
 */
int main() {
    using namespace Sigma;

    // SCENARIO 1: Real Convergence (High Effort)
    // k=0.98, E=0.85
    State real_state = {0.98, 0.85}; 
    Status result1 = Engine::evaluate(real_state, 0.95);
    
    std::cout << "Scenario 1 (Real Peace): " 
              << (result1 == Status::ADVANCE ? "ADVANCE AUTHORIZED" : "FAILED") 
              << std::endl;

    // SCENARIO 2: False Peace (Low Effort / Mimicry)
    // k=0.99, E=0.005
    State fake_state = {0.99, 0.005}; 
    Status result2 = Engine::evaluate(fake_state, 0.95);

    std::cout << "Scenario 2 (False Peace): " 
              << (result2 == Status::ABORT ? "ABORT TRIGGERED (SUCCESS)" : "FAILED") 
              << std::endl;

    return 0;
}
