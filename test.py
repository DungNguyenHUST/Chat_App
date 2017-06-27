import os

_cached_stamp = 0
filename = ''

stamp = os.stat(self.filename).st_mtime
if stamp != self._cached_stamp:
    self._cached_stamp = stamp
    # File has changed, so do something...
    