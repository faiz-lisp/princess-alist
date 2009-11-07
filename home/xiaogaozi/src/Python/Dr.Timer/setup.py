from distutils.core import setup
import py2exe

setup(name = "Dr. Timer",
      version = "0.0.1",
      author = "xiaogaozi",
      author_email = "gaochangjian@gmail.com",
      license = "GPLv3",
      data_files = [("sound", ["sound/ring.wav", "sound/end.wav"])],
      windows = [{"script": "timer.py",
                  "icon_resources": [(1, "py.ico")]}])
