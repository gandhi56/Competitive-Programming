import sys
from typing import Tuple

class TrieNode:
	def __init__(self, c):
		self.char = c
		self.children = []
		self.isLeaf = False
		self.counter = 1

def add(root, word):
	node = root
	for char in word:
		found = False
		for child in node.children:
			if child.char == char:
				child.counter += 1
				node = child
				found = True
				break
		if not found:
			newNode = TrieNode(char)
			node.children.append(newNode)
			node = newNode
	node.isLeaf = True

def solve(s):
	s = s.replace(' ', '')
	
	# build a trie


for line in sys.stdin:
	solve(line)
