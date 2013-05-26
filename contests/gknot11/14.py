def nim(heaps, misere=True):
	X = reduce(lambda x,y: x^y, heaps)
	if X == 0: # Will lose unless all non-empty heaps have size one
		print "You will lose :("
		for i, heap in enumerate(heaps):
			if heap > 0: # Empty any (non-empty) heap
				chosen_heap, nb_remove = i, heap
				break
	else:
		sums = [t^X < t for t in heaps]
		chosen_heap = sums.index(True)
		nb_remove = heaps[chosen_heap] - (heaps[chosen_heap]^X)
		heaps_twomore = 0
		for i, heap in enumerate(heaps):
			n = heap-nb_remove if chosen_heap == i else heap
			if n>1: heaps_twomore += 1
		# If move leaves no heap of size 2 or larger, leave an even (misère) or odd (normal) number of heaps of size 1
		if heaps_twomore == 0: 
			chosen_heap = heaps.index(max(heaps))
			heaps_one = sum(t==1 for t in heaps)
			# misère (resp. normal) strategy: if it is even (resp. odd) make it odd (resp. even), else do not change
			nb_remove = heaps[chosen_heap]-1 if heaps_one%2!=misere else heaps[chosen_heap]
	return chosen_heap, nb_remove

for i in range(1, 21):
