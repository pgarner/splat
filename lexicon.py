#!/usr/bin/env python3
#
# Copyright 2018 by Philip N. Garner
#
# See the file COPYING for the licence associated with this software.
#
# Author(s):
#   Phil Garner, October 2018
#

# Options
from optparse import OptionParser
op = OptionParser()
op.add_option("-v", dest="verbose", help="Verbose")
(opt, arg) = op.parse_args()

# The global lexicon
lexicon = {}

# Pick up the lexicons on the command line
for lex in arg:
    with open(lex) as f:
        for line in f:
            list = line.split()
            word = list.pop(0)
            if (not word in lexicon.keys()):
                lexicon[word] = []
            lexicon[word].append(list)

# Stats about words
nWords = len(lexicon)
print ("Lexicon has", nWords, "words")

# Stats about phones
phone = {}
for word in lexicon.keys():
    for pron in lexicon[word]:
        for p in pron:
            if (not p in phone.keys()):
                phone[p] = 0
            else:
                phone[p] += 1
print ("Phone list:", phone.keys())
