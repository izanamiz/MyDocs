import cv2
import numpy as np
input_image = cv2.imread('input_image.png', cv2.IMREAD_GRAYSCALE)
output_image = np.zeros_like(input_image, dtype=np.float32)

for i in range(input_image.shape[0]):
    for j in range(input_image.shape[1]):
        x = input_image[i, j] / 255.0  
        
        if x <= 3/8:
            y = x / 3
        elif 3/8 <= x <= 5/8:
            y = 3 * x - 1
        elif 5/8 <= x <= 1:
            y = (x + 2) /3
        output_image[i, j] = y * 255.0  

cv2.imwrite('output_image.png', output_image)
