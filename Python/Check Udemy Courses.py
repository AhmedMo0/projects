###################
# Check Udemy courses Price
###################

import requests
from bs4 import BeautifulSoup
import smtplib
import time
from twilio.rest import TwilioRestClient
from datetime import datetime
import re


def check_course():
    global url
    headers = {
        "User-Agent": "type here"
    }

    url = input("type course url: ")
    source = requests.get(url, headers=headers)

    soup = BeautifulSoup(source.content, "html.parser")
    state = soup.find('div', class_="price-text--container--Ws-fP udlite-clp-price-text").get_text().split(" ")[1]
    r = re.search('(Free)',state)
    print(state)
    '''
    if r :
        print("Get Course")
        send_mail()
        dial_numbers(DIAL_NUMBERS)
        now = datetime.now()
        current_time = now.strftime("%H:%M:%S")
        print("Current Time =", current_time)
        print("----------------------")
    else:
        print("Not yet")
        print(state)
        now = datetime.now()
        current_time = now.strftime("%H:%M:%S")
        print("Current Time =", current_time)
        print("----------------------")
'''


# Make a call


# Twilio phone number goes here. Grab one at https://twilio.com/try-twilio
# and use the E.164 format, for example: "+12025551234"
TWILIO_PHONE_NUMBER = "type here"

# list of one or more phone numbers to dial, in "+19732644210" format
DIAL_NUMBERS = ["type here"]

# URL location of TwiML instructions for how to handle the phone call
TWIML_INSTRUCTIONS_URL = \
  "http://static.fullstackpython.com/phone-calls-python.xml"

# replace the placeholder values with your Account SID and Auth Token
# found on the Twilio Console: https://www.twilio.com/console
client = TwilioRestClient("Account SID", "Auth Token")


def dial_numbers(numbers_list):
    """Dials one or more phone numbers from a Twilio phone number."""
    for number in numbers_list:
        print("Dialing " + number)
        # set the method to "GET" from default POST because Amazon S3 only
        # serves GET requests on files. Typically POST would be used for apps
        client.calls.create(to=number, from_=TWILIO_PHONE_NUMBER,
                            url=TWIML_INSTRUCTIONS_URL, method="GET")


    print("Calling Done")

##########################


def send_mail():

    s = smtplib.SMTP('smtp.gmail.com', 587)
    s.ehlo()
    s.starttls()
    s.ehlo()

    s.login('Email', 'pass')

    subject = 'submition opened'
    body = "Check the link {}".format(url)

    msg = f'Subject: {subject}\n\n{body}'

    s.sendmail(
    'from',
    'to',
    msg
    )
    #print a message to check if the email has been sent
    print('Hey Email has been sent')
    # quit the server
    s.quit()

#loop that allows the program to regularly check for prices


while True:
    check_course()
    time.sleep(60*20)










