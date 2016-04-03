#the-central-limit-theorem-2.py
#The Central Limit Theorem #2
#Intro to Statistics
#By derekhh
#Mar 31, 2016

from scipy.stats import norm

distribution = norm(2.4 * 100, 2.0 * 10)
print("%.4f" % distribution.cdf(250))
