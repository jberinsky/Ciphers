# Jason Berinsky
# CS 50 Problem Set 6
# Implements a Vigenere cipher in Python

from cs50 import get_string
import sys
from sys import argv

if len(sys.argv) != 2:
    sys.exit("Usage: python vigenere.py keyword")
key = argv[1]
if key.isalpha() == False:
    sys.exit("Usage: python vigenere.py keyword")
plaintext = get_string("plaintext: ")
cipher = list(plaintext)
textlength = len(plaintext)
keylength = len(key)
j = 0
for i in range(textlength):
    if ord(key[j]) >= ord('a'):
        letter = chr(ord(key[j]) - ord('a'))
    else:
        letter = chr(ord(key[j]) - ord('A'))
    if ord(plaintext[i]) >= ord('A') and ord(plaintext[i]) <= ord('Z'):
        cipher[i] = chr(ord('A') + ((ord(plaintext[i]) - ord('A')) + ord(letter)) % 26)
        j = j + 1
    elif ord(plaintext[i]) >= ord('a') and ord(plaintext[i]) <= ord('z'):
        cipher[i] = chr(ord('a') + ((ord(plaintext[i]) - ord('a')) + ord(letter)) % 26)
        j = j + 1
    if j == keylength:
        j = 0
new = ''.join(cipher)
print(f"ciphertext: {new}")
