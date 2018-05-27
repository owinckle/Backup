import numpy as np
import sys

FIELD = ['Count', 'Mean', 'Std', 'Min', '25%', '50%', '75%', 'Max']

def describe(f):

    def analyze(arr):
        a = np.sort(arr, kind='mergesort')
        c = len(a)
        m = sum(a) / c
        std = (sum((a - m) ** 2) / (c - 1)) ** 0.5
        v0 = a[int(a.shape[0] * 0.25)]
        v1 = a[int(a.shape[0] * 0.5)]
        v2 = a[int(a.shape[0] * 0.75)]
        return c, m, std, a[0], v0, v1, v2, a[c - 1]

    def calculate(data):
        rslt = []
        for feature in data.T:
            rslt.append(analyze(feature))
        return np.array(rslt)

    def print_data(rslt):
        print('%-8s' % '' + ''.join(['{:>15.15s}'.format(x) for x in header]))
        for i in range(len(FIELD)):
            print('%-8s' % FIELD[i] + ''.join(['{:15.6f}'.format(x) for x in rslt[i]]))

    header = np.genfromtxt(f, delimiter=',', max_rows=1, dtype='str')
    data = np.genfromtxt(f, delimiter=',', skip_header=1)
    mask = ~np.all(np.isnan(data), axis=0)
    data = data[:, mask]                                    #removing all columns full of Nan
    header = header[mask]
    data = data[~np.isnan(data).any(axis=1)]                #removing all rows with a Nan
    rslt = calculate(data)
    print_data(rslt.T)

def main():
    if len(sys.argv) != 2:
        exit('''Usage: py describe.py [data_file.csv]''')
    for f in sys.argv[1:]:
        describe(f)

if __name__ == '__main__':
    main()