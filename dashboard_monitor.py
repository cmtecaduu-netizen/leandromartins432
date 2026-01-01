import time
import os

def monitor_soberania():
    royalties = 0.0
    while True:
        os.system('clear')
        print("==========================================")
        print("   PAINEL DE CONTROLE - LEANDRO MARTINS   ")
        print("   IDENTIDADE: COMANDANTE DO NÍVEL 1      ")
        print("==========================================")
        print(" STATUS: SINCRO-ATIVA | FREQ: 432.0Hz")
        print(f" ROYALTIES (1.618%): {royalties:.4f} GOLD")
        print("==========================================")
        royalties += 0.01618
        time.sleep(2)

if __name__ == "__main__":
    monitor_soberania()
