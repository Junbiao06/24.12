import numpy as np
import matplotlib.pyplot as plt

# 定义theta的范围
theta = np.linspace(0, 2 * np.pi, 1000)

# 计算 r^2 = cos(2theta) 的 r 值
r_cos = np.sqrt(np.maximum(np.cos(2 * theta), 0))  # 只有cos(2theta) >= 0时才有解
x_cos = r_cos * np.cos(theta)  # 转换为直角坐标系
y_cos = r_cos * np.sin(theta)

# 计算 r = sqrt(2) * sin(theta) 的 r 值
r_sin = np.sqrt(2) * np.sin(theta)
x_sin = r_sin * np.cos(theta)  # 转换为直角坐标系
y_sin = r_sin * np.sin(theta)

# 创建图形
plt.figure(figsize=(8, 8))

# 绘制 r^2 = cos(2theta)
plt.plot(x_cos, y_cos, label=r'$r^2 = \cos(2\theta)$', color='blue')

# 绘制 r = sqrt(2) * sin(theta)
plt.plot(x_sin, y_sin, label=r'$r = \sqrt{2} \sin(\theta)$', color='red', linestyle='--')

# 添加图例
plt.legend()

# 添加标签和标题
plt.title(r'Graphs of $r^2 = \cos(2\theta)$ and $r = \sqrt{2} \sin(\theta)$ in Cartesian coordinates')
plt.xlabel('x')
plt.ylabel('y')

# 设置轴的范围
plt.xlim(-2, 2)
plt.ylim(-2, 2)

# 显示网格
plt.grid(True)

# 显示图形
plt.gca().set_aspect('equal', adjustable='box')
plt.show()
