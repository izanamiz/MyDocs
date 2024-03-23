import cv2
import numpy as np

# Đọc ảnh gốc
input_image = cv2.imread("input_image.png", cv2.IMREAD_GRAYSCALE)

# Thực hiện cân bằng lược đồ xám
equalized_image = cv2.equalizeHist(input_image)

# Hiển thị ảnh gốc và ảnh đã cân bằng
cv2.imshow("Original Image", input_image)
cv2.imshow("Equalized Image", equalized_image)
cv2.waitKey(0)
cv2.destroyAllWindows()

# cv2.imwrite('output_image.png', equalized_image)