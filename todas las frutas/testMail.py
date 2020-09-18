import smtplib
from email.mime.text import MIMEText
from email.mime.multipart import MIMEMultipart
from email.mime.base import MIMEBase
from email import encoders

email_user = 'monterreyprogramminghub@gmail.com'
email_password = 'pablito12345'

import csv

with open('C:\\Users\\pcruiher08\\Desktop\\csvMonterreyProgrammingHubMails1.csv', newline='') as f:
    reader = csv.reader(f)
    data = list(reader)

print(data)

email_send = []

for singleMail in data:
    print(singleMail[0])
    email_send.append(singleMail[0])

subject = 'Bienvenidos a Programming 101'
msg = MIMEMultipart()
msg['From'] = email_user
msg['To'] = ", ".join(email_send)
msg['Subject'] = subject
body = "¡Hola, Monterrey Programming Hub!\n\nLes recordamos que hoy arranca el curso Programming 101 donde van a poder aprender Python.\nLas clases serán de 6 PM a 8 PM (hora del centro de México).\n\nEnseguida les recordamos los canales oficiales de coumincación para que puedan acceder a las clases:\n\nPara ver las clases en directo:\nYouTube - https://bit.ly/MonterreyProgrammingHub\n\nPara contactar a los maestros y moderadores es muy importante que esten dentro del servidor de Discord:\nDiscord - https://discord.gg/tkBjhWx\n\nLes preparamos un tutorial para que puedan utilizar el servidor de Discord, lo pueden encontrar en:\nhttps://www.youtube.com/watch?v=JSX2nhs4U9k\n\nPara cualquier otro índole:\nCorreo oficial - monterreyprogramminghub@gmail.com\n\n\nGracias,\nEquipo Monterrey Programming Hub"
msg.attach(MIMEText(body,'plain'))
text = msg.as_string()
server = smtplib.SMTP('smtp.gmail.com',587)
server.starttls()
server.login(email_user,email_password)
server.sendmail(email_user,email_send,text)
server.quit()