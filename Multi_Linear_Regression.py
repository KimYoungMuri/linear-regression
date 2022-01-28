import numpy as np
import pandas as pd
import matplotlib.pyplot as plt
import seaborn as sns
%matplotlib inline

#data set 
dataset = pd.read_csv('datasets/crop_yields_data.csv')
Y = dataset[['yields']]
X = dataset.drop(['summer_waves', 'avg_temp', 'date'],  axis=1)

#initialization
X.info()
columns = X.columns
columns
X.head()

dataset = dataset.drop(['summer_waves', 'date'], axis=1)
dataset.corr(method='pearson')

#visualization
plt.subplots(figsize=(10,8))
sns.heatmap(dataset.corr())

#PART 2

import statsmodels.api as sml
from statsmodels import tools

X_new = tools.add_constant(X)
regressor_OLS = sml.OLS(endog = Y,exog =  X_new).fit()
regressor_OLS.summary()

x = X[['crop_yields']]
y = Y

plt.figure(figsize=(10,6))
plt.xlabel('summer_waves')
plt.ylabel('crop_yields')
plt.scatter(x,y, marker='o', color='g')


#Simple Linear Regression
from scipy import stats
sns.set(color_codes=True)

slope, intercept, r_value, p_value, std_err = stats.linregress(dataset['summer_waves'],dataset['crop_yields'])

f = plt.figure(figsize=(10,6))
data = dataset[['summer_waves','crop_yields']]
ax = sns.regplot(x='summer_waves', y='crop_yields', data=data, 
                 scatter_kws={"color": "g"}, 
                line_kws={'color': 'r', 'label':"y={0:.1f}x+{1:.1f}".format(slope,intercept)})
ax.legend()

print(slope, intercept)
print(std_err)

#Multi-variable Regression with Scikit-Learn

from sklearn.linear_model import LinearRegression
from sklearn.preprocessing import StandardScaler

mlr = LinearRegression()
sc_x = StandardScaler()
X_new = sc_x.fit_transform(x)

mlr.fit(X_new, Y)
y_hat = mlr.predict(X_new)
mlr.score(X_new, Y)
mlr.intercept_
mlr.coef_

x_neq = np.concatenate((np.ones(len(x)).reshape(-1,1), x), axis=1)
a = np.linalg.inv(np.dot(x_neq.T, x_neq))
b = np.dot(x_neq.T, y)
theta_neq = np.dot(a,b)
theta_neq

from scipy import stats

slope, intercept, r_value, p_value, std_err = stats.linregress(X.values.reshape(-1,1),  Y.values)

print('theta[0] = ', intercept)
print('theta[1] = ', slope)
import statsmodels.api as sm
#without feature scaling
results = sm.OLS(Y, x_neq).fit()
results.summary()
