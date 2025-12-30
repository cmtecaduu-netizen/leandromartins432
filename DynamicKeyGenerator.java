import java.util.UUID;

/**
 * PROTOCOLO: MARTINS-432-FLOW-2025
 * COMPONENTE: GERADOR DE CHAVE DINÂMICA - GRAU 9
 * FUNÇÃO: CRIPTOGRAFIA MUTANTE POR CICLO
 * ARQUITETO: LEANDRO MARTINS
 */
public class DynamicKeyGenerator {

    private static String chaveAtual;

    public static String gerarNovaChave() {
        // Gera um identificador único para este ciclo
        chaveAtual = "MARTINS-" + UUID.randomUUID().toString().substring(0, 8).toUpperCase();
        System.out.println(">>> [CRIPT] Nova Chave Dinâmica Gerada: " + chaveAtual);
        return chaveAtual;
    }

    public static String getChaveAtual() {
        return chaveAtual;
    }
}
