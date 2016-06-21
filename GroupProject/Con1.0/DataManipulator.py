import psycopg2
import sys

print("Hello")

class DataManipulator:
    
   def getSatisfactionCount(self):
	connection = psycopg2.connect(database="pev115", user="pev115", password="BPIwoFvA2A",
                        host="db", port="5432")
	if connection is None:
		print ("Run")
	else:
		print ("Success")


	cursor = connection.cursor()
	sql='SELECT count FROM count WHERE count>2'
	cursor.execute(sql)
	data = cursor.fetchall()[0][0]
	print data
        return data
	
	#for row in data:
	#	print row[0]

	connection.close()
	

	
	

#dataMan = DataManipulator()
#dataMan.getSatisfactionCount()


