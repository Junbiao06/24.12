
import numpy as np
import matplotlib.pyplot as plt

# 参数化曲线
a = 1  # 设置常数 a
t = np.linspace(0, 2 * np.pi, 1000)  # 参数 t 从 0 到 2pi

# 定义 x 和 y
x = a * np.cos(t)**3
y = a * np.sin(t)**3

# 绘制图像
plt.figure(figsize=(6, 6))
plt.plot(x, y, label=r'$x = a \cos^3(t), y = a \sin^3(t)$')
plt.title('Parametric Curve: $x = a \\cos^3(t), y = a \\sin^3(t)$')
plt.xlabel('x')
plt.ylabel('y')
plt.axhline(0, color='black',linewidth=0.5)
plt.axvline(0, color='black',linewidth=0.5)
plt.gca().set_aspect('equal', adjustable='box')  # 保持长宽比相等
plt.legend()
plt.grid(True)
plt.show()
