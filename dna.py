from csv import reader, DictReader
from sys import argv

if len(argv) < 3:  # Checks for correct usage
    print("usage error, dna.py sequence.txt database.csv")
    exit()


with open(argv[2]) as dna_seqfile:  # read sequence from file
    dna_seqreader = reader(dna_seqfile)
    for row in dna_seqreader:
        dna_seqlist = row


dna_seq = dna_seqlist[0]
str_dict = {}


with open(argv[1]) as peoplefile:  # Extract str_dict from database
    people = reader(peoplefile)
    for row in people:
        strseq = row
        strseq.pop(0)
        break


for item in strseq:
    str_dict[item] = 1


for key in str_dict:  # iterate trough sequence
    l = len(key)
    tempMax = 0
    temp = 0
    for i in range(len(dna_seq)):

        while temp > 0:
            temp -= 1
            continue

        if dna_seq[i: i + l] == key:
            while dna_seq[i - l: i] == dna_seq[i: i + l]:
                temp += 1
                i += l

            if temp > tempMax:
                tempMax = temp

    str_dict[key] += tempMax

# open and iterate trough the database
with open(argv[1], newline='') as peoplefile:
    people = DictReader(peoplefile)
    for person in people:
        match = 0
        for dna_seq in str_dict:
            if str_dict[dna_seq] == int(person[dna_seq]):
                match += 1
        if match == len(str_dict):
            print(person['name'])  # Prints the name of the matching person
            exit()

    print("No match")  # No one matches the DNA