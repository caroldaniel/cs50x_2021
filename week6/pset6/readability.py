import cs50

# Prompt user for text
text = cs50.get_string("Text: ")
# Initialize variables
letters = 0
words = 0
sentences = 0
# Interate over text to check for letters, words and sentences
for i in range(len(text)):
    if text[i].isalpha():
        letters += 1
    elif text[i].isspace():
        words += 1
    elif text[i] == "." or text[i] == "!" or text[i] == "?":
        sentences += 1
        if i == len(text) - 1:
            words += 1
# Find out the Coleman-Liau index
L = letters * 100 / words
S = sentences * 100 / words
coleman_index = round(float((0.0588 * L) - (0.296 * S) - 15.8))
# Print result
if coleman_index >= 16:
    print("Grade 16+")
elif coleman_index < 1:
    print("Before Grade 1")
else:
    print(f"Grade {coleman_index}")
