import paypalrestsdk
def iniciar_fluxo(id, secret):
    paypalrestsdk.configure({"mode": "sandbox", "client_id": id, "client_secret": secret})
    print("📡 Sincronia Diária: Conexão AELOH-432 Estabelecida com Sucesso.")
