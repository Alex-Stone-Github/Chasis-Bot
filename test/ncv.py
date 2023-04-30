import cv2
import numpy as np

def nothing(x): pass

video = cv2.VideoCapture(0)
cv2.namedWindow('sliders')
cv2.createTrackbar('HMin','sliders',0,179,nothing)
cv2.createTrackbar('SMin','sliders',0,255,nothing)
cv2.createTrackbar('VMin','sliders',0,255,nothing)
cv2.createTrackbar('HMax','sliders',0,179,nothing)
cv2.createTrackbar('SMax','sliders',0,255,nothing)
cv2.createTrackbar('VMax','sliders',0,255,nothing)

while True:
    _, frame = video.read()

    cv2.imshow("cam", frame)

    hsv = cv2.cvtColor(frame, cv2.COLOR_BGR2HSV)
    cv2.imshow("hsv", hsv)

    hMin = cv2.getTrackbarPos('HMin','sliders')
    sMin = cv2.getTrackbarPos('SMin','sliders')
    vMin = cv2.getTrackbarPos('VMin','sliders')
    hMax = cv2.getTrackbarPos('HMax','sliders')
    sMax = cv2.getTrackbarPos('SMax','sliders')
    vMax = cv2.getTrackbarPos('VMax','sliders')
    lower = np.array([hMin, sMin, vMin])
    upper = np.array([hMax, sMax, vMax])
    mask = cv2.inRange(hsv, lower, upper)
    cv2.imshow("mask", mask)



    key = cv2.waitKey(20)
    if key == 27: # escape
        break

cv2.destroyWindow()
video.release()