import mysql.connector

conn=mysql.connector.connect(host='localhost',username='root',password='Ram11',database='sachin_table')
my_cursor=conn.cursor()

conn.commit()
conn.close()

print("connection done")