import matplotlib.pyplot as plt
import numpy as np

x: np.ndarray[int] = np.arange(1998, 2024)
y: np.ndarray[int] = np.array(
    [24361347, 27172139,
     29722950, 31913003, 35523633, 36658501, 39240875, 42071961, 45372640, 49644025, 54506661, 59361642,
     64817974, 70543535, 76137191, 81600729, 86700490, 90686936, 93867016, 97091956, 100746553, 104784375,
     107948371, 111446870, 115116532, 119227657])

# Plot the total number of vehicles as a line plot
plt.plot(x, y / 1000000)

#plt.grid(True)
plt.xlabel('Ano')
plt.ylabel('Veículos em milhões')
plt.savefig(fname="fig1.pdf", transparent=True, bbox_inches='tight')
