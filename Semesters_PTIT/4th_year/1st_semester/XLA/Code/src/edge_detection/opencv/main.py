import numpy as np

# Define the image
I = np.array([
    [1, 4, 1, 1, 2, 3, 2, 3],
    [3, 2, 4, 2, 5, 2, 6, 2],
    [2, 1, 8, 2, 5, 2, 5, 6],
    [2, 5, 2, 4, 7, 9, 1, 4],
    [2, 2, 3, 0, 0, 1, 2, 1],
    [1, 5, 7, 1, 2, 4, 5, 6]
])

# Define the number of intensity levels (L)
L = 10

# Calculate the total number of pixels in the image
total_pixels = I.size

# Initialize variables to store the best threshold and the maximum between-class variance
best_threshold = 0
max_between_class_variance = 0

# Iterate through different threshold values (k from 0 to 10)
for k in range(L + 1):
    # Calculate the probabilities of each intensity level
    probabilities = np.bincount(I.flatten()) / total_pixels

    # Calculate the cumulative probabilities
    cumulative_probabilities = np.cumsum(probabilities)

    # Calculate the cumulative means
    cumulative_means = np.cumsum(np.arange(L) * probabilities)

    # Calculate the between-class variance for the current threshold (k)
    between_class_variance = (
        (cumulative_means[k] * cumulative_probabilities[k] - cumulative_means[k]) ** 2 /
        (cumulative_probabilities[k] * (1 - cumulative_probabilities[k]))
    )

    # Update the best threshold if the current variance is greater
    if between_class_variance > max_between_class_variance:
        best_threshold = k
        max_between_class_variance = between_class_variance

# Print the Otsu's threshold for each k from 0 to 10
print("Otsu's threshold for k from 0 to 10:")
for k in range(L + 1):
    print(f"k = {k}: Otsu's Threshold = {best_threshold if k == best_threshold else 'N/A'}")
