def table(header, column, row):
	columnOffset = " " * (len(max(column, key=len)) + 1)
	ridx = 0
	def dRow():
		nonlocal ridx
		i = 0
		for r in row:
			if i == 5:
				print("\n", end="")
				ridx += 1
				break
			print(r[ridx], end=" ")
			i += 1

	def dColumn():
		print("\n", end="")
		for col in column:
			colRightOffset = " " * (len(columnOffset) - len(col) + 1)
			print(col + colRightOffset + "|", end="")
			dRow()

	def dHeader():
		headCount = 0
		print(columnOffset + " | ", end="")
		for idx, h in enumerate(header):
			print(h, end=" | ")
			if headCount == 5:
				dColumn()
				print("\n" + columnOffset + " | ", end="")
				headCount = 0
			headCount += 1
		dColumn()

	dHeader()