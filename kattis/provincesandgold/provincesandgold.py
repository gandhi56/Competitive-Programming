g, s, c = map(int, input().split())

vic = dict()
tre = dict()
vic['Province'] = (8, 6)
vic['Duchy'] = (5, 3)
vic['Estate'] = (2, 1)
tre['Gold'] = (6,3)
tre['Silver'] = (3,2)
tre['Copper'] = (0,1)

victory = None
val = g*3 + s*2 + c
for v in vic.keys():
	if val >= vic[v][0]:
		victory = v
		break

treasure = None
for t in tre.keys():
	if val >= tre[t][0]:
		treasure = t
		break
if victory is None:
	print(treasure)
else:
	print('{} or {}'.format(victory, treasure))
