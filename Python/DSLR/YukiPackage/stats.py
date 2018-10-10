import math

def percentile(s, p):
	n = len(s)
	i = math.ceil(float(p) / 100.0 * float(n))
	return (s[i - 1])

def mean(s):
	return (sum(map(float, s)) / len(s))

def variance(s):
	m = mean(s)
	sd = []
	s = [str(x) for x in s]
	for val in s:
		val = float(val)
		sd.append((val - m) ** 2)
	v = sum(map(float, sd)) / len(s)
	return v

def std(s):
	return (math.sqrt(variance(s)))