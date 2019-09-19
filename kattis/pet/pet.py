bestGrade, bestStudent = -1000, 0
for i in range(5):
	grades = [int(n) for n in input().split()]
	if sum(grades) > bestGrade:
		bestGrade = sum(grades)
		bestStudent = i+1
print(bestStudent, bestGrade)
