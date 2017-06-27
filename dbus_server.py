#! /usr/bin/env python3

# D-Bus Server -- Session Bus

from gi.repository import GLib
import dbus
import dbus.service
from dbus.mainloop.glib import DBusGMainLoop

class Session_DBus(dbus.service.Object):

    def __init__(self):
        bus_name = dbus.service.BusName('lge.example.QtDBus.ChatExample', bus=dbus.SessionBus())
        dbus.service.Object.__init__(self, bus_name, '/1')

    # Interface and Method
    @dbus.service.method('lge.qtchat.test1')
    def messageSend(self, username, message):
        print username, ":" , message
        return "DBus: " + message

DBusGMainLoop(set_as_default=True)
dbus_service = Session_DBus()

try:
    GLib.MainLoop().run()
except KeyboardInterrupt:
    print("\nThe MainLoop will close...")
    GLib.MainLoop().quit()