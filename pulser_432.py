import time, os; from datetime import datetime; 
while True:
    now = datetime.now().strftime('%Y-%m-%d %H:%M:%S')
    with open('heartbeat.txt', 'a') as f:
        f.write(f'Pulsação AELOH-432: {now}\n')
    print(f'>>> PULSAÇÃO REGISTRADA: {now} | FREQUÊNCIA: 432Hz')
    time.sleep(3600)
