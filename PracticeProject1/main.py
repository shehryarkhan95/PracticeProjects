from mqtt import MQTTClient
from network import WLAN
import machine
import time

def sub_cb(topic, msg):
   print(msg)

# Connect to Wi-Fi
wlan = WLAN(mode=WLAN.STA)
wlan.connect("Martin Router King", auth=(WLAN.WPA2, "Pn5.Fh89?rT!45"), timeout=5000)

while not wlan.isconnected():
    machine.idle()
print("Connected to WiFi\n")

# MQTT setup
client = MQTTClient("device_id", 
                    "io.adafruit.com", 
                    user="shehryar_k95", 
                    password="******************************", 
                    port=1883)

client.set_callback(sub_cb)
client.connect()
client.subscribe(topic="shehryar_k95/feeds/lights")

while True:
    print("Sending ON")
    client.publish(topic="shehryar_k95/feeds/lights", msg="ON")
    time.sleep(5)
    print("Sending OFF")
    client.publish(topic="shehryar_k95/feeds/lights", msg="OFF")
    client.check_msg()

    time.sleep(5)