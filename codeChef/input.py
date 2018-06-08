#! python

ptr = open("input_u32.txt", "w")

numOfTc = 4294967296*4294967296
ptr.write(str(numOfTc))
ptr.write('\n')
for i in xrange(0,4294967296):
    for j in xrange(0,4294967296):
        line = str(i) + " " + str(j)+'\n'
        ptr.write(line)
ptr.close()
