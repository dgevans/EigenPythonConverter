# -*- coding: utf-8 -*-
"""
Created on Wed Jun 12 09:06:27 2013

@author: dgevans
"""
import numpy as np
from numpy.random import rand
from numpy.random import randn
import test_cpp

N = 10000

X = np.hstack( (np.ones((N,1)),randn(N,3)))

beta = rand(X.shape[1])

y = X.dot(beta) + randn(N)

def estimate(X,y):
    return np.linalg.solve(X.T.dot(X),X.T.dot(y))


