import smtplib
import string


from email.mime.multipart import MIMEMultipart
from email.mime.text import MIMEText


class MessageProcessor:
    def sendMessage(self, FROM , TO, SUBJECT, TEXT):
        #print "message is being sent..."

       # message = string.join("From: %s\r\n" % FROM,
        #"To: %s\r\n" % ", ".join(TO),
       # "Subject: %s\r\n" %SUBJECT,
        #"\r\n",
       # TEXT)


      # Create message container - the correct MIME type is multipart/alternative.
      msg = MIMEMultipart('alternative')
      msg['Subject'] = SUBJECT
      msg['From'] = FROM
      msg['To'] = ", ".join(TO)

      # Create the body of the message (a plain-text and an HTML version).
      text = TEXT
      html = """\
      <html>
	<head></head>
	<body>
	  <p>Hi!<br>
	  %s
	  </p>
	</body>
      </html>
      """ % TEXT

      # Record the MIME types of both parts - text/plain and text/html.
      part1 = MIMEText(text, 'plain')
      part2 = MIMEText(html, 'html')

      msg.attach(part1)
      msg.attach(part2)


      # message = """\
      # From: %s\r\n
      #To: %s\r\n
      # Subject: %s\r\n

      #%s
      # """ % (FROM, ", ".join(TO), SUBJECT, TEXT)
      
      server = smtplib.SMTP('smarthost.cc.ic.ac.uk')
	  
      server.sendmail(FROM, TO, msg.as_string())
        
      #server.sendmail(FROM,TO,message)
      server.quit()

    def processMessage(self,satisfaction_count):
        print "processing message..."
        if satisfaction_count is 4 :
           self.sendMessage("aeb115@ic.ac.uk",["pev115@ic.ac.uk","adrien_boukobza@hotmail.fr", "aeb115@ic.ac.uk"],"Warning",
                            "Miguel and Eugene are the best, so I'll offer them a drink on Friday !!!")
        if satisfaction_count is 8 :
            self.sendMessage('pev115@ic.ac.uk',["aeb115@ic.ac.uk", "adrien_boukobza@hotmail.fr"],"Warning",
                        "We recommend that the cleaning company is thoroughly managed")
        if satisfaction_count is 15 : 
            self.sendMessage('pev115@ic.ac.uk',["aeb115@ic.ac.uk", "adrien_boukobza@hotmail.fr"],"Warning",
                        "Time for some firing")



        

#message = MessageProcessor()
#message.sendMessage(2)
