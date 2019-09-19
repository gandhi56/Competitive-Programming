
c = {}
c['a'] = '@'
c['b'] = '8'
c['c'] = '('
c['d'] = '|)'
c['e'] = '3'
c['f'] = '#'
c['g'] = '6'
c['h'] = '[-]'
c['i'] = '|'
c['j'] = '_|'
c['k'] = '|<'
c['l'] = '1'
c['m'] = '[]\/[]'
c['n'] = '[]\[]'
c['o'] = '0'
c['p'] = '|D'
c['q'] = '(,)'
c['r'] = '|Z'
c['s'] = '$'
c['t'] = "']['"
c['u'] = '|_|'
c['v'] = '\/'
c['w'] = '\/\/'
c['x'] = '}{'
c['y'] = '`/'
c['z'] = '2'
c[' '] = ' '
c['.'] = '.'

code = input().strip()
new = ''
for cr in code:
	if cr.lower() in c.keys():
		new += c[cr.lower()]
	else:
		new += cr
print(new)
