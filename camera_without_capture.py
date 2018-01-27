from picamera import PiCamera
from time import sleep

camera = PiCamera()

camera.start_preview()
camera.image_effect = 'oilpaint'
sleep(100000)
camera.stop_preview()
