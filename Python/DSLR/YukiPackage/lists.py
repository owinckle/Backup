def delDup(l):
	return (list(set(l)))

def delEl(l, s):
	for idx, val in enumerate(l):
		if val == s:
			l.pop(idx)
	return l

def cleanList(data, header, s):
	match = 0
	ind = []
	for l in data:
		for idx, val in enumerate(l):
			if val == s:
				for x in data:
					if x[idx] == s:
						match = 1
					else:
						match = 0
				if match == 1:
					ind.append(idx)
	ind = delDup(ind)
	for i, l in enumerate(data):
		for idx in sorted(ind, reverse=True):
			data[i].pop(idx)
	for idx in sorted(ind, reverse=True):
		header.pop(idx)
	return data, header