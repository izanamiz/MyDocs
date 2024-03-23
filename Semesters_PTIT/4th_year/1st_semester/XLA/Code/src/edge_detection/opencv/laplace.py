import cv2
import numpy as np

image = cv2.imread("original.jpg", cv2.IMREAD_GRAYSCALE)

laplace = cv2.Laplacian(image, cv2.CV_64F)
scaled_image = cv2.normalize(laplace, None, 0, 255, cv2.NORM_MINMAX, cv2.CV_8U)
sharp_image = cv2.filter2D(image, -1, np.array([[0, -1, 0], [-1, 5, -1], [0, -1, 0]]))

cv2.imwrite("laplace.jpg", laplace)
cv2.imwrite("scaled_image.jpg", scaled_image)
cv2.imwrite("sharp_image.jpg", sharp_image)
