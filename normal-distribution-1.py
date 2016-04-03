#normal-distribution-1.py
#Normal Distribution #1
#Intro to Statistics
#By derekhh
#Mar 31, 2016

from scipy.stats import norm

distribution = norm(30, 4)
print("%.3f" % distribution.cdf(40))
print("%.3f" % (1.0 - distribution.cdf(21)))
print("%.3f" % (distribution.cdf(35) - (1.0 - distribution.cdf(30))))
