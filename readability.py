from cs50 import get_string


def count_letters(x):  # Counts the letters
    length = len(x)
    iterator = 0
    for i in x:
        if i.isalpha():
            iterator += 1
        else:
            continue
    return iterator


def count_words(x):  # Counts the words
    length = len(x)
    iterator = 1
    for i in x:
        if i.isspace():
            iterator += 1
        else:
            continue
    return iterator


def count_sentences(x):  # Counts the sentences
    length = len(x)
    iterator = 0
    num = x.count(".")
    num += x.count("!")
    num += x.count("?")
    return num


# Main program
input = get_string("Text: ")

letters = count_letters(input)
words = count_words(input)
sentences = count_sentences(input)


L = letters / words * 100  # Average letters per 100 words
S = sentences / words * 100  # Average sentences per 100 words

grade = round(0.0588 * L - 0.296 * S - 15.8)  # The formula

if (grade >= 16):
    print("Grade 16+")
elif (grade < 1):
    print("Before Grade 1")
else:
    print(f"Grade {grade}")