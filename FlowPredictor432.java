/**
 * PROTOCOLO: MARTINS-432-FLOW-2025
 * COMPONENTE: MOTOR PREDITIVO - GRAU 8
 * FUNÇÃO: ANÁLISE DE TENDÊNCIA E BLOQUEIO PREVENTIVO
 * ARQUITETO: LEANDRO MARTINS
 */
public class FlowPredictor432 {

    private static double ultimaFrequencia = 432.0;

    public static boolean preverInstabilidade(double novaFrequencia) {
        System.out.println(">>> [IA] Analisando tendência de fluxo...");
        
        // Se a variação for muito brusca (ex: > 100Hz de diferença), prevê instabilidade
        double variacao = Math.abs(novaFrequencia - ultimaFrequencia);
        
        if (variacao > 100.0) {
            System.err.println("!!! IA AVISA: TENDÊNCIA DE RUÍDO DETECTADA (Variação: " + variacao + "Hz) !!!");
            return true; // Instabilidade prevista
        }

        ultimaFrequencia = novaFrequencia;
        return false; // Fluxo estável
    }
}
