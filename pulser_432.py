import time
import logging
from datetime import datetime

logging.basicConfig(
    filename='heartbeat.log',
    level=logging.INFO,
    format='%(asctime)s | %(message)s',
)

FREQUENCIA = 432.0
INTERVALO = 3600

def pulser():
    while True:
        try:
            now = datetime.now().strftime('%Y-%m-%d %H:%M:%S')
            mensagem = f'Pulsação AELOH-432: {now} | FREQUÊNCIA: {FREQUENCIA}Hz'
            logging.info(mensagem)
            print(f'>>> {mensagem}')
            time.sleep(INTERVALO)
        except Exception as e:
            logging.error(f'Erro detectado no pulso: {e}')
            time.sleep(10)

if __name__ == "__main__":
    pulser()
