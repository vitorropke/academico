import sqlite3
import time
import datetime

connection = sqlite3.connect('tutorial.db')
c = connection.cursor()

def create_table():
    c.execute('CREATE TABLE IF NOT EXISTS dados(id integer, unix real,\
              keyword text, datestamp text, value real)')

def data_entry():
    '''
    c.execute("INSERT INTO dados VALUES(1, 12321342.323, 'Python Sentiment',\
              '2013-04-14 10:09:41', 5)")
    c.execute("INSERT INTO dados VALUES(2, 54535132.323, 'Python Sentiment',\
              '2013-04-14 10:10:57', 6)")
    c.execute("INSERT INTO dados VALUES(3, 84943432.323, 'Python Sentiment',\
              '2013-04-14 10:11:41', 4)")
    connection.commit()
    '''

    date = str(datetime.datetime.fromtimestamp(int(time.time())).strftime('%Y-%m-%d %H:%M:%S'))

    c.execute('INSERT INTO dados (id, unix, keyword, datestamp, value) VALUES (?, ?, ?, ?, ?)',
              (data_id, time.time(), keyword, date, value))

    connection.commit()

create_table()

data_id = 4
keyword = 'Python is awesome!'
value = 4

data_entry()
