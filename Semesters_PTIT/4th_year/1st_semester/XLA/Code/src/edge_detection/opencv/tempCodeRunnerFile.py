import numpy as np

# Define the image
I = np.array(
    [
        [1, 4, 1, 1, 2, 3, 2, 3],
        [3, 2, 4, 2, 5, 2, 6, 2],
        [2, 1, 8, 2, 5, 2, 5, 6],
        [2, 5, 2, 4, 7, 9, 1, 4],
        [2, 2, 3, 0, 0, 1, 2, 1],
        [1, 5, 7, 1, 2, 4, 5, 6],
    ]
)

# Define the Otsu's threshold
otsu_threshold = 5

# Apply the threshold and round each pixel value
rounded_image = np.round(I)

# Calculate the variance of the rounded image at k = 0
variance_k0 = np.var(rounded_image[rounded_image == 3])

print("Rounded squared variance at k = 0:", variance_k0)
