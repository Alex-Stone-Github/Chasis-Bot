import numpy as np
import cv2 as cv

cap = cv.VideoCapture(0)

while True:
    _, frame = cap.read()
    cv.imshow('frame', frame)
    if cv.waitKey(1) == ord('q'):
        break
cap.release()
cv.destroyAllWindows()

