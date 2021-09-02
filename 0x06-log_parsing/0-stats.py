#!/usr/bin/python3
'''stats module'''


from sys import stdin

# keeps track of status code occurences
statusCodes = {'200': 0, '301': 0, '400': 0, '401': 0,
               '403': 0, '404': 0, '405': 0, '500': 0}

printed = 0

def printStatusCodes(sumFileSizes):
    '''prints status codes
       sumFileSizes - sum of all file sizes for printing
     '''
    print('File size:', sumFileSizes)
    for statusCode, occurences in sorted(statusCodes.items()):
        if occurences > 0:
            print("{}: {}".format(statusCode, occurences))


def main():
    '''script that reads stdin line by line and computes metrics'''
    try:
        count = 0
        sumFileSizes = 0
        for line in stdin:
            inputs = line.split()
            if len(inputs) > 6 and len(inputs[-2]) is 3:
                inputFileSize = int(inputs[-1])
                statusCode = inputs[-2]
                sumFileSizes += inputFileSize
                if (statusCode in statusCodes):
                    statusCodes[statusCode] += 1
                    count += 1
                    if count == 10:
                        printStatusCodes(sumFileSizes)
                        count = 0
                        printed = 1
            else:
                try:
                    sumFileSizes += int(inputs[-1])
                except Exception:
                    pass
        if count > 0:
            printStatusCodes(sumFileSizes)
            printed = 1
        if printed == 0:
            print("File size: 0")
    except KeyboardInterrupt:
        printStatusCodes(sumFileSizes)
        raise


if __name__ == '__main__':
    main()
