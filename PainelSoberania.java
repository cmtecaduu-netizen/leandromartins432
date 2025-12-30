/**
 * PROTOCOLO: MARTINS-432-FLOW-2025
 * COMPONENTE: PAINEL DE SOBERANIA - GRAU 10 (FINAL)
 * ARQUITETO: LEANDRO MARTINS
 */
public class PainelSoberania {

    public static void main(String[] args) {
        
        // 1. INICIALIZAÇÃO DO CORE
        System.out.println("========== INICIANDO PROTOCOLO 432 ==========");
        
        // 2. TESTE DE RESILIÊNCIA E AUTO-RECUPERAÇÃO
        double frequenciaAposCarga = 440.0; // Desvio detectado
        SelfHealing432.verificarESanar(frequenciaAposCarga); // Estabilizando para 432Hz
        
        // 3. REGISTRO NO WATCHDOG (HISTÓRICO)
        SincroniaWatchdog.registrar(432.0, "ESTÁVEL");
        SincroniaWatchdog.exportarHistorico();
        
        // 4. LACRE FINAL: CHAMADA DO DASHBOARD SOBERANO
        // Este componente mostra sua Chave Dinâmica e Status Real
        DashboardUI.exibirStatus();
        
        System.out.println("========== MARTINS-432-FLOW-2025: ATIVO ==========");
    }
}












