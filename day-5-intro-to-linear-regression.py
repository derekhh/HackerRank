#day-5-introduction-to-linear-regression.py
#Day 5: Introduction to Linear Regression
#Intro to Statistics
#By derekhh
#Apr 1, 2016

import numpy as np
from sklearn import linear_model

x = [95, 85, 80, 70, 60]
x = np.reshape(x, (5, 1))

y = [85, 95, 70, 65, 70]
y = np.reshape(y, (5, -1))

reg = linear_model.LinearRegression()
reg.fit(x, y)
print("%.1f" % reg.predict([[80]]))