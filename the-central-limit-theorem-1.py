#the-central-limit-theorem-1.py
#The Central Limit Theorem #1
#Intro to Statistics
#By derekhh
#Mar 31, 2016

from scipy.stats import norm

distribution = norm(205 * 49, 15 * 7)
print("%.4f" % distribution.cdf(9800))
