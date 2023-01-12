import sqlite3
import time
import datetime

connection = sqlite3.connect('projeto.db')
c = connection.cursor()

def criptografia(usuario, senha):
    usuario = '21323232'
    senha = '443423'

def create_table():
    c.execute('CREATE TABLE IF NOT EXISTS dados(Usuario char, Senha char, Data text)')

def data_entry(usuario, senha):
    date = str(datetime.datetime.fromtimestamp(int(time.time())).strftime('%Y-%m-%d %H:%M:%S'))
    
    c.execute('INSERT INTO dados VALUES(?, ?, ?)', (usuario, senha, date))
    
    connection.commit()

create_table()

usuario = input("Digite um nome de usuário: ")
senha = input("Digite uma senha: ")

criptografia(usuario, senha)
data_entry(usuario, senha)
