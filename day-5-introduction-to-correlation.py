#day-5-introduction-to-correlation.py
#Day 5: Introduction to Correlation
#Intro to Statistics
#By derekhh
#Apr 1, 2016

from scipy import stats

x = [10, 9.8, 8, 7.8, 7.7, 7, 6, 5, 4, 2]
y = [200, 44, 32, 24, 22, 17, 15, 12, 8, 4]
p = stats.pearsonr(x,y)
r = stats.spearmanr(x, y)
print("%.3f" % p[0])
print("%.1f" % r[0])