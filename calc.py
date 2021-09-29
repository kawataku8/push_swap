import string
path = "./output"

counter = 0
total = 0
minimum = 99999
maximum = 0

with open(path) as f:
    l = f.readlines()
    for i in l:
        if minimum > int(i):
            minimum = int(i)
        if maximum < int(i):
            maximum = int(i)
        total += int(i)
        counter += 1

print("AVG:{}".format(total/counter))
print("MIN:{}".format(minimum))
print("MAX:{}".format(maximum))

        