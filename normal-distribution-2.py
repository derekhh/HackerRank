#normal-distribution-2.py
#Normal Distribution #2
#Intro to Statistics
#By derekhh
#Mar 31, 2016

from scipy.stats import norm

distribution = norm(20, 2)
print("%.3f" % distribution.cdf(19.5))
print("%.3f" % (distribution.cdf(22) - (1.0 - distribution.cdf(20))))

