import time


from MessageProcessor import MessageProcessor
from DataManipulator import DataManipulator

while True:
  print "sendin a message sneekily hehe" 
  countFetch = DataManipulator()
  satisfaction_count=countFetch.getSatisfactionCount()
  messenger = MessageProcessor()
  messenger.processMessage(satisfaction_count)

  time.sleep(60)





