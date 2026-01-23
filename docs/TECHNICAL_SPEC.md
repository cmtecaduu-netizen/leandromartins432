# 🛡️ Σ-Clock 2.6 | Technical Specification

## 1. Objective
This document defines the deterministic operational requirements for the **Σ-Clock 2.6 Engine**. The system utilizes a dual-layer architecture to provide both mathematical purity and industrial observability.

## 2. Dual-Layer Architecture

### Layer 1: Engine Core (Stateless)
- **Target:** NASA / Mission-Critical Systems.
- **Characteristics:** Pure functional logic, zero internal memory, reentrant.
- **Logic:** Fixed 6-iteration Newton-Raphson temporal convergence.
- **Safety:** Hard-clamping of inputs [0.0, 1.0].

### Layer 2: Engine Supervisor (Stateful)
- **Target:** Google Cloud / Industrial IoT / Small Business.
- **Characteristics:** Implements a **Safety Latch** and **Telemetry**.
- **Observability:** Records the specific reason for failure (e.g., Anti-Goodhart).
- **Recovery:** Requires an explicit manual `reset()` to exit the ABORT state.



## 3. Sovereignty State Machine
The engine evaluates system health based on the relationship between **Convergence ($k$)** and **Effort ($E$)**.

| Input State | Condition | Output Status | Action |
| :--- | :--- | :--- | :--- |
| $k < \tau$ | Stability not reached | `HOLD` | Maintain current cycle |
| $k \geq \tau$ & $E \geq \epsilon$ | Legitimate Stability | `ADVANCE` | Authorize logical tick |
| $k > \tau$ & $E < \epsilon$ | False Peace detected | `ABORT` | Hard-Latch Shutdown |

> **⚠️ NOTE:** In the Supervisor layer, `ABORT` is a **Terminal Absorbing State**. System recovery requires an external manual reset to ensure safety integrity and human-in-the-loop verification.

## 4. Telemetry & Diagnostics
The system provides a `Telemetry` report accessible via the Supervisor:
- `last_reason`: Diagnosis code (e.g., 0x01 for Anti-Goodhart).
- `is_latched`: Boolean flag indicating if the safety barrier is active.

---
**Protocol:** MARTINS-432-FLOW-2026  
**Version:** 2.6.Dual (Production Ready)  
**Architect:** Leandro Martins
