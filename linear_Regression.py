from csv import reader
import numpy as np
from csv import reader

def load_csv(filename):
	dataset = list()
	with open(filename, 'r') as file:
		csv_reader = reader(file)
		for row in csv_reader:
			if not row:
				continue
			dataset.append(row)
	return dataset
dataset = load_csv("House_price.csv")
Training_set = dataset[0:354]
Test_set = dataset[354:507]

Training_set = np.array(Training_set,dtype=float)
Test_set = np.array(Test_set,dtype=float)

Y= [row[-1] for row in Training_set]
Y_test= [row[-1] for row in Test_set]

Z_train = [row[:-1] for row in Training_set]
Z_test = [row[:-1] for row in Test_set]

Z = []
arr = [1]*354
arr = np.transpose(arr)

Z = np.insert(Z_train,0,arr,axis=1)
Zt = np.transpose(Z)

o = [0]*12
count = 100
ok = o
alpha = 0.00000002
while(count>0):
    a = np.subtract(np.dot(ok,Zt),Y)
    a = np.dot(a,Z)
    ok = np.subtract(ok,2*alpha*(a))
    count -= 1       
temp_ok = ok[:-1]
intercept = ok[len(ok)-1]

print("The Coefficients of the Optimized model is:")
print(ok)
mul = []
for row in Z_test:
    a = np.dot(row,np.transpose(temp_ok))
    a = a + intercept
    mul.append("{:.4f}".format(a))
mul = np.array(mul,dtype=float)

error = np.subtract(mul,Y_test)
SSE = 0
for i in error:
    SSE += i*i
MSE = SSE/(len(Test_set))
y_mean = 0
for i in Y_test:
 y_mean += i
y_mean /= len(Test_set) 

ssr = 0
for i in mul:
    a = i-y_mean
    ssr += a*a
sst = 0    
for i in Y_test:
    a = i - y_mean
    sst += a*a
R2 = ssr/sst
      
# training data
mul_train = []
for row in Z_train:
    a = np.dot(row,np.transpose(temp_ok))
    a = a + intercept
    mul_train.append("{:.4f}".format(a))
mul_train = np.array(mul_train,dtype=float)


error_Train = np.subtract(mul_train,Y)

SSE_train = 0
for i in error_Train:
    SSE_train += i*i
print("The SSE of the train set is:")    
print(SSE_train) 

MSE_train = SSE_train/(len(Training_set))
print("The MSE of the train set is:")    
print(MSE_train)

y_mean_train = 0
for i in Y:
 y_mean_train += i
y_mean_train /= len(Training_set) 

ssr = 0
for i in mul_train:
    a = i-y_mean_train
    ssr += a*a
sst = 0    
for i in Y:
    a = i - y_mean_train
    sst += a*a
R2_train = ssr/sst
print("The R2 of the train set is:")    
print(R2_train)        
print("The SSE of the test set is:")    
print(SSE)
print("The MSE of the test set is:")    
print(MSE)
print("The R2 of the test set is:")    
print(R2)
