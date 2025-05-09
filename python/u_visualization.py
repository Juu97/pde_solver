import pandas as pd
import numpy as np
import matplotlib.pyplot as plt
from mpl_toolkits.mplot3d import Axes3D

import pandas as pd
import numpy as np
import matplotlib.pyplot as plt
from mpl_toolkits.mplot3d import Axes3D


df = pd.read_csv("../python/u_data.csv")  # <-- aggiorna se serve


alpha = 1.0
pi2 = np.pi**2


timesteps = sorted(df["timestep"].unique())
nx = df["i"].max() + 1
ny = df["j"].max() + 1


plt.ion()
fig = plt.figure(figsize=(12, 6))
ax = fig.add_subplot(111, projection="3d")

for t in timesteps:
    df_t = df[df["timestep"] == t].sort_values(["j", "i"])
    x = df_t["x"].values.reshape(ny, nx)
    y = df_t["y"].values.reshape(ny, nx)
    u_num = df_t["u"].values.reshape(ny, nx)

    t_real = df_t["time"].iloc[0]
    u_exact = np.sin(np.pi * x) * np.sin(np.pi * y) * np.exp(-2 * pi2 * alpha * t_real)

    ax.clear()
    ax.plot_surface(x, y, u_num, cmap="inferno", edgecolor="none", alpha=0.8)
    ax.plot_wireframe(x, y, u_exact, color="cyan", linewidth=0.5)

    ax.set_title(f"Soluzione numerica vs esatta al tempo t = {t_real:.3f}")
    ax.set_xlabel("x")
    ax.set_ylabel("y")
    ax.set_zlabel("u(x,y)")
    ax.set_zlim(0, 1)
    plt.pause(0.05)

plt.ioff()
plt.show()
