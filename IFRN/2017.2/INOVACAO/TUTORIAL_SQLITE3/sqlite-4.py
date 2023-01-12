import sqlite3
import time
import datetime
import random

conn = sqlite3.connect('tutorial.db')
c = conn.cursor()

def create_table():
    c.execute('CREATE TABLE IF NOT EXISTS stuffToPlot(unix REAL, datestamp TEXT, keyword TEXT, value REAL)')

def data_entry():
    c.execute("INSERT INTO stuffToPlot VALUES(123213, '2016-01-02', 'Python', 8)")
    conn.commit()
    c.close()
    conn.close()

def dynamic_data_entry():
    unix = time.time()
    date = str(datetime.datetime.fromtimestamp(unix).strftime('%Y-%m-%d %H:%M:%S'))
    keyword = 'Python'
    value =  random.randrange(0,10)
    c.execute("INSERT INTO stuffToPlot (unix, datestamp, keyword, value) VALUES (?, ?, ?, ?)", (unix, date, keyword, value))
    conn.commit()

def read_from_db():
    c.execute("SELECT * FROM stuffToPlot")
    #data = c.fetchall()
    #print(data)
    for row in c.fetchall():
        print(row)

def del_and_update():
    c.execute('SELECT * FROM stuffToPlot')
    [print(row) for row in c.fetchall()]

##    c.execute('UPDATE stuffToPlot SET value = 99 WHERE value = 8')
##    conn.commit()
##
##    c.execute('SELECT * FROM stuffToPlot')
##    [print(row) for row in c.fetchall()]

##    c.execute('DELETE FROM stuffToPlot WHERE value = 2')
##    conn.commit()
##    print(50*'#')

    c.execute('SELECT * FROM stuffToPlot WHERE value = 2')
    [print(row) for row in c.fetchall()]

    c.execute('SELECT * FROM stuffToPlot WHERE value = 2')
    [print(row) for row in c.fetchall()]


##create_table()
##data_entry()
##for i in range(10):
##    dynamic_data_entry()
##    time.sleep(1)
##read_from_db()
del_and_update()
c.close()
conn.close()
