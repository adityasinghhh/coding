#!/usr/bin/python
def f(index, value, N, M, heap):

	left = value;
	if heap.has_key(2*index):
		left = heap[2*index];

	right = value;
	if heap.has_key(2*index+1):
		right = heap[2*index+1];


T = input();
while T:
	T -= 1;

	inp = raw_input().split();

	N = int(inp[0]);
	M = int(inp[1]);

	Q = input();
	heap = {};
	while Q:
		Q -= 1;

		inp = raw_input().split();

		node = int(inp[0]);
		value = int(inp[1]);

		heap[node] = value;

	top = 1;
	if heap.has_key(1):
		top = heap[1];

	print f(1, top, N, M, heap);
	
