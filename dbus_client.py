#! /usr/bin/env python
import dbus

bus = dbus.SessionBus()
session = bus.get_object("lge.example.QtDBus.ChatExample", "/2")

session.messageSend('sonnd2', 'lge.qtchat.test1')

while True:
    session.messageSend('sonnd', raw_input(">"))