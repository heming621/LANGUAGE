
print 'Hello world!'

def magic():
  print "maximan 9 values"
  a=[]
  for i in range(3):
    a.append([])
    for j in range(3):
      a[i].append(input('Enter one value:'))
  print a,"Is it a magic value?"
  l1 = a[0][0]+a[1][0]+a[2][0]
  l2 = a[0][1]+a[1][1]+a[2][1]
  l3 = a[0][2]+a[1][2]+a[2][2]
  r1 = sum(a[0])
  r2 = sum(a[1])
  r3 = sum(a[2])
  if l1 == l2 == l3 == r1 == r2 == r3:
    print a,"It's a magic square"
  else:
    print a,"It's not a magic square"
magic()


#2 9 4
#7 5 3
#6 1 8
