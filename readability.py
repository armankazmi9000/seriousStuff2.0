import re
text = input("Text: ")

letters = 0;
words = 1;
sentences = 0;

for i in range (len(text)):
    if text[i].isalnum()==True:      
        letters = letters + 1
    elif text[i] == " ":
        words = words + 1
    elif text[i] == ".":
        sentences += 1
    elif text[i] == "?":
        sentences += 1
    elif text[i] == "!":
        sentences += 1

L = (letters / words) * 100
S = (sentences / words) * 100
index = ((0.0588 * L) - (0.296 * S) - 15.8)

print(letters)
print(words)
print(sentences)

if round(index) > 16:
    print("Grade 16+")
elif round(index) < 1:
    print("Before Grade 1")
else:
    print(f"Grade {round(index)}")