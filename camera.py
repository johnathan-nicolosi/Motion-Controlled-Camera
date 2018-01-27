from picamera import PiCamera
from time import sleep

camera = PiCamera()

camera.start_preview()
camera.image_effect = 'oilpaint'
camera.capture('/home/pi/Desktop/oilpaint1.jpg')
camera.start_recording('/home/pi/Desktop/video2.h264')
sleep(100)
camera.capture('/home/pi/Desktop/oilpaint2.jpg')
camera.stop_recording()
camera.stop_preview()
