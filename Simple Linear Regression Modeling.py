from sklearn import linear_model
import pandas
import numpy
import matplotlib
import matplotlib.pyplot as plt
import csv
import biopython
f = open('/Users/youngkim/Desktop/crop_yields_data.csv','r')
reader = csv.reader(f)

listx = []
listx2 = []
listy = []
myreader = list(reader)
#print(myreader[0])
myreader.pop(0)
#print(myreader)
for line in myreader:
    #print(line)
    listx.append(float(line[1]))
    listx2.append(float(line[4]))
    listy.append(float(line[2]))


#print(listx, listy)

f.close()

data2 = {

'x' : listx,

'x2' : listx2,

'y' : listy}


data2 = pandas.DataFrame(data2)
x = data2[['x', 'x2']]
y = data2['y']

#ata2.plot(kind="scatter", x='GDP', x2 = 'Health', y = 'Happiness Score', figsize=(15,30), color="black")


linear_regression2 = linear_model.LinearRegression()
linear_regression2.fit(X=pandas.DataFrame(x),y=y)
prediction2 = linear_regression2.predict(X=pandas.DataFrame(x))
print('>>>', linear_regression2.intercept_, linear_regression2.coef_)
residuals = data2['y'] - prediction2
residuals.describe()
print(residuals)

SSE = ((residuals)**2).sum()
SST = ((data2['y'].mean() - data2['y'])**2).sum()
R2 = 1 - SSE/SST
print (SSE, SST, R2)
