import java.util.ArrayList;
import java.util.List;
import java.util.Date;

/**
 * PROTOCOLO: MARTINS-432-FLOW-2025
 * COMPONENTE: MEMÓRIA IMUTÁVEL (WATCHDOG) - GRAU 3
 * PROTEÇÃO: FLUXO CIFRADO ATIVO
 * ARQUITETO: LEANDRO MARTINS
 */
public class SincroniaWatchdog {
    private static final List<String> historicoTransmutacoes = new ArrayList<>();

    /**
     * Registra a ação aplicando a criptografia de Grau 3 antes do armazenamento.
     */
    public static void registrar(double fator, String descricao) {
        String timestamp = new Date().toString();
        String dadoBruto = String.format("[%s] Fator: %.2fHz | Ação: %s | Assinado: LEANDRO MARTINS", 
                            timestamp, fator, descricao);
        
        // Aplica a cifra antes de guardar na lista
        String dadoProtegido = CriptoFlow432.cifrar(dadoBruto);
        
        historicoTransmutacoes.add(dadoProtegido);
        System.out.println(">>> LOG CIFRADO E ARMAZENADO COM SEGURANÇA.");
    }

    public static void exportarHistorico() {
        System.out.println("\n--- RELATÓRIO DE SOBERANIA CRIPTOGRAFADO ---");
        if (historicoTransmutacoes.isEmpty()) {
            System.out.println("Nenhum registro encontrado.");
        } else {
            for (String registro : historicoTransmutacoes) {
                System.out.println(registro);
            }
        }
        System.out.println("--------------------------------------------\n");
    }
}



