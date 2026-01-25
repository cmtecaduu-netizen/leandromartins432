# MARTINS-432-FLOW — System Architecture (v2.6.Dual)

## 1. Purpose

This document describes the internal architecture, execution model, and governance mechanisms of the MARTINS-432-FLOW protocol. 

It establishes the technical foundation for the **v2.6.Dual** transition, focusing on the dual-layer separation between pure mathematical evaluation and stateful integrity supervision.

---

## 2. High-Level Overview

The system is organized into a **Dual-Layer Sovereign Architecture**:

1. **Layer 1: EngineCore (Stateless)** — The mathematical heart.
2. **Layer 2: EngineSupervisor (Stateful)** — The telemetry and safety sentinel.

Each layer operates within the `Sigma` namespace to ensure isolation and modularity in industrial SoC environments.

---

## 3. System Components

### 3.1 EngineCore (`Sigma::EngineCore`)

The pure execution layer. It is designed to be **stateless**, meaning it has no internal memory of previous cycles, ensuring total determinism.

**Key Attributes:**
- **Newton-Raphson Implementation**: Fixed-iteration for constant-time execution.
- **Pure Evaluation**: Input parameters are processed through the `evaluate` gate.
- **Statelessness**: Eliminates side-effects and race conditions.

---

### 3.2 EngineSupervisor (`Sigma::EngineSupervisor`)

The stateful governance layer. It manages the system's "memory" regarding safety and faults.

**Key Attributes:**
- **Telemetry Logging**: Tracks the reason for system halts (e.g., Anti-Goodhart violations).
- **The Latch Mechanism**: Implements a safety lock that prevents execution after a critical failure until a manual `reset()` is issued.
- **Sovereignty of Silence**: Triggers the `Status::ABORT` state when integrity is compromised.

---

## 4. Execution Flow (432Hz Sync)

### 4.1 Initialization Phase
1. Hardware clock calibration.
2. Static memory pre-allocation.
3. `Sigma::EngineSupervisor::reset()` to clear previous latches.

### 4.2 Runtime Cycle (≈2.3148 ms)
1. **Input Sampling**: Capture `k` (coefficient) and `e` (error).
2. **Supervisor Audit**: Check if `is_latched` is true.
3. **Core Evaluation**: Mathematical gate processing.
4. **Telemetry Update**: Log reasons for any `ABORT` status.

---

## 5. Memory & Safety Model

- **Zero-STL / Zero-Heap**: No dynamic allocation during runtime.
- **Manual Control**: Explicit use of `unsigned char` for `Status` to minimize memory footprint.
- **Epistemic Latch**: Protection against Goodhart’s Law (mimicry detection).

---

## 6. Failure Handling (Operational Protocol)

| Condition | Action | Implementation |
| :--- | :--- | :--- |
| **Logic Violation** | `Status::ABORT` | Instant halt via Supervisor |
| **Integrity Breach** | `is_latched = true` | Permanent lock until reset |
| **Nominal Hold** | `Status::HOLD` | Wait for next sync cycle |
| **System Success** | `Status::ADVANCE` | Proceed to commit |

---

## 7. Development Roadmap

- **v2.6.Dual (Current)** — Implementation of Stateless/Stateful dual layers.
- **v2.7** — Extended Hardware Abstraction Layer (HAL) for ARM/RISC-V.
- **v3.0** — Formal Epistemic Verification & Civilizational Anchor.

---

**Architect:** Leandro Martins  
**Compliance:** MIT License | Industrial & Sovereign Ready
